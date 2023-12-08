/**
 * @file open_usbcam.cpp
 * @author jackew
 * @date 2023-11-22
 * @brief This file contains the functions related to opening usb cameras.
 *        If additional driver cameras need to be added in the future, a class with the corresponding name can be created.
 *
 * Copyright (c) 2023.
 */

#include "open_usbcam.h"

UsbCam::UsbCam()
{

}

UsbCam:: ~UsbCam()
{

}

/**
 * @brief open multi usb cameras
 */
void UsbCam::open_usbcam()
{
    // idx starts from 0
    usbCams = new VideoCapture[cam_maxnum];
    for(int i = 0; i < cam_maxnum; i++) {
//        usbCams[i].open("/dev/video_" + to_string(i));
        qDebug() << "open Camera:" << i * 2 << endl;
        usbCams[i].open(i * 2, CAP_V4L2);
        if(!usbCams[i].isOpened()) {
            delete[] usbCams;
            qDebug() << "usb carema " << i << " not open!" << endl;
            return;
        }
        cam_idx.push_back(i);
    }
    // fill the maximum carema numbers
    for(int i = cam_idx.size(); i < cam_maxnum; i++) {
        cam_idx.push_back(-1);
    }
}


void UsbCam::close_usbcam()
{
    for(int i = 0; i < cam_maxnum; i++) {
        usbCams[i].release();
    }
    delete[] usbCams;
}

Mat readUsbImg(VideoCapture camera)
{
    Mat img;
    camera.read(img);
    if(img.empty()) {
        std::cerr << "image is empty!" << endl;
    }
    cvtColor(img, img, cv::COLOR_BGR2RGB);

    return img;
}

/**
 * @brief cover the Mat type to GpuMat type
 * @param src_img: Image format for USB camera direct output
 * @param GpuRGB: Target format for gpumat type
 * @param GTable
 */
void usbImageToGpuMat(VideoCapture camera, cuda::GpuMat& GpuRGB, cuda::GpuMat& GTable)
{
    cv::Mat src_img;
    cv::Mat gamma_img;
    cv::Mat MTable;
    camera.read(src_img);
    if(src_img.empty()) {
        std::cerr << "src image is empty!" << endl;
    }
    if(src_img.channels() == 1) {
        std::cerr << "The src_img is one channel!" << endl;
    }
    cvtColor(src_img,src_img,cv::COLOR_BGR2RGB);
    GTable.download(MTable);
//    GpuRGB.upload(src_img);

    //gamma correction
    cv::LUT(src_img, MTable, gamma_img);

    GpuRGB.upload(gamma_img);
}
