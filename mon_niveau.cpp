#include "mon_niveau.h"
#include <fstream>
#include <string>
#include <iostream>
#include <string.h>
using namespace std;

mon_niveau::mon_niveau()
{
niv =new int*[nb_bloc];
}
void mon_niveau::setNiveau(int i){
    string fichier;
   if(i==1){
   fichier="C:/Users/LENOVO/Desktop/jeu-traffic/ressources/niveau1.txt" ;}
   else if(i==2){
  fichier="C:/Users/LENOVO/Desktop/jeu-traffic/ressources/niveau2.txt";}
  else{  fichier="C:/Users/LENOVO/Desktop/jeu-traffic/ressources/niveau3.txt";}


    ifstream mon_niveau(fichier.c_str());
    if(mon_niveau){


    mon_niveau >>nb_bloc;
    niv=new int*[nb_bloc];
    for(int i=0;i<nb_bloc;i++){
        niv[i]=new int[4];
            mon_niveau>>niv[i][0];
            mon_niveau>>niv[i][1];
            mon_niveau>>niv[i][2];
            mon_niveau>>niv[i][3];

    }



    }
    else{
        cout<<"impossible d'ouvrire la fichier";
    }

}

int mon_niveau::getnb_bloc(){
    return nb_bloc;
}
int** mon_niveau::getNiveau(){
    return niv;
                             }
