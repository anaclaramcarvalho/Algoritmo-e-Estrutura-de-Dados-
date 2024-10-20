#include <stdio.h>
#include <stdlib.h>

int main(){
   printf("Entre com o valor: ");
    int n;
    scanf("%d",&n);
    int i,acc = 1;
    for (i=n;i>0;i--)
    acc = acc * i;
    printf("O valor do fatorial de %d eh %d",n,acc);
}
//achei tranquilo , fiz o teste com o 0 porem nao deu certo e ai lembrei que todo numero multiplicado por 0 é 0 , logo essa não seria a solução
