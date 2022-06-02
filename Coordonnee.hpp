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
/**
*  Correspond à un point dans la grille avec axe des abscisse et axe des ordonnées
*/
class Coordonnee {
  private : 
    /** 
      * \brief valeur 'char' qui correspond à l'Abscisse
      *  a:(x,y) 
    */
    char x;
    /** 
      * \brief Ordonnée : valeur entière entre 1 et 10
    */
    int y;
  public :
    /** 
      * \brief Constructeur par défaut de la classe avec des coordonnées
    */
    Coordonnee(){};

    /** 
    * \brief Constructeur de coordonnée
    * \param x: Abscisse
    *\param y: Ordonnée
    */
    Coordonnee(char x,int y); 
    /** 
    * \brief Méthode pour récupérer l'ordonnée de la coordonnée
    */
    int GetY(); 
    /** 
    * \brief Méthode pour récupérer l'abscisse de la coordonnée
    */
    char GetX();
    /** 
    * \brief 
    * \param y: Ordonnée
    */
    void SetY(int _y);
    /** 
    * \brief
    * \param x: Abscisse
    */
    void SetX(char _x);
    /** 
    * \brief Surcharge de l'opérateur '=='
    */
    bool operator==( Coordonnee &second_coord) const; 
};