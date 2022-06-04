/**
 * \file     Joueur.cpp
 * \brief    Fichier de déclaration de la classe Joueur
 * \author   Arthur, Benaroch, Gueniot, Yvinec
 * \version  0.1
 * \date     20 Mai 2022
 *
 * Classe Joueur permettant de définir les méthode et variables d'un joueur à la bataille navale
 */
#include "Joueur.hpp"

/**
  * Définir la liste des coordonnées à partir du point arrière du bateau, de la taille et de son orientation
  */
vector<Coordonnee> Joueur::DefinirListeCoord(string nom, Coordonnee coord, bool orientation) {
    int taille =0;
    std::vector<Coordonnee> liste_coord;
    if(nom=="Porte-avion")
      taille = 5;
    else if(nom== "Croiseur") 
      taille = 4;
    else if(nom=="Contre-torpilleur")
      taille = 3;
    else if(nom=="Torpilleur")
      taille=2;
  
    if(orientation == true){
      for(int i =0; i < taille ; i++){
        liste_coord.push_back( Coordonnee(coord.GetX() , coord.GetY()+i ));
      }
    }
    else{
      for(int i =0; i < taille ; i++){
        liste_coord.push_back( Coordonnee(coord.GetX()+i , coord.GetY() ));
      }
    }
    return liste_coord;
}


/**
*  Récupérer l'état du joueur
*/
bool Joueur::JoueurVivant(){
  bool vivant = false;
  for(auto &it : liste_bateau){
    if(it.get_vie_bateau()==true) {
      vivant = true;
      /* On a pas besoin de continuer à boucler car on sait qu'il est vivant */
      break;
    }
  }
  return vivant;
}


/**
  * Vérifier les conflits entre les coordonnées en paramètre et les limites du plateau
  */
bool Joueur::VerifierConflitPlateau(vector<Coordonnee> coordonnees){
  if( (coordonnees[coordonnees.size()-1].GetY() > 10) || (coordonnees[coordonnees.size()-1].GetX() > 'J') ){
    if ( this->afficher_message == true ) {
      std::cout<<"Une partie du bateau est en dehors du jeu, changez vos coordonnees !"<<std::endl;
    }
    return true;
  }
  else {
    return false;
  }
}


/**
  * Vérifier les conflits entre les coordonnées et les autres bateaux du joueur
  */
bool Joueur::VerifierConflitBateaux(Coordonnee coord, bool is_in_config){
    for(auto &it : liste_bateau){
      if(it.verif_coord(coord)==true){
      		if ( is_in_config == true ){
            if ( this->afficher_message == true ) {
      			  std::cout<<"erreur : un bateau se trouve deja sur la coordonnee souhaitee. Choisissez-en une autre !"<<std::endl;
            }
      		}
        return true;
        }
    }
    return false;
  }


/**
  * Vérifier les conflits entre les coordonnées en paramètre et les autres bateaux du joueur
  */
bool Joueur::VerifierConflitBateaux(vector<Coordonnee> liste_coord){
    for(auto &bateau_it : liste_bateau){
        for(auto &coord_it : liste_coord){
            if(bateau_it.verif_coord(coord_it)==true){
              if ( this->afficher_message == true ) {
                std::cout<<"erreur : un bateau se trouve deja sur les coordonnees souhaitees pour votre bateau. Choisissez-en des autres !"<<std::endl;
              }
              return true;
            }
        }
    }
    return false;
}


/**
  * Vérifier si les coordonnées en paramètres sont dans la liste des tirs qui n'ont pa touchés de bateau
  */
bool Joueur::VerifierPionBlanc(Coordonnee coord){
    for(auto &it : liste_pion_blanc){
      if(it == coord)
        return true;
    }
    return false;
}


/**
  * Ajouter un pion blanc dans la liste et afficher que le tire est 'loupé'
  */
void Joueur::AjouterPionBlanc(Coordonnee &coord){
        liste_pion_blanc.push_back(coord);
        std::cout<<"Loupé !!!!"<<std::endl;
}


/**
  * Traiter l'attaque du joueur adverse
  */
bool Joueur::Attaquer(Coordonnee &coord){
  bool cible_toucher = false;
  for(auto &it : liste_bateau){
    if(it.get_vie_bateau() == true){//si bateau toujours en vie alors on regarde ses coordonnées
      if(it.set_tir_touche(coord)==true)
        cible_toucher = true;
    }
  }
  return cible_toucher;
}


/**
  * Récupérer la liste des impacts pour chaque bateau
  */
std::vector<Coordonnee> Joueur::GetListeCoordImpactBateau(){
  std::vector<Coordonnee> liste_impact_coord;
  for(auto &it : liste_bateau){
    for(auto &it_bateau : it.get_liste_impact_bateau()){
      liste_impact_coord.push_back(it_bateau);
    }
  }
  return liste_impact_coord;
}


/**
  * Permet de savoir si les coordonnées en paramètre correspondent à une case où le bateau est présent
  */
bool Joueur::GetImpactCoord(Coordonnee coord){
  std::vector<Coordonnee> liste = this->GetListeCoordImpactBateau();
  for(auto &it : liste){
    if(it == coord) {
      return true;
    }
  }
  return false;
}


/**
  * Vérifier que le bateau n'est pas adjacent à un autre bateau
  */
bool Joueur::VerifAdjacentBateau(std::vector<Coordonnee> coord){
  for(int i=0; i<coord.size(); i++){
    if(i==0){
      std::vector<Coordonnee> liste_coord_haut = {Coordonnee()};
    }
  }
}