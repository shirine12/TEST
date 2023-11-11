//
// Created by alban on 28/10/2023.
//

#include <stdio.h>
#include "LIBRAIRIE SS PROG.h"
#include <unistd.h>
#include <windows.h>
#include <conio.h>

int compteur(int* x){
    int *i=&x;
    while(x>0){
        *i=*i-1;
        sleep(1);
        gotoligcol(0,15);
        printf("        Il reste %d secondes pour completer le niveau.        ",*i);
    }
}

