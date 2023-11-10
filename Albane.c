//
// Created by alban on 28/10/2023.
//

#ifdef _WIN32
#include "LIBRAIRIE SS PROG.h"
#include <windows.h>
#include <conio.h>
#endif
#include <stdio.h>

void menu(){
    printf("--------------------------------------\n"
            "BIENVENUE SUR LA REVANCHE DE SNOOOPY\n"
           "--------------------------------------\n"
           "1. Afficher les regles\n"
           "2. Lancer une partie\n"
           "3. Charger une partie\n"
           "4. Afficher les mots de passe\n"
           "5. Afficher les scores\n"
           "6. Quitter\n\n");
}

void Locate(int x,int y)
{
#ifdef _WIN32
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    COORD C;
    C.X=(SHORT)x;
    C.Y=(SHORT)y;
    SetConsoleCursorPosition(H,C);
#endif
    // trouver alternative hors Windows.
}


void InitialiserVie(int a) {
    a = 3;
}


void NiveauCasesVides(unsigned char tab[Nc][Nl]){
    int i,f;
    for ((i=0);(i<Nc);(i++)){
        for ((f=0);(f<Nl);(f++)) {
            tab[i][f]=0x00;
        }
    }
}

void AfficherNiv(int x,int y, int balleX, int balleY, unsigned char tab[Nc][Nl])
{
    int i,j;
    Locate(0,0);
    for(i=0;i<Nc;i++)
    {
        for(j=0;j<Nl;j++)
        {
            if (i==x && j==y)
                printf("3");
            if ((i==balleX)&&(j==balleY)){
                printf("o");
            }
            else
                printf("%c",tab[i][j]);
        }
        printf("\n");
    }
}

//||((k!='z')||(k!='d')||(k!='q')||(k!='s')){

void Deplacement( int x, int y, unsigned char tab[Nc][Nl], int touche, int S){
    touche=MyGetch();
    switch(touche)
    {
        case 'q':
            TryMove(&x,&y,0,-1,tab,1,&S);
            break;
        case 'd':
            TryMove(&x,&y,0,1,tab,3,&S);
            break;
        case 'z':
            TryMove(&x,&y,-1,0,tab,2,&S);
            break;
        case 's':
            TryMove(&x,&y,1,0,tab,4,&S);
        default:
            break;
    }
}


//if (a == 'z') {
//Init(x, y, tab);
//x=x-1;
//InitSnoopy(x, y, tab);
//}
