#include <stdlib.h>
#include "pilha.h"

// Essa pilha será usada para validar a fórmula e para fazer a conversão para a forma pósfixa da fórmula

struct pilha {
    char info[MAX_P];
    int topo;
};

pilha *cria_pilha(){
    pilha *p = (pilha*)malloc(sizeof(pilha));
    if(p != NULL){
        p->topo = -1;
    }
    return p;
}

int pilha_vazia(pilha *p){
    if(p->topo == -1){
        return 1;   // pilha vazia
    }else{
        return 0;   // pilha não vazia
    }
}

int pilha_cheia(pilha *p){
    if(p->topo == MAX_P - 1){
        return 1;   // pilha cheia
    }else{
        return 0; // pilha vazia
    }
}

int push(pilha *p, char elem){
    if (pilha_cheia(p) == 1){
        return 0;
    }
    p->topo++;
    p->info[p->topo] = elem;
    return 1;
}

int pop(pilha *p, char *var){
    if(pilha_vazia(p) == 1){
        return 0;
    }
    *var = p->info[p->topo];
    p->topo--;
    return 1;
}

int get_topo(pilha *p, char *var){
    if(pilha_vazia(p) == 1){
        return 0;
    }
    *var = p->info[p->topo];
    return 1;
}

void apaga_pilha(pilha *p){
    free(p);
    p = NULL;
}

void esvazia_pilha(pilha *p){
    p->topo = -1;
}

int tamanho_pilha(pilha *p){
    return p->topo + 1;
}
