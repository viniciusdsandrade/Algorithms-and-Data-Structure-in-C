#include <stdlib.h>
#include <locale.h>
#include "global.h"
#include "stdio.h"

/*
    Objetivo: Este exerc�cio visa desenvolver um programa em C que gerencia o registro de alunos
    em uma universidade. O programa permitir� a
    entrada, armazenamento, consulta, edi��o e exclus�o de dados dos alunos.

    Requisitos:
    1 - O programa deve criar e utilizar uma estrutura de dados para armazenar informa��es do aluno,
    como
        nome,
        matr�cula,
        curso e
        data de nascimento.
    2 - O programa deve oferecer um menu interativo com as seguintes op��es:

        1. Adicionar novo aluno: Permitir a entrada dos dados do aluno e adicionar o novo registro �
        estrutura de dados,
        2. Buscar aluno por nome: Solicitar o nome do aluno e buscar o registro correspondente na
        estrutura de dados. Se o aluno for encontrado, exibir seus dados completos. Caso contr�rio,
        informar que o aluno n�o foi encontrado.
        3. Excluir aluno: Solicitar o nome ou matr�cula do aluno e excluir o registro correspondente da
        estrutura de dados.
        4. Listar todos os alunos: Exibir os dados de todos os alunos cadastrados na estrutura de
        dados.

        5. Editar dados de um aluno: Solicitar o nome ou matr�cula do aluno e permitir a edi��o de
        seus dados, como nome, curso ou data de nascimento

    Implementa��o:
    Utilize a linguagem de programa��o C para implementar o programa.
    Utilize uma estrutura de dados adequada para armazenar os dados dos alunos, como uma lista ou um vetor.
    Implemente cada funcionalidade do menu de forma modular, utilizando fun��es separadas para cada tarefa
    Utilize fun��es auxiliares para tarefas como entrada de dados, valida��o e formata��o de sa�da.

    Dicas:
    Utilize coment�rios para explicar o c�digo e facilitar a compreens�o.
    Teste o programa com diferentes entradas para garantir seu funcionamento correto.
    Utilize ferramentas de depura��o para identificar e corrigir erros

    Recursos Adicionais:
    Utilize a biblioteca stdlib.h para fun��es de entrada e sa�da de dados.
    Utilize a biblioteca string.h para fun��es de manipula��o de strings
    Consulte a documenta��o da linguagem C para obter mais informa��es sobre as fun��es utilizadas.
 */

int main(void) {

    setlocale(LC_ALL, "Portuguese");
    Aluno alunos[MAX_ALUNOS];
    int numAlunos = 0;
    char opcaoStr[10]; // Assuming the option won't exceed 10 characters
    while (1) {
        printf("1. Adicionar novo aluno\n");
        printf("2. Buscar aluno por nome\n");
        printf("3. Excluir aluno\n");
        printf("4. Listar todos os alunos\n");
        printf("5. Editar dados de um aluno\n");
        printf("6. Sair\n");
        printf("Digite a opcao desejada: ");
        fgets(opcaoStr, sizeof(opcaoStr), stdin);
        int opcao = (int)strtol(opcaoStr, NULL, 10); // Convert the string to an integer using strtol

        // Error handling for strtol
        if (opcao == 0 && opcaoStr[0] != '0') {
            printf("\nOpcao invalida. Por favor, digite um numero de opcao valido.\n\n");
            continue;
        }

        switch (opcao) {
            case 1:
                adicionarAluno(alunos, &numAlunos);
                break;
            case 2:
                buscarAlunoPorNome(alunos, numAlunos);
                break;
            case 3:
                excluirAluno(alunos, &numAlunos);
                break;
            case 4:
                listarAlunos(alunos, numAlunos);
                break;
            case 5:
                editarAluno(alunos, numAlunos);
                break;
            case 6:
                printf("Saindo...\n");
                return 0;
            default:
                printf("Opcao invalida\n");
                break;
        }
    }
}