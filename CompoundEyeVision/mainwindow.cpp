#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qRegisterMetaType<StreamResult>("StreamResult");

    // new backend thread
    backend_core = new Backend(&sharedData, this);
    backend_core_thread = new QThread;
    backend_core->moveToThread(backend_core_thread);
}

MainWindow::~MainWindow()
{
    if(sharedData.inputMedia == 0) {
        backend_core->close_usbcam();
    }

    // quit backend thread
    backend_core_thread->quit();
    backend_core->deleteLater();
    backend_core_thread->deleteLater();

    // quit ui thread
    delete ui;
}

void MainWindow::init()
{
    // Initaliza the ui options
    ui->radioButton_isUsb->setChecked(true);
    ui->label_enhance_val->setNum(sharedData.enhance_kVal);
    ui->label_zoom_val->setNum(sharedData.zoom_Val);

    // Initalize the cuda block
    sharedData.threadsPerBlock = dim3(32, 32);
    uint block_num_vertical = (video_rows + sharedData.threadsPerBlock.x - 1) / sharedData.threadsPerBlock.x;
    uint block_num_horizontal = (video_cols + sharedData.threadsPerBlock.y - 1) / sharedData.threadsPerBlock.y;
    sharedData.numBlocks = dim3(block_num_horizontal, block_num_vertical);

    sharedData.view_threadsPerBlock = dim3(32, 32);
    uint viewblock_num_vertical = (video_rows + sharedData.view_threadsPerBlock.x -1) / sharedData.view_threadsPerBlock.x;
    uint viewblock_num_horizontal = (video_cols + sharedData.view_threadsPerBlock.y - 1) / sharedData.view_threadsPerBlock.y;
    sharedData.view_numBlocks = dim3(viewblock_num_horizontal, viewblock_num_vertical);

    // Initialze the sharedData options
    sharedData.inputMedia = 0;
    sharedData.isKeyIn =false;
    sharedData.isExistRect = false;

    // Initialze qt connect and slot functions
    connect(ui->pushButton_start, SIGNAL(clicked(bool)), this, SLOT(onClickedStart()));
    connect(backend_core_thread, SIGNAL(started()), backend_core, SLOT(core()));
    connect(backend_core, SIGNAL(ack(StreamResult)), this, SLOT(onAck(StreamResult)));

    // Initialze empty view for cv mat
    empty = cv::Mat(1280, 720, CV_8UC3, cv::Scalar(0, 0, 0));

    sharedData.widget_width = ui->main_widget_stitch->windows_width;
    sharedData.widget_height = ui->main_widget_stitch->windows_height;

    subViewPos = cv::Point(0, 0);
    ui->main_widget_free->setGeometry(QRect(0, 0, subview_cols, subview_rows));
    ui->main_widget_free->display(empty, true);
    ui->main_widget_free->setHidden(true);
}

void MainWindow::onClickedStart()
{
    qDebug() << "Start Button!" << endl;
    sharedData.idx_camSelect = 0;
    sharedData.idx_table = 0;
    bool success = false;

    if(sharedData.inputMedia == 0) {
        success = backend_core->open_usbcam();
    }else {
        qDebug() << "Unsupport!" << endl;
    }

    if(!success) {
        qDebug() << "Camera startup failed!" << endl;
        return;
    }

    ui->radioButton_cam0->setChecked(true);
    qDebug() << "camera0 selected" << endl;
    backend_core_thread->start();
    qDebug() << "Camere starts successfully!" << endl;
}

