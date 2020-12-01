/****************************************************************************
** Meta object code from reading C++ file 'PyEngine.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../PyEngine/PyEngine.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'PyEngine.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PyEngine__Module_t {
    QByteArrayData data[8];
    char stringdata0[76];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PyEngine__Module_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PyEngine__Module_t qt_meta_stringdata_PyEngine__Module = {
    {
QT_MOC_LITERAL(0, 0, 16), // "PyEngine::Module"
QT_MOC_LITERAL(1, 17, 14), // "Signal_FuncEnd"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 9), // "PyObject*"
QT_MOC_LITERAL(4, 43, 3), // "ret"
QT_MOC_LITERAL(5, 47, 6), // "errStr"
QT_MOC_LITERAL(6, 54, 15), // "QPyEngine_RetFn"
QT_MOC_LITERAL(7, 70, 5) // "retFn"

    },
    "PyEngine::Module\0Signal_FuncEnd\0\0"
    "PyObject*\0ret\0errStr\0QPyEngine_RetFn\0"
    "retFn"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PyEngine__Module[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::QString, 0x80000000 | 6,    4,    5,    7,

       0        // eod
};

void PyEngine::Module::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Module *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Signal_FuncEnd((*reinterpret_cast< PyObject*(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QPyEngine_RetFn(*)>(_a[3]))); break;
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
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Module::*)(PyObject * , QString , QPyEngine_RetFn );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Module::Signal_FuncEnd)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject PyEngine::Module::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_PyEngine__Module.data,
    qt_meta_data_PyEngine__Module,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *PyEngine::Module::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PyEngine::Module::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PyEngine__Module.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int PyEngine::Module::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

// SIGNAL 0
void PyEngine::Module::Signal_FuncEnd(PyObject * _t1, QString _t2, QPyEngine_RetFn _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
