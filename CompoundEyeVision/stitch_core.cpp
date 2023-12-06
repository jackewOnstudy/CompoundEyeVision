#include "stitch_core.h"

/**
 * @brief update_GpuMatxy
 * 计算图像边界到目标角点的透视变换矩阵。
 * 计算透视变换矩阵的逆矩阵。
 * 在 GPU 上使用逆透视变换矩阵对映射坐标进行变换。
 * @param obj_corners are the coordinates of the four target corner points
 * @param maps_x Output parameter indicating the mapped coordinates
 * @param maps_y in the x and y directions after the perspective transformation.
 * @param numBlocks  Specify the number of GPU blocks and threads
 * @param threadsPerBlock
 */
void update_GpuMatxy(std::vector<Point2f> obj_corners, cuda::GpuMat& maps_x, cuda::GpuMat& maps_y, dim3 numBlocks, dim3 threadsPerBlock)
{
    std::vector<Point2f> borders_corners(4);
    borders_corners[0] = Point(0, 0);
    borders_corners[1] = Point(video_cols, 0);
    borders_corners[2] = Point(video_cols, video_rows);
    borders_corners[3] = Point(0, video_rows);

    Mat H(Size(3, 3), CV_32FC1);
    H = findHomography(borders_corners, obj_corners, RANSAC);
    Mat H_inv(Size(3, 3), CV_32FC1);
    H_inv = H.inv();

    cuda::GpuMat gpuH_inv(Size(3, 3), CV_32FC1);
    gpuH_inv.upload(H_inv);
    genCornerHomo(gpuH_inv, maps_x, maps_y, numBlocks, threadsPerBlock);
}

/**
 * @brief stitch_twolayer
 * @param bottom_layer input layer
 * @param top_layer  input layer
 * @param dst_layer output layer, the Merged layers
 * @param numBlocks
 * @param threadsPerBlock
 */
void stitch_twolayer(cuda::GpuMat& bottom_layer, cuda::GpuMat& top_layer, cuda::GpuMat& dst_layer, dim3 numBlocks, dim3 threadsPerBlock)
{
    getStitch(bottom_layer, top_layer, dst_layer, numBlocks, threadsPerBlock);
}

/**
 * @brief stitchOpt_twolayer
 * @param bottom_layer
 * @param top_layer1
 * @param top_layer2
 * @param top_buffer is a buffer layer for optimization
 * @param dst_layer
 * @param isOdd indicates whether the current layer is odd or even.
 * @param numBlocks
 * @param threadsPerBlock
 */
void stitchOpt_twolayer(cuda::GpuMat& bottom_layer, cuda::GpuMat& top_layer1, cuda::GpuMat& top_layer2, cuda::GpuMat& top_buffer,
                        cuda::GpuMat& dst_layer, bool isOdd, dim3 numBlocks, dim3 threadsPerBlock)
{
    getStitchOpt(bottom_layer, top_layer1, top_layer2, top_buffer, dst_layer, isOdd, numBlocks, threadsPerBlock);
}

