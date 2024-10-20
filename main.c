#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef struct {
    char cpf[12];
    char estadocivil[20];
    int numfilhos;
    char nomesfilhos[10][30];
}Cliente;

int main(){
    int opcao, numclientes = 0;
    Cliente clientes[MAX];
    do{
        printf("\nOpcoes:\n");
        printf("1. Inserir cliente\n");
        printf("2. Remover cliente\n");
        printf("3. Mostrar CPFs dos clientes\n");
        printf("4. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        switch (opcao){
            case 1:{
                if(numclientes < MAX){
                    Cliente novocliente;
                    printf("CPF do cliente: ");
                    scanf("%s", novocliente.cpf);
                    printf("Estado civil do cliente: ");
                    scanf("%s", novocliente.estadocivil);
                    printf("Numero de filhos: ");
                    scanf("%d", &novocliente.numfilhos);
                    for (int i = 0; i < novocliente.numfilhos; i++){
                        printf("Nome do filho %d: ", i + 1);
                        scanf("%s", novocliente.nomesfilhos[i]);
                    }
                    clientes[numclientes] = novocliente;
                    numclientes++;
                    printf("Cliente inserido com sucesso!\n");
                }else{
                    printf("Limite de clientes atingido.\n");
                }
                break;
            }
            case 2:{
                if(numclientes > 0){
                    int posicao;
                    printf("Digite a posicao do cliente a ser removido (0 a %d): ", numclientes - 1);
                    scanf("%d", &posicao);
                    if(posicao >= 0 && posicao < numclientes){
                        for (int i = posicao; i < numclientes - 1; i++){
                            clientes[i] = clientes[i + 1];
                        }
                        numclientes--;
                        printf("Cliente removido com sucesso!\n");
                    }else{
                        printf("Posicao invalida.\n");
                    }
                }else{
                    printf("Nao exite clientes para remover.\n");
                }
                break;
            }
            case 3:{
                printf("\nCPF dos clientes:\n");
                for (int i = 0; i < numclientes; i++) {
                    printf("%d. %s\n", i + 1, clientes[i].cpf);
                }
                break;
            }
            case 4:{
                printf("Encerrando o programa.\n");
                break;
            }
            default:{
                printf("Opcao invalida.\n");
                break;
            }
        }
    }while(opcao != 4);

    return 0;
}
