/**
 * @file backend.cpp
 * @author jackew
 * @date 2023-11-22
 * @brief This file contains the implementation of the Backend.
 *
 * Copyright (c) 2023.
 */


#include "backend.h"

Backend::Backend(SharedData* shared, MainWindow* parent): sharedData(shared), parent(parent)
{

}

Backend:: ~Backend()
{

}


/**
 * @brief choose which tab to show in QTabWidget.
 *        the task function of the backend core thread
 */
void Backend:: core()
{
    frame_cnt = 0;
    double buffer_cnt[50];
    double sum_cost = 0;
    while(true) {
        sum_cost = 0;
        clock_t begin = clock();
        switch (sharedData->idx_table) {
            case 0 :
                StreamMultiCam();
                break;
            case 1:
                StreamMultiCam();
                break;
            case 2:
                streamSingleCam();
                break;
            case 3:
                streamStitch();
                break;
        }
        frame_cnt++;
        clock_t end = clock();
        double time_cost = (double)(end - begin) / CLOCKS_PER_SEC;
        buffer_cnt[frame_cnt % 50] = time_cost;

        for(int i = 0; i < 50; i++) {
            sum_cost += buffer_cnt[i];
        }
//        qDebug() << "adv time cost:" << sum_cost / 50 << endl;

        qDebug() << "choose tab" << endl;
    }
}


/**
 * @brief init GpuMat for display
 * @return
 */
bool Backend::initGpuMat() {
    //In image processing, gamma correction is a way to adjust the brightness of an image.
    // Gamma value is a non-linear parameter used to describe the relationship between input brightness and output brightness.
    // The formula is as follows:
    // O = I^(gamma)
    // gamma table for cam
    float gamma = 1.25f;
    for(int i = 0; i < 256; i++) {
        cpuGtable.at<uchar>(0, i) = float(pow((float)i/ 255, float(gamma)) * 255);
    }
    gpuGTable = cuda::GpuMat(1, 256, CV_8UC1, Scalar(0));
    gpuGTable.upload(cpuGtable);

    // gamma table for nvdec to correct invgamma
    float invgamma = 1.1f;
    for(int i = 0; i  < 256; i++) {
        cpuInvGTable.at<uchar>(0, i) = float( pow( (float)i / 255, float(invgamma)) * 255);
    }
    gpuInvGTable = cuda::GpuMat(1, 256, CV_8UC1, Scalar(0));
    gpuInvGTable.upload(cpuInvGTable);

    // init Gpumat for video size
    res_dehaze = cuda::GpuMat(video_rows, video_cols, CV_8UC3, Scalar(0, 0, 0));
    res_darkch = cuda::GpuMat(video_rows, video_cols, CV_8UC1, Scalar(0));
    res_tran = cuda::GpuMat(video_rows, video_cols, CV_8UC1, Scalar(0));
    res_tran_LL = cuda::GpuMat(video_rows, video_cols, CV_8UC1, Scalar(0));
    res_enhanceLL = cuda::GpuMat(video_rows, video_cols, CV_8UC3, Scalar(0, 0, 0));

    // init Gpumat for display size
    view_dehaze = cuda::GpuMat(video_rows, video_cols, CV_8UC3, Scalar(0, 0, 0));
    view_darkch = cuda::GpuMat(video_rows, video_cols, CV_8UC1, Scalar(0));
    view_tran = cuda::GpuMat(video_rows, video_cols, CV_8UC1, Scalar(0));
    view_tran_LL = cuda::GpuMat(video_rows, video_cols, CV_8UC1, Scalar(0));
    view_enhanceLL = cuda::GpuMat(video_rows, video_cols, CV_8UC3, Scalar(0, 0, 0));

    // init Gpumat for multicam stream and singlecam stream
    gpu_raw =  cuda::GpuMat(video_rows, video_cols, CV_8UC1, Scalar(0));
    gpu_rgb = cuda::GpuMat(video_rows, video_cols, CV_8UC3, Scalar(0, 0, 0));
    gpu_view = cuda::GpuMat(video_rows, video_cols, CV_8UC3, Scalar(0, 0, 0));

    // for stitch
    gpuStitchViewResult = cuda::GpuMat(video_rows, video_cols, CV_8UC3, Scalar(0, 0, 0));
    gpuStitchResult = cuda::GpuMat(video_rows, video_cols, CV_8UC3, Scalar(0, 0, 0));
    gpuEmpty = cuda::GpuMat(video_rows, video_cols, CV_8UC3, Scalar(0, 0, 0));


    return true;
}


