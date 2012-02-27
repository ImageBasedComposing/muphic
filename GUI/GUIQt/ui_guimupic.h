/********************************************************************************
** Form generated from reading UI file 'guimupic.ui'
**
** Created: Mon 27. Feb 20:34:32 2012
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
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QStatusBar>
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
    QGraphicsView *graphicsView_Pic;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    PolygonWidget *polyWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_Analyze;
    QPushButton *pushButton_Generate;
    QProgressBar *progressBar_Generate;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_Play;
    QPushButton *pushButton_Stop;
    QSlider *horizontalSlider;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox_2;
    QComboBox *filterSelComboBox;
    QLabel *label;
    QGroupBox *groupBox_3;
    QMenuBar *menuBar;
    QMenu *menuAbout;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *GuiMupic)
    {
        if (GuiMupic->objectName().isEmpty())
            GuiMupic->setObjectName(QString::fromUtf8("GuiMupic"));
        GuiMupic->resize(1002, 385);
        centralWidget = new QWidget(GuiMupic);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 971, 321));
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
        graphicsView_Pic = new QGraphicsView(layoutWidget);
        graphicsView_Pic->setObjectName(QString::fromUtf8("graphicsView_Pic"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(graphicsView_Pic->sizePolicy().hasHeightForWidth());
        graphicsView_Pic->setSizePolicy(sizePolicy);
        graphicsView_Pic->setMinimumSize(QSize(256, 194));
        graphicsView_Pic->viewport()->setProperty("cursor", QVariant(QCursor(Qt::CrossCursor)));
        graphicsView_Pic->setAutoFillBackground(true);
        graphicsView_Pic->setFrameShape(QFrame::StyledPanel);

        horizontalLayout_5->addWidget(graphicsView_Pic);

        groupBox = new QGroupBox(layoutWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        groupBox->setMinimumSize(QSize(256, 194));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        polyWidget = new PolygonWidget(groupBox);
        polyWidget->setObjectName(QString::fromUtf8("polyWidget"));
        sizePolicy.setHeightForWidth(polyWidget->sizePolicy().hasHeightForWidth());
        polyWidget->setSizePolicy(sizePolicy);

        gridLayout->addWidget(polyWidget, 0, 0, 1, 1);


        horizontalLayout_5->addWidget(groupBox);


        gridLayout_2->addLayout(horizontalLayout_5, 2, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 0, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pushButton_Analyze = new QPushButton(layoutWidget);
        pushButton_Analyze->setObjectName(QString::fromUtf8("pushButton_Analyze"));

        horizontalLayout_2->addWidget(pushButton_Analyze);

        pushButton_Generate = new QPushButton(layoutWidget);
        pushButton_Generate->setObjectName(QString::fromUtf8("pushButton_Generate"));

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


        gridLayout_3->addLayout(verticalLayout, 1, 0, 1, 2);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        groupBox_2 = new QGroupBox(layoutWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        sizePolicy.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy);
        groupBox_2->setMaximumSize(QSize(441, 16777215));
        filterSelComboBox = new QComboBox(groupBox_2);
        filterSelComboBox->setObjectName(QString::fromUtf8("filterSelComboBox"));
        filterSelComboBox->setGeometry(QRect(50, 20, 111, 22));
        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 20, 31, 16));

        verticalLayout_2->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(layoutWidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        sizePolicy.setHeightForWidth(groupBox_3->sizePolicy().hasHeightForWidth());
        groupBox_3->setSizePolicy(sizePolicy);
        groupBox_3->setMaximumSize(QSize(441, 16777215));

        verticalLayout_2->addWidget(groupBox_3);


        gridLayout_3->addLayout(verticalLayout_2, 0, 1, 1, 1);

        GuiMupic->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(GuiMupic);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1002, 21));
        menuAbout = new QMenu(menuBar);
        menuAbout->setObjectName(QString::fromUtf8("menuAbout"));
        GuiMupic->setMenuBar(menuBar);
        statusBar = new QStatusBar(GuiMupic);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        GuiMupic->setStatusBar(statusBar);

        menuBar->addAction(menuAbout->menuAction());

        retranslateUi(GuiMupic);

        filterSelComboBox->setCurrentIndex(2);


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
        groupBox->setTitle(QApplication::translate("GuiMupic", "Analysis output", 0, QApplication::UnicodeUTF8));
        pushButton_Analyze->setText(QApplication::translate("GuiMupic", "Analyze", 0, QApplication::UnicodeUTF8));
        pushButton_Generate->setText(QApplication::translate("GuiMupic", "Compose", 0, QApplication::UnicodeUTF8));
        pushButton_Play->setText(QString());
        pushButton_Stop->setText(QString());
        groupBox_2->setTitle(QApplication::translate("GuiMupic", "Phic Options", 0, QApplication::UnicodeUTF8));
        filterSelComboBox->clear();
        filterSelComboBox->insertItems(0, QStringList()
         << QApplication::translate("GuiMupic", "Threshold", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("GuiMupic", "Adaptative Threshold", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("GuiMupic", "Canny", 0, QApplication::UnicodeUTF8)
        );
        label->setText(QApplication::translate("GuiMupic", "Filter", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("GuiMupic", "Mu Options", 0, QApplication::UnicodeUTF8));
        menuAbout->setTitle(QApplication::translate("GuiMupic", "About", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class GuiMupic: public Ui_GuiMupic {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUIMUPIC_H
