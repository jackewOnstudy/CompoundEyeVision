#include "cuda_function.h"


__global__ void map_kernel(cuda::PtrStepSz<double> map_Hinv, cuda::PtrStepSz<float> mapx, cuda::PtrStepSz<float> mapy)
{
    int i = threadIdx.x + blockIdx.x * blockDim.x;
    int j = threadIdx.y + blockIdx.y * blockDim.y;

    mapx(j, i) = ((map_Hinv(0, 0) * i + map_Hinv(0, 1) * j + map_Hinv(0, 2)) / (map_Hinv(2, 0) * i + map_Hinv(2, 1) * j + map_Hinv(2, 2)));
    mapy(j, i) = ((map_Hinv(1, 0) * i + map_Hinv(1, 1) * j + map_Hinv(1, 2)) / (map_Hinv(2, 0) * i + map_Hinv(2, 1) * j + map_Hinv(2, 2)));
}

/**
 * @brief stitch_kernel
 * 在合并两个图层时，以非零像素为准。如果顶层图像的像素值为零，则选择底层图像的像素值。
 * 这种操作通常用于遮罩效果，其中顶层图像的非零像素表示前景，零像素表示透明区域，而底层图像则充当背景。
 * @param bottom
 * @param top
 * @param dst
 */
__global__ void stitch_kernel(cuda::PtrStepSz<uchar3> bottom, cuda::PtrStepSz<uchar3> top, cuda::PtrStepSz<uchar3> dst)
{
    int i = threadIdx.x + blockIdx.x * blockDim.x;
    int j = threadIdx.y + blockIdx.y * blockDim.y;

    dst(j, i).x = top(j, i).x > 0 ? top(j, i).x : bottom(j, i).x;
    dst(j, i).y = top(j, i).y > 0 ? top(j, i).y : bottom(j, i).y;
    dst(j, i).z = top(j, i).z > 0 ? top(j, i).z : bottom(j, i).z;
}

/**
 * @brief stitchOpt_kernel
 * 通过线程坐标 (i, j) 计算每个像素位置。top_buffer 中的像素值递减，
 * 且如果 diff_val 大于阈值（20），则 top_buffer 中的像素值被设置为 30。
 * 根据 top_buffer 的值，决定选择哪个顶层或底层的像素值作为输出。
 * @param bottom
 * @param top1
 * @param top2
 * @param top_buffer
 * @param dst
 * @param odd
 */
__global__ void stitchOpt_kernel(cuda::PtrStepSz<uchar3> bottom, cuda::PtrStepSz<uchar3> top1, cuda::PtrStepSz<uchar3> top2,
                                 cuda::PtrStepSz<uchar> top_buffer, cuda::PtrStepSz<uchar3> dst, bool odd)
{
    int i = threadIdx.x + blockIdx.x * blockDim.x;
    int j = threadIdx.y + blockIdx.y * blockDim.y;

    if(top_buffer(j, i) > 0) top_buffer(j, i)--;
    int diff_val = 0;

    if(odd)
        diff_val = abs( bottom(j, i).x - top1(j, i).x) + abs(bottom(j, i).y - top1(j, i).y) + abs(bottom(j, i).z - top1(j, i).z);
    else
        diff_val = abs( bottom(j, i).x - top2(j, i).x) + abs(bottom(j, i).y - top2(j, i).y) + abs(bottom(j, i).z - top2(j, i).z);
    if(diff_val > 20) top_buffer(j, i) = 30;

    if (top_buffer(j, i) > 0 ) {
        if(odd){
            dst(j, i).x = top1(j, i).x > 0 ? top1(j, i).x : bottom(j, i).x;
            dst(j, i).y = top1(j, i).y > 0 ? top1(j, i).y : bottom(j, i).y;
            dst(j, i).z = top1(j, i).z > 0 ? top1(j, i).z : bottom(j, i).z;
        }
        else {
            dst(j, i).x = top2(j, i).x > 0 ? top2(j, i).x : bottom(j, i).x;
            dst(j, i).y = top2(j, i).y > 0 ? top2(j, i).y : bottom(j, i).y;
            dst(j, i).z = top2(j, i).z > 0 ? top2(j, i).z : bottom(j, i).z;
        }
    }
    else
        return;
}

