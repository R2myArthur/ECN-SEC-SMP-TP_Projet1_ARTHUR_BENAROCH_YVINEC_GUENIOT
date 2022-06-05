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

/** 
* Constructeur de coordonnée avec définition des axes
*/
Coordonnee::Coordonnee(char x, int y){
  this->x = x;
  this->y = y;
}

/** 
* Getter de la valeur de l'ordonnée
*/
int Coordonnee::GetY(){
  return y;
}

/** 
* Getter de la valeur de l'abscisse
*/
char Coordonnee::GetX(){
  return x;
}

/** 
* Setter de la valeur de l'ordonnée
*/
void Coordonnee::SetY(int _y){
  this->y = _y;
}

/** 
* Setter de la valeur de l'abscisse
*/
void Coordonnee::SetX(char _x){
  this->x = _x;
}

/** 
* Surcharge de l'opérateur '=='
*/
bool Coordonnee::operator==( Coordonnee &second_coord) const {
    if( (this->x == second_coord.GetX()) && (this->y == second_coord.GetY()) )
        return true;
    else
        return false;
}

/** 
* Générer une valeur aléatiore de coordonnée dans la plage du plateau
*/
Coordonnee Coordonnee::TirageAleatoireCoordonnee(){
  srand(time(0));
  return Coordonnee(TAB_ABSCISSE[rand()% TAILLE_PLATEAU], TAB_ORDONNEE[rand()% TAILLE_PLATEAU]);
}

/** Surcharge de l'opérateur << */
// ostream& operator<<(ostream& os, const Coordonnee& c){
//      os << "Coordonnées : " << c.x << c.y;
//     return os;
// }
