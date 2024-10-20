#include <stdio.h>
#include <stdlib.h>
#include<math.h>

/*
int verificar(char letra, char *text){
    int i;
    for(i = 0;i =! '\0';i++){
        if(letra == text[i] ){
            return 1;
        }
    }
    return 0;
}

int ocorrencias(char *texto, char *text, char *repeticoes){
    int i;
    for(i = 0;i != '\0';i++){
        if(verificar(texto[i],text) == 0){
            *text = (char *)realloc(text,sizeof(char)*(strlen(text)+1));
            text = texto[i];
        }else {
            repeticoes[i]++;
        }
    }
}
*/
/*
void ninteiros(int tam,int *vet,float *media,int *maior){
    int i, m = 0;
    for(i = 0;i < tam;i++){
        if(vet[i] > *maior){
            *maior = vet[i];
            m = m + vet[i];
        }
    }
    *media = m/2;
}
*/
/*
void ocorrecias(char *vet,int tam, char caracter,int *count){
     int i;
     for(i = 0;i < tam;i++){
        if(vet[i] == caracter){
            vet[i] = '*';
            *count++;
        }
     }
 }

/*
int fatorial(int n){
    int i,fat = 1;
    if(n == 0){
        fat = 0;
    }else{
        for(i = 2;i <= n;i++){
            fat = fat * i;
        }
    }
    return fat;
}
*/
/*
void calculaHexagono(float l, float *area, float *perimetro){
    *area = (3*(l*l)*sqrt(3))/2;
    *perimetro = 6*l;
}
*/
/*
int divisao(int a, int b,float *quociente, float *resto){
    if(b == 0){
        return -1;
    }else{
        *quociente = a/b;
        *resto = a%b;
    }
    return 0;
}
*/
/*
float taylor(int baseT,int expoenteT){
    int soma = 0,i;
    float result = 0;
    for(i = 2;i <= expoenteT;i++){
        soma = soma + (expoente(baseT,i)/fatorial(i));
    }
    result = 1 + baseT + soma;
    return result;
}
*/
/*
int expoente(int base,int exp){
    int i, result = 1;
    for(i = 0;i < exp;i++){
        result *= base;
    }
    return result;
}
*/
/*
int soma(int n){
    int i,soma = 0;
    for(i = 1;i <= n;i++){
        soma += i;
    }
    return soma;
}
*/

int main(){

//EXERCICIO A
/*
    int n = 0;
    printf("Digite ate que numero voce quer somar: ");
    scanf("%d",&n);
    printf("A soma dos numeros e: %d.",soma(n));

*/
//EXERCICIO B
/*
    int base = 0,exp = 0;
    printf("Digite a base: ");
    scanf("%d", &base);
    printf("Digite o exepoente: ");
    scanf("%d",&exp);
    printf("O resultado e: %d.", expoente(base,exp));
*/
//EXERCICIO C
/*
    int expoenteT ,baseT;
    printf("Ate qual expoente voce quer que a serie de taylor va: ");
    scanf("%d", &expoenteT);
    printf("Digite a base: ");
    scanf("%d",&baseT);
    printf("O resultado do taylor e %.2f.",taylor(expoenteT,baseT));
*/
//EXERCICIO D
/*
    float a = 0,b = 0,quociente = 0,resto = 0;
    printf("Digite o dividendo: ");
    scanf("%f",&a);
    printf("Digite o divisor: ");
    scanf("%f",&b);
    divisao(a,b,&quociente,&resto);
    printf("O quociente da divisao e: %.2f.\n",quociente);
    printf("O resto da divisao e: %.2f.",resto);

*/
//EXERCICIO E
/*
    float l = 0,area = 0,perimetro = 0;
    printf("Digite o tamanho do lado: ");
    scanf("%f",&l);
    calculaHexagono(l,&area,&perimetro);
    printf("A area do hexagono e: %2f.\n", area);
    printf("O perimetro do hexagono e: %.2f",perimetro);

*/
//EXERCICIO F
/*
    char *vet, caracter;
    int tam = 0,i,*count;
    printf("Digite o tamanho do vetor: ");
    scanf("%d",&tam);
    printf("Digite a string: ");
    for(i = 0;i < tam;i++){
        scanf("%c",&vet[i]);
    }
    while((getchar()) != '\n');
    printf("Digite o caracter escolhido: ");
    scanf("%c", &caracter);
    ocorrecias(vet,tam,caracter,&count);
    printf("\nO numero de ocorrencias foi: %d.",*count);

*/
//EXERCICIO G
/*
*/

//EXERCICIO H
/*
    char texto[400], *text, *repeticoes;
    char lx;
    int i;
    printf("Digite seu texto e coloque ENTER quando acabar: ");
    for(i = 0;scanf("%c", &lx) && lx != '\n';++i){
        texto[i] = lx;
    }
    texto[i] = '\0';


*/
//EXERCICIO I
/*
    int *vet, tam = 0,i,*maior;
    float *media;
    printf("Digite o tamanho do vetor: ");
    scanf("%d",&tam);
    for(i = 0;i <= tam;i++){
        printf("Digite o valor: ");
        scanf("%d",vet[i]);
    }
    ninteiros(tam,vet,&media,&maior);
    printf("A media dos numeros digitados foi %.2f.", *media);
    printf("O maior numero digitado foi %d.",*maior);
*/
    return 0;
    }
