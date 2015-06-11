/****************************************************************************
** Meta object code from reading C++ file 'PluginGUIHandler.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "gui/PluginGUIHandler.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'PluginGUIHandler.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_PluginGUIHandler[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      26,   18,   17,   17, 0x0a,
      54,   18,   17,   17, 0x0a,
      80,   18,   17,   17, 0x0a,
     108,   18,   17,   17, 0x0a,
     145,  136,   17,   17, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_PluginGUIHandler[] = {
    "PluginGUIHandler\0\0peer_id\0"
    "ReceivedInvitation(QString)\0"
    "ReceivedVoipData(QString)\0"
    "ReceivedVoipHangUp(QString)\0"
    "ReceivedVoipAccept(QString)\0peer_id,\0"
    "ReceivedVoipBandwidthInfo(QString,int)\0"
};

void PluginGUIHandler::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        PluginGUIHandler *_t = static_cast<PluginGUIHandler *>(_o);
        switch (_id) {
        case 0: _t->ReceivedInvitation((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->ReceivedVoipData((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->ReceivedVoipHangUp((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->ReceivedVoipAccept((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->ReceivedVoipBandwidthInfo((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData PluginGUIHandler::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject PluginGUIHandler::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_PluginGUIHandler,
      qt_meta_data_PluginGUIHandler, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &PluginGUIHandler::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *PluginGUIHandler::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *PluginGUIHandler::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PluginGUIHandler))
        return static_cast<void*>(const_cast< PluginGUIHandler*>(this));
    return QObject::qt_metacast(_clname);
}

int PluginGUIHandler::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_END_MOC_NAMESPACE
