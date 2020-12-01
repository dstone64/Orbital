/****************************************************************************
** Meta object code from reading C++ file 'PlotEditorDialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../UI/PlotEditorDialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'PlotEditorDialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PlotEditorDialog_t {
    QByteArrayData data[13];
    char stringdata0[281];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PlotEditorDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PlotEditorDialog_t qt_meta_stringdata_PlotEditorDialog = {
    {
QT_MOC_LITERAL(0, 0, 16), // "PlotEditorDialog"
QT_MOC_LITERAL(1, 17, 28), // "Signal_UpdatePlotArrangement"
QT_MOC_LITERAL(2, 46, 0), // ""
QT_MOC_LITERAL(3, 47, 18), // "QVector<GridPoint>"
QT_MOC_LITERAL(4, 66, 15), // "plotArrangement"
QT_MOC_LITERAL(5, 82, 27), // "Signal_UpdatePlotProperties"
QT_MOC_LITERAL(6, 110, 15), // "QVector<size_t>"
QT_MOC_LITERAL(7, 126, 15), // "plotUpdateQueue"
QT_MOC_LITERAL(8, 142, 26), // "on_pushButton_save_clicked"
QT_MOC_LITERAL(9, 169, 28), // "on_pushButton_cancel_clicked"
QT_MOC_LITERAL(10, 198, 27), // "on_pushButton_apply_clicked"
QT_MOC_LITERAL(11, 226, 37), // "on_pushButton_gridArrangement..."
QT_MOC_LITERAL(12, 264, 16) // "Slot_GridChanged"

    },
    "PlotEditorDialog\0Signal_UpdatePlotArrangement\0"
    "\0QVector<GridPoint>\0plotArrangement\0"
    "Signal_UpdatePlotProperties\0QVector<size_t>\0"
    "plotUpdateQueue\0on_pushButton_save_clicked\0"
    "on_pushButton_cancel_clicked\0"
    "on_pushButton_apply_clicked\0"
    "on_pushButton_gridArrangement_clicked\0"
    "Slot_GridChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PlotEditorDialog[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,
       5,    1,   52,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   55,    2, 0x0a /* Public */,
       9,    0,   56,    2, 0x0a /* Public */,
      10,    0,   57,    2, 0x0a /* Public */,
      11,    0,   58,    2, 0x0a /* Public */,
      12,    0,   59,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    7,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void PlotEditorDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<PlotEditorDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Signal_UpdatePlotArrangement((*reinterpret_cast< const QVector<GridPoint>(*)>(_a[1]))); break;
        case 1: _t->Signal_UpdatePlotProperties((*reinterpret_cast< const QVector<size_t>(*)>(_a[1]))); break;
        case 2: _t->on_pushButton_save_clicked(); break;
        case 3: _t->on_pushButton_cancel_clicked(); break;
        case 4: _t->on_pushButton_apply_clicked(); break;
        case 5: _t->on_pushButton_gridArrangement_clicked(); break;
        case 6: _t->Slot_GridChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<GridPoint> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (PlotEditorDialog::*)(const QVector<GridPoint> & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PlotEditorDialog::Signal_UpdatePlotArrangement)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (PlotEditorDialog::*)(const QVector<size_t> & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PlotEditorDialog::Signal_UpdatePlotProperties)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject PlotEditorDialog::staticMetaObject = { {
    &QDialog::staticMetaObject,
    qt_meta_stringdata_PlotEditorDialog.data,
    qt_meta_data_PlotEditorDialog,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *PlotEditorDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PlotEditorDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PlotEditorDialog.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int PlotEditorDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void PlotEditorDialog::Signal_UpdatePlotArrangement(const QVector<GridPoint> & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void PlotEditorDialog::Signal_UpdatePlotProperties(const QVector<size_t> & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
