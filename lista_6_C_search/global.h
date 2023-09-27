#ifndef INC_2_LISTAS_GLOBAL_H
#define INC_2_LISTAS_GLOBAL_H
#include "global.c"

Produto *lerProdutos(int n);
void ordenaPreco(Produto vet[], int n);
void ordenaQuant(Produto vet[], int n);
void imprimeProduto(Produto vet[], int n);

Aluno *leAlunos(int n);
Alune *leAlunes(int n);
void imprimeAluno(Aluno aluno);
void listarTurma(Aluno aluno[], int n);
double mediaAlunes(Alune alunes[], int n);

Ponto lePonto();
void imprimePonto(Ponto p);
Ponto somaPonto(Ponto p1, Ponto p2);
Ponto subtraiPonto(Ponto p1, Ponto p2);

Reg leReg(void);
Reg somaVetorSegundoAtributo(Reg reg);
void imprimeReg(Reg reg);

char *concatena(char *s1, char *s2);

void ordena(struct Data vet[], int tam);
struct Data leData(void);
void imprimeData(struct Data data);

Base cria_base();
int insere_base(Pessoa p, Base base);
int remove_base(int rg, Base base);
int buscaBinaria(Pessoa cadastro[], int tamanho, int rg);

Pessoa lePessoa();
void buscar(const int vet[], int tam, int chave, int posicoes[], int n);


#endif //INC_2_LISTAS_GLOBAL_H