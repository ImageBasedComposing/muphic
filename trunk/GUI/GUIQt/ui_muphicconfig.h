/********************************************************************************
** Form generated from reading UI file 'muphicconfig.ui'
**
** Created: Tue May 15 17:14:59 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MUPHICCONFIG_H
#define UI_MUPHICCONFIG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QFormLayout>
#include <QtGui/QGraphicsView>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLCDNumber>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QScrollArea>
#include <QtGui/QSlider>
#include <QtGui/QSpacerItem>
#include <QtGui/QTabWidget>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "polygonwidget.h"
#include "seekbar.h"
#include "volumebar.h"

QT_BEGIN_NAMESPACE

class Ui_MuphicConfig
{
public:
    QWidget *tab;
    QGridLayout *gridLayout_11;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_InputPic;
    QLineEdit *lineEdit_InputPic;
    QToolButton *toolButton_InputPic;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_OutputMidi;
    QLineEdit *lineEdit_OutputMidi;
    QToolButton *toolButton_OutputMidi;
    QHBoxLayout *horizontalLayout_5;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_4;
    QGraphicsView *graphicsView_Pic;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_10;
    QScrollArea *scrollArea;
    PolygonWidget *polyWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_14;
    QPushButton *pushButton_Analyze;
    QPushButton *pushButton_Generate;
    QProgressBar *progressBar_Generate;
    QHBoxLayout *horizontalLayout_player;
    QPushButton *pushButton_Play;
    QPushButton *pushButton_pause;
    QPushButton *pushButton_Stop;
    SeekBar *seekSlider;
    VolumeBar *volumeSlider;
    QLCDNumber *timeLcd;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *verticalSpacer_2;
    QWidget *tab1;
    QGridLayout *gridLayout_12;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label;
    QComboBox *filterSelComboBox;
    QSpacerItem *horizontalSpacer;
    QLabel *label_4;
    QSlider *horizontalSlider_3;
    QLabel *noiseLabel;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_3;
    QSlider *horizontalSlider_6;
    QLabel *labelPolSimp;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_2;
    QSlider *horizontalSlider_2;
    QLabel *tLabel;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_ThresholdH;
    QSlider *horizontalSliderTH;
    QLabel *labelThresholdH;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_ThresholdS;
    QSlider *horizontalSliderTS;
    QLabel *labelThresholdS;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_ThresholdV;
    QSlider *horizontalSliderTV;
    QLabel *labelThresholdV;
    QHBoxLayout *horizontalLayout;
    QLabel *label_ColorLevels;
    QSlider *horizontalSlider_colorLevels;
    QLabel *labelColorLevels;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_analysisDepth;
    QSlider *horizontalSlider_AnalisisDepth;
    QLabel *labelAnalysisDepth;
    QWidget *tab2;
    QGridLayout *gridLayout_5;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_14;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_reconColors;
    QComboBox *comboBox_reconColors;
    QSpacerItem *horizontalSpacer_4;
    QGridLayout *gridLayout_13;
    QGroupBox *groupBox_v1;
    QFormLayout *formLayout_3;
    QGridLayout *gridLayout_9;
    QLabel *label_v1Composer;
    QComboBox *comboBox_v1Composer;
    QLabel *label_v1Instrument;
    QComboBox *comboBox_v1Instrument;
    QGroupBox *groupBox_v2;
    QFormLayout *formLayout_4;
    QGridLayout *gridLayout_8;
    QLabel *label_v2Composer;
    QComboBox *comboBox_v2Composer;
    QLabel *label_v2Instrument;
    QComboBox *comboBox_v2Instruments;
    QGroupBox *groupBox_v3;
    QFormLayout *formLayout_2;
    QGridLayout *gridLayout_6;
    QLabel *label_v3Composer;
    QComboBox *comboBox_v3Composer;
    QLabel *label_v3Instrument;
    QComboBox *comboBox_v3Instrument;
    QGroupBox *groupBox_v4;
    QFormLayout *formLayout;
    QGridLayout *gridLayout_7;
    QLabel *label_v4Composer;
    QComboBox *comboBox_v4Composer;
    QLabel *label_v4Instrument;
    QComboBox *comboBox_v4Instrument;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_composerMix;
    QComboBox *comboBox_composerMixer;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_tempo;
    QComboBox *comboBox_v3Composer_3;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QTabWidget *MuphicConfig)
    {
        if (MuphicConfig->objectName().isEmpty())
            MuphicConfig->setObjectName(QString::fromUtf8("MuphicConfig"));
        MuphicConfig->resize(589, 539);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MuphicConfig->sizePolicy().hasHeightForWidth());
        MuphicConfig->setSizePolicy(sizePolicy);
        MuphicConfig->setMinimumSize(QSize(589, 539));
        MuphicConfig->setMaximumSize(QSize(16777215, 16777215));
        MuphicConfig->setMovable(true);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        sizePolicy.setHeightForWidth(tab->sizePolicy().hasHeightForWidth());
        tab->setSizePolicy(sizePolicy);
        gridLayout_11 = new QGridLayout(tab);
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setSizeConstraint(QLayout::SetMaximumSize);
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_InputPic = new QLabel(tab);
        label_InputPic->setObjectName(QString::fromUtf8("label_InputPic"));

        horizontalLayout_4->addWidget(label_InputPic);

        lineEdit_InputPic = new QLineEdit(tab);
        lineEdit_InputPic->setObjectName(QString::fromUtf8("lineEdit_InputPic"));
        lineEdit_InputPic->setEnabled(true);
        lineEdit_InputPic->setReadOnly(true);

        horizontalLayout_4->addWidget(lineEdit_InputPic);

        toolButton_InputPic = new QToolButton(tab);
        toolButton_InputPic->setObjectName(QString::fromUtf8("toolButton_InputPic"));

        horizontalLayout_4->addWidget(toolButton_InputPic);


        gridLayout_2->addLayout(horizontalLayout_4, 0, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_OutputMidi = new QLabel(tab);
        label_OutputMidi->setObjectName(QString::fromUtf8("label_OutputMidi"));

        horizontalLayout_3->addWidget(label_OutputMidi);

        lineEdit_OutputMidi = new QLineEdit(tab);
        lineEdit_OutputMidi->setObjectName(QString::fromUtf8("lineEdit_OutputMidi"));

        horizontalLayout_3->addWidget(lineEdit_OutputMidi);

        toolButton_OutputMidi = new QToolButton(tab);
        toolButton_OutputMidi->setObjectName(QString::fromUtf8("toolButton_OutputMidi"));

        horizontalLayout_3->addWidget(toolButton_OutputMidi);


        gridLayout_2->addLayout(horizontalLayout_3, 1, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        groupBox_4 = new QGroupBox(tab);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        sizePolicy.setHeightForWidth(groupBox_4->sizePolicy().hasHeightForWidth());
        groupBox_4->setSizePolicy(sizePolicy);
        gridLayout_4 = new QGridLayout(groupBox_4);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        graphicsView_Pic = new QGraphicsView(groupBox_4);
        graphicsView_Pic->setObjectName(QString::fromUtf8("graphicsView_Pic"));
        sizePolicy.setHeightForWidth(graphicsView_Pic->sizePolicy().hasHeightForWidth());
        graphicsView_Pic->setSizePolicy(sizePolicy);
        graphicsView_Pic->setMinimumSize(QSize(256, 194));
        graphicsView_Pic->viewport()->setProperty("cursor", QVariant(QCursor(Qt::CrossCursor)));
        graphicsView_Pic->setAutoFillBackground(true);
        graphicsView_Pic->setFrameShape(QFrame::StyledPanel);

        gridLayout_4->addWidget(graphicsView_Pic, 0, 0, 1, 1);


        horizontalLayout_5->addWidget(groupBox_4);

        groupBox = new QGroupBox(tab);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        groupBox->setMinimumSize(QSize(256, 194));
        gridLayout_10 = new QGridLayout(groupBox);
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        scrollArea = new QScrollArea(groupBox);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        polyWidget = new PolygonWidget();
        polyWidget->setObjectName(QString::fromUtf8("polyWidget"));
        polyWidget->setGeometry(QRect(0, 0, 228, 286));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(polyWidget->sizePolicy().hasHeightForWidth());
        polyWidget->setSizePolicy(sizePolicy1);
        polyWidget->setMinimumSize(QSize(216, 217));
        scrollArea->setWidget(polyWidget);

        gridLayout_10->addWidget(scrollArea, 0, 0, 1, 1);


        horizontalLayout_5->addWidget(groupBox);


        gridLayout_2->addLayout(horizontalLayout_5, 2, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 1, 1, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        pushButton_Analyze = new QPushButton(tab);
        pushButton_Analyze->setObjectName(QString::fromUtf8("pushButton_Analyze"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pushButton_Analyze->sizePolicy().hasHeightForWidth());
        pushButton_Analyze->setSizePolicy(sizePolicy2);
        pushButton_Analyze->setMaximumSize(QSize(150, 16777215));

        horizontalLayout_14->addWidget(pushButton_Analyze);

        pushButton_Generate = new QPushButton(tab);
        pushButton_Generate->setObjectName(QString::fromUtf8("pushButton_Generate"));
        sizePolicy2.setHeightForWidth(pushButton_Generate->sizePolicy().hasHeightForWidth());
        pushButton_Generate->setSizePolicy(sizePolicy2);
        pushButton_Generate->setMaximumSize(QSize(150, 16777215));

        horizontalLayout_14->addWidget(pushButton_Generate);

        progressBar_Generate = new QProgressBar(tab);
        progressBar_Generate->setObjectName(QString::fromUtf8("progressBar_Generate"));
        progressBar_Generate->setValue(0);

        horizontalLayout_14->addWidget(progressBar_Generate);


        verticalLayout->addLayout(horizontalLayout_14);

        horizontalLayout_player = new QHBoxLayout();
        horizontalLayout_player->setObjectName(QString::fromUtf8("horizontalLayout_player"));
        pushButton_Play = new QPushButton(tab);
        pushButton_Play->setObjectName(QString::fromUtf8("pushButton_Play"));
        QIcon icon;
        icon.addFile(QString::fromUtf8("play.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_Play->setIcon(icon);

        horizontalLayout_player->addWidget(pushButton_Play);

        pushButton_pause = new QPushButton(tab);
        pushButton_pause->setObjectName(QString::fromUtf8("pushButton_pause"));

        horizontalLayout_player->addWidget(pushButton_pause);

        pushButton_Stop = new QPushButton(tab);
        pushButton_Stop->setObjectName(QString::fromUtf8("pushButton_Stop"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("stop.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_Stop->setIcon(icon1);

        horizontalLayout_player->addWidget(pushButton_Stop);

        seekSlider = new SeekBar(tab);
        seekSlider->setObjectName(QString::fromUtf8("seekSlider"));

        horizontalLayout_player->addWidget(seekSlider);

        volumeSlider = new VolumeBar(tab);
        volumeSlider->setObjectName(QString::fromUtf8("volumeSlider"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(255);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(volumeSlider->sizePolicy().hasHeightForWidth());
        volumeSlider->setSizePolicy(sizePolicy3);

        horizontalLayout_player->addWidget(volumeSlider);

        timeLcd = new QLCDNumber(tab);
        timeLcd->setObjectName(QString::fromUtf8("timeLcd"));

        horizontalLayout_player->addWidget(timeLcd);


        verticalLayout->addLayout(horizontalLayout_player);


        gridLayout_3->addLayout(verticalLayout, 2, 1, 1, 2);

        horizontalSpacer_5 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_5, 1, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_3->addItem(verticalSpacer_2, 0, 1, 1, 1);


        gridLayout_11->addLayout(gridLayout_3, 0, 0, 1, 1);

        MuphicConfig->addTab(tab, QString());
        tab1 = new QWidget();
        tab1->setObjectName(QString::fromUtf8("tab1"));
        gridLayout_12 = new QGridLayout(tab1);
        gridLayout_12->setObjectName(QString::fromUtf8("gridLayout_12"));
        groupBox_2 = new QGroupBox(tab1);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(1);
        sizePolicy4.setVerticalStretch(1);
        sizePolicy4.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy4);
        groupBox_2->setMinimumSize(QSize(441, 240));
        groupBox_2->setMaximumSize(QSize(16777215, 16777215));
        groupBox_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        gridLayout = new QGridLayout(groupBox_2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy5(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy5);

        horizontalLayout_6->addWidget(label);

        filterSelComboBox = new QComboBox(groupBox_2);
        filterSelComboBox->setObjectName(QString::fromUtf8("filterSelComboBox"));

        horizontalLayout_6->addWidget(filterSelComboBox);

        horizontalSpacer = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer);

        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_6->addWidget(label_4);

        horizontalSlider_3 = new QSlider(groupBox_2);
        horizontalSlider_3->setObjectName(QString::fromUtf8("horizontalSlider_3"));
        horizontalSlider_3->setMinimumSize(QSize(103, 0));
        horizontalSlider_3->setMaximum(100);
        horizontalSlider_3->setSingleStep(1);
        horizontalSlider_3->setPageStep(10);
        horizontalSlider_3->setValue(0);
        horizontalSlider_3->setOrientation(Qt::Horizontal);
        horizontalSlider_3->setTickPosition(QSlider::TicksBelow);
        horizontalSlider_3->setTickInterval(10);

        horizontalLayout_6->addWidget(horizontalSlider_3);

        noiseLabel = new QLabel(groupBox_2);
        noiseLabel->setObjectName(QString::fromUtf8("noiseLabel"));
        QSizePolicy sizePolicy6(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(noiseLabel->sizePolicy().hasHeightForWidth());
        noiseLabel->setSizePolicy(sizePolicy6);
        noiseLabel->setMinimumSize(QSize(30, 0));
        noiseLabel->setMaximumSize(QSize(30, 16777215));
        noiseLabel->setFrameShape(QFrame::StyledPanel);
        noiseLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_6->addWidget(noiseLabel);


        gridLayout->addLayout(horizontalLayout_6, 0, 0, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy5.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy5);

        horizontalLayout_7->addWidget(label_3);

        horizontalSlider_6 = new QSlider(groupBox_2);
        horizontalSlider_6->setObjectName(QString::fromUtf8("horizontalSlider_6"));
        horizontalSlider_6->setMinimum(1);
        horizontalSlider_6->setMaximum(45);
        horizontalSlider_6->setValue(2);
        horizontalSlider_6->setOrientation(Qt::Horizontal);
        horizontalSlider_6->setTickPosition(QSlider::TicksBelow);
        horizontalSlider_6->setTickInterval(1);

        horizontalLayout_7->addWidget(horizontalSlider_6);

        labelPolSimp = new QLabel(groupBox_2);
        labelPolSimp->setObjectName(QString::fromUtf8("labelPolSimp"));
        sizePolicy6.setHeightForWidth(labelPolSimp->sizePolicy().hasHeightForWidth());
        labelPolSimp->setSizePolicy(sizePolicy6);
        labelPolSimp->setMinimumSize(QSize(30, 0));
        labelPolSimp->setMaximumSize(QSize(30, 16777215));
        labelPolSimp->setFrameShape(QFrame::StyledPanel);
        labelPolSimp->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_7->addWidget(labelPolSimp);


        gridLayout->addLayout(horizontalLayout_7, 2, 0, 1, 1);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_8->addWidget(label_2);

        horizontalSlider_2 = new QSlider(groupBox_2);
        horizontalSlider_2->setObjectName(QString::fromUtf8("horizontalSlider_2"));
        horizontalSlider_2->setEnabled(true);
        horizontalSlider_2->setMaximum(200);
        horizontalSlider_2->setValue(50);
        horizontalSlider_2->setOrientation(Qt::Horizontal);
        horizontalSlider_2->setTickPosition(QSlider::TicksBelow);
        horizontalSlider_2->setTickInterval(10);

        horizontalLayout_8->addWidget(horizontalSlider_2);

        tLabel = new QLabel(groupBox_2);
        tLabel->setObjectName(QString::fromUtf8("tLabel"));
        tLabel->setEnabled(true);
        sizePolicy6.setHeightForWidth(tLabel->sizePolicy().hasHeightForWidth());
        tLabel->setSizePolicy(sizePolicy6);
        tLabel->setMinimumSize(QSize(30, 0));
        tLabel->setMaximumSize(QSize(30, 16777215));
        tLabel->setFrameShape(QFrame::StyledPanel);
        tLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_8->addWidget(tLabel);


        gridLayout->addLayout(horizontalLayout_8, 3, 0, 1, 1);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_ThresholdH = new QLabel(groupBox_2);
        label_ThresholdH->setObjectName(QString::fromUtf8("label_ThresholdH"));

        horizontalLayout_9->addWidget(label_ThresholdH);

        horizontalSliderTH = new QSlider(groupBox_2);
        horizontalSliderTH->setObjectName(QString::fromUtf8("horizontalSliderTH"));
        horizontalSliderTH->setEnabled(true);
        horizontalSliderTH->setMaximum(200);
        horizontalSliderTH->setValue(35);
        horizontalSliderTH->setOrientation(Qt::Horizontal);
        horizontalSliderTH->setTickPosition(QSlider::TicksBelow);
        horizontalSliderTH->setTickInterval(10);

        horizontalLayout_9->addWidget(horizontalSliderTH);

        labelThresholdH = new QLabel(groupBox_2);
        labelThresholdH->setObjectName(QString::fromUtf8("labelThresholdH"));
        sizePolicy6.setHeightForWidth(labelThresholdH->sizePolicy().hasHeightForWidth());
        labelThresholdH->setSizePolicy(sizePolicy6);
        labelThresholdH->setMinimumSize(QSize(30, 0));
        labelThresholdH->setFrameShape(QFrame::StyledPanel);
        labelThresholdH->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_9->addWidget(labelThresholdH);


        gridLayout->addLayout(horizontalLayout_9, 4, 0, 1, 1);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_ThresholdS = new QLabel(groupBox_2);
        label_ThresholdS->setObjectName(QString::fromUtf8("label_ThresholdS"));

        horizontalLayout_10->addWidget(label_ThresholdS);

        horizontalSliderTS = new QSlider(groupBox_2);
        horizontalSliderTS->setObjectName(QString::fromUtf8("horizontalSliderTS"));
        horizontalSliderTS->setEnabled(true);
        horizontalSliderTS->setMaximum(200);
        horizontalSliderTS->setValue(20);
        horizontalSliderTS->setOrientation(Qt::Horizontal);
        horizontalSliderTS->setTickPosition(QSlider::TicksBelow);
        horizontalSliderTS->setTickInterval(10);

        horizontalLayout_10->addWidget(horizontalSliderTS);

        labelThresholdS = new QLabel(groupBox_2);
        labelThresholdS->setObjectName(QString::fromUtf8("labelThresholdS"));
        sizePolicy6.setHeightForWidth(labelThresholdS->sizePolicy().hasHeightForWidth());
        labelThresholdS->setSizePolicy(sizePolicy6);
        labelThresholdS->setMinimumSize(QSize(30, 0));
        labelThresholdS->setFrameShape(QFrame::StyledPanel);
        labelThresholdS->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_10->addWidget(labelThresholdS);


        gridLayout->addLayout(horizontalLayout_10, 5, 0, 1, 1);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        label_ThresholdV = new QLabel(groupBox_2);
        label_ThresholdV->setObjectName(QString::fromUtf8("label_ThresholdV"));

        horizontalLayout_11->addWidget(label_ThresholdV);

        horizontalSliderTV = new QSlider(groupBox_2);
        horizontalSliderTV->setObjectName(QString::fromUtf8("horizontalSliderTV"));
        horizontalSliderTV->setEnabled(true);
        horizontalSliderTV->setMaximum(200);
        horizontalSliderTV->setValue(50);
        horizontalSliderTV->setOrientation(Qt::Horizontal);
        horizontalSliderTV->setTickPosition(QSlider::TicksBelow);
        horizontalSliderTV->setTickInterval(10);

        horizontalLayout_11->addWidget(horizontalSliderTV);

        labelThresholdV = new QLabel(groupBox_2);
        labelThresholdV->setObjectName(QString::fromUtf8("labelThresholdV"));
        sizePolicy6.setHeightForWidth(labelThresholdV->sizePolicy().hasHeightForWidth());
        labelThresholdV->setSizePolicy(sizePolicy6);
        labelThresholdV->setMinimumSize(QSize(30, 0));
        labelThresholdV->setFrameShape(QFrame::StyledPanel);
        labelThresholdV->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_11->addWidget(labelThresholdV);


        gridLayout->addLayout(horizontalLayout_11, 6, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_ColorLevels = new QLabel(groupBox_2);
        label_ColorLevels->setObjectName(QString::fromUtf8("label_ColorLevels"));

        horizontalLayout->addWidget(label_ColorLevels);

        horizontalSlider_colorLevels = new QSlider(groupBox_2);
        horizontalSlider_colorLevels->setObjectName(QString::fromUtf8("horizontalSlider_colorLevels"));
        horizontalSlider_colorLevels->setMinimum(1);
        horizontalSlider_colorLevels->setMaximum(10);
        horizontalSlider_colorLevels->setValue(3);
        horizontalSlider_colorLevels->setOrientation(Qt::Horizontal);
        horizontalSlider_colorLevels->setTickPosition(QSlider::TicksBelow);
        horizontalSlider_colorLevels->setTickInterval(1);

        horizontalLayout->addWidget(horizontalSlider_colorLevels);

        labelColorLevels = new QLabel(groupBox_2);
        labelColorLevels->setObjectName(QString::fromUtf8("labelColorLevels"));
        sizePolicy6.setHeightForWidth(labelColorLevels->sizePolicy().hasHeightForWidth());
        labelColorLevels->setSizePolicy(sizePolicy6);
        labelColorLevels->setMinimumSize(QSize(30, 0));
        labelColorLevels->setFrameShape(QFrame::StyledPanel);
        labelColorLevels->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(labelColorLevels);


        gridLayout->addLayout(horizontalLayout, 7, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_analysisDepth = new QLabel(groupBox_2);
        label_analysisDepth->setObjectName(QString::fromUtf8("label_analysisDepth"));

        horizontalLayout_2->addWidget(label_analysisDepth);

        horizontalSlider_AnalisisDepth = new QSlider(groupBox_2);
        horizontalSlider_AnalisisDepth->setObjectName(QString::fromUtf8("horizontalSlider_AnalisisDepth"));
        horizontalSlider_AnalisisDepth->setMaximum(100);
        horizontalSlider_AnalisisDepth->setSliderPosition(50);
        horizontalSlider_AnalisisDepth->setOrientation(Qt::Horizontal);
        horizontalSlider_AnalisisDepth->setTickPosition(QSlider::TicksBelow);
        horizontalSlider_AnalisisDepth->setTickInterval(5);

        horizontalLayout_2->addWidget(horizontalSlider_AnalisisDepth);

        labelAnalysisDepth = new QLabel(groupBox_2);
        labelAnalysisDepth->setObjectName(QString::fromUtf8("labelAnalysisDepth"));
        sizePolicy6.setHeightForWidth(labelAnalysisDepth->sizePolicy().hasHeightForWidth());
        labelAnalysisDepth->setSizePolicy(sizePolicy6);
        labelAnalysisDepth->setMinimumSize(QSize(30, 0));
        labelAnalysisDepth->setFrameShape(QFrame::StyledPanel);
        labelAnalysisDepth->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(labelAnalysisDepth);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 1);


        gridLayout_12->addWidget(groupBox_2, 0, 0, 1, 1);

        MuphicConfig->addTab(tab1, QString());
        tab2 = new QWidget();
        tab2->setObjectName(QString::fromUtf8("tab2"));
        gridLayout_5 = new QGridLayout(tab2);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        groupBox_3 = new QGroupBox(tab2);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        sizePolicy.setHeightForWidth(groupBox_3->sizePolicy().hasHeightForWidth());
        groupBox_3->setSizePolicy(sizePolicy);
        groupBox_3->setMinimumSize(QSize(441, 300));
        groupBox_3->setMaximumSize(QSize(16777215, 16777215));
        gridLayout_14 = new QGridLayout(groupBox_3);
        gridLayout_14->setObjectName(QString::fromUtf8("gridLayout_14"));
        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        label_reconColors = new QLabel(groupBox_3);
        label_reconColors->setObjectName(QString::fromUtf8("label_reconColors"));

        horizontalLayout_13->addWidget(label_reconColors);

        comboBox_reconColors = new QComboBox(groupBox_3);
        comboBox_reconColors->setObjectName(QString::fromUtf8("comboBox_reconColors"));
        QSizePolicy sizePolicy7(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(comboBox_reconColors->sizePolicy().hasHeightForWidth());
        comboBox_reconColors->setSizePolicy(sizePolicy7);
        comboBox_reconColors->setMinimumSize(QSize(100, 0));
        comboBox_reconColors->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_13->addWidget(comboBox_reconColors);

        horizontalSpacer_4 = new QSpacerItem(121, 24, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_4);


        gridLayout_14->addLayout(horizontalLayout_13, 0, 0, 1, 1);

        gridLayout_13 = new QGridLayout();
        gridLayout_13->setObjectName(QString::fromUtf8("gridLayout_13"));
        groupBox_v1 = new QGroupBox(groupBox_3);
        groupBox_v1->setObjectName(QString::fromUtf8("groupBox_v1"));
        sizePolicy.setHeightForWidth(groupBox_v1->sizePolicy().hasHeightForWidth());
        groupBox_v1->setSizePolicy(sizePolicy);
        groupBox_v1->setMinimumSize(QSize(179, 83));
        formLayout_3 = new QFormLayout(groupBox_v1);
        formLayout_3->setObjectName(QString::fromUtf8("formLayout_3"));
        gridLayout_9 = new QGridLayout();
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        label_v1Composer = new QLabel(groupBox_v1);
        label_v1Composer->setObjectName(QString::fromUtf8("label_v1Composer"));

        gridLayout_9->addWidget(label_v1Composer, 0, 0, 1, 1);

        comboBox_v1Composer = new QComboBox(groupBox_v1);
        comboBox_v1Composer->setObjectName(QString::fromUtf8("comboBox_v1Composer"));
        sizePolicy2.setHeightForWidth(comboBox_v1Composer->sizePolicy().hasHeightForWidth());
        comboBox_v1Composer->setSizePolicy(sizePolicy2);

        gridLayout_9->addWidget(comboBox_v1Composer, 0, 1, 1, 1);

        label_v1Instrument = new QLabel(groupBox_v1);
        label_v1Instrument->setObjectName(QString::fromUtf8("label_v1Instrument"));

        gridLayout_9->addWidget(label_v1Instrument, 1, 0, 1, 1);

        comboBox_v1Instrument = new QComboBox(groupBox_v1);
        comboBox_v1Instrument->setObjectName(QString::fromUtf8("comboBox_v1Instrument"));
        sizePolicy2.setHeightForWidth(comboBox_v1Instrument->sizePolicy().hasHeightForWidth());
        comboBox_v1Instrument->setSizePolicy(sizePolicy2);

        gridLayout_9->addWidget(comboBox_v1Instrument, 1, 1, 1, 1);


        formLayout_3->setLayout(0, QFormLayout::LabelRole, gridLayout_9);


        gridLayout_13->addWidget(groupBox_v1, 0, 0, 1, 1);

        groupBox_v2 = new QGroupBox(groupBox_3);
        groupBox_v2->setObjectName(QString::fromUtf8("groupBox_v2"));
        sizePolicy.setHeightForWidth(groupBox_v2->sizePolicy().hasHeightForWidth());
        groupBox_v2->setSizePolicy(sizePolicy);
        groupBox_v2->setMinimumSize(QSize(179, 83));
        formLayout_4 = new QFormLayout(groupBox_v2);
        formLayout_4->setObjectName(QString::fromUtf8("formLayout_4"));
        gridLayout_8 = new QGridLayout();
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        label_v2Composer = new QLabel(groupBox_v2);
        label_v2Composer->setObjectName(QString::fromUtf8("label_v2Composer"));

        gridLayout_8->addWidget(label_v2Composer, 0, 0, 1, 1);

        comboBox_v2Composer = new QComboBox(groupBox_v2);
        comboBox_v2Composer->setObjectName(QString::fromUtf8("comboBox_v2Composer"));
        sizePolicy2.setHeightForWidth(comboBox_v2Composer->sizePolicy().hasHeightForWidth());
        comboBox_v2Composer->setSizePolicy(sizePolicy2);

        gridLayout_8->addWidget(comboBox_v2Composer, 0, 1, 1, 1);

        label_v2Instrument = new QLabel(groupBox_v2);
        label_v2Instrument->setObjectName(QString::fromUtf8("label_v2Instrument"));

        gridLayout_8->addWidget(label_v2Instrument, 1, 0, 1, 1);

        comboBox_v2Instruments = new QComboBox(groupBox_v2);
        comboBox_v2Instruments->setObjectName(QString::fromUtf8("comboBox_v2Instruments"));
        sizePolicy2.setHeightForWidth(comboBox_v2Instruments->sizePolicy().hasHeightForWidth());
        comboBox_v2Instruments->setSizePolicy(sizePolicy2);

        gridLayout_8->addWidget(comboBox_v2Instruments, 1, 1, 1, 1);


        formLayout_4->setLayout(0, QFormLayout::LabelRole, gridLayout_8);


        gridLayout_13->addWidget(groupBox_v2, 0, 1, 1, 1);

        groupBox_v3 = new QGroupBox(groupBox_3);
        groupBox_v3->setObjectName(QString::fromUtf8("groupBox_v3"));
        sizePolicy.setHeightForWidth(groupBox_v3->sizePolicy().hasHeightForWidth());
        groupBox_v3->setSizePolicy(sizePolicy);
        groupBox_v3->setMinimumSize(QSize(179, 83));
        groupBox_v3->setAutoFillBackground(false);
        groupBox_v3->setFlat(false);
        formLayout_2 = new QFormLayout(groupBox_v3);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        gridLayout_6 = new QGridLayout();
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        label_v3Composer = new QLabel(groupBox_v3);
        label_v3Composer->setObjectName(QString::fromUtf8("label_v3Composer"));

        gridLayout_6->addWidget(label_v3Composer, 0, 0, 1, 1);

        comboBox_v3Composer = new QComboBox(groupBox_v3);
        comboBox_v3Composer->setObjectName(QString::fromUtf8("comboBox_v3Composer"));
        sizePolicy2.setHeightForWidth(comboBox_v3Composer->sizePolicy().hasHeightForWidth());
        comboBox_v3Composer->setSizePolicy(sizePolicy2);

        gridLayout_6->addWidget(comboBox_v3Composer, 0, 1, 1, 1);

        label_v3Instrument = new QLabel(groupBox_v3);
        label_v3Instrument->setObjectName(QString::fromUtf8("label_v3Instrument"));

        gridLayout_6->addWidget(label_v3Instrument, 1, 0, 1, 1);

        comboBox_v3Instrument = new QComboBox(groupBox_v3);
        comboBox_v3Instrument->setObjectName(QString::fromUtf8("comboBox_v3Instrument"));
        sizePolicy2.setHeightForWidth(comboBox_v3Instrument->sizePolicy().hasHeightForWidth());
        comboBox_v3Instrument->setSizePolicy(sizePolicy2);

        gridLayout_6->addWidget(comboBox_v3Instrument, 1, 1, 1, 1);


        formLayout_2->setLayout(0, QFormLayout::LabelRole, gridLayout_6);


        gridLayout_13->addWidget(groupBox_v3, 1, 0, 1, 1);

        groupBox_v4 = new QGroupBox(groupBox_3);
        groupBox_v4->setObjectName(QString::fromUtf8("groupBox_v4"));
        sizePolicy.setHeightForWidth(groupBox_v4->sizePolicy().hasHeightForWidth());
        groupBox_v4->setSizePolicy(sizePolicy);
        groupBox_v4->setMinimumSize(QSize(179, 83));
        formLayout = new QFormLayout(groupBox_v4);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        gridLayout_7 = new QGridLayout();
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        label_v4Composer = new QLabel(groupBox_v4);
        label_v4Composer->setObjectName(QString::fromUtf8("label_v4Composer"));

        gridLayout_7->addWidget(label_v4Composer, 0, 0, 1, 1);

        comboBox_v4Composer = new QComboBox(groupBox_v4);
        comboBox_v4Composer->setObjectName(QString::fromUtf8("comboBox_v4Composer"));
        sizePolicy2.setHeightForWidth(comboBox_v4Composer->sizePolicy().hasHeightForWidth());
        comboBox_v4Composer->setSizePolicy(sizePolicy2);

        gridLayout_7->addWidget(comboBox_v4Composer, 0, 1, 1, 1);

        label_v4Instrument = new QLabel(groupBox_v4);
        label_v4Instrument->setObjectName(QString::fromUtf8("label_v4Instrument"));

        gridLayout_7->addWidget(label_v4Instrument, 1, 0, 1, 1);

        comboBox_v4Instrument = new QComboBox(groupBox_v4);
        comboBox_v4Instrument->setObjectName(QString::fromUtf8("comboBox_v4Instrument"));
        sizePolicy2.setHeightForWidth(comboBox_v4Instrument->sizePolicy().hasHeightForWidth());
        comboBox_v4Instrument->setSizePolicy(sizePolicy2);

        gridLayout_7->addWidget(comboBox_v4Instrument, 1, 1, 1, 1);


        formLayout->setLayout(0, QFormLayout::LabelRole, gridLayout_7);


        gridLayout_13->addWidget(groupBox_v4, 1, 1, 1, 1);


        gridLayout_14->addLayout(gridLayout_13, 1, 0, 1, 1);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        label_composerMix = new QLabel(groupBox_3);
        label_composerMix->setObjectName(QString::fromUtf8("label_composerMix"));
        sizePolicy5.setHeightForWidth(label_composerMix->sizePolicy().hasHeightForWidth());
        label_composerMix->setSizePolicy(sizePolicy5);
        label_composerMix->setMinimumSize(QSize(130, 0));
        label_composerMix->setMaximumSize(QSize(80, 16777215));

        horizontalLayout_12->addWidget(label_composerMix);

        comboBox_composerMixer = new QComboBox(groupBox_3);
        comboBox_composerMixer->setObjectName(QString::fromUtf8("comboBox_composerMixer"));
        sizePolicy2.setHeightForWidth(comboBox_composerMixer->sizePolicy().hasHeightForWidth());
        comboBox_composerMixer->setSizePolicy(sizePolicy2);
        comboBox_composerMixer->setMaximumSize(QSize(94, 16777215));

        horizontalLayout_12->addWidget(comboBox_composerMixer);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_2);

        label_tempo = new QLabel(groupBox_3);
        label_tempo->setObjectName(QString::fromUtf8("label_tempo"));
        sizePolicy6.setHeightForWidth(label_tempo->sizePolicy().hasHeightForWidth());
        label_tempo->setSizePolicy(sizePolicy6);
        label_tempo->setMinimumSize(QSize(50, 0));
        label_tempo->setMaximumSize(QSize(16777215, 16777215));
        label_tempo->setBaseSize(QSize(0, 0));

        horizontalLayout_12->addWidget(label_tempo);

        comboBox_v3Composer_3 = new QComboBox(groupBox_3);
        comboBox_v3Composer_3->setObjectName(QString::fromUtf8("comboBox_v3Composer_3"));
        sizePolicy2.setHeightForWidth(comboBox_v3Composer_3->sizePolicy().hasHeightForWidth());
        comboBox_v3Composer_3->setSizePolicy(sizePolicy2);
        comboBox_v3Composer_3->setMinimumSize(QSize(40, 0));
        comboBox_v3Composer_3->setMaximumSize(QSize(89, 16777215));

        horizontalLayout_12->addWidget(comboBox_v3Composer_3);

        horizontalSpacer_6 = new QSpacerItem(50, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_6);


        gridLayout_14->addLayout(horizontalLayout_12, 2, 0, 1, 1);


        gridLayout_5->addWidget(groupBox_3, 0, 0, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_3, 0, 1, 1, 1);

        MuphicConfig->addTab(tab2, QString());

        retranslateUi(MuphicConfig);

        MuphicConfig->setCurrentIndex(0);
        filterSelComboBox->setCurrentIndex(2);
        comboBox_reconColors->setCurrentIndex(2);
        comboBox_v1Composer->setCurrentIndex(2);
        comboBox_v1Instrument->setCurrentIndex(0);
        comboBox_v2Composer->setCurrentIndex(2);
        comboBox_v2Instruments->setCurrentIndex(1);
        comboBox_v3Composer->setCurrentIndex(2);
        comboBox_v3Instrument->setCurrentIndex(2);
        comboBox_v4Composer->setCurrentIndex(2);
        comboBox_v4Instrument->setCurrentIndex(2);
        comboBox_composerMixer->setCurrentIndex(2);
        comboBox_v3Composer_3->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MuphicConfig);
    } // setupUi

    void retranslateUi(QTabWidget *MuphicConfig)
    {
        MuphicConfig->setWindowTitle(QApplication::translate("MuphicConfig", "TabWidget", 0, QApplication::UnicodeUTF8));
        label_InputPic->setText(QApplication::translate("MuphicConfig", "   Input Pic  ", 0, QApplication::UnicodeUTF8));
        lineEdit_InputPic->setText(QApplication::translate("MuphicConfig", "./test1.png", 0, QApplication::UnicodeUTF8));
        toolButton_InputPic->setText(QApplication::translate("MuphicConfig", "...", 0, QApplication::UnicodeUTF8));
        label_OutputMidi->setText(QApplication::translate("MuphicConfig", " Output Midi", 0, QApplication::UnicodeUTF8));
        toolButton_OutputMidi->setText(QApplication::translate("MuphicConfig", "...", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QApplication::translate("MuphicConfig", "Input Image", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("MuphicConfig", "Analysis output", 0, QApplication::UnicodeUTF8));
        pushButton_Analyze->setText(QApplication::translate("MuphicConfig", "Analyze", 0, QApplication::UnicodeUTF8));
        pushButton_Generate->setText(QApplication::translate("MuphicConfig", "Compose", 0, QApplication::UnicodeUTF8));
        pushButton_Play->setText(QString());
        pushButton_pause->setText(QApplication::translate("MuphicConfig", "Pause", 0, QApplication::UnicodeUTF8));
        pushButton_Stop->setText(QString());
        MuphicConfig->setTabText(MuphicConfig->indexOf(tab), QApplication::translate("MuphicConfig", "Main Window", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("MuphicConfig", "Phic Options", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MuphicConfig", "Filter", 0, QApplication::UnicodeUTF8));
        filterSelComboBox->clear();
        filterSelComboBox->insertItems(0, QStringList()
         << QApplication::translate("MuphicConfig", "Threshold", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MuphicConfig", "Adaptative Threshold", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MuphicConfig", "Canny", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MuphicConfig", "Hue Division", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MuphicConfig", "Multiple Threshold", 0, QApplication::UnicodeUTF8)
        );
        label_4->setText(QApplication::translate("MuphicConfig", "Noise Selection", 0, QApplication::UnicodeUTF8));
        noiseLabel->setText(QApplication::translate("MuphicConfig", "0.0", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MuphicConfig", "Polygon Simplification", 0, QApplication::UnicodeUTF8));
        labelPolSimp->setText(QApplication::translate("MuphicConfig", "2", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MuphicConfig", "Threshold", 0, QApplication::UnicodeUTF8));
        tLabel->setText(QApplication::translate("MuphicConfig", "50", 0, QApplication::UnicodeUTF8));
        label_ThresholdH->setText(QApplication::translate("MuphicConfig", "Threshold H", 0, QApplication::UnicodeUTF8));
        labelThresholdH->setText(QApplication::translate("MuphicConfig", "35", 0, QApplication::UnicodeUTF8));
        label_ThresholdS->setText(QApplication::translate("MuphicConfig", "Threshold S", 0, QApplication::UnicodeUTF8));
        labelThresholdS->setText(QApplication::translate("MuphicConfig", "20", 0, QApplication::UnicodeUTF8));
        label_ThresholdV->setText(QApplication::translate("MuphicConfig", "Threshold V", 0, QApplication::UnicodeUTF8));
        labelThresholdV->setText(QApplication::translate("MuphicConfig", "50", 0, QApplication::UnicodeUTF8));
        label_ColorLevels->setText(QApplication::translate("MuphicConfig", "Color levels", 0, QApplication::UnicodeUTF8));
        labelColorLevels->setText(QApplication::translate("MuphicConfig", "3", 0, QApplication::UnicodeUTF8));
        label_analysisDepth->setText(QApplication::translate("MuphicConfig", "Anaysis Depth", 0, QApplication::UnicodeUTF8));
        labelAnalysisDepth->setText(QApplication::translate("MuphicConfig", "50", 0, QApplication::UnicodeUTF8));
        MuphicConfig->setTabText(MuphicConfig->indexOf(tab1), QApplication::translate("MuphicConfig", "Graphic Config", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("MuphicConfig", "Mu Options", 0, QApplication::UnicodeUTF8));
        label_reconColors->setText(QApplication::translate("MuphicConfig", "Color System", 0, QApplication::UnicodeUTF8));
        comboBox_reconColors->clear();
        comboBox_reconColors->insertItems(0, QStringList()
         << QApplication::translate("MuphicConfig", "Demo1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MuphicConfig", "Demo2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MuphicConfig", "Scriabin", 0, QApplication::UnicodeUTF8)
        );
        groupBox_v1->setTitle(QApplication::translate("MuphicConfig", "Voice 1", 0, QApplication::UnicodeUTF8));
        label_v1Composer->setText(QApplication::translate("MuphicConfig", "Composer", 0, QApplication::UnicodeUTF8));
        comboBox_v1Composer->clear();
        comboBox_v1Composer->insertItems(0, QStringList()
         << QApplication::translate("MuphicConfig", "Demo1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MuphicConfig", "Demo2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MuphicConfig", "FigMelody2", 0, QApplication::UnicodeUTF8)
        );
        label_v1Instrument->setText(QApplication::translate("MuphicConfig", "Instrument", 0, QApplication::UnicodeUTF8));
        comboBox_v1Instrument->clear();
        comboBox_v1Instrument->insertItems(0, QStringList()
         << QApplication::translate("MuphicConfig", "Strings", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MuphicConfig", "Flute", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MuphicConfig", "Electric Bass", 0, QApplication::UnicodeUTF8)
        );
        groupBox_v2->setTitle(QApplication::translate("MuphicConfig", "Voice 2", 0, QApplication::UnicodeUTF8));
        label_v2Composer->setText(QApplication::translate("MuphicConfig", "Composer", 0, QApplication::UnicodeUTF8));
        comboBox_v2Composer->clear();
        comboBox_v2Composer->insertItems(0, QStringList()
         << QApplication::translate("MuphicConfig", "Demo1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MuphicConfig", "Demo2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MuphicConfig", "FigMelody2", 0, QApplication::UnicodeUTF8)
        );
        label_v2Instrument->setText(QApplication::translate("MuphicConfig", "Instrument", 0, QApplication::UnicodeUTF8));
        comboBox_v2Instruments->clear();
        comboBox_v2Instruments->insertItems(0, QStringList()
         << QApplication::translate("MuphicConfig", "Strings", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MuphicConfig", "Flute", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MuphicConfig", "Electric Bass", 0, QApplication::UnicodeUTF8)
        );
        groupBox_v3->setTitle(QApplication::translate("MuphicConfig", "Voice 3", 0, QApplication::UnicodeUTF8));
        label_v3Composer->setText(QApplication::translate("MuphicConfig", "Composer", 0, QApplication::UnicodeUTF8));
        comboBox_v3Composer->clear();
        comboBox_v3Composer->insertItems(0, QStringList()
         << QApplication::translate("MuphicConfig", "Demo1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MuphicConfig", "Demo2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MuphicConfig", "FigBass2", 0, QApplication::UnicodeUTF8)
        );
        label_v3Instrument->setText(QApplication::translate("MuphicConfig", "Instrument", 0, QApplication::UnicodeUTF8));
        comboBox_v3Instrument->clear();
        comboBox_v3Instrument->insertItems(0, QStringList()
         << QApplication::translate("MuphicConfig", "Strings", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MuphicConfig", "Flute", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MuphicConfig", "Electric Bass", 0, QApplication::UnicodeUTF8)
        );
        groupBox_v4->setTitle(QApplication::translate("MuphicConfig", "Voice 4", 0, QApplication::UnicodeUTF8));
        label_v4Composer->setText(QApplication::translate("MuphicConfig", "Composer", 0, QApplication::UnicodeUTF8));
        comboBox_v4Composer->clear();
        comboBox_v4Composer->insertItems(0, QStringList()
         << QApplication::translate("MuphicConfig", "Demo1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MuphicConfig", "Demo2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MuphicConfig", "FigRithm2", 0, QApplication::UnicodeUTF8)
        );
        label_v4Instrument->setText(QApplication::translate("MuphicConfig", "Instrument", 0, QApplication::UnicodeUTF8));
        comboBox_v4Instrument->clear();
        comboBox_v4Instrument->insertItems(0, QStringList()
         << QApplication::translate("MuphicConfig", "Demo1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MuphicConfig", "Demo2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MuphicConfig", "Drums & Clanks", 0, QApplication::UnicodeUTF8)
        );
        label_composerMix->setText(QApplication::translate("MuphicConfig", "Composer Mixer", 0, QApplication::UnicodeUTF8));
        comboBox_composerMixer->clear();
        comboBox_composerMixer->insertItems(0, QStringList()
         << QApplication::translate("MuphicConfig", "Demo1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MuphicConfig", "Demo2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MuphicConfig", "Timothy2", 0, QApplication::UnicodeUTF8)
        );
        label_tempo->setText(QApplication::translate("MuphicConfig", "Tempo", 0, QApplication::UnicodeUTF8));
        comboBox_v3Composer_3->clear();
        comboBox_v3Composer_3->insertItems(0, QStringList()
         << QApplication::translate("MuphicConfig", "1/4", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MuphicConfig", "2/4", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MuphicConfig", "3/4", 0, QApplication::UnicodeUTF8)
        );
        MuphicConfig->setTabText(MuphicConfig->indexOf(tab2), QApplication::translate("MuphicConfig", "Composition Config", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MuphicConfig: public Ui_MuphicConfig {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MUPHICCONFIG_H
