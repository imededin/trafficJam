#include "guide.h"
#include<QLabel>
#include<QGridLayout>
#include<QPixmap>
#include<QTextEdit>

guide::guide()
{
    bg = new QLabel(this);
    p=new QPixmap("C:/Users/LENOVO/Desktop/jeu-traffic/ressources/guide_bg.png");
    bg->setPixmap(QPixmap(p->scaled(1200,1000,Qt::IgnoreAspectRatio)));
    layout=new QGridLayout;
      layout->addWidget(bg,0,0,9,9);



}
