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

void AfficherNiv(int x,int y, int balleX, int balleY, unsigned char tab[Nc][Nl], int block)
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
                /*printf("%c", 0xF4);*/
                printf("%c", 0xF4);
            }
            /*if((i==0&&j==1)||(i==9&&j==20)||(i==0&&j==20)||(i==9&&j==1)){
                printf("%c", 0xA9);
            }*/

            if (i==balleX && j==balleY){
                printf(MAGENTA_COLOR "%c", 0x9D );
            }
            if((i==8&&j==5)||(i==9&&j==5)||(i==1&&j==16)){
                printf("%c", 0xCE);
            }
            if((i==2&&j==1)||(i==1&&j==5)||(i==3&&j==17)){
                printf("%c", 0xB2);
            }
            if(i==6&&j==18){

                if(block==1) {
                    printf(" ");
                }
                else{
                    printf("%c", 0xFE);
                }
            }
            else
                printf(RESET_COLOR"%c",tab[i][j]);
        }
        printf("\n");
    }
    ShowConsoleCursor(FALSE);
}

void JeuGAGNE(int v, int S){
    char touche;
    system("cls");
    printf("Vous avez gagne la partie!! Felicitations...\n"
           "\n"
           "Vous avez obtenu un score de %d: \n"
           "Vous avez encore %d vies.\n"
           "Appuyez sur z pour continuer vers le niveau 2.\n",S,v);
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
        if (tab[*x + vx][*y + vy] == tab[*x + vx +vx][*y + vy + vy ]) {
            return;
        }
        tab[*x + vx+ vx][*y + vy + vy] = 'X';
        tab[*x + vx][*y + vy] = ' ';
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
