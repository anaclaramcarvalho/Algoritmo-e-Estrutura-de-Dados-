#ifndef LISTAD_H_INCLUDED
#define LISTAD_H_INCLUDED

typedef struct aluno{
    int matricula;
    char nome[30];
    float nota;
}Aluno;
typedef struct lista Lista;

Lista *criar();
void limpar(Lista *l);
int tamanho(Lista *l);
void mostrar(Lista *l);

int inserirInicio(Lista *l,Aluno item);
int insereFim(Lista *l, Aluno item);
int inserirPosicao(Lista *l,Aluno item, int posicao);

int removerInicio(Lista *l);
int removerFim(Lista *l);
int removerPosicao(Lista *l,int posicao);
int removerItem(Lista *l,int chave);

int buscarItem(Lista *l, int chave,Aluno *retorno);
int buscaPosicao(Lista *l,int posicao,Aluno *item);

int listaVazia(Lista *l);

#endif // LISTAD_H_INCLUDED
