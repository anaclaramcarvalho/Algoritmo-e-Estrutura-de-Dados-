#include <stdlib.h>
#include <stdio.h>
#include "exercicioC.h"

typedef struct matriz{
    float **mat;
    int linha, coluna;
}matriz;

matriz* criar(){
    matriz *m = (matriz**)malloc(sizeof(matriz*));
    m->linha = 0;
    m->coluna = 0;
    return m;
}

matriz* atribuir(matriz *m,int linha,int coluna, float num){
    m->mat[linha][coluna] = num;
}
