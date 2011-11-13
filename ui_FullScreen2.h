/********************************************************************************
** Form generated from reading UI file 'FullScreen2.ui'
**
** Created: Thu Sep 1 01:35:51 2011
**      by: Qt User Interface Compiler version 4.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FULLSCREEN2_H
#define UI_FULLSCREEN2_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FullScreen2
{
public:

    void setupUi(QWidget *FullScreen2)
    {
        if (FullScreen2->objectName().isEmpty())
            FullScreen2->setObjectName(QString::fromUtf8("FullScreen2"));
        FullScreen2->resize(400, 300);

        retranslateUi(FullScreen2);

        QMetaObject::connectSlotsByName(FullScreen2);
    } // setupUi

    void retranslateUi(QWidget *FullScreen2)
    {
        FullScreen2->setWindowTitle(QApplication::translate("FullScreen2", "FullScreen2", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class FullScreen2: public Ui_FullScreen2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FULLSCREEN2_H
