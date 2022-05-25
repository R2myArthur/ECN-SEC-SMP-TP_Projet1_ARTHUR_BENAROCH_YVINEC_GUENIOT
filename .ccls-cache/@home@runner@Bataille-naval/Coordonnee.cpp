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