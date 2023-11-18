
#ifdef _WIN32
#include "LIBRAIRIE SS PROG.h"
#include <windows.h>
#include <conio.h>
#include <unistd.h>
#endif
#include <stdio.h>

int CalculScoreNiv(int S, int t){
    return S*t;
}

int CalculScorePartie(int S1, int S2, int S3){
    return S1+S2+S3;
}
