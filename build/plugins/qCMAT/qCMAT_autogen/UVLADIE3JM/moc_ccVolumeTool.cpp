/****************************************************************************
** Meta object code from reading C++ file 'ccVolumeTool.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../plugins/qCMAT/src/ccVolumeTool.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ccVolumeTool.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ccVolumeTool_t {
    QByteArrayData data[10];
    char stringdata0[128];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ccVolumeTool_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ccVolumeTool_t qt_meta_stringdata_ccVolumeTool = {
    {
QT_MOC_LITERAL(0, 0, 12), // "ccVolumeTool"
QT_MOC_LITERAL(1, 13, 11), // "testConsole"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 13), // "processClouds"
QT_MOC_LITERAL(4, 40, 13), // "contourVolume"
QT_MOC_LITERAL(5, 54, 13), // "displayVolmes"
QT_MOC_LITERAL(6, 68, 10), // "saveVolume"
QT_MOC_LITERAL(7, 79, 15), // "readCSVContours"
QT_MOC_LITERAL(8, 95, 14), // "loadContVolume"
QT_MOC_LITERAL(9, 110, 17) // "saveCloudContours"

    },
    "ccVolumeTool\0testConsole\0\0processClouds\0"
    "contourVolume\0displayVolmes\0saveVolume\0"
    "readCSVContours\0loadContVolume\0"
    "saveCloudContours"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ccVolumeTool[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x09 /* Protected */,
       3,    0,   55,    2, 0x09 /* Protected */,
       4,    0,   56,    2, 0x09 /* Protected */,
       5,    0,   57,    2, 0x09 /* Protected */,
       6,    0,   58,    2, 0x09 /* Protected */,
       7,    0,   59,    2, 0x09 /* Protected */,
       8,    0,   60,    2, 0x09 /* Protected */,
       9,    0,   61,    2, 0x09 /* Protected */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ccVolumeTool::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ccVolumeTool *_t = static_cast<ccVolumeTool *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->testConsole(); break;
        case 1: _t->processClouds(); break;
        case 2: _t->contourVolume(); break;
        case 3: _t->displayVolmes(); break;
        case 4: _t->saveVolume(); break;
        case 5: _t->readCSVContours(); break;
        case 6: _t->loadContVolume(); break;
        case 7: _t->saveCloudContours(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject ccVolumeTool::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ccVolumeTool.data,
      qt_meta_data_ccVolumeTool,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ccVolumeTool::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ccVolumeTool::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ccVolumeTool.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "Ui::ccVolumeTool"))
        return static_cast< Ui::ccVolumeTool*>(this);
    return QDialog::qt_metacast(_clname);
}

int ccVolumeTool::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE