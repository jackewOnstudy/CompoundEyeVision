#include "displaywidget.h"
#include <QDebug>

DisplayWidget::DisplayWidget(QWidget *parent) : QWidget(parent)
{
    QPalette pal = palette();
    pal.setColor(QPalette::Background, Qt::black);
    setAutoFillBackground(true);
    setPalette(pal);
}

void DisplayWidget::display(const cv::Mat &frame, bool resize)
{
    if (resize)
        cv::resize(frame, m_mat, cv::Size(this->size().width(), this->size().height()));
    else
        m_mat = frame;
    m_frame = QImage(m_mat.data, m_mat.cols, m_mat.rows, m_mat.step, QImage::Format_RGB888);
    repaint();
}


void DisplayWidget::paintEvent(QPaintEvent *ev)
{
    QPainter painter(this);
    int hmargin = this->width() - m_frame.width();
    int vmargin = this->height() - m_frame.height();
    painter.drawImage(QPoint(hmargin / 2, vmargin / 2), m_frame);
    painter.end();
}


void DisplayWidget::enterEvent(QEvent *)
{
    qDebug()<< "DisplayWidget enter widget";

}
void DisplayWidget::leaveEvent(QEvent *)
{
     qDebug()<< "DisplayWidget leave widget";

}

void DisplayWidget::mousePressEvent(QMouseEvent * event)
{
    qDebug()<< "DisplayWidget leave widget";
     mouse_clk = cv::Point(event->pos().x(), event->pos().y());
     windows_width = this->width();
     windows_height = this->height();
     if(mouse_clk.x!=0 && mouse_clk.y!=0)
     isPress = true;
}
void DisplayWidget::mouseReleaseEvent(QMouseEvent * event)
{
     qDebug()<< "DisplayWidget leave widget";

     mouse_clk = cv::Point(event->pos().x(), event->pos().y());
     windows_width = this->width();
     windows_height = this->height();
     if(mouse_clk.x!=0 && mouse_clk.y!=0)
     isPress = false;
     qDebug()<< "event->pos().x(): " << event->pos().x() << "event->pos().y(): " << event->pos().y()  <<endl;

}
void DisplayWidget::mouseMoveEvent(QMouseEvent * event)
{


}
