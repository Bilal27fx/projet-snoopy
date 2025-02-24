#ifndef PLATEAU_H_INCLUDED
#define PLATEAU_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "windows.h"
#include <conio.h>
#include <stdbool.h>
#include <unistd.h>
#define Ligne 15
#define Colonne 30
#define MAX_BALLES 3
#define MaxTailleMotDePasse 20
#define NombreNiveaux 3
#define NIVEAU1 "ece1"
#define NIVEAU2 "ece2"
#define NIVEAU3 "ece3"
#define NIVEAU4 "ece4"





typedef struct position
{
    int x;
    int y;
}t_position;

typedef struct {
    int scoreRequis;
}t_niveau;

typedef struct plateau
{
    char caractere[Ligne][Colonne];
    char caractere_precedent[Ligne][Colonne];
    int vieSnoopy;
    int score;
    t_position PositionSnoopy;
    t_position PositionSnoopy_precedent;
    t_position Position_nouveau;
    t_position boule;
    t_position oiseau[3];
    t_position blocCassable[15];
    t_position blocPiege[7];
    t_position blocInvincible[15];
    t_position blocDisApa[5];
    t_position blocApousser[10];
    t_position gagnerVie[1];
    int niveau;
    int pause;
    char ancienCaractereBalle;
    t_position blocVie;
    char motsDePasse[50];

}t_plateau;
void clearBuffer();
void pause(t_plateau*terrain);
void traiterTousLesBlocs(t_plateau *terrain);
void afficherBlocPoussable(t_plateau* terrain);
void blocPoussable(t_plateau*terrain);
void deplacementBalle2(t_plateau *terrain, int nbBalles);
void effacerEcran();
void clearplateau();
void sauvegarderPlateau(t_plateau *terrain, char *nomFichier);
void initialiserPlateau(t_plateau*terrain);
void afficherPlateauFromFile(char *nomFichier);
void Deplacement(t_plateau *terrain);
void effacerConsole();
void DeplacementBoule(t_plateau *terrain, char direction);
void afficherPlateau();
void DeplacementAutoBoule(t_plateau *terrain);
void effacerZone(int debutLigne, int debutColonne, int finLigne, int finColonne);
void effacerCaractere(int ligne, int colonne);
void Menu();
void effacerPlateau(t_plateau *terrain);
void iniPlateau2(t_plateau *terrain);
void info_joueur(t_plateau*terrain,int x,int y, int *timerCount);
void Deplacement2(t_plateau *terrain);
void deplacerBalleSnoopy(terrain);
void gererCode(t_plateau *terrain);
void deplacementSnoopy(t_plateau *terrain);
void boucleDeJeu(t_plateau *terrain);
void boucleDeJeu(t_plateau *terrain);
void deplacementSnoopy(t_plateau *terrain);
void deplacementBalle(t_plateau *terrain);
void AfficherZone(int debutLigne, int debutColonne, int finLigne, int finColonne, t_plateau*terrain);
void switchcase(t_plateau*terrain);
void blocIncassable(t_plateau*terrain);
void deplacerBloc(t_plateau *terrain);
void demanderMotDePasseNiveau(int niveau, t_plateau *terrain);
int verifierMotDePasseNiveau(char *motDePasse, t_plateau *terrain);
void boucleDeJeuMotdepasse(t_plateau *terrain);
void afficherMenuPause();
void rechargerPlateauDepuisFichier(t_plateau *terrain, const char *nomFichier);
void blocPiege2(t_plateau* terrain);



#endif // PLATEAU_H_INCLUDED
