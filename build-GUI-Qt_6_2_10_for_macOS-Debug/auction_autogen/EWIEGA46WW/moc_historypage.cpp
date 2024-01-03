/****************************************************************************
** Meta object code from reading C++ file 'historypage.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.10)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../GUI/historypage.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'historypage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.10. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_HistoryPage_t {
    uint offsetsAndSizes[20];
    char stringdata0[152];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_HistoryPage_t::offsetsAndSizes) + ofs), len 
static const qt_meta_stringdata_HistoryPage_t qt_meta_stringdata_HistoryPage = {
    {
        QT_MOC_LITERAL(0, 11),  // "HistoryPage"
        QT_MOC_LITERAL(12, 11),  // "HomeClicked"
        QT_MOC_LITERAL(24, 0),  // ""
        QT_MOC_LITERAL(25, 13),  // "CreateClicked"
        QT_MOC_LITERAL(39, 20),  // "HistoryDetailClicked"
        QT_MOC_LITERAL(60, 22),  // "on_btn_hometab_clicked"
        QT_MOC_LITERAL(83, 24),  // "on_btn_createtab_clicked"
        QT_MOC_LITERAL(108, 11),  // "viewClicked"
        QT_MOC_LITERAL(120, 15),  // "moveHistoryPage"
        QT_MOC_LITERAL(136, 15)   // "showJoinedRooms"
    },
    "HistoryPage\0HomeClicked\0\0CreateClicked\0"
    "HistoryDetailClicked\0on_btn_hometab_clicked\0"
    "on_btn_createtab_clicked\0viewClicked\0"
    "moveHistoryPage\0showJoinedRooms"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_HistoryPage[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   62,    2, 0x06,    1 /* Public */,
       3,    0,   63,    2, 0x06,    2 /* Public */,
       4,    0,   64,    2, 0x06,    3 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       5,    0,   65,    2, 0x08,    4 /* Private */,
       6,    0,   66,    2, 0x08,    5 /* Private */,
       7,    0,   67,    2, 0x08,    6 /* Private */,
       8,    0,   68,    2, 0x0a,    7 /* Public */,
       9,    0,   69,    2, 0x0a,    8 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void HistoryPage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<HistoryPage *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->HomeClicked(); break;
        case 1: _t->CreateClicked(); break;
        case 2: _t->HistoryDetailClicked(); break;
        case 3: _t->on_btn_hometab_clicked(); break;
        case 4: _t->on_btn_createtab_clicked(); break;
        case 5: _t->viewClicked(); break;
        case 6: _t->moveHistoryPage(); break;
        case 7: _t->showJoinedRooms(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (HistoryPage::*)();
            if (_t _q_method = &HistoryPage::HomeClicked; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (HistoryPage::*)();
            if (_t _q_method = &HistoryPage::CreateClicked; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (HistoryPage::*)();
            if (_t _q_method = &HistoryPage::HistoryDetailClicked; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
    }
    (void)_a;
}

const QMetaObject HistoryPage::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_HistoryPage.offsetsAndSizes,
    qt_meta_data_HistoryPage,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_HistoryPage_t
, QtPrivate::TypeAndForceComplete<HistoryPage, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *HistoryPage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *HistoryPage::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_HistoryPage.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int HistoryPage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void HistoryPage::HomeClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void HistoryPage::CreateClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void HistoryPage::HistoryDetailClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
