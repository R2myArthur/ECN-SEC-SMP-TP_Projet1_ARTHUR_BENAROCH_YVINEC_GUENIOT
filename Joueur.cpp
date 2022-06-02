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
#include "Afficher.hpp"

/**
  * <li>Définition du construsteur de la classe Joueur
  */
Joueur::Joueur(std::string nom, bool _is_a_bot){
    Coordonnee coord;
    Afficher affichage_bateau;
    std::vector<Coordonnee> liste_coord;
    this->nom = nom;
    this->is_a_bot = _is_a_bot;
    std::string coord_abs, orientation_nonconvertie;
    int coord_ord;
    bool orientation;

    if ( this->is_a_bot == true ) {
      /* Initialiser le random sur la base du temps */
      srand (time(NULL));
    }
  
    //on parcourt le tableau de type de bateau soit 5 bateaux
    for(int i =0; i<5; i++){
      //on affiche la map joueur
      this->AfficherJoueur();
      //on verifie qu'il n'y a pas de conflit avec d'autres bateaux deja placés
      do{
        //verifie en premier que les coordonnées ne depasse pas du jeu
        do{
          //on verifie que la coordonnee choisie n'est pas en conflit avec une deja occupée, si c'est le cas alors on reboucle sur la aprtie precedente jusqu'a en trouver une qui convient
          do{
            // Définir l'orientation
            do{
              if ( this->is_a_bot == true){
                string orient[2] = {"0", "1"};
                orientation_nonconvertie = orient[rand()% 2];
              } else {
                std::cout<<this->GetNom()<<" choisi l'orientation (1 = vertical, 0= horizontal) du bateau "<< tableau_bateau_const[i] <<" :"<<std::endl;
                std::cin>> orientation_nonconvertie;
              }
            }while( (orientation_nonconvertie != "0") && (orientation_nonconvertie !="1") );
            (orientation_nonconvertie[0]=='0') ? orientation = 0 : orientation =1;
            if ( this->is_a_bot == false){
              affichage_bateau.affichage_bateau_selection(orientation,tableau_bateau_const[i]);
            }
            coord = this->RenseignerCoordonnee();
            
          }while( this->VerifierConflitBateaux(coord,true) ==true );
          
          //Grace a l'orientation, le type de bateau et la première coordonnee initialiser on genère les coordonées restantees qui composent le bateau
          liste_coord = this->DefinirListeCoord(tableau_bateau_const[i], coord,orientation);
          
        }while(this->VerifierConflitPlateau(liste_coord) == true);
        
      }while(this->VerifierConflitBateaux(liste_coord) == true);
      
      //tout est bon on ajoute alors le bateau construit a notre liste de bateau
      liste_bateau.push_back( Bateau(tableau_bateau_const[i],liste_coord,orientation) );
    }
}

/*******************************************************
** SERT UNIQUEMENT POUR FAIRE DU DEBUG
********************************************************/
Joueur::Joueur(){
    Coordonnee coord;
    Afficher affichage_bateau;
    std::vector<Coordonnee> liste_coord;
    this->nom = "test";
    this->is_a_bot = true;
    std::string coord_abs, orientation_nonconvertie;
    int coord_ord;
    bool orientation;

    if ( this->is_a_bot == true ) {
      /* Initialiser le random sur la base du temps */
      srand (time(NULL));
    }
  
    //on parcourt le tableau de type de bateau soit 5 bateaux
    for(int i =0; i<5; i++){
      //on verifie qu'il n'y a pas de conflit avec d'autres bateaux deja placés
      do{
        //verifie en premier que les coordonnées ne depasse pas du jeu
        do{
          //on verifie que la coordonnee choisie n'est pas en conflit avec une deja occupée, si c'est le cas alors on reboucle sur la aprtie precedente jusqu'a en trouver une qui convient
          do{
            // Définir l'orientation
            do{
              string orient[2] = {"0", "1"};
              orientation_nonconvertie = orient[rand()% 2];
            }while( (orientation_nonconvertie != "0") && (orientation_nonconvertie !="1") );
            (orientation_nonconvertie[0]=='0') ? orientation = 0 : orientation =1;
            coord = this->RenseignerCoordonnee();
          }while( this->VerifierConflitBateaux(coord,true) ==true );
          
          //Grace a l'orientation, le type de bateau et la première coordonnee initialisée on genère les coordonées restantees qui composent le bateau
          liste_coord = this->DefinirListeCoord(tableau_bateau_const[i], coord,orientation);
          
        }while(this->VerifierConflitPlateau(liste_coord) == true);
        
      }while(this->VerifierConflitBateaux(liste_coord) == true);
      
      //tout est bon on ajoute alors le bateau construit a notre liste de bateau
      liste_bateau.push_back( Bateau(tableau_bateau_const[i],liste_coord,orientation) );
    }
    //on affiche la map joueur
    // this->AfficherJoueur();
    this->is_a_bot = false;
}


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


Coordonnee Joueur::RenseignerCoordonnee(){
  string coord_abs;
  int    coord_ord;
  
  if (this->is_a_bot == true) {
    coord_abs[0] = TAB_ABSCISSE[rand()% TAILLE_PLATEAU];
    coord_ord    = TAB_ORDONNEE[rand()% TAILLE_PLATEAU];
  } else {
    do{
      cout<< "Choisi la première coordonnée (abscisse de A à J)"<<endl;
      cin>> coord_abs;
    }while( (coord_abs[0]<'A' || coord_abs[0]>'J') || coord_abs.length()>1 );
  
    //blindage pour éviter saisie d'une valeur en dehors de l'intervalle
    do{
      cout<< "Choisi la première coordonnée (ordonnee de 1 à 10) "<<endl;
      cin>> coord_ord;
    }while(coord_ord <1 || coord_ord>10);
  }
  return Coordonnee(coord_abs[0],coord_ord);
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


void Joueur::AfficherJoueur(){
  std::string current_case;
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

