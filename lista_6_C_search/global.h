#ifndef INC_2_LISTAS_GLOBAL_H
#define INC_2_LISTAS_GLOBAL_H
#include "global.c"

void maxAndMin(const int vet[],
               int tam,
               int *min,
               int *max);
int *uniao(const int vet1[],
           int n1,
           const int vet2[],
           int n2);
int *initVet(int *size, int *maxSize);
void printVet(int *vet, int size, int maxSize);
int *addVet(int *v, int *size, int *maxSize, int e);
int find(const int *v, int size, int e);
int *removeVet(int *v, int *size, int *maxSize, int e);

char *replicarStringComEspacos(const char *vetor, int vezes);
int somaPeso(Cell vet[], int n);

int binarySearch(const int vet[], int tam, int chave);
int linearSearch(const int vet[], int tam, int chave);
void insertionSort(int vet[], int tam);
void bubbleSort(int vet[], int tam);

void troca(int *a, int *b);
int indiceMenor(const int vet[], int tam, int ini);
void selectionSort(int vet[], int tam);
void selectionSortAbstrato(int vet[], int tam);

Produto *lerProdutos(int n);
void ordenaPreco(Produto vet[], int n);
void ordenaQtd(Produto vet[], int n);
void imprimeProduto(Produto vet[], int n);

Aluno leAluno();
Aluno *leAlunos(int n);
Alune *leAlunes(int n);
void imprimeAluno(Aluno aluno);
void listarTurma(Aluno aluno[], int n);
double mediaAlunes(Alune alunes[], int n);

Ponto *lePonto();
void imprimePonto(Ponto p);
Ponto somaPonto(Ponto p1, Ponto p2);
Ponto *somaPonto2(Ponto *p1, Ponto *p2);
Ponto subtraiPonto(Ponto p1, Ponto p2);

Reg leReg(void);
Reg somaVetorSegundoAtributo(Reg reg);
void imprimeReg(Reg reg);

char *concatena(char *s1, char *s2);

Data leData(void);
void swapData(Data *a, Data *b);
void ordenaPorDia(Data vet[], int tam);
void ordenaPorMes(Data vet[], int tam);
void ordenaPorAno(Data vet[], int tam);
void ordena(Data vet[], int tam);
void imprimeDatas(Data datas[], int tam);

Base cria_base();
int insere_base(Pessoa p, Base base);
int remove_base(int rg, Base base);
int buscaBinaria(Pessoa cadastro[], int tamanho, int rg);

Pessoa lePessoa();

#endif //INC_2_LISTAS_GLOBAL_H