/**
 * \file     Joueur.cpp
 * \brief    Fichier de déclaration de la classe Joueur
 * \author   Arthur, Benaroch, Gueniot, Yvinec
 * \version  0.1
 * \date     20 Mai 2022
 *
 * Classe Joueur permettant de définir les méthode et variables d'un joueur à la bataille navale
 */

#include "JoueurReel.hpp"
#include "Afficher.hpp"

/**
  * Définition du construsteur de la classe Joueur
  */
JoueurReel::JoueurReel(std::string nom){
    Coordonnee coord;
    Afficher affichage_bateau;
    std::vector<Coordonnee> liste_coord;
    this->nom = nom;
    this->afficher_message = true;
    std::string coord_abs, orientation_nonconvertie;
    int coord_ord;
    bool orientation;
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
              std::cout<<this->GetNom()<<" choisi l'orientation (1 = vertical, 0= horizontal) du bateau "<< tableau_bateau_const[i] <<" :"<<std::endl;
              std::cin>> orientation_nonconvertie;
            }while( (orientation_nonconvertie != "0") && (orientation_nonconvertie !="1") );
            (orientation_nonconvertie[0]=='0') ? orientation = 0 : orientation =1;
            affichage_bateau.affichage_bateau_selection(orientation,tableau_bateau_const[i]);
            coord = this->RenseignerCoordonnee();
            
          }while( this->VerifierConflitBateaux(coord,true) ==true );
          
          //Grace a l'orientation, le type de bateau et la première coordonnee initialiser on genère les coordonées restantees qui composent le bateau
          liste_coord = this->DefinirListeCoord(tableau_bateau_const[i], coord,orientation);
          
        }while(this->VerifierConflitPlateau(liste_coord) == true);
        
      }while(this->VerifierConflitBateaux(liste_coord) == true || this->VerifAdjacentBateauConflit(liste_coord,orientation)==true);
      
      //tout est bon on ajoute alors le bateau construit a notre liste de bateau
      liste_bateau.push_back( Bateau(tableau_bateau_const[i],liste_coord,orientation) );
    }
}

/**
  * Définition du construsteur de la classe Joueur avec création des bateau auto
  */
JoueurReel::JoueurReel(){
  Coordonnee coord;
  std::vector<Coordonnee> liste_coord;
  this->nom = "Test";
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
      
    }while(this->VerifierConflitBateaux(liste_coord) == true|| this->VerifAdjacentBateauConflit(liste_coord,orientation)==true);
    
    //tout est bon on ajoute alors le bateau construit a notre liste de bateau
    liste_bateau.push_back( Bateau(tableau_bateau_const[i],liste_coord,orientation) );
  }
  this->afficher_message = true;
}

/**
  * Définition de la DefinirListeCoord
  */

Coordonnee JoueurReel::RenseignerCoordonnee(){
    string coord_abs;
    int coord_ord;
  
    /** Recupération de l'abscisse
      * Boucles jusqu'à avoir une valeur autorisée
      */
    do{
      cout<< "Choisi la première coordonnée (abscisse de A à J)"<<endl;
      cin>> coord_abs;
    }while( (coord_abs[0]<'A' || coord_abs[0]>'J') || coord_abs.length()>1 );
    /** Recupération de l'ordonnee 
      * Boucles jusqu'à avoir une valeur autorisée
      */
    do{
      cout<< "Choisi la première coordonnée (ordonnee de 1 à 10) "<<endl;
      scanf("%d", &coord_ord); /* utilisation d'un scanf plutot qu'un cin exceptionnelement afin de blinder la saisie d'un caractere a la place d'un nombre */
      getchar(); /* car scanf laisse un '\n' */
    }while(coord_ord <1 || coord_ord>10);//blindage pour éviter saisie d'une valeur en dehors de l'intervalle
  return Coordonnee(coord_abs[0],coord_ord);
}

void JoueurReel::AfficherJoueur(){
  std::string current_case;
  std::cout<<"     A   B   C   D   E   F   G   H   I   J "<<std::endl;
  std::cout<<"   |---|---|---|---|---|---|---|---|---|---|"<<std::endl;
  for(int i=1; i< 11; i++){
    for(char c='A'; c<'K';c++){
      if(c == 'A'){
        if(i>9)
          std::cout<<i;
        else
          std::cout<<i<<" ";
        }
      std::cout<<" | ";
      current_case = " ";
      if( this->VerifierConflitBateaux( Coordonnee(c,i), false ) == true )
        current_case = "X";
      if(this->GetImpactCoord( Coordonnee(c,i) )==true){
        current_case = "X";
        std::cout << "\033[31Em";
        }
      std::cout<<current_case;
    }
    std::cout<<" |"<<std::endl;
    if(i!=10)
        std::cout<<"   |---|---|---|---|---|---|---|---|---|---|"<<std::endl;

  }
    std::cout<<"   |---|---|---|---|---|---|---|---|---|---|"<<std::endl;
}
