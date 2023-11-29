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

    std::vector<cam> Cams;

    VideoCapture* usbCams;

    void open_usbcam();
    void close_usbcam();
};

void usbImageToGpuMat(VideoCapture camera, cuda::GpuMat& GpuRGB, cuda::GpuMat& GTable);

#endif // OPEN_USBCAM_H
