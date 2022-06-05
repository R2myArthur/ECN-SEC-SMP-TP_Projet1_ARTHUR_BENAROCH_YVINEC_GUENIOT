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
    *  Constructeur de la classe Afficher
    */
    Afficher(){};


    /**
    *  Afficher le plateau d'attaque du Joueur selectionné (plateau supérieur dans le jeu)
    *
    *  \param j1_a_afficher  Joueur à afficher
    *  \param j2_info_recup  Joueur adverse
    *
    *  \details Affiche le plateau du j1_a_afficher en fonction des attaques envoyées sur j2_info_recup
    */
    void afficher_plateau_haut_Joueur(Joueur &j1_a_afficher, Joueur &j2_info_recup);

    /**
    *  Afficher le plateau de défense du Joueur selectionné (plateau inférieur dans le jeu)
    *
    *  \param j1_a_afficher  Taille du bateau
    *
    *  \details Affiche le plateau du j1_a_afficher avec ses bateaux
    */
    void afficher_plateau_bas_Joueur(Joueur &j1_a_afficher);
      /**
      *  Maitre du jeu de la partie entre deux joueurs reels
      *  
      *  \param joueur_qui_joue   joueur jouant actuellement
      *  \param adversaire adversaire du joueur
      *
      *  \return vide
      */
    void deroulement_joueur(Joueur &joueur_qui_joue, Joueur &adversaire);
      /**
      *  Permet de donner un visuel en format ASCII du bateau qu'il faut actuellement placer
      *  
      *  \param orientation         Orientation du bateau à placer
      *  \param nom_bateau Le nom du bateau
      *
      *  \return vide
      */
    void affichage_bateau_selection(bool orientation, std::string nom_bateau);
      /**
      *  Permet de nettoyer la console pour ne pas voir le plateau du joueur précédent
      *
      *  \return vide
      */
    void ClearScrollback();
      /**
      *   Permettra de choisir entre se battre contre une IA ou un joueur, puis de faire générer ou pas son plateau aléatoirement, puis choisir un niveau de difficulté de l'IA (si le combat est contre elle)
      */
    void SelectionMenu();
      /**
      *  Initialise la partie et le roulement de tour entre les 2 joueurs
      *  
      *  \param j1  joueur 1 
      *  \param j2  joueur 2
      */
    void InitialisationJoueurVsJoueur(JoueurReel &j1, JoueurReel &j2);
      /**
      *  Initialise la partie et le roulement de tour entre les 2 joueurs, l'un réel et l'autre IA
      *  
      *  \param j1  Joueur 1
      *  \param jIA IA
      *
      *  \return vide
      */
    void InitialisationJoueurVsIA(JoueurReel &j1, JoueurIA &jIA);
      /**
      *  Maitre du jeu de la partie entre un joueur reel et une IA
      *  
      *  \param joueur_qui_joue IA
      *  \param adversaire Joueur réel
      *
      *  \return vide
      */
    void DeroulementJoueurIA(JoueurIA &joueur_qui_joue, JoueurReel &adversaire);
      /**
      *  Message émis lors de la génération du plateau par l'ordinateur.
      */
    void afficher_message_construction();

};
