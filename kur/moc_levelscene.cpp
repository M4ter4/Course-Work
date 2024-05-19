/****************************************************************************
** Meta object code from reading C++ file 'levelscene.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "levelscene.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'levelscene.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_LevelScene_t {
    QByteArrayData data[18];
    char stringdata0[253];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LevelScene_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LevelScene_t qt_meta_stringdata_LevelScene = {
    {
QT_MOC_LITERAL(0, 0, 10), // "LevelScene"
QT_MOC_LITERAL(1, 11, 15), // "updatePlayerPos"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 12), // "Square::Cell"
QT_MOC_LITERAL(4, 41, 4), // "cell"
QT_MOC_LITERAL(5, 46, 11), // "updateField"
QT_MOC_LITERAL(6, 58, 24), // "QVector<QVector<bool> >*"
QT_MOC_LITERAL(7, 83, 14), // "gameOverSignal"
QT_MOC_LITERAL(8, 98, 16), // "enemyDeathSignal"
QT_MOC_LITERAL(9, 115, 15), // "nextRoundSignal"
QT_MOC_LITERAL(10, 131, 14), // "changePlayerHP"
QT_MOC_LITERAL(11, 146, 2), // "hp"
QT_MOC_LITERAL(12, 149, 16), // "onPowerUpTimeout"
QT_MOC_LITERAL(13, 166, 13), // "onWallDestroy"
QT_MOC_LITERAL(14, 180, 18), // "onPlayerChangeCell"
QT_MOC_LITERAL(15, 199, 16), // "onEnemyDeathSlot"
QT_MOC_LITERAL(16, 216, 17), // "onPlayerDeathSlot"
QT_MOC_LITERAL(17, 234, 18) // "changePlayerHPSlot"

    },
    "LevelScene\0updatePlayerPos\0\0Square::Cell\0"
    "cell\0updateField\0QVector<QVector<bool> >*\0"
    "gameOverSignal\0enemyDeathSignal\0"
    "nextRoundSignal\0changePlayerHP\0hp\0"
    "onPowerUpTimeout\0onWallDestroy\0"
    "onPlayerChangeCell\0onEnemyDeathSlot\0"
    "onPlayerDeathSlot\0changePlayerHPSlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LevelScene[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x06 /* Public */,
       5,    1,   77,    2, 0x06 /* Public */,
       7,    0,   80,    2, 0x06 /* Public */,
       8,    0,   81,    2, 0x06 /* Public */,
       9,    0,   82,    2, 0x06 /* Public */,
      10,    1,   83,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      12,    0,   86,    2, 0x0a /* Public */,
      13,    1,   87,    2, 0x0a /* Public */,
      14,    1,   90,    2, 0x0a /* Public */,
      15,    0,   93,    2, 0x0a /* Public */,
      16,    0,   94,    2, 0x0a /* Public */,
      17,    1,   95,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::SChar,   11,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::SChar,   11,

       0        // eod
};

void LevelScene::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<LevelScene *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updatePlayerPos((*reinterpret_cast< Square::Cell(*)>(_a[1]))); break;
        case 1: _t->updateField((*reinterpret_cast< QVector<QVector<bool> >*(*)>(_a[1]))); break;
        case 2: _t->gameOverSignal(); break;
        case 3: _t->enemyDeathSignal(); break;
        case 4: _t->nextRoundSignal(); break;
        case 5: _t->changePlayerHP((*reinterpret_cast< qint8(*)>(_a[1]))); break;
        case 6: _t->onPowerUpTimeout(); break;
        case 7: _t->onWallDestroy((*reinterpret_cast< Square::Cell(*)>(_a[1]))); break;
        case 8: _t->onPlayerChangeCell((*reinterpret_cast< Square::Cell(*)>(_a[1]))); break;
        case 9: _t->onEnemyDeathSlot(); break;
        case 10: _t->onPlayerDeathSlot(); break;
        case 11: _t->changePlayerHPSlot((*reinterpret_cast< qint8(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (LevelScene::*)(Square::Cell );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LevelScene::updatePlayerPos)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (LevelScene::*)(QVector<QVector<bool>> * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LevelScene::updateField)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (LevelScene::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LevelScene::gameOverSignal)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (LevelScene::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LevelScene::enemyDeathSignal)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (LevelScene::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LevelScene::nextRoundSignal)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (LevelScene::*)(qint8 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&LevelScene::changePlayerHP)) {
                *result = 5;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject LevelScene::staticMetaObject = { {
    QMetaObject::SuperData::link<QGraphicsScene::staticMetaObject>(),
    qt_meta_stringdata_LevelScene.data,
    qt_meta_data_LevelScene,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *LevelScene::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LevelScene::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_LevelScene.stringdata0))
        return static_cast<void*>(this);
    return QGraphicsScene::qt_metacast(_clname);
}

int LevelScene::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsScene::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void LevelScene::updatePlayerPos(Square::Cell _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void LevelScene::updateField(QVector<QVector<bool>> * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void LevelScene::gameOverSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void LevelScene::enemyDeathSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void LevelScene::nextRoundSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void LevelScene::changePlayerHP(qint8 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
