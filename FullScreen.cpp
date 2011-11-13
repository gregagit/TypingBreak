/* 
 * File:   FullScreen.cpp
 * Author: grega
 * 
 * Created on Torek, 30 avgust 2011, 1:56
 */

#include <qt4/QtGui/qbrush.h>
#include <qt4/QtGui/qlabel.h>
#include <qt4/QtGui/qmessagebox.h>

#include "FullScreen.h"

FullScreen::FullScreen() {
}

FullScreen::FullScreen( QRect screen ) {
    this->screen = screen;

    this->label1 = new QLabel(this);
    this->label2 = new QLabel(this);

    this->setFocusPolicy( Qt::StrongFocus );
}


FullScreen::~FullScreen() {
}

//bool FullScreen::event ( QEvent *event ){
//    event->accept();
//    return true;
//}




/**
 *
 * @param screen
 */
void FullScreen::setLabel1(){
    int fS = 30;
 
    this->label1->setWindowOpacity(1);
    this->label1->setGeometry( this->screen.width()/2-250, this->screen.height()/2-100-fS, 500, 100 );
    this->label1->setText( "Potreben bo odmor!" );
    this->label1->setFont( QFont("Times", fS, QFont::Bold) );
    this->label1->setAlignment ( Qt::AlignCenter );

    this->label1->show();
}

void FullScreen::setLabel2( QString zacCas ){
    int fS = 30;

    this->label2->setWindowOpacity(1);
    this->label2->setGeometry( this->screen.width()/2-150, this->screen.height()/2-80, 300, 100 );
    this->label2->setText( zacCas );
    this->label2->setFont( QFont("Times", fS, QFont::Bold) );
    this->label2->setAlignment ( Qt::AlignCenter );

    this->label2->show();
}

/**
 *
 * @param cas
 */
void FullScreen::odpri( int withText, QString zacCas  ){

    this->setWindowOpacity( 0.5 );
    this->showFullScreen();

    if ( withText == 1 ){
        this->setLabel1();
        this->setLabel2( zacCas );
    }

    this->grabKeyboard();
    this->grabMouse();    
}

/**
 *
 */
void FullScreen::zapri(){
    this->releaseKeyboard();
    this->releaseMouse();
    this->hide();
}

/**
 *
 * @param cas
 */
void FullScreen::osveziCas(QString cas){
    this->label2->setText( cas );
}
