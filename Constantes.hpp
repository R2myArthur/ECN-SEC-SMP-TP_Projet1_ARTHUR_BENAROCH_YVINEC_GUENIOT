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
 * <li> TYPE DEF
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


/**
 * \enum e_axe_t
 * \brief Constantes pour définir l'axe utilisé
 *
 * e_axe_t permet de choisir un axe abscisse ou ordonnée
 */
typedef enum {
  ABSCISSE  = 0,
  ORDONNEE  = 1,
} e_axe_t;


/**
 * \enum e_level_IA_t
 * \brief Constantes pour définir la difficulté du jeu contre l'IA
 *
 * e_level_IA_t permet de choisir le niveau de difficulté de l'IA :
 *       FACILE      Tir de façon aléatoire toute la partie
 *       MOYEN       Tir aléatoire jusqu'a toucher un bateau, une fois touché elle tire sur les cases adjacentes du bateau (x+1,x-1,y+1,y-1)
 *       DIFFICILE   Tir aléatoire jusqu'a toucher un bateau, elle tire jusqu'a couler le bateau
 */
typedef enum {
  FACILE    = 0,
  MOYEN     = 1,
  DIFFICILE = 2,
} e_level_IA_t;

/**
 * <li>CONSTANTES
 */

/**
 * Taille en nombre de case du porte avion
 */
const int TAILLE_PORTE_AVION        = 5;
/**
 * Taille en nombre de case du croiseur
 */
const int TAILLE_CROISEUR           = 4;
/**
 * Taille en nombre de case du contre torpilleur
 */
const int TAILLE_CONTRE_TORPILLEUR  = 3;
/**
 * Taille en nombre de case du torpilleur
 */
const int TAILLE_TORPILLEUR         = 2;

/** Définition des noms de bateaux dans un tableau */
const string tableau_bateau_const[5] = {"Porte-avion","Croiseur","Contre-torpilleur","Contre-torpilleur","Torpilleur"};

/** Taille du plateau de jeu (en abscisse et ordonnée) */
const int   TAILLE_PLATEAU = 10;

/** Définition d'un tableau avec la liste des coordonnées du plateau en abscisse */
const char  TAB_ABSCISSE[TAILLE_PLATEAU] = {'A','B','C','D','E','F','G','H','I','J'};

/** Définition d'un tableau avec la liste des coordonnées du plateau en abscisse */
const int   TAB_ORDONNEE[TAILLE_PLATEAU] = {1,2,3,4,5,6,7,8,9,10};

