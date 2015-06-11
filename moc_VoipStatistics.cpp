/****************************************************************************
** Meta object code from reading C++ file 'VoipStatistics.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "gui/VoipStatistics.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'VoipStatistics.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_VoipStatistics[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

static const char qt_meta_stringdata_VoipStatistics[] = {
    "VoipStatistics\0"
};

void VoipStatistics::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObjectExtraData VoipStatistics::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject VoipStatistics::staticMetaObject = {
    { &RsAutoUpdatePage::staticMetaObject, qt_meta_stringdata_VoipStatistics,
      qt_meta_data_VoipStatistics, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &VoipStatistics::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *VoipStatistics::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *VoipStatistics::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_VoipStatistics))
        return static_cast<void*>(const_cast< VoipStatistics*>(this));
    if (!strcmp(_clname, "Ui::VoipStatistics"))
        return static_cast< Ui::VoipStatistics*>(const_cast< VoipStatistics*>(this));
    return RsAutoUpdatePage::qt_metacast(_clname);
}

int VoipStatistics::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = RsAutoUpdatePage::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_VoipStatisticsWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

static const char qt_meta_stringdata_VoipStatisticsWidget[] = {
    "VoipStatisticsWidget\0"
};

void VoipStatisticsWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObjectExtraData VoipStatisticsWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject VoipStatisticsWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_VoipStatisticsWidget,
      qt_meta_data_VoipStatisticsWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &VoipStatisticsWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *VoipStatisticsWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *VoipStatisticsWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_VoipStatisticsWidget))
        return static_cast<void*>(const_cast< VoipStatisticsWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int VoipStatisticsWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
