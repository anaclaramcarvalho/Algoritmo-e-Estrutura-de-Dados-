#include <stdio.h>
#include <stdlib.h>
#include "exercicioE.h"

typedef struct lista{
    int *dados;
    int tamanho;
}Lista;

void inicializarLista(Lista *lista, int tamanho){
    lista->dados = (int *)malloc(tamanho * sizeof(int));
    lista->tamanho = tamanho;
}

void liberarLista(Lista *lista){
    free(lista->dados);
}

int separarParesImpares(const Lista *entrada, Lista *pares, Lista *impares){
    if (entrada == NULL || pares == NULL || impares == NULL) {
        return 1;
    }
    inicializarLista(pares, entrada->tamanho);
    inicializarLista(impares, entrada->tamanho);
    int indicePares = 0, indiceImpares = 0;
    for (int i = 0; i < entrada->tamanho; i++) {
        if (entrada->dados[i] % 2 == 0) {
            pares->dados[indicePares++] = entrada->dados[i];
        } else {
            impares->dados[indiceImpares++] = entrada->dados[i];
        }
    }
    pares->tamanho = indicePares;
    impares->tamanho = indiceImpares;

    return 0;
}
