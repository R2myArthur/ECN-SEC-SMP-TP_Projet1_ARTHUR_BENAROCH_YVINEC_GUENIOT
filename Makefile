all: main clean-deps

CXX = clang++
override CXXFLAGS += -g -Wno-everything

SRCS = $(shell find . -name '.ccls-cache' -type d -prune -o -type f -name '*.cpp' -print | sed -e 's/ /\\ /g')
OBJS = $(SRCS:.cpp=.o)
DEPS = $(SRCS:.cpp=.d)

%.d: %.cpp
	@set -e; rm -f "$@"; \
	$(CXX) -MM $(CXXFLAGS) "$<" > "$@.$$$$"; \
	sed 's,\([^:]*\)\.o[ :]*,\1.o \1.d : ,g' < "$@.$$$$" > "$@"; \
	rm -f "$@.$$$$"

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c "$<" -o "$@"

include $(DEPS)

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

clean:
	rm -f $(OBJS) $(DEPS) main

clean-deps:
	rm -f $(DEPS)
