#pragma once

#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include "Coordonnee.hpp"


class Bateau { 
    private : 
        bool orientation;
        std::string nom;
        int taille;
        std::vector<std::pair<bool,Coordonnee>> liste_coord_vie_bateau;
        bool en_vie;
    public : 
        Bateau(std::string nom, std::vector<Coordonnee> &liste_coord, bool orientation);
        
};