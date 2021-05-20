#ifndef NIVEAU_H
#define NIVEAU_H


class mon_niveau
{
public:
    mon_niveau();
    void setNiveau(int i);
    int ** getNiveau();

    int getnb_bloc();
private:
    int **niv;
    int nb_bloc=1;
};

#endif // NIVEAU_H
