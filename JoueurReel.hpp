/**
 * \file     JoueurReel.hpp
 * \brief    Fichier header de la classe JoueurReel.cpp
 * \author   Arthur, Benaroch, Gueniot, Yvinec
 * \version  0.1
 * \date     20 Mai 2022
 *
 * Classe JoueurReel permettant de définir les méthode et variables d'un joueur humain (et non bot) à la bataille navale
 */

#pragma once

#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>
#include <stdlib.h>         /* srand, rand */
#include <time.h>           /* time */
#include <algorithm>
#include "Joueur.hpp"
#include "Constantes.hpp"

// On inclut pas "Afficher.hpp" car sinon rebouclage avec les include de la classe Afficher et conflit
class Afficher;

// Permet de ne pas avoir à renseigner "std::" lors de l'appelle de fonctions de la bibliothèque
using namespace std;

/**
* Déclaration de la classe Joueur
*/
class JoueurReel : public Joueur{
  public:
    /**
    * \brief Constructeur de la classe Joueur
    *
    * \param name Nom que prendra le joueur durant la partie
    */
    JoueurReel(string name);

    /**
    * \brief Constructeur de la classe Joueur qui génère automatiquement les bateaux
    */
    JoueurReel();

    /**
    *  Interroge l'utilisateur sur un jeu de coordonnée
    *
    *  \detail les coordonnées renseignées sont vérifier par la méthode
    *
    *  \return Retourne les coordonnées rentrées par l'utilisateur
    */
    virtual Coordonnee RenseignerCoordonnee();

    /**
    *  Afficher la table du jeu à l'utilisateur avec les bateaux du Joueur
    */  
    void AfficherJoueur();

};