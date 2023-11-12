#include <stdio.h>
#include "LIBRAIRIE SS PROG.h"
#include <conio.h>
#include <windows.h>
#include <unistd.h>

void DeplacementBalle(int* balleX,int* balleY,int*vx, int*vy, unsigned char tab[Nc][Nl]){
    tab[*balleX][*balleY]=' ';
    if ((tab[*balleX+*vx][*balleY+*vy]=='0') || (tab[*balleX+*vx][*balleY+*vy]=='X')){
        *vy = *vy*(-1);
        *vx = -1 * *vx;
        system("cls");
    }
        *balleX = *balleX + *vx;
        *balleY = *balleY + *vy;

        if (*balleY <= 0 || *balleY >= 19) {//(hauteur matrice-1)
            *vy = *vy*(-1); // Inverse la direction verticale
        system("cls");
        }
        if (*balleX <= 0 || *balleX >= 9) {//(largeur matrice-1)
            *vx = -1 * *vx; // Inverse la direction horizontale
         system("cls");
        }
}

void gotoligcol( int lig, int col )
{
// ressources
    COORD mycoord;
    mycoord.X = col;
    mycoord.Y = lig;
    SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), mycoord );
}
void ShowConsoleCursor(int showFlag){
    //Permet de retirer le curseur (trouvé à partir de recherches internet qui ont demandés de la réflexion)//
HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
CONSOLE_CURSOR_INFO cursorInfo;

GetConsoleCursorInfo(consoleHandle, &cursorInfo);
cursorInfo.bVisible = showFlag;
SetConsoleCursorInfo(consoleHandle, &cursorInfo);
}
