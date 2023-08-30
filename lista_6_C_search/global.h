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
void listarTurma(Aluno turma[], int n);
double mediaAlunes(Alune turma[], int n);

Ponto lePonto();
void imprimePonto(Ponto p);
Ponto somaPonto(Ponto p1, Ponto p2);
Ponto subtraiPonto(Ponto p1, Ponto p2);

#endif //INC_2_LISTAS_GLOBAL_H
