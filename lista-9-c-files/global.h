#ifndef ALGORITHMS_AND_DATA_STRUCTURE_IN_C_GLOBAL_H
#define ALGORITHMS_AND_DATA_STRUCTURE_IN_C_GLOBAL_H

#include "global.c"

void copiarArquivo(const char *nomeArquivoOrigem, const char *nomeArquivoDestino);
void imprimirConteudoArquivo(const char *nomeArquivo);
int verificarArquivo(const char *nomeArquivo);
void cadastraAluno(char nomeArq[]);
void imprimeAluno(char nomeArq[]);
void alteraNomeAluno(char nomeArq[], int ra, char nome[]);
bool compareFiles(const char *file1, const char *file2);

#endif //ALGORITHMS_AND_DATA_STRUCTURE_IN_C_GLOBAL_H