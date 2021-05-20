#include <QGraphicsScene>
#include <QApplication>
#include <QPushButton>
#include <QFont>
#include <QLCDNumber>
#include "mainwindow.h"
#include "mafenetre.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Mafenetre *f=new Mafenetre;
    f->setStyleSheet("background-color:lightGray; color:white;font: bold 25px;QPushButton{background-color:white}");
    qApp->setStyleSheet("QPushButton{ background-color: dimGray;color:white;border-style: outset;border-width: 2px; border-radius: 10px; border-color: beige;font: bold 20px;min-width: 10em;padding: 6px;}");
    f->setGeometry(400,100,400,400);
    f->show();
    return a.exec();

}