void MainWindow::onAck(StreamResult res)
{
    // streamMultiCam Result
    switch(sharedData.idx_table) {
        case 0:
            if(!res.view[0].empty() && !res.view[1].empty() && !res.view[2].empty() && !res.view[3].empty()) {
                ui->main_widget_subview0->display(res.view[0]);
                ui->main_widget_subview1->display(res.view[1]);
                ui->main_widget_subview2->display(res.view[2]);
                ui->main_widget_subview3->display(res.view[3]);
            }else {
                qDebug() << "Tab1 has empty subview!" << endl;
            }
            break;
        case 1:
            if(!res.view[4].empty()) {
                ui->main_widget_subview4->display(res.view[4]);
            }
            if(!res.view[5].empty()) {
                ui->main_widget_subview5->display(res.view[5]);
            }
            if(!res.view[6].empty()) {
                ui->main_widget_subview6->display(res.view[6]);
            }
            break;
        case 2:
            // use shareData.zoom_Val to redefine the value of idx_camSelect, only show the camare belong to this zoom
            if(sharedData.zoom_Val < 20 && !res.view[0].empty()) {
                qDebug() << "Viewing  camera 0" << endl;
                ui->main_widget_single->display(res.view[0], true);
            }else if(sharedData.zoom_Val < 40 && !res.view[1].empty()) {
                qDebug() << "Viewing  camera 1" << endl;
                ui->main_widget_single->display(res.view[1], true);
            }else if(sharedData.zoom_Val < 60 && !res.view[2].empty()) {
                qDebug() << "Viewing  camera 2" << endl;
                ui->main_widget_single->display(res.view[2], true);
            }else if(sharedData.zoom_Val <= 80 && !res.view[3].empty()) {
                qDebug() << "Viewing  camera 3" << endl;
                ui->main_widget_single->display(res.view[3], true);
            }else if(sharedData.idx_camSelect == 4 && !res.view[4].empty()) {
                ui->main_widget_single->display(res.view[4], true);
            }else if(sharedData.idx_camSelect == 5 && !res.view[5].empty()) {
                ui->main_widget_single->display(res.view[5], true);
            }else if(sharedData.idx_camSelect == 6 && !res.view[6].empty()) {
                ui->main_widget_single->display(res.view[6], true);
            }else {
                ui->main_widget_single->display(empty);
            }
            break;
        case 3:
            if(sharedData.isTwinView) {
                if(ui->main_widget_stitch->isPress) {
                    // qDebug() << "isPress" << endl;
                    // TODO
                }

                if(sharedData.isMouseLatch == true && !ui->main_widget_stitch->isPress) {
                    qDebug() << "isPressRelease1" << endl;
                }

                if(res.view_base.empty() && !res.view_stitch.empty()) {
                    ui->main_widget_stitch->display(res.view_stitch);
                }else {
                    if(res.view_stitch.empty()) {
                        ui->main_widget_stitch->display(empty);
                    }
                }
            }else {
                if(!res.view_stitch.empty()) {
                    ui->main_widget_stitch->display(res.view_stitch);
                }else {
                    ui->main_widget_stitch->display(empty);
                }
            }
            break;
        default:
            break;
    }
}

void MainWindow::keyPressEvent(QKeyEvent* k) {
    if(sharedData.idx_table == 0) {
        sharedData.step_offset = 10;
    }

    if(sharedData.idx_table == 3) {
        sharedData.isKeyIn = true;
        if(k->key() == 'W' || k->key() == 'w' || k->key() == Qt::Key_Up)
            sharedData.offset_xy.y = sharedData.offset_xy.y - sharedData.step_offset;
        else if(k->key() == 'S' || k->key() == 's' || k->key() == Qt::Key_Down)
            sharedData.offset_xy.y = sharedData.offset_xy.y + sharedData.step_offset;
        else if(k->key() == 'A' || k->key() == 'a' || k->key() == Qt::Key_Left)
            sharedData.offset_xy.x = sharedData.offset_xy.x - sharedData.step_offset;
        else if(k->key() == 'D' || k->key() == 'd' || k->key() == Qt::Key_Right)
            sharedData.offset_xy.x = sharedData.offset_xy.x + sharedData.step_offset;
        else if(k->key() == '+' || k->key() == '=')
            sharedData.rate_resize = sharedData.rate_resize * 1.01;
        else if(k->key() == '-' || k->key() == '_')
            sharedData.rate_resize = sharedData.rate_resize / 1.01;
        else if(k->key() == 'E' || k->key() == 'e' || k->key() == 'Q' || k->key() == 'q') {
            qDebug() << "Key Esc" << endl;
            sharedData.offset_xy = cv::Point(0, 0);
            sharedData.rate_resize = 1;
        }

        if(k->key() == 'I' || k->key() == 'i')
            subViewPos.y = subViewPos.y - sharedData.step_offset;
        else if(k->key() == 'K' || k->key() == 'k')
            subViewPos.y = subViewPos.y + sharedData.step_offset;
        else if(k->key() == 'J' || k->key() == 'j')
            subViewPos.x = subViewPos.x - sharedData.step_offset;
        else if(k->key() == 'L' || k->key() == 'l')
            subViewPos.x = subViewPos.x + sharedData.step_offset;

        if(k->key() == 'M' || k->key() == 'm') {
            sharedData.isStartMove = true;
            qDebug() << "sharedData.isStartMove: " <<  sharedData.isStartMove << endl;

        }else if(k->key() == 'N' || k->key() == 'n') {
            sharedData.isStartMove = false;
            qDebug() << "sharedData.isStartMove: " <<  sharedData.isStartMove << endl;
        }else if(k->key() == 'B' || k->key() == 'b') {
            sharedData.isRest = true;
            qDebug() << "sharedData.isReset: " <<  sharedData.isRest << endl;

        }

        ui->main_widget_free->setGeometry(QRect(subViewPos.x, subViewPos.y, 640, 360));
        sharedData.step_offset = 10 / sharedData.rate_resize;
        if(sharedData.step_offset < 1)
            sharedData.step_offset = 2;
    }
}

