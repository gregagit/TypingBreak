/*
 * File:   mainForm.cpp
 * Author: grega
 *
 * Created on Torek, 30 avgust 2011, 0:02
 */

#include "mainForm.h"

mainForm::mainForm() {
    widget.setupUi(this);
}

mainForm::mainForm(QRect screen, QString pt){
    widget.setupUi(this);

    this->pot = pt;
 
    this->setWindowTitle("Keyboard Watcher");
    //this->setWindowTitle(pot);
    this->setWindowIcon( QIcon(this->pot + "/glavnaIkona.xpm") );

    this->trayIcon = new QSystemTrayIcon( QIcon(this->pot + "/glavnaIkona.xpm"), this);
    this->trayIcon->show();

    this->fullScreen = new FullScreen( screen );

    this->maliTimer = new QTimer();
    this->glavniTimer = new QTimer();

    connect(this->glavniTimer, SIGNAL(timeout()), this, SLOT(glavniTimerExecute()));
    connect(this->maliTimer, SIGNAL(timeout()), this, SLOT(maliTimerExecute()));
    connect(widget.pushButtonVklop, SIGNAL( pressed() ),this, SLOT( vklopPressed() ) );
    connect(widget.actionIzhod, SIGNAL( triggered() ),this, SLOT( izhodPressed() ) );
    connect(this->trayIcon, SIGNAL( activated(QSystemTrayIcon::ActivationReason) ),this, SLOT( trayLeftClicked(QSystemTrayIcon::ActivationReason) ) );

    this->isActivared = 0;
    this->exitStatus = 0;

    // tudi kliče zagon v primeru da je tako v nastavitvah
    this->getParFromF();
}



mainForm::~mainForm() {
    this->setParFromF();
}

/** povožena rutina
 *  aplikacijo zapremo le če je this->exitStatus enak 1
 *
 * @param event
 */
void mainForm::closeEvent ( QCloseEvent * event){
    if( this->exitStatus == 0 ){
            event->ignore();
            this->hide();
    } else if( this->exitStatus == 0 ){
        event->accept();
    }

}

/** Signal se kliče ob vsakem kliku na tray ikono
 *
 * @param reason
 */
void mainForm::trayLeftClicked( QSystemTrayIcon::ActivationReason reason ){
    if( this->isVisible() )
        this->hide();
    else if( !this->isVisible() )
        this->show();
}

/** signal za dejanski izhod, ce ga pritisnem v meniju
 *
 */
void mainForm::izhodPressed(){
   this->exitStatus = 1;
   this->close();
}

/** Na zacetku preberem parametre za oba casa iz datoteke, ce obstaja
 *  prvi je interval dela
 *  drugi je cas odmora
 * tretji je stenje programa ob izhodu
 */
void mainForm::getParFromF(){

     QByteArray line;

     QFile file(this->pot + "/param.set");
     if ( file.open(QIODevice::ReadOnly | QIODevice::Text) ){
         for(int i=0;i<3;i++){
             if(file.atEnd()) break;
             line = file.readLine();
             if( i== 0) this->widget.lineEditIntervalDela->setText( QString(line).trimmed() );
             if( i== 1) this->widget.lineEditCasOdmora->setText( QString(line).trimmed() );
             if( (i== 2) & ( QString(line).trimmed().toInt() == 1 ) ){
                 vklopPressed();
                 break;
             }
        }
         file.close();
     }
}


/** Na koncu shranim zadnje parametre za oba casa v datoteke
 * ter ali je bil timer v zagonu ali ne
 */
void mainForm::setParFromF(){
    QFile file(this->pot + "/param.set");

    if ( file.open( QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate ) ){

        QByteArray line;
        
        line = this->widget.lineEditIntervalDela->text().trimmed().toAscii();
        file.write( line );
        file.write( "\n" );
        line = this->widget.lineEditCasOdmora->text().trimmed().toAscii();
        file.write( line );
        file.write( "\n" );
        line = QByteArray::number( this->isActivared );
        file.write( line );
        
        file.close();
    }
}


