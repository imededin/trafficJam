#ifndef DEF_MAFENETRE
#define DEF_MAFENETRE

#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QMessageBox>
#include <QInputDialog>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QString>
#include "mainwindow.h"
#include "apropos.h"
#include<QTextEdit>
#include<QFile>


class Mafenetre : public QWidget
{
    Q_OBJECT
    public:
    Mafenetre();
    public
    slots:
    //void changerLargeur(int largeur);
    void ouvrirDialogue();
    void Jouer();
    void A_propos();
    void histo();

signals:
    private:
    QPushButton *btn;
    QVBoxLayout *layout;
    QPushButton *guide;
    QPushButton *historique;
    QPushButton *quitter;
     MainWindow* w;
     apropos *A;
     QTextEdit *zonetext;
};

#endif
