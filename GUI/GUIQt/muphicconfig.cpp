#include "muphicconfig.h"

MuphicConfig::MuphicConfig(QWidget *parent) :
    QTabWidget(parent),
    ui(new Ui::MuphicConfig)
{
    ui->setupUi(this);

    l = new Launcher();
    pidAnal = pidComp = -1;

    analysing = false;
    composing = false;
}

MuphicConfig::~MuphicConfig()
{
    delete ui;
    delete usrConf;
}

void MuphicConfig::initialize()
{
    //We initialize Phic
    usrConf = new UsrConf();
    usrConf->setPhicNoiseSelec(0);
    usrConf->setPhicPolygonSimp(2);
    usrConf->setPhicColorLevels(3);
    usrConf->setPhicAnalysisDetail(50);
    usrConf->setPhicFilterSelect(3);
    usrConf->setPhicThresholdSelec(50);
    usrConf->setPhicThresholdH(35);
    usrConf->setPhicThresholdS(20);
    usrConf->setPhicThresholdV(50);

    //We initialize Mu
    usrConf->setMuReconColors(1);
    usrConf->setMuCompVoice1(2);
    usrConf->setMuInstrVoice1(45);
    usrConf->setMuCompVoice2(2);
    usrConf->setMuInstrVoice2(73);
    usrConf->setMuCompVoice3(2);
    usrConf->setMuInstrVoice3(32);
    usrConf->setMuCompVoice4(2);
    usrConf->setMuInstrVoice4(128);
    usrConf->setMuCompMix(2);
    usrConf->setMuTempo(120);
    usrConf->setPhicAnalysisDetail(50);

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

void MuphicConfig::setupActions()
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

void MuphicConfig::tick(qint64 time)
{
    QTime displayTime(0, (time / 60000) % 60, (time / 1000) % 60);

    ui->timeLcd->display(displayTime.toString("mm:ss"));
    //ui->horizontalSlider_Seek->setSliderPosition(mediaObject->currentTime()*1000 / mediaObject->totalTime());
}

void MuphicConfig::stateChanged(Phonon::State newState, Phonon::State /* oldState */)
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

void MuphicConfig::on_toolButton_OutputMidi_clicked()
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

void MuphicConfig::on_toolButton_InputPic_clicked()
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

void MuphicConfig::on_pushButton_Generate_clicked()
{

    if (composing)
    {
        #ifdef __WINDOWS
            system("taskkill /F /T /IM Muphic.exe");
        #endif
        #ifdef __LINUX
            l->killProcess(pidComp);
        #endif
        composing = false;
        ui->pushButton_Generate->setText("Compose");
    }
    else
    {
        #ifdef __WINDOWS
            mediaSource = Phonon::MediaSource("");
        #endif

        mediaObject->setCurrentSource(mediaSource);

        std::string picFile = ui->lineEdit_InputPic->text().toStdString();
        std::string muFile = ui->lineEdit_OutputMidi->text().toStdString();

        usrConf->setMuOutputFile(muFile);
        usrConf->setPhicActive(false);
        usrConf->setMuDebug(false);
        usrConf->setMuActive(true);
        //std::string name = changeExtension(fileName.toStdString(), "xml");
        usrConf->write("user_conf.xml");
        std::string userConfFile = "user_conf.xml";

        std::string args[] = {userConfFile, picFile};
        pidComp = l->launchAndGo(2, Launcher::MUPHIC, args);
        ui->pushButton_Generate->setText("Stop");
        composing = true;
    }
}

void MuphicConfig::on_pushButton_pause_clicked()
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

void MuphicConfig::on_pushButton_Stop_clicked()
{
    mediaObject->stop();
    #ifdef __WINDOWS
        mediaSource = Phonon::MediaSource("");
    #endif

    mediaObject->setCurrentSource(mediaSource);
    ui->pushButton_pause->setEnabled(false);
}

void MuphicConfig::paintEvent(QPaintEvent*)
{
    if (analysing)
    {
        FILE *f=NULL;
        f = fopen("analysis_log","r");
        if (f)
        {
            fclose(f);
            ui->polyWidget->load(imageFile.toStdString());
            ui->polyWidget->setMinimumHeight(ui->polyWidget->iHeight);
            ui->polyWidget->setMinimumWidth(ui->polyWidget->iWidth);
            ui->pushButton_Generate->setEnabled(true);
            analysing = false;
            remove("analysis_log");
            ui->pushButton_Analyze->setText("Analyze");
        }
    }
    if (composing)
    {
        FILE *f=NULL;
        f = fopen("composition_log","r");
        if (f)
        {
            fclose(f);

            composing = false;
            remove("composition_log");
            ui->pushButton_Generate->setText("Compose");
        }
    }


}


void MuphicConfig::on_pushButton_Play_clicked()
{
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

void MuphicConfig::on_pushButton_Analyze_clicked()
{
    if (analysing)
    {
        #ifdef __WINDOWS
            system("taskkill /F /T /IM Muphic.exe");
        #endif
        #ifdef __LINUX
            l->killProcess(pidAnal);
        #endif

        analysing = false;
        ui->pushButton_Analyze->setText("Analyze");
    }
    else
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
        pidAnal = l->launchAndGo(2, Launcher::MUPHIC, args);
        analysing = true;
        ui->pushButton_Analyze->setText("Stop");

/*
        ui->polyWidget->load(imageFile.toStdString());
        ui->polyWidget->setMinimumHeight(ui->polyWidget->iHeight);
        ui->polyWidget->setMinimumWidth(ui->polyWidget->iWidth);
        ui->pushButton_Generate->setEnabled(true);*/
     }
    }
}


