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


class stitch_core
{
public:
    stitch_core();
};

#endif // STITCH_CORE_H
