//
// Created by alban on 28/10/2023.
//

#ifdef _WIN32
#include "LIBRAIRIE SS PROG.h"
#include <windows.h>
#include <conio.h>
#include <unistd.h>
#include <windows.h>
#include <conio.h>
#endif
#include <stdio.h>
#define MAGENTA_COLOR "\x1b[35m"
#define RESET_COLOR "\x1b[0m"

void menu(){
    printf("-------------------------------------------\n"
           "             BIENVENUE SUR...\n"
           "\n"
           "               LA REVANCHE\n"
           "                    DE\n"
           "\n"
           "               S N O O P Y\n"
           "\n"
           "--------------             ----------------\n"
           "                                       \n"
           "                  ........           \n"
           "                 .      .....          \n"
           "                 . .   ......       \n"
           "             ....       .....        \n"
           "             .     ...-  ....          \n"
           "               ...            \n\n"
           "-------------------------------------------\n"
           "\n"
           "1. Afficher les regles\n"
           "2. Lancer une partie\n"
           "3. Charger une partie\n"
           "4. Afficher les mots de passe\n"
           "5. Afficher les scores\n"
           "6. Quitter\n\n"
           "-------------------------------------------\n");
    sleep(1);
    gotoligcol(0,0);
    printf("-------------------------------------------\n"
           "             BIENVENUE SUR...\n"
           "\n"
           "               LA REVANCHE\n"
           "                    DE\n"
           "\n"
           "               S N O O P Y\n"
           "\n"
           "--------------             ----------------\n"
           "                              \n"
           "                  ........    \n"
           "                 / /    .....        \n"
           "                 . .   ......        \n"
           "             ....       .....         \n"
           "             .     ..._  ....       \n"
           "               ...     ..            \n\n"
           "-------------------------------------------\n"
           "\n"
           "1. Afficher les regles\n"
           "2. Lancer une partie\n"
           "3. Charger une partie\n"
           "4. Afficher les mots de passe\n"
           "5. Afficher les scores\n"
           "6. Quitter\n\n"
           "-------------------------------------------\n");
}

void InitialiserVie(int* a) {
    *a = 3;
}

void AfficherNiv(int x,int y, int balleX, int balleY, unsigned char tab[Nc][Nl])
{
    int i,j;
    gotoligcol(0,0);
    for(i=0;i<Nc;i++)
    {
        for(j=0;j<Nl;j++)
        {
            tab[x][y]=NULL;
            tab[balleX][balleY]=NULL;
            if (i==x && j==y){
                printf("%c", 0xF4);
            }

            if (i==balleX && j==balleY){
                printf(MAGENTA_COLOR "%c", 0x9D );
            }
            if (tab[i][j]=="X"){
                tab[i][j]=NULL;
                printf("%c",0x6A);
                tab[i][j]="X";
            }
            else
                printf(RESET_COLOR"%c",tab[i][j]);
        }
        printf("\n");
    }
}

void JeuGAGNE(int v, int S){
    char touche;
    system("cls");
    printf("Vous avez gagne la partie!! Felicitations...\n"
           "\n"
           "Vous avez obtenu un score de %d: \n"
           "Vous avez encore %d vies.\n"
           "Appuyez sur Z pour continuer vers le niveau 2.\n",S,v);
    while (touche!="z"){
        touche=MyGetch;
    }
}

char MyGetch()
{
#ifdef _WIN32
    return getch();
#endif
// trouver alternative hors Windows.
}

void TryMove(int* x,int* y,int vx,int vy, unsigned char tab[Nc][Nl], int C,int* S) {
    if (tab[*x + vx][*y + vy] == 'X') {
        if (tab[*x + vx][*y + vy] == tab[*x + vx + vx][*y + vy + vy]) {
            return;
        }
        tab[*x + vx+ vx][*y + vy + vy] = 'X';
        tab[*x + vx][*y + vy] = ' ';
    }
    if (tab[*x + vx][*y + vy] == 'Y') {
        return;
    }
    if (*x+vx==-1 || *x+vx==10 ||*y+vy==0 || *y+vy==20){
        return;
    }

    if (tab[*x + vx][*y + vy]=='0'){
        *S=*S+1;
        gotoligcol(30,10);
        printf("Votre score a augmente!\n");
        sleep(1);
        system("cls");
    }
    tab[*x][*y]=' ';
    (*x) += vx;
    (*y) += vy;


}
