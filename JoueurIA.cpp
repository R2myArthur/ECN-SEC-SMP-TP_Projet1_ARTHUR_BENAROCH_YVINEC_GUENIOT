/**
 * \file     JoueurIA.cpp
 * \brief    Fichier de déclaration de la classe JoueurIA
 * \author   Arthur, Benaroch, Gueniot, Yvinec
 * \version  0.1
 * \date     20 Mai 2022
 *
 * Classe Joueur permettant de définir les méthodes et variables d'un joueur IA à la bataille navale
 */
#include "JoueurIA.hpp"

/**
  * <li>Définition du construsteur de la classe Joueur
  */
JoueurIA::JoueurIA(e_level_IA_t level){
  Coordonnee coord;
  std::vector<Coordonnee> liste_coord;
  this->nom = "IA";
  this->difficulte_ia = level;
  this->afficher_message = false;
  bool orientation;
  
  /* Initialiser le random sur la base du temps */
  srand (time(NULL));

  // Parcourir le tableau de type de bateaux
  for(int i =0; i<5; i++){
    //on verifie qu'il n'y a pas de conflit avec d'autres bateaux deja placés
    do{
      //verifie en premier que les coordonnées ne depasse pas du jeu
      do{
        //on verifie que la coordonnee choisie n'est pas en conflit avec une deja occupée, si c'est le cas alors on reboucle sur la aprtie precedente jusqu'a en trouver une qui convient
        do{
          // Définir l'orientation
          orientation = rand()% 2;
          coord = coord.TirageAleatoireCoordonnee();
        }while( this->VerifierConflitBateaux(coord,true) ==true );
        //Grace a l'orientation, le type de bateau et la première coordonnee initialiser on genère les coordonées restantees qui composent le bateau
        liste_coord = this->DefinirListeCoord(tableau_bateau_const[i], coord, orientation);
        
      }while(this->VerifierConflitPlateau(liste_coord) == true);
      
    }while(this->VerifierConflitBateaux(liste_coord) == true);
    
    //tout est bon on ajoute alors le bateau construit a notre liste de bateau
    liste_bateau.push_back( Bateau(tableau_bateau_const[i],liste_coord,orientation) );
  }
  this->AfficherJoueur();
}

void JoueurIA::AfficherJoueur(){
  std::string current_case;
  
  std::cout<<"AFFICHAGE PLATEAU IA"<<std::endl;
  std::cout<<"   A B C D E F G H I J "<<std::endl;
  std::cout<<"  ╔═╦═╦═╦═╦═╦═╦═╦═╦═╦═╗"<<std::endl;
  for(int i=1; i< 11; i++){
    for(char c='A'; c<'K';c++){
      if(c == 'A'){
        if(i>9)
          std::cout<<i;
        else
          std::cout<<i<<" ";
        }
      std::cout<<"║";
      current_case = " ";
      if( this->VerifierConflitBateaux( Coordonnee(c,i), false ) == true )
        current_case = "X";
      if(this->GetImpactCoord( Coordonnee(c,i) )==true){
        current_case = "X";
        std::cout << "\033[31Em";
        }
      std::cout<<current_case;
    }
    std::cout<<"║"<<std::endl;
    if(i!=10)
      std::cout<<"  ╠═╬═╬═╬═╬═╬═╬═╬═╬═╬═╣"<<std::endl;

  }
  std::cout<<"  ╚═╩═╩═╩═╩═╩═╩═╩═╩═╩═╝"<<std::endl;
}


e_level_IA_t JoueurIA::GetDifficulte() {
  return this->difficulte_ia;
}

bool JoueurIA::VerifierConflitPlateauAttaque(Coordonnee coordonnees){
  if( (coordonnees.GetY() < 1)   || (coordonnees.GetY() > 10) || 
      (coordonnees.GetX() < 'A') || (coordonnees.GetX() > 'J') ){
    return true;
  }
  else {
    return false;
  }
}
