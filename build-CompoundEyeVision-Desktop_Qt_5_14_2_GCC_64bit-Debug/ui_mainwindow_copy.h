/********************************************************************************
** Form generated from reading UI file 'mainwindow_copy.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_COPY_H
#define UI_MAINWINDOW_COPY_H

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
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "displaywidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QTabWidget *tabWidget;
    QWidget *tab_3;
    QGridLayout *gridLayout_2;
    DisplayWidget *main_widget_subview0;
    DisplayWidget *main_widget_subview1;
    DisplayWidget *main_widget_subview2;
    DisplayWidget *main_widget_subview3;
    QWidget *tab_2;
    QGridLayout *gridLayout_6;
    DisplayWidget *main_widget_subview6;
    DisplayWidget *main_widget_subview5;
    DisplayWidget *main_widget_subview4;
    DisplayWidget *main_widget_subview7;
    QWidget *tab_4;
    QGridLayout *gridLayout_3;
    DisplayWidget *main_widget_single;
    QWidget *tab;
    QGridLayout *gridLayout_5;
    DisplayWidget *main_widget_stitch;
    DisplayWidget *main_widget_free;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pushButton_start;
    QGroupBox *groupBox_camswitch;
    QFormLayout *formLayout_2;
    QRadioButton *radioButton_isSpincam;
    QRadioButton *radioButton_isWebCam;
    QFrame *line_8;
    QGroupBox *groupBox_CamSelect;
    QFormLayout *formLayout;
    QRadioButton *radioButton_cam0;
    QRadioButton *radioButton_cam4;
    QRadioButton *radioButton_cam1;
    QRadioButton *radioButton_cam5;
    QRadioButton *radioButton_cam2;
    QRadioButton *radioButton_cam6;
    QRadioButton *radioButton_cam3;
    QRadioButton *radioButton_cam7;
    QFrame *line_2;
    QGroupBox *groupBox_airParam;
    QVBoxLayout *verticalLayout_3;
    QSlider *horizontalSlider_Rch;
    QLabel *label_Red;
    QSlider *horizontalSlider_Gch;
    QLabel *label_Green;
    QSlider *horizontalSlider_Bch;
    QLabel *label_Blue;
    QFrame *line;
    QGroupBox *groupBox_dehaze;
    QVBoxLayout *verticalLayout_4;
    QRadioButton *radioButton_isDehaze;
    QFrame *line_10;
    QGroupBox *groupBox_dedark;
    QVBoxLayout *verticalLayout_7;
    QRadioButton *radioButton_isEnhance;
    QFrame *line_9;
    QRadioButton *radioButton_interframe;
    QRadioButton *radioButton_colorCorrection;
    QFrame *line_3;
    QFrame *line_5;
    QRadioButton *radioButton_isTwinView;
    QFrame *line_6;
    QLabel *label_show_enhanece_val;
    QSlider *horizontalSlider_enhanece_kval;
    QLabel *label_enhanece_val;
    QLabel *label_show_zoom_val;
    QSlider *horizontalSlider_zoom_val;
    QLabel *label_zoom_val;
    QSpinBox *spinBox_zoom_val;
    QPushButton *pushButton_updateparam;
    QPushButton *pushButton_CC;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents_2;
    QGroupBox *Cam4box;
    QSlider *horizontalSlider_cam4_X;
    QSlider *horizontalSlider_cam4_R;
    QSlider *horizontalSlider_cam4_Y;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_cam4_X;
    QLabel *label_cam4_Y;
    QLabel *label_cam4_R;
    QSlider *horizontalSlider_cam4_Z;
    QLabel *label_cam4_Z;
    QLabel *label_7;
    QGroupBox *Cam2box;
    QSlider *horizontalSlider_cam2_X;
    QSlider *horizontalSlider_cam2_R;
    QSlider *horizontalSlider_cam2_Y;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_18;
    QLabel *label_cam2_X;
    QLabel *label_cam2_Y;
    QLabel *label_cam2_R;
    QSlider *horizontalSlider_cam2_Z;
    QLabel *label_cam2_Z;
    QLabel *label_9;
    QGroupBox *Cam1box;
    QSlider *horizontalSlider_cam1_X;
    QSlider *horizontalSlider_cam1_R;
    QSlider *horizontalSlider_cam1_Y;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_cam1_X;
    QLabel *label_cam1_Y;
    QLabel *label_cam1_R;
    QSlider *horizontalSlider_cam1_Z;
    QLabel *label_cam1_Z;
    QLabel *label_8;
    QSlider *horizontalSlider_camGlobal_R;
    QLabel *label_11;
    QLabel *label_camGlobal_R;
    QLabel *label_25;
    QSlider *horizontalSlider_camGlobal_Z;
    QLabel *label_camGlobal_Z;
    QSpacerItem *verticalSpacer;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(4240, 2546);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        centralWidget->setMinimumSize(QSize(787, 578));
        centralWidget->setMaximumSize(QSize(3840, 2160));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        sizePolicy.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy);
        tabWidget->setAcceptDrops(false);
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        gridLayout_2 = new QGridLayout(tab_3);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        main_widget_subview0 = new DisplayWidget(tab_3);
        main_widget_subview0->setObjectName(QString::fromUtf8("main_widget_subview0"));
        sizePolicy.setHeightForWidth(main_widget_subview0->sizePolicy().hasHeightForWidth());
        main_widget_subview0->setSizePolicy(sizePolicy);
        main_widget_subview0->setMinimumSize(QSize(480, 270));

        gridLayout_2->addWidget(main_widget_subview0, 0, 0, 1, 1);

        main_widget_subview1 = new DisplayWidget(tab_3);
        main_widget_subview1->setObjectName(QString::fromUtf8("main_widget_subview1"));
        sizePolicy.setHeightForWidth(main_widget_subview1->sizePolicy().hasHeightForWidth());
        main_widget_subview1->setSizePolicy(sizePolicy);
        main_widget_subview1->setMinimumSize(QSize(480, 270));

        gridLayout_2->addWidget(main_widget_subview1, 0, 1, 1, 1);

        main_widget_subview2 = new DisplayWidget(tab_3);
        main_widget_subview2->setObjectName(QString::fromUtf8("main_widget_subview2"));
        sizePolicy.setHeightForWidth(main_widget_subview2->sizePolicy().hasHeightForWidth());
        main_widget_subview2->setSizePolicy(sizePolicy);
        main_widget_subview2->setMinimumSize(QSize(480, 270));

        gridLayout_2->addWidget(main_widget_subview2, 1, 0, 1, 1);

        main_widget_subview3 = new DisplayWidget(tab_3);
        main_widget_subview3->setObjectName(QString::fromUtf8("main_widget_subview3"));
        sizePolicy.setHeightForWidth(main_widget_subview3->sizePolicy().hasHeightForWidth());
        main_widget_subview3->setSizePolicy(sizePolicy);
        main_widget_subview3->setMinimumSize(QSize(480, 270));

        gridLayout_2->addWidget(main_widget_subview3, 1, 1, 1, 1);

        tabWidget->addTab(tab_3, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        gridLayout_6 = new QGridLayout(tab_2);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        main_widget_subview6 = new DisplayWidget(tab_2);
        main_widget_subview6->setObjectName(QString::fromUtf8("main_widget_subview6"));
        sizePolicy.setHeightForWidth(main_widget_subview6->sizePolicy().hasHeightForWidth());
        main_widget_subview6->setSizePolicy(sizePolicy);
        main_widget_subview6->setMinimumSize(QSize(480, 270));

        gridLayout_6->addWidget(main_widget_subview6, 1, 0, 1, 1);

        main_widget_subview5 = new DisplayWidget(tab_2);
        main_widget_subview5->setObjectName(QString::fromUtf8("main_widget_subview5"));
        sizePolicy.setHeightForWidth(main_widget_subview5->sizePolicy().hasHeightForWidth());
        main_widget_subview5->setSizePolicy(sizePolicy);
        main_widget_subview5->setMinimumSize(QSize(480, 270));

        gridLayout_6->addWidget(main_widget_subview5, 0, 2, 1, 1);

        main_widget_subview4 = new DisplayWidget(tab_2);
        main_widget_subview4->setObjectName(QString::fromUtf8("main_widget_subview4"));
        sizePolicy.setHeightForWidth(main_widget_subview4->sizePolicy().hasHeightForWidth());
        main_widget_subview4->setSizePolicy(sizePolicy);
        main_widget_subview4->setMinimumSize(QSize(480, 270));

        gridLayout_6->addWidget(main_widget_subview4, 0, 0, 1, 1);

        main_widget_subview7 = new DisplayWidget(tab_2);
        main_widget_subview7->setObjectName(QString::fromUtf8("main_widget_subview7"));
        sizePolicy.setHeightForWidth(main_widget_subview7->sizePolicy().hasHeightForWidth());
        main_widget_subview7->setSizePolicy(sizePolicy);
        main_widget_subview7->setMinimumSize(QSize(480, 270));

        gridLayout_6->addWidget(main_widget_subview7, 1, 2, 1, 1);

        tabWidget->addTab(tab_2, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        gridLayout_3 = new QGridLayout(tab_4);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        main_widget_single = new DisplayWidget(tab_4);
        main_widget_single->setObjectName(QString::fromUtf8("main_widget_single"));
        main_widget_single->setAcceptDrops(false);

        gridLayout_3->addWidget(main_widget_single, 0, 0, 1, 1);

        tabWidget->addTab(tab_4, QString());
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        gridLayout_5 = new QGridLayout(tab);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        main_widget_stitch = new DisplayWidget(tab);
        main_widget_stitch->setObjectName(QString::fromUtf8("main_widget_stitch"));
        main_widget_free = new DisplayWidget(main_widget_stitch);
        main_widget_free->setObjectName(QString::fromUtf8("main_widget_free"));
        main_widget_free->setGeometry(QRect(560, 130, 120, 80));
        main_widget_free->setAcceptDrops(true);

        gridLayout_5->addWidget(main_widget_stitch, 0, 0, 1, 1);

        tabWidget->addTab(tab, QString());

        horizontalLayout->addWidget(tabWidget);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setSizeConstraint(QLayout::SetMinimumSize);
        verticalLayout_2->setContentsMargins(10, -1, -1, -1);
        pushButton_start = new QPushButton(centralWidget);
        pushButton_start->setObjectName(QString::fromUtf8("pushButton_start"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton_start->sizePolicy().hasHeightForWidth());
        pushButton_start->setSizePolicy(sizePolicy1);
        pushButton_start->setMinimumSize(QSize(100, 0));

        verticalLayout_2->addWidget(pushButton_start);

        groupBox_camswitch = new QGroupBox(centralWidget);
        groupBox_camswitch->setObjectName(QString::fromUtf8("groupBox_camswitch"));
        formLayout_2 = new QFormLayout(groupBox_camswitch);
        formLayout_2->setSpacing(6);
        formLayout_2->setContentsMargins(11, 11, 11, 11);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        radioButton_isSpincam = new QRadioButton(groupBox_camswitch);
        radioButton_isSpincam->setObjectName(QString::fromUtf8("radioButton_isSpincam"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, radioButton_isSpincam);

        radioButton_isWebCam = new QRadioButton(groupBox_camswitch);
        radioButton_isWebCam->setObjectName(QString::fromUtf8("radioButton_isWebCam"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, radioButton_isWebCam);


        verticalLayout_2->addWidget(groupBox_camswitch);

        line_8 = new QFrame(centralWidget);
        line_8->setObjectName(QString::fromUtf8("line_8"));
        line_8->setFrameShape(QFrame::HLine);
        line_8->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line_8);

        groupBox_CamSelect = new QGroupBox(centralWidget);
        groupBox_CamSelect->setObjectName(QString::fromUtf8("groupBox_CamSelect"));
        formLayout = new QFormLayout(groupBox_CamSelect);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        radioButton_cam0 = new QRadioButton(groupBox_CamSelect);
        radioButton_cam0->setObjectName(QString::fromUtf8("radioButton_cam0"));

        formLayout->setWidget(0, QFormLayout::LabelRole, radioButton_cam0);

        radioButton_cam4 = new QRadioButton(groupBox_CamSelect);
        radioButton_cam4->setObjectName(QString::fromUtf8("radioButton_cam4"));

        formLayout->setWidget(0, QFormLayout::FieldRole, radioButton_cam4);

        radioButton_cam1 = new QRadioButton(groupBox_CamSelect);
        radioButton_cam1->setObjectName(QString::fromUtf8("radioButton_cam1"));

        formLayout->setWidget(1, QFormLayout::LabelRole, radioButton_cam1);

        radioButton_cam5 = new QRadioButton(groupBox_CamSelect);
        radioButton_cam5->setObjectName(QString::fromUtf8("radioButton_cam5"));

        formLayout->setWidget(1, QFormLayout::FieldRole, radioButton_cam5);

        radioButton_cam2 = new QRadioButton(groupBox_CamSelect);
        radioButton_cam2->setObjectName(QString::fromUtf8("radioButton_cam2"));

        formLayout->setWidget(2, QFormLayout::LabelRole, radioButton_cam2);

        radioButton_cam6 = new QRadioButton(groupBox_CamSelect);
        radioButton_cam6->setObjectName(QString::fromUtf8("radioButton_cam6"));

        formLayout->setWidget(2, QFormLayout::FieldRole, radioButton_cam6);

        radioButton_cam3 = new QRadioButton(groupBox_CamSelect);
        radioButton_cam3->setObjectName(QString::fromUtf8("radioButton_cam3"));

        formLayout->setWidget(3, QFormLayout::LabelRole, radioButton_cam3);

        radioButton_cam7 = new QRadioButton(groupBox_CamSelect);
        radioButton_cam7->setObjectName(QString::fromUtf8("radioButton_cam7"));

        formLayout->setWidget(3, QFormLayout::FieldRole, radioButton_cam7);


        verticalLayout_2->addWidget(groupBox_CamSelect);

        line_2 = new QFrame(centralWidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line_2);

        groupBox_airParam = new QGroupBox(centralWidget);
        groupBox_airParam->setObjectName(QString::fromUtf8("groupBox_airParam"));
        verticalLayout_3 = new QVBoxLayout(groupBox_airParam);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalSlider_Rch = new QSlider(groupBox_airParam);
        horizontalSlider_Rch->setObjectName(QString::fromUtf8("horizontalSlider_Rch"));
        horizontalSlider_Rch->setMinimum(1);
        horizontalSlider_Rch->setValue(70);
        horizontalSlider_Rch->setOrientation(Qt::Horizontal);

        verticalLayout_3->addWidget(horizontalSlider_Rch);

        label_Red = new QLabel(groupBox_airParam);
        label_Red->setObjectName(QString::fromUtf8("label_Red"));
        label_Red->setLayoutDirection(Qt::LeftToRight);
        label_Red->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_Red);

        horizontalSlider_Gch = new QSlider(groupBox_airParam);
        horizontalSlider_Gch->setObjectName(QString::fromUtf8("horizontalSlider_Gch"));
        horizontalSlider_Gch->setMinimum(1);
        horizontalSlider_Gch->setValue(70);
        horizontalSlider_Gch->setOrientation(Qt::Horizontal);

        verticalLayout_3->addWidget(horizontalSlider_Gch);

        label_Green = new QLabel(groupBox_airParam);
        label_Green->setObjectName(QString::fromUtf8("label_Green"));
        label_Green->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_Green);

        horizontalSlider_Bch = new QSlider(groupBox_airParam);
        horizontalSlider_Bch->setObjectName(QString::fromUtf8("horizontalSlider_Bch"));
        horizontalSlider_Bch->setMinimum(1);
        horizontalSlider_Bch->setValue(70);
        horizontalSlider_Bch->setOrientation(Qt::Horizontal);

        verticalLayout_3->addWidget(horizontalSlider_Bch);

        label_Blue = new QLabel(groupBox_airParam);
        label_Blue->setObjectName(QString::fromUtf8("label_Blue"));
        label_Blue->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_Blue);


        verticalLayout_2->addWidget(groupBox_airParam);

        line = new QFrame(centralWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line);

        groupBox_dehaze = new QGroupBox(centralWidget);
        groupBox_dehaze->setObjectName(QString::fromUtf8("groupBox_dehaze"));
        verticalLayout_4 = new QVBoxLayout(groupBox_dehaze);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        radioButton_isDehaze = new QRadioButton(groupBox_dehaze);
        radioButton_isDehaze->setObjectName(QString::fromUtf8("radioButton_isDehaze"));

        verticalLayout_4->addWidget(radioButton_isDehaze);


        verticalLayout_2->addWidget(groupBox_dehaze);

        line_10 = new QFrame(centralWidget);
        line_10->setObjectName(QString::fromUtf8("line_10"));
        line_10->setFrameShape(QFrame::HLine);
        line_10->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line_10);

        groupBox_dedark = new QGroupBox(centralWidget);
        groupBox_dedark->setObjectName(QString::fromUtf8("groupBox_dedark"));
        verticalLayout_7 = new QVBoxLayout(groupBox_dedark);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        radioButton_isEnhance = new QRadioButton(groupBox_dedark);
        radioButton_isEnhance->setObjectName(QString::fromUtf8("radioButton_isEnhance"));

        verticalLayout_7->addWidget(radioButton_isEnhance);


        verticalLayout_2->addWidget(groupBox_dedark);

        line_9 = new QFrame(centralWidget);
        line_9->setObjectName(QString::fromUtf8("line_9"));
        line_9->setFrameShape(QFrame::HLine);
        line_9->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line_9);

        radioButton_interframe = new QRadioButton(centralWidget);
        radioButton_interframe->setObjectName(QString::fromUtf8("radioButton_interframe"));
        radioButton_interframe->setMaximumSize(QSize(1, 16777215));

        verticalLayout_2->addWidget(radioButton_interframe);

        radioButton_colorCorrection = new QRadioButton(centralWidget);
        radioButton_colorCorrection->setObjectName(QString::fromUtf8("radioButton_colorCorrection"));

        verticalLayout_2->addWidget(radioButton_colorCorrection);

        line_3 = new QFrame(centralWidget);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line_3);

        line_5 = new QFrame(centralWidget);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line_5);

        radioButton_isTwinView = new QRadioButton(centralWidget);
        radioButton_isTwinView->setObjectName(QString::fromUtf8("radioButton_isTwinView"));

        verticalLayout_2->addWidget(radioButton_isTwinView);

        line_6 = new QFrame(centralWidget);
        line_6->setObjectName(QString::fromUtf8("line_6"));
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line_6);

        label_show_enhanece_val = new QLabel(centralWidget);
        label_show_enhanece_val->setObjectName(QString::fromUtf8("label_show_enhanece_val"));
        label_show_enhanece_val->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_show_enhanece_val);

        horizontalSlider_enhanece_kval = new QSlider(centralWidget);
        horizontalSlider_enhanece_kval->setObjectName(QString::fromUtf8("horizontalSlider_enhanece_kval"));
        horizontalSlider_enhanece_kval->setMinimum(3);
        horizontalSlider_enhanece_kval->setMaximum(10);
        horizontalSlider_enhanece_kval->setPageStep(1);
        horizontalSlider_enhanece_kval->setValue(3);
        horizontalSlider_enhanece_kval->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(horizontalSlider_enhanece_kval);

        label_enhanece_val = new QLabel(centralWidget);
        label_enhanece_val->setObjectName(QString::fromUtf8("label_enhanece_val"));
        label_enhanece_val->setTextFormat(Qt::PlainText);
        label_enhanece_val->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_enhanece_val);

        label_show_zoom_val = new QLabel(centralWidget);
        label_show_zoom_val->setObjectName(QString::fromUtf8("label_show_zoom_val"));
        label_show_zoom_val->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_show_zoom_val);

        horizontalSlider_zoom_val = new QSlider(centralWidget);
        horizontalSlider_zoom_val->setObjectName(QString::fromUtf8("horizontalSlider_zoom_val"));
        horizontalSlider_zoom_val->setMinimum(0);
        horizontalSlider_zoom_val->setMaximum(80);
        horizontalSlider_zoom_val->setPageStep(1);
        horizontalSlider_zoom_val->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(horizontalSlider_zoom_val);

        label_zoom_val = new QLabel(centralWidget);
        label_zoom_val->setObjectName(QString::fromUtf8("label_zoom_val"));
        label_zoom_val->setTextFormat(Qt::PlainText);
        label_zoom_val->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_zoom_val);

        spinBox_zoom_val = new QSpinBox(centralWidget);
        spinBox_zoom_val->setObjectName(QString::fromUtf8("spinBox_zoom_val"));
        spinBox_zoom_val->setMaximum(80);

        verticalLayout_2->addWidget(spinBox_zoom_val);

        pushButton_updateparam = new QPushButton(centralWidget);
        pushButton_updateparam->setObjectName(QString::fromUtf8("pushButton_updateparam"));

        verticalLayout_2->addWidget(pushButton_updateparam);

        pushButton_CC = new QPushButton(centralWidget);
        pushButton_CC->setObjectName(QString::fromUtf8("pushButton_CC"));

        verticalLayout_2->addWidget(pushButton_CC);

        scrollArea = new QScrollArea(centralWidget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 351, 606));
        Cam4box = new QGroupBox(scrollAreaWidgetContents_2);
        Cam4box->setObjectName(QString::fromUtf8("Cam4box"));
        Cam4box->setGeometry(QRect(0, 0, 301, 160));
        Cam4box->setAlignment(Qt::AlignCenter);
        horizontalSlider_cam4_X = new QSlider(Cam4box);
        horizontalSlider_cam4_X->setObjectName(QString::fromUtf8("horizontalSlider_cam4_X"));
        horizontalSlider_cam4_X->setGeometry(QRect(90, 40, 160, 20));
        horizontalSlider_cam4_X->setMaximum(150);
        horizontalSlider_cam4_X->setPageStep(1);
        horizontalSlider_cam4_X->setValue(0);
        horizontalSlider_cam4_X->setOrientation(Qt::Horizontal);
        horizontalSlider_cam4_R = new QSlider(Cam4box);
        horizontalSlider_cam4_R->setObjectName(QString::fromUtf8("horizontalSlider_cam4_R"));
        horizontalSlider_cam4_R->setGeometry(QRect(90, 100, 160, 20));
        horizontalSlider_cam4_R->setMinimum(-45);
        horizontalSlider_cam4_R->setMaximum(45);
        horizontalSlider_cam4_R->setPageStep(1);
        horizontalSlider_cam4_R->setOrientation(Qt::Horizontal);
        horizontalSlider_cam4_Y = new QSlider(Cam4box);
        horizontalSlider_cam4_Y->setObjectName(QString::fromUtf8("horizontalSlider_cam4_Y"));
        horizontalSlider_cam4_Y->setGeometry(QRect(90, 70, 160, 20));
        horizontalSlider_cam4_Y->setMaximum(150);
        horizontalSlider_cam4_Y->setPageStep(1);
        horizontalSlider_cam4_Y->setOrientation(Qt::Horizontal);
        label = new QLabel(Cam4box);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 40, 89, 23));
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(Cam4box);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(0, 70, 89, 23));
        label_2->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(Cam4box);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(0, 100, 89, 23));
        label_3->setAlignment(Qt::AlignCenter);
        label_cam4_X = new QLabel(Cam4box);
        label_cam4_X->setObjectName(QString::fromUtf8("label_cam4_X"));
        label_cam4_X->setGeometry(QRect(250, 40, 60, 23));
        label_cam4_X->setTextFormat(Qt::PlainText);
        label_cam4_X->setAlignment(Qt::AlignCenter);
        label_cam4_Y = new QLabel(Cam4box);
        label_cam4_Y->setObjectName(QString::fromUtf8("label_cam4_Y"));
        label_cam4_Y->setGeometry(QRect(250, 70, 60, 23));
        label_cam4_Y->setTextFormat(Qt::PlainText);
        label_cam4_Y->setAlignment(Qt::AlignCenter);
        label_cam4_R = new QLabel(Cam4box);
        label_cam4_R->setObjectName(QString::fromUtf8("label_cam4_R"));
        label_cam4_R->setGeometry(QRect(250, 100, 60, 23));
        label_cam4_R->setTextFormat(Qt::PlainText);
        label_cam4_R->setAlignment(Qt::AlignCenter);
        horizontalSlider_cam4_Z = new QSlider(Cam4box);
        horizontalSlider_cam4_Z->setObjectName(QString::fromUtf8("horizontalSlider_cam4_Z"));
        horizontalSlider_cam4_Z->setGeometry(QRect(90, 130, 160, 20));
        horizontalSlider_cam4_Z->setMaximum(10);
        horizontalSlider_cam4_Z->setPageStep(1);
        horizontalSlider_cam4_Z->setOrientation(Qt::Horizontal);
        label_cam4_Z = new QLabel(Cam4box);
        label_cam4_Z->setObjectName(QString::fromUtf8("label_cam4_Z"));
        label_cam4_Z->setGeometry(QRect(250, 130, 60, 23));
        label_cam4_Z->setTextFormat(Qt::PlainText);
        label_cam4_Z->setAlignment(Qt::AlignCenter);
        label_7 = new QLabel(Cam4box);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(0, 130, 89, 23));
        label_7->setAlignment(Qt::AlignCenter);
        Cam2box = new QGroupBox(scrollAreaWidgetContents_2);
        Cam2box->setObjectName(QString::fromUtf8("Cam2box"));
        Cam2box->setGeometry(QRect(0, 340, 301, 160));
        Cam2box->setAlignment(Qt::AlignCenter);
        horizontalSlider_cam2_X = new QSlider(Cam2box);
        horizontalSlider_cam2_X->setObjectName(QString::fromUtf8("horizontalSlider_cam2_X"));
        horizontalSlider_cam2_X->setGeometry(QRect(90, 40, 160, 20));
        horizontalSlider_cam2_X->setMaximum(150);
        horizontalSlider_cam2_X->setPageStep(1);
        horizontalSlider_cam2_X->setValue(0);
        horizontalSlider_cam2_X->setOrientation(Qt::Horizontal);
        horizontalSlider_cam2_R = new QSlider(Cam2box);
        horizontalSlider_cam2_R->setObjectName(QString::fromUtf8("horizontalSlider_cam2_R"));
        horizontalSlider_cam2_R->setGeometry(QRect(90, 100, 160, 20));
        horizontalSlider_cam2_R->setMinimum(-45);
        horizontalSlider_cam2_R->setMaximum(45);
        horizontalSlider_cam2_R->setPageStep(1);
        horizontalSlider_cam2_R->setOrientation(Qt::Horizontal);
        horizontalSlider_cam2_Y = new QSlider(Cam2box);
        horizontalSlider_cam2_Y->setObjectName(QString::fromUtf8("horizontalSlider_cam2_Y"));
        horizontalSlider_cam2_Y->setGeometry(QRect(90, 70, 160, 20));
        horizontalSlider_cam2_Y->setMaximum(150);
        horizontalSlider_cam2_Y->setPageStep(1);
        horizontalSlider_cam2_Y->setOrientation(Qt::Horizontal);
        label_16 = new QLabel(Cam2box);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(0, 40, 89, 23));
        label_16->setAlignment(Qt::AlignCenter);
        label_17 = new QLabel(Cam2box);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(0, 70, 89, 23));
        label_17->setAlignment(Qt::AlignCenter);
        label_18 = new QLabel(Cam2box);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(0, 100, 89, 23));
        label_18->setAlignment(Qt::AlignCenter);
        label_cam2_X = new QLabel(Cam2box);
        label_cam2_X->setObjectName(QString::fromUtf8("label_cam2_X"));
        label_cam2_X->setGeometry(QRect(250, 40, 60, 23));
        label_cam2_X->setTextFormat(Qt::PlainText);
        label_cam2_X->setAlignment(Qt::AlignCenter);
        label_cam2_Y = new QLabel(Cam2box);
        label_cam2_Y->setObjectName(QString::fromUtf8("label_cam2_Y"));
        label_cam2_Y->setGeometry(QRect(250, 70, 60, 23));
        label_cam2_Y->setTextFormat(Qt::PlainText);
        label_cam2_Y->setAlignment(Qt::AlignCenter);
        label_cam2_R = new QLabel(Cam2box);
        label_cam2_R->setObjectName(QString::fromUtf8("label_cam2_R"));
        label_cam2_R->setGeometry(QRect(250, 100, 60, 23));
        label_cam2_R->setTextFormat(Qt::PlainText);
        label_cam2_R->setAlignment(Qt::AlignCenter);
        horizontalSlider_cam2_Z = new QSlider(Cam2box);
        horizontalSlider_cam2_Z->setObjectName(QString::fromUtf8("horizontalSlider_cam2_Z"));
        horizontalSlider_cam2_Z->setGeometry(QRect(90, 130, 160, 20));
        horizontalSlider_cam2_Z->setMaximum(10);
        horizontalSlider_cam2_Z->setPageStep(1);
        horizontalSlider_cam2_Z->setOrientation(Qt::Horizontal);
        label_cam2_Z = new QLabel(Cam2box);
        label_cam2_Z->setObjectName(QString::fromUtf8("label_cam2_Z"));
        label_cam2_Z->setGeometry(QRect(250, 130, 60, 23));
        label_cam2_Z->setTextFormat(Qt::PlainText);
        label_cam2_Z->setAlignment(Qt::AlignCenter);
        label_9 = new QLabel(Cam2box);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(0, 130, 89, 23));
        label_9->setAlignment(Qt::AlignCenter);
        Cam1box = new QGroupBox(scrollAreaWidgetContents_2);
        Cam1box->setObjectName(QString::fromUtf8("Cam1box"));
        Cam1box->setGeometry(QRect(0, 170, 301, 160));
        Cam1box->setAlignment(Qt::AlignCenter);
        horizontalSlider_cam1_X = new QSlider(Cam1box);
        horizontalSlider_cam1_X->setObjectName(QString::fromUtf8("horizontalSlider_cam1_X"));
        horizontalSlider_cam1_X->setGeometry(QRect(90, 40, 160, 20));
        horizontalSlider_cam1_X->setMaximum(150);
        horizontalSlider_cam1_X->setPageStep(1);
        horizontalSlider_cam1_X->setValue(0);
        horizontalSlider_cam1_X->setOrientation(Qt::Horizontal);
        horizontalSlider_cam1_R = new QSlider(Cam1box);
        horizontalSlider_cam1_R->setObjectName(QString::fromUtf8("horizontalSlider_cam1_R"));
        horizontalSlider_cam1_R->setGeometry(QRect(90, 100, 160, 20));
        horizontalSlider_cam1_R->setMinimum(-45);
        horizontalSlider_cam1_R->setMaximum(45);
        horizontalSlider_cam1_R->setPageStep(1);
        horizontalSlider_cam1_R->setOrientation(Qt::Horizontal);
        horizontalSlider_cam1_Y = new QSlider(Cam1box);
        horizontalSlider_cam1_Y->setObjectName(QString::fromUtf8("horizontalSlider_cam1_Y"));
        horizontalSlider_cam1_Y->setGeometry(QRect(90, 70, 160, 20));
        horizontalSlider_cam1_Y->setMaximum(150);
        horizontalSlider_cam1_Y->setPageStep(1);
        horizontalSlider_cam1_Y->setOrientation(Qt::Horizontal);
        label_13 = new QLabel(Cam1box);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(0, 40, 89, 23));
        label_13->setAlignment(Qt::AlignCenter);
        label_14 = new QLabel(Cam1box);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(0, 70, 89, 23));
        label_14->setAlignment(Qt::AlignCenter);
        label_15 = new QLabel(Cam1box);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(0, 100, 89, 23));
        label_15->setAlignment(Qt::AlignCenter);
        label_cam1_X = new QLabel(Cam1box);
        label_cam1_X->setObjectName(QString::fromUtf8("label_cam1_X"));
        label_cam1_X->setGeometry(QRect(250, 40, 60, 23));
        label_cam1_X->setTextFormat(Qt::PlainText);
        label_cam1_X->setAlignment(Qt::AlignCenter);
        label_cam1_Y = new QLabel(Cam1box);
        label_cam1_Y->setObjectName(QString::fromUtf8("label_cam1_Y"));
        label_cam1_Y->setGeometry(QRect(250, 70, 60, 23));
        label_cam1_Y->setTextFormat(Qt::PlainText);
        label_cam1_Y->setAlignment(Qt::AlignCenter);
        label_cam1_R = new QLabel(Cam1box);
        label_cam1_R->setObjectName(QString::fromUtf8("label_cam1_R"));
        label_cam1_R->setGeometry(QRect(250, 100, 60, 23));
        label_cam1_R->setTextFormat(Qt::PlainText);
        label_cam1_R->setAlignment(Qt::AlignCenter);
        horizontalSlider_cam1_Z = new QSlider(Cam1box);
        horizontalSlider_cam1_Z->setObjectName(QString::fromUtf8("horizontalSlider_cam1_Z"));
        horizontalSlider_cam1_Z->setGeometry(QRect(90, 130, 160, 20));
        horizontalSlider_cam1_Z->setMaximum(10);
        horizontalSlider_cam1_Z->setPageStep(1);
        horizontalSlider_cam1_Z->setOrientation(Qt::Horizontal);
        label_cam1_Z = new QLabel(Cam1box);
        label_cam1_Z->setObjectName(QString::fromUtf8("label_cam1_Z"));
        label_cam1_Z->setGeometry(QRect(250, 130, 60, 23));
        label_cam1_Z->setTextFormat(Qt::PlainText);
        label_cam1_Z->setAlignment(Qt::AlignCenter);
        label_8 = new QLabel(Cam1box);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(0, 130, 89, 23));
        label_8->setAlignment(Qt::AlignCenter);
        horizontalSlider_camGlobal_R = new QSlider(scrollAreaWidgetContents_2);
        horizontalSlider_camGlobal_R->setObjectName(QString::fromUtf8("horizontalSlider_camGlobal_R"));
        horizontalSlider_camGlobal_R->setGeometry(QRect(110, 510, 160, 20));
        horizontalSlider_camGlobal_R->setMinimum(-45);
        horizontalSlider_camGlobal_R->setMaximum(45);
        horizontalSlider_camGlobal_R->setPageStep(1);
        horizontalSlider_camGlobal_R->setOrientation(Qt::Horizontal);
        label_11 = new QLabel(scrollAreaWidgetContents_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(0, 510, 121, 23));
        label_camGlobal_R = new QLabel(scrollAreaWidgetContents_2);
        label_camGlobal_R->setObjectName(QString::fromUtf8("label_camGlobal_R"));
        label_camGlobal_R->setGeometry(QRect(270, 510, 60, 23));
        label_camGlobal_R->setTextFormat(Qt::PlainText);
        label_camGlobal_R->setAlignment(Qt::AlignCenter);
        label_25 = new QLabel(scrollAreaWidgetContents_2);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setGeometry(QRect(0, 540, 121, 23));
        horizontalSlider_camGlobal_Z = new QSlider(scrollAreaWidgetContents_2);
        horizontalSlider_camGlobal_Z->setObjectName(QString::fromUtf8("horizontalSlider_camGlobal_Z"));
        horizontalSlider_camGlobal_Z->setGeometry(QRect(110, 540, 160, 20));
        horizontalSlider_camGlobal_Z->setMaximum(10);
        horizontalSlider_camGlobal_Z->setPageStep(1);
        horizontalSlider_camGlobal_Z->setOrientation(Qt::Horizontal);
        label_camGlobal_Z = new QLabel(scrollAreaWidgetContents_2);
        label_camGlobal_Z->setObjectName(QString::fromUtf8("label_camGlobal_Z"));
        label_camGlobal_Z->setGeometry(QRect(270, 540, 60, 23));
        label_camGlobal_Z->setTextFormat(Qt::PlainText);
        label_camGlobal_Z->setAlignment(Qt::AlignCenter);
        scrollArea->setWidget(scrollAreaWidgetContents_2);

        verticalLayout_2->addWidget(scrollArea);

        verticalSpacer = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Minimum);

        verticalLayout_2->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout_2);

        horizontalLayout->setStretch(0, 10);

        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 4240, 39));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "GIGAPIXEL_STREAMING", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("MainWindow", "SubView1", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "SubView2", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QCoreApplication::translate("MainWindow", "MainView", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "Stitch", nullptr));
        pushButton_start->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        groupBox_camswitch->setTitle(QCoreApplication::translate("MainWindow", "Source", nullptr));
        radioButton_isSpincam->setText(QCoreApplication::translate("MainWindow", "SpinCam", nullptr));
        radioButton_isWebCam->setText(QCoreApplication::translate("MainWindow", "WebCam", nullptr));
        groupBox_CamSelect->setTitle(QCoreApplication::translate("MainWindow", "CamSelect", nullptr));
        radioButton_cam0->setText(QCoreApplication::translate("MainWindow", "Cam1", nullptr));
        radioButton_cam4->setText(QCoreApplication::translate("MainWindow", "Cam5", nullptr));
        radioButton_cam1->setText(QCoreApplication::translate("MainWindow", "Cam2", nullptr));
        radioButton_cam5->setText(QCoreApplication::translate("MainWindow", "Cam6", nullptr));
        radioButton_cam2->setText(QCoreApplication::translate("MainWindow", "Cam3", nullptr));
        radioButton_cam6->setText(QCoreApplication::translate("MainWindow", "Cam7", nullptr));
        radioButton_cam3->setText(QCoreApplication::translate("MainWindow", "Cam4", nullptr));
        radioButton_cam7->setText(QCoreApplication::translate("MainWindow", "Cam8", nullptr));
        groupBox_airParam->setTitle(QCoreApplication::translate("MainWindow", "AirChannel", nullptr));
        label_Red->setText(QCoreApplication::translate("MainWindow", "0.7", nullptr));
        label_Green->setText(QCoreApplication::translate("MainWindow", "0.7", nullptr));
        label_Blue->setText(QCoreApplication::translate("MainWindow", "0.7", nullptr));
        groupBox_dehaze->setTitle(QCoreApplication::translate("MainWindow", "Dehaze", nullptr));
        radioButton_isDehaze->setText(QCoreApplication::translate("MainWindow", "Enable", nullptr));
        groupBox_dedark->setTitle(QCoreApplication::translate("MainWindow", "LowLightEnhance", nullptr));
        radioButton_isEnhance->setText(QCoreApplication::translate("MainWindow", "Enable", nullptr));
        radioButton_interframe->setText(QCoreApplication::translate("MainWindow", "InterFrame", nullptr));
        radioButton_colorCorrection->setText(QCoreApplication::translate("MainWindow", "ColorCorrection", nullptr));
        radioButton_isTwinView->setText(QCoreApplication::translate("MainWindow", "isTwinView", nullptr));
        label_show_enhanece_val->setText(QCoreApplication::translate("MainWindow", "LowLightParam", nullptr));
        label_enhanece_val->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        label_show_zoom_val->setText(QCoreApplication::translate("MainWindow", "Zoom Param", nullptr));
        label_zoom_val->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        pushButton_updateparam->setText(QCoreApplication::translate("MainWindow", "UpdateParam", nullptr));
        pushButton_CC->setText(QCoreApplication::translate("MainWindow", "ColorCorrection", nullptr));
        Cam4box->setTitle(QCoreApplication::translate("MainWindow", "Cam4 adjustment tools", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Rotate", nullptr));
        label_cam4_X->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_cam4_Y->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_cam4_R->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_cam4_Z->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Zoom", nullptr));
        Cam2box->setTitle(QCoreApplication::translate("MainWindow", "Cam2 adjustment tools", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "Rotate", nullptr));
        label_cam2_X->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_cam2_Y->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_cam2_R->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_cam2_Z->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Zoom", nullptr));
        Cam1box->setTitle(QCoreApplication::translate("MainWindow", "Cam1 adjustment tools", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "Rotate", nullptr));
        label_cam1_X->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_cam1_Y->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_cam1_R->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_cam1_Z->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Zoom", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Global Rot", nullptr));
        label_camGlobal_R->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_25->setText(QCoreApplication::translate("MainWindow", "GlobalZoom", nullptr));
        label_camGlobal_Z->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_COPY_H
