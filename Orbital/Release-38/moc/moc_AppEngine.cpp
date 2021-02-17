/****************************************************************************
** Meta object code from reading C++ file 'AppEngine.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../AppEngine.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'AppEngine.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AppEngine_t {
    QByteArrayData data[64];
    char stringdata0[1016];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AppEngine_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AppEngine_t qt_meta_stringdata_AppEngine = {
    {
QT_MOC_LITERAL(0, 0, 9), // "AppEngine"
QT_MOC_LITERAL(1, 10, 10), // "Slot_Error"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 6), // "errMsg"
QT_MOC_LITERAL(4, 29, 8), // "Slot_Msg"
QT_MOC_LITERAL(5, 38, 21), // "Slot_ScriptInitialize"
QT_MOC_LITERAL(6, 60, 23), // "Slot_ScriptInitializeEx"
QT_MOC_LITERAL(7, 84, 18), // "QVector<GridPoint>"
QT_MOC_LITERAL(8, 103, 9), // "Slot_Data"
QT_MOC_LITERAL(9, 113, 10), // "double[32]"
QT_MOC_LITERAL(10, 124, 10), // "Slot_XData"
QT_MOC_LITERAL(11, 135, 16), // "QVector<double>*"
QT_MOC_LITERAL(12, 152, 13), // "Slot_DataInfo"
QT_MOC_LITERAL(13, 166, 17), // "Slot_DataFileInfo"
QT_MOC_LITERAL(14, 184, 19), // "Slot_PlotProperty2D"
QT_MOC_LITERAL(15, 204, 19), // "Slot_PlotPropertyCM"
QT_MOC_LITERAL(16, 224, 13), // "Slot_SaveData"
QT_MOC_LITERAL(17, 238, 14), // "Slot_ClearData"
QT_MOC_LITERAL(18, 253, 11), // "Slot_CMData"
QT_MOC_LITERAL(19, 265, 14), // "Slot_CMDataRow"
QT_MOC_LITERAL(20, 280, 12), // "Slot_CMSetup"
QT_MOC_LITERAL(21, 293, 11), // "Slot_CMShow"
QT_MOC_LITERAL(22, 305, 17), // "Slot_CustomFnName"
QT_MOC_LITERAL(23, 323, 19), // "Slot_AutoSaveConfig"
QT_MOC_LITERAL(24, 343, 20), // "Slot_PlotArrangement"
QT_MOC_LITERAL(25, 364, 15), // "Slot_RetFn_Init"
QT_MOC_LITERAL(26, 380, 14), // "Slot_RetFn_Run"
QT_MOC_LITERAL(27, 395, 15), // "Slot_RetFn_Stop"
QT_MOC_LITERAL(28, 411, 18), // "Slot_RetFn_Custom1"
QT_MOC_LITERAL(29, 430, 18), // "Slot_RetFn_Custom2"
QT_MOC_LITERAL(30, 449, 18), // "Slot_RetFn_Custom3"
QT_MOC_LITERAL(31, 468, 18), // "Slot_RetFn_Custom4"
QT_MOC_LITERAL(32, 487, 18), // "Slot_RetFn_Custom5"
QT_MOC_LITERAL(33, 506, 18), // "Slot_RetFn_Custom6"
QT_MOC_LITERAL(34, 525, 18), // "Slot_RetFn_Custom7"
QT_MOC_LITERAL(35, 544, 18), // "Slot_RetFn_Custom8"
QT_MOC_LITERAL(36, 563, 15), // "Slot_LoadModule"
QT_MOC_LITERAL(37, 579, 8), // "filename"
QT_MOC_LITERAL(38, 588, 14), // "Slot_RunModule"
QT_MOC_LITERAL(39, 603, 15), // "Slot_StopModule"
QT_MOC_LITERAL(40, 619, 18), // "Slot_CustomControl"
QT_MOC_LITERAL(41, 638, 6), // "size_t"
QT_MOC_LITERAL(42, 645, 2), // "cc"
QT_MOC_LITERAL(43, 648, 20), // "Slot_CreateNewScript"
QT_MOC_LITERAL(44, 669, 18), // "Slot_ExampleScript"
QT_MOC_LITERAL(45, 688, 8), // "scriptID"
QT_MOC_LITERAL(46, 697, 20), // "Slot_ReferenceManual"
QT_MOC_LITERAL(47, 718, 17), // "Slot_ParamsImport"
QT_MOC_LITERAL(48, 736, 17), // "Slot_ParamsExport"
QT_MOC_LITERAL(49, 754, 33), // "Slot_PlotEditor_UpdateArrange..."
QT_MOC_LITERAL(50, 788, 15), // "plotArrangement"
QT_MOC_LITERAL(51, 804, 32), // "Slot_PlotEditor_UpdateProperties"
QT_MOC_LITERAL(52, 837, 15), // "QVector<size_t>"
QT_MOC_LITERAL(53, 853, 15), // "plotUpdateQueue"
QT_MOC_LITERAL(54, 869, 19), // "Slot_UpdateDataInfo"
QT_MOC_LITERAL(55, 889, 8), // "dataInfo"
QT_MOC_LITERAL(56, 898, 33), // "QVector<std::pair<bool,QStrin..."
QT_MOC_LITERAL(57, 932, 11), // "dataSetInfo"
QT_MOC_LITERAL(58, 944, 21), // "Slot_UpdatePythonPath"
QT_MOC_LITERAL(59, 966, 9), // "Slot_Save"
QT_MOC_LITERAL(60, 976, 4), // "file"
QT_MOC_LITERAL(61, 981, 13), // "QVector<bool>"
QT_MOC_LITERAL(62, 995, 10), // "dataToSave"
QT_MOC_LITERAL(63, 1006, 9) // "timeStamp"

    },
    "AppEngine\0Slot_Error\0\0errMsg\0Slot_Msg\0"
    "Slot_ScriptInitialize\0Slot_ScriptInitializeEx\0"
    "QVector<GridPoint>\0Slot_Data\0double[32]\0"
    "Slot_XData\0QVector<double>*\0Slot_DataInfo\0"
    "Slot_DataFileInfo\0Slot_PlotProperty2D\0"
    "Slot_PlotPropertyCM\0Slot_SaveData\0"
    "Slot_ClearData\0Slot_CMData\0Slot_CMDataRow\0"
    "Slot_CMSetup\0Slot_CMShow\0Slot_CustomFnName\0"
    "Slot_AutoSaveConfig\0Slot_PlotArrangement\0"
    "Slot_RetFn_Init\0Slot_RetFn_Run\0"
    "Slot_RetFn_Stop\0Slot_RetFn_Custom1\0"
    "Slot_RetFn_Custom2\0Slot_RetFn_Custom3\0"
    "Slot_RetFn_Custom4\0Slot_RetFn_Custom5\0"
    "Slot_RetFn_Custom6\0Slot_RetFn_Custom7\0"
    "Slot_RetFn_Custom8\0Slot_LoadModule\0"
    "filename\0Slot_RunModule\0Slot_StopModule\0"
    "Slot_CustomControl\0size_t\0cc\0"
    "Slot_CreateNewScript\0Slot_ExampleScript\0"
    "scriptID\0Slot_ReferenceManual\0"
    "Slot_ParamsImport\0Slot_ParamsExport\0"
    "Slot_PlotEditor_UpdateArrangement\0"
    "plotArrangement\0Slot_PlotEditor_UpdateProperties\0"
    "QVector<size_t>\0plotUpdateQueue\0"
    "Slot_UpdateDataInfo\0dataInfo\0"
    "QVector<std::pair<bool,QString> >\0"
    "dataSetInfo\0Slot_UpdatePythonPath\0"
    "Slot_Save\0file\0QVector<bool>\0dataToSave\0"
    "timeStamp"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AppEngine[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      44,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,  234,    2, 0x0a /* Public */,
       4,    2,  237,    2, 0x0a /* Public */,
       5,    3,  242,    2, 0x0a /* Public */,
       6,    3,  249,    2, 0x0a /* Public */,
       8,    3,  256,    2, 0x0a /* Public */,
      10,    4,  263,    2, 0x0a /* Public */,
      12,    2,  272,    2, 0x0a /* Public */,
      13,    1,  277,    2, 0x0a /* Public */,
      14,    3,  280,    2, 0x0a /* Public */,
      15,    3,  287,    2, 0x0a /* Public */,
      16,    2,  294,    2, 0x0a /* Public */,
      17,    1,  299,    2, 0x0a /* Public */,
      18,    4,  302,    2, 0x0a /* Public */,
      19,    3,  311,    2, 0x0a /* Public */,
      20,   11,  318,    2, 0x0a /* Public */,
      21,    2,  341,    2, 0x0a /* Public */,
      22,    2,  346,    2, 0x0a /* Public */,
      23,    2,  351,    2, 0x0a /* Public */,
      24,    1,  356,    2, 0x0a /* Public */,
      25,    1,  359,    2, 0x0a /* Public */,
      26,    1,  362,    2, 0x0a /* Public */,
      27,    1,  365,    2, 0x0a /* Public */,
      28,    1,  368,    2, 0x0a /* Public */,
      29,    1,  371,    2, 0x0a /* Public */,
      30,    1,  374,    2, 0x0a /* Public */,
      31,    1,  377,    2, 0x0a /* Public */,
      32,    1,  380,    2, 0x0a /* Public */,
      33,    1,  383,    2, 0x0a /* Public */,
      34,    1,  386,    2, 0x0a /* Public */,
      35,    1,  389,    2, 0x0a /* Public */,
      36,    1,  392,    2, 0x0a /* Public */,
      38,    0,  395,    2, 0x0a /* Public */,
      39,    0,  396,    2, 0x0a /* Public */,
      40,    1,  397,    2, 0x0a /* Public */,
      43,    1,  400,    2, 0x0a /* Public */,
      44,    1,  403,    2, 0x0a /* Public */,
      46,    0,  406,    2, 0x0a /* Public */,
      47,    1,  407,    2, 0x0a /* Public */,
      48,    1,  410,    2, 0x0a /* Public */,
      49,    1,  413,    2, 0x0a /* Public */,
      51,    1,  416,    2, 0x0a /* Public */,
      54,    2,  419,    2, 0x0a /* Public */,
      58,    0,  424,    2, 0x0a /* Public */,
      59,    3,  425,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString, QMetaType::Bool,    2,    2,
    QMetaType::Void, QMetaType::UInt, QMetaType::QStringList, QMetaType::QStringList,    2,    2,    2,
    QMetaType::Void, 0x80000000 | 7, QMetaType::QStringList, QMetaType::QStringList,    2,    2,    2,
    QMetaType::Void, QMetaType::UInt, QMetaType::UInt, 0x80000000 | 9,    2,    2,    2,
    QMetaType::Void, QMetaType::UInt, 0x80000000 | 11, 0x80000000 | 11, QMetaType::Bool,    2,    2,    2,    2,
    QMetaType::Void, QMetaType::UInt, QMetaType::QString,    2,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::UInt, QMetaType::QString, QMetaType::QString,    2,    2,    2,
    QMetaType::Void, QMetaType::UInt, QMetaType::QString, QMetaType::QString,    2,    2,    2,
    QMetaType::Void, QMetaType::UInt, QMetaType::QString,    2,    2,
    QMetaType::Void, QMetaType::UInt,    2,
    QMetaType::Void, QMetaType::UInt, QMetaType::UInt, QMetaType::UInt, QMetaType::Double,    2,    2,    2,    2,
    QMetaType::Void, QMetaType::UInt, QMetaType::UInt, 0x80000000 | 11,    2,    2,    2,
    QMetaType::Void, QMetaType::UInt, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::Double, QMetaType::UInt, QMetaType::UInt, QMetaType::Bool, QMetaType::Double, QMetaType::Double, QMetaType::Bool,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,    2,
    QMetaType::Void, QMetaType::UInt, QMetaType::Bool,    2,    2,
    QMetaType::Void, QMetaType::UInt, QMetaType::QString,    2,    2,
    QMetaType::Void, QMetaType::Bool, QMetaType::QString,    2,    2,
    QMetaType::Void, 0x80000000 | 7,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::QString,   37,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 41,   42,
    QMetaType::Void, QMetaType::QString,   37,
    QMetaType::Void, QMetaType::UInt,   45,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   37,
    QMetaType::Void, QMetaType::QString,   37,
    QMetaType::Void, 0x80000000 | 7,   50,
    QMetaType::Void, 0x80000000 | 52,   53,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 56,   55,   57,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 61, QMetaType::Bool,   60,   62,   63,

       0        // eod
};

