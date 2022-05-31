/**
 * \file     Afficher.cpp
 * \brief    Fichier de déclaration de la classe Afficher
 * \author   Arthur, Benaroch, Gueniot, Yvinec
 * \version  0.1
 * \date     20 Mai 2022
 *
 * Classe Afficher permettant de définir les méthode et variables d'affichage du jeu pour la bataille navale
 */

#include "Afficher.hpp"

void Afficher::afficher_plateau_haut_Joueur(Joueur &j1_a_afficher, Joueur &j2_info_recup){
  std::string current_case;
    std::cout<<"   PLATEAU ATTAQUE "<<std::endl;
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
      if(j2_info_recup.GetImpactCoord( Coordonnee(c,i) )==true)
        current_case = "X";
      else if(j1_a_afficher.VerifierPionBlanc( Coordonnee(c,i) )==true){
                current_case = "O";
                std::cout << "\033[34m";
      }
      std::cout<<current_case;
      std::cout << "\033[0m";
    }
    std::cout<<"║"<<std::endl;
    if(i!=10)
      std::cout<<"  ╠═╬═╬═╬═╬═╬═╬═╬═╬═╬═╣"<<std::endl;

  }
  std::cout<<"  ╚═╩═╩═╩═╩═╩═╩═╩═╩═╩═╝"<<std::endl;
}

void Afficher::afficher_plateau_bas_Joueur(Joueur &j1_a_afficher){
  std::string current_case;
  std::cout<<"   PLATEAU DEFENSE "<<std::endl;
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
      if(j1_a_afficher.VerifierConflitBateaux( Coordonnee(c,i), false )==true)
        current_case = "X";
      if(j1_a_afficher.GetImpactCoord( Coordonnee(c,i) )==true){
        current_case = "X";
        std::cout << "\033[31m";
        }
      std::cout<<current_case;
      std::cout << "\033[0m";
    }
    std::cout<<"║"<<std::endl;
    if(i!=10)
      std::cout<<"  ╠═╬═╬═╬═╬═╬═╬═╬═╬═╬═╣"<<std::endl;

  }
  std::cout<<"  ╚═╩═╩═╩═╩═╩═╩═╩═╩═╩═╝"<<std::endl;
  std::cout<<"Legende : "<<std::endl<<"X: Bateau"<<std::endl<<"O : Tir loupé"<<std::endl<<"T : Tir touché"<<std::endl;
}

void Afficher::deroulement_joueur(Joueur &joueur_qui_joue, Joueur &adversaire){
 // std::cout << "\033[2J\033[0;0H";
  std::string myString = "";
  std::cout<<"Au joueur "<<joueur_qui_joue.GetNom()<<" de jouer"<<std::endl;
  this->afficher_plateau_haut_Joueur(joueur_qui_joue,adversaire);
  this->afficher_plateau_bas_Joueur(joueur_qui_joue);
  std::cout<<"Choisi un point à attaquer !"<<std::endl;
  Coordonnee coord = joueur_qui_joue.RenseignerCoordonnee();
  if((adversaire.GetImpactCoord(coord)==false) && (joueur_qui_joue.VerifierPionBlanc(coord)==false) ) {
      if (adversaire.Attaquer(coord)==false){
        joueur_qui_joue.AjouterPionBlanc(coord);
        }
    }
  else{
    std::cout<<"Coordoonnée déjà tirée"<<std::endl;
    coord = joueur_qui_joue.RenseignerCoordonnee();
  }
  this->afficher_plateau_haut_Joueur(joueur_qui_joue,adversaire);
  this->afficher_plateau_bas_Joueur(joueur_qui_joue);
  //std::this_thread::sleep_for(std::chrono::milliseconds(3000));
  while (1) {
    if (std::cin.get() == '\n') {
      std::cout << "Enter key is pressed" << std::endl;
      break;
    }
    }
  
  this->ClearScrollback();
}

void Afficher::ClearScrollback()
{
    cout << "\x1B[3J\x1B[H";
    cout << "\x1B[2J\x1B[H";
}

void Afficher::affichage_bateau_selection(bool orientation, std::string nom_bateau){
  if(nom_bateau == "Torpilleur"){
    std::cout<<"   _____"<<std::endl;
    std::cout<<"  / o o |____"<<std::endl;
    std::cout<<"  |_________/"<<std::endl;
    std::cout<<"   ↑"<<std::endl;
    std::cout<<"arriere du bateau"<<std::endl<<std::endl;
  }
  else if(nom_bateau == "Contre-torpilleur"){
    std::cout<<"     _______"<<std::endl;
    std::cout<<"  __/ o o o |__"<<std::endl;
    std::cout<<" |____________/"<<std::endl;
    std::cout<<"   ↑"<<std::endl;
    std::cout<<"arriere du bateau"<<std::endl<<std::endl;
  }
  else if(nom_bateau == "Croiseur"){
    std::cout<<"    _________"<<std::endl;
    std::cout<<"   / o o o o |____"<<std::endl;
    std::cout<<"   |_____________/"<<std::endl;
    std::cout<<"   ↑"<<std::endl;
    std::cout<<"arriere du bateau"<<std::endl<<std::endl;
  }
    else if(nom_bateau == "Porte-avion"){
    std::cout<<"     ____________"<<std::endl;
    std::cout<<"  __/ o o o o o |______________"<<std::endl;
    std::cout<<" |____________________________/"<<std::endl;
    std::cout<<"   ↑"<<std::endl;
    std::cout<<"arriere du bateau"<<std::endl<<std::endl;
  }
}
