#include "scene.h"
#include "mainwindow.h"
#include <QPen>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
using namespace std;

scene::scene(QObject *parent) :
    QGraphicsScene(parent)
{

       //this->setBackgroundBrush(Qt::blue);
    //QPixmap image= QPixmap("C:/Users/LENOVO/Desktop/rue.jfif");
   // addPixmap(image.scaled(800,800,Qt::IgnoreAspectRatio));
       //this->setForegroundBrush(QColor(0, 0, 250, 100));
    sonBloc->setMedia(QUrl("c:/users/lenovo/desktop/jeu-traffic/ressources/block_dep.mp3"));
    sonGagne->setMedia(QUrl("c:/users/lenovo/desktop/jeu-traffic/ressources/applause.wav"));

    QPixmap imag= QPixmap("C:/Users/LENOVO/Desktop/jeu-traffic/ressources/bg.png");
    addPixmap(imag.scaled(1400,800,Qt::IgnoreAspectRatio));


connect(this,SIGNAL(sonPlayer()),this,SLOT(jouerSonBloc()));
connect(this,SIGNAL(gagne()),this,SLOT(jouerSonGagne()));
}

scene::~scene()
{
    //delete ui;
}
void scene::charger_niveau(int **t,int n){
    nb_bloc=n;
    tab_bloc=new Bloc*[n];
    posblocs= new int*[n];
    for(int i=0;i<n;i++){
        posblocs[i]=new int[4];
        for(int j=0;j<4;j++){
            posblocs[i][j]=*(t[i]+j);
        }
  }


}
void scene::dessiner_scene(int n){
    tab_bloc[0]=new Bloc(posblocs[0][0]*80+280,posblocs[0][1]*80+80,posblocs[0][2]*80,posblocs[0][3]*80,0);

    tab_bloc[0]->setFocus();
    this->addItem(tab_bloc[0]);
   for(int i=1;i<n;i++){
       tab_bloc[i]=new Bloc(posblocs[i][0]*80+280,posblocs[i][1]*80+80,posblocs[i][2]*80,posblocs[i][3]*80,i);
       //tab_bloc[i]->setATTribut(posblocs[i][0]*80,posblocs[i][1]*80,posblocs[i][2]*80,posblocs[i][3]*80);

        tab_bloc[i]->setFocus();
        this->addItem(tab_bloc[i]);

        }


}
int scene::getbloc_num(){
    return(nb_bloc);

}
void  scene::mouv(){
    mov=true;

}


   void scene::tracer_grid(int n){
      // this->setBackgroundBrush(Qt::blue);


       QPixmap image= QPixmap("C:/Users/LENOVO/Desktop/jeu-traffic/ressources/bg.png");
       addPixmap(image.scaled(1400,800,Qt::IgnoreAspectRatio));

      for(int i=0;i<n+2;i++){
           addLine(280,i*80,280+(n*80),i*80,QPen(Qt::blue,Qt::PenStyle(),Qt::SolidLine));
       addLine(i*80+280,80,i*80+280,80+(n*80),QPen(Qt::blue));
   }
      this->addRect(n*80+280,240,160,80,QPen(Qt::red),QBrush(Qt::white));

   }
