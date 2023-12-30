/****************************************************************************
** Meta object code from reading C++ file 'worker.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../worker.h"
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'worker.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSWorkerENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSWorkerENDCLASS = QtMocHelpers::stringData(
    "Worker",
    "signUp_dataReceived",
    "",
    "char*",
    "message",
    "signIn_dataReceived",
    "signout_dataReceived",
    "create_room_dataRecieved",
    "join_room_dataRecieved",
    "leaveRoom_dataReceived",
    "create_item_dataReceived",
    "doWork"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSWorkerENDCLASS_t {
    uint offsetsAndSizes[24];
    char stringdata0[7];
    char stringdata1[20];
    char stringdata2[1];
    char stringdata3[6];
    char stringdata4[8];
    char stringdata5[20];
    char stringdata6[21];
    char stringdata7[25];
    char stringdata8[23];
    char stringdata9[23];
    char stringdata10[25];
    char stringdata11[7];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSWorkerENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSWorkerENDCLASS_t qt_meta_stringdata_CLASSWorkerENDCLASS = {
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
        QT_MOC_LITERAL(179, 6)   // "doWork"
    },
    "Worker",
    "signUp_dataReceived",
    "",
    "char*",
    "message",
    "signIn_dataReceived",
    "signout_dataReceived",
    "create_room_dataRecieved",
    "join_room_dataRecieved",
    "leaveRoom_dataReceived",
    "create_item_dataReceived",
    "doWork"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSWorkerENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   62,    2, 0x06,    1 /* Public */,
       5,    1,   65,    2, 0x06,    3 /* Public */,
       6,    1,   68,    2, 0x06,    5 /* Public */,
       7,    1,   71,    2, 0x06,    7 /* Public */,
       8,    1,   74,    2, 0x06,    9 /* Public */,
       9,    1,   77,    2, 0x06,   11 /* Public */,
      10,    1,   80,    2, 0x06,   13 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      11,    0,   83,    2, 0x0a,   15 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject Worker::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_CLASSWorkerENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSWorkerENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSWorkerENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Worker, std::true_type>,
        // method 'signUp_dataReceived'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<char *, std::false_type>,
        // method 'signIn_dataReceived'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<char *, std::false_type>,
        // method 'signout_dataReceived'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<char *, std::false_type>,
        // method 'create_room_dataRecieved'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<char *, std::false_type>,
        // method 'join_room_dataRecieved'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<char *, std::false_type>,
        // method 'leaveRoom_dataReceived'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<char *, std::false_type>,
        // method 'create_item_dataReceived'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<char *, std::false_type>,
        // method 'doWork'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

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
        case 7: _t->doWork(); break;
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
    }
}

const QMetaObject *Worker::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Worker::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSWorkerENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Worker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
