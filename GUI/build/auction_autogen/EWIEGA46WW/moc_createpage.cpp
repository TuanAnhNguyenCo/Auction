/****************************************************************************
** Meta object code from reading C++ file 'createpage.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../createpage.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'createpage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSCreatePageENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSCreatePageENDCLASS = QtMocHelpers::stringData(
    "CreatePage",
    "HomeClicked",
    "",
    "HistoryClicked",
    "on_btn_hometab_clicked",
    "on_btn_historytab_clicked",
    "on_btn_save_clicked",
    "on_btn_cancel_clicked",
    "on_btn_createtab_clicked",
    "handleMessageFromRoomCreationRequest",
    "char*",
    "Message"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSCreatePageENDCLASS_t {
    uint offsetsAndSizes[24];
    char stringdata0[11];
    char stringdata1[12];
    char stringdata2[1];
    char stringdata3[15];
    char stringdata4[23];
    char stringdata5[26];
    char stringdata6[20];
    char stringdata7[22];
    char stringdata8[25];
    char stringdata9[37];
    char stringdata10[6];
    char stringdata11[8];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSCreatePageENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSCreatePageENDCLASS_t qt_meta_stringdata_CLASSCreatePageENDCLASS = {
    {
        QT_MOC_LITERAL(0, 10),  // "CreatePage"
        QT_MOC_LITERAL(11, 11),  // "HomeClicked"
        QT_MOC_LITERAL(23, 0),  // ""
        QT_MOC_LITERAL(24, 14),  // "HistoryClicked"
        QT_MOC_LITERAL(39, 22),  // "on_btn_hometab_clicked"
        QT_MOC_LITERAL(62, 25),  // "on_btn_historytab_clicked"
        QT_MOC_LITERAL(88, 19),  // "on_btn_save_clicked"
        QT_MOC_LITERAL(108, 21),  // "on_btn_cancel_clicked"
        QT_MOC_LITERAL(130, 24),  // "on_btn_createtab_clicked"
        QT_MOC_LITERAL(155, 36),  // "handleMessageFromRoomCreation..."
        QT_MOC_LITERAL(192, 5),  // "char*"
        QT_MOC_LITERAL(198, 7)   // "Message"
    },
    "CreatePage",
    "HomeClicked",
    "",
    "HistoryClicked",
    "on_btn_hometab_clicked",
    "on_btn_historytab_clicked",
    "on_btn_save_clicked",
    "on_btn_cancel_clicked",
    "on_btn_createtab_clicked",
    "handleMessageFromRoomCreationRequest",
    "char*",
    "Message"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSCreatePageENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   62,    2, 0x06,    1 /* Public */,
       3,    0,   63,    2, 0x06,    2 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       4,    0,   64,    2, 0x08,    3 /* Private */,
       5,    0,   65,    2, 0x08,    4 /* Private */,
       6,    0,   66,    2, 0x08,    5 /* Private */,
       7,    0,   67,    2, 0x08,    6 /* Private */,
       8,    0,   68,    2, 0x08,    7 /* Private */,
       9,    1,   69,    2, 0x0a,    8 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 10,   11,

       0        // eod
};

Q_CONSTINIT const QMetaObject CreatePage::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSCreatePageENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSCreatePageENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSCreatePageENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<CreatePage, std::true_type>,
        // method 'HomeClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'HistoryClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btn_hometab_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btn_historytab_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btn_save_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btn_cancel_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btn_createtab_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'handleMessageFromRoomCreationRequest'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<char *, std::false_type>
    >,
    nullptr
} };

void CreatePage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CreatePage *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->HomeClicked(); break;
        case 1: _t->HistoryClicked(); break;
        case 2: _t->on_btn_hometab_clicked(); break;
        case 3: _t->on_btn_historytab_clicked(); break;
        case 4: _t->on_btn_save_clicked(); break;
        case 5: _t->on_btn_cancel_clicked(); break;
        case 6: _t->on_btn_createtab_clicked(); break;
        case 7: _t->handleMessageFromRoomCreationRequest((*reinterpret_cast< std::add_pointer_t<char*>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CreatePage::*)();
            if (_t _q_method = &CreatePage::HomeClicked; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (CreatePage::*)();
            if (_t _q_method = &CreatePage::HistoryClicked; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject *CreatePage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CreatePage::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSCreatePageENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int CreatePage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void CreatePage::HomeClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void CreatePage::HistoryClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
