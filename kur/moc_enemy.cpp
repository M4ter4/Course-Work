/****************************************************************************
** Meta object code from reading C++ file 'enemy.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "enemy.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'enemy.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Enemy_t {
    QByteArrayData data[10];
    char stringdata0[111];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Enemy_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Enemy_t qt_meta_stringdata_Enemy = {
    {
QT_MOC_LITERAL(0, 0, 5), // "Enemy"
QT_MOC_LITERAL(1, 6, 16), // "enemyDeathSignal"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 13), // "onWallDestroy"
QT_MOC_LITERAL(4, 38, 24), // "QVector<QVector<bool> >*"
QT_MOC_LITERAL(5, 63, 5), // "field"
QT_MOC_LITERAL(6, 69, 18), // "onPlayerCellUpdate"
QT_MOC_LITERAL(7, 88, 12), // "Square::Cell"
QT_MOC_LITERAL(8, 101, 4), // "cell"
QT_MOC_LITERAL(9, 106, 4) // "tick"

    },
    "Enemy\0enemyDeathSignal\0\0onWallDestroy\0"
    "QVector<QVector<bool> >*\0field\0"
    "onPlayerCellUpdate\0Square::Cell\0cell\0"
    "tick"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Enemy[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   35,    2, 0x0a /* Public */,
       6,    1,   38,    2, 0x0a /* Public */,
       9,    0,   41,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void,

       0        // eod
};

void Enemy::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Enemy *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->enemyDeathSignal(); break;
        case 1: _t->onWallDestroy((*reinterpret_cast< QVector<QVector<bool> >*(*)>(_a[1]))); break;
        case 2: _t->onPlayerCellUpdate((*reinterpret_cast< Square::Cell(*)>(_a[1]))); break;
        case 3: _t->tick(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Enemy::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Enemy::enemyDeathSignal)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Enemy::staticMetaObject = { {
    QMetaObject::SuperData::link<Tank::staticMetaObject>(),
    qt_meta_stringdata_Enemy.data,
    qt_meta_data_Enemy,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Enemy::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Enemy::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Enemy.stringdata0))
        return static_cast<void*>(this);
    return Tank::qt_metacast(_clname);
}

int Enemy::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Tank::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void Enemy::enemyDeathSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
