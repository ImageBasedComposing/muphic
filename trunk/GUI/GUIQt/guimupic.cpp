#include "guimupic.h"
#include "launcher.h"


GuiMupic::GuiMupic(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GuiMupic)
{
    ui->setupUi(this);
}

GuiMupic::~GuiMupic()
{
    delete ui;
}

void GuiMupic::initialize()
{
    newScene = new QGraphicsScene(0,0,ui->graphicsView_Pic->width(),ui->graphicsView_Pic->height());
    ui->graphicsView_Pic->setScene(newScene);

    QPixmap pixImg(DEFAULT_PIC);
    pixImg = pixImg.scaled(ui->graphicsView_Pic->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    ui->graphicsView_Pic->scene()->addPixmap(pixImg);

}

void GuiMupic::on_toolButton_OutputMidi_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), "",
        tr("(*.mid)"));

    if (fileName != "") {
        QFile file(fileName);
        if (file.exists()) {
         QMessageBox::critical(this, tr("Warning"),
             tr("Already have a file with this name!"));

        }
        ui->lineEdit_OutputMidi->setText(fileName);
    }
}

void GuiMupic::on_toolButton_InputPic_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "",
        tr("(*.jpg *.png *.bmp)"));

    if (fileName != "") {
        QFile file(fileName);
        if (!file.exists()) {
         QMessageBox::critical(this, tr("Error"),
             tr("Could not open file, not exists"));
         return;
        }
        ui->lineEdit_InputPic->setText(fileName);

        delete newScene; newScene = NULL;
        newScene = new QGraphicsScene(0,0,ui->graphicsView_Pic->width(),ui->graphicsView_Pic->height());
        ui->graphicsView_Pic->setScene(newScene);

        QPixmap pixImg(fileName);
        pixImg = pixImg.scaled(ui->graphicsView_Pic->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
        ui->graphicsView_Pic->scene()->addPixmap(pixImg);
    }
}

void GuiMupic::on_pushButton_Generate_clicked()
{/*
    QString picFile = ui->lineEdit_InputPic->text();
    QString userConfFile = "dummypath";
    QString exeFile = "./Muphic";
    QString command = exeFile + " " + userConfFile + " " + picFile;

    //conversion de QString a char *
    QByteArray   bytes  = command.toAscii();
    const char * commandChar = bytes.data();

    system(commandChar);*/

    std::string exeFile = "Muphic";
    std::string userConfFile = "dummypath";
    std::string picFile = ui->lineEdit_InputPic->text().toStdString();

    cout << exeFile << " " << userConfFile << " " << picFile << endl;

    Launcher* l = new Launcher();
    string args[] = {exeFile, userConfFile, picFile};
    l->launch(3, args);
}
