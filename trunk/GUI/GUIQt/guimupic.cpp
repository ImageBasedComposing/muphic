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
    delete usrConf;
    delete ui;
}

void GuiMupic::initialize()
{
    //ui->scrollArea->setWidget(ui->polyWidget);

    usrConf = new UsrConf();
    usrConf->setPhicNoiseSelec(0);
    usrConf->setPhicPolygonSimp(2);
    usrConf->setPhicColorLevels(3);

    //We initialize Mu
    usrConf->setMuReconColors(1);
    usrConf->setMuCompVoice1(2);
    usrConf->setMuInstrVoice1(45);
    usrConf->setMuCompVoice2(2);
    usrConf->setMuInstrVoice2(73);
    usrConf->setMuCompVoice3(2);
    usrConf->setMuInstrVoice3(34);
    usrConf->setMuCompVoice4(2);
    usrConf->setMuInstrVoice4(128);
    usrConf->setMuCompMix(2);
    usrConf->setMuTempo(120);

    newScene = new QGraphicsScene(0,0,ui->graphicsView_Pic->width(),ui->graphicsView_Pic->height());
    ui->graphicsView_Pic->setScene(newScene);

    QPixmap pixImg(DEFAULT_PIC);
    pixImg = pixImg.scaled(ui->graphicsView_Pic->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    ui->graphicsView_Pic->scene()->addPixmap(pixImg);
    imageFile = DEFAULT_PIC;

    // We save sizes for dynamic interaction between options
    hSlider_2_max = ui->horizontalSlider_2->maximumSize();
    tlabel_max = ui->tLabel->maximumSize();
    label_2_max = ui->label_2->maximumSize();
    hSliderColorLevels_max = ui->horizontalSlider_colorLevels->maximumSize();
    labelColorLevels_max = ui->labelColorLevels->maximumSize();
    label_colorLevels_max = ui->label_ColorLevels->maximumSize();
    labelThresholdH_max = ui->labelThresholdH->maximumSize();
    label_ThresholdH_max = ui->label_ThresholdH->maximumSize();
    hSliderThersholdH_max = ui->horizontalSliderTH->maximumSize();
    labelThresholdS_max = ui->labelThresholdS->maximumSize();
    label_ThresholdS_max = ui->label_ThresholdS->maximumSize();
    hSliderThersholdS_max = ui->horizontalSliderTS->maximumSize();
    labelThresholdV_max = ui->labelThresholdV->maximumSize();
    label_ThresholdV_max = ui->label_ThresholdV->maximumSize();
    hSliderThersholdV_max = ui->horizontalSliderTV->maximumSize();

    //We deactivate threshold operations
    ui->horizontalSlider_2->setVisible(false);
    ui->horizontalSlider_2->setMaximumSize(0,0);
    ui->tLabel->setVisible(false);
    ui->tLabel->setMaximumSize(0,0);
    ui->label_2->setVisible(false);
    ui->label_2->setMaximumSize(0,0);

    //We deactivate colorLevels operations
    ui->horizontalSlider_colorLevels->setVisible(false);
    ui->horizontalSlider_colorLevels->setMaximumSize(0,0);
    ui->labelColorLevels->setVisible(false);
    ui->labelColorLevels->setMaximumSize(0,0);
    ui->label_ColorLevels->setVisible(false);
    ui->label_ColorLevels->setMaximumSize(0,0);

    //We deactivate threshold H operations
    ui->label_ThresholdH->setVisible(false);
    ui->label_ThresholdH->setMaximumSize(0,0);
    ui->labelThresholdH->setVisible(false);
    ui->labelThresholdH->setMaximumSize(0,0);
    ui->horizontalSliderTH->setVisible(false);
    ui->horizontalSliderTH->setMaximumSize(0,0);

    //We deactivate threshold S operations
    ui->label_ThresholdS->setVisible(false);
    ui->label_ThresholdS->setMaximumSize(0,0);
    ui->labelThresholdS->setVisible(false);
    ui->labelThresholdS->setMaximumSize(0,0);
    ui->horizontalSliderTS->setVisible(false);
    ui->horizontalSliderTS->setMaximumSize(0,0);

    //We deactivate threshold V operations
    ui->label_ThresholdV->setVisible(false);
    ui->label_ThresholdV->setMaximumSize(0,0);
    ui->labelThresholdV->setVisible(false);
    ui->labelThresholdV->setMaximumSize(0,0);
    ui->horizontalSliderTV->setVisible(false);
    ui->horizontalSliderTV->setMaximumSize(0,0);


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
    mediaObject->clear();

    std::string picFile = ui->lineEdit_InputPic->text().toStdString();

    usrConf->setPhicActive(false);
    usrConf->setMuDebug(false);
    usrConf->setMuActive(true);
    //std::string name = changeExtension(fileName.toStdString(), "xml");
    usrConf->write("user_conf.xml");
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
    /*if (pidPlay > 0)
    {
        l->killProcess(pidPlay);
        pidPlay = -1;
    }*/
    mediaObject->stop();
    mediaObject->clear();
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
        mediaSource = new Phonon::MediaSource((analysedPic+".wav").c_str());
        mediaObject->setCurrentSource(*mediaSource);
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

        usrConf->setPhicActive(true);
        usrConf->setPhicDebug(false);
        usrConf->setMuActive(false);
        //std::string name = changeExtension(imageFile.toStdString(), "xml");
        usrConf->write("user_conf.xml");

        std::string args[] = {"user_conf.xml", imageFile.toStdString()};
        l->launch(2, Launcher::MUPHIC, args);

        ui->polyWidget->load(imageFile.toStdString());
        ui->polyWidget->setMinimumHeight(ui->polyWidget->iHeight);
        ui->polyWidget->setMinimumWidth(ui->polyWidget->iWidth);
        ui->pushButton_Generate->setEnabled(true);
     }
}

