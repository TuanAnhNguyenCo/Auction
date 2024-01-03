/****************************************************************************
** Meta object code from reading C++ file 'login.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.10)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../GUI/login.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'login.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.10. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_LogIn_t {
    uint offsetsAndSizes[18];
    char stringdata0[105];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_LogIn_t::offsetsAndSizes) + ofs), len 
static const qt_meta_stringdata_LogIn_t qt_meta_stringdata_LogIn = {
    {
        QT_MOC_LITERAL(0, 5),  // "LogIn"
        QT_MOC_LITERAL(6, 13),  // "SignupClicked"
        QT_MOC_LITERAL(20, 0),  // ""
        QT_MOC_LITERAL(21, 7),  // "LoginOk"
        QT_MOC_LITERAL(29, 25),  // "on_btn_signupPage_clicked"
        QT_MOC_LITERAL(55, 20),  // "on_btn_login_clicked"
        QT_MOC_LITERAL(76, 14),  // "update_sign_in"
        QT_MOC_LITERAL(91, 5),  // "char*"
        QT_MOC_LITERAL(97, 7)   // "message"
    },
    "LogIn\0SignupClicked\0\0LoginOk\0"
    "on_btn_signupPage_clicked\0"
    "on_btn_login_clicked\0update_sign_in\0"
    "char*\0message"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LogIn[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   44,    2, 0x06,    1 /* Public */,
       3,    0,   45,    2, 0x06,    2 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       4,    0,   46,    2, 0x0a,    3 /* Public */,
       5,    0,   47,    2, 0x0a,    4 /* Public */,
       6,    1,   48,    2, 0x0a,    5 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    8,

       0        // eod
};

void LogIn::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<LogIn *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->SignupClicked(); break;
        case 1: _t->LoginOk(); break;
        case 2: _t->on_btn_signupPage_clicked(); break;
        case 3: _t->on_btn_login_clicked(); break;
        case 4: _t->update_sign_in((*reinterpret_cast< std::add_pointer_t<char*>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (LogIn::*)();
            if (_t _q_method = &LogIn::SignupClicked; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (LogIn::*)();
            if (_t _q_method = &LogIn::LoginOk; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject LogIn::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_LogIn.offsetsAndSizes,
    qt_meta_data_LogIn,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_LogIn_t
, QtPrivate::TypeAndForceComplete<LogIn, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<char *, std::false_type>


>,
    nullptr
} };


const QMetaObject *LogIn::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LogIn::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_LogIn.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int LogIn::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void LogIn::SignupClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void LogIn::LoginOk()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
