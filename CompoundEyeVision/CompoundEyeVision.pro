QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

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
    backend.cpp \
    displaywidget.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    CompoundEye.h \
    backend.h \
    displaywidget.h \
    mainwindow.h \
    type.h \
    video.h

FORMS += \
    mainwindow.ui \
    mainwindow_copy.ui

TRANSLATIONS +=/usr/local/include \
		/usr/include \
#		/usr/lib/x86_64-linux-gnu \
    CompoundEyeVision_zh_CN.ts
 
LIBS += -L/usr/local/lib
LIBS += -L/usr/lib

#opencv4.8
#INCLUDEPATH += /usr/include/opencv4 \

INCLUDEPATH += /usr/local/include/opencv4 \
               /usr/local/include/boost   \
               /usr/lib/gcc/x86_64-linux-gnu \
               /usr/local/cuda-12.0/targets/x86_64-linux/include \
		
CONFIG += link_pkgconfig
PKGCONFIG += opencv4

#LIBS += -L /usr/lib/ -lopencv_core -lopencv_highgui -lopencv_imgproc -lopencv_imgcodecs
#LIBS += -L /usr/local/lib/libopencv_*.so

LIBS +=  -L/usr/local/lib \
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


# Path to cuda SDK install
CUDA_SDK = "/usr/local/cuda-12.0/"
# Path to cuda toolkit install
CUDA_DIR = "/usr/local/cuda-12.0/"



# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
