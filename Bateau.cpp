/**
 * \file     Bateau.cpp
 * \brief    Fichier de déclaration de la classe Bateau
 * \author   Arthur, Benaroch, Gueniot, Yvinec
 * \version  0.1
 * \date     20 Mai 2022
 *
 * Classe Bateau permettant de définir les méthode et variables d'un bateau pour le jeu de bataille navale
 */

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
    this->liste_coord_vie_bateau.push_back( std::make_pair(true,liste_coord[i]) );
  }
}

std::vector<Coordonnee> Bateau::get_liste_coord(){
   std::vector<Coordonnee> liste_coord_envoi;
   for(auto &it : liste_coord_vie_bateau){
       liste_coord_envoi.push_back(it.second);
   }
   return liste_coord_envoi;
}
void Bateau::bateau_exploser(){
    this->en_vie = false;
    std::cout<<"Le bateau "<<this->nom<<" a été coulé !"<<std::endl;
}

bool Bateau::set_tir_touche(Coordonnee coord){
    bool toucher = false;
    bool etat_en_vie=false;/*on demarre l'etat de la vie du bateau à faux, et lorsqu'on verra qu'au moins 
    une des cases est en vie, alors on passe la variable en true*/
    for(auto &it : liste_coord_vie_bateau){
       if(it.second == coord){//si on trouve la coordonnee passé en paramètre dans notre liste coord du bateau alors on met l'etat false à la coordonnee
         if(it.first==false){
           std::cout<<"Cette coordonnée a déjà été donnée et a touché un bateau recommence !"<<std::endl;
         }  
         else{
           it.first = false;//indique touché
           toucher =true;
           std::cout<<" Touché !!!! "<<std::endl;
        }
       }
       if(it.first == true)//si on trouve au moins une case pas touché alors bateau toujours en vie
            etat_en_vie = true;
   }
   if(etat_en_vie == false){//si la variable est restée a false alors aucune case est encore vivante et donc toutes ont été touchées, le bateau explose et est détruit.
        this->bateau_exploser();}
  return toucher;
}

std::vector<Coordonnee> Bateau::get_liste_impact_bateau(){
    std::vector<Coordonnee> liste_impact_bateau;
    for(auto &it : liste_coord_vie_bateau){
      if(it.first == false)//false veut dire coordonnée pas en vie, donc touché
        liste_impact_bateau.push_back(it.second);//donc si coordonnée touchée, on ajoute cette coord dans notre liste d'envoi 
    }
  return liste_impact_bateau;
}

 bool Bateau::verif_coord(Coordonnee coord){
        for(auto &it : liste_coord_vie_bateau){
            if(it.second == coord)//si on trouve la coordonnee passé en paramètre dans notre liste coord du bateau alors on return true
                return true;
        }
        return false;
 }