vector<cv::Point2f> findStitchCorner(Mat Left_img, Mat Right_img, int idx_left, int idx_right)
{
    vector<cv::Point2f> result;
    Mat Left_img_grey;
    Mat Right_img_grey;
    cvtColor(Left_img, Left_img_grey, COLOR_BGR2GRAY);
    cvtColor(Right_img, Right_img_grey, COLOR_BGR2GRAY);

    Mat limg;
    Mat rimg;
    Left_img_grey.convertTo(limg, CV_32FC1);
    Right_img_grey.convertTo(rimg, CV_32FC1);
    unsigned int w = limg.cols;
    unsigned int h = limg.rows;
    std::cout << "Image size: = (" << w << "," << h << ")" << std::endl;

    // Perform some initial blurring (if needed)
    cv::GaussianBlur(limg, limg, cv::Size(5, 5), 1.0);
    cv::GaussianBlur(rimg, rimg, cv::Size(5, 5), 1.0);

    // Initial Cuda images and download images to device
    std::cout << "Initializing data..." << std::endl;
    InitCuda();
    CudaImage img1, img2;
    img1.Allocate(w, h, iAlignUp(w, 128), false, NULL, (float*)limg.data);
    img2.Allocate(w, h, iAlignUp(w, 128), false, NULL, (float*)rimg.data);
    img1.Download();
    img2.Download();

    // Extract sift features from images
    SiftData siftData1, siftData2;
    float initBlur = 0.0f;
    float thresh = 5.0f;
    InitSiftData(siftData1, 2048, true, true); //
    InitSiftData(siftData2, 2048, true, true);
    ExtractSift(siftData1, img1, 5, initBlur, thresh, 0.0f);
    ExtractSift(siftData2, img2, 5, initBlur, thresh, 0.0f);

    // Match Sift features and find a homography
    MatchSiftData(siftData1, siftData2);
    float homography[9];
    int numMatches;
    FindHomography(siftData1, homography, &numMatches, 10000, 0.50f, 1.00f, 5.0);
    int numFit = ImproveHomography(siftData1, homography, 3, 0.80f, 0.95f, 3.0);
    cv::Mat H(cv::Size(3, 3), CV_32FC1);
    int cnt = 0;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            H.at<float>(i, j) = homography[cnt++];
        }
    }

    std::cout << H << std::endl;
    std::vector<cv::Point2f> sceneCorners(4);
    sceneCorners[0] = Point(0, 0);
    sceneCorners[1] = Point(video_cols, 0);
    sceneCorners[2] = Point(video_cols, video_rows);
    sceneCorners[3] = Point(0, video_rows);
    std::vector<cv::Point2f> objectCorners(4);

    perspectiveTransform(sceneCorners, objectCorners, H);
    bool isCorrect = false;

    if(objectCorners[0].x < objectCorners[1].x && objectCorners[3].x < objectCorners[2].x
            && objectCorners[0].y < objectCorners[3].y && objectCorners[1].y < objectCorners[2].y)
        isCorrect = true;

    if(isCorrect) {
        for(int i = 0; i < 4; i++) {
            result.push_back(objectCorners[i]);
            cout << "i: " << i << objectCorners[i] << endl;
        }
    }else {
        return result;
    }

    // Stitch the left and right images horizontally into the output image, where there is a gap of one pixel between the two images
    Mat outimg(Left_img.rows, Left_img.cols + Right_img.cols + 1, Left_img.type());
    Left_img.colRange(0, Left_img.cols).copyTo(outimg.colRange(0, Left_img.cols));
    Right_img.colRange(0, Right_img.cols).copyTo(outimg.colRange(Left_img.cols + 1, outimg.cols));
    for(int i = 0; i < 4; i++) {
        // 绘制匹配的四边形的边，连接 objectCorners[i] 和 objectCorners[(i + 1) % 4] 的线段。这些点已经通过透视变换从场景坐标转换为目标坐标（左图坐标），颜色为绿色。
        line(outimg, objectCorners[i] + Point2f((float)Left_img.cols, 0),objectCorners[(i + 1) % 4] + Point2f((float)Left_img.cols, 0), Scalar(0, 255, 0), 2, LINE_AA);
        // 绘制场景中的四边形的边，连接 sceneCorners[i] 和 sceneCorners[(i + 1) % 4] 的线段。这是原始场景中的四边形，颜色为蓝色。
        line(outimg, sceneCorners[i], sceneCorners[(i + 1) % 4], Scalar(255, 0, 0), 4, LINE_AA);
        // 绘制匹配线，连接场景中的点 sceneCorners[i] 和匹配后的目标中的点 objectCorners[i]，颜色为黄色。
        line(outimg, sceneCorners[i], objectCorners[i] + Point2f((float)Left_img.cols, 0), Scalar(255, 255, 0), 2, LINE_AA);
    }
    float MatchPersent = 100.0f * numMatches / std::min(siftData1.numPts, siftData2.numPts);
    cout << "Number of original features: " << siftData1.numPts << " " << siftData2.numPts << endl;
    cout << "Match left idx-" << idx_left << "right idx-" << idx_right << "Number of matching features: " << numFit \
         << " " << numMatches << " " << MatchPersent << "%" << endl;
    char str_name[50];
    sprintf(str_name, "./MatchImg_%d-%d.png", idx_left, idx_right);
    cv::imwrite(str_name, outimg);

    // Free sift data from device
    FreeSiftData(siftData1);
    FreeSiftData(siftData2);
    return result;
}
