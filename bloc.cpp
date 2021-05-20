#include "bloc.h"
#include <QPen>
#include <QKeyEvent>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPixmap>

//Bloc::Bloc():QGraphicsRectItem()
//{

//    x=0;y=0;w=0;h=0;
//    setRect(x,y,w,h);
//    setBrush(Qt::red);
//    setFlag(ItemIsMovable);
//    setFlag(ItemIsSelectable);

//}

Bloc::Bloc(int m,int n,int k,int r,int i ):QGraphicsPixmapItem()
{

        // QRect rect= QRect(m,n,k,r);
    x=m;
    y=n;
    w=k;
    h=r;
    id=i;
      if(i==0){
          bloc= QPixmap("C:/Users/LENOVO/Desktop/jeu-traffic/ressources/sp.webp");

      }

      else if(w>h){
          if(i%3==0) bloc= QPixmap("C:/Users/LENOVO/Desktop/jeu-traffic/ressources/rod.png");

          else if (i%4==0)  bloc= QPixmap("C:/Users/LENOVO/Desktop/jeu-traffic/ressources/bh.png");
          else if(i%2==0&&i%4!=0)  bloc= QPixmap("C:/Users/LENOVO/Desktop/jeu-traffic/ressources/h.webp");
          else if(i%7==0 )  bloc= QPixmap("C:/Users/LENOVO/Desktop/jeu-traffic/ressources/moins.jpg");
          else bloc= QPixmap("C:/Users/LENOVO/Desktop/jeu-traffic/ressources/bus.webp"); }

     else{

           if(i%4==0)  bloc= QPixmap("C:/Users/LENOVO/Desktop/jeu-traffic/ressources/car.webp");

           else if (i%4==1)  bloc= QPixmap("C:/Users/LENOVO/Desktop/jeu-traffic/ressources/v.png");
           else if(i%4==2)  bloc= QPixmap("C:/Users/LENOVO/Desktop/jeu-traffic/ressources/jv.webp");
           else  bloc= QPixmap("C:/Users/LENOVO/Desktop/jeu-traffic/ressources/vv.png");

}

        // setRect(rect);
       setOffset(x,y);
       setPixmap(bloc.scaled(k,r,Qt::IgnoreAspectRatio));
       setFlag(ItemIsMovable);
       setFlag(ItemIsSelectable);
       setFlag(ItemIsFocusable);

 }

void Bloc::setATTribut(int m,int n, int s,int r ){
    x=m;
    y=n;
    w=s;
    h=r;
}

void Bloc::advance(int phase)
{
    if(!phase)
        return;
    setPos(mapToParent(this->x,this->y));
    update();

}
