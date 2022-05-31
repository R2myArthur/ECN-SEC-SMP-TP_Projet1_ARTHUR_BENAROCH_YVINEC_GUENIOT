/**
 * \file     Constantes.hpp
 * \brief    Constantes et typedef du projet de bataille navale
 * \author   Arthur, Benaroch, Gueniot, Yvinec
 * \version  0.1
 * \date     20 Mai 2022
 *
 * Contient l'ensemble des constantes et typedef du projet bataille navale
 */

#pragma once
#include <iostream>
#include <array>
#include <vector>

using namespace std;

/**
 * <ul> TYPE DEF
 */

/**
 * \enum e_orientation_t
 * \brief Constantes d'orientation du bateau sur le plateau de jeu.
 *
 * e_orientation_t est une série de constantes prédéfinie pour définir l'orientation du bateau
 * sur le plateau de jeu
 */
typedef enum {
  ORIENTATION_UNDEFINED   = 0,
  ORIENTATION_HORIZONTALE = 1,
  ORIENTATION_VERTICALE   = 2
} e_orientation_t;

typedef enum {
  ABSCISSE  = 0,
  ORDONNEE  = 1,
} e_axe_t;

/**
 * <\ul>
 */

/**
 * <ul>CONSTANTES
 */
const int TAILLE_PORTE_AVION        = 5;
const int TAILLE_CROISEUR           = 4;
const int TAILLE_CONTRE_TORPILLEUR  = 3;
const int TAILLE_TORPILLEUR         = 2;

const string tableau_bateau_const[5] = {"Porte-avion","Croiseur","Contre-torpilleur","Contre-torpilleur","Torpilleur"};
/**
 * <\ul>
 */
