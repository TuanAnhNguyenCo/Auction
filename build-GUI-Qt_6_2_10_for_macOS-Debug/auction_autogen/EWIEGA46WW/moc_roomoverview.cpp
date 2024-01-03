/****************************************************************************
** Meta object code from reading C++ file 'roomoverview.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.10)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../GUI/roomoverview.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'roomoverview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.10. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_RoomOverview_t {
    uint offsetsAndSizes[24];
    char stringdata0[175];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_RoomOverview_t::offsetsAndSizes) + ofs), len 
static const qt_meta_stringdata_RoomOverview_t qt_meta_stringdata_RoomOverview = {
    {
        QT_MOC_LITERAL(0, 12),  // "RoomOverview"
        QT_MOC_LITERAL(13, 17),  // "backtoRoomClicked"
        QT_MOC_LITERAL(31, 0),  // ""
        QT_MOC_LITERAL(32, 14),  // "addItemClicked"
        QT_MOC_LITERAL(47, 18),  // "participantClicked"
        QT_MOC_LITERAL(66, 12),  // "callItemByID"
        QT_MOC_LITERAL(79, 2),  // "id"
        QT_MOC_LITERAL(82, 30),  // "on_btn_backAuctionroom_clicked"
        QT_MOC_LITERAL(113, 18),  // "on_btn_add_clicked"
        QT_MOC_LITERAL(132, 10),  // "deleteItem"
        QT_MOC_LITERAL(143, 21),  // "on_pushButton_clicked"
        QT_MOC_LITERAL(165, 9)   // "showItems"
    },
    "RoomOverview\0backtoRoomClicked\0\0"
    "addItemClicked\0participantClicked\0"
    "callItemByID\0id\0on_btn_backAuctionroom_clicked\0"
    "on_btn_add_clicked\0deleteItem\0"
    "on_pushButton_clicked\0showItems"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RoomOverview[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   68,    2, 0x06,    1 /* Public */,
       3,    0,   69,    2, 0x06,    2 /* Public */,
       4,    0,   70,    2, 0x06,    3 /* Public */,
       5,    1,   71,    2, 0x06,    4 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       7,    0,   74,    2, 0x08,    6 /* Private */,
       8,    0,   75,    2, 0x08,    7 /* Private */,
       9,    0,   76,    2, 0x08,    8 /* Private */,
      10,    0,   77,    2, 0x08,    9 /* Private */,
      11,    0,   78,    2, 0x0a,   10 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void RoomOverview::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<RoomOverview *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->backtoRoomClicked(); break;
        case 1: _t->addItemClicked(); break;
        case 2: _t->participantClicked(); break;
        case 3: _t->callItemByID((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 4: _t->on_btn_backAuctionroom_clicked(); break;
        case 5: _t->on_btn_add_clicked(); break;
        case 6: _t->deleteItem(); break;
        case 7: _t->on_pushButton_clicked(); break;
        case 8: _t->showItems(); break;
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
        {
            using _t = void (RoomOverview::*)(int );
            if (_t _q_method = &RoomOverview::callItemByID; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject RoomOverview::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_RoomOverview.offsetsAndSizes,
    qt_meta_data_RoomOverview,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_RoomOverview_t
, QtPrivate::TypeAndForceComplete<RoomOverview, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *RoomOverview::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RoomOverview::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_RoomOverview.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int RoomOverview::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 9;
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

// SIGNAL 3
void RoomOverview::callItemByID(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
