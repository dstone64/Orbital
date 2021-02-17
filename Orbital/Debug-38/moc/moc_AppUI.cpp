/****************************************************************************
** Meta object code from reading C++ file 'AppUI.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../AppUI.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'AppUI.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AppUI_t {
    QByteArrayData data[30];
    char stringdata0[514];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AppUI_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AppUI_t qt_meta_stringdata_AppUI = {
    {
QT_MOC_LITERAL(0, 0, 5), // "AppUI"
QT_MOC_LITERAL(1, 6, 17), // "Signal_LoadModule"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 8), // "filename"
QT_MOC_LITERAL(4, 34, 16), // "Signal_RunModule"
QT_MOC_LITERAL(5, 51, 17), // "Signal_StopModule"
QT_MOC_LITERAL(6, 69, 20), // "Signal_CustomControl"
QT_MOC_LITERAL(7, 90, 2), // "cc"
QT_MOC_LITERAL(8, 93, 22), // "Signal_CreateNewScript"
QT_MOC_LITERAL(9, 116, 19), // "Signal_ParamsImport"
QT_MOC_LITERAL(10, 136, 19), // "Signal_ParamsExport"
QT_MOC_LITERAL(11, 156, 35), // "Signal_PlotEditor_UpdateArran..."
QT_MOC_LITERAL(12, 192, 18), // "QVector<GridPoint>"
QT_MOC_LITERAL(13, 211, 15), // "plotArrangement"
QT_MOC_LITERAL(14, 227, 34), // "Signal_PlotEditor_UpdatePrope..."
QT_MOC_LITERAL(15, 262, 15), // "QVector<size_t>"
QT_MOC_LITERAL(16, 278, 15), // "plotUpdateQueue"
QT_MOC_LITERAL(17, 294, 21), // "Signal_UpdateDataInfo"
QT_MOC_LITERAL(18, 316, 8), // "dataInfo"
QT_MOC_LITERAL(19, 325, 33), // "QVector<std::pair<bool,QStrin..."
QT_MOC_LITERAL(20, 359, 11), // "dataSetInfo"
QT_MOC_LITERAL(21, 371, 23), // "Signal_UpdatePythonPath"
QT_MOC_LITERAL(22, 395, 11), // "Signal_Save"
QT_MOC_LITERAL(23, 407, 13), // "QVector<bool>"
QT_MOC_LITERAL(24, 421, 9), // "timeStamp"
QT_MOC_LITERAL(25, 431, 20), // "Signal_ExampleScript"
QT_MOC_LITERAL(26, 452, 8), // "scriptID"
QT_MOC_LITERAL(27, 461, 22), // "Signal_ReferenceManual"
QT_MOC_LITERAL(28, 484, 26), // "Slot_UpdatePlotArrangement"
QT_MOC_LITERAL(29, 511, 2) // "pa"

    },
    "AppUI\0Signal_LoadModule\0\0filename\0"
    "Signal_RunModule\0Signal_StopModule\0"
    "Signal_CustomControl\0cc\0Signal_CreateNewScript\0"
    "Signal_ParamsImport\0Signal_ParamsExport\0"
    "Signal_PlotEditor_UpdateArrangement\0"
    "QVector<GridPoint>\0plotArrangement\0"
    "Signal_PlotEditor_UpdateProperties\0"
    "QVector<size_t>\0plotUpdateQueue\0"
    "Signal_UpdateDataInfo\0dataInfo\0"
    "QVector<std::pair<bool,QString> >\0"
    "dataSetInfo\0Signal_UpdatePythonPath\0"
    "Signal_Save\0QVector<bool>\0timeStamp\0"
    "Signal_ExampleScript\0scriptID\0"
    "Signal_ReferenceManual\0"
    "Slot_UpdatePlotArrangement\0pa"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AppUI[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      14,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   89,    2, 0x06 /* Public */,
       4,    0,   92,    2, 0x06 /* Public */,
       5,    0,   93,    2, 0x06 /* Public */,
       6,    1,   94,    2, 0x06 /* Public */,
       8,    1,   97,    2, 0x06 /* Public */,
       9,    1,  100,    2, 0x06 /* Public */,
      10,    1,  103,    2, 0x06 /* Public */,
      11,    1,  106,    2, 0x06 /* Public */,
      14,    1,  109,    2, 0x06 /* Public */,
      17,    2,  112,    2, 0x06 /* Public */,
      21,    0,  117,    2, 0x06 /* Public */,
      22,    3,  118,    2, 0x06 /* Public */,
      25,    1,  125,    2, 0x06 /* Public */,
      27,    0,  128,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      28,    1,  129,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::UInt,    7,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void, 0x80000000 | 15,   16,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 19,   18,   20,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 23, QMetaType::Bool,    2,    2,   24,
    QMetaType::Void, QMetaType::UInt,   26,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 12,   29,

       0        // eod
};

