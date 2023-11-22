#ifndef DISPLAYWIDGET_H
#define DISPLAYWIDGET_H
#include <QWidget>
#include <QImage>
#include <QPainter>
#include <QPalette>
#include <QEvent>
#include <QMouseEvent>

#include <QDateTime>
#include <QObject>
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

#include <cmath>

//#include "backend.h"

class DisplayWidget : public QWidget
{
    Q_OBJECT
public:
    explicit DisplayWidget(QWidget *parent = 0);
    void enterEvent(QEvent *) override;
    void leaveEvent(QEvent *) override;
    void mousePressEvent(QMouseEvent * event) override;
    void mouseReleaseEvent(QMouseEvent * event) override;
     void mouseMoveEvent(QMouseEvent * event) override;
    bool empty();
    cv::Point mouse_clk;
    int windows_width;
    int windows_height;
    bool isPress = false;


signals:

public slots:
    void display(const cv::Mat &frame, bool resize = true);

protected:
    void paintEvent(QPaintEvent *ev) override;
    QImage m_frame;
    cv::Mat m_mat;
};

#endif // DISPLAYWIDGET_H
