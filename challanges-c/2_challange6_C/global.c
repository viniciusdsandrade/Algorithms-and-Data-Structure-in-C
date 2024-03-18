#include <stdio.h>
#include <string.h>
#include "global.h"
#include <locale.h>

void adicionarAluno(Aluno alunos[], int *numAlunos) {
    setlocale(LC_ALL, "Portuguese");
    if (*numAlunos < MAX_ALUNOS) {
        printf("Digite o nome do aluno: ");
        scanf("%s", alunos[*numAlunos].nome);
        printf("Digite a matricula do aluno: ");
        scanf("%s", alunos[*numAlunos].matricula);
        printf("Digite o curso do aluno: ");
        scanf("%s", alunos[*numAlunos].curso);
        printf("Digite a data de nascimento do aluno: ");
        scanf("%s", alunos[*numAlunos].dataNascimento);
        (*numAlunos)++;
    } else {
        printf("Limite de alunos atingido\n");
    }
}
void buscarAlunoPorNome(Aluno alunos[], int numAlunos) {
    setlocale(LC_ALL, "Portuguese");
    char nome[MAX_NOME];
    printf("Digite o nome do aluno: ");
    scanf("%s", nome);
    for (int j = 0; j < numAlunos; j++) {
        if (strcmp(alunos[j].nome, nome) == 0) {
            printf("Nome: %s\n", alunos[j].nome);
            printf("Matricula: %s\n", alunos[j].matricula);
            printf("Curso: %s\n", alunos[j].curso);
            printf("Data de nascimento: %s\n", alunos[j].dataNascimento);
        }
    }
}
void excluirAluno(Aluno alunos[], const int *numAlunos) {
    setlocale(LC_ALL, "Portuguese");
    char nome[MAX_NOME];
    printf("Digite o nome do aluno: ");
    scanf("%s", nome);
    for (int j = 0; j < *numAlunos; j++) {
        if (strcmp(alunos[j].nome, nome) == 0) {
            strcpy(alunos[j].nome, "");
            strcpy(alunos[j].matricula, "");
            strcpy(alunos[j].curso, "");
            strcpy(alunos[j].dataNascimento, "");
        }
    }
}
void listarAlunos(Aluno alunos[], int numAlunos) {
    setlocale(LC_ALL, "Portuguese");
    if (numAlunos == 0) {
        printf("\n-------------------------\n");
        printf("Nao ha alunos cadastrados.\n");
        printf("-------------------------\n\n");
        return;
    }

    printf("Lista de Alunos:\n");
    printf("---------------------------------------------------------------------------------------\n");
    printf("| %-20s | %-10s | %-20s | %-15s |\n", "Nome", "Matricula", "Curso", "Data de Nascimento");
    printf("---------------------------------------------------------------------------------------\n");

    for (int j = 0; j < numAlunos; j++) {
        printf("| %-20s | %-10s | %-20s | %-15s |\n", alunos[j].nome, alunos[j].matricula, alunos[j].curso, alunos[j].dataNascimento);
    }
    printf("---------------------------------------------------------------------------------------\n");
}
void editarAluno(Aluno alunos[], int numAlunos) {
    setlocale(LC_ALL, "Portuguese");
    char nome[MAX_NOME];
    printf("Digite o nome do aluno: ");
    scanf("%s", nome);
    for (int j = 0; j < numAlunos; j++) {
        if (strcmp(alunos[j].nome, nome) == 0) {
            printf("Digite o nome do aluno: ");
            scanf("%s", alunos[j].nome);
            printf("Digite a matricula do aluno: ");
            scanf("%s", alunos[j].matricula);
            printf("Digite o curso do aluno: ");
            scanf("%s", alunos[j].curso);
            printf("Digite a data de nascimento do aluno: ");
            scanf("%s", alunos[j].dataNascimento);
        }
    }
}