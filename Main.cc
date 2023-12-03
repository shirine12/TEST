#include <stdio.h>
#include "LIBRAIRIE SS PROG.h"
#include <windows.h>
#include <conio.h>
#include <unistd.h>
#include <time.h>

int main() {
        //Mise en place des niveaux
        unsigned char tabNiv1[Nc][Nl] = {
                " 0                 0",
                "                    ",
                "                    ",
                "                    ",
                "                    ",
                "                    ",
                "                    ",
                "                    ",
                "                    ",
                " 0                 0",
        };

        typedef struct Partie {
            int Score1, Score2, Score3, Niv, t, Vie;
            char MDP;
        } Partie;

        int A;
        int P;
        int G = 0;
        int Ret = 0;
        int x, y;
        int Vie;
        int NIV=1;
        int choixmdp;
        int retour1;
        int retour2;
        int retour3;
        int retour4;
        int mdp;
        int niv=0;

        int ScoreP1[4];
int ScoreP2[4];
int ScoreP3[4];
int ScoreP4[4];

int PartieP1[6];
int PartieP2[6];
int PartieP3[6];
int PartieP4[6];
        int T=120;
                    int Z=0;

        //Début du jeu
        do {

            menu();
            scanf("%d", &A);
            //if (kbhit()) {
            switch (A) {


                case 1 :
                    while (Ret < 1) {
                        printf("Les regles sont les suivantes :\n"
                               "Pour avancer, appuyez sur z.\n"
                               "Pour reculer, appuyez sur s.\n"
                               "Pour aller vers la gauche, appuyez sur s.\n"
                               "Pour aller vers la droite, appuyez sur d.\n"
                               "Appuyer sur P pour mettre pause.\n"
                               "Appuyer sur k pour casser les blocs cassables.\n"
                               "Appuyer sur m pour sauvegarder la progression. \n\n\n");
                        printf("Ceci est la balle : %c\n", 0x9D);
                        printf("Ceci est un bloc non poussable : %c\n", 0xCE);
                        printf("Ceci est un bloc qui tue : %c\n", 0xB2);
                        printf("Ceci un bloc cassable : %c\n", 0xFE);
                        printf("\nAppuyer sur 1 pour retourner au menu .\n");

                        scanf("%d", &Ret);
                        if (Ret != 1) {
                            printf("Ce n'est pas le bon bouton!\n");
                        }
                    }
                    break;

                case 2:

                    do {
                        system("cls");
                        printf("Veuillez entrer un mot de passe. Si le mot de passe correspond à un niveau, vous y serez redirigé.\n");
                        scanf("%d", &mdp);

                        switch (mdp) {
                            case 3411:
                                NIV = 1;
                                niv = 1;
                                    P=1;
                                break;
                            case 8574:
                                NIV = 2;
                                niv = 2;
                                    P=2;
                                   
                                break;
                            case 9251:
                                NIV = 3;
                                niv = 3;
                                    P=3;
                                
                                break;
                            case 7719:
                                NIV = 4;
                                niv = 4;
                                    P=4;
                                  
                                break;
                            default:
                                printf("Mot de passe incorrect. Veuillez réessayer.\n");
                                break;
                        }
                    } while (niv == 0);


                case 3 :
                    printf("Commencez votre aventure! Bienvenue sur le Niveau 1.\n"
                           "Enregistrer cette partie dans un des slots disponible.\n"
                           "Appuyer sur Z pour confirmer (il vous faudra sauvegarder dans le menu pause, sinon vous perdrez vos progres).\n");

                    int S = 0;
                    char touche;
                    int balleX = 5;
                    int balleY = 7;
                    int vx;
                    int vy;
                    int valid;

                    //Initialisation de Snoopy et la direction de la balle
                    int x, y;
                    int Score1;
                    int block;
                    int block2=0;
                    int block3=0;
                    int stop=1;
                    if (NIV == 1) {
                        x = 4;
                        y = 9;
                        vx = 1;
                        vy = 1;
                    }
                    if (NIV == 2) {
                        x = 8;
                        y = 3;
                        vx = 1;
                        vy = 1;
                    }
                    if (NIV == 3) {
                        x = 4;
                        y = 11;
                        vx = 1;
                        vy = 1;
                    }
                    if(NIV==4){
                        x=9;
                        y=20;
                        vx=1;
                        vy=1;
                    }


                    FILE *Save = fopen("saveNiv", "w");
                    int x1 = x;
                    int y1 = y;
                    int Score11 = Score1;
                    int block1 = block;
                    int balleX1 = balleX;
                    int balleY1 = balleY;
                    if (Save == NULL) {
                        perror("Erreur lors de l'ouverture du fichier de sauvegarde");
                        return 1;
                    }

                    fscanf(Save, "%d %d %d %d %d ", &x1, &y1, &Score11, &balleX1, &balleY1);

                    fclose(Save);
                    x1 = x;
                    y1 = y;
                    Score11 = Score1;
                    block1 = block;
                    balleX1 = balleX;
                    balleY1 = balleY;


                    touche = 0;
                    system("cls");
                    InitialiserVie(&Vie);
                       do{
                            while (S != 4) {
                                if (T != 0) {
                                    while(stop!=0) {
                                    if (Z != 0) {
                                        clock_t startTime = Z;
                                        T = 120 - (clock() / CLOCKS_PER_SEC);
                                    } else {
                                        clock_t startTime = clock();
                                        Z = clock();
                                        T = 120 - (clock() / CLOCKS_PER_SEC);
                                    }
                                    AfficherNiv(x, y, balleX, balleY, tabNiv1, block, block2, block3, NIV);
                                    if (_kbhit()) {
                                        touche = _getch();
                                        if (NIV == 1) {
                                            if ((x == 6 && y == 17) || (x == 6 && y == 19) || (x == 5 && y == 18) ||
                                                (x == 7 && y == 18)) {
                                                if (touche == 'k') {
                                                    block = 1;
                                                    AfficherNiv(x, y, balleX, balleY, tabNiv1, block, block2, block3,
                                                                NIV);
                                                }
                                            }
                                        }

                                        if (NIV == 2) {
                                            if ((x == 5 && y == 2) || (x == 5 && y == 4) || (x == 4 && y == 3) ||
                                                (x == 6 && y == 3)) {
                                                if (touche == 'k') {
                                                    block = 1;
                                                    AfficherNiv(x, y, balleX, balleY, tabNiv1, block, block2, block3,
                                                                NIV);
                                                }
                                            }
                                            if ((x == 5 && y == 19) || (x == 5 && y == 17) || (x == 4 && y == 18) ||
                                                (x == 6 && y == 18)) {
                                                if (touche == 'k') {
                                                    block2 = 1;
                                                }
                                            }
                                        }
                                        if (NIV == 3) {
                                            if ((x == 0 && y == 3) || (x == 0 && y == 1) || (x == 1 && y == 2)) {
                                                if (touche == 'k') {
                                                    block = 1;
                                                    AfficherNiv(x, y, balleX, balleY, tabNiv1, block, block2, block3,
                                                                NIV);
                                                }
                                            }
                                            if ((x == 1 && y == 2) || (x == 0 && y == 1) || (x == 2 && y == 1)) {
                                                if (touche == 'k') {
                                                    block2 = 1;
                                                    AfficherNiv(x, y, balleX, balleY, tabNiv1, block, block2, block3,
                                                                NIV);
                                                }
                                            }
                                            if ((x == 1 && y == 3) || (x == 1 && y == 1) || (x == 0 && y == 2) ||
                                                (x == 2 && y == 2)) {
                                                if (touche == 'k') {
                                                    block3 = 1;
                                                    AfficherNiv(x, y, balleX, balleY, tabNiv1, block, block2, block3,
                                                                NIV);
                                                }
                                            }
                                        }

                                        switch (touche) {
                                            case 'q':
                                                TryMove(&x, &y, 0, -1, tabNiv1, 1, &S);
                                                AfficherNiv(x, y, balleX, balleY, tabNiv1, block, block2, block3, NIV);
                                                if (NIV == 1) {
                                                    if ((x == 8 && y == 5) || (x == 9 && y == 5) ||
                                                        (x == 1 && y == 16)) { //bloc qui bouge pas
                                                        y = y + 1;
                                                        AfficherNiv(x, y, balleX, balleY, tabNiv1, block, block2,
                                                                    block3, NIV);
                                                    }
                                                    if (x == 6 && y == 18) { //bloc cassable
                                                        if (block != 1) {
                                                            y = y + 1;
                                                            AfficherNiv(x, y, balleX, balleY, tabNiv1, block, block2,
                                                                        block3, NIV);
                                                        }
                                                    }
                                                }
                                                if (NIV == 2) {
                                                    if (x == 5 && y == 3) { //bloc cassable
                                                        if (block != 1) {
                                                            y = y + 1;
                                                            AfficherNiv(x, y, balleX, balleY, tabNiv1, block, block2,
                                                                        block3, NIV);
                                                        }
                                                    }
                                                    if (x == 5 && y == 18) {
                                                        if (block2 != 1) {
                                                            y = y + 1;
                                                            AfficherNiv(x, y, balleX, balleY, tabNiv1, block, block2,
                                                                        block3, NIV);
                                                        }
                                                    }
                                                    if ((x == 6 && y == 18) || (x == 7 && y == 18) ||
                                                        (x == 8 && y == 18) ||
                                                        (x == 9 && y == 18)) { //bloc qui bouge pas
                                                        y = y + 1;
                                                        AfficherNiv(x, y, balleX, balleY, tabNiv1, block, block2,
                                                                    block3, NIV);
                                                    }
                                                }
                                                if (NIV == 3) {
                                                    if (x == 0 && y == 2) { //bloc cassable
                                                        if (block != 1) {
                                                            y = y + 1;
                                                            AfficherNiv(x, y, balleX, balleY, tabNiv1, block, block2,
                                                                        block3, NIV);
                                                        }
                                                    }
                                                    if (x == 1 && y == 1) { //bloc cassable
                                                        if (block2 != 1) {
                                                            y = y + 1;
                                                            AfficherNiv(x, y, balleX, balleY, tabNiv1, block, block2,
                                                                        block3, NIV);
                                                        }
                                                    }
                                                    if (x == 1 && y == 2) { //bloc cassable
                                                        if (block3 != 1) {
                                                            y = y + 1;
                                                            AfficherNiv(x, y, balleX, balleY, tabNiv1, block, block2,
                                                                        block3, NIV);
                                                        }
                                                    }
                                                    if ((x == 9 && y == 2) || (x == 8 && y == 2) ||
                                                        (x == 7 && y == 2) || (x == 7 && y == 3) ||
                                                        (x == 7 && y == 4) ||
                                                        (x == 7 && y == 5) || (x == 8 && y == 7) ||
                                                        (x == 8 && y == 8) || (x == 8 && y == 11) ||
                                                        (x == 8 && y == 12) || (x == 8 && y == 13) ||
                                                        (x == 8 && y == 14) ||
                                                        (x == 8 && y == 15) || (x == 9 && y == 17) ||
                                                        (x == 7 && y == 15) || (x == 6 && y == 15) ||
                                                        (x == 6 && y == 16) || (x == 6 && y == 17) ||
                                                        (x == 6 && y == 18) ||
                                                        (x == 6 && y == 19) ||
                                                        (x == 6 && y == 20)) { //bloc qui bouge pas
                                                        y = y + 1;
                                                        AfficherNiv(x, y, balleX, balleY, tabNiv1, block, block2,
                                                                    block3, NIV);
                                                    }
                                                }
                                                if (NIV == 4) {
                                                    if ((x == 5 && y == 19) || (x == 6 && y == 19) ||
                                                        (x == 7 && y == 19) || (x == 8 && y == 19) ||
                                                        (x == 8 && y == 18) || (x == 8 && y == 17) ||
                                                        (x == 9 && y == 15) || (x == 8 && y == 15) ||
                                                        (x == 7 && y == 15) || (x == 0 && y == 12) ||
                                                        (x == 1 && y == 12) || (x == 2 && y == 14) ||
                                                        (x == 1 && y == 14) ||
                                                        (x == 8 && y == 1)) { //bloc qui bouge pas
                                                        y = y + 1;
                                                        AfficherNiv(x, y, balleX, balleY, tabNiv1, block, block2,
                                                                    block3, NIV);
                                                    }
                                                }
                                                system("cls");
                                                break;
                                            case 'd':
                                                TryMove(&x, &y, 0, 1, tabNiv1, 3, &S);
                                                AfficherNiv(x, y, balleX, balleY, tabNiv1, block, block2, block3, NIV);
                                                if (NIV == 1) {
                                                    if ((x == 8 && y == 5) || (x == 9 && y == 5) ||
                                                        (x == 1 && y == 16)) {
                                                        y = y - 1;
                                                        AfficherNiv(x, y, balleX, balleY, tabNiv1, block, block2,
                                                                    block3, NIV);
                                                    }
                                                    if (x == 6 && y == 18) {
                                                        if (block != 1) {
                                                            y = y - 1;
                                                            AfficherNiv(x, y, balleX, balleY, tabNiv1, block, block2,
                                                                        block3, NIV);
                                                        }
                                                    }
                                                }
                                                if (NIV == 2) {
                                                    if (x == 5 && y == 3) { //bloc cassable
                                                        if (block != 1) {
                                                            y = y - 1;
                                                            AfficherNiv(x, y, balleX, balleY, tabNiv1, block, block2,
                                                                        block3, NIV);
                                                        }
                                                    }
                                                    if (x == 5 && y == 18) {
                                                        if (block2 != 1) {
                                                            y = y - 1;
                                                            AfficherNiv(x, y, balleX, balleY, tabNiv1, block, block2,
                                                                        block3, NIV);
                                                        }
                                                    }
                                                    if ((x == 6 && y == 18) || (x == 7 && y == 18) ||
                                                        (x == 8 && y == 18) ||
                                                        (x == 9 && y == 18)) { //bloc qui bouge pas
                                                        y = y - 1;
                                                        AfficherNiv(x, y, balleX, balleY, tabNiv1, block, block2,
                                                                    block3, NIV);
                                                    }
                                                }
                                                if (NIV == 3) {
                                                    if (x == 0 && y == 2) { //bloc cassable
                                                        if (block != 1) {
                                                            y = y - 1;
                                                            AfficherNiv(x, y, balleX, balleY, tabNiv1, block, block2,
                                                                        block3, NIV);
                                                        }
                                                    }
                                                    if (x == 1 && y == 1) { //bloc cassable
                                                        if (block2 != 1) {
                                                            y = y - 1;
                                                            AfficherNiv(x, y, balleX, balleY, tabNiv1, block, block2,
                                                                        block3, NIV);
                                                        }
                                                    }
                                                    if (x == 1 && y == 2) { //bloc cassable
                                                        if (block3 != 1) {
                                                            y = y - 1;
                                                            AfficherNiv(x, y, balleX, balleY, tabNiv1, block, block2,
                                                                        block3, NIV);
                                                        }
                                                    }
                                                    if ((x == 9 && y == 2) || (x == 8 && y == 2) ||
                                                        (x == 7 && y == 2) || (x == 7 && y == 3) ||
                                                        (x == 7 && y == 4) ||
                                                        (x == 7 && y == 5) || (x == 8 && y == 7) ||
                                                        (x == 8 && y == 8) ||
                                                        (x == 8 && y == 9) || (x == 8 && y == 10) ||
                                                        (x == 8 && y == 11) ||
                                                        (x == 8 && y == 12) || (x == 8 && y == 13) ||
                                                        (x == 8 && y == 14) ||
                                                        (x == 8 && y == 15) || (x == 9 && y == 17) ||
                                                        (x == 7 && y == 15) || (x == 6 && y == 15) ||
                                                        (x == 6 && y == 16) || (x == 6 && y == 17) ||
                                                        (x == 6 && y == 18) ||
                                                        (x == 6 && y == 19) ||
                                                        (x == 6 && y == 20)) { //bloc qui bouge pas
                                                        y = y - 1;
                                                        AfficherNiv(x, y, balleX, balleY, tabNiv1, block, block2,
                                                                    block3, NIV);
                                                    }
                                                }
                                                if (NIV == 4) {
                                                    if ((x == 5 && y == 19) || (x == 6 && y == 19) ||
                                                        (x == 7 && y == 19) || (x == 8 && y == 19) ||
                                                        (x == 8 && y == 18) || (x == 8 && y == 17) ||
                                                        (x == 9 && y == 15) || (x == 8 && y == 15) ||
                                                        (x == 7 && y == 15) || (x == 0 && y == 12) ||
                                                        (x == 1 && y == 12) || (x == 2 && y == 14) ||
                                                        (x == 1 && y == 14) ||
                                                        (x == 8 && y == 1)) { //bloc qui bouge pas
                                                        y = y - 1;
                                                        AfficherNiv(x, y, balleX, balleY, tabNiv1, block, block2,
                                                                    block3, NIV);
                                                    }
                                                }
                                                system("cls");
                                                break;
                                            case 'z':
                                                TryMove(&x, &y, -1, 0, tabNiv1, 2, &S);
                                                AfficherNiv(x, y, balleX, balleY, tabNiv1, block, block2, block3, NIV);
                                                if (NIV == 1) {
                                                    if ((x == 8 && y == 5) || (x == 9 && y == 5) ||
                                                        (x == 1 && y == 16)) {
                                                        x = x + 1;
                                                        AfficherNiv(x, y, balleX, balleY, tabNiv1, block, block2,
                                                                    block3, NIV);
                                                    }
                                                    if (x == 6 && y == 18) {
                                                        if (block != 1) {
                                                            x = x + 1;
                                                            AfficherNiv(x, y, balleX, balleY, tabNiv1, block, block2,
                                                                        block3, NIV);
                                                        }
                                                    }
                                                }
                                                if (NIV == 2) {
                                                    if (x == 5 && y == 3) { //bloc cassable
                                                        if (block != 1) {
                                                            x = x + 1;
                                                            AfficherNiv(x, y, balleX, balleY, tabNiv1, block, block2,
                                                                        block3, NIV);
                                                        }
                                                    }
                                                    if (x == 5 && y == 18) { //bloc cassable
                                                        if (block != 1) {
                                                            x = x + 1;
                                                            AfficherNiv(x, y, balleX, balleY, tabNiv1, block, block2,
                                                                        block3, NIV);
                                                        }
                                                    }
                                                    if (x == 5 && y == 18) {
                                                        if (block2 != 1) {
                                                            x = x + 1;
                                                            AfficherNiv(x, y, balleX, balleY, tabNiv1, block, block2,
                                                                        block3, NIV);
                                                        }
                                                    }
                                                    if ((x == 6 && y == 18) || (x == 7 && y == 18) ||
                                                        (x == 8 && y == 18) ||
                                                        (x == 9 && y == 18)) { //bloc qui bouge pas
                                                        x = x + 1;
                                                        AfficherNiv(x, y, balleX, balleY, tabNiv1, block, block2,
                                                                    block3, NIV);
                                                    }

                                                }
                                                if (NIV == 3) {
                                                    if (x == 0 && y == 2) { //bloc cassable
                                                        if (block != 1) {
                                                            x = x + 1;
                                                            AfficherNiv(x, y, balleX, balleY, tabNiv1, block, block2,
                                                                        block3, NIV);
                                                        }
                                                    }
                                                    if (x == 1 && y == 1) { //bloc cassable
                                                        if (block2 != 1) {
                                                            x = x + 1;
                                                            AfficherNiv(x, y, balleX, balleY, tabNiv1, block, block2,
                                                                        block3, NIV);
                                                        }
                                                    }
                                                    if (x == 1 && y == 2) { //bloc cassable
                                                        if (block3 != 1) {
                                                            x = x + 1;
                                                            AfficherNiv(x, y, balleX, balleY, tabNiv1, block, block2,
                                                                        block3, NIV);
                                                        }
                                                    }
                                                    if ((x == 9 && y == 2) || (x == 8 && y == 2) ||
                                                        (x == 7 && y == 2) || (x == 7 && y == 3) ||
                                                        (x == 7 && y == 4) ||
                                                        (x == 7 && y == 5) || (x == 8 && y == 7) ||
                                                        (x == 8 && y == 8) ||
                                                        (x == 8 && y == 9) || (x == 8 && y == 10) ||
                                                        (x == 8 && y == 11) ||
                                                        (x == 8 && y == 12) || (x == 8 && y == 13) ||
                                                        (x == 8 && y == 14) ||
                                                        (x == 8 && y == 15) || (x == 9 && y == 17) ||
                                                        (x == 7 && y == 15) || (x == 6 && y == 15) ||
                                                        (x == 6 && y == 16) || (x == 6 && y == 17) ||
                                                        (x == 6 && y == 18) ||
                                                        (x == 6 && y == 19) ||
                                                        (x == 6 && y == 20)) { //bloc qui bouge pas
                                                        x = x + 1;
                                                        AfficherNiv(x, y, balleX, balleY, tabNiv1, block, block2,
                                                                    block3, NIV);
                                                    }
                                                }
                                                if (NIV == 4) {
                                                    if ((x == 5 && y == 19) || (x == 6 && y == 19) ||
                                                        (x == 7 && y == 19) || (x == 8 && y == 19) ||
                                                        (x == 8 && y == 18) || (x == 8 && y == 17) ||
                                                        (x == 9 && y == 15) || (x == 8 && y == 15) ||
                                                        (x == 7 && y == 15) || (x == 0 && y == 12) ||
                                                        (x == 1 && y == 12) || (x == 2 && y == 14) ||
                                                        (x == 1 && y == 14) ||
                                                        (x == 8 && y == 1)) { //bloc qui bouge pas
                                                        x = x + 1;
                                                        AfficherNiv(x, y, balleX, balleY, tabNiv1, block, block2,
                                                                    block3, NIV);
                                                    }
                                                }
                                                system("cls");
                                                break;
                                            case 's':
                                                TryMove(&x, &y, 1, 0, tabNiv1, 4, &S);
                                                AfficherNiv(x, y, balleX, balleY, tabNiv1, block, block2, block3, NIV);
                                                if (NIV == 1) {
                                                    if ((x == 8 && y == 5) || (x == 9 && y == 5) ||
                                                        (x == 1 && y == 16)) {
                                                        x = x - 1;
                                                        AfficherNiv(x, y, balleX, balleY, tabNiv1, block, block2,
                                                                    block3, NIV);
                                                    }
                                                    if (x == 6 && y == 18) {
                                                        if (block != 1) {
                                                            x = x - 1;
                                                            AfficherNiv(x, y, balleX, balleY, tabNiv1, block, block2,
                                                                        block3, NIV);
                                                        }
                                                    }
                                                }
                                                if (NIV == 2) {
                                                    if (x == 5 && y == 3) { //bloc cassable
                                                        if (block != 1) {
                                                            x = x - 1;
                                                            AfficherNiv(x, y, balleX, balleY, tabNiv1, block, block2,
                                                                        block3, NIV);
                                                        }
                                                    }
                                                    if (x == 5 && y == 18) {
                                                        if (block2 != 1) {
                                                            x = x - 1;
                                                            AfficherNiv(x, y, balleX, balleY, tabNiv1, block, block2,
                                                                        block3, NIV);
                                                        }
                                                    }
                                                    if ((x == 6 && y == 18) || (x == 7 && y == 18) ||
                                                        (x == 8 && y == 18) ||
                                                        (x == 9 && y == 18)) { //bloc qui bouge pas
                                                        x = x - 1;
                                                        AfficherNiv(x, y, balleX, balleY, tabNiv1, block, block2,
                                                                    block3, NIV);
                                                    }
                                                }
                                                if (NIV == 3) {
                                                    if (x == 0 && y == 2) { //bloc cassable
                                                        if (block != 1) {
                                                            x = x - 1;
                                                            AfficherNiv(x, y, balleX, balleY, tabNiv1, block, block2,
                                                                        block3, NIV);
                                                        }
                                                    }
                                                    if (x == 1 && y == 1) { //bloc cassable
                                                        if (block2 != 1) {
                                                            x = x - 1;
                                                            AfficherNiv(x, y, balleX, balleY, tabNiv1, block, block2,
                                                                        block3, NIV);
                                                        }
                                                    }
                                                    if (x == 1 && y == 2) { //bloc cassable
                                                        if (block3 != 1) {
                                                            x = x - 1;
                                                            AfficherNiv(x, y, balleX, balleY, tabNiv1, block, block2,
                                                                        block3, NIV);
                                                        }
                                                    }
                                                    if ((x == 9 && y == 2) || (x == 8 && y == 2) ||
                                                        (x == 7 && y == 2) || (x == 7 && y == 3) ||
                                                        (x == 7 && y == 4) ||
                                                        (x == 7 && y == 5) || (x == 8 && y == 7) ||
                                                        (x == 8 && y == 8) ||
                                                        (x == 8 && y == 9) || (x == 8 && y == 10) ||
                                                        (x == 8 && y == 11) ||
                                                        (x == 8 && y == 12) || (x == 8 && y == 13) ||
                                                        (x == 8 && y == 14) ||
                                                        (x == 8 && y == 15) || (x == 9 && y == 17) ||
                                                        (x == 7 && y == 15) || (x == 6 && y == 15) ||
                                                        (x == 6 && y == 16) || (x == 6 && y == 17) ||
                                                        (x == 6 && y == 18) ||
                                                        (x == 6 && y == 19) ||
                                                        (x == 6 && y == 20)) { //bloc qui bouge pas
                                                        x = x - 1;
                                                        AfficherNiv(x, y, balleX, balleY, tabNiv1, block, block2,
                                                                    block3, NIV);
                                                    }
                                                }
                                                if (NIV == 4) {
                                                    if ((x == 5 && y == 19) || (x == 6 && y == 19) ||
                                                        (x == 7 && y == 19) || (x == 8 && y == 19) ||
                                                        (x == 8 && y == 18) || (x == 8 && y == 17) ||
                                                        (x == 9 && y == 15) || (x == 8 && y == 15) ||
                                                        (x == 7 && y == 15) || (x == 0 && y == 12) ||
                                                        (x == 1 && y == 12) || (x == 2 && y == 14) ||
                                                        (x == 1 && y == 14) ||
                                                        (x == 8 && y == 1)) { //bloc qui bouge pas
                                                        x = x - 1;
                                                        AfficherNiv(x, y, balleX, balleY, tabNiv1, block, block2,
                                                                    block3, NIV);
                                                    }
                                                }
                                                system("cls");
                                                break;

                                            case 'p':
                                                system("cls");
                                                gotoligcol(50, 50);
                                                printf("\t\t\tVOUS AVEZ MIS EN PAUSE.\n"
                                                       "\t Appuyer a nouveau sur p pour remettre le jeu en route. \n");
                                                printf("\t\tSi vous voulez sauvegarder votre avancee appuyez sur la touche u\n");
                                                touche = getch();*
                                                        SauvegardePartie(PartieP1,Vie,Score,NIV,Z,x,y);
                                                    SauvegarderFichierPartie(PartieP1,P);
                                                /*system("cls");*/
                                                    

                                                break;

                                            case 't':
                                                stop=0;
                                                break;

                                            case 'm': {
                                                FILE *Save = fopen("saveNiv", "w");
                                                if (Save == NULL) {
                                                    perror("Erreur lors de l'ouverture du fichier de sauvegarde");
                                                    return 1;
                                                }
                                                int x1 = x;
                                                int y1 = y;
                                                int Score11 = Score1;
                                                int block1 = block;
                                                int balleX1 = balleX;
                                                int balleY1 = balleY;
                                                fprintf(Save, "%d %d %d %d %d", x1, y1, Score11, balleX1,
                                                        balleY1);

                                                fclose(Save);
                                            }


                                        }
                                    } else {
                                        gotoligcol(15, 15);
                                        printf("           Il reste %d secondes pour completer le niveau.        \n"
                                               "                SCORE = %d                   VIES=%d\n", T, S,
                                               Vie);
                                        DeplacementBalle(&balleX, &balleY, &vx, &vy, tabNiv1);
                                    }

//si la balle touche snoopy alors il perd une vie et la partie recommence//
                                    if (balleX == x && balleY == y) {
                                        int w;
                                        int z;
                                        Vie = Vie - 1;
                                        x = 4;
                                        y = 9;
                                        AfficherNiv(x, y, balleX, balleY, tabNiv1, block, block2, block3, NIV);
                                        printf("---GAME OVER---\n"
                                               "Il vous reste %d vies.\n"
                                               "Entrer 2 pour recommencer\n", Vie);
                                        do {
                                            ShowConsoleCursor(TRUE);
                                            scanf("%d", &w);
                                        } while (w != 2);
                                        S = 0;
                                    }
                                    if (NIV == 1) {
                                        if ((x == 2 && y == 1) || (x == 1 && y == 5) || (x == 3 && y == 17)) {
                                            int p;
                                            Vie = Vie - 1;
                                            x = 4;
                                            y = 9;
                                            AfficherNiv(x, y, balleX, balleY, tabNiv1, block, block2, block3, NIV);
                                            printf("---GAME OVER---\n"
                                                   "Il vous reste %d vies.\n"
                                                   "Entrer 2 pour recommencer\n", Vie);
                                            do {
                                                ShowConsoleCursor(TRUE);
                                                scanf("%d", &p);
                                            } while (p != 2);
                                            S = 0;

                                        }
                                    }
                                    if (NIV == 2) {
                                        if ((x == 2 && y == 1) || (x == 2 && y == 2) || (x == 2 && y == 3) ||
                                            (x == 2 && y == 4) || (x == 2 && y == 5) || (x == 2 && y == 6) ||
                                            (x == 2 && y == 7) || (x == 9 && y == 10) || (x == 8 && y == 11)) {
                                            int p;
                                            Vie = Vie - 1;
                                            x = 8;
                                            y = 3;
                                            AfficherNiv(x, y, balleX, balleY, tabNiv1, block, block2, block3, NIV);
                                            printf("---GAME OVER---\n"
                                                   "Il vous reste %d vies.\n"
                                                   "Entrer 2 pour recommencer\n", Vie);
                                            do {
                                                ShowConsoleCursor(TRUE);
                                                scanf("%d", &p);
                                            } while (p != 2);
                                            S = 0;

                                        }
                                    }
                                    if (NIV == 3) {
                                        if ((x == 0 && y == 10) || (x == 1 && y == 10) || (x == 2 && y == 10) ||
                                            (x == 3 && y == 10) || (x == 4 && y == 10) || (x == 5 && y == 10) ||
                                            (x == 5 && y == 11) || (x == 5 && y == 12) || (x == 4 && y == 12) ||
                                            (x == 3 && y == 12)) {
                                            int p;
                                            Vie = Vie - 1;
                                            x = 4;
                                            y = 11;
                                            AfficherNiv(x, y, balleX, balleY, tabNiv1, block, block2, block3, NIV);
                                            printf("---GAME OVER---\n"
                                                   "Il vous reste %d vies.\n"
                                                   "Entrer 2 pour recommencer\n", Vie);
                                            do {
                                                ShowConsoleCursor(TRUE);
                                                scanf("%d", &p);
                                            } while (p != 2);
                                            S = 0;

                                        }
                                    }
                                    if (NIV == 4) {
                                        if ((x == 4 && y == 20) || (x == 4 && y == 90) || (x == 4 && y == 18) ||
                                            (x == 4 && y == 17) || (x == 4 && y == 16) || (x == 4 && y == 15) ||
                                            (x == 4 && y == 14) || (x == 4 && y == 13) || (x == 4 && y == 12) ||
                                            (x == 4 && y == 11) || (x == 4 && y == 10) || (x == 4 && y == 9) ||
                                            (x == 4 && y == 8) ||
                                            (x == 4 && y == 7) || (x == 4 && y == 6) || (x == 4 && y == 5) ||
                                            (x == 4 && y == 4) || (x == 4 && y == 3) || (x == 4 && y == 2)
                                            || (x == 6 && y == 14) || (x == 6 && y == 13) || (x == 6 && y == 12) ||
                                            (x == 6 && y == 11) ||
                                            (x == 6 && y == 10) || (x == 6 && y == 9) || (x == 6 && y == 8) ||
                                            (x == 6 && y == 7) || (x == 6 && y == 6) || (x == 6 && y == 5)) {
                                            int p;
                                            Vie = Vie - 1;
                                            x = 9;
                                            y = 20;
                                            AfficherNiv(x, y, balleX, balleY, tabNiv1, block, block2, block3, NIV);
                                            printf("---GAME OVER---\n"
                                                   "Il vous reste %d vies.\n"
                                                   "Entrer 2 pour recommencer\n", Vie);
                                            do {
                                                ShowConsoleCursor(TRUE);
                                                scanf("%d", &p);
                                            } while (p != 2);
                                            S = 0;

                                        }
                                    }


                                }
                                if (Vie == 0) {
                                    int w;
                                    int z;
                                    //Vie=Vie-1;
                                    x = 4;
                                    y = 9;
                                    //AfficherNiv(x, y, balleX, balleY, tabNiv1, block);
                                    printf("---GAME OVER---\n"
                                           "Il vous reste %d vies.\n"
                                           "Entrer 1 pour retourner au menu\n", Vie);
                                    do {
                                        ShowConsoleCursor(TRUE);
                                        scanf("%d", &z);
                                    } while (z != 1);

                                    S = 0;
                                    if (z == 1) {
                                        system("cls");
                                        printf("\n\n\n\n\n\n\n\n\n");
                                        menu();

                                    }

                                }


                            }


                                if(stop==0){

                                }
                            if (S == 4) {
                                ShowConsoleCursor(TRUE);
                                Score1 = CalculScoreNiv(S, T);
                                JeuGAGNE(Vie, Score1);
                                scanf("%c", &touche);
                                NIV = NIV + 1;
                            }
                            break;
                        }
                    }while(stop!=0);

                    break;



                        case 4 :
                            do {
                                system("cls");
                                printf("Selectionnez le mot de passe du niveau que vous voulez :\n");
                                printf("\n\n1.Niveau 1\n2.Niveau 2\n3.Niveau 3\n4.Niveau 4\n");
                                scanf("%d", &choixmdp);
                            } while ((choixmdp > 4) || (choixmdp < 0));
                        switch (choixmdp) {
                            case 1:
                                while (retour1 != 1) {
                                    system("cls");
                                    printf("le mot de passe est : 3411\n\nEntrez 1 pour revenir au menu\n");
                                    scanf("%d", &retour1);
                                }
                                system("cls");
                                break;


                            case 3 :
                                while (retour1 != 1) {
                                    system("cls");
                                    printf("le mot de passe est : 9251\n\nEntrez 1 pour revenir au menu\n");
                                    scanf("%d", &retour2);
                                }
                                system("cls");
                                break;

                            case 4:
                                while (retour1 != 1) {
                                    system("cls");
                                    printf("le mot de passe est : 7719\n\nEntrez 1 pour revenir au menu\n");
                                    scanf("%d", &retour2);
                                }
                                system("cls");
                                break;


                        }
                        break;


                        case 5 :
                            printf("Les scores sont les suivants : \n");
                        break;


                        case 6 :
                            printf("Tres bien, au revoir!\n");
                        sleep(4);
                        break;


                        default :
                            printf("Veuillez selectionner une valeur correcte.\n");

                    }
            }


            while ((A < 2) || (A > 6) || (A == 1) || (G == 0));

            return 0;


}
