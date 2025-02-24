#include "plateau.h"
void Color(int couleurDuTexte,int couleurDeFond) // fonction d'affichage de couleurs
{
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}


void gotoligcol(int lig, int col){

    COORD mycoord;
    mycoord.X = col;

    mycoord.Y = lig;

    SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), mycoord );
}

void effacage_txt (int ligne, int colonne, char txt[])
{
    gotoligcol(ligne, colonne);
    Color(0, 0);
    Color(15, 0);
}

void initialiserPlateau(t_plateau *terrain){

    for (int i = 0; i < Ligne; i++)
    {
        for (int j = 0; j < Colonne; j++)
        {
            if (i == 0 || i == Ligne - 1)
            {
                terrain->caractere[i][j] = '-';

            }
            else if (j == 0 || j == Colonne - 1)
            {
                terrain->caractere[i][j] = '|';
            }
            else
            {
                terrain->caractere[i][j] = ' ';
            }
        }
    }

    terrain->PositionSnoopy.x=Ligne/2;
    terrain->PositionSnoopy.y=Colonne/2;
    terrain->caractere[terrain->PositionSnoopy.x][terrain->PositionSnoopy.y]= 0x01;
    terrain->boule.x=Ligne/3;
    terrain->boule.y=Colonne/2;
    terrain->caractere[terrain->boule.x][terrain->boule.y] = 0x0B ;
    terrain->vieSnoopy=3;
    // Initialisation des oiseaux dans les coins
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
    terrain->score=0;
    terrain->caractere[terrain->boule.x][terrain->boule.y]=0x0B;
    //Bloc invincible
    terrain->blocInvincible[0].x=1;
    terrain->blocInvincible[0].y=3;
    terrain->caractere[terrain->blocInvincible[0].x][terrain->blocInvincible[0].y]=0x0F;

    terrain->blocInvincible[1].x=1;
    terrain->blocInvincible[1].y=27;
    terrain->caractere[terrain->blocInvincible[1].x][terrain->blocInvincible[1].y]=0x0F;

    terrain->blocInvincible[2].x=13;
    terrain->blocInvincible[2].y=3;
    terrain->caractere[terrain->blocInvincible[2].x][terrain->blocInvincible[2].y]=0x0F;

    terrain->blocInvincible[3].x=12;
    terrain->blocInvincible[3].y=25;
    terrain->caractere[terrain->blocInvincible[3].x][terrain->blocInvincible[3].y]=0x0F;

    terrain->blocInvincible[4].x=3;
    terrain->blocInvincible[4].y=1;
    terrain->caractere[terrain->blocInvincible[4].x][terrain->blocInvincible[4].y]=0x0F;

    terrain->blocCassable[1].x=3;
    terrain->blocCassable[1].y=3;
    terrain->caractere[terrain->blocCassable[1].x][terrain->blocCassable[1].y]=0X06;

    terrain->blocCassable[2].x=2;
    terrain->blocCassable[2].y=3;
    terrain->caractere[terrain->blocCassable[2].x][terrain->blocCassable[2].y]=0X06;

    terrain->blocCassable[3].x=3;
    terrain->blocCassable[3].y=2;
    terrain->caractere[terrain->blocCassable[3].x][terrain->blocCassable[3].y]=0X06;

    terrain->blocCassable[4].x=3;
    terrain->blocCassable[4].y=27;
    terrain->caractere[terrain->blocCassable[4].x][terrain->blocCassable[4].y]=0X06;

    terrain->blocCassable[5].x=3;
    terrain->blocCassable[5].y=28;
    terrain->caractere[terrain->blocCassable[5].x][terrain->blocCassable[5].y]=0X06;

    terrain->blocCassable[6].x=2;
    terrain->blocCassable[6].y=27;
    terrain->caractere[terrain->blocCassable[6].x][terrain->blocCassable[6].y]=0X06;

    terrain->blocCassable[7].x=3;
    terrain->blocCassable[7].y=15;
    terrain->caractere[terrain->blocCassable[7].x][terrain->blocCassable[7].y]=0X06;

    terrain->blocCassable[8].x=4;
    terrain->blocCassable[8].y=15;
    terrain->caractere[terrain->blocCassable[8].x][terrain->blocCassable[8].y]=0X06;

    terrain->blocCassable[9].x=5;
    terrain->blocCassable[9].y=15;
    terrain->caractere[terrain->blocCassable[9].x][terrain->blocCassable[9].y]=0X06;

     terrain->blocCassable[14].x=6;
    terrain->blocCassable[14].y=15;
    terrain->caractere[terrain->blocCassable[14].x][terrain->blocCassable[14].y]=0X06;


    terrain->blocCassable[10].x=10;
    terrain->blocCassable[10].y=15;
    terrain->caractere[terrain->blocCassable[10].x][terrain->blocCassable[10].y]=0X06;

    terrain->blocCassable[11].x=11;
    terrain->blocCassable[11].y=15;
    terrain->caractere[terrain->blocCassable[11].x][terrain->blocCassable[11].y]=0X06;

    terrain->blocCassable[12].x=12;
    terrain->blocCassable[12].y=15;
    terrain->caractere[terrain->blocCassable[12].x][terrain->blocCassable[12].y]=0X06;

    terrain->blocCassable[13].x=13;
    terrain->blocCassable[13].y=15;
    terrain->caractere[terrain->blocCassable[13].x][terrain->blocCassable[13].y]=0X06;

    terrain->blocApousser[0].x=7;
    terrain->blocApousser[0].y=18;
    terrain->caractere[terrain->blocApousser[0].x][terrain->blocApousser[0].y]=0X16;

    terrain->blocApousser[1].x=7;
    terrain->blocApousser[1].y=13;
    terrain->caractere[terrain->blocApousser[1].x][terrain->blocApousser[1].y]=0X16;

    terrain->gagnerVie[0].x=12;
    terrain->gagnerVie[0].y=3;
    terrain->caractere[terrain->gagnerVie[0].x][terrain->gagnerVie[0].y]='+';

    terrain->gagnerVie[1].x=11;
    terrain->gagnerVie[1].y=24;
    terrain->caractere[terrain->gagnerVie[1].x][terrain->gagnerVie[1].y]='+';

}