bool Backend::open_usbcam()
{
    qDebug() << "open usb camera" << endl;
    initGpuMat();
    usbCam.open_usbcam();
    table_cam.clear();

    for(unsigned int i = 0; i < usbCam.cam_idx.size(); i++) {
        table_cam.push_back(usbCam.cam_idx[i]);
    }

    // init usbcam GpuMat
    for(int i = 0; i < camera_nums; i++) {
        cam camera;
        usbCam.Cams.push_back(camera);
        usbCam.Cams[i].gpu_src = cuda::GpuMat(video_rows, video_cols, CV_8UC3, Scalar(0, 0, 0));

        usbCam.Cams[i].gpu_frame1 = cuda::GpuMat(video_rows, video_cols, CV_8UC3, Scalar(0, 0, 0));
        usbCam.Cams[i].gpu_frame2 = cuda::GpuMat(video_rows, video_cols, CV_8UC3, Scalar(0, 0, 0));
        usbCam.Cams[i].gpu_buffer = cuda::GpuMat(video_rows, video_cols, CV_8UC1, Scalar(5));

        usbCam.Cams[i].gpu_dst = cuda::GpuMat(video_rows, video_cols, CV_8UC3, Scalar(0, 0, 0));
        usbCam.Cams[i].gpu_tmp = cuda::GpuMat(video_rows, video_cols, CV_8UC3, Scalar(0, 0, 0));
        usbCam.Cams[i].gpu_mapx = cuda::GpuMat(video_rows, video_cols, CV_8UC1, Scalar(0));
        usbCam.Cams[i].gpu_mapy = cuda::GpuMat(video_rows, video_cols, CV_8UC1, Scalar(0));
    }
    // Remap generation
    vector<Point2f> corner;
    corner = getCornerFromTxt("/home/jackew/Project/CompoundEyeVision/CornerSet.txt");
    for(int i = 0; i < camera_nums; i++) {
        usbCam.Cams[i].map_corners.push_back(corner[4 * i]);
        usbCam.Cams[i].map_corners.push_back(corner[4 * i + 1]);
        usbCam.Cams[i].map_corners.push_back(corner[4 * i + 2]);
        usbCam.Cams[i].map_corners.push_back(corner[4 * i + 3]);
        update_GpuMapxy(usbCam.Cams[i].map_corners,  usbCam.Cams[i].gpu_mapx,  usbCam.Cams[i].gpu_mapy, sharedData->numBlocks, sharedData->threadsPerBlock);
    }

    // Save camera SnapShot
    sharedData->camSnapshot.clear();
    for(unsigned int i = 0; i < camera_nums; i++) {
        if(table_cam[i] != -1) {
            cv::Mat temp_mat;
            char img_name[50];

            if(!usbCam.usbCams[i].read(temp_mat)) {
                std::cerr << "Error reading frame from camera:" << i << endl;
            }
            sprintf(img_name, "camSnapshot_%d.png", i);
            cv::imwrite(img_name, temp_mat);
            sharedData->camSnapshot.push_back(temp_mat);
        }else {
            cv::Mat temp_mat;
            char img_name[50];
            temp_mat = empty;
            sprintf(img_name, "camSnapshot_%d.png", i);
            cv::imwrite(img_name, temp_mat);
            sharedData->camSnapshot.push_back(temp_mat);
        }
    }
    qDebug() << "End of camera initialization." << endl;
    return true;
}

bool Backend::close_usbcam()
{
    qDebug() << "Close usb camera." << endl;
    usbCam.close_usbcam();
    return true;
}

/**
 * @brief read frame from multi cameras and send the ack signals
 */
