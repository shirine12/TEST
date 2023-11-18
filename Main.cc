#include <stdio.h>
#include "LIBRAIRIE SS PROG.h"
#include <windows.h>
#include <conio.h>
#include <unistd.h>

int main() {
        //Mise en place des niveaux
        unsigned char tabNiv1[Nc][Nl] = {
                " 0                 0",
                "                    ",
                "         X          ",
                "        X X         ",
                "       X   X        ",
                "        X X         ",
                "         X          ",
                "                    ",
                "                    ",
                " 0                 0",
        };

        typedef struct Partie {
            int Score1, Score2, Score3, Niv, t, Vie;
            char MDP;
        } Partie;

        int A;
        int G = 0;
        int Ret = 0;
        int x, y;
        int Vie;

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
                               "Appuyer sur k pour casser les blocs cassables. \n\n");
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


                case 2 :
                    printf("Commencez votre aventure! Bienvenue sur le Niveau 1.\n"
                           "Enregistrer cette partie dans un des slots disponible.\n"
                           "Appuyer sur Z pour confirmer (il vous faudra sauvegarder dans le menu pause, sinon vous perdrez vos progres).\n");

                    int TempsREST = 120;
                    int S = 0;
                    char touche;
                    int balleX = 5;
                    int balleY = 7;
                    int vx;
                    int vy;

                    //Initialisation de Snoopy et la direction de la balle
                    int x, y;
                    int Score1;
                    int block;
                    x = 4;
                    y = 9;
                    vx = 1;
                    vy = 1;

                    touche = 0;
                    system("cls");
                    InitialiserVie(&Vie);
                    while (Vie != 0) {
                        while (S != 4) {
                            if (TempsREST != 0) {
                                AfficherNiv(x, y, balleX, balleY, tabNiv1, block);
                                if (_kbhit()) {
                                    touche = _getch();
                                    if ((x == 6 && y == 17) || (x == 6 && y == 19)) {
                                        if (touche == 'k') {
                                            block = 1;
                                            AfficherNiv(x, y, balleX, balleY, tabNiv1, block);
                                        }
                                    }
                                    if ((x == 5 && y == 18) || (x == 7 && y == 18)) {
                                        if (touche == 'k') {
                                            block = 1;
                                            AfficherNiv(x, y, balleX, balleY, tabNiv1, block);
                                        }
                                    }
                                    switch (touche) {
                                        case 'q':
                                            TryMove(&x, &y, 0, -1, tabNiv1, 1, &S);
                                            AfficherNiv(x, y, balleX, balleY, tabNiv1, block);
                                            if ((x == 8 && y == 5) || (x == 9 && y == 5) || (x == 1 && y == 16)) {
                                                y = y + 1;
                                                AfficherNiv(x, y, balleX, balleY, tabNiv1, block);
                                            }
                                            if (x == 6 && y == 18) {
                                                if (block != 1) {
                                                    y = y + 1;
                                                    AfficherNiv(x, y, balleX, balleY, tabNiv1, block);
                                                }
                                            }
                                            system("cls");
                                            break;
                                        case 'd':
                                            TryMove(&x, &y, 0, 1, tabNiv1, 3, &S);
                                            AfficherNiv(x, y, balleX, balleY, tabNiv1, block);
                                            if ((x == 8 && y == 5) || (x == 9 && y == 5) || (x == 1 && y == 16)) {
                                                y = y - 1;
                                                AfficherNiv(x, y, balleX, balleY, tabNiv1, block);
                                            }
                                            if (x == 6 && y == 18) {
                                                if (block != 1) {
                                                    y = y - 1;
                                                    AfficherNiv(x, y, balleX, balleY, tabNiv1, block);
                                                }
                                            }
                                            system("cls");
                                            break;
                                        case 'z':
                                            TryMove(&x, &y, -1, 0, tabNiv1, 2, &S);
                                            AfficherNiv(x, y, balleX, balleY, tabNiv1, block);
                                            if ((x == 8 && y == 5) || (x == 9 && y == 5) || (x == 1 && y == 16)) {
                                                x = x + 1;
                                                AfficherNiv(x, y, balleX, balleY, tabNiv1, block);
                                            }
                                            if (x == 6 && y == 18) {
                                                if (block != 1) {
                                                    x = x + 1;
                                                    AfficherNiv(x, y, balleX, balleY, tabNiv1, block);
                                                }
                                            }
                                            system("cls");
                                            break;
                                        case 's':
                                            TryMove(&x, &y, 1, 0, tabNiv1, 4, &S);
                                            AfficherNiv(x, y, balleX, balleY, tabNiv1, block);
                                            if ((x == 8 && y == 5) || (x == 9 && y == 5) || (x == 1 && y == 16)) {
                                                x = x - 1;
                                                AfficherNiv(x, y, balleX, balleY, tabNiv1, block);
                                            }
                                            if (x == 6 && y == 18) {
                                                if (block != 1) {
                                                    x = x - 1;
                                                    AfficherNiv(x, y, balleX, balleY, tabNiv1, block);
                                                }
                                            }
                                            system("cls");
                                            break;

                                        case 'p':
                                            gotoligcol(50, 50);
                                            printf("\t\tVOUS AVEZ MIS EN PAUSE.\n"
                                                   "\t Appuyer a nouveau sur p pour remettre le jeu en route. \n");
                                            touche = getch();
                                            system("cls");
                                            break;
                                        default:
                                            break;
                                    }
                                } else {
                                    usleep(10000);
                                    TempsREST = TempsREST - 1;
                                    gotoligcol(15, 15);
                                    printf("           Il reste %d secondes pour completer le niveau.        \n"
                                           "                SCORE = %d                   VIES=%d\n", TempsREST, S, Vie);
                                    DeplacementBalle(&balleX, &balleY, &vx, &vy, tabNiv1);

                                }



//si la balle touche snoopy alors il perd une vie et la partie recommence//
                                if (balleX == x && balleY == y) {
                                    int w;
                                    int z;
                                    Vie = Vie - 1;
                                    x = 4;
                                    y = 9;
                                    AfficherNiv(x, y, balleX, balleY, tabNiv1, block);
                                    printf("---GAME OVER---\n"
                                           "Il vous reste %d vies.\n"
                                           "Entrer 2 pour recommencer\n", Vie);
                                    do {
                                        ShowConsoleCursor(TRUE);
                                        scanf("%d", &w);
                                    } while (w != 2);
                                    S = 0;
                                }
                                if ((x == 2 && y == 1) || (x == 1 && y == 5) || (x == 3 && y == 17)) {
                                    int p;
                                    Vie = Vie - 1;
                                    x = 4;
                                    y = 9;
                                    AfficherNiv(x, y, balleX, balleY, tabNiv1, block);
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


                        if (S == 4) {
                            ShowConsoleCursor(TRUE);
                            Score1 = CalculScoreNiv(S, TempsREST);
                            JeuGAGNE(Vie, Score1);
                            scanf("%c", &touche);
                        }
                        break;
                    }


                case 3 :
                    printf("Entrez le mot de passe de votre partie pour y acceder :\n");
                    break;


                case 4 :
                    printf("Les mots de passe sont les suivants :\n");
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

        } while ((A < 2) || (A > 6) || (A == 1) || (G == 0));

        return 0;

}
