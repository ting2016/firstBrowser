/****************************************************************************
** Meta object code from reading C++ file 'tab.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../tab.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tab.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Tab_t {
    QByteArrayData data[7];
    char stringdata0[73];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Tab_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Tab_t qt_meta_stringdata_Tab = {
    {
QT_MOC_LITERAL(0, 0, 3), // "Tab"
QT_MOC_LITERAL(1, 4, 19), // "askEnableJavaScript"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 7), // "askLoad"
QT_MOC_LITERAL(4, 33, 17), // "doEnableJavScript"
QT_MOC_LITERAL(5, 51, 6), // "doLoad"
QT_MOC_LITERAL(6, 58, 14) // "adjustLocation"

    },
    "Tab\0askEnableJavaScript\0\0askLoad\0"
    "doEnableJavScript\0doLoad\0adjustLocation"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Tab[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,
       3,    1,   40,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   43,    2, 0x09 /* Protected */,
       5,    1,   44,    2, 0x09 /* Protected */,
       6,    0,   47,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QUrl,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QUrl,    2,
    QMetaType::Void,

       0        // eod
};

void Tab::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Tab *_t = static_cast<Tab *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->askEnableJavaScript(); break;
        case 1: _t->askLoad((*reinterpret_cast< QUrl(*)>(_a[1]))); break;
        case 2: _t->doEnableJavScript(); break;
        case 3: _t->doLoad((*reinterpret_cast< QUrl(*)>(_a[1]))); break;
        case 4: _t->adjustLocation(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Tab::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Tab::askEnableJavaScript)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Tab::*_t)(QUrl );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Tab::askLoad)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject Tab::staticMetaObject = {
    { &QWebView::staticMetaObject, qt_meta_stringdata_Tab.data,
      qt_meta_data_Tab,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Tab::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Tab::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Tab.stringdata0))
        return static_cast<void*>(const_cast< Tab*>(this));
    return QWebView::qt_metacast(_clname);
}

int Tab::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWebView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void Tab::askEnableJavaScript()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void Tab::askLoad(QUrl _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
