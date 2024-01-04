/****************************************************************************
** Meta object code from reading C++ file 'worker.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.10)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../GUI/worker.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'worker.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.10. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Worker_t {
    uint offsetsAndSizes[50];
    char stringdata0[365];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_Worker_t::offsetsAndSizes) + ofs), len 
static const qt_meta_stringdata_Worker_t qt_meta_stringdata_Worker = {
    {
        QT_MOC_LITERAL(0, 6),  // "Worker"
        QT_MOC_LITERAL(7, 19),  // "signUp_dataReceived"
        QT_MOC_LITERAL(27, 0),  // ""
        QT_MOC_LITERAL(28, 5),  // "char*"
        QT_MOC_LITERAL(34, 7),  // "message"
        QT_MOC_LITERAL(42, 19),  // "signIn_dataReceived"
        QT_MOC_LITERAL(62, 20),  // "signout_dataReceived"
        QT_MOC_LITERAL(83, 24),  // "create_room_dataRecieved"
        QT_MOC_LITERAL(108, 22),  // "join_room_dataRecieved"
        QT_MOC_LITERAL(131, 22),  // "leaveRoom_dataReceived"
        QT_MOC_LITERAL(154, 24),  // "create_item_dataReceived"
        QT_MOC_LITERAL(179, 19),  // "handleKickingMember"
        QT_MOC_LITERAL(199, 7),  // "sendOff"
        QT_MOC_LITERAL(207, 10),  // "notifyInfo"
        QT_MOC_LITERAL(218, 16),  // "bid_dataReceived"
        QT_MOC_LITERAL(235, 17),  // "updateAuctionItem"
        QT_MOC_LITERAL(253, 21),  // "updateAuctionItemByID"
        QT_MOC_LITERAL(275, 2),  // "id"
        QT_MOC_LITERAL(278, 13),  // "callShowItems"
        QT_MOC_LITERAL(292, 10),  // "setNewTime"
        QT_MOC_LITERAL(303, 8),  // "stopTime"
        QT_MOC_LITERAL(312, 16),  // "showAlertMessage"
        QT_MOC_LITERAL(329, 15),  // "showJoinedRooms"
        QT_MOC_LITERAL(345, 12),  // "viewItemInfo"
        QT_MOC_LITERAL(358, 6)   // "doWork"
    },
    "Worker\0signUp_dataReceived\0\0char*\0"
    "message\0signIn_dataReceived\0"
    "signout_dataReceived\0create_room_dataRecieved\0"
    "join_room_dataRecieved\0leaveRoom_dataReceived\0"
    "create_item_dataReceived\0handleKickingMember\0"
    "sendOff\0notifyInfo\0bid_dataReceived\0"
    "updateAuctionItem\0updateAuctionItemByID\0"
    "id\0callShowItems\0setNewTime\0stopTime\0"
    "showAlertMessage\0showJoinedRooms\0"
    "viewItemInfo\0doWork"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Worker[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      20,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      19,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  134,    2, 0x06,    1 /* Public */,
       5,    1,  137,    2, 0x06,    3 /* Public */,
       6,    1,  140,    2, 0x06,    5 /* Public */,
       7,    1,  143,    2, 0x06,    7 /* Public */,
       8,    1,  146,    2, 0x06,    9 /* Public */,
       9,    1,  149,    2, 0x06,   11 /* Public */,
      10,    1,  152,    2, 0x06,   13 /* Public */,
      11,    0,  155,    2, 0x06,   15 /* Public */,
      12,    0,  156,    2, 0x06,   16 /* Public */,
      13,    1,  157,    2, 0x06,   17 /* Public */,
      14,    1,  160,    2, 0x06,   19 /* Public */,
      15,    0,  163,    2, 0x06,   21 /* Public */,
      16,    1,  164,    2, 0x06,   22 /* Public */,
      18,    0,  167,    2, 0x06,   24 /* Public */,
      19,    0,  168,    2, 0x06,   25 /* Public */,
      20,    0,  169,    2, 0x06,   26 /* Public */,
      21,    0,  170,    2, 0x06,   27 /* Public */,
      22,    0,  171,    2, 0x06,   28 /* Public */,
      23,    0,  172,    2, 0x06,   29 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      24,    0,  173,    2, 0x0a,   30 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   17,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void Worker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Worker *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->signUp_dataReceived((*reinterpret_cast< std::add_pointer_t<char*>>(_a[1]))); break;
        case 1: _t->signIn_dataReceived((*reinterpret_cast< std::add_pointer_t<char*>>(_a[1]))); break;
        case 2: _t->signout_dataReceived((*reinterpret_cast< std::add_pointer_t<char*>>(_a[1]))); break;
        case 3: _t->create_room_dataRecieved((*reinterpret_cast< std::add_pointer_t<char*>>(_a[1]))); break;
        case 4: _t->join_room_dataRecieved((*reinterpret_cast< std::add_pointer_t<char*>>(_a[1]))); break;
        case 5: _t->leaveRoom_dataReceived((*reinterpret_cast< std::add_pointer_t<char*>>(_a[1]))); break;
        case 6: _t->create_item_dataReceived((*reinterpret_cast< std::add_pointer_t<char*>>(_a[1]))); break;
        case 7: _t->handleKickingMember(); break;
        case 8: _t->sendOff(); break;
        case 9: _t->notifyInfo((*reinterpret_cast< std::add_pointer_t<char*>>(_a[1]))); break;
        case 10: _t->bid_dataReceived((*reinterpret_cast< std::add_pointer_t<char*>>(_a[1]))); break;
        case 11: _t->updateAuctionItem(); break;
        case 12: _t->updateAuctionItemByID((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 13: _t->callShowItems(); break;
        case 14: _t->setNewTime(); break;
        case 15: _t->stopTime(); break;
        case 16: _t->showAlertMessage(); break;
        case 17: _t->showJoinedRooms(); break;
        case 18: _t->viewItemInfo(); break;
        case 19: _t->doWork(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Worker::*)(char * );
            if (_t _q_method = &Worker::signUp_dataReceived; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Worker::*)(char * );
            if (_t _q_method = &Worker::signIn_dataReceived; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Worker::*)(char * );
            if (_t _q_method = &Worker::signout_dataReceived; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Worker::*)(char * );
            if (_t _q_method = &Worker::create_room_dataRecieved; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Worker::*)(char * );
            if (_t _q_method = &Worker::join_room_dataRecieved; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (Worker::*)(char * );
            if (_t _q_method = &Worker::leaveRoom_dataReceived; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (Worker::*)(char * );
            if (_t _q_method = &Worker::create_item_dataReceived; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (Worker::*)();
            if (_t _q_method = &Worker::handleKickingMember; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (Worker::*)();
            if (_t _q_method = &Worker::sendOff; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (Worker::*)(char * );
            if (_t _q_method = &Worker::notifyInfo; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (Worker::*)(char * );
            if (_t _q_method = &Worker::bid_dataReceived; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (Worker::*)();
            if (_t _q_method = &Worker::updateAuctionItem; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 11;
                return;
            }
        }
        {
            using _t = void (Worker::*)(int );
            if (_t _q_method = &Worker::updateAuctionItemByID; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 12;
                return;
            }
        }
        {
            using _t = void (Worker::*)();
            if (_t _q_method = &Worker::callShowItems; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 13;
                return;
            }
        }
        {
            using _t = void (Worker::*)();
            if (_t _q_method = &Worker::setNewTime; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 14;
                return;
            }
        }
        {
            using _t = void (Worker::*)();
            if (_t _q_method = &Worker::stopTime; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 15;
                return;
            }
        }
        {
            using _t = void (Worker::*)();
            if (_t _q_method = &Worker::showAlertMessage; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 16;
                return;
            }
        }
        {
            using _t = void (Worker::*)();
            if (_t _q_method = &Worker::showJoinedRooms; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 17;
                return;
            }
        }
        {
            using _t = void (Worker::*)();
            if (_t _q_method = &Worker::viewItemInfo; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 18;
                return;
            }
        }
    }
}

const QMetaObject Worker::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_Worker.offsetsAndSizes,
    qt_meta_data_Worker,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_Worker_t
, QtPrivate::TypeAndForceComplete<Worker, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<char *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<char *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<char *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<char *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<char *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<char *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<char *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<char *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<char *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *Worker::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Worker::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Worker.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Worker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 20)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 20;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 20)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 20;
    }
    return _id;
}

// SIGNAL 0
void Worker::signUp_dataReceived(char * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Worker::signIn_dataReceived(char * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Worker::signout_dataReceived(char * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Worker::create_room_dataRecieved(char * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Worker::join_room_dataRecieved(char * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Worker::leaveRoom_dataReceived(char * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void Worker::create_item_dataReceived(char * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void Worker::handleKickingMember()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void Worker::sendOff()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}

// SIGNAL 9
void Worker::notifyInfo(char * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void Worker::bid_dataReceived(char * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void Worker::updateAuctionItem()
{
    QMetaObject::activate(this, &staticMetaObject, 11, nullptr);
}

// SIGNAL 12
void Worker::updateAuctionItemByID(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void Worker::callShowItems()
{
    QMetaObject::activate(this, &staticMetaObject, 13, nullptr);
}

// SIGNAL 14
void Worker::setNewTime()
{
    QMetaObject::activate(this, &staticMetaObject, 14, nullptr);
}

// SIGNAL 15
void Worker::stopTime()
{
    QMetaObject::activate(this, &staticMetaObject, 15, nullptr);
}

// SIGNAL 16
void Worker::showAlertMessage()
{
    QMetaObject::activate(this, &staticMetaObject, 16, nullptr);
}

// SIGNAL 17
void Worker::showJoinedRooms()
{
    QMetaObject::activate(this, &staticMetaObject, 17, nullptr);
}

// SIGNAL 18
void Worker::viewItemInfo()
{
    QMetaObject::activate(this, &staticMetaObject, 18, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
