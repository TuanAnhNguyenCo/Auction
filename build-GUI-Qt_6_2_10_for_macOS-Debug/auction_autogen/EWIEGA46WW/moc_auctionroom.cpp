/****************************************************************************
** Meta object code from reading C++ file 'auctionroom.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.10)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../GUI/auctionroom.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'auctionroom.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.10. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AuctionRoom_t {
    uint offsetsAndSizes[48];
    char stringdata0[322];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_AuctionRoom_t::offsetsAndSizes) + ofs), len 
static const qt_meta_stringdata_AuctionRoom_t qt_meta_stringdata_AuctionRoom = {
    {
        QT_MOC_LITERAL(0, 11),  // "AuctionRoom"
        QT_MOC_LITERAL(12, 11),  // "HomeClicked"
        QT_MOC_LITERAL(24, 0),  // ""
        QT_MOC_LITERAL(25, 13),  // "callShowItems"
        QT_MOC_LITERAL(39, 15),  // "callShowMembers"
        QT_MOC_LITERAL(55, 12),  // "callShowItem"
        QT_MOC_LITERAL(68, 23),  // "on_btn_backHome_clicked"
        QT_MOC_LITERAL(92, 18),  // "on_btn_bid_clicked"
        QT_MOC_LITERAL(111, 23),  // "on_btn_overview_clicked"
        QT_MOC_LITERAL(135, 16),  // "backfromOverview"
        QT_MOC_LITERAL(152, 14),  // "moveToOverview"
        QT_MOC_LITERAL(167, 18),  // "on_btn_bin_clicked"
        QT_MOC_LITERAL(186, 10),  // "addNemItem"
        QT_MOC_LITERAL(197, 17),  // "moveToParticipant"
        QT_MOC_LITERAL(215, 23),  // "on_startAuction_clicked"
        QT_MOC_LITERAL(239, 8),  // "showItem"
        QT_MOC_LITERAL(248, 12),  // "showItemByID"
        QT_MOC_LITERAL(261, 2),  // "id"
        QT_MOC_LITERAL(264, 6),  // "notify"
        QT_MOC_LITERAL(271, 5),  // "char*"
        QT_MOC_LITERAL(277, 7),  // "message"
        QT_MOC_LITERAL(285, 10),  // "setNewTime"
        QT_MOC_LITERAL(296, 8),  // "stopTime"
        QT_MOC_LITERAL(305, 16)   // "showAlertMessage"
    },
    "AuctionRoom\0HomeClicked\0\0callShowItems\0"
    "callShowMembers\0callShowItem\0"
    "on_btn_backHome_clicked\0on_btn_bid_clicked\0"
    "on_btn_overview_clicked\0backfromOverview\0"
    "moveToOverview\0on_btn_bin_clicked\0"
    "addNemItem\0moveToParticipant\0"
    "on_startAuction_clicked\0showItem\0"
    "showItemByID\0id\0notify\0char*\0message\0"
    "setNewTime\0stopTime\0showAlertMessage"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AuctionRoom[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,  128,    2, 0x06,    1 /* Public */,
       3,    0,  129,    2, 0x06,    2 /* Public */,
       4,    0,  130,    2, 0x06,    3 /* Public */,
       5,    0,  131,    2, 0x06,    4 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       6,    0,  132,    2, 0x08,    5 /* Private */,
       7,    0,  133,    2, 0x08,    6 /* Private */,
       8,    0,  134,    2, 0x08,    7 /* Private */,
       9,    0,  135,    2, 0x08,    8 /* Private */,
      10,    0,  136,    2, 0x08,    9 /* Private */,
      11,    0,  137,    2, 0x08,   10 /* Private */,
      12,    0,  138,    2, 0x08,   11 /* Private */,
      13,    0,  139,    2, 0x08,   12 /* Private */,
      14,    0,  140,    2, 0x08,   13 /* Private */,
      15,    0,  141,    2, 0x0a,   14 /* Public */,
      16,    1,  142,    2, 0x0a,   15 /* Public */,
      18,    1,  145,    2, 0x0a,   17 /* Public */,
      21,    0,  148,    2, 0x0a,   19 /* Public */,
      22,    0,  149,    2, 0x0a,   20 /* Public */,
      23,    0,  150,    2, 0x0a,   21 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
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
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   17,
    QMetaType::Void, 0x80000000 | 19,   20,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void AuctionRoom::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<AuctionRoom *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->HomeClicked(); break;
        case 1: _t->callShowItems(); break;
        case 2: _t->callShowMembers(); break;
        case 3: _t->callShowItem(); break;
        case 4: _t->on_btn_backHome_clicked(); break;
        case 5: _t->on_btn_bid_clicked(); break;
        case 6: _t->on_btn_overview_clicked(); break;
        case 7: _t->backfromOverview(); break;
        case 8: _t->moveToOverview(); break;
        case 9: _t->on_btn_bin_clicked(); break;
        case 10: _t->addNemItem(); break;
        case 11: _t->moveToParticipant(); break;
        case 12: _t->on_startAuction_clicked(); break;
        case 13: _t->showItem(); break;
        case 14: _t->showItemByID((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 15: _t->notify((*reinterpret_cast< std::add_pointer_t<char*>>(_a[1]))); break;
        case 16: _t->setNewTime(); break;
        case 17: _t->stopTime(); break;
        case 18: _t->showAlertMessage(); break;
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
        {
            using _t = void (AuctionRoom::*)();
            if (_t _q_method = &AuctionRoom::callShowMembers; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (AuctionRoom::*)();
            if (_t _q_method = &AuctionRoom::callShowItem; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject AuctionRoom::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_AuctionRoom.offsetsAndSizes,
    qt_meta_data_AuctionRoom,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_AuctionRoom_t
, QtPrivate::TypeAndForceComplete<AuctionRoom, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<char *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *AuctionRoom::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AuctionRoom::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AuctionRoom.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int AuctionRoom::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 19)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 19;
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

// SIGNAL 2
void AuctionRoom::callShowMembers()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void AuctionRoom::callShowItem()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
