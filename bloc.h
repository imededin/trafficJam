#ifndef BLOC_H
#define BLOC_H

#include <QGraphicsRectItem>
#include <QPainter>
#include <QPaintEvent>

class Bloc : public QGraphicsPixmapItem
{
public:
    Bloc(int x,int y,int w,int h,int i=0);
    //QRectF rect();
    //void paint(QPainter* panter,QStyleOptionGraphicsItem *option,QWidget *parent);
    void setATTribut(int x,int y,int w,int h);
    int getX(){
        return x;
    }
    int getY(){
        return y;
    }
    int getW(){
        return w;
    }
    int getH(){
        return h;
    }
    QPixmap getQPixmap(){
        return(bloc);
    }
    int getId(){
        return id;
    }

  public:

   // virtual void keyPressEvent(QKeyEvent *event);
    virtual void advance(int phase);
   protected:
public:
  int x=80;
  int y=0;
  int w=160;
  int h=80;
  int id;
  QPixmap bloc;
};

#endif // BLOC_H
