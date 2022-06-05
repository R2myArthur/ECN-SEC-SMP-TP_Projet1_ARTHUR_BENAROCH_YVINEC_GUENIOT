/**
 * \file     Afficher.cpp
 * \brief    Fichier de déclaration de la classe Afficher
 * \author   Arthur, Benaroch, Gueniot, Yvinec
 * \version  0.1
 * \date     20 Mai 2022
 *
 * Classe Afficher permettant de définir les méthode et variables d'affichage du jeu pour la bataille navale
 */

#include "Afficher.hpp"

/**
  * Affiche le plateau haut du joueur 1 (passer en premier paramètre), liste pion blanc récupéré chez le J1 et la liste pion rouge est récupérée chez J2.
  */
void Afficher::afficher_plateau_haut_Joueur(Joueur &j1_a_afficher, Joueur &j2_info_recup){
 unsigned char jonction = 199;
  std::string current_case;
    std::cout<<"              PLATEAU ATTAQUE "<<std::endl;
  std::cout<<"     A   B   C   D   E   F   G   H   I   J "<<std::endl;
  std::cout<<"   |---|---|---|---|---|---|---|---|---|---|"<<std::endl;
  for(int i=1; i< 11; i++){
    for(char c='A'; c<'K';c++){
      if(c == 'A'){
        if(i>9)
          std::cout<<i;
        else
          std::cout<<i<<" ";
        }
      std::cout<<" | ";
      current_case = " ";//Current case est la case à afficher qui prend soit un champ vide si rien est trouvé comme pion deja joué à cette coordonnée, X rouge si coordonnée d'un baetau a été touché, ou 0 bleu si tir loupé
      if(j2_info_recup.GetImpactCoord( Coordonnee(c,i) )==true){//si coordonée d'un bateau de J2 a été touché
        current_case = "X";
        std::cout << "\033[31m";
        }
      else if(j1_a_afficher.VerifierPionBlanc( Coordonnee(c,i) )==true){//si tir loupé (chaque tir loupé est présent dans la liste des pions blancs )
                current_case = "O";
                std::cout << "\033[34m";
      }
      std::cout<<current_case;//on affiche à la fin notre variable string
      std::cout << "\033[0m";
    }
    std::cout<<" |"<<std::endl;
    if(i!=10)
      std::cout<<"   |---|---|---|---|---|---|---|---|---|---|"<<std::endl;

  }
        std::cout<<"   |---|---|---|---|---|---|---|---|---|---|"<<std::endl;
}
/**
  * Affiche le plateau bas du joueur 1 (passer en premier paramètre), c'est à dire que ça affiche ses bateaux, tout en faisant la distinction des coordonnées des bateaux qui ont été touchées(X rouge) et pas touchées(X blanc).
  */
void Afficher::afficher_plateau_bas_Joueur(Joueur &j1_a_afficher){
  std::string current_case;
  std::cout<<"                 PLATEAU DEFENSE "<<std::endl;
  std::cout<<"     A   B   C   D   E   F   G   H   I   J "<<std::endl;
  std::cout<<"   |---|---|---|---|---|---|---|---|---|---|"<<std::endl;
  for(int i=1; i< 11; i++){
    for(char c='A'; c<'K';c++){
      if(c == 'A'){
        if(i>9)
          std::cout<<i;
        else
          std::cout<<i<<" ";
        }
      std::cout<<" | ";
      current_case = " ";
      if(j1_a_afficher.VerifierConflitBateaux( Coordonnee(c,i), false )==true)//si coordonnée de bateau présent sur cette case, on l'affiche
        current_case = "X";
      if(j1_a_afficher.GetImpactCoord( Coordonnee(c,i) )==true){//si coordonnée du bateau a été touché à cette case, on colore le X en rouge
        current_case = "X";
        std::cout << "\033[31m";
        }
      std::cout<<current_case;
      std::cout << "\033[0m";
    }
    std::cout<<" |"<<std::endl;
    if(i!=10)
        std::cout<<"   |---|---|---|---|---|---|---|---|---|---|"<<std::endl;

  }
  std::cout<<"   |---|---|---|---|---|---|---|---|---|---|"<<std::endl;
  /* Legende du plateau */
  std::cout<<"Legende : "<<std::endl<<"X: Bateau"<<std::endl << "\033[34m"<<"O"<< "\033[0m"<<" : Tir loupé"<<std::endl<<"\033[31m"<<"X"<< "\033[0m" <<": Tir touché"<<std::endl;
}

