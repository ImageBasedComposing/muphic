#ifndef GUIMUPIC_H
#define GUIMUPIC_H

#include <QMainWindow>

#include "ui_guimupic.h"
#include "launcher.h"
#include "polygonwidget.h"
#include "UsrConf.h"
#include "aux_functions.h"
#include "muphicconfig.h"

#include <QFile>
#include <QMessageBox>
#include <QFileDialog>

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QPixmap>
#include <QTime>
#include <QSize>


#include <phonon/audiooutput.h>
#include <phonon/seekslider.h>
#include <phonon/mediaobject.h>
#include <phonon/volumeslider.h>
#include <phonon/backendcapabilities.h>
#include <phonon/mediasource.h>

/*
#include <Phonon/AudioOutput>
#include <Phonon/SeekSlider>
#include <Phonon/MediaObject>
#include <Phonon/VolumeSlider>
#include <Phonon/BackendCapabilities>
#include <Phonon/MediaSource>
*/
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

    void paintEvent(QPaintEvent*);

private slots:
    void on_toolButton_OutputMidi_clicked();

    void on_toolButton_InputPic_clicked();

    void on_pushButton_Generate_clicked();

    void on_pushButton_Stop_clicked();

    void on_pushButton_Play_clicked();

    void on_pushButton_Analyze_clicked();

    void stateChanged(Phonon::State newState, Phonon::State oldState);

    void tick(qint64 time);

    void setupActions();

    void on_pushButton_pause_clicked();

private:
    Ui::GuiMupic *ui;
    QGraphicsScene * newScene;
    PolygonWidget * poly;
    MuphicConfig * muphicConfig;

    QString imageFile;
    Launcher* l;
    pid_t pidPlay;

    Phonon::MediaObject *mediaObject;
    Phonon::AudioOutput *audioOutput;
    Phonon::MediaSource mediaSource;

    bool is_paused;
    qint64 mediaTime;

    QAction *playAction;
    QAction *pauseAction;
    QAction *stopAction;
};

#endif // GUIMUPIC_H
