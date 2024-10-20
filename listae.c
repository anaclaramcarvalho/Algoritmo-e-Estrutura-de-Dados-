#include <stdio.h>
#include <stdlib.h>
#include"listae.h"

void inicializarContagem(ContagemCaractere contagem[]){
    for (int i = 0; i < MAX; i++) {
        contagem[i].caractere = 'a' + i;
        contagem[i].contagem = 0;
    }
}

void atualizarContagem(ContagemCaractere contagem[], char c){
    if (c >= 'a' && c <= 'z'){
        contagem[c - 'a'].contagem++;
    }
}

void exibirHistograma(ContagemCaractere contagem[]){
    printf("Histograma de ocorrencias de caracteres:\n");
    for (int i = 0; i < NUM_CARACTERES; i++){
        printf("%c: %d\n", contagem[i].caractere, contagem[i].contagem);
    }
}