void effacerZone(int debutLigne, int debutColonne, int finLigne, int finColonne) {
    for (int i = debutLigne; i <= finLigne; i++) {
        gotoligcol(i, debutColonne); // Positionner le curseur au début de la ligne
        for (int j = debutColonne; j <= finColonne; j++) {
            printf(" "); // Imprimer des espaces pour effacer la zone
        }
    }
}

void AfficherZone(int debutLigne, int debutColonne, int finLigne, int finColonne, t_plateau*terrain) {
    for (int i = debutLigne; i <= finLigne; i++) {
        gotoligcol(i, debutColonne); // Positionner le curseur au début de la ligne
        for (int j = debutColonne; j <= finColonne; j++) {
           printf("%c",terrain->caractere[i][j]);
        }
    }
}

void effacerCaractere(int ligne, int colonne) {
    gotoligcol(ligne, colonne); // Positionner le curseur à la position spécifique
    printf(" "); // Imprimer un espace pour effacer le caractère à cette position
}



void afficherPlateau(t_plateau *terrain) {
    for (int i = 0; i < Ligne; i++) {
        for (int j = 0; j < Colonne; j++) {
            // Vérifier si le caractère a changé
            if (terrain->caractere[i][j] != terrain->caractere_precedent[i][j]) {
                gotoligcol(i, j); // Déplacer le curseur à la position
                printf("%c", terrain->caractere[i][j]); // Afficher le caractère
                terrain->caractere_precedent[i][j] = terrain->caractere[i][j]; // Mettre à jour la copie du caractère précédent
            }
        }
    }

}

void rechargerPlateauDepuisFichier(t_plateau *terrain, const char *nomFichier) {
    FILE *fichier = fopen(nomFichier, "r");
    if (fichier != NULL) {
        for (int i = 0; i < Ligne; i++) {
            for (int j = 0; j < Colonne; j++) {
                fscanf(fichier, " %c", &(terrain->caractere[i][j]));
            }
        }
        fclose(fichier);
    } else {
        printf("Impossible d'ouvrir le fichier %s pour la recharge du plateau.\n", nomFichier);
    }
}


