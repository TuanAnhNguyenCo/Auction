/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.10)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../GUI/mainwindow.h"
#include <QtGui/qtextcursor.h>
#include <QScreen>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.10. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    uint offsetsAndSizes[36];
    char stringdata0[263];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_MainWindow_t::offsetsAndSizes) + ofs), len 
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
        QT_MOC_LITERAL(0, 10),  // "MainWindow"
        QT_MOC_LITERAL(11, 12),  // "callShowItem"
        QT_MOC_LITERAL(24, 0),  // ""
        QT_MOC_LITERAL(25, 24),  // "on_btn_createtab_clicked"
        QT_MOC_LITERAL(50, 25),  // "on_btn_historytab_clicked"
        QT_MOC_LITERAL(76, 8),  // "moveHome"
        QT_MOC_LITERAL(85, 13),  // "moveCreateTab"
        QT_MOC_LITERAL(99, 14),  // "moveHistoryTab"
        QT_MOC_LITERAL(114, 15),  // "moveAuctionRoom"
        QT_MOC_LITERAL(130, 5),  // "char*"
        QT_MOC_LITERAL(136, 7),  // "message"
        QT_MOC_LITERAL(144, 21),  // "on_btn_logout_clicked"
        QT_MOC_LITERAL(166, 14),  // "moveSignupPage"
        QT_MOC_LITERAL(181, 13),  // "moveLoginPage"
        QT_MOC_LITERAL(195, 12),  // "handleLogout"
        QT_MOC_LITERAL(208, 10),  // "notifyInfo"
        QT_MOC_LITERAL(219, 21),  // "moveHistoryDetailPage"
        QT_MOC_LITERAL(241, 21)   // "on_search_textChanged"
    },
    "MainWindow\0callShowItem\0\0"
    "on_btn_createtab_clicked\0"
    "on_btn_historytab_clicked\0moveHome\0"
    "moveCreateTab\0moveHistoryTab\0"
    "moveAuctionRoom\0char*\0message\0"
    "on_btn_logout_clicked\0moveSignupPage\0"
    "moveLoginPage\0handleLogout\0notifyInfo\0"
    "moveHistoryDetailPage\0on_search_textChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   98,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       3,    0,   99,    2, 0x0a,    2 /* Public */,
       4,    0,  100,    2, 0x0a,    3 /* Public */,
       5,    0,  101,    2, 0x0a,    4 /* Public */,
       6,    0,  102,    2, 0x0a,    5 /* Public */,
       7,    0,  103,    2, 0x0a,    6 /* Public */,
       8,    1,  104,    2, 0x0a,    7 /* Public */,
      11,    0,  107,    2, 0x0a,    9 /* Public */,
      12,    0,  108,    2, 0x0a,   10 /* Public */,
      13,    0,  109,    2, 0x0a,   11 /* Public */,
      14,    1,  110,    2, 0x0a,   12 /* Public */,
      15,    1,  113,    2, 0x0a,   14 /* Public */,
      16,    0,  116,    2, 0x0a,   16 /* Public */,
      17,    0,  117,    2, 0x08,   17 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->callShowItem(); break;
        case 1: _t->on_btn_createtab_clicked(); break;
        case 2: _t->on_btn_historytab_clicked(); break;
        case 3: _t->moveHome(); break;
        case 4: _t->moveCreateTab(); break;
        case 5: _t->moveHistoryTab(); break;
        case 6: _t->moveAuctionRoom((*reinterpret_cast< std::add_pointer_t<char*>>(_a[1]))); break;
        case 7: _t->on_btn_logout_clicked(); break;
        case 8: _t->moveSignupPage(); break;
        case 9: _t->moveLoginPage(); break;
        case 10: _t->handleLogout((*reinterpret_cast< std::add_pointer_t<char*>>(_a[1]))); break;
        case 11: _t->notifyInfo((*reinterpret_cast< std::add_pointer_t<char*>>(_a[1]))); break;
        case 12: _t->moveHistoryDetailPage(); break;
        case 13: _t->on_search_textChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainWindow::*)();
            if (_t _q_method = &MainWindow::callShowItem; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.offsetsAndSizes,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_MainWindow_t
, QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<char *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<char *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<char *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::callShowItem()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
