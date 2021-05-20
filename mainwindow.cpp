#include "mainwindow.h"
#include "QPalette"
#include <iostream>
#include <QMessageBox>
#include <QFlags>
#include <QSizePolicy>
#include <QInputDialog>
#include <QFile>
#include <QTextStream>
#include <QPropertyAnimation>
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("BIENVENUE");
    setFixedSize(1400,800);
      QMenu *Niveau = menuBar()->addMenu("&niveau");
       QAction *niveau1 = new QAction("&niveau1", this);

       QMenu *inscription = menuBar()->addMenu("&inscription");
        QAction *inscrire = new QAction("&inscrire", this);
         Niveau->addAction(niveau1);
           inscription->addAction(inscrire);

          QAction *niveau2 = new QAction("&niveau2", this);
             Niveau->addAction(niveau2);

            QAction *niveau3 = new QAction("&niveau3", this);
                Niveau->addAction(niveau3);


              temps_restant=new QProgressBar(this);
              temps_restant->setMaximum(60);
              temps_restant->setGeometry(100,30,5,480);




  view=new QGraphicsView();
    scen=new scene(view);
    view->setScene(scen);
    view->centerOn(0,0);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
   start=new QPushButton("start");
   QPushButton *paus=new QPushButton("pause",this);
   reinitial=new QPushButton("reinitialiser");
   compteur =new QLabel();
   compteur->setText(QString::number(mm)+":"+QString::number(ss));
   time=new QTimer();
   QLabel *mvment=new QLabel;
   mvment->setText("deplacement");





   QLabel *niveau=new QLabel;
   niveau->setText("niveau");
   affich_mouv_nbr=new QLCDNumber;
   affich_niveau_act=new QLCDNumber;
    view->update();
    layout=new QGridLayout;
    layout->addWidget(view,0,0,12,12);
    layout->addWidget(start,4,0,1,1);
    layout->addWidget(paus,6,0,1,1);
    layout->addWidget(reinitial,7,0,2,1);
    layout->addWidget(compteur,4,9,2,1);

    layout->addWidget(mvment,6,9,1,1);
    layout->addWidget(niveau,7,9,1,1);
    layout->addWidget(affich_mouv_nbr,6,10,1,1);
    layout->addWidget(affich_niveau_act,7,10,1,1);

      layout->addWidget(temps_restant,0,3,1,6);
      QFont font("Times", 10, 50,true);
      temps_restant->setFont(font);
      temps_restant->setStyleSheet("background-color: dimGray;color:white;border-style: outset;border-width: 2px; border-radius: 10px; border-color: beige;font: bold 25px;");

    containeur=new QWidget;
    containeur->setLayout(layout);
    setCentralWidget(containeur);
    this->setStyleSheet("niveau,QMenu,QLabel{color:white;font:bold 25px;border-style: outset;border-width: 2px; border-radius: 10px;background-color:dimGray};");
    //this->setStyleSheet("QLabel{color:blue}");




connect(niveau1,SIGNAL(triggered()),this,SLOT(choisir_Niveau1()));
connect(niveau2,SIGNAL(triggered()),this,SLOT(choisir_Niveau2()));
connect(niveau3,SIGNAL(triggered()),this,SLOT(choisir_Niveau3()));

connect(inscrire,SIGNAL(triggered()),this,SLOT(inscrire()));
connect(start,SIGNAL(clicked()),this,SLOT(commencer_jeu()));
connect(this,SIGNAL(mouv_autorise()),scen,SLOT(mouv()));
connect(reinitial,SIGNAL(clicked()),this,SLOT(reinitialiser()));

connect(time,SIGNAL(timeout()),this,SLOT(compteur_change()));
connect(scen,SIGNAL(gagne()),this,SLOT(felicitation()));
connect(start,SIGNAL(clicked()),this,SLOT(activer_chrono()));
connect(paus,SIGNAL(clicked()),this,SLOT(pause()));
connect(this,SIGNAL(loser()),this,SLOT(perdu()));
connect(scen,SIGNAL(mov_effectuer(int )),affich_mouv_nbr,SLOT(display(int)));



