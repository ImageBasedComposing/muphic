#ifndef GUIMUPIC_H
#define GUIMUPIC_H

#include <QMainWindow>

#include "ui_guimupic.h"

#include <QFile>
#include <QMessageBox>
#include <QFileDialog>

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QPixmap>

#define DEFAULT_PIC "./test1.png"

namespace Ui {
    class GuiMupic;
}

class GuiMupic : public QMainWindow
{
    Q_OBJECT

public:
    explicit GuiMupic(QWidget *parent = 0);
    ~GuiMupic();

    void initialize();

private slots:
    void on_toolButton_OutputMidi_clicked();

    void on_toolButton_InputPic_clicked();

    void on_pushButton_Generate_clicked();

private:
    Ui::GuiMupic *ui;
    QGraphicsScene * newScene;
};

#endif // GUIMUPIC_H
