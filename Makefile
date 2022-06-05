GTEST_DIR = ./googletest/googletest
GTEST_LIB = ./googletest/lib

OBJS = $(.cpp=.o)
DEPS = $(.cpp=.d)

CPP_FLAGS = -isystem $(GTEST_DIR)/include  -g -Wall -Wextra -pthread -std=c++11

GTEST_HEADERS = $(GTEST_DIR)/include/gtest/*.h \
                $(GTEST_DIR)/include/gtest/internal/*.h

Coordonnee_Gtest.out: Coordonnee_Gtest.o Coordonnee.o
	g++ $(CPP_FLAGS) -o Coordonnee_Gtest.out Coordonnee_Gtest.o Coordonnee.o -lpthread $(GTEST_LIB)/libgtest.a $(GTEST_LIB)/libgtest_main.a

Bateau_Gtest.out: Bateau_Gtest.o Bateau.o  Coordonnee.o
	g++ $(CPP_FLAGS) -o Bateau_Gtest.out Bateau_Gtest.o Bateau.o Coordonnee.o -lpthread $(GTEST_LIB)/libgtest.a $(GTEST_LIB)/libgtest_main.a

main: Joueur.o JoueurIA.o JoueurReel.o Bateau.o Coordonnee.o main.o Afficher.o
	g++ -o main Joueur.o JoueurIA.o JoueurReel.o Bateau.o Coordonnee.o main.o Afficher.o

main.o: main.cpp
	g++ -c main.cpp
Joueur.o: Joueur.cpp
	g++ -c Joueur.cpp
JoueurIA.o: JoueurIA.cpp
	g++ -c JoueurIA.cpp
JoueurReel.o: JoueurReel.cpp
	g++ -c JoueurReel.cpp
Bateau.o: Bateau.cpp
	g++ -c Bateau.cpp
Coordonnee.o: Coordonnee.cpp
	g++ -c Coordonnee.cpp
Afficher.o: Afficher.cpp
	g++ -c Afficher.cpp
Coordonnee_Gtest.o: Coordonnee_Gtest.cpp
	g++ -c $(CPP_FLAGS) Coordonnee_Gtest.cpp
Bateau_Gtest.o: Bateau_Gtest.cpp
	g++ -c $(CPP_FLAGS) Bateau_Gtest.cpp

clean:
	rm -f *.o
	rm -f *.out
	rm -f *.d
	rm -f main
