/****************************************************************************
** Meta object code from reading C++ file 'audioplay.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../AudioPlay/audioplay.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'audioplay.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AudioPlay_t {
    QByteArrayData data[22];
    char stringdata0[502];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AudioPlay_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AudioPlay_t qt_meta_stringdata_AudioPlay = {
    {
QT_MOC_LITERAL(0, 0, 9), // "AudioPlay"
QT_MOC_LITERAL(1, 10, 32), // "on_tableWidget_cellDoubleClicked"
QT_MOC_LITERAL(2, 43, 0), // ""
QT_MOC_LITERAL(3, 44, 3), // "row"
QT_MOC_LITERAL(4, 48, 6), // "column"
QT_MOC_LITERAL(5, 55, 30), // "on_PushButton_OpenFile_clicked"
QT_MOC_LITERAL(6, 86, 30), // "on_PushButton_PlayStop_clicked"
QT_MOC_LITERAL(7, 117, 30), // "on_PushButton_Previous_clicked"
QT_MOC_LITERAL(8, 148, 26), // "on_PushButton_Next_clicked"
QT_MOC_LITERAL(9, 175, 29), // "on_Slider_Volume_valueChanged"
QT_MOC_LITERAL(10, 205, 5), // "value"
QT_MOC_LITERAL(11, 211, 20), // "do_getduration_slots"
QT_MOC_LITERAL(12, 232, 8), // "playtime"
QT_MOC_LITERAL(13, 241, 23), // "do_updatePosition_slots"
QT_MOC_LITERAL(14, 265, 8), // "position"
QT_MOC_LITERAL(15, 274, 36), // "on_Slider_ProgressBar_sliderR..."
QT_MOC_LITERAL(16, 311, 30), // "on_PushButton_PlayMode_clicked"
QT_MOC_LITERAL(17, 342, 33), // "on_PushButton_DeleteMusic_cli..."
QT_MOC_LITERAL(18, 376, 31), // "on_pushButton_WindowMin_clicked"
QT_MOC_LITERAL(19, 408, 31), // "on_pushButton_WindowMax_clicked"
QT_MOC_LITERAL(20, 440, 32), // "on_pushButton_WindowExit_clicked"
QT_MOC_LITERAL(21, 473, 28) // "on_commandLinkButton_clicked"

    },
    "AudioPlay\0on_tableWidget_cellDoubleClicked\0"
    "\0row\0column\0on_PushButton_OpenFile_clicked\0"
    "on_PushButton_PlayStop_clicked\0"
    "on_PushButton_Previous_clicked\0"
    "on_PushButton_Next_clicked\0"
    "on_Slider_Volume_valueChanged\0value\0"
    "do_getduration_slots\0playtime\0"
    "do_updatePosition_slots\0position\0"
    "on_Slider_ProgressBar_sliderReleased\0"
    "on_PushButton_PlayMode_clicked\0"
    "on_PushButton_DeleteMusic_clicked\0"
    "on_pushButton_WindowMin_clicked\0"
    "on_pushButton_WindowMax_clicked\0"
    "on_pushButton_WindowExit_clicked\0"
    "on_commandLinkButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AudioPlay[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   89,    2, 0x08 /* Private */,
       5,    0,   94,    2, 0x08 /* Private */,
       6,    0,   95,    2, 0x08 /* Private */,
       7,    0,   96,    2, 0x08 /* Private */,
       8,    0,   97,    2, 0x08 /* Private */,
       9,    1,   98,    2, 0x08 /* Private */,
      11,    1,  101,    2, 0x08 /* Private */,
      13,    1,  104,    2, 0x08 /* Private */,
      15,    0,  107,    2, 0x08 /* Private */,
      16,    0,  108,    2, 0x08 /* Private */,
      17,    0,  109,    2, 0x08 /* Private */,
      18,    0,  110,    2, 0x08 /* Private */,
      19,    0,  111,    2, 0x08 /* Private */,
      20,    0,  112,    2, 0x08 /* Private */,
      21,    0,  113,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::LongLong,   12,
    QMetaType::Void, QMetaType::LongLong,   14,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void AudioPlay::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AudioPlay *_t = static_cast<AudioPlay *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_tableWidget_cellDoubleClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->on_PushButton_OpenFile_clicked(); break;
        case 2: _t->on_PushButton_PlayStop_clicked(); break;
        case 3: _t->on_PushButton_Previous_clicked(); break;
        case 4: _t->on_PushButton_Next_clicked(); break;
        case 5: _t->on_Slider_Volume_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->do_getduration_slots((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 7: _t->do_updatePosition_slots((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 8: _t->on_Slider_ProgressBar_sliderReleased(); break;
        case 9: _t->on_PushButton_PlayMode_clicked(); break;
        case 10: _t->on_PushButton_DeleteMusic_clicked(); break;
        case 11: _t->on_pushButton_WindowMin_clicked(); break;
        case 12: _t->on_pushButton_WindowMax_clicked(); break;
        case 13: _t->on_pushButton_WindowExit_clicked(); break;
        case 14: _t->on_commandLinkButton_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject AudioPlay::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_AudioPlay.data,
      qt_meta_data_AudioPlay,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *AudioPlay::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AudioPlay::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AudioPlay.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int AudioPlay::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
