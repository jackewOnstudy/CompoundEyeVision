QT       += core gui
#QMAKE_CXXFLAGS += "-msse2"
#QMAKE_CXXFLAGS += -fopenmp
#QMAKE_LFLAGS += -fopenmp
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
#CONFIG += cuda

TARGET = CompoundEyeVision
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    CompoundEye.cpp \
    CudaSift_Src/geomFuncs.cpp \
    backend.cpp \
    displaywidget.cpp \
    main.cpp \
    mainwindow.cpp \
    open_usbcam.cpp \
    stitch_core.cpp

HEADERS += \
    CompoundEye.h \
    backend.h \
    displaywidget.h \
    mainwindow.h \
    open_usbcam.h \
    stitch_core.h \
    type.h

FORMS += \
    mainwindow.ui \
    mainwindow_copy.ui

TRANSLATIONS +=/usr/local/include \
               /usr/include \
#		/usr/lib/x86_64-linux-gnu \
    CompoundEyeVision_zh_CN.ts

#opencv4.8
INCLUDEPATH += /usr/local/include/opencv4 \
               /usr/local/include/boost   \
               /usr/lib/gcc/x86_64-linux-gnu \
               /usr/local/cuda-12.0/targets/x86_64-linux/include \
               /home/jackew/Project/CompoundEyeVision/CompoundEyeVision/CudaSift_Ind \
		
CONFIG += link_pkgconfig
PKGCONFIG += opencv4

#LIBS += -L /usr/lib/ -lopencv_core -lopencv_highgui -lopencv_imgproc -lopencv_imgcodecs
#LIBS += -L /usr/local/lib/libopencv_*.so

LIBS +=  -L/usr/local/lib \
#         -L/usr/lib \
#        -L/usr/lib/x86_64-linux-gnu \
        -lgomp \
        -llapack \
        -latlas \
        -lboost_system \
        -lboost_thread \
        -lboost_filesystem \
        -lboost_chrono \
        -lboost_date_time \
        -lboost_atomic \
        -lpthread \
        -lglog \
        -lgflags \
        -lz \
        -ldl \
        -lm \
        -lopencv_calib3d \
        -lopencv_highgui \
        -lopencv_core \
        -lopencv_cudev \
        -lopencv_cudacodec \
        -lopencv_cudaarithm \
        -lopencv_cudaimgproc \
        -lopencv_cudawarping \
        -lopencv_imgcodecs \
        -lopencv_imgproc \
        -lopencv_videoio \
        -lopencv_video \
        -lopencv_xfeatures2d \
        -lopencv_cudafeatures2d \


# This makes the .cu files appear in your project
OTHER_FILES += \
    CudaSift_Src/cudaImage.cu \
    CudaSift_Src/cudaSiftH.cu \
    CudaSift_Src/matching.cu

# CUDA settings <-- may change depending on your system
CUDA_SOURCES += \
    CudaSift_Src/cudaImage.cu \
    CudaSift_Src/cudaSiftH.cu \
    CudaSift_Src/matching.cu

# Path to cuda SDK install
CUDA_SDK = "/usr/local/cuda-12.0/"
# Path to cuda toolkit install
CUDA_DIR = "/usr/local/cuda-12.0/"

SYSTEM_NAME = ubuntu
SYSTEM_TYPE = 64
CUDA_ARCH = sm_89

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    CudaSift_Src/cudaImage.cu \
    CudaSift_Src/cudaSiftH.cu \
    CudaSift_Src/matching.cu

NVCC_OPTIONS = --use_fast_math --fmad=false

# include paths
INCLUDEPATH += $$CUDA_DIR/include

# library directories
QMAKE_LIBDIR += $$CUDA_DIR/lib64/

CUDA_OBJECTS_DIR = ./

# The following library conflicts with something in Cuda

#QMAKE_LFLAGS_RELEASE = /NODEFAULTLIB:msvcrt.lib

#QMAKE_LFLAGS_DEBUG   = /NODEFAULTLIB:msvcrtd.lib

# Add the necessary libraries

CUDA_LIBS =  -lcuda -lcudart -lnppc -lnpps -lcufft -lcublas -lcurand -lcudnn

# The following makes sure all path names (which often include spaces) are put between quotation marks
CUDA_INC = $$join(INCLUDEPATH,'" -I"','-I"','"')

NVCC_LIBS = $$join(CUDA_LIBS,' -l','-l', '')

# LIBS += $$join(CUDA_LIBS,'.so ', '', '.so')
LIBS += $$CUDA_LIBS

# Configuration of the Cuda compiler

CONFIG(debug, debug|release) {
    # Debug mode

    cuda_d.input = CUDA_SOURCES

    cuda_d.output = $$CUDA_OBJECTS_DIR/${QMAKE_FILE_BASE}_cuda.o

    cuda_d.commands = $$CUDA_DIR/bin/nvcc -D_DEBUG $$NVCC_OPTIONS $$CUDA_INC $$NVCC_LIBS \
    --machine $$SYSTEM_TYPE -arch=$$CUDA_ARCH -c -o ${QMAKE_FILE_OUT} ${QMAKE_FILE_NAME}

    cuda_d.dependency_type = TYPE_C

    QMAKE_EXTRA_COMPILERS += cuda_d

}

else {

    # Release mode

    cuda.input = CUDA_SOURCES

    cuda.output = $$CUDA_OBJECTS_DIR/${QMAKE_FILE_BASE}_cuda.o

    cuda.commands = $$CUDA_DIR/bin/nvcc $$NVCC_OPTIONS $$CUDA_INC $$NVCC_LIBS \
    --machine $$SYSTEM_TYPE -arch=$$CUDA_ARCH -O3 -c -o ${QMAKE_FILE_OUT} ${QMAKE_FILE_NAME}

    cuda.dependency_type = TYPE_C

    QMAKE_EXTRA_COMPILERS += cuda

}

