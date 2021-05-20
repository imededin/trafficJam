#include "mafenetre.h"
#include<QFileDialog>
#include<QPixmap>
#include <QLabel>
#include <QSizePolicy>


Mafenetre::Mafenetre():QWidget()
{
   setFixedSize(1000,1000);


    setWindowTitle("jeu du traffic jam");
    QGridLayout *layoutp = new QGridLayout;
         QLabel *image = new QLabel(this);
         QPixmap *p=new QPixmap("C:/Users/LENOVO/Desktop/jeu-traffic/ressources/bg.png");
         image->setPixmap(QPixmap(p->scaled(1200,1200,Qt::KeepAspectRatio)));


         QLabel *imag = new QLabel(this);
         QPixmap *p0=new QPixmap("C:/Users/LENOVO/Desktop/jeu-traffic/ressources/logo3.png");
         imag->setPixmap(QPixmap(p0->scaled(800,200,Qt::IgnoreAspectRatio)));
         imag->setStyleSheet("background-color:transparent");


         QLabel *image3 = new QLabel(this);
         QPixmap *p3=new QPixmap("C:/Users/LENOVO/Desktop/jeu-traffic/ressources/logo1.png");
         image3->setPixmap(QPixmap(p3->scaled(350,350,Qt::KeepAspectRatio)));
         image3->setStyleSheet("background-color:transparent");
         imag->setStyleSheet("background-color: dimGray;color:white;border-style: outset;border-width: 2px; border-radius: 10px; border-color: beige;font: bold 15px;");




         setLayout(layoutp);
         layoutp->addWidget(image,0,0,10,10);
         //layoutp->addWidget(image1,6,6,5,5);
         //layoutp->addWidget(image2,6,0,5,5);
         layoutp->addWidget(image3,6,3,5,5);
         layoutp->addWidget(imag,1,1,2,8);
    QPushButton *guide=new QPushButton("Guide");
    QPushButton *historiq=new QPushButton("Historique");
    QPushButton *quitter=new QPushButton("Quitter");
    QPushButton *a_propos=new QPushButton("A propos");
    QPushButton *jouer=new QPushButton("Jouer");
    layoutp->addWidget(jouer,2,3,2,2);
    layoutp->addWidget(guide,3,3,2,2);
    layoutp->addWidget(historiq,4,3,2,2);
    layoutp->addWidget(a_propos,5,3,2,2);
    layoutp->addWidget(quitter,6,3,2,2);
    w=new MainWindow;
    A=new apropos;

     connect(quitter,SIGNAL(clicked()),qApp,SLOT(quit()));
     connect(guide,SIGNAL(clicked()),this,SLOT(ouvrirDialogue()));
     connect(jouer,SIGNAL(clicked()),this,SLOT(Jouer()));
     connect(a_propos,SIGNAL(clicked()),this,SLOT(A_propos()));
     connect(historiq,SIGNAL(clicked()),this,SLOT(histo()));
}
void Mafenetre::ouvrirDialogue(){

    QWidget *mon_guide=new QWidget;
    mon_guide->setStyleSheet("background-color:transparent;color:white");
    mon_guide->setGeometry(300,100,1200,1200);
    QLabel*bg=new QLabel;
    QPixmap *p=new QPixmap;

    p=new QPixmap("C:/Users/LENOVO/Desktop/jeu-traffic/ressources/guide_bg.png");
    bg->setPixmap(QPixmap(p->scaled(1600,900,Qt::IgnoreAspectRatio)));
    QGridLayout *layout=new QGridLayout;
      layout->addWidget(bg,0,0,9,9);
    QLabel *text=new QLabel(bg);
    text->setText("<pre><p align=center><font color= gold size=100>guide</font><br><br><h2>le but de  ce jeu est d'aider la jeune femme pour sortir du grid<br>* pour deplacer une voiture selectionner la avec la souris <br>puis utiliser les flèches(right-left-Down-Up)<br><br>si vous n'arriveZ pas à aider la femme dans une minute<br> vous allez perdu ");
    layout->addWidget(text,1,1,7,7);
    mon_guide->setLayout(layout);

    QPropertyAnimation *animation = new QPropertyAnimation(text, "geometry");

    animation->setDuration(5000);
    animation->setStartValue(QRect(400,0 , 0, 0));
    animation->setEndValue(QRect(430, 200,800 , 400));
    animation->start();
    mon_guide->show();

}

void Mafenetre::Jouer(){
    w->show();


}
void Mafenetre::A_propos(){
    A->show();

}
void Mafenetre::histo(){
    zonetext=new QTextEdit("historique");

    zonetext->setGeometry(100,100,1000,1000);
    zonetext->setStyleSheet("color :white;background-color:black;");


    QFile histo("C:/Users/LENOVO/Desktop/jeu-traffic/ressources/historique.txt");
    histo.open(QIODevice::ReadOnly);
    QString text;
    text=histo.readAll();
    histo.close();
    zonetext->setText("<h1><pre>  "+ text + " </h1>");
    Mafenetre *f=new Mafenetre;
    zonetext->addScrollBarWidget(f,Qt::AlignLeft);
    zonetext->show();
}