connect(suivant,SIGNAL(clicked()),this,SLOT(next()));
connect(rejouer,SIGNAL(clicked()),this,SLOT(replay()));


}

MainWindow::~MainWindow()
{
   // delete ui;

}

void MainWindow::choisir_Niveau1(){
   if(niveau_courant==0){
       scen->clear();
    scen->tracer_grid(6);
    niv=new mon_niveau;
    niv->setNiveau(1);
    int n=niv->getnb_bloc();
    scen->charger_niveau(niv->getNiveau(),n);
    scen->dessiner_scene(scen->getbloc_num());
    dessiner=true;
    niveau_courant=1;
    charger=true;
    affich_niveau_act->display(1);
}}

void MainWindow::choisir_Niveau2(){
   if(niveau_courant==0){
    scen->clear();

    niv=new mon_niveau;
    niv->setNiveau(2);
    int n=niv->getnb_bloc();
    scen->tracer_grid(6);
    scen->charger_niveau(niv->getNiveau(),n);
    niveau_courant=2;
    charger=true;
     affich_niveau_act->display(2);
}}

void MainWindow::choisir_Niveau3(){
    if(niveau_courant==0){
        scen->clear();

        niv=new mon_niveau;
        niv->setNiveau(3);
        int n=niv->getnb_bloc();
        scen->tracer_grid(6);
        scen->charger_niveau(niv->getNiveau(),n);
        niveau_courant=3;
        charger=true;
         affich_niveau_act->display(3);
}}
void MainWindow::commencer_jeu(){
   if(!dessiner&&charger){ scen->dessiner_scene(scen->getbloc_num());
       dessiner=true;
   }
    emit mouv_autorise();
}
 // QLabel *label=new QLabel;

void MainWindow::felicitation(){
        time->stop();
        scen->clear();
        score=calculer_score(scen->getNbr_deplacement(),mm,ss);
        sauvegarder_resultat();
       // QLabel *label=new QLabel;
        QPixmap *p=new QPixmap("C:/Users/LENOVO/Desktop/jeu-traffic/ressources/felicitation.jfif");
       label->setPixmap(QPixmap(p->scaled(1400,800,Qt::IgnoreAspectRatio)));

       scor->setText("<h3>bravo <font color='gold'> " + pseudo + "</font><br>votre score est :"+QString::number(score));
       //label->setText("bravo");
       //label->addAction(inscrire);

           animation->setDuration(500);
           animation->setStartValue(QRect(0, 0, 400, 400));
           animation->setEndValue(QRect(0, 0,1400 , 800));

           animation->start();
            //layout->addWidget(scor,0,0,2,1);
           layout->addWidget(label,0,0,13,13);
           suivant=new QPushButton("Next");
           scor->setHidden(false);
           label->setHidden(false);
          rejouer=new QPushButton("Replay");
          layout->addWidget(scor,3,3,2,2);
           layout->addWidget(rejouer,5,3,1,1);
           layout->addWidget(suivant,5,4,1,1);
           temps_restant->setValue(60);
           //suivant->animateClick(1000);



           compteur->setText(QString::number(0)+":"+QString::number(0));
                      lancer=false;
                    scen->setMov(false);
                     scen->setNbr_deplacement(0);
                      affich_mouv_nbr->display(0);


//        int reponse=QMessageBox::information(this, "felicitation", "<pre><h1>Bravo   "+pseudo+" votre score est :  " + QString::number(score) +"<br>vous avez gagne <br>voulez vous passer au niveau suivant?</strong<",QMessageBox::Yes|QMessageBox::No);
//        if(reponse==QMessageBox::Yes){
//            scen->clear();

//            niv=new mon_niveau;
//            niv->setNiveau(niveau_courant+1);
//            int n=niv->getnb_bloc();

//            scen->tracer_grid(6);
//            scen->charger_niveau(niv->getNiveau(),n);
//             scen->dessiner_scene(scen->getbloc_num());
//             compteur->setText(QString::number(0)+":"+QString::number(0));
//             lancer=false;
//             scen->setMov(false);
//             scen->setNbr_deplacement(0);
//             affich_mouv_nbr->display(0);
//             niveau_courant++;
//              affich_niveau_act->display(niveau_courant);

//        }

                      connect(suivant,SIGNAL(clicked()),this,SLOT(next()));
                      connect(rejouer,SIGNAL(clicked()),this,SLOT(replay()));


}
void MainWindow::next(){

                scen->clear();
                label->setHidden(true);
                suivant->close();
                rejouer->close();
                //scor->clear();
                scor->setHidden(true);

                niv=new mon_niveau;
               niv->setNiveau(niveau_courant+1);
                int n=niv->getnb_bloc();

               scen->tracer_grid(6);
                scen->charger_niveau(niv->getNiveau(),n);
                scen->dessiner_scene(scen->getbloc_num());
                niveau_courant++;
                affich_niveau_act->display(niveau_courant);


}