/**
  * Deroule la partie du joueur 1 et joueur 2, maitre du jeu.
  */
void Afficher::deroulement_joueur(Joueur &joueur_qui_joue, Joueur &adversaire){
  this->ClearScrollback();
  std::string myString = "";
  bool condition_rebouclage = false;//pour reboucler lors de la saisie d'une coordonnée si celle-ci est fausse
  Coordonnee coord;
  
  std::cout<<"Au joueur "<<joueur_qui_joue.GetNom()<<" de jouer"<<std::endl;
  // On affiche les plateaux du joueur
  this->afficher_plateau_haut_Joueur(joueur_qui_joue,adversaire);
  this->afficher_plateau_bas_Joueur(joueur_qui_joue);
  //on lui fait saisir une coordonnée à atatquer, si déjà joué/ en dehors du plateau on fait reboucler 
  do {
      condition_rebouclage = false;
      std::cout<<"Choisi un point à attaquer !"<<std::endl;
      coord = joueur_qui_joue.RenseignerCoordonnee();//return un coordonée VERIFIE
      if ( (adversaire.GetImpactCoord(coord) == true) || (joueur_qui_joue.VerifierPionBlanc(coord) == true) ) {//si la coordonnée ne fait ni parti de la liste des pions rouges & pions blancs alors la coordonée n'a pas encore été jouée
        condition_rebouclage = true;
        std::cout<<"Coordoonnée déjà tirée, recommence"<<std::endl;
      }
  } while ( condition_rebouclage == true );
  this->ClearScrollback();
  //on joue l'attaque à l'endroit séléctionné précdemment
  if (adversaire.Attaquer(coord) == false) {
    joueur_qui_joue.AjouterPionBlanc(coord);
  }
  //on réaffiche le nouveau plateau avec l'attaque joué
  this->afficher_plateau_haut_Joueur(joueur_qui_joue,adversaire);
  this->afficher_plateau_bas_Joueur(joueur_qui_joue);
  //Pour passer au tour suivant, écrire n'importe quelle coordonnée
  string OST;
  std::cout<<"Presse n'importe quel caractère pour passer au joueur suivant"<<std::endl;
  std::cin>>OST;
  this->ClearScrollback();
}
/**
  * Clean ineterface de jeu
  */
void Afficher::ClearScrollback() {
    cout << "\x1B[3J\x1B[H";
    cout << "\x1B[2J\x1B[H";
}
/**
  * Afficher visuellement les bateaux selon le nom (aide à la selection et pose des bateaux sur le jeu en début de partie)
  */
void Afficher::affichage_bateau_selection(bool orientation, std::string nom_bateau) {
  if(nom_bateau == "Torpilleur"){
    std::cout<<"   _____"<<std::endl;
    std::cout<<"  | o o |____"<<std::endl;
    std::cout<<"  |_________/"<<std::endl;
    std::cout<<"   ↑"<<std::endl;
    std::cout<<"arriere du bateau"<<std::endl<<std::endl;
  }
  else if(nom_bateau == "Contre-torpilleur"){
    std::cout<<"     _______"<<std::endl;
    std::cout<<"  __/ o o o |__"<<std::endl;
    std::cout<<" |____________/"<<std::endl;
    std::cout<<"   ↑"<<std::endl;
    std::cout<<"arriere du bateau"<<std::endl<<std::endl;
  }
  else if(nom_bateau == "Croiseur"){
    std::cout<<"    _________"<<std::endl;
    std::cout<<"   / o o o o |____"<<std::endl;
    std::cout<<"   |_____________/"<<std::endl;
    std::cout<<"   ↑"<<std::endl;
    std::cout<<"arriere du bateau"<<std::endl<<std::endl;
  }
    else if(nom_bateau == "Porte-avion"){
    std::cout<<"     ____________"<<std::endl;
    std::cout<<"  __/ o o o o o |______________"<<std::endl;
    std::cout<<" |____________________________/"<<std::endl;
    std::cout<<"   ↑"<<std::endl;
    std::cout<<"arriere du bateau"<<std::endl<<std::endl;
  }
}
/**
  * Permettra de choisir entre se battre contre une IA ou un joueur, puis de faire générer ou pas son plateau aléatoirement, puis choisir un niveau de difficulté de l'IA (si le combat est contre elle)
  */
