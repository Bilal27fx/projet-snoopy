#include "plateau.h"


void effacerPlateau(t_plateau *terrain) {
    for (int i = 0; i < Ligne; i++) {
        for (int j = 0; j < Colonne; j++) {
            terrain->caractere[i][j] = ' ';
            terrain->caractere_precedent[i][j] = ' '; // Réinitialisation du tableau de caractères précédents
        }
    }
}

void blocPiege(t_plateau* terrain) {
    for (int i = 0; i < 12; i++) {
        if (terrain->PositionSnoopy.x == terrain->blocPiege[i].x && terrain->PositionSnoopy.y == terrain->blocPiege[i].y) {
            terrain->vieSnoopy-=1;
            terrain->blocPiege[i] .x=-1;
            terrain->blocPiege[i] .y=-1;
        }
    }
}

void blocPiege2(t_plateau* terrain) {
    for (int i = 0; i < 12; i++) {
        if (terrain->PositionSnoopy.x == terrain->blocPiege[i].x && terrain->PositionSnoopy.y == terrain->blocPiege[i].y) {
            terrain->vieSnoopy-=2;
            terrain->blocPiege[i] .x=-1;
            terrain->blocPiege[i] .y=-1;
        }
    }
}

void blocIncassable(t_plateau*terrain)
{
    for(int i=0;i<10;i++)
    {
        if (terrain->PositionSnoopy.x==terrain->blocInvincible[i].x && terrain->PositionSnoopy.y==terrain->blocInvincible[i].y)
        {
            terrain->PositionSnoopy.x=terrain->PositionSnoopy_precedent.x;
            terrain->PositionSnoopy.y=terrain->PositionSnoopy_precedent.y;
            terrain->caractere[terrain->blocInvincible[i].x][terrain->blocInvincible[i].y]=0x0F;
            terrain->caractere[terrain->PositionSnoopy.x][terrain->PositionSnoopy.y]=0x01;
        }
    }
}

void gagnerVie(t_plateau*terrain)
{
    for(int i=0;i<2;i++)
    {
        if(terrain->PositionSnoopy.x==terrain->gagnerVie[i].x && terrain->PositionSnoopy.y==terrain->gagnerVie[i].y)
        {
            terrain->vieSnoopy+=1;
            terrain->gagnerVie[i].x=-1;
            terrain->gagnerVie[i].y=-1;

        }
    }

}


void deplacerBloc(t_plateau *terrain) {
    // Vérifier si Snoopy touche un bloc cassable
    for (int i = 0; i < 15; ++i) {
        if (terrain->PositionSnoopy.x == terrain->blocApousser[i].x && terrain->PositionSnoopy.y == terrain->blocApousser[i].y) {
            char directionUtilisateur;
            int deplacementX = 0, deplacementY = 0;
            gotoligcol(20,1);
            printf("Entrez la direction pour déplacer le bloc cassable (haut, bas, gauche, droite - 'z', 's', 'q', 'd') : ");
            scanf(" %c", &directionUtilisateur);
            effacerZone(19,1,21,120);

            // Calculer le déplacement en fonction de la direction choisie
            if (directionUtilisateur == 'z') {
                deplacementX = -1; // Vers le haut
            } else if (directionUtilisateur == 's') {
                deplacementX = 1; // Vers le bas
            } else if (directionUtilisateur == 'q') {
                deplacementY = -1; // Vers la gauche
            } else if (directionUtilisateur == 'd') {
                deplacementY = 1; // Vers la droite
            } else {
                printf("Direction invalide.\n");
                return; // Sortir de la fonction si la direction est invalide
            }

            // Déplacer le bloc cassable
            terrain->blocApousser[i].x += deplacementX;
            terrain->blocApousser[i].y += deplacementY;
            terrain->caractere[terrain->blocApousser[i].x][terrain->blocApousser[i].y]=0x16;
            return; // Sortir de la fonction après le déplacement du bloc cassable
        }
    }
}




