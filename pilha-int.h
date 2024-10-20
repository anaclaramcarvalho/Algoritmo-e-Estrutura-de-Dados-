#ifndef PILHA-INT_H_INCLUDED
#define PILHA-INT_H_INCLUDED
#define MAX_PI 100

typedef struct pilha_int pilha_int;

pilha_int *cria_pilha_int();
int pilha_int_vazia(pilha_int *p);
int pilha_int_cheia(pilha_int *p);
int push_int(pilha_int *p, int elem);
int pop_int(pilha_int *p, int *var);
int get_topo_int(pilha_int *p, int *var);
void apaga_pilha_int(pilha_int *p);
void esvazia_pilha_int(pilha_int *p);
int tamanho_pilha_int(pilha_int *p);


#endif // PILHA-INT_H_INCLUDED
