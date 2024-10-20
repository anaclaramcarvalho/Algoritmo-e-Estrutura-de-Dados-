#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "lista.h"
#include "pilha.h"
#include "pilha-int.h"

#define MAX_LETRAS 27

// struct para armazenar as variáveis e seus valores
typedef struct dicio{
    char variavel;
    int valor;
} dicio;

int verificaFormula (char *formula){
    pilha *p_par = cria_pilha();
    pilha *p_ope = cria_pilha();
    char topo = '/', topo_op = '/', lx;
    for(int i = 0; formula[i] != '\0'; ++i) {
        if(pilha_vazia(p_par) != 1)     // se a pilha não estiver vazia, vê qual é o topo da pilha
            get_topo(p_par, &topo);
        if(pilha_vazia(p_ope) != 1)    // se a pilha não estiver vazia, vê qual é o topo da pilha
            get_topo(p_ope, &topo_op);
        switch(formula[i]){
            case '(' :
                push(p_par, formula[i]);
                break;
            case ')' :
                if(pilha_vazia(p_par) == 1 || topo != '('){
                    printf("Expressao invalida. Fechador de escopo '(' sem sua abertura correspondente ')'.\n");
                    apaga_pilha(p_par);
                    return 0;
                }
                pop(p_par, &lx);
                break;
            case '|' : case '&' :
                // se a pilha de variveis/operadores estiver vazia, então o primeiro elemento é um  operador
                // ou se o topo da pilha não for um alfanumerico, então temos dois operadores seguidos
                // & p | q ou p & & q
                if(pilha_vazia(p_ope) == 1 || isalpha(topo_op) == 0){
                    printf("Expressao invalida. Operador sem variavel.\n");
                    apaga_pilha(p_par);
                    apaga_pilha(p_ope);
                    return 0;
                }
                push(p_ope, formula[i]);
                break;
            case 'A' ... 'Z':  case 'a' ... 'z':
                if(isalpha(topo_op) != 0){
                    printf("Expressao invalida. Duas variaveis seguidas.\n");
                    apaga_pilha(p_par);
                    apaga_pilha(p_ope);
                    return 0;
                }
                push(p_ope, formula[i]);
                break;
            case ' ':  break;
            default:
                printf("Digite apenas caracteres validos.\n");
                apaga_pilha(p_par);
                apaga_pilha(p_ope);
                return 0;
        }
    }
    get_topo(p_par, &topo);
    get_topo(p_ope, &topo_op);
    if(pilha_vazia(p_par) != 1){
        printf("Expressão invalida. Numero de escopos abertos e diferente do numero de escopos fechados.\n");
        apaga_pilha(p_par);
        apaga_pilha(p_ope);
        return 0;
    }
    // se o topo da pilha ao fim da fórmula for um operador, então está errado
    // p & q &
    else if (isalpha(topo_op) == 0) {
        printf("Expressao invalida. Operador sem variavel.\n");
        apaga_pilha(p_par);
        apaga_pilha(p_ope);
        return 0;
    }else{
        apaga_pilha(p_par);
        apaga_pilha(p_ope);
        return 1;
    }
}

// se op1 tem precedencia sobre op2, retorna 1
// se op2 tem precedencia sobre op1, retorna -1
// se a precedencia é igual, retorna 0
int compara_prec(char op1, char op2){
    if(op1 == '&' && op2 == '|'){
        return 1;
    }else if(op1 == '|' && op2 == '&'){
        return -1;
    }else{
        return 0;
    }
}

int convertePosfixa (char* formula){
    char topo, lx, posfixa[MAX];
    int i, j = 0;
    pilha *p = cria_pilha();
    for (i = 0; formula[i] != '\0'; ++i) {
        switch(formula[i]){
            case '(':
                push(p, formula[i]);
                break;
            case ')':
                // enquanto não encontrar o fim do escopo, preenche a posfixa com os elementos da pilha
                for(; get_topo(p, &topo) && topo != '('; ++j){
                    pop(p, &posfixa[j]);
                }
                pop(p, &lx);
                break;
            case 'A' ... 'Z': case 'a' ... 'z':
                posfixa[j] = formula[i];
                j++;
                break;
            case '&': case '|':
                for(;pilha_vazia(p) == 0 && get_topo(p, &topo) && topo != '(' && compara_prec(topo, formula[i]) >= 0; ++j){
                    pop(p, &posfixa[j]);
                }
                push(p, formula[i]);
                break;
            case ' ': break;
            default: return 0;
        }
    }
    while (pilha_vazia(p) == 0){
        pop(p, &posfixa[j]);
        j++;
    }
    posfixa[j] = '\0';
    strcpy(formula, posfixa);
    apaga_pilha(p);
    return 1;
}

// recebe o vetor de valores das variáveis e uma variável e retorna o valor associado aquela variável
int buscaValor(dicio *vet, char var){
    for(int i = 0; i < MAX_LETRAS; ++i){
        if(vet[i].variavel == toupper(var)){
            return vet[i].valor;
        }
    }
    return -1;
}

