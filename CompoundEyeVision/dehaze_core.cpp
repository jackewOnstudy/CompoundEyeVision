#include "dehaze_core.h"


void dehaze(cuda::GpuMat src, cuda::GpuMat result, cuda::GpuMat dark_ch, cuda::GpuMat tran, float air[], dim3 numBlocks, dim3 threadsPerBlock)
{
    getDarkChannel(src, dark_ch, numBlocks, threadsPerBlock);
    getTransmit(dark_ch, tran, numBlocks, threadsPerBlock);
    getDehaze(src, result, tran, air, numBlocks, threadsPerBlock);
}

// dehaze with inter frames
void dehaze_opt(cuda::GpuMat frame1, cuda::GpuMat frame2, cuda::GpuMat result, cuda::GpuMat dark_ch,
                cuda::GpuMat tran, cuda::GpuMat buffer, bool isOdd, float air[], dim3 numBlocks, dim3 threadsPerBlock)
{
    getDehaze_opt(frame1, frame2, result, dark_ch, tran, buffer, isOdd, air, numBlocks, threadsPerBlock);
}

//calDarkC
void calDarkChannel(cuda::GpuMat src, cuda::GpuMat dst, dim3 numBlocks, dim3 threadsPerBlock)
{
    getDarkChannel(src, dst, numBlocks, threadsPerBlock);
}

// For guidedfilter
void boxfiter(cuda::GpuMat& I, cuda::GpuMat result, cv::Ptr<cuda::Filter> filter)
{
    filter->apply(I, result);
}

void GuidedFilterMono(cuda::GpuMat& I, cuda::GpuMat& I_mul, cuda::GpuMat& mean_I, cuda::GpuMat& mean_mul, cuda::GpuMat& mean_II,
                      cuda::GpuMat& var_I, cv::Ptr<cuda::Filter> filter)
{
    boxfiter(I, mean_I, filter);
    cuda::multiply(I, I, I_mul);
    boxfiter(I_mul, mean_II, filter);
    cuda::multiply(mean_I, mean_I, mean_mul);
    cuda::subtract(mean_II, mean_mul, var_I);
}

void filterSingleChannel(cuda::GpuMat& p, cuda::GpuMat& I, cuda::GpuMat& mean_p, cuda::GpuMat& mean_I, cuda::GpuMat& var_I,
                         cuda::GpuMat& mean_Imulp, cuda::GpuMat& Imul_p, cuda::GpuMat& cov_Ip, cuda::GpuMat& meanImul_meanp,
                         cuda::GpuMat& a, cuda::GpuMat& b, cuda::GpuMat& mean_a, cuda::GpuMat& mean_b,
                         cuda::GpuMat& varI_addeps, cuda::GpuMat eps_mat,
                         cuda::GpuMat& amul_meanI,
                         cuda::GpuMat& filter_dst, cv::Ptr<cuda::Filter> filter)
{
    boxfiter(p, mean_p, filter);
    cuda::multiply(I, p, Imul_p);
    boxfiter(Imul_p, mean_Imulp, filter);
    cuda::multiply(mean_I, mean_p, meanImul_meanp);
    cuda::subtract(mean_Imulp, meanImul_meanp, cov_Ip);

    cuda::add(var_I, eps_mat, varI_addeps);

    cuda::divide(cov_Ip, varI_addeps, a);
    cuda::multiply(a, mean_I, amul_meanI);
    cuda::subtract(mean_p, amul_meanI, b);

    boxfiter(a, mean_a, filter);
    boxfiter(b, mean_b, filter);
    cuda::add(mean_a, mean_b, filter_dst);
}

// dehaze with guidefilter
void dehaze_withGF(cuda::GpuMat src, cuda::GpuMat result, cv::Ptr<cv::cuda::Filter> filter, float air[], dim3 numBlocks, dim3 threadsPerBlock,
                   cuda::GpuMat dark_ch, cuda::GpuMat grey, cuda::GpuMat tran,
                   cuda::GpuMat I_mul, cuda::GpuMat mean_I, cuda::GpuMat mean_mul, cuda::GpuMat mean_II, cuda::GpuMat var_I, cuda::GpuMat mean_p,
                   cuda::GpuMat mean_Imulp, cuda::GpuMat Imul_p, cuda::GpuMat cov_Ip, cuda::GpuMat meanImul_meanp, cuda::GpuMat a, cuda::GpuMat b,
                   cuda::GpuMat mean_a, cuda::GpuMat mean_b, cuda::GpuMat varI_addeps, cuda::GpuMat eps_mat, cuda::GpuMat amul_meanI, cuda::GpuMat filter_dst)
{
    cuda::cvtColor(src, grey, COLOR_RGB2GRAY);
    getDarkChannel(src, dark_ch, numBlocks, threadsPerBlock);
    GuidedFilterMono(grey, I_mul, mean_I, mean_mul, mean_II, var_I, filter);
    filterSingleChannel(dark_ch, grey, mean_p, mean_I, var_I, mean_Imulp, Imul_p, cov_Ip, meanImul_meanp, a,
                        b, mean_a, mean_b, varI_addeps, eps_mat, amul_meanI, filter_dst, filter);
    getTransmit(filter_dst, tran, numBlocks, threadsPerBlock);
    getDehaze(src, result, tran, air, numBlocks, threadsPerBlock);
}