void sauvegarderPlateau(t_plateau *terrain,  char *nomFichier) {
    FILE *fichier = fopen(nomFichier, "w");
    if (fichier != NULL) {
        for (int i = 0; i < Ligne; i++) {
            for (int j = 0; j < Colonne; j++) {
                fprintf(fichier, "%c", terrain->caractere[i][j]);
            }
             fprintf(fichier, "\n");
        }


        fclose(fichier);

        //afficherPlateauFromFile(nomFichier); // Afficher le contenu du fichier après chaque sauvegarde
    } else {
        printf("Impossible d'ouvrir le fichier %s pour l'enregistrement.\n", nomFichier);
    }
}

void info_joueur(t_plateau*terrain,int x,int y, int *timerCount)
{
    gotoligcol(x,y);
    Color(12,0);
     printf("Timer : %d \n", 120 - *timerCount); // Affiche le temps restant
    gotoligcol(x+1,y);
    printf("NombreVie : ");
     Color(15,0);
    printf("%d\n",terrain->vieSnoopy);
    Color(12,0);
    gotoligcol(x+2,y);
    printf("ScoreSnoopy : ");
     Color(15,0);
    printf("%d",terrain->score);

}


void deplacementBalle(t_plateau *terrain) {
    static int direction_x = 1; // Utilisation du mot-clé static pour conserver la direction entre les appels
    static int direction_y = 1;

    terrain->caractere[terrain->boule.x][terrain->boule.y] = ' ';


    int new_x = terrain->boule.x + direction_x;
    int new_y = terrain->boule.y + direction_y;


    // Vérifier les limites du plateau pour le rebondissement de la balle
    if (new_x >= Ligne - 1 || new_x <= 0) {
        direction_x = -direction_x;
    }

    if (new_y >= Colonne - 1 || new_y <= 0) {
        direction_y = -direction_y;
    }


   for (int i = 0; i < 15; ++i) {
        if (new_x == terrain->blocCassable[i].x && new_y == terrain->blocCassable[i].y) {
            // Si la destination est un bloc cassable, changer la direction sans déplacer la balle
            direction_x = -direction_x;
            direction_y = -direction_y;
            return;
        }
    }


    for (int i = 0; i < 4; ++i) {
        // Faites quelque chose avec blocPoussable[i]
        if (new_x == terrain->blocApousser[i].x && new_y == terrain->blocApousser[i].y) {
            // Si la destination est un bloc cassable, changer la direction sans déplacer la balle
            direction_x = -direction_x;
            direction_y = -direction_y;
            return;
        }
    }

    // Traiter les blocs pièges
    for (int i = 0; i < 7; ++i) {
        // Faites quelque chose avec blocPiege[i]
         if (new_x == terrain->blocPiege[i].x && new_y == terrain->blocPiege[i].y) {
            // Si la destination est un bloc cassable, changer la direction sans déplacer la balle
            direction_x = -direction_x;
            direction_y = -direction_y;
            return;
        }
    }

    // Traiter les blocs invincibles
    for (int i = 0; i < 5; ++i) {
        // Faites quelque chose avec blocInvincible[i]
         if (new_x == terrain->blocInvincible[i].x && new_y == terrain->blocInvincible[i].y) {
            // Si la destination est un bloc cassable, changer la direction sans déplacer la balle
            direction_x = -direction_x;
            direction_y = -direction_y;
            return;
        }
    }

    // Traiter les blocs qui disparaissent/aparaissent
    for (int i = 0; i < 5; ++i) {
        // Faites quelque chose avec blocDisApa[i]
         if (new_x == terrain->blocDisApa[i].x && new_y == terrain->blocDisApa[i].y) {
            // Si la destination est un bloc cassable, changer la direction sans déplacer la balle
            direction_x = -direction_x;
            direction_y = -direction_y;
            return;
        }
    }

    // Traiter les blocs qui peuvent être poussés
    for (int i = 0; i < 5; ++i) {
        // Faites quelque chose avec blocApousser[i]
         if (new_x == terrain->blocApousser[i].x && new_y == terrain->blocApousser[i].y) {
            // Si la destination est un bloc cassable, changer la direction sans déplacer la balle
            direction_x = -direction_x;
            direction_y = -direction_y;
            return;
        }
    }


    // Mettre à jour les nouvelles coordonnées après le rebondissement
    new_x = terrain->boule.x + direction_x;
    new_y = terrain->boule.y + direction_y;

    terrain->boule.x = new_x;
    terrain->boule.y = new_y;
    if (terrain->caractere[new_x][new_y] == ' ') {
        terrain->boule.x = new_x;
        terrain->boule.y = new_y;
    }
    // Réaffectation de la position de la balle sur le plateau
    terrain->caractere[terrain->boule.x][terrain->boule.y]=0x0B;



   if (terrain->boule.x == terrain->PositionSnoopy.x && terrain->boule.y == terrain->PositionSnoopy.y)
        {
            terrain->vieSnoopy -= 1;
        }

   if (terrain->PositionSnoopy.x == terrain->oiseau[0].x && terrain->PositionSnoopy.y == terrain->oiseau[0].y)
        {
            if (terrain->oiseau[0].x >= 0 && terrain->oiseau[0].y >= 0)
            {
                terrain->score += 1;
                terrain->oiseau[0].x = -1; // Marquer l'oiseau comme capturé en affectant des coordonnées hors limites
                terrain->oiseau[0].y = -1;
            }
        }
        if (terrain->PositionSnoopy.x == terrain->oiseau[1].x && terrain->PositionSnoopy.y == terrain->oiseau[1].y)
        {
            if (terrain->oiseau[1].x >= 0 && terrain->oiseau[1].y >= 0)
            {
                terrain->score += 1;
                terrain->oiseau[1].x = -1; // Marquer l'oiseau comme capturé en affectant des coordonnées hors limites
                terrain->oiseau[1].y = -1;
            }
        }
        if (terrain->PositionSnoopy.x == terrain->oiseau[2].x && terrain->PositionSnoopy.y == terrain->oiseau[2].y)
        {
            if (terrain->oiseau[2].x >= 0 && terrain->oiseau[2].y >= 0)
            {
                terrain->score += 1;
                terrain->oiseau[2].x = -1; // Marquer l'oiseau comme capturé en affectant des coordonnées hors limites
                terrain->oiseau[2].y = -1;
            }
        }
        if (terrain->PositionSnoopy.x == terrain->oiseau[3].x && terrain->PositionSnoopy.y == terrain->oiseau[3].y)
        {
            if (terrain->oiseau[3].x >= 0 && terrain->oiseau[3].y >= 0)
            {
                terrain->score += 1;
                terrain->oiseau[3].x = -1; // Marquer l'oiseau comme capturé en affectant des coordonnées hors limites
                terrain->oiseau[3].y = -1;
            }
        }



    sauvegarderPlateau(terrain, "plateau.txt");
   //AfficherZone(0,0,14,29,terrain);

}