/** Glavni timer, interval na katerega se sprozi aplikacija
 *  proži se vsako minuto, dokler se ne izteče this->intervalPremora
 * 
 * @return 
 */
void mainForm::glavniTimerExecute(){
    if( this->intervalPremora <= 0 ){

        QString min = "";
        QString sek = "";
        min.setNum( this->casPremora / 60 );
        sek.setNum( this->casPremora % 60 );
        if (  (this->casPremora % 60) < 10 )
                sek = "0" + sek;

        this->fullScreen->odpri(1,  min + ":" + sek );
        this->maliTimer->start(1000);

        this->glavniTimer->stop();        

    } else{
            this->intervalPremora = this->intervalPremora - 1;

            QString min = "";
            min.setNum( this->intervalPremora );
            this->widget.labelIzpis->setText( min + " min" );
            this->trayIcon->setToolTip("Do premora ostaja "  + min + " min." );

            if ( this->intervalPremora < 1 ){
                this->trayIcon->setToolTip(" Do premora ostaja manj kot minuta " );
                this->trayIcon->showMessage("Pozor", "Do premora ostaja še manj kot minuta");
                this->trayIcon->setIcon( QIcon(this->pot + "/glavnaIkona2.xpm") );
            }
                
    }
}

/** drugi timer ki deluje v času odmora
 * prozi se vsako sekundo dokkelr se this->casPremora ne izteče
 *
 */
void mainForm::maliTimerExecute(){

    if( this->casPremora <= 0 ){

        this->maliTimer->stop();
        this->fullScreen->zapri();

        this->casPremora = this->widget.lineEditCasOdmora->text().toFloat() * 60;
        this->intervalPremora = this->widget.lineEditIntervalDela->text().toInt();

        this->glavniTimer->start( 60 * 1000 );

        QString min = "";
        min.setNum( this->intervalPremora );
        this->widget.labelIzpis->setText( min + " min" );

        this->trayIcon->setToolTip("Do premora ostaja "  + min + " min." );
        this->trayIcon->setIcon( QIcon(this->pot + "/glavnaIkona.xpm") );
        
    } else{
            this->casPremora = this->casPremora - 1;

            QString min = "";
            QString sek = "";
            min.setNum( this->casPremora / 60 );
            sek.setNum( this->casPremora % 60 );

            if (  (this->casPremora % 60) < 10 )
                sek = "0" + sek;

            this->fullScreen->osveziCas( min + ":" + sek );

    }

}

/** signal ob kliku na gumb
 *
 */
void mainForm::vklopPressed(){

    if( this->isActivared == 0 ){
            this->casPremora = this->widget.lineEditCasOdmora->text().toFloat() * 60;
            this->intervalPremora = this->widget.lineEditIntervalDela->text().toInt();

            this->glavniTimer->start( 60 * 1000 );
            this->isActivared = 1;
            this->widget.pushButtonVklop->setText("Izkljuci");

            this->widget.lineEditCasOdmora->setEnabled( false );
            this->widget.lineEditIntervalDela->setEnabled( false );

            QString min = "";
            min.setNum( this->intervalPremora );
            this->widget.labelIzpis->setText( min + " min" );

            this->trayIcon->setToolTip("Do premora ostaja "  + min + " min." );
            this->trayIcon->setIcon( QIcon(this->pot + "/glavnaIkona.xpm") );

    } else if( this->isActivared == 1 ){
            this->glavniTimer->stop();
            this->isActivared = 0;
            this->widget.pushButtonVklop->setText("Vkljuci");
            this->widget.labelIzpis->setText("Izkljucen");

            this->widget.lineEditCasOdmora->setEnabled( true );
            this->widget.lineEditIntervalDela->setEnabled( true );

            this->trayIcon->setIcon( QIcon(this->pot + "/glavnaIkona.xpm") );
    }

    
}