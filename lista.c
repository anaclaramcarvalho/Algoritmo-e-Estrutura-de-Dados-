#include <stdio.h>
#include <stdlib.h>
#include"lista.h"

//EXERCICIO A
typedef struct lista{
    int total;
    Aluno valores[MAX];
}Lista;

Lista *criar(){
    Lista *l = (Lista*)malloc(sizeof(Lista));
    if(l != NULL){
        l->total = 0;
    }
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
    if(listaCheia(l) == 0){
        return 1;
    }
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
    if(listaCheia(l) == 0){
        return 1;
    }
    l->valores[l->total] = item;
    l->total++;
    return 0;
}
int inserirPosicao(Lista *l,Aluno item, int posicao){
    if(l == NULL){
        return 2;
    }
    if(listaCheia(l) == 0){
        return 1;
    }
    if(posicao < 0 || posicao > MAX){
        return 3;
    }
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
    return 0;
}
int removerFim(Lista *l){
    if(l == NULL){
        return 2;
    }
    l->total--;
    return 0;
}
int removerPosicao(Lista *l,int posicao){
    if(l == NULL){
        return 2;
    }
    if(listaVazia(l) == 0){
        return 1;
    }
    if(posicao < 0 || posicao > MAX){
        return 3;
    }
    int i;
    for(i = posicao;i < l->total -1;i++){
        l->valores[i] = l->valores[i+1];
    }
    l->total--;
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
int listaCheia(Lista *l){
    if(l == NULL){
        return 2;
    }
    if(l->total == MAX){
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
         return l;
    }
}

//EXERCICIO B
int contemItem(Lista *l,int chave){
    if(l == NULL){
        return 2;
    }
    if(listaVazia(l) == 0){
        return 3;
    }
    int i;
    for(i = 0;i < l->total;i++){
        if(l->valores[i].matricula == chave){
            return 0;
        }else{
          return 1;
          }
    }
    return -1;
}

int reversa(Lista *l){
    if(l == NULL){
        return 2;
    }
    if(listaVazia(l) == 0){
        return 1;
    }
    Lista *listarev = criar();
    int i;
    for(i = 0;i < l->total;i++){
        inserirInicio(listarev,l->valores[i]);
    }
    return 0;
}

int contaItem(Lista *l, int chave){
    if(l == NULL){
        return 2;
    }
    if(listaVazia(l) == 0){
        return 1;
    }
    int i, count = 0;
    for(i = 0;i < l->total;i++){
        if(l->valores[i].matricula == chave){
            count++;
        }
    }
    return 0;
}