void MuphicConfig::on_filterSelComboBox_currentIndexChanged(int index)
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

void MuphicConfig::on_horizontalSlider_2_valueChanged(int position)
{
    usrConf->setPhicThresholdSelec(position);
    char a[10];
    ui->tLabel->setText(our_itoa(position,a,10));
}


// NOISE MINDFUCK!

void MuphicConfig::on_horizontalSlider_6_valueChanged(int position)
{
    usrConf->setPhicPolygonSimp(position);
    char a[10];
    ui->labelPolSimp->setText(our_itoa(position,a,10));
}

void MuphicConfig::on_horizontalSlider_colorLevels_valueChanged(int position)
{
    usrConf->setPhicColorLevels(position);
    char a[10];
    ui->labelColorLevels->setText(our_itoa(position,a,10));
}

void MuphicConfig::on_horizontalSliderTH_valueChanged(int position)
{
    usrConf->setPhicThresholdH(position);
    char a[10];
    ui->labelThresholdH->setText(our_itoa(position,a,10));
}

void MuphicConfig::on_horizontalSliderTS_valueChanged(int position)
{
    usrConf->setPhicThresholdS(position);
    char a[10];
    ui->labelThresholdS->setText(our_itoa(position,a,10));
}

void MuphicConfig::on_horizontalSliderTV_valueChanged(int position)
{
    usrConf->setPhicThresholdV(position);
    char a[10];
    ui->labelThresholdV->setText(our_itoa(position,a,10));
}

void MuphicConfig::on_comboBox_reconColors_currentIndexChanged(int index)
{
    usrConf->setMuReconColors(index);
}

void MuphicConfig::on_comboBox_v1Composer_currentIndexChanged(int index)
{
    usrConf->setMuCompVoice1(index);
}

void MuphicConfig::on_comboBox_v1Instrument_currentIndexChanged(int index)
{
    int instrument = 45;

    switch(index)
    {
    case 0:
        instrument = 0;
        break;
    case 1:
        instrument = 6;
        break;
    case 2:
        instrument = 20;
        break;
    case 3:
        instrument = 24;
        break;
    case 4:
        instrument = 32;
        break;
    case 5:
        instrument = 88;
        break;
    case 6:
        instrument = 45;
        break;
    case 7:
        instrument = 52;
        break;
    case 8:
        instrument = 55;
        break;
    case 9:
        instrument = 56;
        break;
    case 10:
        instrument = 66;
        break;
    case 11:
        instrument = 73;
        break;
    case 12:
        instrument = 85;
        break;
    }

    usrConf->setMuInstrVoice1(instrument);
}

void MuphicConfig::on_comboBox_v2Composer_currentIndexChanged(int index)
{
    usrConf->setMuCompVoice2(index);
}

void MuphicConfig::on_comboBox_v2Instruments_currentIndexChanged(int index)
{
    int instrument = 73;

    switch(index)
    {
    case 0:
        instrument = 0;
        break;
    case 1:
        instrument = 6;
        break;
    case 2:
        instrument = 20;
        break;
    case 3:
        instrument = 24;
        break;
    case 4:
        instrument = 32;
        break;
    case 5:
        instrument = 88;
        break;
    case 6:
        instrument = 45;
        break;
    case 7:
        instrument = 52;
        break;
    case 8:
        instrument = 55;
        break;
    case 9:
        instrument = 56;
        break;
    case 10:
        instrument = 66;
        break;
    case 11:
        instrument = 73;
        break;
    case 12:
        instrument = 85;
        break;
    }
    usrConf->setMuInstrVoice2(instrument);
}

void MuphicConfig::on_comboBox_v3Composer_currentIndexChanged(int index)
{
    usrConf->setMuCompVoice3(index);
}

void MuphicConfig::on_comboBox_v3Instrument_currentIndexChanged(int index)
{
    int instrument = 32;

    switch(index)
    {
    case 0:
        instrument = 0;
        break;
    case 1:
        instrument = 6;
        break;
    case 2:
        instrument = 20;
        break;
    case 3:
        instrument = 24;
        break;
    case 4:
        instrument = 32;
        break;
    case 5:
        instrument = 88;
        break;
    case 6:
        instrument = 45;
        break;
    case 7:
        instrument = 52;
        break;
    case 8:
        instrument = 55;
        break;
    case 9:
        instrument = 56;
        break;
    case 10:
        instrument = 66;
        break;
    case 11:
        instrument = 73;
        break;
    case 12:
        instrument = 85;
        break;
    }

    usrConf->setMuInstrVoice3(instrument);
}

void MuphicConfig::on_comboBox_v4Composer_currentIndexChanged(int index)
{
    int instrument = 128;
    usrConf->setMuCompVoice4(instrument);
}

void MuphicConfig::on_comboBox_v4Instrument_currentIndexChanged(int index)
{
    usrConf->setMuInstrVoice4(index);
}

void MuphicConfig::on_comboBox_composerMixer_currentIndexChanged(int index)
{
    usrConf->setMuCompMix(index);
}

void MuphicConfig::on_comboBox_v3Composer_3_currentIndexChanged(int index)
{
    usrConf->setMuTempo(index);
}

void MuphicConfig::on_horizontalSlider_3_valueChanged(int position)
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

void MuphicConfig::on_horizontalSlider_AnalisisDepth_valueChanged(int value)
{
    usrConf->setPhicAnalysisDetail(value);
    char a[10];
    ui->labelAnalysisDepth->setText(our_itoa(value,a,10));
}
