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
      * \brief Variable permettant de gérer l'affichage des message dans les méthodes de Joueur, notemment pour eviter les affichage avec l'IA
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
      *  \param nom         Nom du bateau
      *  \param coord Point de coordonnée de l'arrière du bateau
      *  \param orientation Orientation du bateau
      *
      *  \return Retourne la liste des coordonnées qu'occupe le bateau
      */
      vector<Coordonnee> DefinirListeCoord(string nom, Coordonnee coord, bool orientation);
  
      /**
      *  Vérifier les conflits entre les coordonnées en paramètre et les limites du plateau
      *
      *  \param coordonnees Coordonnées du bateau à vérifier
      *
      *  \return Retourne un booléen qui indique si il y a au moins un conflit
      */
      bool VerifierConflitPlateau(vector<Coordonnee> coordonnees);
  
      /**
      *  Vérifier les conflits entre les coordonnées en paramètre et les autres bateaux du joueur
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
      *  \return Vrai si vivant, Faux si mort
      */
      bool JoueurVivant();
  
      /**
      *  Interroge l'utilisateur sur un jeu de coordonnée
      *
      *  \details C'est une méthode virtuelle à redéfinir dans les sous-classe
      *  Les entrées de l'utilisateurs seront vérifiées
      *
      *  \return Retourne les coordonnées rentrées par l'utilisateur
      */
      virtual Coordonnee RenseignerCoordonnee() = 0;
  
      /**
      *  Vérifier si les coordonnées en paramètres sont dans la liste des tirs qui n'ont pa touchés de bateau
      *
      *  \param coord Coordonnées à vérifier
      *
      *  \return Retourne vrai si pion blanc deja present dans la #liste_pion_blanc sinon Faux
      */
      bool VerifierPionBlanc(Coordonnee coord);
  
      /**
      *  Ajouter un pion blanc dans la liste et afficher que le tire est 'loupé'
      *
      *  \param coord Coordonnée à rajouter
      */
      void AjouterPionBlanc(Coordonnee &coord);
  
  
      /**
      *  Traiter l'attaque du joueur adverse
      *
      *  \details Fonction a appeler par le joueur qui se fait attaquer avec les coordonnees souhaitées de l'attaquant
      *
      *  \param coord Coordonnée à attaquer sur le joueur
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
      *  Permet de savoir si les coordonnées en paramètre correspondent à une case où le bateau est présent
      *
      *  \param coord Coordonnée à vérifier
      *
      *  \return Retourne Vrai si un bateau du joueur est touché sinon Faux
      */
      bool GetImpactCoord(Coordonnee coord);
 

      /**
      *  Vérifier que le bateau n'est pas adjacent à un autre bateau
      *  
      *  \param coord Coordonnée à vérifier
      *  \param orientation Orientation du bateau

      *  \return Retourne Vrai si il est adjacent, sinon Faux
      */  
      bool VerifAdjacentBateauConflit(std::vector<Coordonnee> coord, bool orientation);


      /**
      *  Récupérer le nom du joueur
      *  
      * \return Retourne le nom du joueur
      */  
      string GetNom(){ return this->nom; };
};