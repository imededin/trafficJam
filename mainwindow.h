#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVBoxLayout>
#include <QPushButton>
#include "scene.h"
#include <QGridLayout>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMenuBar>
#include "mon_niveau.h"
#include <QTimer>
#include <QLabel>
#include <QSlider>
#include <QLCDNumber>
#include <QPixmap>
#include <QPropertyAnimation>
#include <QProgressBar>
using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
     int calculer_score(int n,int m,int ss);
     void sauvegarder_resultat();

private slots:
   //S void on_pushButton_clicked();
    void choisir_Niveau1();
    void choisir_Niveau2();
    void choisir_Niveau3();
    void commencer_jeu();
    void felicitation();
    void compteur_change();
    void activer_chrono();
    void perdu();
    void inscrire();
    void reinitialiser();
    void pause();
    void next();
    void replay();

signals:
    void mouv_autorise();
    void loser();

private:
    //Ui::MainWindow *ui;
    int **t=new int*;


    QGridLayout *layout;
    QPushButton *start;
    QPushButton *paus;
    QPushButton *reinitial;
    scene *scen;
    QGraphicsView *view;
    QMenu *niveau;
    QTimer *time;
    QLabel *compteur;
    mon_niveau *niv;
    QLabel *label=new QLabel;

     QPushButton *suivant=new QPushButton;
     QPushButton *rejouer=new QPushButton("Replay");
     QLabel *scor=new QLabel();
      QPropertyAnimation *animation = new QPropertyAnimation(label, "geometry");
    QWidget *containeur;
    QLCDNumber *affich_mouv_nbr;
     QLCDNumber *affich_niveau_act;
     QProgressBar *temps_restant;
    int ss=0,mm=0;//pour le compteur
    int niveau_courant=0;
    bool dessiner=false;
    bool lancer=false;
    bool charger=false;
    QString pseudo;
    int score=0;
    bool ok=false;
    bool arreter=false;



};
#endif // MAINWINDOW_H
