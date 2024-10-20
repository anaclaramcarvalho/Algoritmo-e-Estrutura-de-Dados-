#include <stdio.h>
#include <stdlib.h>
#include"listad.h"

typedef struct lista{
    int total;
    Aluno *valores;
}Lista;

Lista *criar(){
    Lista *l = (Lista*)malloc(sizeof(Lista));
    if(l != NULL){
        l->total = 0;
    }
    return l;
}
void limpar(Lista *l){
    if(l != NULL){
        l->total = 0;
    }
}

int inserirInicio(Lista *l,Aluno item){
    int i;
    if(l == NULL){
        return 2;
    }
    l->valores = realloc(l->valores ,sizeof(l->valores)+1);
    for(i = l->total;i>0;i--){
        l->valores[i] = l->valores[i-1];
    }
    l->valores[0] = item;
    l->total++;
    return 0;
}
int insereFim(Lista *l, Aluno item){
    if(l == NULL){
        return 2;
    }
    l->valores = realloc(l->valores ,sizeof(l->valores)+1);
    l->valores[l->total] = item;
    l->total++;
    return 0;
}
int inserirPosicao(Lista *l,Aluno item, int posicao){
    if(l == NULL){
        return 2;
    }
    if(posicao < 0){
        return 3;
    }
    l->valores = realloc(l->valores ,sizeof(l->valores)+1);
    int i;
    for(i = l->total;i > posicao;i--){
        l->valores[i] = l->valores[i-1];
    }
    l->valores[posicao] = item;
    l->total++;
    return 0;
}

int removerInicio(Lista *l){
    int i;
    if(l == NULL){
        return 2;
    }
    if(listaVazia(l) == 0){
        return 1;
    }
    for(i = 0;i<l->total;i++){
        l->valores[i] = l->valores[i+1];
    }
    l->total--;
    l->valores = realloc(l->valores ,sizeof(l->valores)-1);
    return 0;
}
int removerFim(Lista *l){
    if(l == NULL){
        return 2;
    }
    l->total--;
   l->valores = realloc(l->valores ,sizeof(l->valores)-1);
    return 0;
}
int removerPosicao(Lista *l,int posicao){
    if(l == NULL){
        return 2;
    }
    if(listaVazia(l) == 0){
        return 1;
    }
    if(posicao < 0){
        return 3;
    }
    int i;
    for(i = posicao;i < l->total -1;i++){
        l->valores[i] = l->valores[i+1];
    }
    l->total--;
    l->valores = realloc(l->valores ,sizeof(l->valores)-1);
    return 0;
}
int removerItem(Lista *l,int chave){
    if(l == NULL){
        return 2;
    }
    if(listaVazia(l) == 0){
        return 1;
    }
    int i;
    for(i = 0;i < l->total;i++){
        if(l->valores[i].matricula == chave){
           removerPosicao(l,i);
           i--;
      }
    }
    l->total--;
    l->valores = realloc(l->valores ,sizeof(l->valores)-1);
    return 0;
}

int buscarItem(Lista *l, int item,Aluno *retorno){
    int i;
    if(l == NULL){
        return 2;
    }
    if(listaVazia(l) == 0){
        return 1;
    }
    for(i = 0;9 < l->total;i++){
        if(l->valores[i].matricula == item){
            *retorno = l->valores[i];
            return 0;
        }
    }
    return -1;
}
int buscaPosicao(Lista *l,int posicao,Aluno *item){
    if(l == NULL){
        return 2;
    }
    if(listaVazia(l) == 0){
        return 1;
    }
    int i;
    for(i = 0;i < l->total;i++){
        if(i == posicao){
            *item = l->valores[i];
            return 0;
        }
    }
    return -1;
}

int listaVazia(Lista *l){
    if(l == NULL){
        return 2;
    }
    if(l->total == 0){
        return 0;
    }else{
        return 1;
    }
}
void mostrar(Lista *l){
    int i;
    if(l != NULL){
        printf("[");
        for(i = 0;i< l->total;i++){
            printf("{%d,", l->valores[i].matricula);
            printf("%s,", l->valores[i].nome);
            printf("%.2f}\n",l->valores[i].nota);
        }
         printf("]\n");
    }
}
