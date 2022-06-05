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
* \class Coordonnee
* Correspond à un point dans la grille avec axe des abscisse et axe des ordonnées
* P:(x,y)
*/
class Coordonnee {
  private : 
    /** 
    * Valeur de l'Abscisse
    */
    char x;

    /** 
    * Valeur de l'ordonnée
    */
    int y;

  public :
    /** 
    * \brief Constructeur par défaut de la classe avec des coordonnées
    */
    Coordonnee(){};

    /** 
    * \brief Constructeur de coordonnée avec définition des axes
    * \param x Abscisse
    * \param y Ordonnée
    */
    Coordonnee(char x,int y); 
      
    /** 
    * \brief Getter de la valeur de l'ordonnée
    *
    * \return valeur de l'ordonnée 
    */
    int GetY(); 
      
    /** 
    * \brief Getter de la valeur de l'abscisse
    *
    * \return valeur de l'abscisse 
    */
    char GetX();
      
    /** 
    * \brief Setter de la valeur de l'ordonnée
    * \param _y: Ordonnée
    */
    void SetY(int _y);
      
    /** 
    * \brief Setter de la valeur de l'abscisse
    * \param _x: Abscisse
    */
    void SetX(char _x);
      
    /** 
    * \brief Surcharge de l'opérateur '=='
    */
    bool operator==( Coordonnee &second_coord) const; 
    
    /** 
    * \brief Générer un valeur aléatire de coordonnée dans la plage du plateau
    *
    * \return Retourne un jeu de coordonnée (x,y)
    */
    void TirageAleatoireCoordonnee();
      
    /** 
    * \brief Redéfinition de l'operateur << pour afficher les coordonnées mises en formes
    */
    // ostream& operator<<(ostream& os, const Coordonnee& c);
};