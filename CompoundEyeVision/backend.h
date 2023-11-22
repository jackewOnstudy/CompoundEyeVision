#ifndef BACKEND_H
#define BACKEND_H

#include <QObject>
#include <QDateTime>
#include <QThread>
#include <QFile>

#include <opencv2/opencv.hpp>
#include <opencv2/cudacodec.hpp>
#include <opencv2/core/cuda.hpp>
#include <opencv2/core/cuda_stream_accessor.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/xfeatures2d/nonfree.hpp>
#include <opencv2/cudafeatures2d.hpp>
#include <opencv2/cudaimgproc.hpp>
#include <opencv2/xfeatures2d/cuda.hpp>

#include <iostream>
#include <time.h>
#include <string>
#include <cmath>

#include "type.h"

class MainWindow;

class Backend : public QObject
{
    Q_OBJECT
public:
    Backend(SharedData* shareddata, MainWindow* parent);
    ~Backend();

    bool open_cam();
    bool close_cam();

    vector<Point2f> autoFindCorner;

public slots:
    void core();
    void streamStitch();
    void StreamMultiCam();
    void streamSingleCam();


    bool initGpuMat();
    bool funcStreamProcess();
    bool funcStreamProcessopt();
    bool funcStitchProcess();

signals:
    void ack(StreamResult res);

private:
    MainWindow* parent;
    SharedData* sharedData;


};

#endif // BACKEND_H