void interpretaFormula(char* formula){
    dicio valores[MAX_LETRAS];
    int i, j;
    for(i = 0; i < MAX_LETRAS; ++i){
        valores[i].variavel = '\0';
        valores[i].valor = -1;
    }

    for(i = 0; formula[i] != '\0'; ++i){
        char c = toupper(formula[i]);
        if(c >= 'A' && c <= 'Z'){
            int index = -1;         // armazena a posição da variável no vetor valores
            for(j = 0; j < MAX_LETRAS; ++j){
                // se a letra já foi lida antes
                if(valores[j].variavel == c){
                    index = j;
                    break;
                }
            }
            // caso a letra não tenha sido lida antes
            if(index == -1){
                printf("Digite o valor para a variavel %c (0 = FALSE; 1 = TRUE) : ", c);
                scanf("%d", &valores[i].valor);
                valores[i].variavel = c;
            }
        }
    }
    pilha_int *p = cria_pilha_int();
    int op1, op2, resultado;
    for(i = 0;formula[i] != '\0'; ++i){
        switch(formula[i]){
            case 'A' ... 'Z' : case 'a' ... 'z' :
                push_int(p, buscaValor(valores, formula[i]));
                break;
            case '&':
                // retira os dois ultimos valores da pilha
                pop_int(p, &op1);
                pop_int(p, &op2);
                resultado = op1 && op2;
                push_int(p, resultado);
                break;
            case '|':
                pop_int(p, &op1);
                pop_int(p, &op2);
                resultado = op1 || op2;
                push_int(p, resultado);
                break;
            case ' ': break;
        }
    }
    pop_int(p, &resultado);
    printf("Resultado da formula: ");
    if(resultado == 0){
        printf("FALSO\n");
    }else{
        printf("VERDADEIRO\n");
    }
}


int main(){
    printf("         Bem vindo !           ");
    int pos, pos2, val = -1, i, flag = 0;
    char opcao, subf[MAX], temp[MAX];
    Lista *l;
    l = criar();
    do{
        printf("\n-----------------------------------------------\n");
        printf("   Analisador de formula da Logica Proposicional\n");
        printf("[1] Cadastrar uma formula.\n");
        printf("[2] Inserir uma subformula a outra.\n");
        printf("[3] Mostrar as formulas cadastradas.\n");
        printf("[4] Interpretar formula.\n");
        printf("[5] Sair do programa.\n");
        printf("------------------------------------------------\n");
        printf("Digite a opcao desejada: ");
        scanf("%c", &opcao);
        switch(opcao){
            case '1':
                do{
                    printf("Digite a formula (APERTE [ENTER] PARA FINALIZAR A CAPTURA): ");
                    if(val != 0){
                        getchar();
                    }
                    for(i = 0; i <= MAX && scanf("%c", &temp[i]) && temp[i] != '\n'; i++){
                        temp[i] = toupper(temp[i]);
                    }
                    temp[i] = '\0';
                    val = verificaFormula(temp);
                    if(val == 1){
                        inserirInicio(l, temp);
                        printf("Formula inserida com sucesso!\n");
                    }
                }while(val != 1);
                break;
            case '2':
                if(listaVazia(l) == 0){
                    printf("Insira formulas primeiro\n");
                    break;
                }
                mostrar(l);
                do{
                    printf("\nEm qual formula deseja adicionar a subformula?\n");
                    scanf("%d", &pos);
                }while (pos < 0 || pos >= tamanhoLista(l));
                buscarPosicao(l, pos, temp);
                do{
                    printf("\nDigite o numero da formula deseja concatenar em %s.\n", temp);
                    scanf("%d", &pos2);
                }while (pos2 < 0 || pos2 >= tamanhoLista(l));
                buscarPosicao(l, pos2, subf);
                getchar();
                do{
                    printf("Digite o numero do operador que deve unir as duas formulas.\n");
                    printf("[0] &\n");
                    printf("[1] |\n");
                    scanf("%d", &val);
                }while (val != 0 && val != 1);
                if(val == 0){
                    strcat(temp, " & ");
                }else{
                    strcat(temp, " | ");
                }
                strcat(temp, subf);
                concatenaFormulas(l, pos, temp);
                printf("Formulas concatenadas com sucesso!\n");
                getchar();
                break;
            case '3':
                printf("Formulas cadastradas:\n");
                mostrar(l);
                getchar();
                break;
            case '4':
                if(listaVazia(l) == 0){
                    printf("Insira formulas primeiro\n");
                    getchar();
                    break;
                }
                mostrar(l);
                do{
                    printf("\nQual formula deseja interpretar? ");
                    scanf("%d", &pos);
                }while(pos < 0 || pos >= tamanhoLista(l));
                buscarPosicao(l, pos, temp);
                convertePosfixa(temp);
                interpretaFormula(temp);
                getchar();
                break;
            case '5':
                apagaLista(l);
                printf("O programa encerrou!");
                break;
            default:
                printf("Opcao invalida\n");
                getchar();
                break;
        }
    }while(opcao != '5');
    return 0;
}
