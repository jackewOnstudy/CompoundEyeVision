/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "displaywidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QTabWidget *TabWidget;
    QWidget *SubView1;
    DisplayWidget *main_widget_subview0;
    DisplayWidget *main_widget_subview1;
    DisplayWidget *main_widget_subview2;
    DisplayWidget *main_widget_subview3;
    QWidget *SubView2;
    DisplayWidget *main_widget_subview7;
    DisplayWidget *main_widget_subview6;
    DisplayWidget *main_widget_subview5;
    DisplayWidget *main_widget_subview4;
    QWidget *MainView;
    DisplayWidget *main_widget_single;
    QWidget *Stitch;
    DisplayWidget *main_widget_stitch;
    QWidget *widget;
    QPushButton *pushButton_start;
    QGroupBox *groupBox_camSwitch;
    QFormLayout *formLayout_2;
    QRadioButton *radioButton_isUsb;
    QRadioButton *radioButton_isVideo;
    QGroupBox *groupBox_camSelect;
    QFormLayout *formLayout;
    QRadioButton *radioButton_cam0;
    QRadioButton *radioButton_cam1;
    QRadioButton *radioButton_cam2;
    QRadioButton *radioButton_cam5;
    QRadioButton *radioButton_cam4;
    QRadioButton *radioButton_cam3;
    QGroupBox *groupBox_airParam;
    QVBoxLayout *verticalLayout;
    QSlider *horizontalSlider_Rch;
    QLabel *label_Red;
    QSlider *horizontalSlider_Gch;
    QLabel *label_Green;
    QSlider *horizontalSlider_Bch;
    QLabel *label_Blue;
    QGroupBox *groupBox_dehaze;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *radioButton_isDehaze;
    QGroupBox *groupBox_dedark;
    QVBoxLayout *verticalLayout_3;
    QRadioButton *radioButton_isEnhance;
    QRadioButton *radioButton_colorCorrection;
    QFrame *line_colorCorrect;
    QFrame *line_isTwinView;
    QRadioButton *radioButton_isTwinView;
    QFrame *line_LowLightParam;
    QLabel *label_show_enhance_val;
    QSlider *horizontalSlider_enhance_kval;
    QLabel *label_enhance_val;
    QFrame *line_LowLightParam_2;
    QLabel *label_show_zoom_val;
    QSlider *horizontalSlider_zoom_val;
    QLabel *label_zoom_val;
    QSpinBox *spinBox_zoom_val;
    QPushButton *pushButton_updateparam;
    QPushButton *pushButton_colorCorrection;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGroupBox *Cam0box;
    QGridLayout *gridLayout;
    QSlider *horizontalSlider_cam0_R;
    QLabel *label_3;
    QSlider *horizontalSlider_cam0_Z;
    QLabel *label;
    QSlider *horizontalSlider_cam0_X;
    QLabel *label_can0_Y;
    QLabel *label_cam0_X;
    QLabel *label_cam0_R;
    QLabel *label_4;
    QLabel *label_cam0_Z;
    QLabel *label_2;
    QSlider *horizontalSlider_cam0_Y;
    QGroupBox *Cam1box;
    QGridLayout *gridLayout_2;
    QLabel *label_5;
    QSlider *horizontalSlider_cam1_X;
    QLabel *label_cam1_X;
    QLabel *label_6;
    QSlider *horizontalSlider_cam1_Y;
    QLabel *label_cam1_Y;
    QLabel *label_7;
    QSlider *horizontalSlider_cam1_R;
    QLabel *label_cam1_R;
    QLabel *label_8;
    QSlider *horizontalSlider_cam1_Z;
    QLabel *label_cam1_Z;
    QGroupBox *Cam2box;
    QGridLayout *gridLayout_3;
    QLabel *label_9;
    QSlider *horizontalSlider_cam2_X;
    QLabel *label_cam2_X;
    QLabel *label_10;
    QSlider *horizontalSlider_cam2_Y;
    QLabel *label_cam2_Y;
    QLabel *label_11;
    QSlider *horizontalSlider_cam2_R;
    QLabel *label_cam2_R;
    QLabel *label_12;
    QSlider *horizontalSlider_cam2_Z;
    QLabel *label_cam2_Z;
    QGroupBox *Cam3box;
    QGridLayout *gridLayout_4;
    QLabel *label_cam3_R;
    QSlider *horizontalSlider_cam3_Z;
    QLabel *label_29;
    QSlider *horizontalSlider_cam3_R;
    QLabel *label_31;
    QLabel *label_cam3_Z;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(4738, 2658);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(20, 30, 3461, 2371));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        TabWidget = new QTabWidget(horizontalLayoutWidget);
        TabWidget->setObjectName(QString::fromUtf8("TabWidget"));
        SubView1 = new QWidget();
        SubView1->setObjectName(QString::fromUtf8("SubView1"));
        main_widget_subview0 = new DisplayWidget(SubView1);
        main_widget_subview0->setObjectName(QString::fromUtf8("main_widget_subview0"));
        main_widget_subview0->setGeometry(QRect(0, 0, 1712, 1120));
        main_widget_subview1 = new DisplayWidget(SubView1);
        main_widget_subview1->setObjectName(QString::fromUtf8("main_widget_subview1"));
        main_widget_subview1->setGeometry(QRect(1730, 0, 1712, 1120));
        main_widget_subview2 = new DisplayWidget(SubView1);
        main_widget_subview2->setObjectName(QString::fromUtf8("main_widget_subview2"));
        main_widget_subview2->setGeometry(QRect(0, 1135, 1712, 1170));
        main_widget_subview3 = new DisplayWidget(SubView1);
        main_widget_subview3->setObjectName(QString::fromUtf8("main_widget_subview3"));
        main_widget_subview3->setGeometry(QRect(1730, 1135, 1712, 1170));
        TabWidget->addTab(SubView1, QString());
        SubView2 = new QWidget();
        SubView2->setObjectName(QString::fromUtf8("SubView2"));
        main_widget_subview7 = new DisplayWidget(SubView2);
        main_widget_subview7->setObjectName(QString::fromUtf8("main_widget_subview7"));
        main_widget_subview7->setGeometry(QRect(1730, 1135, 1712, 1170));
        main_widget_subview6 = new DisplayWidget(SubView2);
        main_widget_subview6->setObjectName(QString::fromUtf8("main_widget_subview6"));
        main_widget_subview6->setGeometry(QRect(0, 1135, 1712, 1170));
        main_widget_subview5 = new DisplayWidget(SubView2);
        main_widget_subview5->setObjectName(QString::fromUtf8("main_widget_subview5"));
        main_widget_subview5->setGeometry(QRect(1730, 0, 1712, 1120));
        main_widget_subview4 = new DisplayWidget(SubView2);
        main_widget_subview4->setObjectName(QString::fromUtf8("main_widget_subview4"));
        main_widget_subview4->setGeometry(QRect(0, 0, 1712, 1120));
        TabWidget->addTab(SubView2, QString());
        MainView = new QWidget();
        MainView->setObjectName(QString::fromUtf8("MainView"));
        main_widget_single = new DisplayWidget(MainView);
        main_widget_single->setObjectName(QString::fromUtf8("main_widget_single"));
        main_widget_single->setGeometry(QRect(0, 0, 3451, 2301));
        TabWidget->addTab(MainView, QString());
        Stitch = new QWidget();
        Stitch->setObjectName(QString::fromUtf8("Stitch"));
        main_widget_stitch = new DisplayWidget(Stitch);
        main_widget_stitch->setObjectName(QString::fromUtf8("main_widget_stitch"));
        main_widget_stitch->setGeometry(QRect(0, 0, 3451, 2301));
        TabWidget->addTab(Stitch, QString());

        horizontalLayout->addWidget(TabWidget);

        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(3490, 30, 601, 2391));
        pushButton_start = new QPushButton(widget);
        pushButton_start->setObjectName(QString::fromUtf8("pushButton_start"));
        pushButton_start->setGeometry(QRect(0, 0, 601, 48));
        groupBox_camSwitch = new QGroupBox(widget);
        groupBox_camSwitch->setObjectName(QString::fromUtf8("groupBox_camSwitch"));
        groupBox_camSwitch->setGeometry(QRect(0, 50, 601, 131));
        formLayout_2 = new QFormLayout(groupBox_camSwitch);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        radioButton_isUsb = new QRadioButton(groupBox_camSwitch);
        radioButton_isUsb->setObjectName(QString::fromUtf8("radioButton_isUsb"));
        radioButton_isUsb->setAutoExclusive(false);

        formLayout_2->setWidget(0, QFormLayout::LabelRole, radioButton_isUsb);

        radioButton_isVideo = new QRadioButton(groupBox_camSwitch);
        radioButton_isVideo->setObjectName(QString::fromUtf8("radioButton_isVideo"));
        radioButton_isVideo->setAutoExclusive(false);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, radioButton_isVideo);

        groupBox_camSelect = new QGroupBox(widget);
        groupBox_camSelect->setObjectName(QString::fromUtf8("groupBox_camSelect"));
        groupBox_camSelect->setEnabled(true);
        groupBox_camSelect->setGeometry(QRect(0, 180, 601, 201));
        formLayout = new QFormLayout(groupBox_camSelect);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        radioButton_cam0 = new QRadioButton(groupBox_camSelect);
        radioButton_cam0->setObjectName(QString::fromUtf8("radioButton_cam0"));
        radioButton_cam0->setAutoExclusive(false);

        formLayout->setWidget(0, QFormLayout::LabelRole, radioButton_cam0);

        radioButton_cam1 = new QRadioButton(groupBox_camSelect);
        radioButton_cam1->setObjectName(QString::fromUtf8("radioButton_cam1"));
        radioButton_cam1->setAutoExclusive(false);

        formLayout->setWidget(0, QFormLayout::FieldRole, radioButton_cam1);

        radioButton_cam2 = new QRadioButton(groupBox_camSelect);
        radioButton_cam2->setObjectName(QString::fromUtf8("radioButton_cam2"));
        radioButton_cam2->setAutoExclusive(false);

        formLayout->setWidget(1, QFormLayout::LabelRole, radioButton_cam2);

        radioButton_cam5 = new QRadioButton(groupBox_camSelect);
        radioButton_cam5->setObjectName(QString::fromUtf8("radioButton_cam5"));
        radioButton_cam5->setAutoExclusive(false);

        formLayout->setWidget(1, QFormLayout::FieldRole, radioButton_cam5);

        radioButton_cam4 = new QRadioButton(groupBox_camSelect);
        radioButton_cam4->setObjectName(QString::fromUtf8("radioButton_cam4"));
        radioButton_cam4->setAutoExclusive(false);

        formLayout->setWidget(2, QFormLayout::LabelRole, radioButton_cam4);

        radioButton_cam3 = new QRadioButton(groupBox_camSelect);
        radioButton_cam3->setObjectName(QString::fromUtf8("radioButton_cam3"));
        radioButton_cam3->setAutoExclusive(false);

        formLayout->setWidget(2, QFormLayout::FieldRole, radioButton_cam3);

        groupBox_airParam = new QGroupBox(widget);
        groupBox_airParam->setObjectName(QString::fromUtf8("groupBox_airParam"));
        groupBox_airParam->setGeometry(QRect(0, 380, 601, 281));
        verticalLayout = new QVBoxLayout(groupBox_airParam);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalSlider_Rch = new QSlider(groupBox_airParam);
        horizontalSlider_Rch->setObjectName(QString::fromUtf8("horizontalSlider_Rch"));
        QFont font;
        font.setPointSize(16);
        horizontalSlider_Rch->setFont(font);
        horizontalSlider_Rch->setMinimum(1);
        horizontalSlider_Rch->setSliderPosition(70);
        horizontalSlider_Rch->setOrientation(Qt::Horizontal);
        horizontalSlider_Rch->setTickPosition(QSlider::NoTicks);

        verticalLayout->addWidget(horizontalSlider_Rch);

        label_Red = new QLabel(groupBox_airParam);
        label_Red->setObjectName(QString::fromUtf8("label_Red"));

        verticalLayout->addWidget(label_Red);

        horizontalSlider_Gch = new QSlider(groupBox_airParam);
        horizontalSlider_Gch->setObjectName(QString::fromUtf8("horizontalSlider_Gch"));
        horizontalSlider_Gch->setFont(font);
        horizontalSlider_Gch->setMinimum(1);
        horizontalSlider_Gch->setSliderPosition(70);
        horizontalSlider_Gch->setOrientation(Qt::Horizontal);
        horizontalSlider_Gch->setTickPosition(QSlider::NoTicks);

        verticalLayout->addWidget(horizontalSlider_Gch);

        label_Green = new QLabel(groupBox_airParam);
        label_Green->setObjectName(QString::fromUtf8("label_Green"));

        verticalLayout->addWidget(label_Green);

        horizontalSlider_Bch = new QSlider(groupBox_airParam);
        horizontalSlider_Bch->setObjectName(QString::fromUtf8("horizontalSlider_Bch"));
        horizontalSlider_Bch->setFont(font);
        horizontalSlider_Bch->setMinimum(1);
        horizontalSlider_Bch->setSliderPosition(70);
        horizontalSlider_Bch->setOrientation(Qt::Horizontal);
        horizontalSlider_Bch->setTickPosition(QSlider::NoTicks);

        verticalLayout->addWidget(horizontalSlider_Bch);

        label_Blue = new QLabel(groupBox_airParam);
        label_Blue->setObjectName(QString::fromUtf8("label_Blue"));

        verticalLayout->addWidget(label_Blue);

        groupBox_dehaze = new QGroupBox(widget);
        groupBox_dehaze->setObjectName(QString::fromUtf8("groupBox_dehaze"));
        groupBox_dehaze->setGeometry(QRect(0, 670, 601, 101));
        verticalLayout_2 = new QVBoxLayout(groupBox_dehaze);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        radioButton_isDehaze = new QRadioButton(groupBox_dehaze);
        radioButton_isDehaze->setObjectName(QString::fromUtf8("radioButton_isDehaze"));

        verticalLayout_2->addWidget(radioButton_isDehaze);

        groupBox_dedark = new QGroupBox(widget);
        groupBox_dedark->setObjectName(QString::fromUtf8("groupBox_dedark"));
        groupBox_dedark->setGeometry(QRect(0, 780, 601, 101));
        verticalLayout_3 = new QVBoxLayout(groupBox_dedark);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        radioButton_isEnhance = new QRadioButton(groupBox_dedark);
        radioButton_isEnhance->setObjectName(QString::fromUtf8("radioButton_isEnhance"));

        verticalLayout_3->addWidget(radioButton_isEnhance);

        radioButton_colorCorrection = new QRadioButton(widget);
        radioButton_colorCorrection->setObjectName(QString::fromUtf8("radioButton_colorCorrection"));
        radioButton_colorCorrection->setEnabled(true);
        radioButton_colorCorrection->setGeometry(QRect(10, 920, 271, 40));
        radioButton_colorCorrection->setAcceptDrops(true);
        radioButton_colorCorrection->setAutoExclusive(false);
        line_colorCorrect = new QFrame(widget);
        line_colorCorrect->setObjectName(QString::fromUtf8("line_colorCorrect"));
        line_colorCorrect->setGeometry(QRect(0, 890, 601, 16));
        line_colorCorrect->setFrameShape(QFrame::HLine);
        line_colorCorrect->setFrameShadow(QFrame::Sunken);
        line_isTwinView = new QFrame(widget);
        line_isTwinView->setObjectName(QString::fromUtf8("line_isTwinView"));
        line_isTwinView->setGeometry(QRect(0, 970, 601, 16));
        line_isTwinView->setFrameShape(QFrame::HLine);
        line_isTwinView->setFrameShadow(QFrame::Sunken);
        radioButton_isTwinView = new QRadioButton(widget);
        radioButton_isTwinView->setObjectName(QString::fromUtf8("radioButton_isTwinView"));
        radioButton_isTwinView->setGeometry(QRect(10, 990, 212, 40));
        radioButton_isTwinView->setAcceptDrops(true);
        radioButton_isTwinView->setAutoExclusive(false);
        line_LowLightParam = new QFrame(widget);
        line_LowLightParam->setObjectName(QString::fromUtf8("line_LowLightParam"));
        line_LowLightParam->setGeometry(QRect(0, 1040, 601, 16));
        line_LowLightParam->setFrameShape(QFrame::HLine);
        line_LowLightParam->setFrameShadow(QFrame::Sunken);
        label_show_enhance_val = new QLabel(widget);
        label_show_enhance_val->setObjectName(QString::fromUtf8("label_show_enhance_val"));
        label_show_enhance_val->setGeometry(QRect(160, 1060, 211, 34));
        horizontalSlider_enhance_kval = new QSlider(widget);
        horizontalSlider_enhance_kval->setObjectName(QString::fromUtf8("horizontalSlider_enhance_kval"));
        horizontalSlider_enhance_kval->setGeometry(QRect(40, 1100, 511, 30));
        horizontalSlider_enhance_kval->setMinimum(3);
        horizontalSlider_enhance_kval->setMaximum(10);
        horizontalSlider_enhance_kval->setPageStep(1);
        horizontalSlider_enhance_kval->setOrientation(Qt::Horizontal);
        label_enhance_val = new QLabel(widget);
        label_enhance_val->setObjectName(QString::fromUtf8("label_enhance_val"));
        label_enhance_val->setGeometry(QRect(270, 1130, 41, 34));
        line_LowLightParam_2 = new QFrame(widget);
        line_LowLightParam_2->setObjectName(QString::fromUtf8("line_LowLightParam_2"));
        line_LowLightParam_2->setGeometry(QRect(0, 1170, 601, 16));
        line_LowLightParam_2->setFrameShape(QFrame::HLine);
        line_LowLightParam_2->setFrameShadow(QFrame::Sunken);
        label_show_zoom_val = new QLabel(widget);
        label_show_zoom_val->setObjectName(QString::fromUtf8("label_show_zoom_val"));
        label_show_zoom_val->setGeometry(QRect(180, 1200, 171, 34));
        horizontalSlider_zoom_val = new QSlider(widget);
        horizontalSlider_zoom_val->setObjectName(QString::fromUtf8("horizontalSlider_zoom_val"));
        horizontalSlider_zoom_val->setGeometry(QRect(40, 1240, 511, 30));
        horizontalSlider_zoom_val->setMaximum(80);
        horizontalSlider_zoom_val->setPageStep(1);
        horizontalSlider_zoom_val->setOrientation(Qt::Horizontal);
        label_zoom_val = new QLabel(widget);
        label_zoom_val->setObjectName(QString::fromUtf8("label_zoom_val"));
        label_zoom_val->setGeometry(QRect(270, 1270, 31, 34));
        spinBox_zoom_val = new QSpinBox(widget);
        spinBox_zoom_val->setObjectName(QString::fromUtf8("spinBox_zoom_val"));
        spinBox_zoom_val->setGeometry(QRect(0, 1310, 601, 49));
        pushButton_updateparam = new QPushButton(widget);
        pushButton_updateparam->setObjectName(QString::fromUtf8("pushButton_updateparam"));
        pushButton_updateparam->setGeometry(QRect(0, 1370, 601, 48));
        pushButton_colorCorrection = new QPushButton(widget);
        pushButton_colorCorrection->setObjectName(QString::fromUtf8("pushButton_colorCorrection"));
        pushButton_colorCorrection->setGeometry(QRect(0, 1430, 601, 48));
        scrollArea = new QScrollArea(widget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(0, 1490, 601, 881));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 599, 879));
        Cam0box = new QGroupBox(scrollAreaWidgetContents);
        Cam0box->setObjectName(QString::fromUtf8("Cam0box"));
        Cam0box->setGeometry(QRect(0, 0, 601, 215));
        gridLayout = new QGridLayout(Cam0box);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalSlider_cam0_R = new QSlider(Cam0box);
        horizontalSlider_cam0_R->setObjectName(QString::fromUtf8("horizontalSlider_cam0_R"));
        horizontalSlider_cam0_R->setMinimum(-45);
        horizontalSlider_cam0_R->setMaximum(45);
        horizontalSlider_cam0_R->setPageStep(1);
        horizontalSlider_cam0_R->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalSlider_cam0_R, 2, 1, 1, 1);

        label_3 = new QLabel(Cam0box);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        horizontalSlider_cam0_Z = new QSlider(Cam0box);
        horizontalSlider_cam0_Z->setObjectName(QString::fromUtf8("horizontalSlider_cam0_Z"));
        horizontalSlider_cam0_Z->setMaximum(10);
        horizontalSlider_cam0_Z->setPageStep(1);
        horizontalSlider_cam0_Z->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalSlider_cam0_Z, 3, 1, 1, 1);

        label = new QLabel(Cam0box);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        horizontalSlider_cam0_X = new QSlider(Cam0box);
        horizontalSlider_cam0_X->setObjectName(QString::fromUtf8("horizontalSlider_cam0_X"));
        horizontalSlider_cam0_X->setMaximum(150);
        horizontalSlider_cam0_X->setPageStep(1);
        horizontalSlider_cam0_X->setValue(0);
        horizontalSlider_cam0_X->setSliderPosition(0);
        horizontalSlider_cam0_X->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalSlider_cam0_X, 0, 1, 1, 1);

        label_can0_Y = new QLabel(Cam0box);
        label_can0_Y->setObjectName(QString::fromUtf8("label_can0_Y"));

        gridLayout->addWidget(label_can0_Y, 1, 2, 1, 1);

        label_cam0_X = new QLabel(Cam0box);
        label_cam0_X->setObjectName(QString::fromUtf8("label_cam0_X"));

        gridLayout->addWidget(label_cam0_X, 0, 2, 1, 1);

        label_cam0_R = new QLabel(Cam0box);
        label_cam0_R->setObjectName(QString::fromUtf8("label_cam0_R"));

        gridLayout->addWidget(label_cam0_R, 2, 2, 1, 1);

        label_4 = new QLabel(Cam0box);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        label_cam0_Z = new QLabel(Cam0box);
        label_cam0_Z->setObjectName(QString::fromUtf8("label_cam0_Z"));

        gridLayout->addWidget(label_cam0_Z, 3, 2, 1, 1);

        label_2 = new QLabel(Cam0box);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        horizontalSlider_cam0_Y = new QSlider(Cam0box);
        horizontalSlider_cam0_Y->setObjectName(QString::fromUtf8("horizontalSlider_cam0_Y"));
        horizontalSlider_cam0_Y->setMaximum(150);
        horizontalSlider_cam0_Y->setPageStep(1);
        horizontalSlider_cam0_Y->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(horizontalSlider_cam0_Y, 1, 1, 1, 1);

        Cam1box = new QGroupBox(scrollAreaWidgetContents);
        Cam1box->setObjectName(QString::fromUtf8("Cam1box"));
        Cam1box->setGeometry(QRect(0, 220, 601, 215));
        gridLayout_2 = new QGridLayout(Cam1box);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_5 = new QLabel(Cam1box);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_2->addWidget(label_5, 0, 0, 1, 1);

        horizontalSlider_cam1_X = new QSlider(Cam1box);
        horizontalSlider_cam1_X->setObjectName(QString::fromUtf8("horizontalSlider_cam1_X"));
        horizontalSlider_cam1_X->setMaximum(150);
        horizontalSlider_cam1_X->setPageStep(1);
        horizontalSlider_cam1_X->setValue(0);
        horizontalSlider_cam1_X->setSliderPosition(0);
        horizontalSlider_cam1_X->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(horizontalSlider_cam1_X, 0, 1, 1, 1);

        label_cam1_X = new QLabel(Cam1box);
        label_cam1_X->setObjectName(QString::fromUtf8("label_cam1_X"));

        gridLayout_2->addWidget(label_cam1_X, 0, 2, 1, 1);

        label_6 = new QLabel(Cam1box);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_2->addWidget(label_6, 1, 0, 1, 1);

        horizontalSlider_cam1_Y = new QSlider(Cam1box);
        horizontalSlider_cam1_Y->setObjectName(QString::fromUtf8("horizontalSlider_cam1_Y"));
        horizontalSlider_cam1_Y->setMaximum(150);
        horizontalSlider_cam1_Y->setPageStep(1);
        horizontalSlider_cam1_Y->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(horizontalSlider_cam1_Y, 1, 1, 1, 1);

        label_cam1_Y = new QLabel(Cam1box);
        label_cam1_Y->setObjectName(QString::fromUtf8("label_cam1_Y"));

        gridLayout_2->addWidget(label_cam1_Y, 1, 2, 1, 1);

        label_7 = new QLabel(Cam1box);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_2->addWidget(label_7, 2, 0, 1, 1);

        horizontalSlider_cam1_R = new QSlider(Cam1box);
        horizontalSlider_cam1_R->setObjectName(QString::fromUtf8("horizontalSlider_cam1_R"));
        horizontalSlider_cam1_R->setMinimum(-45);
        horizontalSlider_cam1_R->setMaximum(45);
        horizontalSlider_cam1_R->setPageStep(1);
        horizontalSlider_cam1_R->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(horizontalSlider_cam1_R, 2, 1, 1, 1);

        label_cam1_R = new QLabel(Cam1box);
        label_cam1_R->setObjectName(QString::fromUtf8("label_cam1_R"));

        gridLayout_2->addWidget(label_cam1_R, 2, 2, 1, 1);

        label_8 = new QLabel(Cam1box);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_2->addWidget(label_8, 3, 0, 1, 1);

        horizontalSlider_cam1_Z = new QSlider(Cam1box);
        horizontalSlider_cam1_Z->setObjectName(QString::fromUtf8("horizontalSlider_cam1_Z"));
        horizontalSlider_cam1_Z->setMaximum(10);
        horizontalSlider_cam1_Z->setPageStep(1);
        horizontalSlider_cam1_Z->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(horizontalSlider_cam1_Z, 3, 1, 1, 1);

        label_cam1_Z = new QLabel(Cam1box);
        label_cam1_Z->setObjectName(QString::fromUtf8("label_cam1_Z"));

        gridLayout_2->addWidget(label_cam1_Z, 3, 2, 1, 1);

        Cam2box = new QGroupBox(scrollAreaWidgetContents);
        Cam2box->setObjectName(QString::fromUtf8("Cam2box"));
        Cam2box->setGeometry(QRect(0, 430, 601, 215));
        gridLayout_3 = new QGridLayout(Cam2box);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_9 = new QLabel(Cam2box);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout_3->addWidget(label_9, 0, 0, 1, 1);

        horizontalSlider_cam2_X = new QSlider(Cam2box);
        horizontalSlider_cam2_X->setObjectName(QString::fromUtf8("horizontalSlider_cam2_X"));
        horizontalSlider_cam2_X->setMaximum(150);
        horizontalSlider_cam2_X->setPageStep(1);
        horizontalSlider_cam2_X->setValue(0);
        horizontalSlider_cam2_X->setSliderPosition(0);
        horizontalSlider_cam2_X->setOrientation(Qt::Horizontal);

        gridLayout_3->addWidget(horizontalSlider_cam2_X, 0, 1, 1, 1);

        label_cam2_X = new QLabel(Cam2box);
        label_cam2_X->setObjectName(QString::fromUtf8("label_cam2_X"));

        gridLayout_3->addWidget(label_cam2_X, 0, 2, 1, 1);

        label_10 = new QLabel(Cam2box);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout_3->addWidget(label_10, 1, 0, 1, 1);

        horizontalSlider_cam2_Y = new QSlider(Cam2box);
        horizontalSlider_cam2_Y->setObjectName(QString::fromUtf8("horizontalSlider_cam2_Y"));
        horizontalSlider_cam2_Y->setMaximum(150);
        horizontalSlider_cam2_Y->setPageStep(1);
        horizontalSlider_cam2_Y->setOrientation(Qt::Horizontal);

        gridLayout_3->addWidget(horizontalSlider_cam2_Y, 1, 1, 1, 1);

        label_cam2_Y = new QLabel(Cam2box);
        label_cam2_Y->setObjectName(QString::fromUtf8("label_cam2_Y"));

        gridLayout_3->addWidget(label_cam2_Y, 1, 2, 1, 1);

        label_11 = new QLabel(Cam2box);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout_3->addWidget(label_11, 2, 0, 1, 1);

        horizontalSlider_cam2_R = new QSlider(Cam2box);
        horizontalSlider_cam2_R->setObjectName(QString::fromUtf8("horizontalSlider_cam2_R"));
        horizontalSlider_cam2_R->setMinimum(-45);
        horizontalSlider_cam2_R->setMaximum(45);
        horizontalSlider_cam2_R->setPageStep(1);
        horizontalSlider_cam2_R->setOrientation(Qt::Horizontal);

        gridLayout_3->addWidget(horizontalSlider_cam2_R, 2, 1, 1, 1);

        label_cam2_R = new QLabel(Cam2box);
        label_cam2_R->setObjectName(QString::fromUtf8("label_cam2_R"));

        gridLayout_3->addWidget(label_cam2_R, 2, 2, 1, 1);

        label_12 = new QLabel(Cam2box);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout_3->addWidget(label_12, 3, 0, 1, 1);

        horizontalSlider_cam2_Z = new QSlider(Cam2box);
        horizontalSlider_cam2_Z->setObjectName(QString::fromUtf8("horizontalSlider_cam2_Z"));
        horizontalSlider_cam2_Z->setMaximum(10);
        horizontalSlider_cam2_Z->setPageStep(1);
        horizontalSlider_cam2_Z->setOrientation(Qt::Horizontal);

        gridLayout_3->addWidget(horizontalSlider_cam2_Z, 3, 1, 1, 1);

        label_cam2_Z = new QLabel(Cam2box);
        label_cam2_Z->setObjectName(QString::fromUtf8("label_cam2_Z"));

        gridLayout_3->addWidget(label_cam2_Z, 3, 2, 1, 1);

        Cam3box = new QGroupBox(scrollAreaWidgetContents);
        Cam3box->setObjectName(QString::fromUtf8("Cam3box"));
        Cam3box->setGeometry(QRect(0, 650, 601, 141));
        gridLayout_4 = new QGridLayout(Cam3box);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        label_cam3_R = new QLabel(Cam3box);
        label_cam3_R->setObjectName(QString::fromUtf8("label_cam3_R"));

        gridLayout_4->addWidget(label_cam3_R, 0, 2, 1, 1);

        horizontalSlider_cam3_Z = new QSlider(Cam3box);
        horizontalSlider_cam3_Z->setObjectName(QString::fromUtf8("horizontalSlider_cam3_Z"));
        horizontalSlider_cam3_Z->setMaximum(10);
        horizontalSlider_cam3_Z->setPageStep(1);
        horizontalSlider_cam3_Z->setOrientation(Qt::Horizontal);

        gridLayout_4->addWidget(horizontalSlider_cam3_Z, 1, 1, 1, 1);

        label_29 = new QLabel(Cam3box);
        label_29->setObjectName(QString::fromUtf8("label_29"));

        gridLayout_4->addWidget(label_29, 0, 0, 1, 1);

        horizontalSlider_cam3_R = new QSlider(Cam3box);
        horizontalSlider_cam3_R->setObjectName(QString::fromUtf8("horizontalSlider_cam3_R"));
        horizontalSlider_cam3_R->setMinimum(-45);
        horizontalSlider_cam3_R->setMaximum(45);
        horizontalSlider_cam3_R->setPageStep(1);
        horizontalSlider_cam3_R->setOrientation(Qt::Horizontal);

        gridLayout_4->addWidget(horizontalSlider_cam3_R, 0, 1, 1, 1);

        label_31 = new QLabel(Cam3box);
        label_31->setObjectName(QString::fromUtf8("label_31"));

        gridLayout_4->addWidget(label_31, 1, 0, 1, 1);

        label_cam3_Z = new QLabel(Cam3box);
        label_cam3_Z->setObjectName(QString::fromUtf8("label_cam3_Z"));

        gridLayout_4->addWidget(label_cam3_Z, 1, 2, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 4738, 39));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        TabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        TabWidget->setTabText(TabWidget->indexOf(SubView1), QCoreApplication::translate("MainWindow", "SubView1", nullptr));
        TabWidget->setTabText(TabWidget->indexOf(SubView2), QCoreApplication::translate("MainWindow", "SubView2", nullptr));
        TabWidget->setTabText(TabWidget->indexOf(MainView), QCoreApplication::translate("MainWindow", "MainView", nullptr));
        TabWidget->setTabText(TabWidget->indexOf(Stitch), QCoreApplication::translate("MainWindow", "Stitch", nullptr));
        pushButton_start->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        groupBox_camSwitch->setTitle(QCoreApplication::translate("MainWindow", "Source", nullptr));
        radioButton_isUsb->setText(QCoreApplication::translate("MainWindow", "USB", nullptr));
        radioButton_isVideo->setText(QCoreApplication::translate("MainWindow", "Video", nullptr));
        groupBox_camSelect->setTitle(QCoreApplication::translate("MainWindow", "CamSelect", nullptr));
        radioButton_cam0->setText(QCoreApplication::translate("MainWindow", "Cam1", nullptr));
        radioButton_cam1->setText(QCoreApplication::translate("MainWindow", "Cam2", nullptr));
        radioButton_cam2->setText(QCoreApplication::translate("MainWindow", "Cam3", nullptr));
        radioButton_cam5->setText(QCoreApplication::translate("MainWindow", "Cam4", nullptr));
        radioButton_cam4->setText(QCoreApplication::translate("MainWindow", "Cam5", nullptr));
        radioButton_cam3->setText(QCoreApplication::translate("MainWindow", "Cam6", nullptr));
        groupBox_airParam->setTitle(QCoreApplication::translate("MainWindow", "AirChannel", nullptr));
        label_Red->setText(QCoreApplication::translate("MainWindow", "R : 0.7", nullptr));
        label_Green->setText(QCoreApplication::translate("MainWindow", "G : 0.7", nullptr));
        label_Blue->setText(QCoreApplication::translate("MainWindow", "B : 0.7", nullptr));
        groupBox_dehaze->setTitle(QCoreApplication::translate("MainWindow", "Dehaze", nullptr));
        radioButton_isDehaze->setText(QCoreApplication::translate("MainWindow", "Enable", nullptr));
        groupBox_dedark->setTitle(QCoreApplication::translate("MainWindow", "LowLightEnhance", nullptr));
        radioButton_isEnhance->setText(QCoreApplication::translate("MainWindow", "Enable", nullptr));
        radioButton_colorCorrection->setText(QCoreApplication::translate("MainWindow", "colorCorrection", nullptr));
        radioButton_isTwinView->setText(QCoreApplication::translate("MainWindow", "isTwinView", nullptr));
        label_show_enhance_val->setText(QCoreApplication::translate("MainWindow", "LowLightParam", nullptr));
        label_enhance_val->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        label_show_zoom_val->setText(QCoreApplication::translate("MainWindow", "Zoom Param", nullptr));
        label_zoom_val->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        pushButton_updateparam->setText(QCoreApplication::translate("MainWindow", "UpdateParam", nullptr));
        pushButton_colorCorrection->setText(QCoreApplication::translate("MainWindow", "ColorCorrection", nullptr));
        Cam0box->setTitle(QCoreApplication::translate("MainWindow", "Cam0 adjustment tools", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Rolate", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "X ", nullptr));
        label_can0_Y->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_cam0_X->setText(QCoreApplication::translate("MainWindow", "000", nullptr));
        label_cam0_R->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Zoom", nullptr));
        label_cam0_Z->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        Cam1box->setTitle(QCoreApplication::translate("MainWindow", "Cam1 adjustment tools", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "X ", nullptr));
        label_cam1_X->setText(QCoreApplication::translate("MainWindow", "000", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        label_cam1_Y->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Rolate", nullptr));
        label_cam1_R->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Zoom", nullptr));
        label_cam1_Z->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        Cam2box->setTitle(QCoreApplication::translate("MainWindow", "Cam2 adjustment tools", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "X ", nullptr));
        label_cam2_X->setText(QCoreApplication::translate("MainWindow", "000", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        label_cam2_Y->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Rolate", nullptr));
        label_cam2_R->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "Zoom", nullptr));
        label_cam2_Z->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        Cam3box->setTitle(QCoreApplication::translate("MainWindow", "Global adjustment tools", nullptr));
        label_cam3_R->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_29->setText(QCoreApplication::translate("MainWindow", "Rolate", nullptr));
        label_31->setText(QCoreApplication::translate("MainWindow", "Zoom", nullptr));
        label_cam3_Z->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
