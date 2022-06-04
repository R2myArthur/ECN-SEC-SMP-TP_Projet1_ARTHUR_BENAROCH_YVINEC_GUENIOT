/**
 * \file     JoueurIA.hpp
 * \brief    Fichier header de la classe JoueurIA.cpp
 * \author   Arthur, Benaroch, Gueniot, Yvinec
 * \version  0.1
 * \date     20 Mai 2022
 *
 * Classe JoueurIA permettant de définir les méthodes et variables d'une IA à la bataille navale
 */
#pragma once

#include "Joueur.hpp"

// On inclut pas "Afficher.hpp" car sinon rebouclage avec les include de la classe Afficher et conflit
class Afficher;

// Permet de ne pas avoir à renseigner "std::" lors de l'appelle de fonctions de la bibliothèque
using namespace std;

/**
* Déclaration de la classe Joueur
*/
class JoueurIA : public Joueur{
  private:
    /**
    * \brief Variable de la difficulté de l'IA
    */
    e_level_IA_t difficulte_ia;


  public:

    Coordonnee historique_tir_touche;

    vector<Coordonnee> coordonnees_a_tirer;

    /**
    * \brief Constructeur de la classe Joueur IA
    *
    * \param name Nom que prendra le joueur durant la partie
    */
    JoueurIA(e_level_IA_t level);

    /**
    *  Interroge l'utilisateur sur un jeu de coordonnée
    *
    *  \detail C'est une méthode virtuelle
    *
    *  \return Retourne les coordonnées rentrées par l'utilisateur vérifié
    */
    Coordonnee RenseignerCoordonnee() {};

    /**
    *  Afficher la table du jeu à l'utilisateur
    *  Utilisé pour le DEBUG
    */  
    void AfficherJoueur();

    e_level_IA_t GetDifficulte();

    bool VerifierConflitPlateauAttaque(Coordonnee coordonnees);
};
