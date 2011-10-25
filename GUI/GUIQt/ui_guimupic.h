/********************************************************************************
** Form generated from reading UI file 'guimupic.ui'
**
** Created: Tue 25. Oct 03:03:52 2011
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
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GuiMupic
{
public:
    QWidget *centralWidget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_InputPic;
    QLineEdit *lineEdit_InputPic;
    QToolButton *toolButton_InputPic;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_OutputMidi;
    QLineEdit *lineEdit_OutputMidi;
    QToolButton *toolButton_OutputMidi;
    QGraphicsView *graphicsView_Pic;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_Generate;
    QSpacerItem *horizontalSpacer;
    QProgressBar *progressBar_Generate;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_Play;
    QPushButton *pushButton_Stop;
    QSlider *horizontalSlider;
    QMenuBar *menuBar;
    QMenu *menuAbout;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *GuiMupic)
    {
        if (GuiMupic->objectName().isEmpty())
            GuiMupic->setObjectName(QString::fromUtf8("GuiMupic"));
        GuiMupic->resize(281, 378);
        centralWidget = new QWidget(GuiMupic);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 258, 313));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
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


        verticalLayout->addLayout(horizontalLayout_4);

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


        verticalLayout->addLayout(horizontalLayout_3);

        graphicsView_Pic = new QGraphicsView(layoutWidget);
        graphicsView_Pic->setObjectName(QString::fromUtf8("graphicsView_Pic"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(graphicsView_Pic->sizePolicy().hasHeightForWidth());
        graphicsView_Pic->setSizePolicy(sizePolicy);
        graphicsView_Pic->viewport()->setProperty("cursor", QVariant(QCursor(Qt::CrossCursor)));
        graphicsView_Pic->setAutoFillBackground(true);
        graphicsView_Pic->setFrameShape(QFrame::StyledPanel);

        verticalLayout->addWidget(graphicsView_Pic);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pushButton_Generate = new QPushButton(layoutWidget);
        pushButton_Generate->setObjectName(QString::fromUtf8("pushButton_Generate"));

        horizontalLayout_2->addWidget(pushButton_Generate);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

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

        GuiMupic->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(GuiMupic);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 281, 21));
        menuAbout = new QMenu(menuBar);
        menuAbout->setObjectName(QString::fromUtf8("menuAbout"));
        GuiMupic->setMenuBar(menuBar);
        statusBar = new QStatusBar(GuiMupic);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        GuiMupic->setStatusBar(statusBar);

        menuBar->addAction(menuAbout->menuAction());

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
        pushButton_Generate->setText(QApplication::translate("GuiMupic", "Generate", 0, QApplication::UnicodeUTF8));
        pushButton_Play->setText(QString());
        pushButton_Stop->setText(QString());
        menuAbout->setTitle(QApplication::translate("GuiMupic", "About", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class GuiMupic: public Ui_GuiMupic {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUIMUPIC_H
