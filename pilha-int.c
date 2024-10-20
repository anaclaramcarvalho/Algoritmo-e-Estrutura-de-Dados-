#include <stdlib.h>
#include "pilha-int.h"

// Essa pilha será usada para interpretar a fórmula, armazenando os resultados das operações da fórmula

struct pilha_int{
    int valor[MAX_PI];
    int topo;
};

pilha_int *cria_pilha_int(){
    pilha_int *p = (pilha_int*)malloc(sizeof(pilha_int));
    if(p != NULL){
        p->topo = -1;
    }
    return p;
}

int pilha_int_vazia(pilha_int *p){
    if(p->topo == -1){
        return 1;   // pilha_int vazia
    }else{
        return 0;   // pilha_int não vazia
    }
}

int pilha_int_cheia(pilha_int *p){
    if(p->topo == MAX_PI - 1){
        return 1;   // pilha_int cheia
    }else{
        return 0;   // pilha_int vazia
    }
}

int push_int(pilha_int *p, int elem){
    if (pilha_int_cheia(p) == 1){
        return 0;
    }
    p->topo++;
    p->valor[p->topo] = elem;
    return 1;
}

int pop_int(pilha_int *p, int *var){
    if (pilha_int_vazia(p) == 1){
        return 0;
    }
    *var = p->valor[p->topo];
    p->topo--;
    return 1;
}

int get_topo_int(pilha_int *p, int *var){
    if (pilha_int_vazia(p) == 1){
        return 0;
    }
    *var = p->valor[p->topo];
    return 1;
}

void apaga_pilha_int(pilha_int *p){
    free(p);
    p = NULL;
}

void esvazia_pilha_int(pilha_int *p){
    p->topo = -1;
}

int tamanho_pilha_int(pilha_int *p){
    return p->topo + 1;
}
