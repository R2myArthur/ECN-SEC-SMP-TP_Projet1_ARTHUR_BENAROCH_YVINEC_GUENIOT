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
      current_case = " ";
      if(j2_info_recup.GetImpactCoord( Coordonnee(c,i) )==true){
        current_case = "X";
        std::cout << "\033[31m";
        }
      else if(j1_a_afficher.VerifierPionBlanc( Coordonnee(c,i) )==true){
                current_case = "O";
                std::cout << "\033[34m";
      }
      std::cout<<current_case;
      std::cout << "\033[0m";
    }
    std::cout<<" |"<<std::endl;
    if(i!=10)
      std::cout<<"   |---|---|---|---|---|---|---|---|---|---|"<<std::endl;

  }
        std::cout<<"   |---|---|---|---|---|---|---|---|---|---|"<<std::endl;
}

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
      if(j1_a_afficher.VerifierConflitBateaux( Coordonnee(c,i), false )==true)
        current_case = "X";
      if(j1_a_afficher.GetImpactCoord( Coordonnee(c,i) )==true){
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
  std::cout<<"Legende : "<<std::endl<<"X: Bateau"<<std::endl << "\033[34m"<<"O"<< "\033[0m"<<" : Tir loupé"<<std::endl<<"\033[31m"<<"X"<< "\033[0m" <<": Tir touché"<<std::endl;
}

void Afficher::deroulement_joueur(Joueur &joueur_qui_joue, Joueur &adversaire){
  this->ClearScrollback();
  std::string myString = "";
  bool condition_rebouclage = false;
  Coordonnee coord;
  
  std::cout<<"Au joueur "<<joueur_qui_joue.GetNom()<<" de jouer"<<std::endl;
  this->afficher_plateau_haut_Joueur(joueur_qui_joue,adversaire);
  this->afficher_plateau_bas_Joueur(joueur_qui_joue);
  do {
      condition_rebouclage = false;
      std::cout<<"Choisi un point à attaquer !"<<std::endl;
      coord = joueur_qui_joue.RenseignerCoordonnee();
      if ( (adversaire.GetImpactCoord(coord) == true) || (joueur_qui_joue.VerifierPionBlanc(coord) == true) ) {
        condition_rebouclage = true;
        std::cout<<"Coordoonnée déjà tirée, recommence"<<std::endl;
      }
  } while ( condition_rebouclage == true );
  this->ClearScrollback();
  if (adversaire.Attaquer(coord) == false) {
    joueur_qui_joue.AjouterPionBlanc(coord);
  }
  this->afficher_plateau_haut_Joueur(joueur_qui_joue,adversaire);
  this->afficher_plateau_bas_Joueur(joueur_qui_joue);
  string OST;
  std::cout<<"Presse n'importe quel caractère pour passer au joueur suivant"<<std::endl;
  std::cin>>OST;
  this->ClearScrollback();
}

void Afficher::ClearScrollback() {
    // cout << "\x1B[3J\x1B[H";
    // cout << "\x1B[2J\x1B[H";
}

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
      // if ( std::stoi(choix_gen_auto) == 1 ){
        JoueurReel j1,j2;
      // } else {
      //   JoueurReel j1(nom_j1);
      //   JoueurReel j2(nom_j2);
      // }
      
      /** Lancer la partie */
      this->InitialisationJoueurVsJoueur(j1, j2);
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
      
      /** Créer les Joueurs */
      // if ( std::stoi(choix_gen_auto) == 1 ){
        JoueurReel joueur;
      // } else {
      //   JoueurReel joueur(nom_j1);
      // }
      // JoueurReel joueur(nom_j1);
      JoueurIA ia((e_level_IA_t)std::stoi(choix_difficulte_ia));
      
      /** Lancer la partie */
      this->InitialisationJoueurVsIA(joueur, ia);
      break;
    }
    default : {
        break;
    }
  }
}

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
  

