#ifndef CUDA_FUNCTION_H
#define CUDA_FUNCTION_H

#include <cuda.h>
#include <cuda_runtime.h>
#include <device_launch_parameters.h>
#include <cuda_device_runtime_api.h>

#include <opencv2/core/cuda.hpp>

#include <stdlib.h>
#include <iostream>
#include <time.h>

#define Min(x, y) ((x < y) ? x : y)

using namespace cv;
using namespace std;

void getImage_WithCC(cuda::GpuMat src, cuda::GpuMat dst, float air_ch[], dim3 numBlocks, dim3 threadsPerBlock);
//Gamma correction for video
void getImage_WithGamma(cuda::GpuMat src, cuda::GpuMat dst, cuda::GpuMat &GTable, dim3 numBlocks, dim3 threadsPerBlock);
//Homography matrix generation with corner information
void genCornerHomo(cuda::GpuMat &gpuH_inv, cuda::GpuMat &maps_x, cuda::GpuMat &maps_y, dim3 numBlocks, dim3 threadsPerBlock);
//get Dehaze result
void getDehaze(cuda::GpuMat src, cuda::GpuMat dehaze_res, cuda::GpuMat trans, float air_val[], dim3 numBlocks, dim3 threadsPerBlock);
//get Transmit result
void getTransmit(cuda::GpuMat src, cuda::GpuMat trans, dim3 numBlocks, dim3 threadsPerBlock);
//get Dark channel result
void getDarkChannel(cuda::GpuMat src, cuda::GpuMat dark_ch, dim3 numBlocks, dim3 threadsPerBlock);
//get Dehaze optimizing with interframe
void getDehaze_opt(cuda::GpuMat frame1, cuda::GpuMat frame2, cuda::GpuMat result, cuda::GpuMat darks, cuda::GpuMat trans,
                   cuda::GpuMat buffers, bool isOdd, float air_val[], dim3 numBlocks, dim3 threadsPerBlock);
//get Low Light Transmit
void getLowLightTransmit(cuda::GpuMat src, cuda::GpuMat trans, dim3 numBlocks, dim3 threadsPerBlock);
//get enhancement result
void getEnhancement(cuda::GpuMat src, cuda::GpuMat enhance_res, cuda::GpuMat trans, float enhace_val, float air_val[], dim3 numBlocks, dim3 threadsPerBlock);
//get enhancement result optimizing with interframe
void getEnhancement_opt(cuda::GpuMat frame1, cuda::GpuMat frame2, cuda::GpuMat result, cuda::GpuMat darks, cuda::GpuMat trans, cuda::GpuMat buffers,
                        bool isOdd, float enhace_val, float air_val[], dim3 numBlocks, dim3 threadsPerBlock);
//Stitch function
void getStitch(cuda::GpuMat &bottom_layer, cuda::GpuMat &top_layer, cuda::GpuMat &dst_layer, dim3 numBlocks, dim3 threadsPerBlock);
void getStitchOpt(cuda::GpuMat &bottom_layer, cuda::GpuMat &top_layer1, cuda::GpuMat &top_layer2,
                      cuda::GpuMat &top_buffer, cuda::GpuMat &dst_layer, bool isOdd, dim3 numBlocks, dim3 threadsPerBlock);

#endif // CUDA_FUNCTION_H
