#ifndef TYPE_H
#define TYPE_H
#include <device_launch_parameters.h>
#include <cuda_device_runtime_api.h>

#include <opencv2/core/cuda.hpp>
#include <opencv2/cudawarping.hpp>
#include <opencv2/calib3d.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/cudacodec.hpp>

#include <vector>

//#include "mtcnn.h"
//#include "cnn_detect.hpp"
//#include "dat_tracker.hpp"
//#include "sort.hpp"

//for open video or camera width and height
#define video_cols 1920
#define video_rows 1080
//for Screen size
#define view_cols 1920
#define view_rows 1080

//for subScreen size
#define subview_cols 640
#define subview_rows 360

#define camera_nums 6  //Downward compatibility

//焦段差距越大，则匹配点数量应该尽量调小   5,4~200   5,6~200
// int matchPNum[camera_nums] = {800, 900, 900, 900, 200, 200};  // threshold: 10 ~ 900

using namespace cv;
using namespace std;

//for webcam or video
typedef struct
{
    VideoCapture camera;
    Mat frame;
    //GPU Mat for remap
    cuda::GpuMat gpu_mapx;
    cuda::GpuMat gpu_mapy;
    //GPU Mat input for cuda functions
    cuda::GpuMat gpu_src;
    cuda::GpuMat gpu_tmp;
    cuda::GpuMat gpu_dst;
    //GPU Mat input for interframe
    cuda::GpuMat gpu_frame1;
    cuda::GpuMat gpu_frame2;
    cuda::GpuMat gpu_buffer;
    //The stitching location
    vector<Point2f> map_corners;
    //Image color channel factor
    float factorBGR[3] = {1, 1, 1};
} Cam;

//for RTSP or video NVDEC
typedef struct
{
    cv::Ptr<cv::cudacodec::VideoReader> videos;
    Mat frame;
    //GPU Mat for remap
    cuda::GpuMat gpu_mapx;
    cuda::GpuMat gpu_mapy;
    //GPU Mat input for cuda functions
    cuda::GpuMat gpu_src;
    cuda::GpuMat gpu_bgra;
    cuda::GpuMat gpu_gamma;
    cuda::GpuMat gpu_tmp;
    cuda::GpuMat gpu_dst;
    cuda::GpuMat gpu_view;
    //GPU Mat input for interframe
    cuda::GpuMat gpu_frame1;
    cuda::GpuMat gpu_frame2;
    cuda::GpuMat gpu_buffer;
    //The stitching location
    vector<Point2f> map_corners;
    //Image color channel factor
    float factorBGR[3] = {1, 1, 1};
} Video;

//flycam and spincam camParam
typedef struct
{
    double exposure_val;
    double brightness_val;
    double shutter_val;
    double gain_val;
    double wb_val1;
    double wb_val2;
} camParam;

//for usbcam and spincam
typedef struct
{
    Mat frame;
    //GPU Mat for remap
    cuda::GpuMat gpu_mapx;
    cuda::GpuMat gpu_mapy;
    //GPU Mat input for cuda functions
    cuda::GpuMat gpu_raw;
    cuda::GpuMat gpu_src;
    cuda::GpuMat gpu_dst;
    cuda::GpuMat gpu_tmp;
    //GPU Mat input for interframe
    cuda::GpuMat gpu_frame1;
    cuda::GpuMat gpu_frame2;
    cuda::GpuMat gpu_buffer;
    //The stitching location
    vector<Point2f> map_corners;
    camParam camparam;
    //Image color channel factor
    float factorBGR[3] = {1, 1, 1};
} cam;

//main view
typedef struct
{
    int id;
    vector<float> main_hist;
}Main_view;

typedef struct
{
    int id;
    vector<float> part_hist;
}Part_view;

class SharedData {
public:
    //0:usb; 1:video;
    int inputMedia = 0;
    //Detect keyboard status by pressing
    bool isKeyIn = false;
    //Use sift methods to match feature point
    bool isMatch = false;
    //Use dehaze method
    bool isDehaze = false;
    //Use lowlight enhancement method
    bool isEnhance = false;

    // Use track method
    bool isTrack = false;
    //Use color correction options for stitch view
    bool isColorCorrection = false;
    //Use the inter-frame acceleration
    bool isInterFrame = false;
    //Update camera param by CameraProperty.txt
    bool isUpdateParam = false;
    //Update color correction by camsnapshot
    bool isUpdateCC = false;

    bool isTwinView = false;
    //Table index
    int idx_table = 0;
    //Camera options index
    int idx_camSelect = 0;
    //Low light enhancement factor
    int enhance_kVal = 3;
    //Zoom factor
    int zoom_Val = 1;

    //camera adjustment params
    int cam0_x = 0;
    int cam0_y = 0;
    int cam0_r = 0;
    int cam0_z = 0;

    int cam1_x = 0;
    int cam1_y = 0;
    int cam1_r = 0;
    int cam1_z = 0;

    int cam2_x = 0;
    int cam2_y = 0;
    int cam2_r = 0;
    int cam2_z = 0;

//    int cam3_x = 0;
//    int cam3_y = 0;
//    int cam3_r = 0;
//    int cam3_z = 0;

    int camGlobal_r = 0;
    int camGlobal_z = 0;

    //The step size of the window changes
    int step_offset = 10;
    //The original point on windows
    cv::Point offset_xy = cv::Point(0,0);
    //The scaling factor of windows zoom in or out
    float rate_resize = 1;
    //The channel factor of dehaze and enhancement
    float air_val[3] = {0.7, 0.7, 0.7};

//    float factor = 0.709f;
//    float threshold[3] = { 0.8f, 0.8f, 0.8f };
//    int minSize = 30;
    //Image snapshot for matching feature point
    std::vector<cv::Mat> camSnapshot;
//    //Track param
//    float conf_th = 0.75;
//    vector<TrackingBox> tracking_results;
//    SORT *sorter1;
//    SORT *sorter2;

    vector<Main_view> main_crop;
    vector<Part_view> part_crop;
    bool main_lock = false;
    bool part_lock = false;
    //Cuda blocks
    dim3 numBlocks;
    dim3 threadsPerBlock;
    //Cuda blocks
    dim3 view_numBlocks;
    dim3 view_threadsPerBlock;

    bool isRest = false;
    bool isExistRect = false;
    bool isPressMouse = false;
    bool isMouseLatch = false;
    bool isStartMove = false;
    int widget_width = 0;
    int widget_height = 0;

    cv::Point start_mouse_pos = cv::Point(0,0);
    cv::Point end_mouse_pos = cv::Point(0,0);

};

class StreamResult {
public:
     cv::Mat view[camera_nums];
     cv::Mat view_stitch;
     cv::Mat view_base;
};



#endif
