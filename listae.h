#ifndef LISTAE_H_INCLUDED
#define LISTAE_H_INCLUDED
#define MAX 200

typedef struct {
    char caractere[200];
    int contagem;
} ContagemCaractere;
void inicializarContagem(ContagemCaractere contagem[]);
void atualizarContagem(ContagemCaractere contagem[], char c);
void exibirHistograma(ContagemCaractere contagem[]);

#endif // LISTAE_H_INCLUDED
