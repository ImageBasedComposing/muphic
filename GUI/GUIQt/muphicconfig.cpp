#include "muphicconfig.h"
#include "ui_muphicconfig.h"
#include "muphicconfig.h"

MuphicConfig::MuphicConfig(QWidget *parent) :
    QTabWidget(parent),
    ui(new Ui::MuphicConfig)
{
    ui->setupUi(this);
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
    usrConf->setMuInstrVoice1(index);
}

void MuphicConfig::on_comboBox_v2Composer_currentIndexChanged(int index)
{
    usrConf->setMuCompVoice2(index);
}

void MuphicConfig::on_comboBox_v2Instruments_currentIndexChanged(int index)
{
    usrConf->setMuInstrVoice2(index);
}

void MuphicConfig::on_comboBox_v3Composer_currentIndexChanged(int index)
{
    usrConf->setMuCompVoice3(index);
}

void MuphicConfig::on_comboBox_v3Instrument_currentIndexChanged(int index)
{
    usrConf->setMuInstrVoice3(index);
}

void MuphicConfig::on_comboBox_v4Composer_currentIndexChanged(int index)
{
    usrConf->setMuCompVoice4(index);
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


