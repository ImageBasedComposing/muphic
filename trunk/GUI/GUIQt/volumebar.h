#ifndef VOULMEBAR_H
#define VOULMEBAR_H

#include <phonon/volumeslider.h>
#include <QWidget>

class VolumeBar : public Phonon::VolumeSlider
{
    Q_OBJECT
public:
    explicit VolumeBar(QWidget *parent = 0);
};

#endif // VOULMEBAR_H
