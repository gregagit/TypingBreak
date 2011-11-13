/********************************************************************************
** Form generated from reading UI file 'mainForm.ui'
**
** Created: Mon Oct 24 02:23:40 2011
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINFORM_H
#define UI_MAINFORM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mainForm
{
public:
    QAction *actionIzhod;
    QWidget *centralwidget;
    QPushButton *pushButtonVklop;
    QLineEdit *lineEditCasOdmora;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEditIntervalDela;
    QLabel *labelIzpis;
    QLabel *label_3;
    QLabel *label_4;
    QMenuBar *menubar;
    QMenu *menuMeni;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *mainForm)
    {
        if (mainForm->objectName().isEmpty())
            mainForm->setObjectName(QString::fromUtf8("mainForm"));
        mainForm->resize(267, 253);
        actionIzhod = new QAction(mainForm);
        actionIzhod->setObjectName(QString::fromUtf8("actionIzhod"));
        centralwidget = new QWidget(mainForm);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pushButtonVklop = new QPushButton(centralwidget);
        pushButtonVklop->setObjectName(QString::fromUtf8("pushButtonVklop"));
        pushButtonVklop->setGeometry(QRect(30, 60, 71, 41));
        lineEditCasOdmora = new QLineEdit(centralwidget);
        lineEditCasOdmora->setObjectName(QString::fromUtf8("lineEditCasOdmora"));
        lineEditCasOdmora->setGeometry(QRect(130, 130, 31, 27));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(130, 110, 91, 17));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(130, 50, 91, 17));
        lineEditIntervalDela = new QLineEdit(centralwidget);
        lineEditIntervalDela->setObjectName(QString::fromUtf8("lineEditIntervalDela"));
        lineEditIntervalDela->setGeometry(QRect(130, 70, 31, 27));
        labelIzpis = new QLabel(centralwidget);
        labelIzpis->setObjectName(QString::fromUtf8("labelIzpis"));
        labelIzpis->setGeometry(QRect(30, 110, 67, 17));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(170, 70, 51, 31));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(170, 130, 51, 31));
        mainForm->setCentralWidget(centralwidget);
        menubar = new QMenuBar(mainForm);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 267, 25));
        menuMeni = new QMenu(menubar);
        menuMeni->setObjectName(QString::fromUtf8("menuMeni"));
        mainForm->setMenuBar(menubar);
        statusbar = new QStatusBar(mainForm);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        mainForm->setStatusBar(statusbar);

        menubar->addAction(menuMeni->menuAction());
        menuMeni->addAction(actionIzhod);

        retranslateUi(mainForm);

        QMetaObject::connectSlotsByName(mainForm);
    } // setupUi

    void retranslateUi(QMainWindow *mainForm)
    {
        mainForm->setWindowTitle(QApplication::translate("mainForm", "mainForm", 0, QApplication::UnicodeUTF8));
        actionIzhod->setText(QApplication::translate("mainForm", "Izhod", 0, QApplication::UnicodeUTF8));
        pushButtonVklop->setText(QApplication::translate("mainForm", "Vkljuci", 0, QApplication::UnicodeUTF8));
        lineEditCasOdmora->setText(QApplication::translate("mainForm", "5", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("mainForm", "\304\214as odmora", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("mainForm", "Interval dela", 0, QApplication::UnicodeUTF8));
        lineEditIntervalDela->setText(QApplication::translate("mainForm", "45", 0, QApplication::UnicodeUTF8));
        labelIzpis->setText(QApplication::translate("mainForm", "Izkljucen", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("mainForm", "min", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("mainForm", "min", 0, QApplication::UnicodeUTF8));
        menuMeni->setTitle(QApplication::translate("mainForm", "Meni", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class mainForm: public Ui_mainForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINFORM_H
