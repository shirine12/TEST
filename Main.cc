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
            "         Y          ",
            "        U U         ",
            "       X   X        ",
            "        U U         ",
            "         Y          ",
            "                    ",
            "                    ",
            " 0                 0",
    };

    typedef struct Partie{
        int Score1,Score2,Score3,Niv,t,Vie;
        char MDP;
    }Partie;

    int A;
    int Ret=0;
    int x,y;
    int Vie;

    //Début du jeu
    do {
        menu();
        scanf("%d",&A);
        //if (kbhit()) {
        switch (A) {


            case 1 :
                while (Ret < 1) {
                    printf("Les regles sont les suivantes :\n\n"
                           "Les controles sont els suivants :\n"
                           "Pour avancer, appuyez sur z.\n"
                           "Pour reculer, appuyez sur s.\n"
                           "Pour aller vers la gauche, appuyez sur s.\n"
                           "Pour aller vers la droite, appuyez sur d.\n"
                           "Appuyer sur P pour mettre pause.\n\n"
                           "Regles du jeu :\n"
                           "Il faut recuperer les 4 oiseaux pour finir le niveau. Gare aux ennemis comme la boule ou le snoopy mechant!\n"
                           "Il y a plusieurs types de blocs avec lesquels interagir. Mais a toi de les decouvrir...\n"
                           "Appuyer sur 1 pour retourner au menu .\n\n");
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
                x = 4;
                y = 9;
                vx = 1;
                vy = 1;
                int w;
                int z;

                touche = 0;
                system("cls");
                InitialiserVie(&Vie);
                while (Vie!=0){
                    while (S!= 4) {
                        if (TempsREST != 0) {
                            AfficherNiv(x, y, balleX, balleY, tabNiv1);
                            if (_kbhit()) {
                                touche = MyGetch();
                                switch (touche) {
                                    case 'q':
                                        TryMove(&x, &y, 0, -1, tabNiv1, 1, &S);
                                        AfficherNiv(x, y, balleX, balleY, tabNiv1);
                                        system("cls");
                                        break;
                                    case 'd':
                                        TryMove(&x, &y, 0, 1, tabNiv1, 3, &S);
                                        AfficherNiv(x, y, balleX, balleY, tabNiv1);
                                        system("cls");
                                        break;
                                    case 'z':
                                        TryMove(&x, &y, -1, 0, tabNiv1, 2, &S);
                                        AfficherNiv(x, y, balleX, balleY, tabNiv1);
                                        system("cls");
                                        break;
                                    case 's':
                                        TryMove(&x, &y, 1, 0, tabNiv1, 4, &S);
                                        AfficherNiv(x, y, balleX, balleY, tabNiv1);
                                        system("cls");
                                        break;
                                    case 'p':
                                        gotoligcol(50,50);
                                        printf("\t\tVOUS AVEZ MIS EN PAUSE.\n"
                                           "\tAppuyer a nouveau sur P pour remettre le jeu en route.\n");
                                        touche=MyGetch();
                                        break;
                                    default:
                                        break;
                                }
                            }
                            else {
                                sleep(1);
                                TempsREST = TempsREST - 1;
                                gotoligcol(15, 15);
                                printf("           Il reste %d secondes pour completer le niveau.        \n"
                                       "                SCORE = %d                   VIES=%d\n", TempsREST,S,Vie);
                                DeplacementBalle(&balleX, &balleY, &vx, &vy, tabNiv1);
                            }


//si la balle touche snoopy alors il perd une vie et la partie recommence//
                            if (balleX==x&&balleY==y){
                                Vie=Vie-1;
                                system("cls");
                                printf("---GAME OVER---\n"
                                       "Il vous reste %d vies.\n"
                                       "Entrer 2 pour recommencer\n",Vie);
                                do{
                                    ShowConsoleCursor(TRUE);
                                    scanf("%d", &w);
                                }while (w!=2);
                                S=0;
                            }
                        }
                        else {
                            Vie=Vie-1;
                            printf("---GAME OVER---\n"
                                   "Il vous reste %d vies.\n"
                                   "Appuyer sur 1 pour recommencer\n",Vie);
                            do{
                                ShowConsoleCursor(TRUE);
                                scanf("%d", &z);
                            }while (z!=1);
                            S=0;
                        }
                    }
                    if (S == 4) {
                        ShowConsoleCursor(TRUE);
                        Score1=CalculScoreNiv(S,TempsREST);
                        JeuGAGNE(Vie,Score1);
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

    } while ((A<2)||(A>6)||(A==1));

    return 0;

