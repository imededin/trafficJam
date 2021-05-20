#include "apropos.h"

apropos::apropos()
{
    setStyleSheet("color:white;background-color:transparent");
    setWindowTitle("a propos");
    setFixedSize(1200,1200);
        text=new QLabel;
        text->setText("<pre><p align=center><h1><font size=100 color=white><font size=100 color=gold><strong><b> Traffic Jam</b></strong></font><br><br>traffic jam est un jeu de case tete trés connue. <br><br>    elle est amusant et enrichissante </h1>");
        text1=new QLabel;
        text1->setText("<h1><font color=gold size=100>ce projet est realise par :</h1>");
        layout=new QGridLayout;
        QLabel *imag1 = new QLabel;
         QPixmap *p=new QPixmap("C:/Users/LENOVO/Desktop/projet POO/imed.png");
        imag1->setPixmap(p->scaled(180,180,Qt::IgnoreAspectRatio));

        QLabel *imag2 = new QLabel;
        QPixmap *p1=new QPixmap("C:/Users/LENOVO/Desktop/projet POO/load.jfif");
        imag2->setPixmap(p1->scaled(180,180,Qt::KeepAspectRatio));
        QLabel *imag3 = new QLabel;
        QPixmap *p2=new QPixmap("C:/Users/LENOVO/Desktop/projet POO/load.jfif");
        imag3->setPixmap(p2->scaled(180,180,Qt::KeepAspectRatio));
        nom1=new QLabel;
        nom1->setText("<h1>Imed Eddin ATI </h3>");
        nom2=new QLabel;
        nom2->setText("<h1>achref Abidi </h3>");
        nom3=new QLabel;
        nom3->setText("<h1>Med Ali Mezghani </h3>");

          QLabel *image = new QLabel(this);
          QPixmap *p0=new QPixmap("C:/Users/LENOVO/Desktop/jeu-traffic/ressources/apropos_bg.png");
          image->setPixmap(QPixmap(p0->scaled(1200,1000,Qt::IgnoreAspectRatio)));
        layout->addWidget(image,0,0,9,9);
          layout->addWidget(text,0,1,3,9);
          layout->addWidget(text1,3,3,2,5);
          layout->addWidget(imag1,5,2,2,2);
          layout->addWidget(imag2,5,4,2,2);
          layout->addWidget(imag3,5,6,2,2);
          layout->addWidget(nom1,6,2,2,2);
          layout->addWidget(nom2,6,4,2,2);
          layout->addWidget(nom3,6,6,2,2);

          setLayout(layout);
}
