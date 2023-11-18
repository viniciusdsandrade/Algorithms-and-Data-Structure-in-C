#include <stdio.h>

#define MIN_FUNCIONARIOS 3
#define MAX_FUNCIONARIOS 30

/*
 * Autor: Vinícius dos Santos Andrade
 * RA:    2760482311026
 * Data:  18/11/2023
 */

/*
Objetivo
    O objetivo desta tarefa é fazer um programa que use recursividade e que,
    dada a matriz que descreve a hierarquia de uma empresa, encontre a cadeia
    hierárquica relativa a um determinado funcionário.

Entrada
    A primeira linha contém dois inteiros: n, o número de funcionários entre 3 e 30, e k,
    o identificador numérico do funcionário sobre o qual deseja-se conhecer a cadeira hierárquica.
    A seguir tem-se n linhas que correspondem as linhas da matriz que descrevem a hierarquia da empresa,
    conforme explicado no enunciado.

 Saída
    Na saída devem ser impressos os números que identificam todos os funcionários que estejam
    na cadeia hierárquica do funcionário k, começando pelo próprio, e então imprimindo,
    em ordem crescente por identificador, os outros funcionários. Os números dos funcionários
    da cadeia devem estar separados por um único espaço em branco.
*/

void lerArquivoTxt(
        const char *nomeArquivo,
        int *numFuncionarios,
        int *idFuncionario,
        int matriz[][MAX_FUNCIONARIOS]
);

int validarEntradaUsuario(
        int *numFuncionarios,
        int *idFuncionario
);

void lerMatrizFuncionario(
        int numFuncionarios,
        int matriz[][MAX_FUNCIONARIOS]
);

void encontrarCadeiaHierarquica(
        int funcionarioAtual,
        int numFuncionarios,
        int matriz[][MAX_FUNCIONARIOS],
        int visitados[],
        int cadeia[]
);

void imprimirCadeiaHierarquica(
        int numFuncionarios,
        int funcionarioAtual,
        int cadeia[]
);

int main(void) {

/*
    const char *teste_0 = "C:\\Users\\Pichau\\Desktop\\CStudy\\c-algorithms\\challanges-c\\2_challange5_C\\teste-0.txt";
    const char *teste_5 = "C:\\Users\\Pichau\\Desktop\\CStudy\\c-algorithms\\challanges-c\\2_challange5_C\\teste-5.txt";
    const char *teste_10 = "C:\\Users\\Pichau\\Desktop\\CStudy\\c-algorithms\\challanges-c\\2_challange5_C\\teste-10.txt";
    const char *teste_11 = "C:\\Users\\Pichau\\Desktop\\CStudy\\c-algorithms\\challanges-c\\2_challange5_C\\teste-11.txt";

    const char *teste_0_1 = "C:\\Users\\vinic\\OneDrive\\Área de Trabalho\\CStudy\\c-algorithms\\challanges-c\\2_challange5_C\\teste-0.txt";
    const char *teste_5_1 = "C:\\Users\\vinic\\OneDrive\\Área de Trabalho\\CStudy\\c-algorithms\\challanges-c\\2_challange5_C\\teste-5.txt";
    const char *teste_10_1 = "C:\\Users\\vinic\\OneDrive\\Área de Trabalho\\CStudy\\c-algorithms\\challanges-c\\2_challange5_C\\teste-10.txt";
    const char *teste_11_1 = "C:\\Users\\vinic\\OneDrive\\Área de Trabalho\\CStudy\\c-algorithms\\challanges-c\\2_challange5_C\\teste-11.txt";
*/

    int numFuncionarios, idFuncionario;
    int matriz[MAX_FUNCIONARIOS][MAX_FUNCIONARIOS];

/*
    // Chama a função para ler o arquivo
    lerArquivoTxt(teste_11_1, &numFuncionarios, &idFuncionario, matriz);
*/


    // Chama a função para validar a entrada do usuário
    if (!validarEntradaUsuario(&numFuncionarios, &idFuncionario))
        return 0; // Se a entrada for inválida, encerra o programa

    // Chama a função para ler a matriz do funcionário
    lerMatrizFuncionario(numFuncionarios, matriz);

    // Arrays para rastrear os funcionários visitados e armazenar a cadeiraHierarquica hierárquica
    int visitados[MAX_FUNCIONARIOS] = {0};
    int cadeiraHierarquica[MAX_FUNCIONARIOS] = {0};

    // Chama a função para encontrar a cadeiraHierarquica hierárquica
    encontrarCadeiaHierarquica(idFuncionario, numFuncionarios, matriz, visitados, cadeiraHierarquica);

    // Chama a função para imprimir a cadeiraHierarquica hierárquica em ordem crescente
    imprimirCadeiaHierarquica(numFuncionarios, idFuncionario, cadeiraHierarquica);

    return 0;
}

