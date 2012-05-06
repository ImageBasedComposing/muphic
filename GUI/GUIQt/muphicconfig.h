#ifndef MUPHICCONFIG_H
#define MUPHICCONFIG_H

#include <QTabWidget>
#include "UsrConf.h"

namespace Ui {
class MuphicConfig;
}

class MuphicConfig : public QTabWidget
{
    Q_OBJECT
    
public:
    UsrConf * usrConf;

    explicit MuphicConfig(QWidget *parent = 0);
    ~MuphicConfig();
    void initialize();
    void destroy();

private slots:

    void on_filterSelComboBox_currentIndexChanged(int index);

    void on_horizontalSlider_2_valueChanged(int position);

    void on_horizontalSlider_6_valueChanged(int position);

    void on_horizontalSlider_colorLevels_valueChanged(int position);

    void on_horizontalSliderTS_valueChanged(int position);

    void on_horizontalSliderTH_valueChanged(int position);

    void on_horizontalSliderTV_valueChanged(int position);

    void on_comboBox_reconColors_currentIndexChanged(int index);

    void on_comboBox_v1Composer_currentIndexChanged(int index);

    void on_comboBox_v1Instrument_currentIndexChanged(int index);

    void on_comboBox_v2Composer_currentIndexChanged(int index);

    void on_comboBox_v2Instruments_currentIndexChanged(int index);

    void on_comboBox_v3Composer_currentIndexChanged(int index);

    void on_comboBox_v3Instrument_currentIndexChanged(int index);

    void on_comboBox_v4Composer_currentIndexChanged(int index);

    void on_comboBox_v4Instrument_currentIndexChanged(int index);

    void on_comboBox_composerMixer_currentIndexChanged(int index);

    void on_comboBox_v3Composer_3_currentIndexChanged(int index);

    void on_horizontalSlider_3_valueChanged(int value);

    void on_horizontalSlider_AnalisisDepth_valueChanged(int value);

private:
    Ui::MuphicConfig *ui;

    QSize label_2_max;
    QSize tlabel_max;
    QSize hSlider_2_max;
    QSize labelColorLevels_max;
    QSize label_colorLevels_max;
    QSize hSliderColorLevels_max;
    QSize labelThresholdH_max;
    QSize label_ThresholdH_max;
    QSize hSliderThersholdH_max;
    QSize labelThresholdS_max;
    QSize label_ThresholdS_max;
    QSize hSliderThersholdS_max;
    QSize labelThresholdV_max;
    QSize label_ThresholdV_max;
    QSize hSliderThersholdV_max;
};

#endif // MUPHICCONFIG_H