void AppUI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<AppUI *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Signal_LoadModule((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->Signal_RunModule(); break;
        case 2: _t->Signal_StopModule(); break;
        case 3: _t->Signal_CustomControl((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 4: _t->Signal_CreateNewScript((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->Signal_ParamsImport((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->Signal_ParamsExport((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->Signal_PlotEditor_UpdateArrangement((*reinterpret_cast< const QVector<GridPoint>(*)>(_a[1]))); break;
        case 8: _t->Signal_PlotEditor_UpdateProperties((*reinterpret_cast< const QVector<size_t>(*)>(_a[1]))); break;
        case 9: _t->Signal_UpdateDataInfo((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QVector<std::pair<bool,QString> >(*)>(_a[2]))); break;
        case 10: _t->Signal_UpdatePythonPath(); break;
        case 11: _t->Signal_Save((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QVector<bool>(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 12: _t->Signal_ExampleScript((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 13: _t->Signal_ReferenceManual(); break;
        case 14: _t->Slot_UpdatePlotArrangement((*reinterpret_cast< const QVector<GridPoint>(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 11:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<bool> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (AppUI::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AppUI::Signal_LoadModule)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (AppUI::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AppUI::Signal_RunModule)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (AppUI::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AppUI::Signal_StopModule)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (AppUI::*)(unsigned int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AppUI::Signal_CustomControl)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (AppUI::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AppUI::Signal_CreateNewScript)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (AppUI::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AppUI::Signal_ParamsImport)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (AppUI::*)(const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AppUI::Signal_ParamsExport)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (AppUI::*)(const QVector<GridPoint> & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AppUI::Signal_PlotEditor_UpdateArrangement)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (AppUI::*)(const QVector<size_t> & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AppUI::Signal_PlotEditor_UpdateProperties)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (AppUI::*)(const QString & , const QVector<std::pair<bool,QString>> & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AppUI::Signal_UpdateDataInfo)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (AppUI::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AppUI::Signal_UpdatePythonPath)) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (AppUI::*)(const QString & , const QVector<bool> & , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AppUI::Signal_Save)) {
                *result = 11;
                return;
            }
        }
        {
            using _t = void (AppUI::*)(unsigned int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AppUI::Signal_ExampleScript)) {
                *result = 12;
                return;
            }
        }
        {
            using _t = void (AppUI::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AppUI::Signal_ReferenceManual)) {
                *result = 13;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject AppUI::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_AppUI.data,
    qt_meta_data_AppUI,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *AppUI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AppUI::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AppUI.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int AppUI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void AppUI::Signal_LoadModule(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void AppUI::Signal_RunModule()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void AppUI::Signal_StopModule()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void AppUI::Signal_CustomControl(unsigned int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void AppUI::Signal_CreateNewScript(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void AppUI::Signal_ParamsImport(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void AppUI::Signal_ParamsExport(const QString & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void AppUI::Signal_PlotEditor_UpdateArrangement(const QVector<GridPoint> & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void AppUI::Signal_PlotEditor_UpdateProperties(const QVector<size_t> & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void AppUI::Signal_UpdateDataInfo(const QString & _t1, const QVector<std::pair<bool,QString>> & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void AppUI::Signal_UpdatePythonPath()
{
    QMetaObject::activate(this, &staticMetaObject, 10, nullptr);
}

// SIGNAL 11
void AppUI::Signal_Save(const QString & _t1, const QVector<bool> & _t2, bool _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void AppUI::Signal_ExampleScript(unsigned int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void AppUI::Signal_ReferenceManual()
{
    QMetaObject::activate(this, &staticMetaObject, 13, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