void encontrarCadeiaHierarquica(
        int funcionarioAtual,
        int numFuncionarios,
        int matriz[][MAX_FUNCIONARIOS],
        int visitados[],
        int cadeia[]
) {
    // Marca o funcionário como visitado
    visitados[funcionarioAtual] = 1;

    // Adiciona o funcionário à cadeia
    for (int i = 0; i < numFuncionarios; i++) {
        if (matriz[funcionarioAtual][i] == 1 && !visitados[i]) {
            encontrarCadeiaHierarquica(i, numFuncionarios, matriz, visitados, cadeia);
        }
    }

    // Adiciona o funcionário atual à cadeia
    cadeia[funcionarioAtual] = 1;
}

void imprimirCadeiaHierarquica(
        int numFuncionarios,
        int funcionarioAtual,
        int cadeia[]
) {
    // Imprimir o funcionário atual
    printf("%d ", funcionarioAtual);

    // Imprimir os demais em ordem crescente
    for (int i = 0; i < numFuncionarios; i++) {
        if (cadeia[i] == 1 && i != funcionarioAtual) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

void lerMatrizFuncionario(
        int numFuncionarios,
        int matriz[][MAX_FUNCIONARIOS]
) {
    for (int i = 0; i < numFuncionarios; i++) {
        for (int j = 0; j < numFuncionarios; j++) {
            printf("matriz[%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
}

// Função para validar a entrada do usuário
int validarEntradaUsuario(
        int *numFuncionarios,
        int *idFuncionario
) {
    printf("Digite o numero de funcionarios entre 3 e 30 (dimensao da matriz funcionarios) e o id do funcionario: \n");
    printf("Dimensao matriz funcionario: ");
    scanf("%d", numFuncionarios);
    printf("Id do funcionario: ");
    scanf("%d", idFuncionario);

    if (*numFuncionarios < MIN_FUNCIONARIOS || *numFuncionarios > MAX_FUNCIONARIOS) {
        printf("Numero de funcionarios invalido.\n");
        printf("O numero de funcionarios deve estar entre %d e %d.\n", MIN_FUNCIONARIOS, MAX_FUNCIONARIOS);
        printf("Numero digitado foi: %d\n", *numFuncionarios);
        return 0; // Retornar 0 indica que a entrada é inválida
    }

    return 1; // Retornar 1 indica que a entrada é válida
}

void lerArquivoTxt(
        const char *nomeArquivo,
        int *numFuncionarios,
        int *idFuncionario,
        int matriz[][MAX_FUNCIONARIOS]
) {
    FILE *arquivo;
    int i, j;

    // Abre o arquivo para leitura
    arquivo = fopen(nomeArquivo, "r");

    // Verifica se o arquivo foi aberto corretamente
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    // Lê os dois inteiros da primeira linha
    fscanf(arquivo, "%d %d", numFuncionarios, idFuncionario);

    // Lê a matriz a partir da segunda linha
    for (i = 0; i < *numFuncionarios; i++) {
        for (j = 0; j < *numFuncionarios; j++) {
            fscanf(arquivo, "%d", &matriz[i][j]);
        }
    }

    // Fecha o arquivo
    fclose(arquivo);
}