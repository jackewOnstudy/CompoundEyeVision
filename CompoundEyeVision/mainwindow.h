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
    void init();

public slots:
    void onClickedStart();
    void onAck(StreamResult res);
    void keyPressEvent(QKeyEvent *k);
    void wheelEvent(QWheelEvent *w);


private slots:
    void on_TabWidget_tabBarClicked(int index);

    void on_radioButton_isUsb_toggled(bool checked);

    void on_radioButton_isVideo_toggled(bool checked);

    void on_radioButton_cam0_toggled(bool checked);

    void on_radioButton_cam1_toggled(bool checked);

    void on_radioButton_cam2_toggled(bool checked);

    void on_radioButton_cam3_toggled(bool checked);

    void on_radioButton_cam4_toggled(bool checked);

    void on_radioButton_cam5_toggled(bool checked);


    void on_radioButton_isDehaze_toggled(bool checked);

    void on_radioButton_isEnhance_toggled(bool checked);

    void on_horizontalSlider_enhance_kval_valueChanged(int value);

    void on_horizontalSlider_zoom_val_valueChanged(int value);

    void on_horizontalSlider_cam0_X_valueChanged(int value);

    void on_horizontalSlider_cam0_Y_valueChanged(int value);

    void on_horizontalSlider_cam0_R_valueChanged(int value);

    void on_horizontalSlider_cam0_Z_valueChanged(int value);

    void on_horizontalSlider_cam1_X_valueChanged(int value);

    void on_horizontalSlider_cam1_Y_valueChanged(int value);

    void on_horizontalSlider_cam1_R_valueChanged(int value);

    void on_horizontalSlider_cam1_Z_valueChanged(int value);

    void on_horizontalSlider_cam2_X_valueChanged(int value);

    void on_horizontalSlider_cam2_Y_valueChanged(int value);

    void on_horizontalSlider_cam2_R_valueChanged(int value);

    void on_horizontalSlider_cam2_Z_valueChanged(int value);

    void on_horizontalSlider_camGlobal_R_valueChanged(int value);

    void on_horizontalSlider_camGlobal_Z_valueChanged(int value);

    void on_pushButton_updateparam_clicked();

    void on_horizontalSlider_Rch_valueChanged(int value);

    void on_horizontalSlider_Gch_valueChanged(int value);

    void on_horizontalSlider_Bch_valueChanged(int value);

    void on_pushButton_colorCorrection_clicked();

    void on_radioButton_colorCorrection_toggled(bool checked);

    void on_radioButton_isTwinView_toggled(bool checked);

    void on_spinBox_zoom_val_valueChanged(int arg1);

private:
    Ui::MainWindow *ui;

    SharedData sharedData;
    Backend* backend_core;
    QThread* backend_core_thread;

    cv::Mat empty;
    bool isSubViewLatch = false;
    cv::Point subViewPos;

    int frame_cnt = 0;
    double sum_clock = 0;
    cv:: Mat view_base;
};
#endif // MAINWINDOW_H
