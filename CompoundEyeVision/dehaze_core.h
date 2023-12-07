#ifndef DEHAZE_CORE_H
#define DEHAZE_CORE_H


#include <device_launch_parameters.h>
#include <cuda_device_runtime_api.h>

#include <opencv2/core/cuda.hpp>
#include <opencv2/cudawarping.hpp>
#include <opencv2/calib3d.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/core/version.hpp>
#include <opencv2/core/fast_math.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv_modules.hpp>
#include <opencv2/cudaarithm.hpp>
#include <opencv2/cudafilters.hpp>
#include <opencv2/cudaimgproc.hpp>

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "cuda_function.h"

// Normal dehaze
void dehaze(cuda::GpuMat src, cuda::GpuMat result, cuda::GpuMat dark_ch, cuda::GpuMat tran, float air[], dim3 numBlocks, dim3 threadsPerBlock);

// dehaze with inter frames
void dehaze_opt(cuda::GpuMat frame1, cuda::GpuMat frame2, cuda::GpuMat result, cuda::GpuMat dark_ch,
                cuda::GpuMat tran, cuda::GpuMat buffer, bool isOdd, float air[], dim3 numBlocks, dim3 threadsPerBlock);

//calDarkC
void calDarkChannel(cuda::GpuMat src, cuda::GpuMat dst, dim3 numBlocks, dim3 threadsPerBlock);

// For guidedfilter
void boxfiter(cuda::GpuMat& I, cuda::GpuMat result, cv::Ptr<cuda::Filter> filter);
void GuidedFilterMono(cuda::GpuMat& I, cuda::GpuMat& I_mul, cuda::GpuMat& mean_I, cuda::GpuMat& mean_mul, cuda::GpuMat& mean_II,
                      cuda::GpuMat& var_I, cv::Ptr<cuda::Filter> filter);
void filterSingleChannel(cuda::GpuMat& p, cuda::GpuMat& I, cuda::GpuMat& mean_p, cuda::GpuMat& mean_I, cuda::GpuMat& var_I,
                         cuda::GpuMat& mean_Imulp, cuda::GpuMat& Imul_p, cuda::GpuMat& cov_Ip, cuda::GpuMat& meanImul_meanp,
                         cuda::GpuMat& a, cuda::GpuMat& b, cuda::GpuMat& mean_a, cuda::GpuMat& mean_b,
                         cuda::GpuMat& varI_addeps, cuda::GpuMat eps_mat,
                         cuda::GpuMat& amul_meanI,
                         cuda::GpuMat& filter_dst, cv::Ptr<cuda::Filter> filter);

// dehaze with guidefilter
void dehaze_withGF(cuda::GpuMat src, cuda::GpuMat result, cv::Ptr<cv::cuda::Filter> filter, float air[], dim3 numBlocks, dim3 threadsPerBlock,
                   cuda::GpuMat dark_ch, cuda::GpuMat grey, cuda::GpuMat tran,
                   cuda::GpuMat I_mul, cuda::GpuMat mean_I, cuda::GpuMat mean_mul, cuda::GpuMat mean_II, cuda::GpuMat var_I, cuda::GpuMat mean_p,
                   cuda::GpuMat mean_Imulp, cuda::GpuMat Imul_p, cuda::GpuMat cov_Ip, cuda::GpuMat meanImul_meanp, cuda::GpuMat a, cuda::GpuMat b,
                   cuda::GpuMat mean_a, cuda::GpuMat mean_b, cuda::GpuMat varI_addeps, cuda::GpuMat eps_mat, cuda::GpuMat amul_meanI, cuda::GpuMat filter_dst);

#endif // DEHAZE_CORE_H
