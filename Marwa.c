//
// Created by alban on 28/10/2023.
//

#ifdef _WIN32
#include "LIBRAIRIE SS PROG.h"
#include <windows.h>
#include <conio.h>
#endif
#include <stdio.h>

int MyGetch()
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
        if (*x+vx==0 || *x+vx==9 ||*y+vy==0 || *y+vy==9){
            return;
        }
        else {
            tab[*x + vx+ vx][*y + vy + vy] = 'X';
        }
    }
    if (tab[*x + vx][*y + vy]=='0'){
        *S=*S+1;
    }

    tab[*x][*y]=' ';
    (*x) += vx;
    (*y) += vy;
}