#include "Afficher.hpp"

int main(){
  Joueur j1("Coco"), j2("Dodo");
  Afficher plateau;
  bool tour = false; //false = J1 de jouer ; True= J2 de jouer
  do{
    if(tour == false){
      plateau.deroulement_joueur(j1,j2);
      tour = true;
    }
    else{
      plateau.deroulement_joueur(j2,j1);
      tour = false;
    }
  }while( (j1.JoueurVivant()==true) && (j2.JoueurVivant()==true) );
  (j1.JoueurVivant()==true) ? std::cout<<"Joueur 1 gagne !"<<std::endl : std::cout<<"Joueur 2 gagne !"<<std::endl;
  return 0;
}