void GuiMupic::on_filterSelComboBox_currentIndexChanged(int index)
{
    usrConf->setPhicFilterSelect(index);
    if( index == 0 )
    {
        ui->horizontalSlider_2->setVisible(true);
        ui->horizontalSlider_2->setMaximumSize(hSlider_2_max);
        ui->tLabel->setVisible(true);
        ui->tLabel->setMaximumSize(tlabel_max);
        ui->label_2->setVisible(true);
        ui->label_2->setMaximumSize(label_2_max);

        //We deactivate color levels operations
        ui->horizontalSlider_colorLevels->setVisible(false);
        ui->horizontalSlider_colorLevels->setMaximumSize(0,0);
        ui->labelColorLevels->setVisible(false);
        ui->labelColorLevels->setMaximumSize(0,0);
        ui->label_ColorLevels->setVisible(false);
        ui->label_ColorLevels->setMaximumSize(0,0);

        //We deactivate threshold H operations
        ui->label_ThresholdH->setVisible(false);
        ui->label_ThresholdH->setMaximumSize(0,0);
        ui->labelThresholdH->setVisible(false);
        ui->labelThresholdH->setMaximumSize(0,0);
        ui->horizontalSliderTH->setVisible(false);
        ui->horizontalSliderTH->setMaximumSize(0,0);

        //We deactivate threshold S operations
        ui->label_ThresholdS->setVisible(false);
        ui->label_ThresholdS->setMaximumSize(0,0);
        ui->labelThresholdS->setVisible(false);
        ui->labelThresholdS->setMaximumSize(0,0);
        ui->horizontalSliderTS->setVisible(false);
        ui->horizontalSliderTS->setMaximumSize(0,0);

        //We deactivate threshold V operations
        ui->label_ThresholdV->setVisible(false);
        ui->label_ThresholdV->setMaximumSize(0,0);
        ui->labelThresholdV->setVisible(false);
        ui->labelThresholdV->setMaximumSize(0,0);
        ui->horizontalSliderTV->setVisible(false);
        ui->horizontalSliderTV->setMaximumSize(0,0);
    }
    else if( index == 3 )
    {
        ui->horizontalSlider_2->setVisible(false);
        ui->horizontalSlider_2->setMaximumSize(0,0);
        ui->tLabel->setVisible(false);
        ui->tLabel->setMaximumSize(0,0);
        ui->label_2->setVisible(false);
        ui->label_2->setMaximumSize(0,0);

        //We activate color level operations
        ui->horizontalSlider_colorLevels->setVisible(true);
        ui->horizontalSlider_colorLevels->setMaximumSize(hSliderColorLevels_max);
        ui->labelColorLevels->setVisible(true);
        ui->labelColorLevels->setMaximumSize(labelColorLevels_max);
        ui->label_ColorLevels->setVisible(true);
        ui->label_ColorLevels->setMaximumSize(label_colorLevels_max);

        //We deactivate threshold H operations
        ui->label_ThresholdH->setVisible(false);
        ui->label_ThresholdH->setMaximumSize(0,0);
        ui->labelThresholdH->setVisible(false);
        ui->labelThresholdH->setMaximumSize(0,0);
        ui->horizontalSliderTH->setVisible(false);
        ui->horizontalSliderTH->setMaximumSize(0,0);

        //We deactivate threshold S operations
        ui->label_ThresholdS->setVisible(false);
        ui->label_ThresholdS->setMaximumSize(0,0);
        ui->labelThresholdS->setVisible(false);
        ui->labelThresholdS->setMaximumSize(0,0);
        ui->horizontalSliderTS->setVisible(false);
        ui->horizontalSliderTS->setMaximumSize(0,0);

        //We deactivate threshold V operations
        ui->label_ThresholdV->setVisible(false);
        ui->label_ThresholdV->setMaximumSize(0,0);
        ui->labelThresholdV->setVisible(false);
        ui->labelThresholdV->setMaximumSize(0,0);
        ui->horizontalSliderTV->setVisible(false);
        ui->horizontalSliderTV->setMaximumSize(0,0);
    }
    else if( index == 4 )
    {
        ui->horizontalSlider_2->setVisible(false);
        ui->horizontalSlider_2->setMaximumSize(0,0);
        ui->tLabel->setVisible(false);
        ui->tLabel->setMaximumSize(0,0);
        ui->label_2->setVisible(false);
        ui->label_2->setMaximumSize(0,0);

        //We deactivate color level operations
        ui->horizontalSlider_colorLevels->setVisible(false);
        ui->horizontalSlider_colorLevels->setMaximumSize(0,0);
        ui->labelColorLevels->setVisible(false);
        ui->labelColorLevels->setMaximumSize(0,0);
        ui->label_ColorLevels->setVisible(false);
        ui->label_ColorLevels->setMaximumSize(0,0);

        //We activate threshold H operations
        ui->label_ThresholdH->setVisible(true);
        ui->label_ThresholdH->setMaximumSize(label_ThresholdH_max);
        ui->labelThresholdH->setVisible(true);
        ui->labelThresholdH->setMaximumSize(labelThresholdH_max);
        ui->horizontalSliderTH->setVisible(true);
        ui->horizontalSliderTH->setMaximumSize(hSliderThersholdH_max);

        //We activate threshold S operations
        ui->label_ThresholdS->setVisible(true);
        ui->label_ThresholdS->setMaximumSize(label_ThresholdS_max);
        ui->labelThresholdS->setVisible(true);
        ui->labelThresholdS->setMaximumSize(labelThresholdS_max);
        ui->horizontalSliderTS->setVisible(true);
        ui->horizontalSliderTS->setMaximumSize(hSliderThersholdS_max);

        //We activate threshold V operations
        ui->label_ThresholdV->setVisible(true);
        ui->label_ThresholdV->setMaximumSize(label_ThresholdV_max);
        ui->labelThresholdV->setVisible(true);
        ui->labelThresholdV->setMaximumSize(labelThresholdV_max);
        ui->horizontalSliderTV->setVisible(true);
        ui->horizontalSliderTV->setMaximumSize(hSliderThersholdV_max);
    }
    else
    {
        ui->horizontalSlider_2->setVisible(false);
        ui->horizontalSlider_2->setMaximumSize(0,0);
        ui->tLabel->setVisible(false);
        ui->tLabel->setMaximumSize(0,0);
        ui->label_2->setVisible(false);
        ui->label_2->setMaximumSize(0,0);

        //We deactivate color level operations
        ui->horizontalSlider_colorLevels->setVisible(false);
        ui->horizontalSlider_colorLevels->setMaximumSize(0,0);
        ui->labelColorLevels->setVisible(false);
        ui->labelColorLevels->setMaximumSize(0,0);
        ui->label_ColorLevels->setVisible(false);
        ui->label_ColorLevels->setMaximumSize(0,0);

        //We deactivate threshold H operations
        ui->label_ThresholdH->setVisible(false);
        ui->label_ThresholdH->setMaximumSize(0,0);
        ui->labelThresholdH->setVisible(false);
        ui->labelThresholdH->setMaximumSize(0,0);
        ui->horizontalSliderTH->setVisible(false);
        ui->horizontalSliderTH->setMaximumSize(0,0);

        //We deactivate threshold S operations
        ui->label_ThresholdS->setVisible(false);
        ui->label_ThresholdS->setMaximumSize(0,0);
        ui->labelThresholdS->setVisible(false);
        ui->labelThresholdS->setMaximumSize(0,0);
        ui->horizontalSliderTS->setVisible(false);
        ui->horizontalSliderTS->setMaximumSize(0,0);

        //We deactivate threshold V operations
        ui->label_ThresholdV->setVisible(false);
        ui->label_ThresholdV->setMaximumSize(0,0);
        ui->labelThresholdV->setVisible(false);
        ui->labelThresholdV->setMaximumSize(0,0);
        ui->horizontalSliderTV->setVisible(false);
        ui->horizontalSliderTV->setMaximumSize(0,0);
    }
}

