/****************************************************************************
** Meta object code from reading C++ file 'roomoverview.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../roomoverview.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'roomoverview.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSRoomOverviewENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSRoomOverviewENDCLASS = QtMocHelpers::stringData(
    "RoomOverview",
    "backtoRoomClicked",
    "",
    "addItemClicked",
    "participantClicked",
    "on_btn_backAuctionroom_clicked",
    "on_btn_add_clicked",
    "on_pushButton_clicked",
    "showItems"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSRoomOverviewENDCLASS_t {
    uint offsetsAndSizes[18];
    char stringdata0[13];
    char stringdata1[18];
    char stringdata2[1];
    char stringdata3[15];
    char stringdata4[19];
    char stringdata5[31];
    char stringdata6[19];
    char stringdata7[22];
    char stringdata8[10];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSRoomOverviewENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSRoomOverviewENDCLASS_t qt_meta_stringdata_CLASSRoomOverviewENDCLASS = {
    {
        QT_MOC_LITERAL(0, 12),  // "RoomOverview"
        QT_MOC_LITERAL(13, 17),  // "backtoRoomClicked"
        QT_MOC_LITERAL(31, 0),  // ""
        QT_MOC_LITERAL(32, 14),  // "addItemClicked"
        QT_MOC_LITERAL(47, 18),  // "participantClicked"
        QT_MOC_LITERAL(66, 30),  // "on_btn_backAuctionroom_clicked"
        QT_MOC_LITERAL(97, 18),  // "on_btn_add_clicked"
        QT_MOC_LITERAL(116, 21),  // "on_pushButton_clicked"
        QT_MOC_LITERAL(138, 9)   // "showItems"
    },
    "RoomOverview",
    "backtoRoomClicked",
    "",
    "addItemClicked",
    "participantClicked",
    "on_btn_backAuctionroom_clicked",
    "on_btn_add_clicked",
    "on_pushButton_clicked",
    "showItems"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSRoomOverviewENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   56,    2, 0x06,    1 /* Public */,
       3,    0,   57,    2, 0x06,    2 /* Public */,
       4,    0,   58,    2, 0x06,    3 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       5,    0,   59,    2, 0x08,    4 /* Private */,
       6,    0,   60,    2, 0x08,    5 /* Private */,
       7,    0,   61,    2, 0x08,    6 /* Private */,
       8,    0,   62,    2, 0x0a,    7 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject RoomOverview::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSRoomOverviewENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSRoomOverviewENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSRoomOverviewENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<RoomOverview, std::true_type>,
        // method 'backtoRoomClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'addItemClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'participantClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btn_backAuctionroom_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btn_add_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'showItems'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void RoomOverview::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<RoomOverview *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->backtoRoomClicked(); break;
        case 1: _t->addItemClicked(); break;
        case 2: _t->participantClicked(); break;
        case 3: _t->on_btn_backAuctionroom_clicked(); break;
        case 4: _t->on_btn_add_clicked(); break;
        case 5: _t->on_pushButton_clicked(); break;
        case 6: _t->showItems(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (RoomOverview::*)();
            if (_t _q_method = &RoomOverview::backtoRoomClicked; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (RoomOverview::*)();
            if (_t _q_method = &RoomOverview::addItemClicked; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (RoomOverview::*)();
            if (_t _q_method = &RoomOverview::participantClicked; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
    }
    (void)_a;
}

const QMetaObject *RoomOverview::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RoomOverview::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSRoomOverviewENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int RoomOverview::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void RoomOverview::backtoRoomClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void RoomOverview::addItemClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void RoomOverview::participantClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
