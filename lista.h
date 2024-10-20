#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#define MAX 100

typedef struct lista Lista;

Lista *criar();

int inserirInicio(Lista *l, char *item);
int buscarPosicao(Lista* l, int posicao, char *retorno);
int listaVazia(Lista *l);
void mostrar(Lista *l);
int concatenaFormulas(Lista *l, int pos, char* novaForm);
int tamanhoLista(Lista *l);
void apagaLista (Lista *l);

#endif // LISTA_H_INCLUDED
