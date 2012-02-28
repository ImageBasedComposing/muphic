#include "guimupic.h"

GuiMupic::GuiMupic(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GuiMupic)
{
    ui->setupUi(this);

    ui->centralWidget->setLayout(ui->gridLayout_3);

    l = new Launcher();
    pidPlay = -1;

    //ui->polyWidget->
}

GuiMupic::~GuiMupic()
{
    delete usrConf;
    delete ui;
}

void GuiMupic::initialize()
{
    usrConf = new UsrConf();
    usrConf->setPhicNoiseSelec(50);
    usrConf->setPhicPolygonSimp(2);

    newScene = new QGraphicsScene(0,0,ui->graphicsView_Pic->width(),ui->graphicsView_Pic->height());
    ui->graphicsView_Pic->setScene(newScene);

    QPixmap pixImg(DEFAULT_PIC);
    pixImg = pixImg.scaled(ui->graphicsView_Pic->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    ui->graphicsView_Pic->scene()->addPixmap(pixImg);
    imageFile = DEFAULT_PIC;

    ui->pushButton_Generate->setEnabled(false);

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
    imageFile = QFileDialog::getOpenFileName(this, tr("Open File"), "",
        tr("(*.jpg *.png *.bmp)"));

    if (imageFile != "") {
        QFile file(imageFile);
        if (!file.exists()) {
         QMessageBox::critical(this, tr("Error"),
             tr("Could not open file, not exists"));
         return;
        }
        ui->lineEdit_InputPic->setText(imageFile);

        delete newScene; newScene = NULL;
        newScene = new QGraphicsScene(0,0,ui->graphicsView_Pic->width(),ui->graphicsView_Pic->height());
        ui->graphicsView_Pic->setScene(newScene);

        QPixmap pixImg(imageFile);
        pixImg = pixImg.scaled(ui->graphicsView_Pic->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
        ui->graphicsView_Pic->scene()->addPixmap(pixImg);

        repaint();
    }
}

void GuiMupic::on_pushButton_Generate_clicked()
{
    std::string picFile = ui->lineEdit_InputPic->text().toStdString();

    UsrConf* usrConf = new UsrConf();
    usrConf->setPhicActive(false);
    usrConf->setMuActive(true);
    //std::string name = changeExtension(fileName.toStdString(), "xml");
    usrConf->write("user_conf.xml");
    std::string userConfFile = "user_conf.xml";

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

void GuiMupic::on_pushButton_Analyze_clicked()
{
     if (imageFile != "") {
         QFile file(imageFile);
         if (!file.exists()) {
          QMessageBox::critical(this, tr("Error"),
              tr("Could not open file, not exists"));
          return;
         }

        usrConf->setPhicActive(true);
        usrConf->setPhicDebug(false);
        usrConf->setMuActive(false);
        //std::string name = changeExtension(imageFile.toStdString(), "xml");
        usrConf->write("user_conf.xml");

        std::string args[] = {"user_conf.xml", imageFile.toStdString()};
        l->launch(2, Launcher::MUPHIC, args);

        ui->polyWidget->load(imageFile.toStdString());
        ui->pushButton_Generate->setEnabled(true);
     }
}

void GuiMupic::on_filterSelComboBox_currentIndexChanged(int index)
{
    usrConf->setPhicFilterSelect(index);
    if( index == 0 )
    {
        ui->horizontalSlider_2->setEnabled(true);
        ui->tLabel->setEnabled(true);
    }
    else
    {
        ui->horizontalSlider_2->setEnabled(false);
        ui->tLabel->setEnabled(false);
    }
}

void GuiMupic::on_horizontalSlider_2_sliderMoved(int position)
{
    usrConf->setPhicThresholdSelec(position);
    char a[10];
    ui->tLabel->setText(our_itoa(position,a,10));
}

void GuiMupic::on_horizontalSlider_3_sliderMoved(int position)
{
    usrConf->setPhicNoiseSelec(position);
    char a[10];
    ui->noiseLabel->setText(our_itoa(position,a,10));
}

void GuiMupic::on_horizontalSlider_6_sliderMoved(int position)
{
    usrConf->setPhicPolygonSimp(position);
    char a[10];
    ui->labelPolSimp->setText(our_itoa(position,a,10));
}