Bloc *bloc;
   void scene::keyPressEvent(QKeyEvent *event){

       for(int i=0;i<nb_bloc;i++ ){

               if(tab_bloc[i]->isSelected()){
                   bloc=tab_bloc[i];
                   break;

              }

          }
           switch(event->key()){
       case Qt::Key_Right:{
               if(mov&&mouv_D(bloc)){
                   if(((bloc->getX()+bloc->getW())<480+280)){
                   bloc->moveBy(80,0);
                   perte+=(bloc->getId())*2;
                   bloc->x+=80;
                    nbr_deplacement++;
                  emit mov_effectuer( nbr_deplacement);
                    emit sonPlayer();
                   }
                   else if(bloc->getX()<480+280&&bloc->getId()==0){
                       bloc->moveBy(80,0);
                       bloc->x+=80;
                        nbr_deplacement++;
                       emit mov_effectuer( nbr_deplacement);
                        emit sonPlayer();
                    if(bloc->getX()==480+280&&bloc->getId()==0){
                        bloc->moveBy(80,0);

                        bloc->x+=80;
                        emit sonPlayer();
                        emit gagne();

                   }}}


               break;
           }
       case Qt::Key_Left:{
                  if(mov&&mouv_G(bloc)&&(bloc->getX()>280)&&bloc->getX()<480+280){
                       bloc->moveBy(-80,0);
                       bloc->x-=80;
                        nbr_deplacement++;
                       emit mov_effectuer( nbr_deplacement);
                        emit sonPlayer();
                 }
                  break;
           }
           case Qt::Key_Up:{
                      if(mov&&mouv_h(bloc)&&(bloc->getY()>80)){
                           bloc->moveBy(0,-80);
                           bloc->y-=80;
                            nbr_deplacement++;
                           emit mov_effectuer( nbr_deplacement);
                            emit sonPlayer();
                     }
                      break;
               }

           case Qt::Key_Down:{
                      if(mov&&mouv_b(bloc)&&((bloc->getY()+bloc->getH())<480+80)){
                           bloc->moveBy(0,80);
                           bloc->y+=80;
                            nbr_deplacement++;
                           emit mov_effectuer( nbr_deplacement);
                            emit sonPlayer();
                     }
                      break;
               }

   }
           update();
   }
   bool scene::mouv_D(Bloc *bloc){
       bool test_d=true;
       for (int i=0;i<nb_bloc;i++){
           if(tab_bloc[i]!=bloc&&((bloc->getX()+bloc->getW())==tab_bloc[i]->getX())&&((bloc->getY()==tab_bloc[i]->getY())||((bloc->getY()>=tab_bloc[i]->getY())&&(bloc->getY()<(tab_bloc[i]->getY()+tab_bloc[i]->getH())))||((bloc->getY()<=tab_bloc[i]->getY())&&(bloc->getY()+bloc->getH()>(tab_bloc[i]->getY()))))){
               test_d=false;
               break;
           }
       }
       return test_d;
   }
   bool scene::mouv_G(Bloc *bloc){
       bool test_g=true;
       for (int i=0;i<nb_bloc;i++){
           if(tab_bloc[i]!=bloc&&((bloc->getX())==tab_bloc[i]->getX()+tab_bloc[i]->getW())&&((bloc->getY()==tab_bloc[i]->getY())||((bloc->getY()>=tab_bloc[i]->getY())&&(bloc->getY()<(tab_bloc[i]->getY()+tab_bloc[i]->getH())))||((bloc->getY()<=tab_bloc[i]->getY())&&(bloc->getY()+bloc->getH())>(tab_bloc[i]->getY())))){
               test_g=false;
               break;
           }
       }
       return test_g;
   }
   bool scene::mouv_h(Bloc *bloc){
       bool test_h=true;
       for (int i=0;i<nb_bloc;i++){
           if(tab_bloc[i]!=bloc&&((bloc->getY())==(tab_bloc[i]->getY()+tab_bloc[i]->getH()))&&((bloc->getX()==tab_bloc[i]->getX())||((bloc->getX()>=tab_bloc[i]->getX())&&(bloc->getX()<(tab_bloc[i]->getX()+tab_bloc[i]->getW())))||((bloc->getX()<=tab_bloc[i]->getX())&&((bloc->getX()+bloc->getW())>(tab_bloc[i]->getX()))))){
               test_h=false;
               break;
           }
       }
       return test_h;
   }
   bool scene::mouv_b(Bloc *bloc){
       bool test_b=true;
       for (int i=0;i<nb_bloc;i++){
           if(tab_bloc[i]!=bloc&&((bloc->getY()+bloc->getH())==tab_bloc[i]->getY())&&((bloc->getX()==tab_bloc[i]->getX())||((bloc->getX()>=tab_bloc[i]->getX())&&(bloc->getX()<(tab_bloc[i]->getX()+tab_bloc[i]->getW())))||((bloc->getX()<=tab_bloc[i]->getX())&&(bloc->getX()+bloc->getW()>(tab_bloc[i]->getX()))))){
               test_b=false;
               break;
           }
       }
       return test_b;
   }

   void scene::jouerSonGagne()
   {
       if(sonGagne->state() == QMediaPlayer::PlayingState){
           sonGagne->setPosition(0);
       }else if (sonGagne->state() == QMediaPlayer::StoppedState){
          sonGagne->play();
       }
   }

   void scene::jouerSonBloc(){
       if(sonBloc->state() == QMediaPlayer::PlayingState){
           sonBloc->setPosition(0);
       }else if (sonBloc->state() == QMediaPlayer::StoppedState){
           sonBloc->play();
       }
   }
