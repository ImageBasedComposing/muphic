#ifndef GUIMUPIC_H
#define GUIMUPIC_H

#include <QMainWindow>

namespace Ui {
    class GuiMupic;
}

class GuiMupic : public QMainWindow
{
    Q_OBJECT

public:
    explicit GuiMupic(QWidget *parent = 0);
    ~GuiMupic();

private slots:
    void on_toolButton_OutputMidi_clicked();

    void on_toolButton_InputPic_clicked();

    void on_pushButton_Generate_clicked();

private:
    Ui::GuiMupic *ui;
};

#endif // GUIMUPIC_H
