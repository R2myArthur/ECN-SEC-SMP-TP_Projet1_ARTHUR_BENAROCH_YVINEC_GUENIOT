/**
 * \file     Afficher.hpp
 * \brief    Fichier header de la classe Afficher.cpp
 * \author   Arthur, Benaroch, Gueniot, Yvinec
 * \version  0.1
 * \date     20 Mai 2022
 *
 * Classe Afficher permettant de définir les méthode et variables d'affichage et de gestion du jeu pour la bataille navale
 */

#pragma once

#include "JoueurReel.hpp"
#include "JoueurIA.hpp"
#include "Coordonnee.hpp"
#include <thread>
#include <chrono>

class Afficher{
  public :
    /**
    *  <li> Constructeur de la classe Afficher
    */
    Afficher(){};


    /**
    *  <li> Afficher le plateau d'attaque du Joueur selectionné (plateau supérieur dans le jeu)
    *
    *  \param j1_a_afficher  Joueur à afficher
    *  \param j2_info_recup  Joueur adverse
    *
    *  \detail Affiche le plateau du j1_a_afficher en fonction des attaques envoyées sur j2_info_recup
    */
    void afficher_plateau_haut_Joueur(Joueur &j1_a_afficher, Joueur &j2_info_recup);

    /**
    *  <li> Afficher le plateau de défense du Joueur selectionné (plateau inférieur dans le jeu)
    *
    *  \param j1_a_afficher  Taille du bateau
    *
    *  \detail Affiche le plateau du j1_a_afficher avec ses bateaux
    */
    void afficher_plateau_bas_Joueur(Joueur &j1_a_afficher);
    void deroulement_joueur(Joueur &joueur_qui_joue, Joueur &adversaire);
    void affichage_bateau_selection(bool orientation, std::string nom_bateau);
    void ClearScrollback();
    void SelectionMenu();
    void InitialisationJoueurVsJoueur(JoueurReel &j1, JoueurReel &j2);
    void InitialisationJoueurVsIA(JoueurReel &j1, JoueurIA &jIA);
    void DeroulementJoueurIA(JoueurIA &joueur_qui_joue, JoueurReel &adversaire);
    void afficher_message_construction();

};
