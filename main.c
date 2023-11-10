#include <stdio.h>
#include "LIBRAIRIE SS PROG.h"
#include <windows.h>
#include <conio.h>
#include <unistd.h>

int main() {
    //Mise en place des niveaux
    unsigned char tabNiv1[Nc][Nl] = {
            "0                  0",
            "                    ",
            "         X          ",
            "        X X         ",
            "       X   X        ",
            "        X X         ",
            "         X          ",
            "                    ",
            "                    ",
            "0                  0",
    };
    printf("                  \n"
           "      ........    \n"
           "     .      ..... \n"
           "     . .   ...... \n"
           " ....       ..... \n"
           " .     ...-  .... \n"
           "   ...            \n"
           "      .      .     \n"
           "      .    ..      \n"
           "      .    .. . . \n"
           "      .       . . \n"
           "      .           \n"
           "                  \n"
           "   ....    .....  \n"
           " .......  ....... \n");

    int MDP1 = 198;
    int MDP2 = 223;
    int MDP3 = 999;
    int MDP;
    int A;
    int x,y;

    //Début du jeu
    do {
        menu();
        scanf("%d",&A);
        switch (A) {



            case 1 : printf("Les regles sont les suivantes :\n"
                            "Pour avancer, appuyez sur z.\n"
                            "Pour reculer, appuyez sur s.\n"
                            "Pour aller vers la gauche, appuyez sur s.\n"
                            "Pour aller vers la droite, appuyez sur d.\n"
                            "Appuyer sur P pour mettre pause.\n\n");
                break;





            case 2 :
                printf("Commencez votre aventure! Bienvenue sur le Niveau 1.\n"
                       "Souhaitez-vous enregistrer cette partie dans un des slots disponible ?\n");

                int TempsREST=120;
                int S=0;
                int touche;
                int balleX = 5;
                int balleY = 7;
                int vx;
                int vy;

                //Initialisation de Snoopy
                int x,y;
                x = 4;
                y = 9;
                vx=1;
                vy=1;

                touche = 0;
                system("cls");

                while((S!=4)||(TempsREST!=0))
                {
                    DeplacementBalle(&balleX,&balleY,&vx,&vy);
                    AfficherNiv(x,y,balleX,balleY, tabNiv1);
                    touche=MyGetch();
                    switch(touche)
                    {
                        case 'q':
                            TryMove(&x,&y,0,-1,tabNiv1,1,&S);
                            break;
                        case 'd':
                            TryMove(&x,&y,0,1,tabNiv1,3,&S);
                            break;
                        case 'z':
                            TryMove(&x,&y,-1,0,tabNiv1,2,&S);
                            break;
                        case 's':
                            TryMove(&x,&y,1,0,tabNiv1,4,&S);
                        default:
                            TempsREST=TempsREST-1;
                            Locate(0,15);
                            printf("        Il reste %d secondes pour completer le niveau.        ",TempsREST);
                            break;
                    }
                }

                if (S==4){
                    printf("Vous avez gagne la partie!! Felicitations...\n"
                           "Appuyez sur Z pour continuer vers le niveau 2.\n");
                }
                scanf("%c",touche);
                if (TempsREST==0){
                    printf("---GAME OVER---\n"
                           "Souhaitez-vous recommencer ?\n");
                }
                break;


            case 3 :
                printf("Entrez le mot de passe de votre partie pour y acceder :\n");
                break;

            case 4 :printf("Les mots de passe sont les suivants :\n");
                break;

            case 5 : printf("Les scores sont les suivants : \n");
                break;

            case 6 :
                printf("Tres bien, au revoir!\n");
                break;

            default :
                printf("Veuillez selectionner une valeur correcte.\n");
        }
    } while ((A<2)||(A>3)||(A==1));
    return 0;
}
