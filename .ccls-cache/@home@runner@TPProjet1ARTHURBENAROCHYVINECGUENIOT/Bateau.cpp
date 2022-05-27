#include "Bateau.hpp"
//en vie =1 ; touché =0

Bateau::Bateau(std::string nom, std::vector<Coordonnee> &liste_coord, bool orientation){
  
  if(nom=="Porte-avion")
    this->taille = 5;
  else if(nom== "Croiseur") 
    this->taille = 4;
  else if(nom=="Contre-torpilleur")
    this->taille = 3;
  else if(nom=="Torpilleur")
    this->taille=2;
  
  this->nom = nom;
  this->orientation = orientation;
  this->en_vie = true;
  for(int i =0; i<liste_coord.size(); i++){
    this->liste_coord_vie_bateau[i].first = true;
    this->liste_coord_vie_bateau[i].second = liste_coord[i];
  }
}