void GuiMupic::on_horizontalSlider_2_sliderMoved(int position)
{
    usrConf->setPhicThresholdSelec(position);
    char a[10];
    ui->tLabel->setText(our_itoa(position,a,10));
}


// NOISE MINDFUCK!
void GuiMupic::on_horizontalSlider_3_sliderMoved(int position)
{
    double poslog = 0;
    if (position != 0)
    {
        int L0, Lf, l0, lf;

        if (position <= 25)
        {
            L0 = 0; Lf = 25;
            l0 = 0; lf = 1;
        }
        else if (position <= 50)
        {
            L0 = 25; Lf = 50;
            l0 = 1; lf = 10;
        }

        else if (position <= 75)
        {
            L0 = 50; Lf = 75;
            l0 = 10; lf = 50;
        }
        else
        {
            L0 = 75; Lf = 100;
            l0 = 50; lf = 100;
        }

        poslog = (position - L0)*((lf - l0)/(double) (Lf - L0)) + l0;
    }
    usrConf->setPhicNoiseSelec(poslog);
    char a[10];
    sprintf(a, "%3.1f",poslog);
    ui->noiseLabel->setText(a);//our_itoa(poslog,a,10));
}

void GuiMupic::on_horizontalSlider_6_sliderMoved(int position)
{
    usrConf->setPhicPolygonSimp(position);
    char a[10];
    ui->labelPolSimp->setText(our_itoa(position,a,10));
}