void Afficher::DeroulementJoueurIA(JoueurIA &joueur_qui_joue, JoueurReel &adversaire){
  srand(time(0));
  static bool is_precedent_tir_touche = false;
  this->ClearScrollback();
  std::string myString = "";
  bool condition_rebouclage = false;
  Coordonnee coord;
  Coordonnee coord_future;
  
  /* Indication utilisateur de qui joue */
  std::cout << "Au joueur "<< joueur_qui_joue.GetNom() << " de jouer" << std::endl;
  
  switch ( joueur_qui_joue.GetDifficulte() ) {
    /* IA SIMPLE */
    case FACILE: {      
      do {
        condition_rebouclage = false;
        coord = coord.TirageAleatoireCoordonnee();
        if ( (adversaire.GetImpactCoord(coord) == true) || (joueur_qui_joue.VerifierPionBlanc(coord) == true) ) {
          condition_rebouclage = true;
        }
      } while ( condition_rebouclage == true );
      break;
    }
    /* IA MOYENNE */
    case MOYEN: {
      //SI table a tirer est vide ALORS Tirage aléatoire
      // SINON tirer les coordonnées du tableau
      for(auto &it : joueur_qui_joue.coordonnees_a_tirer){
      }
      if ( joueur_qui_joue.coordonnees_a_tirer.empty() == true ){
        do {
          condition_rebouclage = false;
          coord = coord.TirageAleatoireCoordonnee();
          if ( (adversaire.GetImpactCoord(coord) == true) || (joueur_qui_joue.VerifierPionBlanc(coord) == true) ) {
            condition_rebouclage = true;
          }
        } while ( condition_rebouclage == true );
      }
      else {
        coord = joueur_qui_joue.coordonnees_a_tirer.back();
        joueur_qui_joue.coordonnees_a_tirer.pop_back();
      }
      break;
    }
    /* IA DIFFICILE */
    case DIFFICILE:{
      // TBD
      break;
    }
    default : {
      break;
    }
  }
  
  this->ClearScrollback();
  
  if (adversaire.Attaquer(coord) == false) {
    // Tir n'a pas touché de bateau
    joueur_qui_joue.AjouterPionBlanc(coord);
  } else {
    // Tir a touché un bateau
    // On réinitialise le tableau d'attaque future
    joueur_qui_joue.coordonnees_a_tirer.erase(joueur_qui_joue.coordonnees_a_tirer.begin(), joueur_qui_joue.coordonnees_a_tirer.end());
    // Check des 4 case autour
    for (int i = 0 ; i < 4 ; i++) {
      switch( i ) {
        case 0: {
          coord_future.SetX(coord.GetX() + 1);
          coord_future.SetY(coord.GetY());
          break;
        }
        case 1: {
          coord_future.SetX(coord.GetX() - 1);
          coord_future.SetY(coord.GetY());
          break;
        }
        case 2: {
          coord_future.SetX(coord.GetX());
          coord_future.SetY(coord.GetY() + 1);
          break;
        }
        case 3: {
          coord_future.SetX(coord.GetX());
          coord_future.SetY(coord.GetY() - 1);
          break;
        }
        default : {
          break;
        }
      } 
      // Si case non déja jouée par le joueur ET dans le plateau, Ce sera une case à attaquer ensuite          
      if ( (joueur_qui_joue.VerifierConflitPlateauAttaque(coord_future) == false) 
                && (adversaire.GetImpactCoord(coord_future) == false) 
                && (joueur_qui_joue.VerifierPionBlanc(coord_future) == false) ) {
        joueur_qui_joue.coordonnees_a_tirer.push_back(coord_future);
      }
    }
  }
}

void Afficher::afficher_message_construction(){
  
  /* Afficher message utilisateur */
cout << "                             *************************************** " << endl;
cout << "                           *                                         * " << endl;
cout << "     *****     ***        *                                           * " << endl;
cout << "    **     ****   ***     *                                           * " << endl;
cout << "   ***   Q         **    *        Création du plateau en cours        * " << endl;
cout << "  *****            *    *                                             * " << endl;
cout << " ******    *******    *                                               * " << endl;
cout << " ******   *             *            ...Merci de patienter...         * " << endl;
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