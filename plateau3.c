#include "plateau.h"


void iniPlateau3(t_plateau *terrain) {
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

    terrain->blocPiege[8].x=25;
    terrain->blocPiege[8].y=13;
    terrain->caractere[terrain->blocPiege[8].x][terrain->blocPiege[8].y]=0x05;

    terrain->blocPiege[9].x=10;
    terrain->blocPiege[9].y=27;
    terrain->caractere[terrain->blocPiege[9].x][terrain->blocPiege[9].y]=0x05;

    terrain->blocPiege[10].x=11;
    terrain->blocPiege[10].y=27;
    terrain->caractere[terrain->blocPiege[10].x][terrain->blocPiege[10].y]=0x05;

    terrain->blocPiege[11].x=9;
    terrain->blocPiege[11].y=27;
    terrain->caractere[terrain->blocPiege[11].x][terrain->blocPiege[11].y]=0x05;


    terrain->blocInvincible[0].x=6;
    terrain->blocInvincible[0].y=13;
    terrain->caractere[terrain->blocInvincible[0].x][terrain->blocInvincible[0].y]=0x0F;

     terrain->blocInvincible[1].x=6;
    terrain->blocInvincible[1].y=14;
    terrain->caractere[terrain->blocInvincible[1].x][terrain->blocInvincible[1].y]=0x0F;

     terrain->blocInvincible[2].x=6;
    terrain->blocInvincible[2].y=15;
    terrain->caractere[terrain->blocInvincible[2].x][terrain->blocInvincible[2].y]=0x0F;

     terrain->blocInvincible[3].x=6;
    terrain->blocInvincible[3].y=16;
    terrain->caractere[terrain->blocInvincible[3].x][terrain->blocInvincible[3].y]=0x0F;

     terrain->blocInvincible[4].x=6;
    terrain->blocInvincible[4].y=17;
    terrain->caractere[terrain->blocInvincible[4].x][terrain->blocInvincible[4].y]=0x0F;

     terrain->blocInvincible[5].x=6;
    terrain->blocInvincible[5].y=22;
    terrain->caractere[terrain->blocInvincible[5].x][terrain->blocInvincible[5].y]=0x0F;

     terrain->blocInvincible[6].x=7;
    terrain->blocInvincible[6].y=22;
    terrain->caractere[terrain->blocInvincible[6].x][terrain->blocInvincible[6].y]=0x0F;

     terrain->blocInvincible[7].x=8;
    terrain->blocInvincible[7].y=22;
    terrain->caractere[terrain->blocInvincible[7].x][terrain->blocInvincible[7].y]=0x0F;

     terrain->blocInvincible[8].x=9;
    terrain->blocInvincible[8].y=22;
    terrain->caractere[terrain->blocInvincible[8].x][terrain->blocInvincible[8].y]=0x0F;

    terrain->blocInvincible[9].x=9;
    terrain->blocInvincible[9].y=15;
    terrain->caractere[terrain->blocInvincible[9].x][terrain->blocInvincible[9].y]=0X06;

    terrain->blocInvincible[10].x=10;
    terrain->blocInvincible[10].y=15;
    terrain->caractere[terrain->blocInvincible[10].x][terrain->blocInvincible[10].y]=0X06;

    terrain->blocInvincible[11].x=11;
    terrain->blocInvincible[11].y=15;
    terrain->caractere[terrain->blocInvincible[11].x][terrain->blocInvincible[11].y]=0X06;

    terrain->blocInvincible[12].x=12;
    terrain->blocInvincible[12].y=15;
    terrain->caractere[terrain->blocInvincible[12].x][terrain->blocInvincible[12].y]=0X06;

    terrain->blocInvincible[13].x=13;
    terrain->blocInvincible[13].y=15;
    terrain->caractere[terrain->blocInvincible[13].x][terrain->blocInvincible[13].y]=0X06;

     terrain->blocApousser[0].x=10;
    terrain->blocApousser[0].y=13;
    terrain->caractere[terrain->blocApousser[0].x][terrain->blocApousser[0].y]=0x16;

     terrain->blocApousser[1].x=10;
    terrain->blocApousser[1].y=14;
    terrain->caractere[terrain->blocApousser[1].x][terrain->blocApousser[1].y]=0x16;

     terrain->blocApousser[2].x=10;
    terrain->blocApousser[2].y=15;
    terrain->caractere[terrain->blocApousser[2].x][terrain->blocApousser[2].y]=0x16;

     terrain->blocInvincible[3].x=10;
    terrain->blocInvincible[3].y=16;
    terrain->caractere[terrain->blocInvincible[3].x][terrain->blocInvincible[3].y]=0x16;

     terrain->blocApousser[4].x=10;
    terrain->blocApousser[4].y=17;
    terrain->caractere[terrain->blocApousser[4].x][terrain->blocApousser[4].y]=0x16;

     terrain->blocApousser[5].x=10;
    terrain->blocApousser[5].y=17;
    terrain->caractere[terrain->blocApousser[5].x][terrain->blocApousser[5].y]=0x16;

     terrain->blocApousser[6].x=6;
    terrain->blocApousser[6].y=13;
    terrain->caractere[terrain->blocApousser[6].x][terrain->blocApousser[6].y]=0x16;

     terrain->blocApousser[7].x=7;
    terrain->blocApousser[7].y=13;
    terrain->caractere[terrain->blocApousser[7].x][terrain->blocApousser[7].y]=0x16;

     terrain->blocApousser[8].x=8;
    terrain->blocApousser[8].y=13;
    terrain->caractere[terrain->blocApousser[8].x][terrain->blocApousser[8].y]=0x16;

     terrain->blocApousser[10].x=9;
    terrain->blocApousser[10].y=13;
    terrain->caractere[terrain->blocApousser[10].x][terrain->blocApousser[10].y]=0x16;

    terrain->blocApousser[11].x=2;
    terrain->blocApousser[1].y=27;
    terrain->caractere[terrain->blocApousser[11].x][terrain->blocApousser[11].y]=0x16;

    terrain->blocApousser[12].x=2;
    terrain->blocApousser[12].y=28;
    terrain->caractere[terrain->blocApousser[12].x][terrain->blocApousser[12].y]=0x16;

    terrain->blocApousser[13].x=3;
    terrain->blocApousser[13].y=28;
    terrain->caractere[terrain->blocApousser[13].x][terrain->blocApousser[13].y]=0x16;

    terrain->blocApousser[14].x=4;
    terrain->blocApousser[14].y=28;
    terrain->caractere[terrain->blocApousser[14].x][terrain->blocApousser[14].y]=0x16;













}

