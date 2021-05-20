#ifndef APROPOS_H
#define APROPOS_H

#include <QObject>
#include <QWidget>
#include <QLabel>
#include<QGridLayout>
#include <QPixmap>
#include <QTextEdit>

class apropos :public QWidget
{
public:
    apropos();
private:
    QLabel* text;
    QLabel* text1;
    QLabel *imag1;
    QLabel*imag2;
    QLabel *imag3;

    QLabel *nom1;
    QLabel *nom2;
    QLabel *nom3;
    QGridLayout *layout;
    QPixmap *p;
     QPixmap *p1;
      QPixmap *p2;


};

#endif // APROPOS_H