void GuiMupic::on_horizontalSlider_colorLevels_sliderMoved(int position)
{
    usrConf->setPhicColorLevels(position);
    char a[10];
    ui->labelColorLevels->setText(our_itoa(position,a,10));
}

void GuiMupic::on_horizontalSliderTH_sliderMoved(int position)
{
    usrConf->setPhicThresholdH(position);
    char a[10];
    ui->labelThresholdH->setText(our_itoa(position,a,10));
}

void GuiMupic::on_horizontalSliderTS_sliderMoved(int position)
{
    usrConf->setPhicThresholdS(position);
    char a[10];
    ui->labelThresholdS->setText(our_itoa(position,a,10));
}

void GuiMupic::on_horizontalSliderTV_sliderMoved(int position)
{
    usrConf->setPhicThresholdV(position);
    char a[10];
    ui->labelThresholdV->setText(our_itoa(position,a,10));
}

void GuiMupic::on_comboBox_reconColors_currentIndexChanged(int index)
{
    usrConf->setMuReconColors(index);
}

void GuiMupic::on_comboBox_v1Composer_currentIndexChanged(int index)
{
    usrConf->setMuCompVoice1(index);
}

void GuiMupic::on_comboBox_v1Instrument_currentIndexChanged(int index)
{
    usrConf->setMuInstrVoice1(index);
}

void GuiMupic::on_comboBox_v2Composer_currentIndexChanged(int index)
{
    usrConf->setMuCompVoice2(index);
}

void GuiMupic::on_comboBox_v2Instruments_currentIndexChanged(int index)
{
    usrConf->setMuInstrVoice2(index);
}

void GuiMupic::on_comboBox_v3Composer_currentIndexChanged(int index)
{
    usrConf->setMuCompVoice3(index);
}

void GuiMupic::on_comboBox_v3Instrument_currentIndexChanged(int index)
{
    usrConf->setMuInstrVoice3(index);
}

void GuiMupic::on_comboBox_v4Composer_currentIndexChanged(int index)
{
    usrConf->setMuCompVoice4(index);
}

void GuiMupic::on_comboBox_v4Instrument_currentIndexChanged(int index)
{
    usrConf->setMuInstrVoice4(index);
}

void GuiMupic::on_comboBox_composerMixer_currentIndexChanged(int index)
{
    usrConf->setMuCompMix(index);
}

void GuiMupic::on_comboBox_v3Composer_3_currentIndexChanged(int index)
{
    usrConf->setMuTempo(index);
}
