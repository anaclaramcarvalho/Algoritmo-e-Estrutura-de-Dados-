#include <stdlib.h>
#include <stdio.h>
#include "exercicioB.h"

typedef struct conjunto{
    int n[100];
    int tam;
}conjunto;

conjunto* criar(){
    conjunto *c = (conjunto*)malloc(sizeof(conjunto));
    c->tam = 0;
    return c;
}

int membro(conjunto *c,int num){
    int i;
    for(i = 0;i < c->tam;i++){
        if(c->n[i] == num){
            return 0;
        }
    }
    return 1;
}

int insere(conjunto *c,int num){
    if(c->tam == 99){
        return 1;
    }
    c->n[c->tam] = num;
    c->tam++;
    return 0;
}

int remove(conjunto *c, int num){
    int i,j;
    for(i = 0;i < c->tam;i++){
        if(c->n[i] == num){
            for(j = i;j < c->tam;j++){
                 c->n[j] = c->n[j+1];
            }
        }
    }
    c->tam--;
    return 0;
}

conjunto* uniao(conjunto *c,conjunto *d){
    conjunto *u = criar();
    int i,j;
    for(i = 0;i < c->tam;i++){
        insere(u,c->n[i]);
    }
    for(j = 0;j < d->tam;j++){
        insere(u,d->n[j]);
    }
    return u;
}

conjunto* intersecao(conjunto *c,conjunto *d){
    conjunto *i = criar();
    int j;
    for(j= 0;j < c->tam;j++){
       if(membro(d, c->n[i]) == 0){
            insere(i,c->n[i]);
       }
    }
    return i;
}

conjunto* diferenca(conjunto *c,conjunto *e){
    conjunto *d = criar();
    int i;
    for(i = 0;i < c->tam;i++){
        if(membro(e,c->n[i]) == 1){
            insere(d,c->n[i]);
        }
    }
    return d;
}

void imprime(conjunto* c) {
    int i;
    for(i = 0;i < c->tam;i++){
        printf("%d",c->n[i]);
    }
}
