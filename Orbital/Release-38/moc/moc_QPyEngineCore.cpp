/****************************************************************************
** Meta object code from reading C++ file 'QPyEngineCore.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../QPyEngine/include/QPyEngineCore.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QPyEngineCore.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QPyEngine__QPyEngineCore_t {
    QByteArrayData data[8];
    char stringdata0[80];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QPyEngine__QPyEngineCore_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QPyEngine__QPyEngineCore_t qt_meta_stringdata_QPyEngine__QPyEngineCore = {
    {
QT_MOC_LITERAL(0, 0, 24), // "QPyEngine::QPyEngineCore"
QT_MOC_LITERAL(1, 25, 10), // "Slot_FnEnd"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 9), // "PyObject*"
QT_MOC_LITERAL(4, 47, 3), // "ret"
QT_MOC_LITERAL(5, 51, 6), // "errStr"
QT_MOC_LITERAL(6, 58, 15), // "QPyEngine_RetFn"
QT_MOC_LITERAL(7, 74, 5) // "retFn"

    },
    "QPyEngine::QPyEngineCore\0Slot_FnEnd\0"
    "\0PyObject*\0ret\0errStr\0QPyEngine_RetFn\0"
    "retFn"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QPyEngine__QPyEngineCore[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    3,   19,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::QString, 0x80000000 | 6,    4,    5,    7,

       0        // eod
};

void QPyEngine::QPyEngineCore::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QPyEngineCore *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Slot_FnEnd((*reinterpret_cast< PyObject*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QPyEngine_RetFn(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 2:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QPyEngine_RetFn >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QPyEngine::QPyEngineCore::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_QPyEngine__QPyEngineCore.data,
    qt_meta_data_QPyEngine__QPyEngineCore,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QPyEngine::QPyEngineCore::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QPyEngine::QPyEngineCore::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QPyEngine__QPyEngineCore.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QPyEngine::QPyEngineCore::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
