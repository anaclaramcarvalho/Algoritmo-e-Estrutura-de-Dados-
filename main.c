#include <stdio.h>
#include <stdlib.h>

int main(){
    int atual = 0,nasci = 0, idade = 0;
    printf("Digite o ano atual: ");
    scanf("%d",&atual);
    printf("Digite o ano em que voce nasceu: ");
    scanf("&d", &nasci);
    idade = atual - nasci;
    printf("\nA sua idade e %d.", idade);
    idade = 2030 - nasci;
    printf("\nEm 2030 voce tera %d", idade);
    return 0;
}
//Durante a aula eu fiz ate a linha 11 e funcionou perfeitamente, depois eu vi que tinha a parte de 2030 e completei, porem não está querendo receber o ano do nascimento, ele só recebe o atual e para o programa.
