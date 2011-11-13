/* 
 * File:   mainForm.h
 * Author: grega
 *
 * Created on Torek, 30 avgust 2011, 0:02
 */

#ifndef _MAINFORM_H
#define	_MAINFORM_H

#include "ui_mainForm.h"
#include <QTimer>
#include <QString>
#include <QGraphicsView>
#include <QDesktopWidget>
#include <QRect>
#include <QCloseEvent>
#include <QSystemTrayIcon>
#include <QFile>

#include "FullScreen.h"

class mainForm : public QMainWindow {
    Q_OBJECT
public:
    mainForm();    
    virtual ~mainForm();
    mainForm(QRect screen, QString pt);

    int intervalPremora;
    int casPremora;
    QString pot;

    QTimer *glavniTimer;
    QTimer *maliTimer;

    FullScreen *fullScreen;

    

public slots:
    void glavniTimerExecute();
    void maliTimerExecute();

    void vklopPressed();
    void trayLeftClicked( QSystemTrayIcon::ActivationReason reason );
    void izhodPressed();
    
private:
    Ui::mainForm widget;    
    QSystemTrayIcon *trayIcon;
    int isActivared;
    int exitStatus;

    void closeEvent ( QCloseEvent * event);
    void getParFromF();
    void setParFromF();
};

#endif	/* _MAINFORM_H */
