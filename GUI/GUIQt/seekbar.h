#ifndef SEEKBAR_H
#define SEEKBAR_H

#include <phonon/seekslider.h>
//#include <Phonon/SeekSlider.h>
#include <QWidget>

class SeekBar : public Phonon::SeekSlider
{
    Q_OBJECT
public:
    explicit SeekBar(QWidget *parent = 0);
};

#endif // SEEKBAR_H
