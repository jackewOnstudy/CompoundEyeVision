#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "displaywidget.h"
#include "type.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_TabWidget_tabBarClicked(int index);

private:
    Ui::MainWindow *ui;

    SharedData sharedData;

    cv::Mat empty;
    bool isSubViewLatch = false;
    cv::Point subViewPos;

    int frame_cnt = 0;
    double sum_clock = 0;
    cv:: Mat view_base;
};
#endif // MAINWINDOW_H
