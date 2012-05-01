/****************************************************************************
** Meta object code from reading C++ file 'gridcell.h'
**
** Created: Mon Apr 30 23:45:22 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "gridcell.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gridcell.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_GridCell[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      15,   10,    9,    9, 0x05,

 // slots: signature, parameters, type, tag, flags
      37,    9,    9,    9, 0x0a,
      51,   10,    9,    9, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_GridCell[] = {
    "GridCell\0\0type\0typeChanged(CellType)\0"
    "handleClick()\0setType(CellType)\0"
};

const QMetaObject GridCell::staticMetaObject = {
    { &QFrame::staticMetaObject, qt_meta_stringdata_GridCell,
      qt_meta_data_GridCell, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &GridCell::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *GridCell::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *GridCell::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GridCell))
        return static_cast<void*>(const_cast< GridCell*>(this));
    return QFrame::qt_metacast(_clname);
}

int GridCell::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QFrame::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: typeChanged((*reinterpret_cast< CellType(*)>(_a[1]))); break;
        case 1: handleClick(); break;
        case 2: setType((*reinterpret_cast< CellType(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void GridCell::typeChanged(CellType _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
