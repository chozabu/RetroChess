/****************************************************************************
** Meta object code from reading C++ file 'PluginNotifier.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "gui/PluginNotifier.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'PluginNotifier.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_PluginNotifier[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x05,
      48,   15,   15,   15, 0x05,
      82,   74,   15,   15, 0x05,
     110,   74,   15,   15, 0x05,
     160,  138,   15,   15, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_PluginNotifier[] = {
    "PluginNotifier\0\0voipInvitationReceived(QString)\0"
    "voipDataReceived(QString)\0peer_id\0"
    "voipHangUpReceived(QString)\0"
    "voipAcceptReceived(QString)\0"
    "peer_id,bytes_per_sec\0"
    "voipBandwidthInfoReceived(QString,int)\0"
};

void PluginNotifier::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        PluginNotifier *_t = static_cast<PluginNotifier *>(_o);
        switch (_id) {
        case 0: _t->voipInvitationReceived((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->voipDataReceived((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->voipHangUpReceived((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->voipAcceptReceived((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->voipBandwidthInfoReceived((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData PluginNotifier::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject PluginNotifier::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_PluginNotifier,
      qt_meta_data_PluginNotifier, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &PluginNotifier::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *PluginNotifier::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *PluginNotifier::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PluginNotifier))
        return static_cast<void*>(const_cast< PluginNotifier*>(this));
    return QObject::qt_metacast(_clname);
}

int PluginNotifier::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void PluginNotifier::voipInvitationReceived(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void PluginNotifier::voipDataReceived(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void PluginNotifier::voipHangUpReceived(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void PluginNotifier::voipAcceptReceived(const QString & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void PluginNotifier::voipBandwidthInfoReceived(const QString & _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_END_MOC_NAMESPACE
