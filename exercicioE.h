#ifndef EXERCICIOE_H_INCLUDED
#define EXERCICIOE_H_INCLUDED

typedef struct Lista;
void inicializarLista(Lista *lista, int tamanho);
void liberarLista(Lista *lista);
int separarParesImpares(const Lista *entrada, Lista *pares, Lista *impares);


#endif // EXERCICIOE_H_INCLUDED
