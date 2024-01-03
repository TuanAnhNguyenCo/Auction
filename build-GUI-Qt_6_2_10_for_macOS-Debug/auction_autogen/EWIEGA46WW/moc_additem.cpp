/****************************************************************************
** Meta object code from reading C++ file 'additem.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.10)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../GUI/additem.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'additem.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.10. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_addItem_t {
    uint offsetsAndSizes[20];
    char stringdata0[149];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_addItem_t::offsetsAndSizes) + ofs), len 
static const qt_meta_stringdata_addItem_t qt_meta_stringdata_addItem = {
    {
        QT_MOC_LITERAL(0, 7),  // "addItem"
        QT_MOC_LITERAL(8, 13),  // "cancelClicked"
        QT_MOC_LITERAL(22, 0),  // ""
        QT_MOC_LITERAL(23, 24),  // "on_btn_choosePic_clicked"
        QT_MOC_LITERAL(48, 19),  // "on_btn_save_clicked"
        QT_MOC_LITERAL(68, 21),  // "on_btn_cancel_clicked"
        QT_MOC_LITERAL(90, 19),  // "on_btn_back_clicked"
        QT_MOC_LITERAL(110, 24),  // "handleRoomCreationStatus"
        QT_MOC_LITERAL(135, 5),  // "char*"
        QT_MOC_LITERAL(141, 7)   // "message"
    },
    "addItem\0cancelClicked\0\0on_btn_choosePic_clicked\0"
    "on_btn_save_clicked\0on_btn_cancel_clicked\0"
    "on_btn_back_clicked\0handleRoomCreationStatus\0"
    "char*\0message"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_addItem[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   50,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       3,    0,   51,    2, 0x08,    2 /* Private */,
       4,    0,   52,    2, 0x08,    3 /* Private */,
       5,    0,   53,    2, 0x08,    4 /* Private */,
       6,    0,   54,    2, 0x08,    5 /* Private */,
       7,    1,   55,    2, 0x0a,    6 /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    9,

       0        // eod
};

void addItem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<addItem *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->cancelClicked(); break;
        case 1: _t->on_btn_choosePic_clicked(); break;
        case 2: _t->on_btn_save_clicked(); break;
        case 3: _t->on_btn_cancel_clicked(); break;
        case 4: _t->on_btn_back_clicked(); break;
        case 5: _t->handleRoomCreationStatus((*reinterpret_cast< std::add_pointer_t<char*>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (addItem::*)();
            if (_t _q_method = &addItem::cancelClicked; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject addItem::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_addItem.offsetsAndSizes,
    qt_meta_data_addItem,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_addItem_t
, QtPrivate::TypeAndForceComplete<addItem, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<char *, std::false_type>


>,
    nullptr
} };


const QMetaObject *addItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *addItem::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_addItem.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int addItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void addItem::cancelClicked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
