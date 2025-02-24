
#include "plateau.h"


void loadingBar(){
    //modepass1();
    // 0 - black background,
    // D - purple Foreground
    system("color 0D");

    // Initialize char for printing
    // loading bar
    char a = 177, b = 219, c = 201, d = 200,  e = 205, f = 188, g = 187;

    printf("\n\n\n\n");
    printf("\n\n\n\n\t\t\t\t\t");
    gotoligcol(100, 500);
    printf("Chargement du jeu...\n\n");
    printf("\t\t\t\t\t");



    //Fond barre de progression
    gotoligcol(100, 500);
    for (int i = 0; i < 26; i++){
        printf("%c", a);
    }


    //Remettre le curseur au point de d�part
    //Situer la barre de chargement
    printf("\r");
    printf("\t\t\t\t\t");

    //Chargement barre de pogression
    gotoligcol(100, 500);
    for (int i = 0; i < 26; i++)
    {
        printf("%c", b);

        //Vitesse de chargement
        Sleep(150);
    }
    system("cls");
}



void reglessnoopy(){
    printf("Regles Snoopy : \n"
           "\n"
           "Snoopy a pour objectif de récupérer quatre oiseaux situés aux quatre coins du niveau, le tout dans un laps de temps défini de deux minutes par niveau. Cependant, récupérer ces oiseaux n'est pas une tâche aisée, car une balle rebondit en permanence dans le niveau, entravant les efforts de Snoopy dans sa quête.\n"
           "  \n"
           "Snoopy doit franchir d'autres obstacles tels que des téléporteurs utilisés par la balle, des cases piégées, voire même des blocs qu'il doit pousser ou briser.\n"
           "\n"
           "La balle se déplace exclusivement en diagonale, rebondissant uniquement sur les murs, c'est-à-dire les bords de la matrice. Sa vitesse reste constante. La balle traverse tous les obstacles du terrain sans changer de direction, mais elle met fin à la quête de Snoopy en le \"tuant\" dès qu'elle le touche.\n"
           "\n"
           "Snoopy ne peut pas se déplacer en diagonale. Il ne peut se déplacer que dans les 4 directions classiques\n"
           "(Haut, Bas, Gauche et Droite) et d'une seule case à la fois.\n"
           "\n"
           "Au départ, le joueur dispose de 3 vies. Chaque niveau doit être complété en moins de 120 secondes. En cas d'expiration du temps imparti, le joueur perd une vie et recommence le niveau. L'objectif consiste à récupérer les 4 oiseaux du niveau sans être touché par la balle et/ou les ennemis, s'ils sont présents.\n"
           "\n"
           "Pour gagner, il faut récupérer les 4 oiseaux du niveau. Un fois un niveau terminé, on charge\n"
           "automatiquement le niveau suivant en donnant son code d’accès et ainsi de suite.\n"
           "Quand le joueur perd toutes ses vies, on affiche un écran de GameOver et le jeu revient au menu\n"
           "principal.\n"
           "\n"
           "Pour gagner, il faut récuperer les 4 oiseaux du niveau. Une fois qu'un niveau est réussi, le niveau suivant se charge automatiquement à l'aide de son code d'accès, et ainsi de suite. En cas de perte de toutes ses vies, le jeu affiche un écran Game Over et retourne au menu principal.");

}


void afficherMenuPause() {

    gotoligcol(20,40);
    printf("=== MENU PAUSE ===\n");
    gotoligcol(21,40);
    printf("1. Reprendre\n");
    gotoligcol(22,40);
    printf("2. Sauvegarder\n");
    gotoligcol(23,40);
    printf("3. Quitter\n");
    gotoligcol(24,40);
    printf("Entrez votre choix : ");
}

// Fonction pour gérer la pause
void pause(t_plateau *terrain) {
    char choix;
    bool enPause = true;
    char sauvegarde[50];

    while (enPause) {
        afficherMenuPause();
        choix = _getch();

        switch (choix) {
            case '1':
                enPause = false; // Sortir de la boucle de pause

                break;
            case '2':
                gotoligcol(26,30);
                printf("saisissez le nom de votre sauvegarde : ");
                scanf("%s",sauvegarde);
                sauvegarderPlateau(terrain, "plateau2");
                effacerZone(26,0,27,120);
                break;
            case '3':
                system("cls");
                effacerZone(0,0,60,120);
                Menu(terrain);


        }
    }
}

void Menu(t_plateau*terrain){
    //modepass();
    int choix;
    do{
        Color(2,0);
        gotoligcol(10,35);
        printf("===========MENU PRINCIPAL=========\n");

        Color(14,0);
        gotoligcol(12,35);
        printf("1.LANCER UNE NOUVELLE PARTIE  \n");
        gotoligcol(14,35);
        printf("2.CHARGER UNE PARTIE A PARTIR D UN NIVEAU   \n");
        gotoligcol(16,35);
        printf("3.SAUVEGARDER UNE PARTIE  \n");
        gotoligcol(18,35);
        printf("4.AFFICHER LES REGLES DU JEU  \n");
        gotoligcol(20,35);
        printf("Pour revenir au menu principal pendant la partie en cours, Entrez 9 \n");
        Color(15, 0);
        gotoligcol(22,35);
        printf("Saisissez votre choix(1-4):");
        scanf("%d",&choix);
    }while(choix < 1 || choix>4);
    switch(choix)
    {
        case 1:
            system("cls");
            loadingBar();
            Color(15,0);
            initialiserPlateau(terrain);
            boucleDeJeu(terrain);
            printf("\n");
            break;
        case 2:
            effacerZone(0,0,60,120);
            char motDePasseSaisi[MaxTailleMotDePasse];

    printf("Veuillez entrer le mot de passe pour accéder directement à un niveau : ");
    scanf("%s", motDePasseSaisi);

    int niveauSouhaite = verifierMotDePasseNiveau(motDePasseSaisi, terrain);

    if (niveauSouhaite != -1) {
        printf("Mot de passe correct pour le niveau %d ! Passage au niveau.\n", niveauSouhaite + 1);
        // Faites quelque chose pour lancer le niveau souhaité (initialisation, etc.)
        // Utilisez la valeur de 'niveauSouhaite' pour charger le niveau correspondant

        // Par exemple :
        if (niveauSouhaite == 0) {
            // Initialisation du niveau 1
            initialiserPlateau(terrain);
        } else if (niveauSouhaite == 1) {
            // Initialisation du niveau 2
           iniPlateau2(terrain);
        }
        // ... et ainsi de suite pour les autres niveaux

        boucleDeJeu(terrain); // Lancer la boucle de jeu pour le niveau choisi
    } else {
        printf("Mot de passe incorrect. Veuillez réessayer ou jouer normalement.\n");
        // Faites quelque chose pour gérer le cas où le mot de passe est incorrect (revenir à un niveau précédent ou afficher un message d'erreur)
        // Par exemple :
        Menu(terrain); // Retourner au menu principal ou à l'écran de sélection des niveaux
    }
    break;
            break;
        case 3:


            break;
        case 4:
            loadingBar();
            reglessnoopy();
            break;
    }


}
