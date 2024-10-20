#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

// Essa lista será usada para armazenar as fórmulas do programa

typedef struct no{
    char valor[MAX];
    struct no *proximo;
}No;

typedef struct lista{
    No *inicio;
    int tam;
}Lista;

Lista *criar(){
    Lista *l = (Lista*)malloc(sizeof(Lista));
    l->inicio = NULL;
    l->tam = 0;
    return l;
}

int listaVazia(Lista *l){
    if(l == NULL){
        return 2;
    }
    if(l->inicio == NULL){
        return 0;
    }
 return 1;
}

int inserirInicio(Lista *l, char* item){
    if(l == NULL){
        return 2;
    }
    No *no = (No*)malloc(sizeof(No));
    strcpy(no->valor, item);
    no->proximo = l->inicio;
    l->inicio = no;
    l->tam++;
    return 0;
}

int buscarPosicao(Lista *l, int posicao, char *retorno){
    if(l == NULL){
        return 2;
    }

    No *noLista = l->inicio;
    int i = 0;
    while((noLista != NULL)){
        if(i == posicao) {
            strcpy(retorno, noLista->valor);
            return 0;
        }
        i++;
        noLista = noLista->proximo;
    }
    return 1;
}

void mostrar(Lista *l){
    int i = 0;
    if(l != NULL){
        No *noLista = l->inicio;
        while(noLista != NULL){
            printf("[%d] %s\n", i, noLista->valor);
            noLista = noLista->proximo;
            i++;
        }
    }
}

int concatenaFormulas (Lista *l, int posicao, char* novaFormula){
    if(l == NULL){
        return 2;
    }
    No *noLista = l->inicio;
    int i = 0;
    while((noLista != NULL)){
        if(i == posicao){
            strcpy(noLista->valor, novaFormula);
            return 0;
        }
        i++;
        noLista = noLista->proximo;
    }
    return 1;
}

int tamanhoLista (Lista *l){
    if(l == NULL){
        return -1;
    }else{
        return l->tam;
    }
}

void apagaLista (Lista *l){
    No *noLista = l->inicio;
    No *aux;
    while(noLista != NULL){
        aux = noLista;
        noLista = noLista->proximo;
        free(aux);
    }
    free(noLista);
    l = NULL;
}
