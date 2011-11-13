/*
 * File:   main.cpp
 * Author: grega
 *
 * Created on Torek, 30 avgust 2011, 0:00
 */

#include <QtGui/QApplication>
#include <qt4/QtGui/qwidget.h>
#include "mainForm.h"

#include <QDesktopWidget>
#include <QRect>
#include <QString>
#include <QFileInfo>

int main(int argc, char *argv[]) {
    // initialize resources, if needed
    // Q_INIT_RESOURCE(resfile);

    QApplication app(argc, argv);
    app.setApplicationName("KeyboardWatcher");
    
    QDesktopWidget *desktop = app.desktop();
    QRect screen = desktop->screenGeometry();

    // create and show your widgets here
    mainForm *form = new mainForm(screen, app.applicationDirPath() );

        //

    return app.exec();
}
