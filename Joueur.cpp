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
  * <li>Définition de la DefinirListeCoord
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


bool Joueur::JoueurVivant(){
  bool vivant = false;
  for(auto &it : liste_bateau){
    if(it.get_vie_bateau()==true)
      vivant = true;
  }
  return vivant;
}


bool Joueur::VerifierConflitPlateau(vector<Coordonnee> coordonnees){
  if( (coordonnees[coordonnees.size()-1].GetY() > 10) || (coordonnees[coordonnees.size()-1].GetX() > 'J') ){
    std::cout<<"Une partie du bateau est en dehors du jeu, changez vos coordonnees !"<<std::endl;
    return true;
  }
  else {
    return false;
  }
}

bool Joueur::VerifierConflitBateaux(Coordonnee coord, bool is_in_config){
    for(auto &it : liste_bateau){
      if(it.verif_coord(coord)==true){
      		if ( is_in_config == true ){
      			std::cout<<"erreur : un bateau se trouve deja sur la coordonnee souhaitee. Choisissez-en une autre !"<<std::endl;
      		}
        return true;
        }
    }
    return false;
  }


bool Joueur::VerifierConflitBateaux(vector<Coordonnee> liste_coord){
    for(auto &bateau_it : liste_bateau){
        for(auto &coord_it : liste_coord){
            if(bateau_it.verif_coord(coord_it)==true){
              std::cout<<"erreur : un bateau se trouve deja sur les coordonnees souhaitees pour votre bateau. Choisissez-en des autres !"<<std::endl;
              return true;
            }
        }
    }
    return false;
}


bool Joueur::VerifierPionBlanc(Coordonnee coord){
    for(auto &it : liste_pion_blanc){
      if(it == coord)
        return true;
    }
    return false;
}


void Joueur::AjouterPionBlanc(Coordonnee &coord){
        liste_pion_blanc.push_back(coord);
        std::cout<<"Loupé !!!!"<<std::endl;
}


bool Joueur::Attaquer(Coordonnee coord){
  bool cible_toucher = false;
  for(auto &it : liste_bateau){
    if(it.get_vie_bateau() == true){//si bateau toujours en vie alors on regarde ses coordonnées
      if(it.set_tir_touche(coord)==true)
        cible_toucher = true;
    }
  }
  return cible_toucher;
}

std::vector<Coordonnee> Joueur::GetListeCoordImpactBateau(){
  std::vector<Coordonnee> liste_impact_coord;
  for(auto &it : liste_bateau){
    for(auto &it_bateau : it.get_liste_impact_bateau()){
      liste_impact_coord.push_back(it_bateau);
    }
  }
  return liste_impact_coord;
}

bool Joueur::GetImpactCoord(Coordonnee coord){
  std::vector<Coordonnee> liste = this->GetListeCoordImpactBateau();
  for(auto &it : liste){
    if(it == coord)
      return true;
  }
  return false;
}
