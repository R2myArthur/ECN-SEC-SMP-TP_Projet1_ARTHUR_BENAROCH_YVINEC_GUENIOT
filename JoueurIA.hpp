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
#include "JoueurReel.hpp"

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
    /**
    * \brief Liste des coordonnées à tirer dans les tours suivants
    */
    vector<Coordonnee> coordonnees_a_tirer;

    /**
    * \brief Constructeur de la classe Joueur IA
    *
    * \param level Niveau de difficulté souhaité
    */
    JoueurIA(e_level_IA_t level);

    /**
    *  Interroge l'utilisateur sur un jeu de coordonnée (plus utilisé pour IA)
    *
    *  \details Non utilisé pour l'IA car pas de coordonnées utilisateur à récupérer
    *
    *  \return Ne fait rien
    */
    Coordonnee RenseignerCoordonnee();

    /**
    *  Afficher la table du jeu à l'utilisateur
    *  
    *  \details Utilisé pour le DEBUG uniquement
    */  
    void AfficherJoueur();

    /**
    *  Getter de la variable de difficulté de l'IA
    *  
    *  \return Valeur de #difficulte_ia
    */  
    e_level_IA_t GetDifficulte();

    /**
    *  Vérifier que les coordonnées en paramètre sont bien dans la plage de jeu du plateau
    *  
    *  \return Vrai si en dehors et Faux si dedans
    */  
    bool VerifierConflitPlateauAttaque(Coordonnee coordonnees);


    /**
    *  Mettre à jour les coordonnées à attaquer en fonction de la difficulté de l'IA. Fonctionnement est détaillé dans la méthode
    *  
    *  La fonction met à jour le paramètre coord
    *
    *  \param adversaire Joueur réel contre qui l'IA joue
    *  \param coord Les coordonnées à attaquer à ce tour
    */ 
    void GestionCoordonneeAttaque(JoueurReel &adversaire, Coordonnee &coord);

    /**
    *  Gérer la suite d'une attaque qui a touché, définir les futures coordonnées à attaquer
    *  
    *  \param adversaire Joueur réel contre qui l'IA joue
    *  \param coord Les coordonnées qui ont été touchées
    */ 
    void GestionAttaqueTouchee(JoueurReel &adversaire, Coordonnee &coord);

};