__global__ void darkch_kernel(cuda::PtrStepSz<uchar3> src, cuda::PtrStepSz<uchar> dst)
{
    int i = threadIdx.x + blockIdx.x * blockDim.x;
    int j = threadIdx.y + blockIdx.y * blockDim.y;

    dst(j, i) = Min(src(j, i).x, Min(src(j, i).y, src(j, i).z));
}

__global__ void tran_kernel(cuda::PtrStepSz<uchar> src, cuda::PtrStepSz<uchar> dst)
{
    int i = threadIdx.x + blockIdx.x * blockDim.x;
    int j = threadIdx.y + blockIdx.y * blockDim.y;

    uchar val = 255 - float( (src(j, i)) * 0.95);
    dst(j, i) = val;
}

__global__ void dehaze_kernal(cuda::PtrStepSz<uchar3> src, cuda::PtrStepSz<uchar3> dst, cuda::PtrStepSz<uchar> tran, float air_val0, float air_val1, float air_val2)
{
    int i = threadIdx.x + blockIdx.x * blockDim.x;
    int j = threadIdx.y + blockIdx.y * blockDim.y;

    float r = float((float)tran(j, i) < 25 ? 25 : (float)tran(j, i)) / 255;

    dst(j, i).x = Min(float(src(j, i).x - float(255 - tran(j, i)) * (1 - air_val0)) / r, 255);
    dst(j, i).y = Min(float(src(j, i).y - float(255 - tran(j, i)) * (1 - air_val1)) / r, 255);
    dst(j, i).z = Min(float(src(j, i).z - float(255 - tran(j, i)) * (1 - air_val2)) / r, 255);
}

__global__ void enhanceTrans_kernel(cuda::PtrStepSz<uchar> src, cuda::PtrStepSz<uchar> dst)
{
    int i = threadIdx.x + blockIdx.x * blockDim.x;
    int j = threadIdx.y + blockIdx.y * blockDim.y;

    uchar val = 255 - float((src(j, i)) * 0.8);
    dst(j, i) = (val > 204) ? val : 204;
}

__global__ void enhance_kernel(cuda::PtrStepSz<uchar3> src, cuda::PtrStepSz<uchar3> dst, cuda::PtrStepSz<uchar> tran, float k_val , float air_val0, float air_val1, float air_val2)
{
    int i = threadIdx.x + blockIdx.x * blockDim.x;
    int j = threadIdx.y + blockIdx.y * blockDim.y;

    float tran_scale = ((float)tran(j, i) / 255);

    dst(j, i).x = Min((float)(((src(j, i).x) / tran_scale * k_val) * air_val0), 255);
    dst(j, i).y = Min((float)(((src(j, i).y) / tran_scale * k_val) * air_val1), 255);
    dst(j, i).z = Min((float)(((src(j, i).z) / tran_scale * k_val) * air_val2), 255);
}
__global__ void dehazeOpt_kernal(cuda::PtrStepSz<uchar3> frame1, cuda::PtrStepSz<uchar3> frame2, cuda::PtrStepSz<uchar3> result, cuda::PtrStepSz<uchar> dark,
                                 cuda::PtrStepSz<uchar> tran, cuda::PtrStepSz<uchar> buffer, bool odd, float air_val0, float air_val1, float air_val2)
{
    int i = threadIdx.x + blockIdx.x * blockDim.x;
    int j = threadIdx.y + blockIdx.y * blockDim.y;

    if(buffer(j, i) > 0) buffer(j, i)--;
    int diff_val = abs( frame1(j, i).x - frame2(j, i).x) + abs(frame1(j, i).y - frame2(j, i).y) + abs(frame1(j, i).z - frame2(j, i).z);
    if(diff_val > 20) buffer(j, i) = 20;

    if (buffer(j, i) > 0) {
        if(odd) {
            dark(j, i) = Min(frame1(j, i).x, Min(frame1(j, i).y, frame1(j, i).z));
            tran(j, i) = 255 - float((dark(j, i)) * 0.95);
            float r = float((float)tran(j, i) < 25 ? 25 : (float)tran(j, i)) / 255;

            result(j, i).x = Min(float(frame1(j, i).x - float(255 - tran(j, i)) * (1 - air_val0)) / r, 255);
            result(j, i).y = Min(float(frame1(j, i).y - float(255 - tran(j, i)) * (1 - air_val1)) / r, 255);
            result(j, i).z = Min(float(frame1(j, i).z - float(255 - tran(j, i)) * (1 - air_val2)) / r, 255);
        }
        else {
            dark(j, i) = Min(frame2(j, i).x, Min(frame2(j, i).y, frame2(j, i).z));
            tran(j, i) = 255 - float((dark(j, i)) * 0.95);
            float r = float((float)tran(j, i) < 25 ? 25 : (float)tran(j, i)) / 255;

            result(j, i).x = Min(float(frame2(j, i).x - float(255 - tran(j, i)) * (1 - air_val0)) / r, 255);
            result(j, i).y = Min(float(frame2(j, i).y - float(255 - tran(j, i)) * (1 - air_val1)) / r, 255);
            result(j, i).z = Min(float(frame2(j, i).z - float(255 - tran(j, i)) * (1 - air_val2)) / r, 255);
        }
    }
    else
        return;
}

