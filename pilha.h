#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED
#define MAX_P 100

typedef struct pilha pilha;

pilha *cria_pilha();
int pilha_vazia(pilha *p);
int pilha_cheia(pilha *p);
int push(pilha *p, char elem);
int pop(pilha *p, char *var);
int get_topo(pilha *p, char *var);
void apaga_pilha(pilha *p);
void esvazia_pilha(pilha *p);
int tamanho_pilha(pilha *p);

#endif // PILHA_H_INCLUDED
