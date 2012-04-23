/********************************************************************************
** Form generated from reading UI file 'guimupic.ui'
**
** Created: Mon 23. Apr 19:18:31 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUIMUPIC_H
#define UI_GUIMUPIC_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QGraphicsView>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLCDNumber>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QScrollArea>
#include <QtGui/QSlider>
#include <QtGui/QSpacerItem>
#include <QtGui/QSplitter>
#include <QtGui/QStatusBar>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include <volumebar.h>
#include "polygonwidget.h"
#include "seekbar.h"

QT_BEGIN_NAMESPACE

class Ui_GuiMupic
{
public:
    QWidget *centralWidget;
    QWidget *layoutWidget;
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
    QGridLayout *gridLayout;
    QScrollArea *scrollArea;
    PolygonWidget *polyWidget;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
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
    QVBoxLayout *verticalLayout_5;
    QGroupBox *groupBox_2;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_4;
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
    QGroupBox *groupBox_3;
    QSplitter *splitter;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_reconColors;
    QComboBox *comboBox_reconColors;
    QSpacerItem *horizontalSpacer_4;
    QWidget *widget1;
    QGridLayout *gridLayout_5;
    QGroupBox *groupBox_v1;
    QGridLayout *gridLayout_6;
    QLabel *label_v1Composer;
    QComboBox *comboBox_v1Composer;
    QLabel *label_v1Instrument;
    QComboBox *comboBox_v1Instrument;
    QGroupBox *groupBox_v2;
    QGridLayout *gridLayout_8;
    QLabel *label_v2Composer;
    QComboBox *comboBox_v2Composer;
    QLabel *label_v2Instrument;
    QComboBox *comboBox_v2Instruments;
    QGroupBox *groupBox_v3;
    QGridLayout *gridLayout_7;
    QLabel *label_v3Composer;
    QComboBox *comboBox_v3Composer;
    QLabel *label_v3Instrument;
    QComboBox *comboBox_v3Instrument;
    QGroupBox *groupBox_v4;
    QGridLayout *gridLayout_9;
    QLabel *label_v4Composer;
    QComboBox *comboBox_v4Composer;
    QLabel *label_v4Instrument;
    QComboBox *comboBox_v4Instrument;
    QWidget *widget2;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_composerMix;
    QComboBox *comboBox_composerMixer;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_tempo;
    QComboBox *comboBox_v3Composer_3;
    QSpacerItem *horizontalSpacer_6;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *GuiMupic)
    {
        if (GuiMupic->objectName().isEmpty())
            GuiMupic->setObjectName(QString::fromUtf8("GuiMupic"));
        GuiMupic->resize(1188, 654);
        centralWidget = new QWidget(GuiMupic);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 1171, 631));
        gridLayout_3 = new QGridLayout(layoutWidget);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_InputPic = new QLabel(layoutWidget);
        label_InputPic->setObjectName(QString::fromUtf8("label_InputPic"));

        horizontalLayout_4->addWidget(label_InputPic);

        lineEdit_InputPic = new QLineEdit(layoutWidget);
        lineEdit_InputPic->setObjectName(QString::fromUtf8("lineEdit_InputPic"));
        lineEdit_InputPic->setEnabled(true);
        lineEdit_InputPic->setReadOnly(true);

        horizontalLayout_4->addWidget(lineEdit_InputPic);

        toolButton_InputPic = new QToolButton(layoutWidget);
        toolButton_InputPic->setObjectName(QString::fromUtf8("toolButton_InputPic"));

        horizontalLayout_4->addWidget(toolButton_InputPic);


        gridLayout_2->addLayout(horizontalLayout_4, 0, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_OutputMidi = new QLabel(layoutWidget);
        label_OutputMidi->setObjectName(QString::fromUtf8("label_OutputMidi"));

        horizontalLayout_3->addWidget(label_OutputMidi);

        lineEdit_OutputMidi = new QLineEdit(layoutWidget);
        lineEdit_OutputMidi->setObjectName(QString::fromUtf8("lineEdit_OutputMidi"));

        horizontalLayout_3->addWidget(lineEdit_OutputMidi);

        toolButton_OutputMidi = new QToolButton(layoutWidget);
        toolButton_OutputMidi->setObjectName(QString::fromUtf8("toolButton_OutputMidi"));

        horizontalLayout_3->addWidget(toolButton_OutputMidi);


        gridLayout_2->addLayout(horizontalLayout_3, 1, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        groupBox_4 = new QGroupBox(layoutWidget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox_4->sizePolicy().hasHeightForWidth());
        groupBox_4->setSizePolicy(sizePolicy);
        gridLayout_4 = new QGridLayout(groupBox_4);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
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

        groupBox = new QGroupBox(layoutWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        groupBox->setMinimumSize(QSize(256, 194));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        scrollArea = new QScrollArea(groupBox);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        polyWidget = new PolygonWidget();
        polyWidget->setObjectName(QString::fromUtf8("polyWidget"));
        polyWidget->setGeometry(QRect(0, 0, 311, 453));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(polyWidget->sizePolicy().hasHeightForWidth());
        polyWidget->setSizePolicy(sizePolicy1);
        polyWidget->setMinimumSize(QSize(216, 217));
        scrollArea->setWidget(polyWidget);

        gridLayout->addWidget(scrollArea, 0, 0, 1, 1);


        horizontalLayout_5->addWidget(groupBox);


        gridLayout_2->addLayout(horizontalLayout_5, 2, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 1, 1, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));

        gridLayout_3->addLayout(verticalLayout_2, 1, 3, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(13, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_3, 1, 4, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pushButton_Analyze = new QPushButton(layoutWidget);
        pushButton_Analyze->setObjectName(QString::fromUtf8("pushButton_Analyze"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(pushButton_Analyze->sizePolicy().hasHeightForWidth());
        pushButton_Analyze->setSizePolicy(sizePolicy2);
        pushButton_Analyze->setMaximumSize(QSize(150, 16777215));

        horizontalLayout_2->addWidget(pushButton_Analyze);

        pushButton_Generate = new QPushButton(layoutWidget);
        pushButton_Generate->setObjectName(QString::fromUtf8("pushButton_Generate"));
        sizePolicy2.setHeightForWidth(pushButton_Generate->sizePolicy().hasHeightForWidth());
        pushButton_Generate->setSizePolicy(sizePolicy2);
        pushButton_Generate->setMaximumSize(QSize(150, 16777215));

        horizontalLayout_2->addWidget(pushButton_Generate);

        progressBar_Generate = new QProgressBar(layoutWidget);
        progressBar_Generate->setObjectName(QString::fromUtf8("progressBar_Generate"));
        progressBar_Generate->setValue(0);

        horizontalLayout_2->addWidget(progressBar_Generate);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_player = new QHBoxLayout();
        horizontalLayout_player->setSpacing(6);
        horizontalLayout_player->setObjectName(QString::fromUtf8("horizontalLayout_player"));
        pushButton_Play = new QPushButton(layoutWidget);
        pushButton_Play->setObjectName(QString::fromUtf8("pushButton_Play"));
        QIcon icon;
        icon.addFile(QString::fromUtf8("play.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_Play->setIcon(icon);

        horizontalLayout_player->addWidget(pushButton_Play);

        pushButton_pause = new QPushButton(layoutWidget);
        pushButton_pause->setObjectName(QString::fromUtf8("pushButton_pause"));

        horizontalLayout_player->addWidget(pushButton_pause);

        pushButton_Stop = new QPushButton(layoutWidget);
        pushButton_Stop->setObjectName(QString::fromUtf8("pushButton_Stop"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("stop.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_Stop->setIcon(icon1);

        horizontalLayout_player->addWidget(pushButton_Stop);

        seekSlider = new SeekBar(layoutWidget);
        seekSlider->setObjectName(QString::fromUtf8("seekSlider"));

        horizontalLayout_player->addWidget(seekSlider);

        volumeSlider = new VolumeBar(layoutWidget);
        volumeSlider->setObjectName(QString::fromUtf8("volumeSlider"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(255);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(volumeSlider->sizePolicy().hasHeightForWidth());
        volumeSlider->setSizePolicy(sizePolicy3);

        horizontalLayout_player->addWidget(volumeSlider);

        timeLcd = new QLCDNumber(layoutWidget);
        timeLcd->setObjectName(QString::fromUtf8("timeLcd"));

        horizontalLayout_player->addWidget(timeLcd);


        verticalLayout->addLayout(horizontalLayout_player);


        gridLayout_3->addLayout(verticalLayout, 2, 1, 1, 3);

        horizontalSpacer_5 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_5, 1, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_3->addItem(verticalSpacer_2, 0, 1, 1, 1);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setSizeConstraint(QLayout::SetFixedSize);
        groupBox_2 = new QGroupBox(layoutWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        QSizePolicy sizePolicy4(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy4);
        groupBox_2->setMinimumSize(QSize(441, 240));
        groupBox_2->setMaximumSize(QSize(441, 16777215));
        groupBox_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        layoutWidget1 = new QWidget(groupBox_2);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 20, 412, 220));
        verticalLayout_4 = new QVBoxLayout(layoutWidget1);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label = new QLabel(layoutWidget1);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy5(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy5);

        horizontalLayout_6->addWidget(label);

        filterSelComboBox = new QComboBox(layoutWidget1);
        filterSelComboBox->setObjectName(QString::fromUtf8("filterSelComboBox"));

        horizontalLayout_6->addWidget(filterSelComboBox);

        horizontalSpacer = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer);

        label_4 = new QLabel(layoutWidget1);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_6->addWidget(label_4);

        horizontalSlider_3 = new QSlider(layoutWidget1);
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

        noiseLabel = new QLabel(layoutWidget1);
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


        verticalLayout_4->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy5.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy5);

        horizontalLayout_7->addWidget(label_3);

        horizontalSlider_6 = new QSlider(layoutWidget1);
        horizontalSlider_6->setObjectName(QString::fromUtf8("horizontalSlider_6"));
        horizontalSlider_6->setMinimum(1);
        horizontalSlider_6->setMaximum(45);
        horizontalSlider_6->setValue(2);
        horizontalSlider_6->setOrientation(Qt::Horizontal);
        horizontalSlider_6->setTickPosition(QSlider::TicksBelow);
        horizontalSlider_6->setTickInterval(1);

        horizontalLayout_7->addWidget(horizontalSlider_6);

        labelPolSimp = new QLabel(layoutWidget1);
        labelPolSimp->setObjectName(QString::fromUtf8("labelPolSimp"));
        sizePolicy6.setHeightForWidth(labelPolSimp->sizePolicy().hasHeightForWidth());
        labelPolSimp->setSizePolicy(sizePolicy6);
        labelPolSimp->setMinimumSize(QSize(30, 0));
        labelPolSimp->setMaximumSize(QSize(30, 16777215));
        labelPolSimp->setFrameShape(QFrame::StyledPanel);
        labelPolSimp->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_7->addWidget(labelPolSimp);


        verticalLayout_4->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_8->addWidget(label_2);

        horizontalSlider_2 = new QSlider(layoutWidget1);
        horizontalSlider_2->setObjectName(QString::fromUtf8("horizontalSlider_2"));
        horizontalSlider_2->setEnabled(true);
        horizontalSlider_2->setMaximum(200);
        horizontalSlider_2->setValue(50);
        horizontalSlider_2->setOrientation(Qt::Horizontal);
        horizontalSlider_2->setTickPosition(QSlider::TicksBelow);
        horizontalSlider_2->setTickInterval(10);

        horizontalLayout_8->addWidget(horizontalSlider_2);

        tLabel = new QLabel(layoutWidget1);
        tLabel->setObjectName(QString::fromUtf8("tLabel"));
        tLabel->setEnabled(true);
        sizePolicy6.setHeightForWidth(tLabel->sizePolicy().hasHeightForWidth());
        tLabel->setSizePolicy(sizePolicy6);
        tLabel->setMinimumSize(QSize(30, 0));
        tLabel->setMaximumSize(QSize(30, 16777215));
        tLabel->setFrameShape(QFrame::StyledPanel);
        tLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_8->addWidget(tLabel);


        verticalLayout_4->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_ThresholdH = new QLabel(layoutWidget1);
        label_ThresholdH->setObjectName(QString::fromUtf8("label_ThresholdH"));

        horizontalLayout_9->addWidget(label_ThresholdH);

        horizontalSliderTH = new QSlider(layoutWidget1);
        horizontalSliderTH->setObjectName(QString::fromUtf8("horizontalSliderTH"));
        horizontalSliderTH->setEnabled(true);
        horizontalSliderTH->setMaximum(200);
        horizontalSliderTH->setValue(35);
        horizontalSliderTH->setOrientation(Qt::Horizontal);
        horizontalSliderTH->setTickPosition(QSlider::TicksBelow);
        horizontalSliderTH->setTickInterval(10);

        horizontalLayout_9->addWidget(horizontalSliderTH);

        labelThresholdH = new QLabel(layoutWidget1);
        labelThresholdH->setObjectName(QString::fromUtf8("labelThresholdH"));
        sizePolicy6.setHeightForWidth(labelThresholdH->sizePolicy().hasHeightForWidth());
        labelThresholdH->setSizePolicy(sizePolicy6);
        labelThresholdH->setMinimumSize(QSize(30, 0));
        labelThresholdH->setFrameShape(QFrame::StyledPanel);
        labelThresholdH->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_9->addWidget(labelThresholdH);


        verticalLayout_4->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_ThresholdS = new QLabel(layoutWidget1);
        label_ThresholdS->setObjectName(QString::fromUtf8("label_ThresholdS"));

        horizontalLayout_10->addWidget(label_ThresholdS);

        horizontalSliderTS = new QSlider(layoutWidget1);
        horizontalSliderTS->setObjectName(QString::fromUtf8("horizontalSliderTS"));
        horizontalSliderTS->setEnabled(true);
        horizontalSliderTS->setMaximum(200);
        horizontalSliderTS->setValue(20);
        horizontalSliderTS->setOrientation(Qt::Horizontal);
        horizontalSliderTS->setTickPosition(QSlider::TicksBelow);
        horizontalSliderTS->setTickInterval(10);

        horizontalLayout_10->addWidget(horizontalSliderTS);

        labelThresholdS = new QLabel(layoutWidget1);
        labelThresholdS->setObjectName(QString::fromUtf8("labelThresholdS"));
        sizePolicy6.setHeightForWidth(labelThresholdS->sizePolicy().hasHeightForWidth());
        labelThresholdS->setSizePolicy(sizePolicy6);
        labelThresholdS->setMinimumSize(QSize(30, 0));
        labelThresholdS->setFrameShape(QFrame::StyledPanel);
        labelThresholdS->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_10->addWidget(labelThresholdS);


        verticalLayout_4->addLayout(horizontalLayout_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        label_ThresholdV = new QLabel(layoutWidget1);
        label_ThresholdV->setObjectName(QString::fromUtf8("label_ThresholdV"));

        horizontalLayout_11->addWidget(label_ThresholdV);

        horizontalSliderTV = new QSlider(layoutWidget1);
        horizontalSliderTV->setObjectName(QString::fromUtf8("horizontalSliderTV"));
        horizontalSliderTV->setEnabled(true);
        horizontalSliderTV->setMaximum(200);
        horizontalSliderTV->setValue(50);
        horizontalSliderTV->setOrientation(Qt::Horizontal);
        horizontalSliderTV->setTickPosition(QSlider::TicksBelow);
        horizontalSliderTV->setTickInterval(10);

        horizontalLayout_11->addWidget(horizontalSliderTV);

        labelThresholdV = new QLabel(layoutWidget1);
        labelThresholdV->setObjectName(QString::fromUtf8("labelThresholdV"));
        sizePolicy6.setHeightForWidth(labelThresholdV->sizePolicy().hasHeightForWidth());
        labelThresholdV->setSizePolicy(sizePolicy6);
        labelThresholdV->setMinimumSize(QSize(30, 0));
        labelThresholdV->setFrameShape(QFrame::StyledPanel);
        labelThresholdV->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_11->addWidget(labelThresholdV);


        verticalLayout_4->addLayout(horizontalLayout_11);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_ColorLevels = new QLabel(layoutWidget1);
        label_ColorLevels->setObjectName(QString::fromUtf8("label_ColorLevels"));

        horizontalLayout->addWidget(label_ColorLevels);

        horizontalSlider_colorLevels = new QSlider(layoutWidget1);
        horizontalSlider_colorLevels->setObjectName(QString::fromUtf8("horizontalSlider_colorLevels"));
        horizontalSlider_colorLevels->setMinimum(1);
        horizontalSlider_colorLevels->setMaximum(10);
        horizontalSlider_colorLevels->setValue(3);
        horizontalSlider_colorLevels->setOrientation(Qt::Horizontal);
        horizontalSlider_colorLevels->setTickPosition(QSlider::TicksBelow);
        horizontalSlider_colorLevels->setTickInterval(1);

        horizontalLayout->addWidget(horizontalSlider_colorLevels);

        labelColorLevels = new QLabel(layoutWidget1);
        labelColorLevels->setObjectName(QString::fromUtf8("labelColorLevels"));
        sizePolicy6.setHeightForWidth(labelColorLevels->sizePolicy().hasHeightForWidth());
        labelColorLevels->setSizePolicy(sizePolicy6);
        labelColorLevels->setMinimumSize(QSize(30, 0));
        labelColorLevels->setFrameShape(QFrame::StyledPanel);
        labelColorLevels->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(labelColorLevels);


        verticalLayout_4->addLayout(horizontalLayout);


        verticalLayout_5->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(layoutWidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        sizePolicy4.setHeightForWidth(groupBox_3->sizePolicy().hasHeightForWidth());
        groupBox_3->setSizePolicy(sizePolicy4);
        groupBox_3->setMinimumSize(QSize(441, 300));
        groupBox_3->setMaximumSize(QSize(441, 16777215));
        splitter = new QSplitter(groupBox_3);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setGeometry(QRect(10, 20, 411, 261));
        splitter->setOrientation(Qt::Vertical);
        widget = new QWidget(splitter);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout_12 = new QHBoxLayout(widget);
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        horizontalLayout_12->setContentsMargins(0, 0, 0, 0);
        label_reconColors = new QLabel(widget);
        label_reconColors->setObjectName(QString::fromUtf8("label_reconColors"));

        horizontalLayout_12->addWidget(label_reconColors);

        comboBox_reconColors = new QComboBox(widget);
        comboBox_reconColors->setObjectName(QString::fromUtf8("comboBox_reconColors"));
        QSizePolicy sizePolicy7(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(comboBox_reconColors->sizePolicy().hasHeightForWidth());
        comboBox_reconColors->setSizePolicy(sizePolicy7);
        comboBox_reconColors->setMinimumSize(QSize(80, 0));
        comboBox_reconColors->setMaximumSize(QSize(80, 16777215));

        horizontalLayout_12->addWidget(comboBox_reconColors);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_4);

        splitter->addWidget(widget);
        widget1 = new QWidget(splitter);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        gridLayout_5 = new QGridLayout(widget1);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        groupBox_v1 = new QGroupBox(widget1);
        groupBox_v1->setObjectName(QString::fromUtf8("groupBox_v1"));
        QSizePolicy sizePolicy8(QSizePolicy::Fixed, QSizePolicy::MinimumExpanding);
        sizePolicy8.setHorizontalStretch(0);
        sizePolicy8.setVerticalStretch(0);
        sizePolicy8.setHeightForWidth(groupBox_v1->sizePolicy().hasHeightForWidth());
        groupBox_v1->setSizePolicy(sizePolicy8);
        groupBox_v1->setMinimumSize(QSize(179, 83));
        gridLayout_6 = new QGridLayout(groupBox_v1);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        label_v1Composer = new QLabel(groupBox_v1);
        label_v1Composer->setObjectName(QString::fromUtf8("label_v1Composer"));

        gridLayout_6->addWidget(label_v1Composer, 0, 0, 1, 1);

        comboBox_v1Composer = new QComboBox(groupBox_v1);
        comboBox_v1Composer->setObjectName(QString::fromUtf8("comboBox_v1Composer"));

        gridLayout_6->addWidget(comboBox_v1Composer, 0, 1, 1, 1);

        label_v1Instrument = new QLabel(groupBox_v1);
        label_v1Instrument->setObjectName(QString::fromUtf8("label_v1Instrument"));

        gridLayout_6->addWidget(label_v1Instrument, 1, 0, 1, 1);

        comboBox_v1Instrument = new QComboBox(groupBox_v1);
        comboBox_v1Instrument->setObjectName(QString::fromUtf8("comboBox_v1Instrument"));

        gridLayout_6->addWidget(comboBox_v1Instrument, 1, 1, 1, 1);


        gridLayout_5->addWidget(groupBox_v1, 0, 0, 1, 1);

        groupBox_v2 = new QGroupBox(widget1);
        groupBox_v2->setObjectName(QString::fromUtf8("groupBox_v2"));
        sizePolicy8.setHeightForWidth(groupBox_v2->sizePolicy().hasHeightForWidth());
        groupBox_v2->setSizePolicy(sizePolicy8);
        groupBox_v2->setMinimumSize(QSize(179, 83));
        gridLayout_8 = new QGridLayout(groupBox_v2);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        label_v2Composer = new QLabel(groupBox_v2);
        label_v2Composer->setObjectName(QString::fromUtf8("label_v2Composer"));

        gridLayout_8->addWidget(label_v2Composer, 0, 0, 1, 1);

        comboBox_v2Composer = new QComboBox(groupBox_v2);
        comboBox_v2Composer->setObjectName(QString::fromUtf8("comboBox_v2Composer"));

        gridLayout_8->addWidget(comboBox_v2Composer, 0, 1, 1, 1);

        label_v2Instrument = new QLabel(groupBox_v2);
        label_v2Instrument->setObjectName(QString::fromUtf8("label_v2Instrument"));

        gridLayout_8->addWidget(label_v2Instrument, 1, 0, 1, 1);

        comboBox_v2Instruments = new QComboBox(groupBox_v2);
        comboBox_v2Instruments->setObjectName(QString::fromUtf8("comboBox_v2Instruments"));

        gridLayout_8->addWidget(comboBox_v2Instruments, 1, 1, 1, 1);


        gridLayout_5->addWidget(groupBox_v2, 0, 1, 1, 1);

        groupBox_v3 = new QGroupBox(widget1);
        groupBox_v3->setObjectName(QString::fromUtf8("groupBox_v3"));
        sizePolicy8.setHeightForWidth(groupBox_v3->sizePolicy().hasHeightForWidth());
        groupBox_v3->setSizePolicy(sizePolicy8);
        groupBox_v3->setMinimumSize(QSize(179, 83));
        gridLayout_7 = new QGridLayout(groupBox_v3);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        label_v3Composer = new QLabel(groupBox_v3);
        label_v3Composer->setObjectName(QString::fromUtf8("label_v3Composer"));

        gridLayout_7->addWidget(label_v3Composer, 0, 0, 1, 1);

        comboBox_v3Composer = new QComboBox(groupBox_v3);
        comboBox_v3Composer->setObjectName(QString::fromUtf8("comboBox_v3Composer"));

        gridLayout_7->addWidget(comboBox_v3Composer, 0, 1, 1, 1);

        label_v3Instrument = new QLabel(groupBox_v3);
        label_v3Instrument->setObjectName(QString::fromUtf8("label_v3Instrument"));

        gridLayout_7->addWidget(label_v3Instrument, 1, 0, 1, 1);

        comboBox_v3Instrument = new QComboBox(groupBox_v3);
        comboBox_v3Instrument->setObjectName(QString::fromUtf8("comboBox_v3Instrument"));

        gridLayout_7->addWidget(comboBox_v3Instrument, 1, 1, 1, 1);


        gridLayout_5->addWidget(groupBox_v3, 1, 0, 1, 1);

        groupBox_v4 = new QGroupBox(widget1);
        groupBox_v4->setObjectName(QString::fromUtf8("groupBox_v4"));
        sizePolicy8.setHeightForWidth(groupBox_v4->sizePolicy().hasHeightForWidth());
        groupBox_v4->setSizePolicy(sizePolicy8);
        groupBox_v4->setMinimumSize(QSize(179, 83));
        gridLayout_9 = new QGridLayout(groupBox_v4);
        gridLayout_9->setSpacing(6);
        gridLayout_9->setContentsMargins(11, 11, 11, 11);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        label_v4Composer = new QLabel(groupBox_v4);
        label_v4Composer->setObjectName(QString::fromUtf8("label_v4Composer"));

        gridLayout_9->addWidget(label_v4Composer, 0, 0, 1, 1);

        comboBox_v4Composer = new QComboBox(groupBox_v4);
        comboBox_v4Composer->setObjectName(QString::fromUtf8("comboBox_v4Composer"));

        gridLayout_9->addWidget(comboBox_v4Composer, 0, 1, 1, 1);

        label_v4Instrument = new QLabel(groupBox_v4);
        label_v4Instrument->setObjectName(QString::fromUtf8("label_v4Instrument"));

        gridLayout_9->addWidget(label_v4Instrument, 1, 0, 1, 1);

        comboBox_v4Instrument = new QComboBox(groupBox_v4);
        comboBox_v4Instrument->setObjectName(QString::fromUtf8("comboBox_v4Instrument"));

        gridLayout_9->addWidget(comboBox_v4Instrument, 1, 1, 1, 1);


        gridLayout_5->addWidget(groupBox_v4, 1, 1, 1, 1);

        splitter->addWidget(widget1);
        widget2 = new QWidget(splitter);
        widget2->setObjectName(QString::fromUtf8("widget2"));
        horizontalLayout_13 = new QHBoxLayout(widget2);
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        horizontalLayout_13->setContentsMargins(0, 0, 0, 0);
        label_composerMix = new QLabel(widget2);
        label_composerMix->setObjectName(QString::fromUtf8("label_composerMix"));
        label_composerMix->setMinimumSize(QSize(80, 0));
        label_composerMix->setMaximumSize(QSize(80, 16777215));

        horizontalLayout_13->addWidget(label_composerMix);

        comboBox_composerMixer = new QComboBox(widget2);
        comboBox_composerMixer->setObjectName(QString::fromUtf8("comboBox_composerMixer"));

        horizontalLayout_13->addWidget(comboBox_composerMixer);

        horizontalSpacer_2 = new QSpacerItem(55, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_2);

        label_tempo = new QLabel(widget2);
        label_tempo->setObjectName(QString::fromUtf8("label_tempo"));
        sizePolicy5.setHeightForWidth(label_tempo->sizePolicy().hasHeightForWidth());
        label_tempo->setSizePolicy(sizePolicy5);
        label_tempo->setMinimumSize(QSize(40, 0));
        label_tempo->setMaximumSize(QSize(40, 16777215));
        label_tempo->setBaseSize(QSize(0, 0));

        horizontalLayout_13->addWidget(label_tempo);

        comboBox_v3Composer_3 = new QComboBox(widget2);
        comboBox_v3Composer_3->setObjectName(QString::fromUtf8("comboBox_v3Composer_3"));
        sizePolicy7.setHeightForWidth(comboBox_v3Composer_3->sizePolicy().hasHeightForWidth());
        comboBox_v3Composer_3->setSizePolicy(sizePolicy7);
        comboBox_v3Composer_3->setMinimumSize(QSize(40, 0));
        comboBox_v3Composer_3->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_13->addWidget(comboBox_v3Composer_3);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_6);

        splitter->addWidget(widget2);
        label_reconColors->raise();
        comboBox_reconColors->raise();
        groupBox_v2->raise();
        groupBox_v2->raise();
        groupBox_v1->raise();
        groupBox_v3->raise();
        groupBox_v4->raise();
        label_composerMix->raise();
        comboBox_composerMixer->raise();
        label_tempo->raise();
        comboBox_v3Composer_3->raise();

        verticalLayout_5->addWidget(groupBox_3);


        gridLayout_3->addLayout(verticalLayout_5, 1, 2, 1, 1);

        GuiMupic->setCentralWidget(centralWidget);
        layoutWidget->raise();
        groupBox_3->raise();
        statusBar = new QStatusBar(GuiMupic);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        GuiMupic->setStatusBar(statusBar);

        retranslateUi(GuiMupic);

        filterSelComboBox->setCurrentIndex(3);
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


        QMetaObject::connectSlotsByName(GuiMupic);
    } // setupUi

    void retranslateUi(QMainWindow *GuiMupic)
    {
        GuiMupic->setWindowTitle(QApplication::translate("GuiMupic", "GuiMupic", 0, QApplication::UnicodeUTF8));
        label_InputPic->setText(QApplication::translate("GuiMupic", "   Input Pic  ", 0, QApplication::UnicodeUTF8));
        lineEdit_InputPic->setText(QApplication::translate("GuiMupic", "./test1.png", 0, QApplication::UnicodeUTF8));
        toolButton_InputPic->setText(QApplication::translate("GuiMupic", "...", 0, QApplication::UnicodeUTF8));
        label_OutputMidi->setText(QApplication::translate("GuiMupic", " Output Midi", 0, QApplication::UnicodeUTF8));
        toolButton_OutputMidi->setText(QApplication::translate("GuiMupic", "...", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QApplication::translate("GuiMupic", "Input Image", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("GuiMupic", "Analysis output", 0, QApplication::UnicodeUTF8));
        pushButton_Analyze->setText(QApplication::translate("GuiMupic", "Analyze", 0, QApplication::UnicodeUTF8));
        pushButton_Generate->setText(QApplication::translate("GuiMupic", "Compose", 0, QApplication::UnicodeUTF8));
        pushButton_Play->setText(QString());
        pushButton_pause->setText(QApplication::translate("GuiMupic", "Pause", 0, QApplication::UnicodeUTF8));
        pushButton_Stop->setText(QString());
        groupBox_2->setTitle(QApplication::translate("GuiMupic", "Phic Options", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("GuiMupic", "Filter", 0, QApplication::UnicodeUTF8));
        filterSelComboBox->clear();
        filterSelComboBox->insertItems(0, QStringList()
         << QApplication::translate("GuiMupic", "Threshold", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("GuiMupic", "Adaptative Threshold", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("GuiMupic", "Canny", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("GuiMupic", "Hue Division", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("GuiMupic", "Multiple Threshold", 0, QApplication::UnicodeUTF8)
        );
        label_4->setText(QApplication::translate("GuiMupic", "Noise Selection", 0, QApplication::UnicodeUTF8));
        noiseLabel->setText(QApplication::translate("GuiMupic", "0.0", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("GuiMupic", "Polygon Simplification", 0, QApplication::UnicodeUTF8));
        labelPolSimp->setText(QApplication::translate("GuiMupic", "2", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("GuiMupic", "Threshold", 0, QApplication::UnicodeUTF8));
        tLabel->setText(QApplication::translate("GuiMupic", "50", 0, QApplication::UnicodeUTF8));
        label_ThresholdH->setText(QApplication::translate("GuiMupic", "Threshold H", 0, QApplication::UnicodeUTF8));
        labelThresholdH->setText(QApplication::translate("GuiMupic", "35", 0, QApplication::UnicodeUTF8));
        label_ThresholdS->setText(QApplication::translate("GuiMupic", "Threshold S", 0, QApplication::UnicodeUTF8));
        labelThresholdS->setText(QApplication::translate("GuiMupic", "20", 0, QApplication::UnicodeUTF8));
        label_ThresholdV->setText(QApplication::translate("GuiMupic", "Threshold V", 0, QApplication::UnicodeUTF8));
        labelThresholdV->setText(QApplication::translate("GuiMupic", "50", 0, QApplication::UnicodeUTF8));
        label_ColorLevels->setText(QApplication::translate("GuiMupic", "Color levels", 0, QApplication::UnicodeUTF8));
        labelColorLevels->setText(QApplication::translate("GuiMupic", "3", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("GuiMupic", "Mu Options", 0, QApplication::UnicodeUTF8));
        label_reconColors->setText(QApplication::translate("GuiMupic", "Color System", 0, QApplication::UnicodeUTF8));
        comboBox_reconColors->clear();
        comboBox_reconColors->insertItems(0, QStringList()
         << QApplication::translate("GuiMupic", "Demo1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("GuiMupic", "Demo2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("GuiMupic", "Scriabin", 0, QApplication::UnicodeUTF8)
        );
        groupBox_v1->setTitle(QApplication::translate("GuiMupic", "Voice 1", 0, QApplication::UnicodeUTF8));
        label_v1Composer->setText(QApplication::translate("GuiMupic", "Composer", 0, QApplication::UnicodeUTF8));
        comboBox_v1Composer->clear();
        comboBox_v1Composer->insertItems(0, QStringList()
         << QApplication::translate("GuiMupic", "Demo1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("GuiMupic", "Demo2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("GuiMupic", "FigMelody2", 0, QApplication::UnicodeUTF8)
        );
        label_v1Instrument->setText(QApplication::translate("GuiMupic", "Instrument", 0, QApplication::UnicodeUTF8));
        comboBox_v1Instrument->clear();
        comboBox_v1Instrument->insertItems(0, QStringList()
         << QApplication::translate("GuiMupic", "Strings", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("GuiMupic", "Flute", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("GuiMupic", "Electric Bass", 0, QApplication::UnicodeUTF8)
        );
        groupBox_v2->setTitle(QApplication::translate("GuiMupic", "Voice 2", 0, QApplication::UnicodeUTF8));
        label_v2Composer->setText(QApplication::translate("GuiMupic", "Composer", 0, QApplication::UnicodeUTF8));
        comboBox_v2Composer->clear();
        comboBox_v2Composer->insertItems(0, QStringList()
         << QApplication::translate("GuiMupic", "Demo1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("GuiMupic", "Demo2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("GuiMupic", "FigMelody2", 0, QApplication::UnicodeUTF8)
        );
        label_v2Instrument->setText(QApplication::translate("GuiMupic", "Instrument", 0, QApplication::UnicodeUTF8));
        comboBox_v2Instruments->clear();
        comboBox_v2Instruments->insertItems(0, QStringList()
         << QApplication::translate("GuiMupic", "Strings", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("GuiMupic", "Flute", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("GuiMupic", "Electric Bass", 0, QApplication::UnicodeUTF8)
        );
        groupBox_v3->setTitle(QApplication::translate("GuiMupic", "Voice 3", 0, QApplication::UnicodeUTF8));
        label_v3Composer->setText(QApplication::translate("GuiMupic", "Composer", 0, QApplication::UnicodeUTF8));
        comboBox_v3Composer->clear();
        comboBox_v3Composer->insertItems(0, QStringList()
         << QApplication::translate("GuiMupic", "Demo1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("GuiMupic", "Demo2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("GuiMupic", "FigBass2", 0, QApplication::UnicodeUTF8)
        );
        label_v3Instrument->setText(QApplication::translate("GuiMupic", "Instrument", 0, QApplication::UnicodeUTF8));
        comboBox_v3Instrument->clear();
        comboBox_v3Instrument->insertItems(0, QStringList()
         << QApplication::translate("GuiMupic", "Strings", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("GuiMupic", "Flute", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("GuiMupic", "Electric Bass", 0, QApplication::UnicodeUTF8)
        );
        groupBox_v4->setTitle(QApplication::translate("GuiMupic", "Voice 4", 0, QApplication::UnicodeUTF8));
        label_v4Composer->setText(QApplication::translate("GuiMupic", "Composer", 0, QApplication::UnicodeUTF8));
        comboBox_v4Composer->clear();
        comboBox_v4Composer->insertItems(0, QStringList()
         << QApplication::translate("GuiMupic", "Demo1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("GuiMupic", "Demo2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("GuiMupic", "FigRithm2", 0, QApplication::UnicodeUTF8)
        );
        label_v4Instrument->setText(QApplication::translate("GuiMupic", "Instrument", 0, QApplication::UnicodeUTF8));
        comboBox_v4Instrument->clear();
        comboBox_v4Instrument->insertItems(0, QStringList()
         << QApplication::translate("GuiMupic", "Demo1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("GuiMupic", "Demo2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("GuiMupic", "Drums & Clanks", 0, QApplication::UnicodeUTF8)
        );
        label_composerMix->setText(QApplication::translate("GuiMupic", "Composer Mixer", 0, QApplication::UnicodeUTF8));
        comboBox_composerMixer->clear();
        comboBox_composerMixer->insertItems(0, QStringList()
         << QApplication::translate("GuiMupic", "Demo1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("GuiMupic", "Demo2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("GuiMupic", "Timothy2", 0, QApplication::UnicodeUTF8)
        );
        label_tempo->setText(QApplication::translate("GuiMupic", "Tempo", 0, QApplication::UnicodeUTF8));
        comboBox_v3Composer_3->clear();
        comboBox_v3Composer_3->insertItems(0, QStringList()
         << QApplication::translate("GuiMupic", "1/4", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("GuiMupic", "2/4", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("GuiMupic", "3/4", 0, QApplication::UnicodeUTF8)
        );
    } // retranslateUi

};

namespace Ui {
    class GuiMupic: public Ui_GuiMupic {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUIMUPIC_H
