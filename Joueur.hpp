#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "Coordonnee.hpp"
#include "Bateau.hpp"
#include "Constantes.hpp"

// Permet de ne pas avoir à renseigner "std::"
using namespace std;

// Déclaration de la classe Joueur
class Joueur {
  private:
    // Nom du joueur
    string nom;

    // Liste contenant les bateaux du joueur 
    vector<Bateau> liste_bateau[5];

    // Liste de coordonnées des pions blanc (raté)
    vector<Coordonnee> liste_pion_blanc;
  public:
    /**
    * Constructeur de la classe Joueur
    */
    Joueur(string name);
    /**
    *  Je comprends pas a quoi ca sert ca? ME rappelle plus...
    */
    vector<Coordonnee> ConfigurerListeCoord(uint8_t taille, Coordonnee point_coord, orientation_t orientation);
    // + ConfigurerListeCoord(taille, point_coord, orientation): vec<coord>

    VerifierConflitPlateau()
    // - VerifierConflitPlateau(list_coord): bool
    // - VerifierConflitBateau(list_coord): bool
    // - GetEtatVie(): vector<coordonnee>

}  