void MainWindow::wheelEvent(QWheelEvent* w)
{
    if(sharedData.idx_table == 3) {
        sharedData.isKeyIn = true;

        int curx = w->pos().x() - 24;
        int cury = w->pos().y() - 71;
        int middlex = ui->main_widget_stitch->width()/2;
        int middley = ui->main_widget_stitch->height()/2;

        if(w->delta() > 0) {
            sharedData.rate_resize = sharedData.rate_resize * 1.09;
        }else {
            sharedData.rate_resize = sharedData.rate_resize / 1.09;
        }
        sharedData.offset_xy.x = sharedData.offset_xy.x + w->delta() * (middlex - curx) / (300 * sharedData.rate_resize);
        sharedData.offset_xy.y = sharedData.offset_xy.y + w->delta() * (middley - cury) / (300 * sharedData.rate_resize);

        sharedData.step_offset = 10 / sharedData.rate_resize;
        if(sharedData.step_offset < 1)
            sharedData.step_offset = 2;
    }
}

void MainWindow::on_TabWidget_tabBarClicked(int index)
{
    sharedData.idx_table = index;
}

void MainWindow::on_radioButton_isUsb_toggled(bool checked)
{
    sharedData.inputMedia = 0;
}

void MainWindow::on_radioButton_isVideo_toggled(bool checked)
{
    sharedData.inputMedia = 1;
}

void MainWindow::on_radioButton_cam0_toggled(bool checked)
{
    sharedData.idx_camSelect = 0;
}

void MainWindow::on_radioButton_cam1_toggled(bool checked)
{
    sharedData.idx_camSelect = 1;
}

void MainWindow::on_radioButton_cam2_toggled(bool checked)
{
    sharedData.idx_camSelect = 2;
}

void MainWindow::on_radioButton_cam3_toggled(bool checked)
{
    sharedData.idx_camSelect = 3;
}

void MainWindow::on_radioButton_cam4_toggled(bool checked)
{
    sharedData.idx_camSelect = 4;
}

void MainWindow::on_radioButton_cam5_toggled(bool checked)
{
    sharedData.idx_camSelect = 5;
}

void MainWindow::on_radioButton_isDehaze_toggled(bool checked)
{
    sharedData.isDehaze = checked;
}

void MainWindow::on_radioButton_isEnhance_toggled(bool checked)
{
    sharedData.isEnhance = checked;
}

void MainWindow::on_horizontalSlider_enhance_kval_valueChanged(int value)
{
    sharedData.enhance_kVal = value;
    ui->label_enhance_val->setNum(value);
}

void MainWindow::on_horizontalSlider_zoom_val_valueChanged(int value)
{
    sharedData.zoom_Val = value;
    ui->label_zoom_val->setNum(value);
}

