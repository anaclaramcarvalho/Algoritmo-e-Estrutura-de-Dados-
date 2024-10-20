#include <stdio.h>
#include <stdlib.h>
#include"listae.h"

int main(){
   char texto[MAX_TEXTO];
    ContagemCaractere contagem[NUM_CARACTERES];
    printf("Digite um texto (maximo de %d caracteres):\n", MAX_TEXTO);
    fgets(texto, sizeof(texto), stdin);
    if (strlen(texto) > 0 && texto[strlen(texto) - 1] == '\n') {
        texto[strlen(texto) - 1] = '\0';
    }
    inicializarContagem(contagem);
    for (int i = 0; texto[i] != '\0'; i++){
        atualizarContagem(contagem, texto[i]);
    }
    exibirHistograma(contagem);
    return 0;
}
