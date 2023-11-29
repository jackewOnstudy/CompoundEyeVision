#ifndef DISPLAYWIDGET_H
#define DISPLAYWIDGET_H
#include <QWidget>
#include <QImage>
#include <QPainter>
#include <QPalette>
#include <QEvent>
#include <QMouseEvent>


#include "backend.h"

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
