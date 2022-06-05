/**
 * \file     Bateau.hpp
 * \brief    Fichier Header de la classe Bateau
 * \author   Arthur, Benaroch, Gueniot, Yvinec
 * \version  0.1
 * \date     20 Mai 2022
 *
 * Contient l'ensemble des définitions de la classe Bateau du projet bataille navale
 */

#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include "Coordonnee.hpp"


class Bateau { 
    private : 
      /**
      * \brief Orientation : Vrai -> vertical et Faux -> horizontal
      */
      bool orientation;

      /**
      * \brief Nom du bateau
      */
      std::string nom;

      /**
      * \brief taille (nombre de case du bateau), sa longueur
      */
      int taille;

      /**
      * \brief #liste_coord_vie_bateau est un couple de donnée pour chaque coordonée du plateau
      *  
      * \details Les deux champs du couple sont :
      *      1-Etat de vie, type booléen,( soit pas touché "Vrai", soit touché "Faux"); 
      *      2- Coordonnée, de type Coordonée
      *  Ainsi un couple est formé : coordonnée + vie de la coordonnee (case du plateau)
      */
      std::vector<std::pair<bool,Coordonnee>> liste_coord_vie_bateau;

      /**
      * \brief #en_vie : Le bateau est toujours vivant (mais peut-être touché) = Vrai ;  Bateau coulé = False
      */
        bool en_vie;
    public : 
      /**
      * \brief Constructeur de la classe Bateau
      *
      * \param nom Le nom du bateau qu'il doit construire
      * \param liste_coord La liste VERIFIEE des coordonnées du bateau
      * \param orientation Son orientation
      */
      Bateau(std::string nom, std::vector<Coordonnee> &liste_coord, bool orientation);

      /**
      *  Retourne toute la liste de coordonnees du bateau sous un vecteur de coordonnee
      *
      *  \return un vecteur de coordonées du bateau
      */
      std::vector<Coordonnee> get_liste_coord();

      /**
      *  Identifier un bateau comme coulé : Change l'etat de vie du bateau en Faux (signifie détruit); 
      *  La méthode #set_tir_touche appelle cette méthode lorsque tout le bateau a été touché
      *
      */
      void bateau_exploser();

      /**
      *  Envoyer une coordonnee VERIFIER qui n'a pas encore été touché pour qu'elle soit déclarer en touché
      *  
      *  \param coord Coordonnée à déclarer touché dans le bateau
      *
      *  \return Vrai si trouvé, sinon Faux
      */
      bool set_tir_touche(Coordonnee &coord);

      /**
      *  Retourne les coordonnees des bateaux qui ont été touché (detectable grâce au first du std::pair qui est à l'état false lorsque touché et true sinon)
      *
      *  \return Un vecteur composé des coordonnées touchées de chaque bateau
      */
      std::vector<Coordonnee> get_liste_impact_bateau();

      /**
      *  Vérifier la correspondance des cordonnées en paramètre parmi celle du bateau actuel
      *  
      *  \param coord Coordonnées à vérifier
      *
      *  \return Vrai si trouvé, sinon Faux
      */
      bool verif_coord(Coordonnee coord);

      /**
      *  GETTER de l'etat de vie du bateau
      *
      *  \return un booléen qui est soit false (mort), soit true (vivant)
      */
        bool get_vie_bateau(){return this->en_vie;};
    
};