void Backend::StreamMultiCam()
{
    switch (sharedData->inputMedia) {
        case 0:
            for(int i = 0; i < camera_nums; i++) {
                if(table_cam[i] != -1)
                    usbCam.usbCams[i].read(imgMultiCam[i]);
                else
                    imgMultiCam[i] = Mat(Size(1280, 720), CV_8UC3, cv::Scalar(0, 0, 0));
            }
            break;
        // Additional cases can be extended to support other types of cameras
        default:
            break;
    }

    for(int i = 0; i < camera_nums; i++) {
        if(!imgMultiCam[i].empty()) {
            cv::cvtColor(imgMultiCam[i], cvtimgMultiCam[i], COLOR_BGR2RGB); //opencv中的图片以BGR格式保存，Qt中是RGB
            res.view[i] = cvtimgMultiCam[i];
        }else {
            res.view[i] = empty;
        }
    }
    // send ack signal
    emit ack(res);
}

void Backend::streamSingleCam()
{

    float zoom_val = (sharedData->zoom_Val) / 10.0 + 1;   // zoom val between 1 to 2, indicates the magnification of the selected camera
    float zoom_check = (sharedData->zoom_Val) / 10.0 + 1; // zoom check between 1 to 9

    int tmp_idxCamSelect = -1;
    tmp_idxCamSelect = sharedData->idx_camSelect;
    if(zoom_check < 3) {
        tmp_idxCamSelect = 0;
    }else if(zoom_check < 5) {
        tmp_idxCamSelect = 1;
        zoom_val -= 2;
    }else if(zoom_check < 7) {
        tmp_idxCamSelect = 2;
        zoom_val -= 4;
    }else {
        tmp_idxCamSelect = 3;
        zoom_val -= 6;
    }

    switch (sharedData->inputMedia) {
        case 0:
            if(table_cam[tmp_idxCamSelect] != -1) {
                if(sharedData->isInterFrame) {
                    if(frame_cnt % 2 == 0)
                        usbImageToGpuMat(usbCam.usbCams[sharedData->idx_camSelect], usbCam.Cams[sharedData->idx_camSelect].gpu_frame2, gpuGTable);
                    else
                        usbImageToGpuMat(usbCam.usbCams[sharedData->idx_camSelect], usbCam.Cams[sharedData->idx_camSelect].gpu_frame1, gpuGTable);
                    funcStreamProcessOpt();
                }else {
                    usbImageToGpuMat(usbCam.usbCams[tmp_idxCamSelect], gpu_rgb, gpuGTable);
                    funcStreamProcess();
                }

                if(!imgMultiCam[tmp_idxCamSelect].empty()) {
                    cv::cvtColor(imgMultiCam[tmp_idxCamSelect], cvtimgMultiCam[tmp_idxCamSelect], COLOR_BGR2RGB);
                }else {
                    imgMultiCam[tmp_idxCamSelect] = empty;
//                    cvtimgMultiCam[tmp_idxCamSelect] = empty;
                }
            }else {
                imgMultiCam[tmp_idxCamSelect] = empty;
//                cvtimgMultiCam[tmp_idxCamSelect] = empty;
            }
            break;
        default:
            break;
    }

    res.view[tmp_idxCamSelect] = cvtimgMultiCam[tmp_idxCamSelect];

    int x_max = 150;
    int y_max = 150;
    // matrix rotate and slide
    if(tmp_idxCamSelect == 0) {
        res.view[tmp_idxCamSelect] = res.view[tmp_idxCamSelect](cv::Rect(sharedData->cam0_x, sharedData->cam0_y, res.view[tmp_idxCamSelect].cols - x_max, res.view[tmp_idxCamSelect].rows - y_max));
        Mat rotateMatrix = getRotationMatrix2D(Point2f(res.view[tmp_idxCamSelect].cols / 2, res.view[tmp_idxCamSelect].rows / 2), sharedData->cam0_r, sharedData->cam0_z / 10.0 + 1);
        cv::warpAffine(res.view[tmp_idxCamSelect], res.view[tmp_idxCamSelect], rotateMatrix, res.view[tmp_idxCamSelect].size());
    }else if(tmp_idxCamSelect == 1) {
        res.view[tmp_idxCamSelect] = res.view[tmp_idxCamSelect](cv::Rect(sharedData->cam1_x, sharedData->cam1_y, res.view[tmp_idxCamSelect].cols - x_max, res.view[tmp_idxCamSelect].rows - y_max));
        Mat rotateMatrix = getRotationMatrix2D(Point2f(res.view[tmp_idxCamSelect].cols / 2, res.view[tmp_idxCamSelect].rows / 2), sharedData->cam1_r, sharedData->cam1_z / 10.0 + 1);
        cv::warpAffine(res.view[tmp_idxCamSelect], res.view[tmp_idxCamSelect], rotateMatrix, res.view[tmp_idxCamSelect].size());
    }else if(tmp_idxCamSelect == 2) {
        res.view[tmp_idxCamSelect] = res.view[tmp_idxCamSelect](cv::Rect(sharedData->cam2_x, sharedData->cam2_y, res.view[tmp_idxCamSelect].cols - x_max, res.view[tmp_idxCamSelect].rows - y_max));
        Mat rotateMatrix = getRotationMatrix2D(Point2f(res.view[tmp_idxCamSelect].cols / 2, res.view[tmp_idxCamSelect].rows / 2), sharedData->cam2_r, sharedData->cam2_z / 10.0 + 1);
        cv::warpAffine(res.view[tmp_idxCamSelect], res.view[tmp_idxCamSelect], rotateMatrix, res.view[tmp_idxCamSelect].size());
    }else {
        res.view[tmp_idxCamSelect] = res.view[tmp_idxCamSelect](cv::Rect(0, 0, res.view[tmp_idxCamSelect].cols - x_max, res.view[tmp_idxCamSelect].rows - y_max));
    }
    res.view[tmp_idxCamSelect] = res.view[tmp_idxCamSelect](cv::Rect((int)((res.view[tmp_idxCamSelect].cols - (int)(res.view[tmp_idxCamSelect].cols/zoom_val))/2), (int)((res.view[tmp_idxCamSelect].rows - (int)(res.view[tmp_idxCamSelect].rows/zoom_val))/2), (int)(res.view[tmp_idxCamSelect].cols/zoom_val), (int)(res.view[tmp_idxCamSelect].rows/zoom_val)));
    Mat rotateMatrix_global = getRotationMatrix2D(Point2f(res.view[tmp_idxCamSelect].cols/2, res.view[tmp_idxCamSelect].rows/2), sharedData->camGlobal_r, sharedData->camGlobal_z/10.0 + 1);
    cv::warpAffine(res.view[tmp_idxCamSelect], res.view[tmp_idxCamSelect], rotateMatrix_global, res.view[tmp_idxCamSelect].size());
    //cout<< "res.view.size:"<< res.view[tmp_idxCamSelect].cols << res.view[tmp_idxCamSelect].rows<<endl;
    emit ack(res);
}



