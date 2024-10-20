#ifndef EXERCICIOB_H_INCLUDED
#define EXERCICIOB_H_INCLUDED

typedef struct conjunto *conjunto;

conjunto* criar();
int membro(conjunto *c, int num);
int insere(conjunto *c, int num);
int remove(conjunto *c, int num)
conjunto* uniao(conjunto *c,conjunto *d);
conjunto* intersecao(conjunto *c,conjunto *d);
conjunto* diferenca(conjunto *c,conjunto *e);
void imprime(conjunto *c);

#endif // EXERCICIOB_H_INCLUDED