void AppEngine::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<AppEngine *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Slot_Error((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->Slot_Msg((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 2: _t->Slot_ScriptInitialize((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< const QStringList(*)>(_a[2])),(*reinterpret_cast< const QStringList(*)>(_a[3]))); break;
        case 3: _t->Slot_ScriptInitializeEx((*reinterpret_cast< const QVector<GridPoint>(*)>(_a[1])),(*reinterpret_cast< const QStringList(*)>(_a[2])),(*reinterpret_cast< const QStringList(*)>(_a[3]))); break;
        case 4: _t->Slot_Data((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2])),(*reinterpret_cast< double(*)[32]>(_a[3]))); break;
        case 5: _t->Slot_XData((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< QVector<double>*(*)>(_a[2])),(*reinterpret_cast< QVector<double>*(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4]))); break;
        case 6: _t->Slot_DataInfo((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 7: _t->Slot_DataFileInfo((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->Slot_PlotProperty2D((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 9: _t->Slot_PlotPropertyCM((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3]))); break;
        case 10: _t->Slot_SaveData((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 11: _t->Slot_ClearData((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 12: _t->Slot_CMData((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2])),(*reinterpret_cast< uint(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4]))); break;
        case 13: _t->Slot_CMDataRow((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2])),(*reinterpret_cast< QVector<double>*(*)>(_a[3]))); break;
        case 14: _t->Slot_CMSetup((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2])),(*reinterpret_cast< double(*)>(_a[3])),(*reinterpret_cast< double(*)>(_a[4])),(*reinterpret_cast< double(*)>(_a[5])),(*reinterpret_cast< uint(*)>(_a[6])),(*reinterpret_cast< uint(*)>(_a[7])),(*reinterpret_cast< bool(*)>(_a[8])),(*reinterpret_cast< double(*)>(_a[9])),(*reinterpret_cast< double(*)>(_a[10])),(*reinterpret_cast< bool(*)>(_a[11]))); break;
        case 15: _t->Slot_CMShow((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 16: _t->Slot_CustomFnName((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 17: _t->Slot_AutoSaveConfig((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 18: _t->Slot_PlotArrangement((*reinterpret_cast< const QVector<GridPoint>(*)>(_a[1]))); break;
        case 19: _t->Slot_RetFn_Init((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 20: _t->Slot_RetFn_Run((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 21: _t->Slot_RetFn_Stop((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 22: _t->Slot_RetFn_Custom1((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 23: _t->Slot_RetFn_Custom2((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 24: _t->Slot_RetFn_Custom3((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 25: _t->Slot_RetFn_Custom4((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 26: _t->Slot_RetFn_Custom5((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 27: _t->Slot_RetFn_Custom6((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 28: _t->Slot_RetFn_Custom7((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 29: _t->Slot_RetFn_Custom8((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 30: _t->Slot_LoadModule((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 31: _t->Slot_RunModule(); break;
        case 32: _t->Slot_StopModule(); break;
        case 33: _t->Slot_CustomControl((*reinterpret_cast< size_t(*)>(_a[1]))); break;
        case 34: _t->Slot_CreateNewScript((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 35: _t->Slot_ExampleScript((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 36: _t->Slot_ReferenceManual(); break;
        case 37: _t->Slot_ParamsImport((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 38: _t->Slot_ParamsExport((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 39: _t->Slot_PlotEditor_UpdateArrangement((*reinterpret_cast< const QVector<GridPoint>(*)>(_a[1]))); break;
        case 40: _t->Slot_PlotEditor_UpdateProperties((*reinterpret_cast< const QVector<size_t>(*)>(_a[1]))); break;
        case 41: _t->Slot_UpdateDataInfo((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QVector<std::pair<bool,QString> >(*)>(_a[2]))); break;
        case 42: _t->Slot_UpdatePythonPath(); break;
        case 43: _t->Slot_Save((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QVector<bool>(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<GridPoint> >(); break;
            }
            break;
        case 18:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<GridPoint> >(); break;
            }
            break;
        case 39:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<GridPoint> >(); break;
            }
            break;
        case 43:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<bool> >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject AppEngine::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_AppEngine.data,
    qt_meta_data_AppEngine,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *AppEngine::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AppEngine::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AppEngine.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int AppEngine::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 44)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 44;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 44)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 44;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
