/********************************************************************************
** Form generated from reading UI file 'FullscreenForm.ui'
**
** Created: Tue Aug 30 01:04:39 2011
**      by: Qt User Interface Compiler version 4.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FULLSCREENFORM_H
#define UI_FULLSCREENFORM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FullscreenForm
{
public:
    QLabel *label;
    QLabel *labelPrikazCasa;

    void setupUi(QWidget *FullscreenForm)
    {
        if (FullscreenForm->objectName().isEmpty())
            FullscreenForm->setObjectName(QString::fromUtf8("FullscreenForm"));
        FullscreenForm->resize(601, 353);
        label = new QLabel(FullscreenForm);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(160, 80, 291, 81));
        QFont font;
        font.setFamily(QString::fromUtf8("Comic Sans MS"));
        font.setPointSize(20);
        label->setFont(font);
        labelPrikazCasa = new QLabel(FullscreenForm);
        labelPrikazCasa->setObjectName(QString::fromUtf8("labelPrikazCasa"));
        labelPrikazCasa->setGeometry(QRect(240, 160, 101, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Comic Sans MS"));
        font1.setPointSize(15);
        labelPrikazCasa->setFont(font1);

        retranslateUi(FullscreenForm);

        QMetaObject::connectSlotsByName(FullscreenForm);
    } // setupUi

    void retranslateUi(QWidget *FullscreenForm)
    {
        FullscreenForm->setWindowTitle(QApplication::translate("FullscreenForm", "FullscreenForm", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("FullscreenForm", "Potreben bo po\304\215itek!", 0, QApplication::UnicodeUTF8));
        labelPrikazCasa->setText(QApplication::translate("FullscreenForm", "Cas", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class FullscreenForm: public Ui_FullscreenForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FULLSCREENFORM_H