void deplacementSnoopy(t_plateau *terrain) {
    char direction;
    int x,y;
    terrain->Position_nouveau.x=terrain->PositionSnoopy.x;
    terrain->Position_nouveau.y=terrain->PositionSnoopy.y;

    terrain->PositionSnoopy_precedent.x=terrain->PositionSnoopy.x;
    terrain->PositionSnoopy_precedent.y=terrain->PositionSnoopy.y;



    if (_kbhit()) {
        direction = _getch();
        terrain->caractere[terrain->PositionSnoopy.x][terrain->PositionSnoopy.y] = ' ';

            if (direction == 'z' && terrain->PositionSnoopy.x > 1) {
                terrain->PositionSnoopy.x = terrain->PositionSnoopy.x - 1;
            } else if (direction == 's' && terrain->PositionSnoopy.x < Ligne - 2) {
                terrain->PositionSnoopy.x = terrain->PositionSnoopy.x + 1;
            } else if (direction == 'q' && terrain->PositionSnoopy.y > 1) {
                terrain->PositionSnoopy.y = terrain->PositionSnoopy.y - 1;
            } else if (direction == 'd' && terrain->PositionSnoopy.y < Colonne - 2) {
                terrain->PositionSnoopy.y = terrain->PositionSnoopy.y + 1;
            }

            terrain->caractere[terrain->PositionSnoopy.x][terrain->PositionSnoopy.y] = 0x01;
            sauvegarderPlateau(terrain, "plateau.txt");

blocIncassable(terrain);
    }

}

