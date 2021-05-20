#ifndef SCENE_H
#define SCENE_H

#include <QDialog>
#include <QPushButton>
#include <QVBoxLayout>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <bloc.h>
#include <QKeyEvent>
#include <QMediaPlayer>

namespace Ui {
class test;
}


class scene : public QGraphicsScene

{
    Q_OBJECT

public:
    explicit scene(QObject *parent = nullptr);

    ~scene();
    void charger_niveau(int **t,int n);
    void dessiner_scene(int n);
    int getbloc_num();
    virtual void keyPressEvent(QKeyEvent *event);
    bool mouv_h(Bloc *B);
    bool mouv_b(Bloc *B);
    bool mouv_D(Bloc *B);
    bool mouv_G(Bloc *B);
    void tracer_grid(int n);
    void  setNbr_deplacement(int n){
        nbr_deplacement=n;
    }
    int getNbr_deplacement(){
        return nbr_deplacement;
    }
    void setMov(bool b){
        mov=b;
    }
private slots:
    void  mouv();
   void jouerSonGagne();
    void jouerSonBloc();
signals:
    void gagne();
    void mov_effectuer(int n);
    void sonPlayer();
private:
    Ui::test *ui;
    QPixmap *p;
    QList<Bloc*> blocs;
    int **posblocs;
    int nb_bloc=0;
    Bloc* bloc_special;
    Bloc **tab_bloc;
    int nbr_deplacement=0;
    bool mov=false;
    QMediaPlayer * sonBloc = new QMediaPlayer;
     QMediaPlayer * sonGagne = new QMediaPlayer;
     int perte=0;
    //sonBloc->setMedia(QUrl("qrc:/son/block_dep.wav"));


};

#endif // SCENE_H
