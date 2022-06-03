/**
 * \file     Coordonnee.cpp
 * \brief    Fichier de déclaration de la classe Coordonnee
 * \author   Arthur, Benaroch, Gueniot, Yvinec
 * \version  0.1
 * \date     20 Mai 2022
 *
 * Contient l'ensemble des déclarations de la classe Coordonnee du projet bataille navale
 */
#include "Coordonnee.hpp"
#include "Constantes.hpp"

Coordonnee::Coordonnee(char x, int y){
  this->x = x;
  this->y = y;
}

int Coordonnee::GetY(){
  return y;
}

char Coordonnee::GetX(){
  return x;
}

void Coordonnee::SetY(int _y){
  this->y = _y;
}

void Coordonnee::SetX(char _x){
  this->y = _x;
}

bool Coordonnee::operator==( Coordonnee &second_coord) const {
    if( (this->x == second_coord.GetX()) && (this->y == second_coord.GetY()) )
        return true;
    else
        return false;
}

Coordonnee Coordonnee::TirageAleatoireCoordonnee(){
  return Coordonnee(TAB_ABSCISSE[rand()% TAILLE_PLATEAU], TAB_ORDONNEE[rand()% TAILLE_PLATEAU]);
}
