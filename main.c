#include <stdio.h>
#include <stdlib.h>

typedef struct livro{
    char titulo[100];
    int anodeedicao;
    int numpag;
    float preco;
}Livro;

int main(){
    Livro livro[5];
    int totalpag = 0;
    for (int i = 0; i < 5; i++){
        printf("=======================================");
        printf("\nLivro %d:\n", i++);
        printf("Titulo: ");
        scanf("%s", &livro[i].titulo);
        printf("Ano de Edicao: ");
        scanf("%d", &livro[i].anodeedicao);
        printf("Numero de Paginas: ");
        scanf("%d", &livro[i].numpag);
        printf("Preco: ");
        scanf("%f", &livro[i].preco);
        printf("=======================================");
        printf("\n");
}
    for (int i = 0; i < 5; i++) {
        totalpag += livro[i].numpag;
}
    float mediapag = totalpag / 5;
    printf("Media do numero de paginas dos livros: %.2f\n", mediapag);
    return 0;
}
//Estava funcionando porem deu problema na linha 12 e eu não entendi o problema para resolver.
