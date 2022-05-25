#pragma once

#include <iostream>
#include <string>
#include <cstdlib>

class Coordonnee {
  private : 
    char x;
    int y;
  public :
    Coordonnee(char x,int y);
    int get_y();
    char get_x();
};