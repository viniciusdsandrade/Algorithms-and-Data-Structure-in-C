#ifndef C_ALGORITHMS_REGISTER_CHALLENGE_H
#define C_ALGORITHMS_REGISTER_CHALLENGE_H

#define MAX_ALUNOS 100
#define MAX_NOME 100
#define MAX_MATRICULA 10
#define MAX_CURSO 50
#define MAX_DATA_NASCIMENTO 10

typedef struct Aluno {
    char nome[MAX_NOME];
    char matricula[MAX_MATRICULA];
    char curso[MAX_CURSO];
    char dataNascimento[MAX_DATA_NASCIMENTO];
} Aluno;
void adicionarAluno(Aluno alunos[], int *numAlunos);
void buscarAlunoPorNome(Aluno alunos[], int numAlunos);
void excluirAluno(Aluno alunos[], const int *numAlunos);
void listarAlunos(Aluno alunos[], int numAlunos);
void editarAluno(Aluno alunos[], int numAlunos);

#endif //C_ALGORITHMS_REGISTER_CHALLENGE_H