#ifndef BACKEND_H
#define BACKEND_H

#include <QObject>
#include <QDateTime>
#include <QThread>
#include <QFile>
#include <QDebug>

#include <opencv2/opencv.hpp>
#include <opencv2/cudacodec.hpp>
#include <opencv2/core/cuda.hpp>
#include <opencv2/core/cuda_stream_accessor.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/xfeatures2d/nonfree.hpp>
#include <opencv2/cudafeatures2d.hpp>
#include <opencv2/cudaimgproc.hpp>
#include <opencv2/xfeatures2d/cuda.hpp>
#include <opencv2/core/mat.hpp>

#include <iostream>
#include <time.h>
#include <string>
#include <cmath>

#include "type.h"
#include "stitch_core.h"
#include "open_usbcam.h"

class MainWindow;

class Backend : public QObject
{
    Q_OBJECT
public:
    Backend(SharedData* shareddata, MainWindow* parent);
    ~Backend();

    bool open_usbcam();
    bool close_usbcam();
    void update_usb_cam_param(UsbCam usbCam);
//    void update_corner_param(); // update corner param to implement stitch function.

    vector<Point2f> autoFindCorner();

//    Mat surfDetect(Mat imagelf, Mat imagesf, int index);
//    Point2f getTransformPoint(const Point2f originalPoint, const Mat &transformMaxtri);


public slots:
    void core();
    void streamStitch();
    void StreamMultiCam();
    void streamSingleCam();


    bool initGpuMat();
    bool funcStreamProcess();
    bool funcStreamProcessOpt();
    bool funcStitchProcess();

    bool update_ColorCorrection(vector<Cam>& Cams, vector<Video>& Videos, UsbCam& usbCam);

signals:
    void ack(StreamResult res);

private:
    MainWindow* parent;
    SharedData* sharedData;

    // Camera interface
    vector<Cam> Cams;
    vector<Video> Videos;
    UsbCam usbCam;

    // Subview Mat
    cv::Mat imgMultiCam[camera_nums];
    cv::Mat cvtimgMultiCam[camera_nums];

    // Empty Mat
    Mat empty = Mat(Size(1280, 720), CV_8UC3, cv::Scalar(0, 0, 0));

    //Camera mapping table
    vector<int> table_cam;

    //The result
    Mat cpuStichResult;
    Mat cpuTwinResult;
    cuda::GpuMat gpuStitchResult;
    cuda::GpuMat res_gpu_view;
    cuda::GpuMat gpuStitchViewResult;

    //Gamma table for linear camera
    Mat cpuGtable = Mat(Size(256, 1), CV_8UC1, cv::Scalar(0, 0, 0));

    // Gamma table for NVdec video
    Mat cpuInvGTable = Mat(Size(256, 1), CV_8UC1, cv::Scalar(0, 0, 0));
    cuda::GpuMat gpuGTable;
    cuda::GpuMat gpuInvGTable;

    // For empty display
    cuda::GpuMat gpuEmpty;

    //For dehaze
    cuda::GpuMat res_dehaze;
    cuda::GpuMat res_darkch;
    cuda::GpuMat res_tran;

    // For lowlight enhancement
    cuda::GpuMat res_tran_LL;
    cuda::GpuMat res_enhanceLL;

    // Locale gpumat for Mainview display
    cuda::GpuMat gpu_src;
    cuda::GpuMat gpu_dst;
    cuda::GpuMat gpu_raw;
    cuda::GpuMat gpu_rgb;
    cuda::GpuMat gpu_view;

    // Locale gpumat for cuda function
    cuda::GpuMat view_dehaze;
    cuda::GpuMat view_darkch;
    cuda::GpuMat view_tran;
    cuda::GpuMat view_tran_LL;
    cuda::GpuMat view_enhanceLL;

    // The results on stitch and camstream
    StreamResult res;

    // The capture counts
    int frame_cnt;

    // Cuda stream
    cv::cuda::Stream cvStream;
    cudaStream_t cudaStream;


    float remap_wscale;
    float remap_hscale;
    double log_a;
    double log_b;
    double scale_time;


    int offset_setpx;
    int offset_setpy;

    cv::Rect Roi_view;
    cv::Rect Move_view;
    cv::Mat Mask;
    cv::Mat temp_img;
    cv::Mat test_img;

    cv::Point offset_location;
    cv::Point roi_location;
    cv::Point target_location;

     // ???
    int matchPNum[camera_nums] = {100, 100};

};

// get camera property
//vector<camParam> getPropertyFromTxt(QString PropertyAddr);

//get stitch corner from txt
vector<Point2f> getCornerFromTxt(QString CornerAddr);

// get stitch corner from sift
vector<Point2f> getCornerFromSift(vector<Mat> camSnapshot);

#endif // BACKEND_H
