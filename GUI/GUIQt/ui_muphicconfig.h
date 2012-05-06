/********************************************************************************
** Form generated from reading UI file 'muphicconfig.ui'
**
** Created: Sun 6. May 15:44:18 2012
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
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QSlider>
#include <QtGui/QSpacerItem>
#include <QtGui/QSplitter>
#include <QtGui/QTabWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MuphicConfig
{
public:
    QWidget *tab1;
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
    QGroupBox *groupBox_3;
    QSplitter *splitter;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_reconColors;
    QComboBox *comboBox_reconColors;
    QSpacerItem *horizontalSpacer_4;
    QWidget *layoutWidget_3;
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
    QWidget *layoutWidget_4;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_composerMix;
    QComboBox *comboBox_composerMixer;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_tempo;
    QComboBox *comboBox_v3Composer_3;
    QSpacerItem *horizontalSpacer_6;

    void setupUi(QTabWidget *MuphicConfig)
    {
        if (MuphicConfig->objectName().isEmpty())
            MuphicConfig->setObjectName(QString::fromUtf8("MuphicConfig"));
        MuphicConfig->resize(482, 349);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MuphicConfig->sizePolicy().hasHeightForWidth());
        MuphicConfig->setSizePolicy(sizePolicy);
        MuphicConfig->setMinimumSize(QSize(482, 349));
        MuphicConfig->setMaximumSize(QSize(482, 349));
        tab1 = new QWidget();
        tab1->setObjectName(QString::fromUtf8("tab1"));
        groupBox_2 = new QGroupBox(tab1);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 10, 441, 261));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(1);
        sizePolicy1.setVerticalStretch(1);
        sizePolicy1.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy1);
        groupBox_2->setMinimumSize(QSize(441, 240));
        groupBox_2->setMaximumSize(QSize(16777215, 16777215));
        groupBox_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        gridLayout = new QGridLayout(groupBox_2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy2);

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
        sizePolicy.setHeightForWidth(noiseLabel->sizePolicy().hasHeightForWidth());
        noiseLabel->setSizePolicy(sizePolicy);
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
        sizePolicy2.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy2);

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
        sizePolicy.setHeightForWidth(labelPolSimp->sizePolicy().hasHeightForWidth());
        labelPolSimp->setSizePolicy(sizePolicy);
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
        sizePolicy.setHeightForWidth(tLabel->sizePolicy().hasHeightForWidth());
        tLabel->setSizePolicy(sizePolicy);
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
        sizePolicy.setHeightForWidth(labelThresholdH->sizePolicy().hasHeightForWidth());
        labelThresholdH->setSizePolicy(sizePolicy);
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
        sizePolicy.setHeightForWidth(labelThresholdS->sizePolicy().hasHeightForWidth());
        labelThresholdS->setSizePolicy(sizePolicy);
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
        sizePolicy.setHeightForWidth(labelThresholdV->sizePolicy().hasHeightForWidth());
        labelThresholdV->setSizePolicy(sizePolicy);
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
        sizePolicy.setHeightForWidth(labelColorLevels->sizePolicy().hasHeightForWidth());
        labelColorLevels->setSizePolicy(sizePolicy);
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
        sizePolicy.setHeightForWidth(labelAnalysisDepth->sizePolicy().hasHeightForWidth());
        labelAnalysisDepth->setSizePolicy(sizePolicy);
        labelAnalysisDepth->setMinimumSize(QSize(30, 0));
        labelAnalysisDepth->setFrameShape(QFrame::StyledPanel);
        labelAnalysisDepth->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(labelAnalysisDepth);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 1);

        MuphicConfig->addTab(tab1, QString());
        tab2 = new QWidget();
        tab2->setObjectName(QString::fromUtf8("tab2"));
        groupBox_3 = new QGroupBox(tab2);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(20, 10, 441, 300));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(groupBox_3->sizePolicy().hasHeightForWidth());
        groupBox_3->setSizePolicy(sizePolicy3);
        groupBox_3->setMinimumSize(QSize(441, 300));
        groupBox_3->setMaximumSize(QSize(441, 16777215));
        splitter = new QSplitter(groupBox_3);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setGeometry(QRect(10, 20, 411, 261));
        splitter->setOrientation(Qt::Vertical);
        layoutWidget_2 = new QWidget(splitter);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        horizontalLayout_12 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        horizontalLayout_12->setContentsMargins(0, 0, 0, 0);
        label_reconColors = new QLabel(layoutWidget_2);
        label_reconColors->setObjectName(QString::fromUtf8("label_reconColors"));

        horizontalLayout_12->addWidget(label_reconColors);

        comboBox_reconColors = new QComboBox(layoutWidget_2);
        comboBox_reconColors->setObjectName(QString::fromUtf8("comboBox_reconColors"));
        QSizePolicy sizePolicy4(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(comboBox_reconColors->sizePolicy().hasHeightForWidth());
        comboBox_reconColors->setSizePolicy(sizePolicy4);
        comboBox_reconColors->setMinimumSize(QSize(80, 0));
        comboBox_reconColors->setMaximumSize(QSize(80, 16777215));

        horizontalLayout_12->addWidget(comboBox_reconColors);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_4);

        splitter->addWidget(layoutWidget_2);
        layoutWidget_3 = new QWidget(splitter);
        layoutWidget_3->setObjectName(QString::fromUtf8("layoutWidget_3"));
        gridLayout_5 = new QGridLayout(layoutWidget_3);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        groupBox_v1 = new QGroupBox(layoutWidget_3);
        groupBox_v1->setObjectName(QString::fromUtf8("groupBox_v1"));
        QSizePolicy sizePolicy5(QSizePolicy::Fixed, QSizePolicy::MinimumExpanding);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(groupBox_v1->sizePolicy().hasHeightForWidth());
        groupBox_v1->setSizePolicy(sizePolicy5);
        groupBox_v1->setMinimumSize(QSize(179, 83));
        gridLayout_6 = new QGridLayout(groupBox_v1);
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

        groupBox_v2 = new QGroupBox(layoutWidget_3);
        groupBox_v2->setObjectName(QString::fromUtf8("groupBox_v2"));
        sizePolicy5.setHeightForWidth(groupBox_v2->sizePolicy().hasHeightForWidth());
        groupBox_v2->setSizePolicy(sizePolicy5);
        groupBox_v2->setMinimumSize(QSize(179, 83));
        gridLayout_8 = new QGridLayout(groupBox_v2);
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

        groupBox_v3 = new QGroupBox(layoutWidget_3);
        groupBox_v3->setObjectName(QString::fromUtf8("groupBox_v3"));
        sizePolicy5.setHeightForWidth(groupBox_v3->sizePolicy().hasHeightForWidth());
        groupBox_v3->setSizePolicy(sizePolicy5);
        groupBox_v3->setMinimumSize(QSize(179, 83));
        gridLayout_7 = new QGridLayout(groupBox_v3);
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

        groupBox_v4 = new QGroupBox(layoutWidget_3);
        groupBox_v4->setObjectName(QString::fromUtf8("groupBox_v4"));
        sizePolicy5.setHeightForWidth(groupBox_v4->sizePolicy().hasHeightForWidth());
        groupBox_v4->setSizePolicy(sizePolicy5);
        groupBox_v4->setMinimumSize(QSize(179, 83));
        gridLayout_9 = new QGridLayout(groupBox_v4);
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

        splitter->addWidget(layoutWidget_3);
        layoutWidget_4 = new QWidget(splitter);
        layoutWidget_4->setObjectName(QString::fromUtf8("layoutWidget_4"));
        horizontalLayout_13 = new QHBoxLayout(layoutWidget_4);
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        horizontalLayout_13->setContentsMargins(0, 0, 0, 0);
        label_composerMix = new QLabel(layoutWidget_4);
        label_composerMix->setObjectName(QString::fromUtf8("label_composerMix"));
        label_composerMix->setMinimumSize(QSize(80, 0));
        label_composerMix->setMaximumSize(QSize(80, 16777215));

        horizontalLayout_13->addWidget(label_composerMix);

        comboBox_composerMixer = new QComboBox(layoutWidget_4);
        comboBox_composerMixer->setObjectName(QString::fromUtf8("comboBox_composerMixer"));

        horizontalLayout_13->addWidget(comboBox_composerMixer);

        horizontalSpacer_2 = new QSpacerItem(55, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_2);

        label_tempo = new QLabel(layoutWidget_4);
        label_tempo->setObjectName(QString::fromUtf8("label_tempo"));
        sizePolicy2.setHeightForWidth(label_tempo->sizePolicy().hasHeightForWidth());
        label_tempo->setSizePolicy(sizePolicy2);
        label_tempo->setMinimumSize(QSize(40, 0));
        label_tempo->setMaximumSize(QSize(40, 16777215));
        label_tempo->setBaseSize(QSize(0, 0));

        horizontalLayout_13->addWidget(label_tempo);

        comboBox_v3Composer_3 = new QComboBox(layoutWidget_4);
        comboBox_v3Composer_3->setObjectName(QString::fromUtf8("comboBox_v3Composer_3"));
        sizePolicy4.setHeightForWidth(comboBox_v3Composer_3->sizePolicy().hasHeightForWidth());
        comboBox_v3Composer_3->setSizePolicy(sizePolicy4);
        comboBox_v3Composer_3->setMinimumSize(QSize(40, 0));
        comboBox_v3Composer_3->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_13->addWidget(comboBox_v3Composer_3);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_6);

        splitter->addWidget(layoutWidget_4);
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