void MainWindow::replay(){

                scen->clear();

                label->setHidden(true);
                scor->setHidden(true);
                suivant->close();
                rejouer->close();
                niv=new mon_niveau;

                niv->setNiveau(niveau_courant);
                 int n=niv->getnb_bloc();
               scen->tracer_grid(6);
                scen->charger_niveau(niv->getNiveau(),n);
                scen->dessiner_scene(scen->getbloc_num());
                affich_niveau_act->display(niveau_courant);

}
void MainWindow::perdu(){
        scen->clear();
        QMessageBox::information(this, "echoue", "<pre><h1>desole vous etes perdu a cause de temps</h1>");



}
void MainWindow::compteur_change(){
    ss++;
    if(ss==60){
        mm++;
        ss=0;
    }
    compteur->setText(QString::number(mm)+":"+QString::number(ss));
    int rest = 60-ss;
    temps_restant->setValue(rest);
    if(mm==1){
        emit loser();
        time->disconnect();
        time->deleteLater();
    }

}
void MainWindow::activer_chrono(){
   if(!lancer&&charger){ mm=0;ss=0;
     compteur->setText(QString::number(mm)+":"+QString::number(ss));
    time->start(1000);
    lancer=true;
   }
   if(arreter){
       time->start();
       arreter=false;
   }
}
void MainWindow::inscrire(){
  pseudo=QInputDialog::getText(this,"inscription","<h1>QUel est votre nom?</h1>",QLineEdit::Normal,QString(),&ok);

  }

int MainWindow::calculer_score(int n, int mm,int ss){
    int temps=mm*60+ss;
    if(n<=15){
        return (500-temps+50);
    }
    else if(n<=20){
        return(500-temps+20);
    }
    else return(500-temps);

}

void MainWindow::sauvegarder_resultat(){
    if(ok&&!pseudo.isEmpty()){
        QFile historique("C:/Users/LENOVO/Desktop/jeu-traffic/ressources/historique.txt");
        historique.open(QIODevice::Append|QIODevice::Text);
        QTextStream cout(&historique);
        QString alignn(22-pseudo.size(),' ');
        QString ch =pseudo+alignn;
        cout<< ch   ;
        cout<<  QString::number( score)+"         "  ;
        cout<<  QString::number(mm )+":"+  QString::number(ss )+  "        "  ;
        cout<<  QString::number( scen->getNbr_deplacement())+"        "  <<'\n';
        cout <<'\n';

        historique.close();
    }

}
void MainWindow::reinitialiser(){
    scen->clear();
    scen->tracer_grid(6);
    scen->dessiner_scene(scen->getbloc_num());
}


void MainWindow::pause(){
    if(!arreter&&lancer){
    time->stop();
    arreter=true;
    scen->setMov(false);

    }
}
