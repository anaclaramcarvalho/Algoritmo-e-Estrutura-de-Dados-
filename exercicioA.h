#ifndef EXERCICIOA_H_INCLUDED
#define EXERCICIOA_H_INCLUDED
#define TAM_MAX 100

typedef struct string string;
string* criar();
string* criar_t (int tam);
void associa (string* s, char* var);
int tamanho (string* s);
void imprime (string* s);
int ocorrencias (string* s, char c);


#endif // EXERCICIOA_H_INCLUDED
