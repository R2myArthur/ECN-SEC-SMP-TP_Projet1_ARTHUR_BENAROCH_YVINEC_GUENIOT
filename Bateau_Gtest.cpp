#include <iostream>
#include <vector>
#include "Bateau.hpp"
#include "googletest/googletest/include/gtest/gtest.h"

class BateauTest : public ::testing::Test {
public: 
protected:
};

/* Vérif coordonnées */
TEST_F(BateauTest, VerfiCoord)
{
  std::vector<Coordonnee> list_coord;
  list_coord.push_back(Coordonnee('A',1));
  list_coord.push_back(Coordonnee('A',2));
  
  Bateau bat("torpilleur", list_coord, 0);
  EXPECT_TRUE(bat.verif_coord(Coordonnee('A',1)));
  
  EXPECT_FALSE(bat.verif_coord(Coordonnee('A',3)));
  EXPECT_FALSE(bat.verif_coord(Coordonnee('D',1)));
}
