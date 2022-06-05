#include <iostream>
#include "Coordonnee.hpp"
#include "googletest/googletest/include/gtest/gtest.h"

class CoordonneeTest : public ::testing::Test {
public: 
protected:
  Coordonnee *coordtest = new Coordonnee;
};

/* Test des getter et setter */
TEST_F(CoordonneeTest, GetSet)
{
  coordtest->SetX('A');
  coordtest->SetY(1);
  
  EXPECT_EQ(coordtest->GetX(), 'A');
  EXPECT_EQ(coordtest->GetY(), 1);
}

/* Test de génération aléatoire */
TEST_F(CoordonneeTest, alea)
{
  coordtest->TirageAleatoireCoordonnee();
  
  EXPECT_TRUE(coordtest->GetX()>='A');
  EXPECT_TRUE(coordtest->GetX()<='J');
  EXPECT_TRUE(coordtest->GetY()>=1);
  EXPECT_TRUE(coordtest->GetY()<=10);
}


// Test des Google tes avant implémentation des vrais tests
// TEST(TU_Joueur, BasicAssertions) {
//   // Expect two strings not to be equal.
//   EXPECT_STRNE("hello", "world");
//   // Expect equality.
//   EXPECT_EQ(7 * 6, 42);
// }
//===== test code =====
