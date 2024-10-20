#include <stdio.h>
#include <stdlib.h>
#include "exercicioE.h"

int main() {
    Lista lista;
    lista = criar();
    Lista entrada, pares, impares;
    int tamanhoEntrada = 6;
    int dadosEntrada[] = {1, 2, 3, 4, 5, 6};
    inicializarLista(&entrada, tamanhoEntrada);
    entrada.dados = dadosEntrada;
    int resultado = separarParesImpares(&entrada, &pares, &impares);
    if (resultado == 0) {
        printf("Numeros Pares: ");
        for (int i = 0; i < pares.tamanho; i++) {
            printf("%d ", pares.dados[i]);
        }
        printf("\nNumeros Impares: ");
        for (int i = 0; i < impares.tamanho; i++) {
            printf("%d ", impares.dados[i]);
        }
        liberarLista(&entrada);
        liberarLista(&pares);
        liberarLista(&impares);

        return 0;
    } else {
        printf("Erro na operacao.\n");
        return resultado;
    }
}
