#include "guimupic.h"

GuiMupic::GuiMupic(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GuiMupic)
{
    ui->setupUi(this);

    ui->centralWidget->setLayout(ui->gridLayout_3);

    l = new Launcher();
    pidPlay = -1;
}

GuiMupic::~GuiMupic()
{
    delete ui;
    delete muphicConfig;
}

void GuiMupic::initialize()
{
    //ui->scrollArea->setWidget(ui->polyWidget);

    //We create the config window
    muphicConfig = new MuphicConfig();
    muphicConfig->setWindowTitle("Configuration");
    muphicConfig->show();
    muphicConfig->initialize();

    newScene = new QGraphicsScene(0,0,ui->graphicsView_Pic->width(),ui->graphicsView_Pic->height());
    ui->graphicsView_Pic->setScene(newScene);

    QPixmap pixImg(DEFAULT_PIC);
    pixImg = pixImg.scaled(ui->graphicsView_Pic->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    ui->graphicsView_Pic->scene()->addPixmap(pixImg);
    imageFile = DEFAULT_PIC;

    ui->pushButton_Generate->setEnabled(false);

    //Phonon thinguies
    audioOutput = new Phonon::AudioOutput(Phonon::MusicCategory,this);
    mediaObject = new Phonon::MediaObject(this);
    mediaObject->setTickInterval(1000);
    connect(mediaObject, SIGNAL(tick(qint64)), this, SLOT(tick(qint64)));
    connect(mediaObject, SIGNAL(stateChanged(Phonon::State,Phonon::State)),
                this, SLOT(stateChanged(Phonon::State,Phonon::State)));
    Phonon::createPath(mediaObject, audioOutput);

    is_paused = false;
    ui->pushButton_pause->setEnabled(false);
    ui->timeLcd->display("00:00");
    ui->seekSlider->setMediaObject(mediaObject);
    ui->volumeSlider->setAudioOutput(audioOutput);

    setupActions();
}

void GuiMupic::setupActions()
{
    playAction = new QAction(style()->standardIcon(QStyle::SP_MediaPlay), tr("Play"), this);
    playAction->setShortcut(tr("Ctrl+P"));
    playAction->setDisabled(true);
    pauseAction = new QAction(style()->standardIcon(QStyle::SP_MediaPause), tr("Pause"), this);
    pauseAction->setShortcut(tr("Ctrl+A"));
    pauseAction->setDisabled(true);
    stopAction = new QAction(style()->standardIcon(QStyle::SP_MediaStop), tr("Stop"), this);
    stopAction->setShortcut(tr("Ctrl+S"));
    stopAction->setDisabled(true);

    connect(playAction, SIGNAL(triggered()), mediaObject, SLOT(play()));
    connect(pauseAction, SIGNAL(triggered()), mediaObject, SLOT(pause()) );
    connect(stopAction, SIGNAL(triggered()), mediaObject, SLOT(stop()));
}

void GuiMupic::tick(qint64 time)
{
    QTime displayTime(0, (time / 60000) % 60, (time / 1000) % 60);

    ui->timeLcd->display(displayTime.toString("mm:ss"));
    //ui->horizontalSlider_Seek->setSliderPosition(mediaObject->currentTime()*1000 / mediaObject->totalTime());
}

void GuiMupic::stateChanged(Phonon::State newState, Phonon::State /* oldState */)
{
    switch (newState) {
        case Phonon::ErrorState:
            if (mediaObject->errorType() == Phonon::FatalError) {
                QMessageBox::warning(this, tr("Fatal Error"),
                mediaObject->errorString());
            } else {
                QMessageBox::warning(this, tr("Error"),
                mediaObject->errorString());
            }
            break;
        case Phonon::PlayingState:
                playAction->setEnabled(false);
                pauseAction->setEnabled(true);
                stopAction->setEnabled(true);
                break;
        case Phonon::StoppedState:
                stopAction->setEnabled(false);
                playAction->setEnabled(true);
                pauseAction->setEnabled(false);
                ui->timeLcd->display("00:00");
                break;
        case Phonon::PausedState:
                pauseAction->setEnabled(false);
                stopAction->setEnabled(true);
                playAction->setEnabled(true);
                break;
        case Phonon::BufferingState:
                break;
        default:
            ;
    }
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
    mediaSource = Phonon::MediaSource("");
    mediaObject->setCurrentSource(mediaSource);

    std::string picFile = ui->lineEdit_InputPic->text().toStdString();

    muphicConfig->usrConf->setPhicActive(false);
    muphicConfig->usrConf->setMuDebug(false);
    muphicConfig->usrConf->setMuActive(true);
    //std::string name = changeExtension(fileName.toStdString(), "xml");
    muphicConfig->usrConf->write("user_conf.xml");
    std::string userConfFile = "user_conf.xml";

    std::string args[] = {userConfFile, picFile};
    l->launch(2, Launcher::MUPHIC, args);
}

void GuiMupic::on_pushButton_pause_clicked()
{
    if(!is_paused)
    {
        mediaObject->pause();
        mediaTime = mediaObject->currentTime();
        is_paused = true;
    }
    else
    {
        mediaObject->seek(mediaTime);
        mediaObject->play();
        is_paused = false;
    }
}

void GuiMupic::on_pushButton_Stop_clicked()
{
    mediaObject->stop();
    mediaSource = Phonon::MediaSource("");
    mediaObject->setCurrentSource(mediaSource);
    ui->pushButton_pause->setEnabled(false);
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
/*    if (pidPlay != -1)
    {
        l->killProcess(pidPlay);
        pidPlay = -1;
    }

    if (pidPlay == -1)
    {
        std::string args[] = {"./MelodyTimothy1.mid"};
        //pidPlay = l->launchAndGo(1, Launcher::MPLAYER, args);

        pidPlay = l->launchAndGo(1, Launcher::MPLAYER, args);
    }*/

    if(!is_paused)
    {
        std::string analysedPic = changeExtension(imageFile.toStdString(), "");
        mediaSource = Phonon::MediaSource((analysedPic+".wav").c_str());
        mediaObject->setCurrentSource(mediaSource);
        mediaObject->play();
        ui->pushButton_pause->setEnabled(true);
    }
    else
    {
        mediaObject->seek(mediaTime);
        mediaObject->play();
        is_paused = false;
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

        muphicConfig->usrConf->setPhicActive(true);
        muphicConfig->usrConf->setPhicDebug(false);
        muphicConfig->usrConf->setMuActive(false);
        //std::string name = changeExtension(imageFile.toStdString(), "xml");
        muphicConfig->usrConf->write("user_conf.xml");

        std::string args[] = {"user_conf.xml", imageFile.toStdString()};
        l->launch(2, Launcher::MUPHIC, args);

        ui->polyWidget->load(imageFile.toStdString());
        ui->polyWidget->setMinimumHeight(ui->polyWidget->iHeight);
        ui->polyWidget->setMinimumWidth(ui->polyWidget->iWidth);
        ui->pushButton_Generate->setEnabled(true);
     }
}
