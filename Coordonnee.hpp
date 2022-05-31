/**
 * \file     Coordonnee.hpp
 * \brief    Fichier Header de la classe Coordonnee
 * \author   Arthur, Benaroch, Gueniot, Yvinec
 * \version  0.1
 * \date     20 Mai 2022
 *
 * Contient l'ensemble des définitions de la classe Coordonnee du projet bataille navale
 */

#pragma once

#include <iostream>
#include <string>
#include <cstdlib>

class Coordonnee {
  private : 
    char x;
    int y;
  public :
    Coordonnee(){};
    Coordonnee(char x,int y);
    int GetY();
    char GetX();
    bool operator==( Coordonnee &second_coord) const;
};