void iniPlateau2(t_plateau *terrain) {
  effacerZone(0,0,60,60);

    for (int i = 0; i < Ligne; i++) {
        for (int j = 0; j < Colonne; j++) {
            if (i == 0 || i == Ligne - 1) {
                terrain->caractere[i][j] = '-';
            } else if (j == 0 || j == Colonne - 1) {
                terrain->caractere[i][j] = '|';
            } else {
                terrain->caractere[i][j] = ' ';
            }
            terrain->caractere_precedent[i][j] = ' '; // Réinitialisation du tableau de caractères précédents
        }
    }

    // Réinitialisation des autres valeurs de la structure
    terrain->PositionSnoopy.x = Ligne / 2;
    terrain->PositionSnoopy.y = Colonne / 2;
    terrain->caractere[terrain->PositionSnoopy.x][terrain->PositionSnoopy.y] = 0x01;
    terrain->boule.x = Ligne / 3;
    terrain->boule.y = Colonne / 2;
    terrain->caractere[terrain->boule.x][terrain->boule.y] = 0x0B;



    // Réinitialisation des oiseaux dans les coins
    terrain->oiseau[0].x = 1;
    terrain->oiseau[0].y = 1;
    terrain->caractere[terrain->oiseau[0].x][terrain->oiseau[0].y] = 0x0E;
    terrain->oiseau[1].x = 1;
    terrain->oiseau[1].y = Colonne - 2;
    terrain->caractere[terrain->oiseau[1].x][terrain->oiseau[1].y] = 0x0E;
    terrain->oiseau[2].x = Ligne - 2;
    terrain->oiseau[2].y = 1;
    terrain->caractere[terrain->oiseau[2].x][terrain->oiseau[2].y] = 0x0E;
    terrain->oiseau[3].x = Ligne - 2;
    terrain->oiseau[3].y = Colonne - 2;
    terrain->caractere[terrain->oiseau[3].x][terrain->oiseau[3].y] = 0x0E;



    // Bloc à droite
    terrain->blocCassable[1].x = terrain->PositionSnoopy.x;
    terrain->blocCassable[1].y = terrain->PositionSnoopy.y + 3;
    terrain->caractere[terrain->blocCassable[1].x][terrain->blocCassable[1].y] = 0x06;

    // Bloc en haut
    terrain->blocCassable[2].x = terrain->PositionSnoopy.x - 3;
    terrain->blocCassable[2].y = terrain->PositionSnoopy.y;
    terrain->caractere[terrain->blocCassable[2].x][terrain->blocCassable[2].y] = 0x06;

    // Bloc en bas
    terrain->blocCassable[3].x = terrain->PositionSnoopy.x + 3;
    terrain->blocCassable[3].y = terrain->PositionSnoopy.y;
    terrain->caractere[terrain->blocCassable[3].x][terrain->blocCassable[3].y] = 0x06;
    terrain->score = 0;
    Color(10,0);
    //Bloc piégé 1
    terrain->blocPiege[0].x=3;
    terrain->blocPiege[0].y=3;
    terrain->caractere[terrain->blocPiege[0].x][terrain->blocPiege[0].y]=0x05;
    //Bloc piégé 2
    terrain->blocPiege[1].x=12;
    terrain->blocPiege[1].y=27;
    terrain->caractere[terrain->blocPiege[1].x][terrain->blocPiege[1].y]=0x05;
     //Bloc piégé 3
    terrain->blocPiege[2].x=3;
    terrain->blocPiege[2].y=2;
    terrain->caractere[terrain->blocPiege[2].x][terrain->blocPiege[2].y]=0x05;
    //Bloc piégé 4
    terrain->blocPiege[3].x=5;
    terrain->blocPiege[3].y=27;
    terrain->caractere[terrain->blocPiege[3].x][terrain->blocPiege[3].y]=0x05;
    //Bloc piégé 5
     terrain->blocPiege[4].x=4;
    terrain->blocPiege[4].y=27;
    terrain->caractere[terrain->blocPiege[4].x][terrain->blocPiege[4].y]=0x05;
    //Bloc piégé 6
    terrain->blocPiege[5].x=12;
    terrain->blocPiege[5].y=3;
    terrain->caractere[terrain->blocPiege[5].x][terrain->blocPiege[5].y]=0x05;
     //Bloc piégé 7
    terrain->blocPiege[6].x=13;
    terrain->blocPiege[6].y=4;
    terrain->caractere[terrain->blocPiege[6].x][terrain->blocPiege[6].y]=0x05;
    //Bloc piégé 8
    terrain->blocPiege[7].x=26;
    terrain->blocPiege[7].y=13;
    terrain->caractere[terrain->blocPiege[7].x][terrain->blocPiege[7].y]=0x05;

    terrain->blocApousser[0].x=1;
    terrain->blocApousser[0].y=4;
    terrain->caractere[terrain->blocApousser[0].x][ terrain->blocApousser[0].y]=0x016;

     terrain->blocApousser[1].x=1;
    terrain->blocApousser[1].y=27;
    terrain->caractere[terrain->blocApousser[1].x][ terrain->blocApousser[1].y]=0x016;

     terrain->blocApousser[2].x=13;
    terrain->blocApousser[2].y=2;
    terrain->caractere[terrain->blocApousser[2].x][ terrain->blocApousser[2].y]=0x016;

     terrain->blocApousser[3].x=13;
    terrain->blocApousser[3].y=27;
    terrain->caractere[terrain->blocApousser[3].x][ terrain->blocApousser[3].y]=0x016;

    terrain->blocApousser[4].x=13;
    terrain->blocApousser[4].y=25;
    terrain->caractere[terrain->blocApousser[4].x][ terrain->blocApousser[4].y]=0x016;
    terrain->vieSnoopy=3;

}

