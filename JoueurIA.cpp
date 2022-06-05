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
  * Définition du construsteur de la classe Joueur
  *
  * \param level Niveau de difficulté souhaité
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
          coord.TirageAleatoireCoordonnee();
        }while( this->VerifierConflitBateaux(coord,true) ==true );
        //Grace a l'orientation, le type de bateau et la première coordonnee initialiser on genère les coordonées restantees qui composent le bateau
        liste_coord = this->DefinirListeCoord(tableau_bateau_const[i], coord, orientation);
        
      }while(this->VerifierConflitPlateau(liste_coord) == true);
      
    }while(this->VerifierConflitBateaux(liste_coord) == true || this->VerifAdjacentBateauConflit(liste_coord,orientation)==true);
    
    //tout est bon on ajoute alors le bateau construit a notre liste de bateau
    liste_bateau.push_back( Bateau(tableau_bateau_const[i],liste_coord,orientation) );
  }
  // Affichage des bateaux de l'IA pour le DEBUG
  // this->AfficherJoueur();
}

/**
*  Afficher la table du jeu à l'utilisateur de l'IA pour le DEBUG SEULEMENT
*/  
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


/**
*  Getter de la variable de difficulté de l'IA
*/
e_level_IA_t JoueurIA::GetDifficulte() {
  return this->difficulte_ia;
}

/**
*  Vérifier que les coordonnées en paramètre sont bien dans la plage de jeu du plateau
*/  
bool JoueurIA::VerifierConflitPlateauAttaque(Coordonnee coordonnees){
  /** Vérifier sur l'axe des abscisse et des ordonnées*/
  if( (coordonnees.GetY() < 1)   || (coordonnees.GetY() > 10) || 
      (coordonnees.GetX() < 'A') || (coordonnees.GetX() > 'J') ){
    return true;
  }
  else {
    return false;
  }
}

Coordonnee JoueurIA::RenseignerCoordonnee(){
  Coordonnee coord;
  coord.TirageAleatoireCoordonnee();
  return coord;
}

void JoueurIA::GestionCoordonneeAttaque(JoueurReel &adversaire, Coordonnee &coord) {
  bool condition_rebouclage = false;
  
  /** Stratégie en fonction de la difficulté */
  switch ( this->GetDifficulte() ) {
    /** IA SIMPLE : Tirage aléatoire sur toute la partie */
    case FACILE: { 
      do {
        condition_rebouclage = false;
        coord.TirageAleatoireCoordonnee();
        if ( (adversaire.GetImpactCoord(coord) == true) || (this->VerifierPionBlanc(coord) == true) ) {
          condition_rebouclage = true;
        }
      } while ( condition_rebouclage == true );
      break;
    }
    /** IA MOYENNE :
    * 1 - Tire aléatoire jusqu'à toucher un bateau
    * 2 - Tirer sur les case adjacentes dans les prochains tours (x+1, x-1, y+1, y-1) Vérifier que les cases soient dans le plateau et pas encore jouée ne coule pas forcément le bateau
    */
    case MOYEN: {
      /** SI table a tirer est vide ALORS Tirage aléatoire */
      /** SINON tirer les coordonnées du tableau #coordonnees_a_tirer
      */
      for(auto &it : this->coordonnees_a_tirer){
      }
      /** La liste peut contenir des éléments si un l'IA a touché un bateau au tour précédent */
      if ( this->coordonnees_a_tirer.empty() == true ){
        do {
          // Remettre la condition de rebouclage a faux pour éviter de boucler indéfiniment
          condition_rebouclage = false;
          // Choisir un point aléatoirement du plateau
          coord.TirageAleatoireCoordonnee();
          if ( (adversaire.GetImpactCoord(coord) == true) || (this->VerifierPionBlanc(coord) == true) ) {
            condition_rebouclage = true;
          }
        } while ( condition_rebouclage == true );
      }
      else {
        /** récupérer la valeur à tirer en commencant par la dernière rentrée */
        coord = this->coordonnees_a_tirer.back();
        /** Supprimer le dernier élément du tableau */
        this->coordonnees_a_tirer.pop_back();
      }
      break;
    }
    
    /** IA DIFFICILE :
    * 1 - Tire aléatoire jusqu'à toucher un bateau
    * 2 - Tirer sur les case adjacentes dans les prochains tours (x+1, x-1, y+1, y-1) jusqu'à couler le bateau
    *  Pas encore définis
    */
    case DIFFICILE:{
      // TBD
      break;
    }
    default : {
      break;
    }
  }
}

void JoueurIA::GestionAttaqueTouchee(JoueurReel &adversaire, Coordonnee &coord) {
  Coordonnee coord_future;
  /** On réinitialise le tableau d'attaque future */
  this->coordonnees_a_tirer.erase(this->coordonnees_a_tirer.begin(), this->coordonnees_a_tirer.end());
  
  /** Check des 4 case autour, pour chaque case adjacente (x+1, x-1, y+1, y-1) :
  *  - Vérifier que les coordonnées sont dans le plateau
  *  - Vérifier que la case n'a pas encore été jouée (tir raté et tir touché)
  *  Si les vérifications sont OK alors ajouter la case dans une liste de coordonnées à tirer
  */
  for (int i = 0 ; i < 4 ; i++) {
    switch( i ) {
      case 0: {
        coord_future.SetX(coord.GetX() + 1);
        coord_future.SetY(coord.GetY());
        break;
      }
      case 1: {
        coord_future.SetX(coord.GetX() - 1);
        coord_future.SetY(coord.GetY());
        break;
      }
      case 2: {
        coord_future.SetX(coord.GetX());
        coord_future.SetY(coord.GetY() + 1);
        break;
      }
      case 3: {
        coord_future.SetX(coord.GetX());
        coord_future.SetY(coord.GetY() - 1);
        break;
      }
      default : {
        break;
      }
    } 
    /** Si case non déja jouée par le joueur ET dans le plateau, Ce sera une case à attaquer ensuite */
    if ( (this->VerifierConflitPlateauAttaque(coord_future) == false) 
              && (adversaire.GetImpactCoord(coord_future) == false) 
              && (this->VerifierPionBlanc(coord_future) == false) ) {
      this->coordonnees_a_tirer.push_back(coord_future);
    }
  }
}