void demanderMotDePasseNiveau(int niveau, t_plateau *terrain) {
    char motDePasseSaisi[MaxTailleMotDePasse];

    gotoligcol(20,1);
    printf("Veuillez entrer le mot de passe pour le niveau %d : ", niveau + 1);
    scanf("%s", motDePasseSaisi);

    if (strcmp(motDePasseSaisi, terrain->motsDePasse[niveau]) == 0) {
        printf("Mot de passe correct pour le niveau %d !\n", niveau + 1);
        // Faites quelque chose si le mot de passe est correct
        // Par exemple, lancez le niveau correspondant
    } else {
        printf("Mot de passe incorrect pour le niveau %d.\n", niveau + 1);
        // Faites quelque chose si le mot de passe est incorrect
        // Par exemple, revenez à un niveau précédent ou affichez un message d'erreur
    }
    effacerZone(0,0,60,120);
}
int verifierMotDePasseNiveau(char *motDePasse, t_plateau *terrain) {
    for (int niveau = 0; niveau < NombreNiveaux; ++niveau) {
        if (strcmp(motDePasse, terrain->motsDePasse[niveau]) == 0) {
            return niveau; // Retourne le niveau correspondant au mot de passe
        }
    }
    return -1; // Retourne -1 si le mot de passe est incorrect
}




void boucleDeJeu(t_plateau *terrain) {
    int timerCount = 0;
    time_t startTime = time(NULL);
    int niveauActuel = 0; // Niveau actuel du jeu
    int scorePrecedent = terrain->score;




    while (terrain->vieSnoopy > 0 && timerCount < 120 && niveauActuel <= 3) {

        deplacementBalle(terrain);
        deplacementSnoopy(terrain);
        blocPiege(terrain);

        gagnerVie(terrain);
        deplacerBloc(terrain);
       afficherPlateau(terrain);
        info_joueur(terrain, 2, 35, &timerCount);
         if (_kbhit()) {
            char c = _getch();
            if (c == 'g') {
                pause(terrain); // Afficher le menu pause
            }
        }

        // Vérification du score pour changer de niveau
        if (niveauActuel==0 && terrain->score==4) {
            niveauActuel++;
            //demanderMotDePasseNiveau(niveauActuel,terrain);
            Color(10,0);
            gotoligcol(20,30);
            printf("Bravo, vous avez atteint le niveau 2  ");
            usleep(2000000);
            effacerZone(20,30,20,80);
            iniPlateau2(terrain);
            timerCount=0;
            deplacementBalle(terrain);
            blocPiege(terrain);
            gagnerVie(terrain);
            deplacerBloc(terrain);
            deplacementSnoopy(terrain);
            info_joueur(terrain, 2, 35, &timerCount);
            scorePrecedent = terrain->score;

        } if (niveauActuel == 1 && terrain->score == 4) {
            niveauActuel++;
           // demanderMotDePasseNiveau(niveauActuel,terrain);
            Color(12,0);
            gotoligcol(20,30);
            printf("Bravo, vous avez atteint le niveau 3 ");
            usleep(2000000);
            effacerZone(20,30,20,80);
            iniPlateau3(terrain);
            timerCount=0;
            deplacementBalle(terrain);
            blocPiege(terrain);
            gagnerVie(terrain);
            deplacerBloc(terrain);
            deplacementSnoopy(terrain);
            info_joueur(terrain, 2, 35, &timerCount);
            scorePrecedent = terrain->score;

        }if (niveauActuel == 2 && terrain->score == 4) {
           // demanderMotDePasseNiveau(niveauActuel,terrain);

            Color(8,0);
            gotoligcol(20,30);
            printf("Bravo, vous avez atteint le niveau 4");
            usleep(2000000);
            effacerZone(20,30,20,80);
            iniPlateau3(terrain);
            timerCount=0;
            deplacementBalle(terrain);
            gagnerVie(terrain);
            blocPiege(terrain);
            deplacerBloc(terrain);
            deplacementSnoopy(terrain);
            info_joueur(terrain, 2, 35, &timerCount);
            scorePrecedent = terrain->score;
            niveauActuel++;

        }

 Sleep(100);
        time_t currentTime = time(NULL);
        if (difftime(currentTime, startTime) >= 1.0) {
            timerCount++;
            startTime = currentTime;
        // ...
    }
    }

    gotoligcol(30,40);
    printf("Game over\n");
    system("cls");
    usleep(2000000);
    niveauActuel=0;
    effacerZone(0, 0, 60, 60);
    Menu(terrain);


}


