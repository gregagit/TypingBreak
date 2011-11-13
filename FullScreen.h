/* 
 * File:   FullScreen.h
 * Author: grega
 *
 * Created on Torek, 30 avgust 2011, 1:56
 */

#ifndef FULLSCREEN_H
#define	FULLSCREEN_H

#include <QGraphicsView>
#include <QPainter>
#include <QRectF>
#include <QBrush>
#include <QLabel>
#include <QDesktopWidget>
#include <QRect>
#include <QMessageBox>
#include <QEvent>

class FullScreen : public QWidget  {
    Q_OBJECT
public:
    FullScreen();
    FullScreen( QRect screen );
    virtual ~FullScreen();
    
    void odpri( int withText, QString zacCas = "" );
    void zapri();
    void osveziCas(QString cas);

private:
    QRect screen;
    QLabel *label1;
    QLabel *label2;

    void setLabel1();
    void setLabel2( QString zacCas );
    //bool event ( QEvent * event );

};

#endif	/* FULLSCREEN_H */