void Backend::streamStitch()
{
    if(sharedData->isKeyIn) {
        sharedData->isKeyIn = false;
        
        switch(sharedData->inputMedia) {
            case 0:
                if(sharedData->isUpdateParam) {
                    sharedData->isUpdateParam = false;
                    update_usb_cam_param(usbCam);
                }
                for(int i = 0; i < camera_nums; i++) {
                    vector<Point2f> temp_corner;
                    temp_corner.clear();
                    if(table_cam[i] != -1){
                        for(int j = 0; j < 4; j++) {
                            Point2f point_map;
                            point_map.x = (usbCam.Cams[i].map_corners[j].x + sharedData->offset_xy.x) *
                                    sharedData->rate_resize - (float)(video_cols * (sharedData->rate_resize - 1) / 2);
                            point_map.y = (usbCam.Cams[i].map_corners[j].y + sharedData->offset_xy.y) *
                                    sharedData->rate_resize - (float)(video_rows * (sharedData->rate_resize - 1) / 2);
                            temp_corner.push_back(point_map);
                        }
                        update_GpuMapxy(temp_corner, usbCam.Cams[i].gpu_mapx, usbCam.Cams[i].gpu_mapy, sharedData->numBlocks, sharedData->threadsPerBlock);
                    }
                }
                break;
            default:
                break;
        }
    }
    if(sharedData->isUpdateCC) {
        sharedData->isUpdateCC = false;
        sharedData->camSnapshot.clear();
        update_ColorCorrection(Cams, Videos, usbCam);
    }
    switch (sharedData->inputMedia) {
        case 0:
            for(int i = 0; i < camera_nums; i++) {
                if(table_cam[i] != -1) {
                    if(sharedData->isColorCorrection) {
                        usbImageToGpuMat(usbCam.usbCams[table_cam[i]], usbCam.Cams[i].gpu_src, gpuGTable);
                        // TODO usb image to GpuMat with color correction
                    }else {
                        usbImageToGpuMat(usbCam.usbCams[table_cam[i]], usbCam.Cams[i].gpu_src, gpuGTable);
                    }
                }else {
                    usbCam.Cams[i].gpu_dst = gpuEmpty;
                }

            }

            for(int i = 0; i < camera_nums; i++) {
                if(sharedData->isInterFrame) {
                    if(frame_cnt % 2 == 0) {
                        cuda::remap(usbCam.Cams[i].gpu_src, usbCam.Cams[i].gpu_frame2, usbCam.Cams[i].gpu_mapx, usbCam.Cams[i].gpu_mapy, INTER_NEAREST, BORDER_CONSTANT, cv::Scalar(0, 0, 0));
                    }else {
                        cuda::remap(usbCam.Cams[i].gpu_src, usbCam.Cams[i].gpu_frame1, usbCam.Cams[i].gpu_mapx, usbCam.Cams[i].gpu_mapy, INTER_NEAREST, BORDER_CONSTANT, cv::Scalar(0, 0, 0));
                    }
                }else {
                    cuda::remap(usbCam.Cams[i].gpu_src, usbCam.Cams[i].gpu_dst, usbCam.Cams[i].gpu_mapx, usbCam.Cams[i].gpu_mapy, INTER_NEAREST, BORDER_CONSTANT, cv::Scalar(0));
                }
            }

            if(sharedData->isInterFrame) {
                for(int i = 0; i < camera_nums; i++) {
                    stitchOpt_twolayer(gpuStitchResult, usbCam.Cams[i].gpu_frame1, usbCam.Cams[i].gpu_frame2, usbCam.Cams[i].gpu_buffer, gpuStitchResult, frame_cnt % 2, sharedData->numBlocks, sharedData->threadsPerBlock);
                }
            }else {
                stitch_twolayer(usbCam.Cams[0].gpu_dst, usbCam.Cams[1].gpu_dst, gpuStitchResult, sharedData->numBlocks, sharedData->threadsPerBlock);
                if(camera_nums > 2) {
                    for(int i = 2; i < camera_nums; i++) {
                        stitch_twolayer(gpuStitchResult, usbCam.Cams[i].gpu_dst, gpuStitchResult, sharedData->numBlocks, sharedData->threadsPerBlock);
                    }
                }
            }

            cuda::resize(gpuStitchResult, gpuStitchViewResult, Size(view_cols, view_rows), 0, 0, INTER_CUBIC);
            funcStitchProcess();
            cv::cvtColor(cpuStichResult, res.view_stitch, COLOR_BGR2RGB);
            emit ack(res);
            break;
        default:
         break;
     }
}



