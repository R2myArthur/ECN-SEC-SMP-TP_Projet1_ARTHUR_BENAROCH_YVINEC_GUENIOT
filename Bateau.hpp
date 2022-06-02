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
        bool orientation;//true -> vertical et false -> horizontal
        std::string nom; //nom du bateau
        int taille;//taille (nombre de case)
        std::vector<std::pair<bool,Coordonnee>> liste_coord_vie_bateau;/*chaque coordonnee(case) est lié a un état.
        Soit elle est "touchée" -> false soit elle est "pas touchée" -> true . Ainsi un couple est formé : coordonnée + vie de la coordonnee (case)*/
        bool en_vie;//si true le bateau est toujours vivant (mais peut-être touché); si false alors il a coulé
    public : 
        /* Constructeur qui reçoit en paramètre 
        - le nom du bateau qu'il doit construire, 
        - la liste VERIFIER des coordonnées du bateau
        - son orientation */
        Bateau(std::string nom, std::vector<Coordonnee> &liste_coord, bool orientation);
        std::vector<Coordonnee> get_liste_coord();//retourne la liste de coordonnees du bateau sous un vecteur de coordonnee
        /*permet de changer l'etat de vie du bateau en false (signifie détruit); 
        la méthode set_tir_touche appelle cette méthode lorsque tout le bateau a été touché */
        void bateau_exploser();
        /* On envoit une coordonnee VERIFIER qui n'a pas encore été touché pour qu'elle soit déclarer en touché */
        bool set_tir_touche(Coordonnee coord);
        std::vector<Coordonnee> get_liste_impact_bateau();//retourne les coordonnees et leur etat (vie) du abteau
        bool verif_coord(Coordonnee coord);
        bool get_vie_bateau(){return this->en_vie;};
    
};