void Afficher::SelectionMenu() {
  string choix, nom_j1, nom_j2, choix_gen_auto, choix_difficulte_ia;

  /** Demander le choix de jeu du joueur entre Joueur vs Joueur ou Joueur vs IA */
  do{
  std::cout<<"Choisi ton combat"<<std::endl<<"1. Combat contre un joueur"<<std::endl<<"2. Combat contre l'IA"<<std::endl;
    std::cin >> choix;
  }while(choix[0]!='1' && choix[0]!='2');

  /** Demander si l'utilisateur veut créer lui même les bateaux ou pas */
  do{
    std::cout<<"Voulez-vous générer automatiquement les bateaux du Joueur de jeux? (0 : NON ; 1 : OUI)"<<std::endl;
    std::cin >> choix_gen_auto;
  } while(choix_gen_auto[0]!='0' && choix_gen_auto[0]!='1');
  
  switch(std::stoi(choix)){
    case 1 : {
      /** Demander les noms des joueurs */
      std::cout<<"Joueur 1 entre ton nom :";
      std::cin>> nom_j1;
      std::cout <<"Joueur 2 entre ton nom :";
      std::cin>> nom_j2;
    
      /** Créer les Joueurs en fonction de la génération automatique ou non */
       if ( std::stoi(choix_gen_auto) == 1 ){
        afficher_message_construction();
        JoueurReel j1,j2;
         this->InitialisationJoueurVsJoueur(j1, j2);
       } else {
         JoueurReel j1(nom_j1);
         JoueurReel j2(nom_j2);
         this->InitialisationJoueurVsJoueur(j1, j2);
       }
      
      /** Lancer la partie */
      break;
    }
    case 2 :{
      /** Demander le nom du joueur à l'utilisateur */
      std::cout<<"Joueur 1 entre ton nom :";
      std::cin>> nom_j1;
      
      /** Demander au joueur difficulté IA */
      do{
        std::cout<<"Quel dfficulté d'IA voulez vous? (0 : FACILE ; 1 : MOYEN)"<<std::endl;
        std::cin >> choix_difficulte_ia;
      } while(choix_difficulte_ia[0]!='0' && choix_difficulte_ia[0]!='1');
      
      afficher_message_construction();
      JoueurIA ia((e_level_IA_t)std::stoi(choix_difficulte_ia));
      /** Créer les Joueurs */
       if ( std::stoi(choix_gen_auto) == 1 ){
        JoueurReel joueur;
        this->InitialisationJoueurVsIA(joueur, ia);
         } 
       else {
        JoueurReel joueur(nom_j1);
        this->InitialisationJoueurVsIA(joueur, ia);
         }      
      /** Lancer la partie */
      break;
    }
    default : {
        break;
    }
  }
}
/**
*  Initialise la partie et le roulement de tour entre les 2 joueurs
*/
void Afficher::InitialisationJoueurVsJoueur(JoueurReel &j1, JoueurReel &j2) {
    bool tour = false; //false = J1 de jouer ; True= J2 de joue
    do{
      // Attente présence joueur
      if(tour == false){
        this->deroulement_joueur(j1,j2);
        tour = true;
      }
      else{
        this->deroulement_joueur(j2,j1);
        tour = false;
      }
      // Attente
      // Fin attente effacer console
    }while( (j1.JoueurVivant()==true) && (j2.JoueurVivant()==true) );
    (j1.JoueurVivant()==true) ? std::cout<<"Joueur 1 gagne !"<<std::endl : std::cout<<"Joueur 2 gagne !"<<std::endl;
}

