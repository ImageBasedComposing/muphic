#include "guimupic.h"

GuiMupic::GuiMupic(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GuiMupic)
{
    ui->setupUi(this);

    l = new Launcher();
    pidPlay = -1;

    //ui->verticalLayout->addWidget(poly, 200, 200, 200, 200);
    /*poly = new PolygonWidget(this);
    QGridLayout * mainLayout = new QGridLayout();
    mainLayout->setColumnStretch(0, 1);
    mainLayout->setColumnStretch(3, 1);
    mainLayout->setRowMinimumHeight(8, 6);
    mainLayout->addWidget(poly, 200, 10, 200, 200);

    ui->setLayout(mainLayout);*/
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
{
    std::string userConfFile = "dummypath";
    std::string picFile = ui->lineEdit_InputPic->text().toStdString();

    std::string args[] = {userConfFile, picFile};
    l->launch(2, Launcher::MUPHIC, args);
}

void GuiMupic::on_pushButton_Stop_clicked()
{
    if (pidPlay > 0)
    {
        l->killProcess(pidPlay);
        pidPlay = -1;
    }

}

void GuiMupic::paintEvent(QPaintEvent*)
{/*
  QPainter painter(this);
  painter.setRenderHint(QPainter::Antialiasing, true);
  painter.setPen(QPen(Qt::black, 12, Qt::DashDotLine, Qt::RoundCap));
  painter.setBrush(QBrush(Qt::green, Qt::SolidPattern));
  painter.drawEllipse(80, 80, 400, 240);*/
}


void GuiMupic::on_pushButton_Play_clicked()
{
    if (pidPlay != -1)
    {
        l->killProcess(pidPlay);
        pidPlay = -1;
    }

    if (pidPlay == -1)
    {
        std::string args[] = {"./MelodyTimothy1.mid"};
        //pidPlay = l->launchAndGo(1, Launcher::MPLAYER, args);

        pidPlay = l->launchAndGo(1, Launcher::MPLAYER, args);
    }
}
