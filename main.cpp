#include "Afficher.hpp"

/** Fonction d'entrée du code*/
int main(){
  Afficher plateau;
  std::cout<<" Bienvenue dans le jeu de la bataille navale"          <<std::endl;
  
  /** lancer le jeu */
  plateau.SelectionMenu();     
  
  return 0;
}