__global__ void enhanceOpt_kernel(cuda::PtrStepSz<uchar3> frame1, cuda::PtrStepSz<uchar3> frame2, cuda::PtrStepSz<uchar3> result, cuda::PtrStepSz<uchar> dark,
                                  cuda::PtrStepSz<uchar> tran, cuda::PtrStepSz<uchar> buffer, bool odd, float k_val, float air_val0, float air_val1, float air_val2)
{
    int i = threadIdx.x + blockIdx.x * blockDim.x;
    int j = threadIdx.y + blockIdx.y * blockDim.y;

    if(buffer(j, i) > 0) buffer(j, i) --;
    int diff_val = abs(frame1(j, i).x - frame2(j, i).x) + abs(frame1(j, i).y - frame2(j, i).y) + abs(frame1(j, i).z - frame2(j, i).z);

    if(diff_val > 20) buffer(j, i) = 20;
    if (buffer(j, i) > 0) {
        if(odd) {
            dark(j, i) = Min(frame1(j, i).x, Min(frame1(j, i).y, frame1(j, i).z));
            uchar val = 255 - float((dark(j, i)) * 0.8);
            tran(j, i) = (val > 204) ? val : 204;

            float tran_scale = ((float)tran(j, i) / 255);
            result(j, i).x = Min((float)(((frame1(j, i).x) / tran_scale * k_val) * air_val0), 255);
            result(j, i).y = Min((float)(((frame1(j, i).y) / tran_scale * k_val) * air_val1), 255);
            result(j, i).z = Min((float)(((frame1(j, i).z) / tran_scale * k_val) * air_val2), 255);
        }
        else {
            dark(j, i) = Min(frame2(j, i).x, Min(frame2(j, i).y, frame2(j, i).z));
            uchar val = 255 - float((dark(j, i)) * 0.8);
            tran(j, i) = (val > 204) ? val : 204;

            float tran_scale = ((float)tran(j, i) / 255);
            result(j, i).x = Min((float)(((frame2(j, i).x) / tran_scale * k_val) * air_val0), 255);
            result(j, i).y = Min((float)(((frame2(j, i).y) / tran_scale * k_val) * air_val1), 255);
            result(j, i).z = Min((float)(((frame2(j, i).z) / tran_scale * k_val) * air_val2), 255);
        }
    }
    else
        return;
}

__global__ void colorCorrection_kernel(cuda::PtrStepSz<uchar3> src, cuda::PtrStepSz<uchar3> dst, float air_val0, float air_val1, float air_val2)
{
    int i = threadIdx.x + blockIdx.x * blockDim.x;
    int j = threadIdx.y + blockIdx.y * blockDim.y;

    dst(j, i).x = Min((float)(((src(j, i).x) * air_val0 )), 255);
    dst(j, i).y = Min((float)(((src(j, i).y) * air_val1 )), 255);
    dst(j, i).z = Min((float)(((src(j, i).z) * air_val2 )), 255);
}

__global__ void gammaCorrection_kernel(cuda::PtrStepSz<uchar3> src, cuda::PtrStepSz<uchar3> dst, cuda::PtrStepSz<uchar> table)
{
    int i = threadIdx.x + blockIdx.x * blockDim.x;
    int j = threadIdx.y + blockIdx.y * blockDim.y;

    dst(j, i).x = table(0, Min((float) src(j, i).x, 255));	// Blue Info
    dst(j, i).y = table(0, Min((float) src(j, i).y, 255));  // Green Info
    dst(j, i).z = table(0, Min((float) src(j, i).z, 255));  // Red Info
}


