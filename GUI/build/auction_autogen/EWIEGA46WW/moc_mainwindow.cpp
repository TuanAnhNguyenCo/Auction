/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../mainwindow.h"
#include <QtGui/qtextcursor.h>
#include <QtGui/qscreen.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSMainWindowENDCLASS = QtMocHelpers::stringData(
    "MainWindow",
    "on_btn_createtab_clicked",
    "",
    "on_btn_historytab_clicked",
    "moveHome",
    "moveCreateTab",
    "moveHistoryTab",
    "moveAuctionRoom",
    "char*",
    "message",
    "on_btn_logout_clicked",
    "moveSignupPage",
    "moveLoginPage",
    "handleLogout"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {
    uint offsetsAndSizes[28];
    char stringdata0[11];
    char stringdata1[25];
    char stringdata2[1];
    char stringdata3[26];
    char stringdata4[9];
    char stringdata5[14];
    char stringdata6[15];
    char stringdata7[16];
    char stringdata8[6];
    char stringdata9[8];
    char stringdata10[22];
    char stringdata11[15];
    char stringdata12[14];
    char stringdata13[13];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSMainWindowENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSMainWindowENDCLASS_t qt_meta_stringdata_CLASSMainWindowENDCLASS = {
    {
        QT_MOC_LITERAL(0, 10),  // "MainWindow"
        QT_MOC_LITERAL(11, 24),  // "on_btn_createtab_clicked"
        QT_MOC_LITERAL(36, 0),  // ""
        QT_MOC_LITERAL(37, 25),  // "on_btn_historytab_clicked"
        QT_MOC_LITERAL(63, 8),  // "moveHome"
        QT_MOC_LITERAL(72, 13),  // "moveCreateTab"
        QT_MOC_LITERAL(86, 14),  // "moveHistoryTab"
        QT_MOC_LITERAL(101, 15),  // "moveAuctionRoom"
        QT_MOC_LITERAL(117, 5),  // "char*"
        QT_MOC_LITERAL(123, 7),  // "message"
        QT_MOC_LITERAL(131, 21),  // "on_btn_logout_clicked"
        QT_MOC_LITERAL(153, 14),  // "moveSignupPage"
        QT_MOC_LITERAL(168, 13),  // "moveLoginPage"
        QT_MOC_LITERAL(182, 12)   // "handleLogout"
    },
    "MainWindow",
    "on_btn_createtab_clicked",
    "",
    "on_btn_historytab_clicked",
    "moveHome",
    "moveCreateTab",
    "moveHistoryTab",
    "moveAuctionRoom",
    "char*",
    "message",
    "on_btn_logout_clicked",
    "moveSignupPage",
    "moveLoginPage",
    "handleLogout"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMainWindowENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   74,    2, 0x0a,    1 /* Public */,
       3,    0,   75,    2, 0x0a,    2 /* Public */,
       4,    0,   76,    2, 0x0a,    3 /* Public */,
       5,    0,   77,    2, 0x0a,    4 /* Public */,
       6,    0,   78,    2, 0x0a,    5 /* Public */,
       7,    1,   79,    2, 0x0a,    6 /* Public */,
      10,    0,   82,    2, 0x0a,    8 /* Public */,
      11,    0,   83,    2, 0x0a,    9 /* Public */,
      12,    0,   84,    2, 0x0a,   10 /* Public */,
      13,    1,   85,    2, 0x0a,   11 /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    9,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSMainWindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSMainWindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSMainWindowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'on_btn_createtab_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_btn_historytab_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'moveHome'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'moveCreateTab'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'moveHistoryTab'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'moveAuctionRoom'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<char *, std::false_type>,
        // method 'on_btn_logout_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'moveSignupPage'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'moveLoginPage'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'handleLogout'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<char *, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_btn_createtab_clicked(); break;
        case 1: _t->on_btn_historytab_clicked(); break;
        case 2: _t->moveHome(); break;
        case 3: _t->moveCreateTab(); break;
        case 4: _t->moveHistoryTab(); break;
        case 5: _t->moveAuctionRoom((*reinterpret_cast< std::add_pointer_t<char*>>(_a[1]))); break;
        case 6: _t->on_btn_logout_clicked(); break;
        case 7: _t->moveSignupPage(); break;
        case 8: _t->moveLoginPage(); break;
        case 9: _t->handleLogout((*reinterpret_cast< std::add_pointer_t<char*>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSMainWindowENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
