#ifndef OPEN_USBCAM_H
#define OPEN_USBCAM_H

#include <iostream>
#include <string.h>

#include <opencv2/cudaarithm.hpp>

#include <QDebug>

#include "type.h"

using namespace cv;
using namespace std;


class UsbCam
{
public:
    UsbCam();
    ~UsbCam();

    // equl to cam_num by type.h;
    int cam_maxnum = 6;

    std::vector<int> cam_idx;

    // Saves the data for the gpu part of each camera
    std::vector<cam> Cams;

    // VideoCapture type,
    VideoCapture* usbCams;

    void open_usbcam();
    void close_usbcam();
};

void usbImageToGpuMat(VideoCapture camera, cuda::GpuMat& GpuRGB, cuda::GpuMat& GTable);
Mat readUsbImg(VideoCapture camera);
#endif // OPEN_USBCAM_H