bool Backend::funcStreamProcessOpt()
{
    bool success;
    switch (sharedData->inputMedia) {
        case 0:
            if(sharedData->isDehaze && !sharedData->isEnhance) {
                dehaze_opt(usbCam.Cams[sharedData->idx_camSelect].gpu_frame1, usbCam.Cams[sharedData->idx_camSelect].gpu_frame2, res_dehaze,
                        res_darkch, res_tran, usbCam.Cams[sharedData->idx_camSelect].gpu_buffer, frame_cnt % 2,
                        sharedData->air_val, sharedData->numBlocks, sharedData->threadsPerBlock);
                res_dehaze.download(imgMultiCam[sharedData->idx_camSelect]);
            }else if(sharedData->isEnhance && !sharedData->isDehaze) {
                enhance_opt(usbCam.Cams[sharedData->idx_camSelect].gpu_frame1, usbCam.Cams[sharedData->idx_camSelect].gpu_frame2, res_enhanceLL,
                        res_darkch, res_tran_LL, usbCam.Cams[sharedData->idx_camSelect].gpu_buffer, frame_cnt % 2,
                        sharedData->enhance_kVal, sharedData->air_val, sharedData->numBlocks, sharedData->threadsPerBlock);
                res_enhanceLL.download(imgMultiCam[sharedData->idx_camSelect]);
            }else if(sharedData->isDehaze && sharedData->isEnhance) {
                dehaze_opt(usbCam.Cams[sharedData->idx_camSelect].gpu_frame1, usbCam.Cams[sharedData->idx_camSelect].gpu_frame2, res_dehaze,
                        res_darkch, res_tran, usbCam.Cams[sharedData->idx_camSelect].gpu_buffer, frame_cnt % 2,
                        sharedData->air_val, sharedData->numBlocks, sharedData->threadsPerBlock);
                enhance(res_dehaze, res_enhanceLL, res_darkch, res_tran_LL, sharedData->enhance_kVal, sharedData->air_val, sharedData->numBlocks, sharedData->threadsPerBlock);
                res_enhanceLL.download(imgMultiCam[sharedData->idx_camSelect]);
            }
            else {
                if(frame_cnt % 2 == 0) {
                    usbCam.Cams[sharedData->idx_camSelect].gpu_frame2.download(imgMultiCam[sharedData->idx_camSelect]);
                }else {
                    usbCam.Cams[sharedData->idx_camSelect].gpu_frame1.download(imgMultiCam[sharedData->idx_camSelect]);
                }
            }
            break;
        default:
            break;
    }

    success = true;
    return success;
}

