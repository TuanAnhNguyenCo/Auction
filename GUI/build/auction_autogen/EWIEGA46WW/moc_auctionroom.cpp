/****************************************************************************
** Meta object code from reading C++ file 'auctionroom.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../auctionroom.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'auctionroom.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSAuctionRoomENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSAuctionRoomENDCLASS = QtMocHelpers::stringData(
    "AuctionRoom",
    "HomeClicked",
    "",
    "callShowItems",
    "on_btn_backHome_clicked",
    "on_btn_bid_clicked",
    "on_btn_overview_clicked",
    "backfromOverview",
    "moveToOverview",
    "on_btn_bin_clicked",
    "addNemItem",
    "moveToParticipant"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSAuctionRoomENDCLASS_t {
    uint offsetsAndSizes[24];
    char stringdata0[12];
    char stringdata1[12];
    char stringdata2[1];
    char stringdata3[14];
    char stringdata4[24];
    char stringdata5[19];
    char stringdata6[24];
    char stringdata7[17];
    char stringdata8[15];
    char stringdata9[19];
    char stringdata10[11];
    char stringdata11[18];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSAuctionRoomENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSAuctionRoomENDCLASS_t qt_meta_stringdata_CLASSAuctionRoomENDCLASS = {
    {
        QT_MOC_LITERAL(0, 11),  // "AuctionRoom"
        QT_MOC_LITERAL(12, 11),  // "HomeClicked"
        QT_MOC_LITERAL(24, 0),  // ""
        QT_MOC_LITERAL(25, 13),  // "callShowItems"
        QT_MOC_LITERAL(39, 23),  // "on_btn_backHome_clicked"
        QT_MOC_LITERAL(63, 18),  // "on_btn_bid_clicked"
        QT_MOC_LITERAL(82, 23),  // "on_btn_overview_clicked"
        QT_MOC_LITERAL(106, 16),  // "backfromOverview"
        QT_MOC_LITERAL(123, 14),  // "moveToOverview"
        QT_MOC_LITERAL(138, 18),  // "on_btn_bin_clicked"
        QT_MOC_LITERAL(157, 10),  // "addNemItem"
        QT_MOC_LITERAL(168, 17)   // "moveToParticipant"
    },
    "AuctionRoom",
    "HomeClicked",
    "",
    "callShowItems",
    "on_btn_backHome_clicked",
    "on_btn_bid_clicked",
    "on_btn_overview_clicked",
    "backfromOverview",
    "moveToOverview",
    "on_btn_bin_clicked",
    "addNemItem",
    "moveToParticipant"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSAuctionRoomENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   74,    2, 0x06,    1 /* Public */,
       3,    0,   75,    2, 0x06,    2 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       4,    0,   76,    2, 0x08,    3 /* Private */,
       5,    0,   77,    2, 0x08,    4 /* Private */,
       6,    0,   78,    2, 0x08,    5 /* Private */,
       7,    0,   79,    2, 0x08,    6 /* Private */,
       8,    0,   80,    2, 0x08,    7 /* Private */,
       9,    0,   81,    2, 0x08,    8 /* Private */,
      10,    0,   82,    2, 0x08,    9 /* Private */,
      11,    0,   83,    2, 0x08,   10 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

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

Q_CONSTINIT const QMetaObject AuctionRoom::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CLASSAuctionRoomENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSAuctionRoomENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSAuctionRoomENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<AuctionRoom, std::true_type>,
        // method 'HomeClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'callShowItems'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btn_backHome_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btn_bid_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btn_overview_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'backfromOverview'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'moveToOverview'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btn_bin_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'addNemItem'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'moveToParticipant'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void AuctionRoom::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<AuctionRoom *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->HomeClicked(); break;
        case 1: _t->callShowItems(); break;
        case 2: _t->on_btn_backHome_clicked(); break;
        case 3: _t->on_btn_bid_clicked(); break;
        case 4: _t->on_btn_overview_clicked(); break;
        case 5: _t->backfromOverview(); break;
        case 6: _t->moveToOverview(); break;
        case 7: _t->on_btn_bin_clicked(); break;
        case 8: _t->addNemItem(); break;
        case 9: _t->moveToParticipant(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (AuctionRoom::*)();
            if (_t _q_method = &AuctionRoom::HomeClicked; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (AuctionRoom::*)();
            if (_t _q_method = &AuctionRoom::callShowItems; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
    }
    (void)_a;
}

const QMetaObject *AuctionRoom::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AuctionRoom::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSAuctionRoomENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int AuctionRoom::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void AuctionRoom::HomeClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void AuctionRoom::callShowItems()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
