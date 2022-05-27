#include "Coordonnee.hpp"

Coordonnee::Coordonnee(char x, int y){
  this->x = x;
  this->y = y;
}

int Coordonnee::get_y(){
  return y;
}

char Coordonnee::get_x(){
  return x;
}

bool Coordonnee::operator==( Coordonnee &second_coord) const {
    if( (this->x == second_coord.get_x()) && (this->y == second_coord.get_y()) )
        return true;
    else
        return false;
}