/**
* Initialise la partie et le roulement de tour entre les 2 joueurs, l'un réel et l'autre IA
*/
void Afficher::InitialisationJoueurVsIA(JoueurReel &j1, JoueurIA &jIA) {
  bool tour = false;
  //false = J1 de jouer ; True= J2 de joue
  do{
    if(tour == false){
      this->deroulement_joueur(j1,jIA);
      tour = true;
    }
    else{
      this->DeroulementJoueurIA(jIA,j1);
      tour = false;
    }
  }while( (j1.JoueurVivant()==true) && (jIA.JoueurVivant()==true) );
  (j1.JoueurVivant()==true) ? std::cout << j1.GetNom() << " gagne !"<<std::endl : std::cout << jIA.GetNom() << " gagne !"<<std::endl;
}
  
/**
* Maitre du jeu de la partie entre un joueur reel et une IA
* 
* \todo Il faudra reprendre la fonction et la découper pour la rendre plus lisible et factoriser le tirage aléatoire.
*/
void Afficher::DeroulementJoueurIA(JoueurIA &joueur_qui_joue, JoueurReel &adversaire){
  srand(time(0));
  bool condition_rebouclage = false;
  Coordonnee coord;
  Coordonnee coord_future;

  /** Effacer la console */
  this->ClearScrollback();
  
  /** Indication utilisateur de qui joue */
  std::cout << "Au joueur "<< joueur_qui_joue.GetNom() << " de jouer" << std::endl;

  /** Récupérer la prochaien coordonnée à attaquer */
  joueur_qui_joue.GestionCoordonneeAttaque(adversaire, coord);

  /** Effacer la console */
  this->ClearScrollback();

  /** Envoyer l'action d'attaque => Vérifier si la case est touchée ou pas  */
  if (adversaire.Attaquer(coord) == false) {
    /** Tir n'a pas touché de bateau : stockage dans la liste de tir raté */
    joueur_qui_joue.AjouterPionBlanc(coord);
  } else {
    /** Tir a touché un bateau */
    /** Récupérer la prochaien coordonnée à attaquer */
    if (joueur_qui_joue.GetDifficulte() == MOYEN){
      joueur_qui_joue.GestionAttaqueTouchee(adversaire, coord);
    }
  }
}

/** Afficher message utilisateur à la construction du plateau */
void Afficher::afficher_message_construction(){
  cout << "                             *************************************** " << endl;
  cout << "                           *                                         * " << endl;
  cout << "     *****     ***        *                                           * " << endl;
  cout << "    **     ****   ***     *                                           * " << endl;
  cout << "   ***   Q         **    *        Création du plateau en cours        * " << endl;
  cout << "  *****            *    *                                             * " << endl;
  cout << " ******    *******    *                                               * " << endl;
  cout << " ******   *             *           ... Merci de patienter ...        * " << endl;
  cout << " ******   *       **     *                                            * " << endl;
  cout << " *****     ****  *  *     *                                           * " << endl;
  cout << "  ****        * *   *     *                                           * " << endl;
  cout << "   ** *    * * *  **       *                                         * " << endl;
  cout << "       *   *  *  *           *************************************** " << endl;
  cout << "       *     *  * " << endl;
  cout << "      *         * " << endl;
  cout << "      *          * " << endl;
  cout << "     *            * " << endl;
  cout << "     *  *          * " << endl;
  cout << "     *  *           * " << endl;
  cout << "     *  *           * " << endl;
  cout << "     *  *          * " << endl;
  cout << "     *   *        * " << endl;
  cout << "      ***        * " << endl;
  cout << "        *   *  ** " << endl;
  cout << "         *  *  * " << endl;
  cout << "         *  *  ***** " << endl;
  cout << "        *  **** *   * " << endl;
  cout << "        *        *** " << endl;
  cout << "         ******** " << endl;
}