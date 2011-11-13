/****************************************************************************
** Meta object code from reading C++ file 'mainForm.h'
**
** Created: Mon Oct 24 02:23:50 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainForm.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainForm.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_mainForm[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x0a,
      31,    9,    9,    9, 0x0a,
      50,    9,    9,    9, 0x0a,
      72,   65,    9,    9, 0x0a,
     123,    9,    9,    9, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_mainForm[] = {
    "mainForm\0\0glavniTimerExecute()\0"
    "maliTimerExecute()\0vklopPressed()\0"
    "reason\0trayLeftClicked(QSystemTrayIcon::ActivationReason)\0"
    "izhodPressed()\0"
};

const QMetaObject mainForm::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_mainForm,
      qt_meta_data_mainForm, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &mainForm::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *mainForm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *mainForm::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_mainForm))
        return static_cast<void*>(const_cast< mainForm*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int mainForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: glavniTimerExecute(); break;
        case 1: maliTimerExecute(); break;
        case 2: vklopPressed(); break;
        case 3: trayLeftClicked((*reinterpret_cast< QSystemTrayIcon::ActivationReason(*)>(_a[1]))); break;
        case 4: izhodPressed(); break;
        default: ;
        }
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
