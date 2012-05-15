/********************************************************************************
** Form generated from reading UI file 'guimupic.ui'
**
** Created: Tue May 15 17:14:59 2012
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
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "polygonwidget.h"
#include "seekbar.h"
#include "volumebar.h"

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
    QStatusBar *statusBar;

    void setupUi(QMainWindow *GuiMupic)
    {
        if (GuiMupic->objectName().isEmpty())
            GuiMupic->setObjectName(QString::fromUtf8("GuiMupic"));
        GuiMupic->resize(967, 548);
        centralWidget = new QWidget(GuiMupic);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 951, 511));
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
        polyWidget->setGeometry(QRect(0, 0, 430, 309));
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


        gridLayout_3->addLayout(verticalLayout, 2, 1, 1, 2);

        horizontalSpacer_5 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_5, 1, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout_3->addItem(verticalSpacer_2, 0, 1, 1, 1);

        GuiMupic->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(GuiMupic);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        GuiMupic->setStatusBar(statusBar);

        retranslateUi(GuiMupic);

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
    } // retranslateUi

};

namespace Ui {
    class GuiMupic: public Ui_GuiMupic {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUIMUPIC_H