void boucleDeJeu2(t_plateau *terrain) {
    int timerCount = 0;
    time_t startTime = time(NULL);
    int niveauActuel = 0; // Niveau actuel du jeu
    int scorePrecedent = terrain->score;




    while (terrain->vieSnoopy > 0 && timerCount < 120 && niveauActuel <= 3) {

        deplacementBalle(terrain);
        deplacementSnoopy(terrain);
        blocPiege(terrain);

        gagnerVie(terrain);
        deplacerBloc(terrain);
       afficherPlateau(terrain);
        info_joueur(terrain, 2, 35, &timerCount);
         if (_kbhit()) {
            char c = _getch();
            if (c == 'g') {
                pause(terrain); // Afficher le menu pause
            }
        }

        // Vérification du score pour changer de niveau
        if (niveauActuel==0 && terrain->score==4) {
            niveauActuel++;
            demanderMotDePasseNiveau(niveauActuel,terrain);
            Color(10,0);
            gotoligcol(20,30);
            printf("Bravo, vous avez atteint le niveau 2  ");
            usleep(2000000);
            effacerZone(20,30,20,80);
            iniPlateau2(terrain);
            timerCount=0;
            deplacementBalle(terrain);
            blocPiege(terrain);
            gagnerVie(terrain);
            deplacerBloc(terrain);
            deplacementSnoopy(terrain);
            info_joueur(terrain, 2, 35, &timerCount);
            scorePrecedent = terrain->score;

        } if (niveauActuel == 1 && terrain->score == 4) {
            niveauActuel++;
            demanderMotDePasseNiveau(niveauActuel,terrain);
            Color(12,0);
            gotoligcol(20,30);
            printf("Bravo, vous avez atteint le niveau 3 ");
            usleep(2000000);
            effacerZone(20,30,20,80);
            iniPlateau2(terrain);
            timerCount=0;
            deplacementBalle(terrain);
            blocPiege2(terrain);
            gagnerVie(terrain);
            deplacerBloc(terrain);
            deplacementSnoopy(terrain);
            info_joueur(terrain, 2, 35, &timerCount);
            scorePrecedent = terrain->score;

        }if (niveauActuel == 2 && terrain->score == 4) {
            demanderMotDePasseNiveau(niveauActuel,terrain);

            Color(8,0);
            gotoligcol(20,30);
            printf("Bravo, vous avez atteint le niveau 4");
            usleep(2000000);
            effacerZone(20,30,20,80);
            iniPlateau2(terrain);
            timerCount=0;
            deplacementBalle(terrain);
            gagnerVie(terrain);
            blocPiege2(terrain);
            deplacerBloc(terrain);
            deplacementSnoopy(terrain);
            info_joueur(terrain, 2, 35, &timerCount);
            scorePrecedent = terrain->score;
            niveauActuel++;

        }

 Sleep(100);
        time_t currentTime = time(NULL);
        if (difftime(currentTime, startTime) >= 1.0) {
            timerCount++;
            startTime = currentTime;
        // ...
    }
    }

    gotoligcol(30,40);
    printf("Game over\n");
    system("cls");
    usleep(2000000);
    niveauActuel=0;
    effacerZone(0, 0, 60, 60);
    boucleDeJeu(terrain);


}




