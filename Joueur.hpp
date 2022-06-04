/**
 * \file     Joueur.hpp
 * \brief    Fichier header de la classe Joueur.cpp
 * \author   Arthur, Benaroch, Gueniot, Yvinec
 * \version  0.1
 * \date     20 Mai 2022
 *
 * Classe Joueur permettant de définir les méthode et variables d'un joueur à la bataille navale
 */

#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>         /* srand, rand */
#include <time.h>           /* time */
#include <algorithm>
#include "Coordonnee.hpp"
#include "Bateau.hpp"
#include "Constantes.hpp"

// On inclut pas "Afficher.hpp" car sinon rebouclage avec les include de la classe Afficher et conflit
class Afficher;

// Permet de ne pas avoir à renseigner "std::" lors de l'appelle de fonctions de la bibliothèque
using namespace std;

/**
* Déclaration de la classe Joueur
*/
class Joueur {
  protected:
      /**
      * \brief Nom du joueur
      */
      string nom;
  
      /**
      * \brief Liste contenant les bateaux du joueur 
      *
      *  Pion blanc sont les tirs effectués par le joueur chez l'enemi qui n'ont pas touché un bateau
      */
      vector<Bateau> liste_bateau;
  
      /**
      * \brief Liste de coordonnées des pions blanc (raté)
      */
      vector<Coordonnee> liste_pion_blanc;

      /**
      * \brief Liste de coordonnées des pions blanc (raté)
      */
      bool afficher_message;

  public:
      /**
      * \brief Constructeur de la classe Joueur
      *
      * \param name Nom que prendra le joueur durant la partie
      */
      Joueur(){};
  
      /**
      *  Définir la liste des coordonnées à partir du point arrière du bateau, de la taille et de son orientation
      *  \param taille      Taille du bateau
      *  \param point_coord Point de coordonnée de l'arrière du bateau
      *  \param orientation orientation du bateau
      *
      *  \return Retourne la liste des coordonnées qu'occupe le bateau
      */
      vector<Coordonnee> DefinirListeCoord(string nom, Coordonnee coord, bool orientation);
  
      /**
      *  Vérifier les conflits entre les coordonnées et les limites du plateau
      *
      *  \param coordonnees Coordonnées du bateau à vérifier
      *
      *  \return Retourne un booléen qui indique si il y a au moins un conflit
      */
      bool VerifierConflitPlateau(vector<Coordonnee> coordonnees);
  
      /**
      *  Vérifier les conflits entre les coordonnées et les autres bateaux du joueur
      *
      *  \param coordonnees Coordonnées du bateau à vérifier
      *
      *  \return Retourne un booléen qui indique si il y a au moins un conflit
      */
      bool VerifierConflitBateaux(vector<Coordonnee> coordonnees);
  
      /**
      *  Vérifier les conflits entre les coordonnées et les autres bateaux du joueur
      *  
      *  \param coord         Coordonnées du bateau à vérifier
      *  \param is_in_config  permet de définir si l'on est configuration ou pas pour afficher ou non un message à l'utilisateur
      *
      *  \return Retourne un booléen qui indique si il y a au moins un conflit
      */
      bool VerifierConflitBateaux(Coordonnee coord, bool is_in_config);
  
      /**
      *  Récupérer l'état du joueur
      *
      *  \return Retourne l'ensemble des coordonnées touchées par l'adversaire
      */
      bool JoueurVivant();
  
      /**
      *  Interroge l'utilisateur sur un jeu de coordonnée
      *
      *  \detail C'est une méthode virtuelle
      *
      *  \return Retourne les coordonnées rentrées par l'utilisateur vérifié
      */
      virtual Coordonnee RenseignerCoordonnee() = 0;
  
      /**
      *  Interroge l'utilisateur sur un jeu de coordonnée
      *
      *  \param coord Coordonnées à vérifier
      *
      *  \return Retourne vrai si pion blanc deja present dans la liste_pion_blanc
      */
      bool VerifierPionBlanc(Coordonnee coord);
  
      /**
      *  Ajouter un pion blanc dans la liste
      *
      *  \param coord Coordonnée à rajouter
      *
      *  \return La liste donné en paramètre possède un pion supplémentaire
      */
      void AjouterPionBlanc(Coordonnee &coord);
  
  
      /**
      *  Traiter l'attaque du joueur adverse
      *
      *  \details Fonction a appeler par le joueur qui se fait attaquer avec les coordonnees souhaites de l'attaquant
      *
      *  \param coord Coordonnée à rajouter
      *
      *  \return Renvoie true si touché, renvoie false si loupé
      */
      bool Attaquer(Coordonnee &coord);
  
  
      /**
      *  Récupérer la liste des impacts pour chaque bateau
      *
      *  \return Retourne une liste de bateaux avec les coordonnées touchées
      */    
      vector<Coordonnee> GetListeCoordImpactBateau();
  
      /**
      *  Est-ce que un bateau est touché
      *
      *  \param coord Coordonnée à vérifier
      *
      *  \return Retourne true si un bateau du joueur est touché
      */
      bool GetImpactCoord(Coordonnee coord);
 
      /**
      *  Récupérer le nom du joueur
      */  
      string GetNom(){ return this->nom; };


      bool VerifAdjacentBateau(std::vector<Coordonnee> coord);
};