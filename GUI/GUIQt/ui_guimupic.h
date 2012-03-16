/********************************************************************************
** Form generated from reading UI file 'guimupic.ui'
**
** Created: Fri 16. Mar 10:36:40 2012
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
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QScrollArea>
#include <QtGui/QSlider>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QTextEdit>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "polygonwidget.h"

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
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_2;
    QSlider *horizontalSlider_2;
    QLabel *tLabel;
    QSpacerItem *horizontalSpacer_6;
    QGroupBox *groupBox_3;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_12;
    QLabel *labelComposer;
    QComboBox *comboBox;
    QSpacerItem *horizontalSpacer_12;
    QHBoxLayout *horizontalLayout_13;
    QLabel *labelInstruments;
    QComboBox *comboBox_2;
    QSpacerItem *horizontalSpacer_13;
    QHBoxLayout *horizontalLayout_14;
    QLabel *labelName;
    QTextEdit *textEdit;
    QSpacerItem *horizontalSpacer_2;
    QLabel *labelOutput;
    QComboBox *comboBox_3;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *horizontalSpacer_3;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_Analyze;
    QPushButton *pushButton_Generate;
    QProgressBar *progressBar_Generate;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_Play;
    QPushButton *pushButton_Stop;
    QSlider *horizontalSlider;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *verticalSpacer_2;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *GuiMupic)
    {
        if (GuiMupic->objectName().isEmpty())
            GuiMupic->setObjectName(QString::fromUtf8("GuiMupic"));
        GuiMupic->resize(1148, 430);
        centralWidget = new QWidget(GuiMupic);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 1036, 393));
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
        polyWidget->setGeometry(QRect(0, 0, 217, 217));
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

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setSizeConstraint(QLayout::SetFixedSize);
        groupBox_2 = new QGroupBox(layoutWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy2);
        groupBox_2->setMinimumSize(QSize(441, 128));
        groupBox_2->setMaximumSize(QSize(441, 128));
        layoutWidget1 = new QWidget(groupBox_2);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(11, 24, 412, 92));
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
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy3);

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
        horizontalSlider_3->setValue(1);
        horizontalSlider_3->setOrientation(Qt::Horizontal);
        horizontalSlider_3->setTickPosition(QSlider::TicksBelow);
        horizontalSlider_3->setTickInterval(10);

        horizontalLayout_6->addWidget(horizontalSlider_3);

        noiseLabel = new QLabel(layoutWidget1);
        noiseLabel->setObjectName(QString::fromUtf8("noiseLabel"));
        QSizePolicy sizePolicy4(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(noiseLabel->sizePolicy().hasHeightForWidth());
        noiseLabel->setSizePolicy(sizePolicy4);
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
        sizePolicy3.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy3);

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
        sizePolicy4.setHeightForWidth(labelPolSimp->sizePolicy().hasHeightForWidth());
        labelPolSimp->setSizePolicy(sizePolicy4);
        labelPolSimp->setMinimumSize(QSize(30, 0));
        labelPolSimp->setMaximumSize(QSize(30, 16777215));
        labelPolSimp->setFrameShape(QFrame::StyledPanel);
        labelPolSimp->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_7->addWidget(labelPolSimp);

        horizontalSpacer_4 = new QSpacerItem(5, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_4);


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
        sizePolicy4.setHeightForWidth(tLabel->sizePolicy().hasHeightForWidth());
        tLabel->setSizePolicy(sizePolicy4);
        tLabel->setMinimumSize(QSize(30, 0));
        tLabel->setMaximumSize(QSize(30, 16777215));
        tLabel->setFrameShape(QFrame::StyledPanel);
        tLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_8->addWidget(tLabel);

        horizontalSpacer_6 = new QSpacerItem(5, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_6);


        verticalLayout_4->addLayout(horizontalLayout_8);


        verticalLayout_5->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(layoutWidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        sizePolicy.setHeightForWidth(groupBox_3->sizePolicy().hasHeightForWidth());
        groupBox_3->setSizePolicy(sizePolicy);
        groupBox_3->setMinimumSize(QSize(441, 128));
        groupBox_3->setMaximumSize(QSize(441, 128));
        layoutWidget2 = new QWidget(groupBox_3);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(10, 23, 421, 80));
        verticalLayout_3 = new QVBoxLayout(layoutWidget2);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        labelComposer = new QLabel(layoutWidget2);
        labelComposer->setObjectName(QString::fromUtf8("labelComposer"));

        horizontalLayout_12->addWidget(labelComposer);

        comboBox = new QComboBox(layoutWidget2);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setEnabled(false);

        horizontalLayout_12->addWidget(comboBox);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_12);


        verticalLayout_3->addLayout(horizontalLayout_12);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        labelInstruments = new QLabel(layoutWidget2);
        labelInstruments->setObjectName(QString::fromUtf8("labelInstruments"));

        horizontalLayout_13->addWidget(labelInstruments);

        comboBox_2 = new QComboBox(layoutWidget2);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setEnabled(false);

        horizontalLayout_13->addWidget(comboBox_2);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_13);


        verticalLayout_3->addLayout(horizontalLayout_13);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        labelName = new QLabel(layoutWidget2);
        labelName->setObjectName(QString::fromUtf8("labelName"));

        horizontalLayout_14->addWidget(labelName);

        textEdit = new QTextEdit(layoutWidget2);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setEnabled(false);
        QSizePolicy sizePolicy5(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(textEdit->sizePolicy().hasHeightForWidth());
        textEdit->setSizePolicy(sizePolicy5);
        textEdit->setMaximumSize(QSize(16777215, 20));
        textEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textEdit->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);

        horizontalLayout_14->addWidget(textEdit);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_2);

        labelOutput = new QLabel(layoutWidget2);
        labelOutput->setObjectName(QString::fromUtf8("labelOutput"));

        horizontalLayout_14->addWidget(labelOutput);

        comboBox_3 = new QComboBox(layoutWidget2);
        comboBox_3->setObjectName(QString::fromUtf8("comboBox_3"));
        comboBox_3->setEnabled(false);

        horizontalLayout_14->addWidget(comboBox_3);


        verticalLayout_3->addLayout(horizontalLayout_14);


        verticalLayout_5->addWidget(groupBox_3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer);


        gridLayout_3->addLayout(verticalLayout_5, 1, 2, 1, 1);

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
        sizePolicy5.setHeightForWidth(pushButton_Analyze->sizePolicy().hasHeightForWidth());
        pushButton_Analyze->setSizePolicy(sizePolicy5);
        pushButton_Analyze->setMaximumSize(QSize(150, 16777215));

        horizontalLayout_2->addWidget(pushButton_Analyze);

        pushButton_Generate = new QPushButton(layoutWidget);
        pushButton_Generate->setObjectName(QString::fromUtf8("pushButton_Generate"));
        sizePolicy5.setHeightForWidth(pushButton_Generate->sizePolicy().hasHeightForWidth());
        pushButton_Generate->setSizePolicy(sizePolicy5);
        pushButton_Generate->setMaximumSize(QSize(150, 16777215));

        horizontalLayout_2->addWidget(pushButton_Generate);

        progressBar_Generate = new QProgressBar(layoutWidget);
        progressBar_Generate->setObjectName(QString::fromUtf8("progressBar_Generate"));
        progressBar_Generate->setValue(0);

        horizontalLayout_2->addWidget(progressBar_Generate);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton_Play = new QPushButton(layoutWidget);
        pushButton_Play->setObjectName(QString::fromUtf8("pushButton_Play"));
        QIcon icon;
        icon.addFile(QString::fromUtf8("play.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_Play->setIcon(icon);

        horizontalLayout->addWidget(pushButton_Play);

        pushButton_Stop = new QPushButton(layoutWidget);
        pushButton_Stop->setObjectName(QString::fromUtf8("pushButton_Stop"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("stop.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_Stop->setIcon(icon1);

        horizontalLayout->addWidget(pushButton_Stop);

        horizontalSlider = new QSlider(layoutWidget);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(horizontalSlider);


        verticalLayout->addLayout(horizontalLayout);


        gridLayout_3->addLayout(verticalLayout, 2, 1, 1, 3);

        horizontalSpacer_5 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_5, 1, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_3->addItem(verticalSpacer_2, 0, 1, 1, 1);

        GuiMupic->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(GuiMupic);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        GuiMupic->setStatusBar(statusBar);

        retranslateUi(GuiMupic);

        filterSelComboBox->setCurrentIndex(2);
        comboBox->setCurrentIndex(1);


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
        groupBox_2->setTitle(QApplication::translate("GuiMupic", "Phic Options", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("GuiMupic", "Filter", 0, QApplication::UnicodeUTF8));
        filterSelComboBox->clear();
        filterSelComboBox->insertItems(0, QStringList()
         << QApplication::translate("GuiMupic", "Threshold", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("GuiMupic", "Adaptative Threshold", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("GuiMupic", "Canny", 0, QApplication::UnicodeUTF8)
        );
        label_4->setText(QApplication::translate("GuiMupic", "Noise Selection", 0, QApplication::UnicodeUTF8));
        noiseLabel->setText(QApplication::translate("GuiMupic", "1", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("GuiMupic", "Polygon Simplification", 0, QApplication::UnicodeUTF8));
        labelPolSimp->setText(QApplication::translate("GuiMupic", "2", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("GuiMupic", "Threshold", 0, QApplication::UnicodeUTF8));
        tLabel->setText(QApplication::translate("GuiMupic", "50", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("GuiMupic", "Mu Options", 0, QApplication::UnicodeUTF8));
        labelComposer->setText(QApplication::translate("GuiMupic", "Composer", 0, QApplication::UnicodeUTF8));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("GuiMupic", "Timothy Composer", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("GuiMupic", "Multiple Composer", 0, QApplication::UnicodeUTF8)
        );
        labelInstruments->setText(QApplication::translate("GuiMupic", "Instruments", 0, QApplication::UnicodeUTF8));
        comboBox_2->clear();
        comboBox_2->insertItems(0, QStringList()
         << QApplication::translate("GuiMupic", "Piano", 0, QApplication::UnicodeUTF8)
        );
        labelName->setText(QApplication::translate("GuiMupic", "Name", 0, QApplication::UnicodeUTF8));
        labelOutput->setText(QApplication::translate("GuiMupic", "Output", 0, QApplication::UnicodeUTF8));
        comboBox_3->clear();
        comboBox_3->insertItems(0, QStringList()
         << QApplication::translate("GuiMupic", ".mid", 0, QApplication::UnicodeUTF8)
        );
        pushButton_Analyze->setText(QApplication::translate("GuiMupic", "Analyze", 0, QApplication::UnicodeUTF8));
        pushButton_Generate->setText(QApplication::translate("GuiMupic", "Compose", 0, QApplication::UnicodeUTF8));
        pushButton_Play->setText(QString());
        pushButton_Stop->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class GuiMupic: public Ui_GuiMupic {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUIMUPIC_H
