#ifndef STITCH_CORE_H
#define STITCH_CORE_H

#include <device_launch_parameters.h>
#include <cuda_device_runtime_api.h>

#include <opencv2/core/cuda.hpp>
#include <opencv2/cudawarping.hpp>
#include <opencv2/calib3d.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv_modules.hpp>

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "type.h"
#include "cudaImage.h"
#include "cudaSift.h"
#include "cuda_function.h"

void update_GpuMapxy(std::vector<Point2f> obj_corners, cuda::GpuMat& maps_x, cuda::GpuMat& maps_y, dim3 numBlocks, dim3 threadsPerBlock);

void stitch_twolayer(cuda::GpuMat& bottom_layer, cuda::GpuMat& top_layer, cuda::GpuMat& dst_layer, dim3 numBlocks, dim3 threadsPerBlock);

void stitchOpt_twolayer(cuda::GpuMat& bottom_layer, cuda::GpuMat& top_layer1, cuda::GpuMat& top_layer2, cuda::GpuMat& top_buffer,
                        cuda::GpuMat& dst_layer, bool isOdd, dim3 numBlocks, dim3 threadsPerBlock);

vector<cv::Point2f> findStitchCorner(Mat Left_img, Mat Right_img, int idx_left, int idx_right);


#endif // STITCH_CORE_H