void getImage_WithGamma(cuda::GpuMat src, cuda::GpuMat dst, cuda::GpuMat &GTable, dim3 numBlocks, dim3 threadsPerBlock)
{
    gammaCorrection_kernel <<< numBlocks, threadsPerBlock >>> (src, dst, GTable);
}

void genCornerHomo(cuda::GpuMat &gpuH_inv, cuda::GpuMat &maps_x, cuda::GpuMat &maps_y, dim3 numBlocks, dim3 threadsPerBlock)
{
    map_kernel <<< numBlocks, threadsPerBlock >>>(gpuH_inv, maps_x, maps_y);
}

void getStitch(cuda::GpuMat &bottom_layer, cuda::GpuMat &top_layer, cuda::GpuMat &dst_layer, dim3 numBlocks, dim3 threadsPerBlock)
{
    stitch_kernel <<< numBlocks, threadsPerBlock >>>(bottom_layer, top_layer, dst_layer);
}

void getStitchOpt(cuda::GpuMat &bottom_layer, cuda::GpuMat &top_layer1, cuda::GpuMat &top_layer2, cuda::GpuMat &top_buffer, cuda::GpuMat &dst_layer, bool isOdd, dim3 numBlocks, dim3 threadsPerBlock)
{
    stitchOpt_kernel <<< numBlocks, threadsPerBlock >>>(bottom_layer, top_layer1, top_layer2, top_buffer, dst_layer, isOdd);
}

void getDarkChannel(cuda::GpuMat src, cuda::GpuMat dark_ch, dim3 numBlocks, dim3 threadsPerBlock)
{
    darkch_kernel <<< numBlocks, threadsPerBlock >>> (src, dark_ch);
}

void getTransmit(cuda::GpuMat src, cuda::GpuMat trans, dim3 numBlocks, dim3 threadsPerBlock)
{
    tran_kernel <<< numBlocks, threadsPerBlock >>> (src, trans);
}

void getDehaze(cuda::GpuMat src, cuda::GpuMat dehaze_res, cuda::GpuMat trans, float air_val[], dim3 numBlocks, dim3 threadsPerBlock)
{
    dehaze_kernal <<< numBlocks, threadsPerBlock >>> (src, dehaze_res, trans, air_val[0],air_val[1],air_val[2]);
}

void getDehaze_opt(cuda::GpuMat frame1, cuda::GpuMat frame2, cuda::GpuMat result, cuda::GpuMat darks, cuda::GpuMat trans,
                   cuda::GpuMat buffers, bool isOdd, float air_val[], dim3 numBlocks, dim3 threadsPerBlock)
{
    dehazeOpt_kernal <<< numBlocks, threadsPerBlock >>> (frame1, frame2, result, darks, trans, buffers, isOdd, air_val[0], air_val[1], air_val[2]);
}

void getLowLightTransmit(cuda::GpuMat src, cuda::GpuMat trans, dim3 numBlocks, dim3 threadsPerBlock)
{
    enhanceTrans_kernel <<< numBlocks, threadsPerBlock >>> (src, trans);
}

void getEnhancement(cuda::GpuMat src, cuda::GpuMat enhance_res, cuda::GpuMat trans, float enhace_val, float air_val[], dim3 numBlocks, dim3 threadsPerBlock)
{
    enhance_kernel <<< numBlocks, threadsPerBlock >>> (src, enhance_res, trans, enhace_val, air_val[0], air_val[1], air_val[2]);
}

void getEnhancement_opt(cuda::GpuMat frame1, cuda::GpuMat frame2, cuda::GpuMat result, cuda::GpuMat darks, cuda::GpuMat trans,
                        cuda::GpuMat buffers, bool isOdd, float enhace_val, float air_val[], dim3 numBlocks, dim3 threadsPerBlock)
{
    enhanceOpt_kernel<<< numBlocks, threadsPerBlock >>>(frame1, frame2, result, darks, trans, buffers, isOdd, enhace_val, air_val[0], air_val[1], air_val[2]);
}