bool Backend::funcStreamProcess()
{
    float zoom_check = (sharedData->zoom_Val) / 10.0 + 1;
    int tmp_idxCamSelect = -1;
    if(zoom_check < 3) {
        tmp_idxCamSelect = 0;
    }else if(zoom_check < 5){
        tmp_idxCamSelect = 1;
    }else if(zoom_check < 7) {
        tmp_idxCamSelect = 2;
    }else {
        tmp_idxCamSelect = 3;
    }
    bool success = false;
    if(sharedData->isDehaze && !sharedData->isEnhance) {
        dehaze(gpu_rgb, res_dehaze, res_darkch, res_tran, sharedData->air_val, sharedData->numBlocks, sharedData->threadsPerBlock);
        res_dehaze.download(imgMultiCam[tmp_idxCamSelect]);
    }else if(sharedData->isEnhance && !sharedData->isDehaze) {
        enhance(gpu_rgb, res_enhanceLL, res_darkch, res_tran_LL, sharedData->enhance_kVal, sharedData->air_val, sharedData->numBlocks, sharedData->threadsPerBlock);
        res_enhanceLL.download(imgMultiCam[tmp_idxCamSelect]);
    }else if(sharedData->isEnhance && sharedData->isDehaze) {
        dehaze(gpu_rgb, res_dehaze, res_darkch, res_tran, sharedData->air_val, sharedData->numBlocks, sharedData->threadsPerBlock);
        enhance(res_dehaze, res_enhanceLL, res_darkch, res_tran_LL, sharedData->enhance_kVal, sharedData->air_val, sharedData->numBlocks, sharedData->threadsPerBlock);
        res_enhanceLL.download(imgMultiCam[tmp_idxCamSelect]);
    }else {
        gpu_rgb.download(imgMultiCam[tmp_idxCamSelect]);
    }

    success = true;
    return success;
}

bool Backend:: funcStitchProcess()
{
    bool success = false;
    if(sharedData->isDehaze && !sharedData->isEnhance) {
        dehaze(gpuStitchViewResult, view_dehaze, view_darkch, view_tran, sharedData->air_val, sharedData->view_numBlocks, sharedData->view_threadsPerBlock);
        view_dehaze.download(cpuStichResult);
    }else if(sharedData->isEnhance && !sharedData->isDehaze) {
        enhance(gpuStitchViewResult, view_enhanceLL, view_darkch, view_tran_LL, sharedData->enhance_kVal, sharedData->air_val, sharedData->view_numBlocks, sharedData->view_threadsPerBlock);
        view_enhanceLL.download(cpuStichResult);
    }else if(sharedData->isDehaze && sharedData->isEnhance) {
        dehaze(gpuStitchViewResult, view_dehaze, view_darkch, view_tran, sharedData->air_val, sharedData->view_numBlocks, sharedData->view_threadsPerBlock);
        enhance(view_dehaze, view_enhanceLL, view_darkch, view_tran_LL, sharedData->enhance_kVal, sharedData->air_val, sharedData->view_numBlocks, sharedData->view_threadsPerBlock);
        view_enhanceLL.download(cpuStichResult);
    }else {
        gpuStitchViewResult.download(cpuStichResult);
    }

    success = true;
    return success;
}