void MainWindow::on_horizontalSlider_cam0_X_valueChanged(int value)
{
    sharedData.cam0_x = value;
    ui->label_cam0_X->setNum(value);
}

void MainWindow::on_horizontalSlider_cam0_Y_valueChanged(int value)
{
    sharedData.cam0_y = value;
    ui->label_cam0_Y->setNum(value);
}

void MainWindow::on_horizontalSlider_cam0_R_valueChanged(int value)
{
    sharedData.cam0_r = value;
    ui->label_cam0_R->setNum(value);
}

void MainWindow::on_horizontalSlider_cam0_Z_valueChanged(int value)
{
    sharedData.cam0_z = value;
    ui->label_cam0_Z->setNum(value);
}

void MainWindow::on_horizontalSlider_cam1_X_valueChanged(int value)
{
    sharedData.cam1_x = value;
    ui->label_cam1_X->setNum(value);
}

void MainWindow::on_horizontalSlider_cam1_Y_valueChanged(int value)
{
    sharedData.cam1_y = value;
    ui->label_cam1_Y->setNum(value);
}

void MainWindow::on_horizontalSlider_cam1_R_valueChanged(int value)
{
    sharedData.cam1_r = value;
    ui->label_cam1_R->setNum(value);
}

void MainWindow::on_horizontalSlider_cam1_Z_valueChanged(int value)
{
    sharedData.cam1_z = value;
    ui->label_cam1_Z->setNum(value);
}

void MainWindow::on_horizontalSlider_cam2_X_valueChanged(int value)
{
    sharedData.cam2_x = value;
    ui->label_cam2_X->setNum(value);
}

void MainWindow::on_horizontalSlider_cam2_Y_valueChanged(int value)
{
    sharedData.cam2_y = value;
    ui->label_cam2_Y->setNum(value);
}

void MainWindow::on_horizontalSlider_cam2_R_valueChanged(int value)
{
    sharedData.cam2_r = value;
    ui->label_cam2_R->setNum(value);
}

void MainWindow::on_horizontalSlider_cam2_Z_valueChanged(int value)
{
    sharedData.cam2_z = value;
    ui->label_cam2_Z->setNum(value);
}

void MainWindow::on_horizontalSlider_camGlobal_R_valueChanged(int value)
{
    sharedData.camGlobal_r = value;
    ui->label_camGlobal_R->setNum(value);
}

void MainWindow::on_horizontalSlider_camGlobal_Z_valueChanged(int value)
{
    sharedData.camGlobal_z = value;
    ui->label_camGlobal_Z->setNum(value);
}

void MainWindow::on_pushButton_updateparam_clicked()
{
    sharedData.isUpdateParam = true;
}

void MainWindow::on_horizontalSlider_Rch_valueChanged(int value)
{
    sharedData.air_val[0] = (float) value / 100;
    ui->label_Red->setNum(sharedData.air_val[0]);
}

void MainWindow::on_horizontalSlider_Gch_valueChanged(int value)
{
    sharedData.air_val[1] = (float) value / 100;
    ui->label_Green->setNum(sharedData.air_val[1]);
}

void MainWindow::on_horizontalSlider_Bch_valueChanged(int value)
{
    sharedData.air_val[2] = (float) value / 100;
    ui->label_Blue->setNum(sharedData.air_val[2]);
}

void MainWindow::on_pushButton_colorCorrection_clicked()
{
    sharedData.isUpdateCC = true;
}

void MainWindow::on_radioButton_colorCorrection_toggled(bool checked)
{
    sharedData.isColorCorrection = checked;
}

void MainWindow::on_radioButton_isTwinView_toggled(bool checked)
{
    sharedData.isTwinView = checked;
}

void MainWindow::on_spinBox_zoom_val_valueChanged(int arg1)
{
    sharedData.zoom_Val = arg1;
    ui->label_zoom_val->setNum(arg1);
}

void MainWindow::on_radioButton_isInterFrame_toggled(bool checked)
{
    sharedData.isInterFrame = checked;
}
