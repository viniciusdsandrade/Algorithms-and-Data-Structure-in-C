#include <stdio.h>
#include <string.h>
#include "global.h"

void adicionarAluno(Aluno alunos[], int *numAlunos) {
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
void buscarAlunoPorNome( Aluno alunos[], int numAlunos) {
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
void excluirAluno( Aluno alunos[], const int *numAlunos) {
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
void listarAlunos( Aluno alunos[], int numAlunos) {
    for (int j = 0; j < numAlunos; j++) {
        printf("Nome: %s\n", alunos[j].nome);
        printf("Matricula: %s\n", alunos[j].matricula);
        printf("Curso: %s\n", alunos[j].curso);
        printf("Data de nascimento: %s\n", alunos[j].dataNascimento);
    }
}
void editarAluno(struct Aluno alunos[], int numAlunos) {
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