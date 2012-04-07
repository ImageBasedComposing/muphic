/****************************************************************************
** Meta object code from reading C++ file 'guimupic.h'
**
** Created: Sat Apr 7 09:20:40 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "guimupic.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'guimupic.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_GuiMupic[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x08,
      45,    9,    9,    9, 0x08,
      78,    9,    9,    9, 0x08,
     111,    9,    9,    9, 0x08,
     140,    9,    9,    9, 0x08,
     169,    9,    9,    9, 0x08,
     207,  201,    9,    9, 0x08,
     262,  253,    9,    9, 0x08,
     301,  253,    9,    9, 0x08,
     340,  253,    9,    9, 0x08,
     397,  379,    9,    9, 0x08,
     444,  439,    9,    9, 0x08,
     457,    9,    9,    9, 0x08,
     472,    9,    9,    9, 0x08,
     502,  253,    9,    9, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_GuiMupic[] = {
    "GuiMupic\0\0on_toolButton_OutputMidi_clicked()\0"
    "on_toolButton_InputPic_clicked()\0"
    "on_pushButton_Generate_clicked()\0"
    "on_pushButton_Stop_clicked()\0"
    "on_pushButton_Play_clicked()\0"
    "on_pushButton_Analyze_clicked()\0index\0"
    "on_filterSelComboBox_currentIndexChanged(int)\0"
    "position\0on_horizontalSlider_2_sliderMoved(int)\0"
    "on_horizontalSlider_3_sliderMoved(int)\0"
    "on_horizontalSlider_6_sliderMoved(int)\0"
    "newState,oldState\0"
    "stateChanged(Phonon::State,Phonon::State)\0"
    "time\0tick(qint64)\0setupActions()\0"
    "on_pushButton_pause_clicked()\0"
    "on_horizontalSlider_Seek_sliderMoved(int)\0"
};

const QMetaObject GuiMupic::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_GuiMupic,
      qt_meta_data_GuiMupic, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &GuiMupic::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *GuiMupic::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *GuiMupic::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GuiMupic))
        return static_cast<void*>(const_cast< GuiMupic*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int GuiMupic::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_toolButton_OutputMidi_clicked(); break;
        case 1: on_toolButton_InputPic_clicked(); break;
        case 2: on_pushButton_Generate_clicked(); break;
        case 3: on_pushButton_Stop_clicked(); break;
        case 4: on_pushButton_Play_clicked(); break;
        case 5: on_pushButton_Analyze_clicked(); break;
        case 6: on_filterSelComboBox_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: on_horizontalSlider_2_sliderMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: on_horizontalSlider_3_sliderMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: on_horizontalSlider_6_sliderMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: stateChanged((*reinterpret_cast< Phonon::State(*)>(_a[1])),(*reinterpret_cast< Phonon::State(*)>(_a[2]))); break;
        case 11: tick((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 12: setupActions(); break;
        case 13: on_pushButton_pause_clicked(); break;
        case 14: on_horizontalSlider_Seek_sliderMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 15;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
