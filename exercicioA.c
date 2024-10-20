#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "exercicioA.h"

struct string {
    char* info;
    int tamanho;
};

typedef struct string string;

string* criar(){
    string* s = (string*)malloc(sizeof(string));
    if (s != NULL) {
        s->tamanho = 0;
        s->info = (char*)malloc(sizeof(char));
    }

    return s;
}

string* criar_t (int tam) {
    string* s = (string*)malloc(sizeof(string));
    if (s != NULL) {
        s->info = (char*)malloc(sizeof(char) * tam);
        s->tamanho = tam;
    }

    return s;
}

void associa (string* s, char* var) {
    int novo_tam = strlen(var);

    if (s->tamanho < novo_tam)
        s->info = (char*)realloc(s->info, sizeof(char) * novo_tam);

    strcpy(s->info, var);
    s->tamanho = novo_tam;
}

int tamanho (string* s) {
    return s->tamanho;
}

void imprime (string* s) {
    if (s != NULL)
        printf("%s\n", s->info);
}

int ocorrencias (string* s, char c) {
    int count = 0;
    for (int i = 0; i < s->tamanho; i++)
        if (s->info[i] == c)
            count++;
    return count;
}