void Backend::update_usb_cam_param(UsbCam usbCam)
{
    
}

bool Backend::update_ColorCorrection(vector<Cam>& Cams, vector<Video>& Videos, UsbCam& usbCam)
{
    std::vector<Mat> camSnapShot;
    camSnapShot.clear();
    switch (sharedData->inputMedia) {
        case 0:
            for(int i = 0; i < camera_nums; i++) {
                camSnapShot.push_back(readUsbImg(usbCam.usbCams[i]));
            }
            for(int i = 0; i < camera_nums; i++) {
                Mat Mask_roi = Mat(video_rows, video_cols, CV_8UC1, Scalar(0));
                vector<vector<Point>> contour;
                vector<Point> pts;
                pts.push_back(usbCam.Cams[i].map_corners[0]);
                pts.push_back(usbCam.Cams[i].map_corners[1]);
                pts.push_back(usbCam.Cams[i].map_corners[2]);
                pts.push_back(usbCam.Cams[i].map_corners[3]);
                contour.push_back(pts);

                drawContours(Mask_roi, contour, 0, Scalar::all(255), -1);

                usbCam.Cams[i].gpu_src.upload(camSnapShot[i]);
                cuda::remap(usbCam.Cams[i].gpu_src, usbCam.Cams[i].gpu_dst, usbCam.Cams[i].gpu_mapx, usbCam.Cams[i].gpu_mapy,
                            INTER_NEAREST, BORDER_CONSTANT, Scalar(0));
                Mat dst;
                usbCam.Cams[i].gpu_dst.download(dst);

                Scalar Mean_color = mean(dst, Mask_roi);
                Scalar MeanBG_color = mean(camSnapShot[0], Mask_roi);

                for(int j = 0; j < 3; j++) {
                    usbCam.Cams[i].factorBGR[j] = (float)MeanBG_color[j] / (float)Mean_color[j];
                }
            }
            break;
        default:
            break;
    }
    return true;
}



//get stitch corner from txt
vector<Point2f> getCornerFromTxt(QString CornerAddr)
{
    vector<Point2f> result;
    QFile f(CornerAddr);
    if(!f.open(QIODevice::ReadOnly | QIODevice::Text))
        std::cout << "CornerSet.txt file is not found, please check the folder" << std::endl;


    QTextStream txtInput(&f);
    for(int i = 0; i < camera_nums; i++) {
        QString lineStr;
        lineStr = txtInput.readLine();
        for(int j = 0; j < 4; j ++) {
            float x = lineStr.section('\t', 2 * j, 2 * j ).trimmed().toFloat();
            float y = lineStr.section('\t', 2 * j + 1, 2 * j + 1).trimmed().toFloat();
            result.push_back(cv::Point2f(x , y));
            qDebug() <<" cam: "<< i <<" corner: "<< j << " x: "<< x <<" y: " << y;
        }
    }
    return result;
}

// get stitch corner from sift
vector<Point2f> getCornerFromSift(vector<Mat> camSnapshot)
{
    vector<Point2f> result;
    result.push_back(Point2f(0, 0));
    result.push_back(Point2f(video_cols, 0));
    result.push_back(Point2f(video_cols, video_rows));
    result.push_back(Point2f(0, video_rows));
    if(camera_nums > 1) {
        vector<Point2f> tmp_corner;
        tmp_corner.clear();
        for(int i = 0; i < camera_nums - 1; i++) {
            tmp_corner = findStitchCorner(camSnapshot[i + 1], camSnapshot[0], i + 1, 0);

            if(tmp_corner.size() != 0) {
                for(unsigned int j = 0; j < tmp_corner.size(); j++) {
                    result.push_back(tmp_corner[j]);
                }
            }else {
                result.push_back(Point2f(0, 0));
                result.push_back(Point2f(video_cols, 0));
                result.push_back(Point2f(video_cols, video_rows));
                result.push_back(Point2f(0, video_rows));
                qDebug() << "Can't find the corner on the image" << endl;
            }
        }
    }
    return result;
}
