/****************************************************************************
** Meta object code from reading C++ file 'gridwindow.h'
**
** Created: Mon Apr 30 23:45:23 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "gridwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'gridwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_GridWindow[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x0a,
      26,   11,   11,   11, 0x0a,
      40,   11,   11,   11, 0x0a,
      54,   11,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_GridWindow[] = {
    "GridWindow\0\0handleClear()\0handleStart()\0"
    "handlePause()\0timerFired()\0"
};

const QMetaObject GridWindow::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_GridWindow,
      qt_meta_data_GridWindow, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &GridWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *GridWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *GridWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_GridWindow))
        return static_cast<void*>(const_cast< GridWindow*>(this));
    return QWidget::qt_metacast(_clname);
}

int GridWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: handleClear(); break;
        case 1: handleStart(); break;
        case 2: handlePause(); break;
        case 3: timerFired(); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
