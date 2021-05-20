#ifndef GUIDE_H
#define GUIDE_H

#include <QWidget>

#include<QLabel>
#include<QGridLayout>
#include<QPixmap>
#include<QTextEdit>

class guide : public QWidget
{
public:
     guide();

//signals:
private:
    QLabel*bg;
    QPixmap *p;
    QTextEdit text;
    QGridLayout *layout;

};

#endif // GUIDE_H
