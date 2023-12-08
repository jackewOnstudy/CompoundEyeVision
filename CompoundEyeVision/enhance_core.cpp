#include "enhance_core.h"

void enhance(cuda::GpuMat src, cuda::GpuMat result, cuda::GpuMat dark_ch, cuda::GpuMat tran, float enhance_val, float air[], dim3 numBlocks, dim3 threadsPerBlock)
{
    getDarkChannel(src, dark_ch, numBlocks, threadsPerBlock);
    getLowLightTransmit(dark_ch, tran, numBlocks, threadsPerBlock);
    getEnhancement(src, result, tran, enhance_val, air, numBlocks, threadsPerBlock);
}
void enhance_opt(cuda::GpuMat fram1, cuda::GpuMat frame2, cuda::GpuMat result, cuda::GpuMat dark_ch, cuda::GpuMat tran, cuda::GpuMat buffer, bool isOdd,
                 float enhance_val, float air[], dim3 numBlocks, dim3 threadsPerBlock)
{
    getEnhancement_opt(fram1, frame2, result, dark_ch, tran, buffer, isOdd, enhance_val, air, numBlocks, threadsPerBlock);
}
