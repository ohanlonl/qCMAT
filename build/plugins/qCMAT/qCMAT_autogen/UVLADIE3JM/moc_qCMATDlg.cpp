/****************************************************************************
** Meta object code from reading C++ file 'qCMATDlg.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../plugins/qCMAT/src/qCMATDlg.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qCMATDlg.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_qCMATDlg_t {
    QByteArrayData data[11];
    char stringdata0[150];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_qCMATDlg_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_qCMATDlg_t qt_meta_stringdata_qCMATDlg = {
    {
QT_MOC_LITERAL(0, 0, 8), // "qCMATDlg"
QT_MOC_LITERAL(1, 9, 19), // "cancelButtonClicked"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 17), // "startVolumeDialog"
QT_MOC_LITERAL(4, 48, 18), // "startSurfaceDialog"
QT_MOC_LITERAL(5, 67, 7), // "startGL"
QT_MOC_LITERAL(6, 75, 12), // "printConsole"
QT_MOC_LITERAL(7, 88, 11), // "std::string"
QT_MOC_LITERAL(8, 100, 10), // "printError"
QT_MOC_LITERAL(9, 111, 20), // "startShorelineDialog"
QT_MOC_LITERAL(10, 132, 17) // "viewButtonClicked"

    },
    "qCMATDlg\0cancelButtonClicked\0\0"
    "startVolumeDialog\0startSurfaceDialog\0"
    "startGL\0printConsole\0std::string\0"
    "printError\0startShorelineDialog\0"
    "viewButtonClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_qCMATDlg[] = {

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
       6,    1,   58,    2, 0x09 /* Protected */,
       8,    1,   61,    2, 0x09 /* Protected */,
       9,    0,   64,    2, 0x09 /* Protected */,
      10,    0,   65,    2, 0x09 /* Protected */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    2,
    QMetaType::Void, 0x80000000 | 7,    2,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void qCMATDlg::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        qCMATDlg *_t = static_cast<qCMATDlg *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->cancelButtonClicked(); break;
        case 1: _t->startVolumeDialog(); break;
        case 2: _t->startSurfaceDialog(); break;
        case 3: _t->startGL(); break;
        case 4: _t->printConsole((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 5: _t->printError((*reinterpret_cast< std::string(*)>(_a[1]))); break;
        case 6: _t->startShorelineDialog(); break;
        case 7: _t->viewButtonClicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject qCMATDlg::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_qCMATDlg.data,
      qt_meta_data_qCMATDlg,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *qCMATDlg::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *qCMATDlg::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_qCMATDlg.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "Ui::CMATDlg"))
        return static_cast< Ui::CMATDlg*>(this);
    return QDialog::qt_metacast(_clname);
}

int qCMATDlg::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
