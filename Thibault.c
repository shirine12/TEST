#include <stdio.h>
#include "LIBRAIRIE SS PROG.h"
#include <conio.h>
#include <windows.h>
#include <unistd.h>

void DeplacementBalle(int* balleX,int* balleY,int*vx, int*vy){
        *balleX = *balleX + *vx;
        *balleY = *balleY + *vy;

        if (*balleY <= 0 || *balleY >= 9) {//(hauteur matrice-1)
            *vy = *vy*(-1); // Inverse la direction verticale
        }
        if (*balleX <= 0 || *balleX >= 9) {//(largeur matrice-1)
            *vx = -1 * *vx; // Inverse la direction horizontale
        }
}
