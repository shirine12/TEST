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
#define CYAN_COLOR "\x1b[36m"
#define RESET_COLOR "\x1b[0m"
#define GRAS "\033[0m"
#define RESET_GRAS "\033[0m"
#define FOND_BLANC "\033[0;47m"
#define RESET_FOND "\033[0m"
#define NOIR_COLOR "\033[0;30m"

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
           "                                           \n"
           "                  ........                 \n"
           "                 .      .....              \n"
           "                 . .   ......              \n"
           "             ....       .....              \n"
           "             .     ...-  ....              \n"
           "               ...                       \n\n"
           "-------------------------------------------\n"
                     "\n"
           "1. Afficher les regles\n"
           "2. Charger une partie\n"
           "3. Lancer une partie\n"
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
           "2. Charger une partie\n"
           "3. Lancer une partie\n"
           "4. Afficher les mots de passe\n"
           "5. Afficher les scores\n"
           "6. Quitter\n\n"
           "-------------------------------------------\n");
}

void InitialiserVie(int* a) {
    *a = 3;
}

void AfficherNiv(int x,int y, int balleX, int balleY, unsigned char tab[Nc][Nl], int block, int block2, int block3, int NIV) {
    int i, j;
    if (NIV == 1) {
        gotoligcol(1, 0);
        for (i = 0; i < Nc; i++) {
            for (j = 0; j < Nl; j++) {
                tab[x][y] = NULL;
                tab[balleX][balleY] = NULL;
                if (i == x && j == y) {
                    /*printf("%c", 0xF4);*/
                    printf("%c", 0xF4);
                }
                /*if((i==0&&j==1)||(i==9&&j==20)||(i==0&&j==20)||(i==9&&j==1)){
                    printf("%c", 0xA9);
                }*/

                if (i == balleX && j == balleY) {
                    printf(MAGENTA_COLOR "%c", 0x9D);
                }
                if ((i == 8 && j == 5) || (i == 9 && j == 5) || (i == 1 && j == 16)) {
                    printf("%c", 0xCE);
                }
                if ((i == 2 && j == 1) || (i == 1 && j == 5) || (i == 3 && j == 17)) {
                    printf("%c", 0xB2);
                }
                if (i == 6 && j == 18) {

                    if (block == 1) {
                        printf(" ");
                    } else {
                        printf("%c", 0xFE);
                    }
                } else
                    printf(RESET_COLOR"");
                    printf("%c", tab[i][j]);
            }
            printf("\n");
        }
    }
    if(NIV==2){
        gotoligcol(1, 0);
        for (i = 0; i < Nc; i++) {
            for (j = 0; j < Nl; j++) {
                tab[x][y] = NULL;
                tab[balleX][balleY] = NULL;
                if (i == x && j == y) {
                    printf("%c", 0xF4);
                }
                /*if((i==0&&j==1)||(i==9&&j==20)||(i==0&&j==20)||(i==9&&j==1)){
                    printf("%c", 0xA9);
                }*/

                if (i == balleX && j == balleY) {
                    printf(MAGENTA_COLOR "%c", 0x9D);
                }
                if ((i == 6 && j == 18) || (i == 7 && j == 18) ||
                    (i == 8 && j == 18) || (i==9&&j==18)) {
                    printf("%c", 0xCE); //bloc bouge pas
                }
                if ((i ==2&& j == 1) || (i == 2 && j == 2) || (i == 2 && j == 3)||(i ==2&& j == 4) || (i == 2 && j == 5) || (i == 2 && j == 6)||(i ==2&& j == 7) || (i == 9 && j == 10) || (i == 8 && j == 11)) {
                    printf("%c", 0xB2); //Bloc qui tue
                }
                if (i == 5 && j == 3){

                    if (block == 1) {
                        printf(" ");
                    } else {
                        printf("%c", 0xFE);
                    }
                }
                if (i==5&&j==18) {

                    if (block2 == 1) {
                        printf(" ");
                    } else {
                        printf("%c", 0xFE);
                    }
                }
                else {
                    printf(RESET_COLOR"");
                    printf("%c", tab[i][j]);
                }
            }
            printf("\n");
        }

    }
    if(NIV==3){
        gotoligcol(1, 0);
        for (i = 0; i < Nc; i++) {
            for (j = 0; j < Nl; j++) {
                tab[x][y] = (unsigned char) NULL;
                tab[balleX][balleY] = (unsigned char) NULL;
                if (i == x && j == y) {
                    printf("%c", 0xF4);
                }
                /*if((i==0&&j==1)||(i==9&&j==20)||(i==0&&j==20)||(i==9&&j==1)){
                    printf("%c", 0xA9);
                }*/

                if (i == balleX && j == balleY) {
                    printf(MAGENTA_COLOR "%c", 0x9D);
                }
                if ((i == 9 && j == 2) || (i == 8 && j == 2) ||
                    (i == 7 && j == 2)||(i == 7 && j == 3) || (i == 7 && j == 4) ||
                    (i == 7 && j == 5)||(i == 8 && j == 7) || (i == 8 && j == 8) ||
                     (i == 8 && j == 11) ||
                    (i == 8 && j == 12)|| (i == 8 && j == 13) || (i == 8 && j == 14) ||
                    (i == 8 && j == 15)||(i == 9 && j == 17) || (i == 7 && j == 15) || (i == 6 && j == 15) ||
                    (i == 6 && j == 16)) {
                    printf("%c", 0xCE); //bloc bouge pas
                }
                if ((i == 0 && j == 10) || (i == 1 && j == 10) || (i == 2 && j == 10) ||
                    (i == 3 && j == 10) || (i == 4 && j == 10) || (i == 5 && j == 10) ||
                    (i == 5 && j == 11) || (i == 5 && j == 12) || (i == 4 && j == 12)||(i==3&&j==12)) {
                    printf("%c", 0xB2); //Bloc qui tue
                }
                if (i==0&&j==2) {

                    if (block == 1) {
                        printf(" ");
                    } else {
                        printf("%c", 0xFE);
                    }
                }
                if (i==1&&j==1) {

                    if (block2 == 1) {
                        printf(" ");
                    } else {
                        printf("%c", 0xFE);
                    }
                }
                if (i==1&&j==2) {

                    if (block3 == 1) {
                        printf(" ");
                    } else {
                        printf("%c", 0xFE);
                    }
                }
                else
                    printf(RESET_COLOR"");
                printf("%c", tab[i][j]);
            }
            printf("\n");
        }

    }
    if(NIV==4){
        gotoligcol(1, 0);
        for (i = 0; i < Nc; i++) {
            for (j = 0; j < Nl; j++) {
                tab[x][y] = NULL;
                tab[balleX][balleY] = NULL;
                if (i == x && j == y) {
                    printf("%c", 0xF4);
                }
                if (i==0&&j==3){
                    printf("%c", 0xCA);
                }
                if(i==9&&j==8){
                    printf("%c", 0xCB);
                }

                if (i == balleX && j == balleY) {
                    printf(MAGENTA_COLOR "%c", 0x9D);
                }
                if ((i == 5&& j == 19) || (i == 6 && j == 19) ||
                    (i == 7 && j == 19) || (i==8&&j==19)||(i == 8&& j == 18) || (i == 8 && j == 17)||(i == 9&& j == 15) || (i == 8 && j == 15)||(i == 7&& j == 15) || (i == 0 && j == 12)||(i == 1&& j == 12) || (i == 2 && j == 14)||(i == 1&& j == 14) || (i == 8 && j == 1)) {
                    printf("%c", 0xCE); //bloc bouge pas
                }
                if ((i == 4 && j == 20) || (i == 4 && j == 90) || (i == 4 && j == 18) ||
                    (i == 4 && j == 17) || (i == 4 && j == 16) || (i == 4 && j == 15) ||
                    (i == 4 && j == 14) || (i == 4 && j == 13) || (i == 4 && j == 12)||
                    (i==4&&j==11)||(i == 4 && j == 10) || (i == 4 && j == 9) || (i == 4 && j == 8) ||
                    (i == 4 && j == 7) || (i == 4 && j == 6) || (i == 4 && j == 5) ||
                    (i == 4 && j == 4) || (i == 4 && j == 3) || (i == 4 && j == 2)
                    ||(i==6&&j==14)||(i == 6 && j == 13) || (i == 6 && j == 12) || (i ==6 && j == 11) ||
                    (i == 6 && j == 10) || (i == 6 && j == 9) || (i == 6 && j == 8) ||
                    (i == 6 && j == 7) || (i == 6 && j == 6) || (i == 6 && j == 5)) {
                    printf("8"); //Bloc qui tue
                }

                else {
                    printf(RESET_COLOR"");
                    printf("%c", tab[i][j]);
                }
            }
            printf("\n");
        }

    }
    ShowConsoleCursor(FALSE);
    gotoligcol(11,0);
    printf(CYAN_COLOR "%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 0xDF, 0xDF, 0xDF, 0xDF, 0xDF, 0xDF, 0xDF, 0xDF, 0xDF, 0xDF, 0xDF, 0xDF, 0xDF, 0xDF, 0xDF, 0xDF, 0xDF, 0xDF, 0xDF, 0xDF, 0xDF, 0xDF);
    gotoligcol(0,0);
    printf(CYAN_COLOR"%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 0xDF, 0xDF, 0xDF, 0xDF, 0xDF, 0xDF, 0xDF, 0xDF, 0xDF, 0xDF, 0xDF, 0xDF, 0xDF, 0xDF, 0xDF, 0xDF, 0xDF, 0xDF, 0xDF, 0xDF, 0xDF);
    gotoligcol(0,22);
    printf("%c", 0xDB);
    gotoligcol(1,22);
    printf("%c", 0xDB);
    gotoligcol(2,22);
    printf("%c", 0xDB);
    gotoligcol(3,22);
    printf("%c", 0xDB);
    gotoligcol(4,22);
    printf("%c", 0xDB);
    gotoligcol(5,22);
    printf("%c", 0xDB);
    gotoligcol(6,22);
    printf("%c", 0xDB);
    gotoligcol(7,22);
    printf("%c", 0xDB);
    gotoligcol(8,22);
    printf("%c", 0xDB);
    gotoligcol(9,22);
    printf("%c", 0xDB);
    gotoligcol(10,22);
    printf("%c", 0xDB);
    //premier plan

    /* gotoligcol(0,0);
     printf("%c", 0xDB);
     gotoligcol(1,0);
     printf("%c", 0xDB);
     gotoligcol(2,0);
     printf("%c", 0xDB);
     gotoligcol(3,0);
     printf("%c", 0xDB);
     gotoligcol(4,0);
     printf("%c", 0xDB);
     gotoligcol(5,0);
     printf("%c", 0xDB);
     gotoligcol(6,0);
     printf("%c", 0xDB);
     gotoligcol(7,0);
     printf("%c", 0xDB);
     gotoligcol(8,0);
     printf("%c", 0xDB);
     gotoligcol(9,0);
     printf("%c", 0xDB);
     gotoligcol(10,0);
     printf("%c", 0xDB);*/
    printf(RESET_COLOR"");
}
void JeuGAGNE(int v, int S){
    char touche;
    system("cls");
    printf("Vous avez gagne la partie!! Felicitations...\n"
           "\n"
           "Vous avez obtenu un score de %d: \n"
           "Vous avez encore %d vies.\n"
           "Appuyez sur z pour continuer vers le niveau 2.\n",S,v);
    while (touche!='z'){
        touche= getch();
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
void NouveauxScores(int tab[4], int S1, int S2, int S3, int S4){
    tab[0]=S1;
    tab[1]=S2;
    tab[2]=S3;
    tab[3]=S4;
}

void FichierScore(int tab[4],int P){
    int i;
    FILE* pf;
    if (P==1){
        pf=fopen("./ScoresP1.txt","w");
    }
    if (P==2){
        pf=fopen("./ScoresP2.txt","w");
    }
    if (P==3){
        pf=fopen("./ScoresP3.txt","w");
    }
    if (P==4){
        pf=fopen("./ScoresP4.txt","w");
    }
    for ((i=0);(i<3);(i++)){
        fprintf(pf,"%d\n",tab[i]);
    }
    fclose(pf);
}

void SauvegardePartie(int tab[6], int NIV, int Vie, int Score, int T, int x, int y){
    tab[0]=NIV;
    tab[1]=Vie;
    tab[2]=Score;
    tab[3]=T;
    tab[4]=x;
    tab[5]=y;
}

void SauvegardeFichierPartie(int tab[6],int P){
    int i;
    FILE* pf;
    if (P==1){
        pf=fopen("./ValeursP1.txt","w");
    }
    if (P==2){
        pf=fopen("./ValeursP2.txt","w");
    }
    if (P==3){
        pf=fopen("./ValeursP3.txt","w");
    }
    if (P==4){
        pf=fopen("./ValeursP4.txt","w");
    }
    for ((i=0);(i<6);(i++)){
        fprintf(pf,"%d\n",tab[i]);
    }
}

void OuvrirSauvegarde(int tab[6],int*  Vie, int* Score, int* NIV, int* T, int* x, int* y){
    *NIV=tab[0];
    *Vie=tab[1];
    *Score=tab[2];
    *T=tab[3];
    *x=tab[4];
    *y=tab[5];

}
