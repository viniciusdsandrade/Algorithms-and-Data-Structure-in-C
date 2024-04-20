#include <stdio.h>
#include <string.h>

/**
    - MEMBROS DO GRUPO:
    @ALUNO 1: Vinícius dos Santos Andrade  RA: 2760482311026
    @ALUNO 2: Gianlucca Fadiga Rissato     RA: 2760482311014
*/
#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCDFAInspection"
#define MAX 129
void leImagemPPM(
        char *name,
        int R[MAX][MAX],
        int G[MAX][MAX],
        int B[MAX][MAX],
        int *cols,
        int *rows
);

void imprimeImagemPPM(
        char *arqSaida,
        int R[MAX][MAX],
        int G[MAX][MAX],
        int B[MAX][MAX],
        int cols,
        int rows
);

void contrastePPM(
        int R[MAX][MAX],
        int G[MAX][MAX],
        int B[MAX][MAX],
        int novaR[MAX][MAX],
        int novaG[MAX][MAX],
        int novaB[MAX][MAX],
        int cols,
        int rows
);

void cinzaPPM(
        int R[MAX][MAX],
        int G[MAX][MAX],
        int B[MAX][MAX],
        int novaR[MAX][MAX],
        int novaG[MAX][MAX],
        int novaB[MAX][MAX],
        int cols,
        int rows
);

/**
 * Função principal do programa que aplica efeitos a imagens PPM.
 *
 * @param argc  Número de argumentos na linha de comando.
 * @param argv  Vetor de strings contendo os argumentos da linha de comando.
 *
 * @return 0 se o programa for executado com sucesso, 1 em caso de erro.
 */
int main(int argc, char **argv) {
    // Verifica se o número de argumentos é válido
    if (argc != 4) {
        fprintf(stderr, "Argumentos inválidos.\n");
        fprintf(stderr, "Uso: %s arquivo_entrada.ppm arquivo_saida.ppm [esticar|cinzaPPM]\n", argv[0]);
        return 1;
    }
    char *arqEntrada = argv[1]; // Nome do arquivo de entrada
    char *arqSaida = argv[2];  // Nome do arquivo de saída
    int R[MAX][MAX], G[MAX][MAX], B[MAX][MAX], novaR[MAX][MAX], novaG[MAX][MAX], novaB[MAX][MAX]; // Matrizes de cores
    int cols, rows; // Número de colunas e linhas da imagem

    leImagemPPM(arqEntrada, R, G, B, &cols, &rows);

    if (strcmp(argv[3], "esticar") == 0) {
        contrastePPM(R, G, B, novaR, novaG, novaB, cols, rows); // Aplica o efeito de esticar contrastePPM
    } else if (strcmp(argv[3], "cinza") == 0) {
        cinzaPPM(R, G, B, novaR, novaG, novaB, cols, rows); // Converte a imagem para escala de cinzaPPM
    } else {
        printf("Efeito desconhecido.\n");
        return 1;
    }

    // Escreve a imagem resultante no arquivo de saída
    imprimeImagemPPM(arqSaida, novaR, novaG, novaB, cols, rows);

    return 0;
}

/**
 * Lê uma imagem PPM a partir de um arquivo e armazena os valores RGB em matrizes.
 *
 * @param name  Nome do arquivo de entrada (imagem PPM).
 * @param R     Matriz de intensidades de vermelho.
 * @param G     Matriz de intensidades de verde.
 * @param B     Matriz de intensidades de azul.
 * @param cols  Ponteiro para armazenar o número de colunas da imagem.
 * @param rows  Ponteiro para armazenar o número de linhas da imagem.
 */
void leImagemPPM(
        char *name,
        int R[MAX][MAX],
        int G[MAX][MAX],
        int B[MAX][MAX],
        int *cols,
        int *rows
) {
    int i, j, lixo;
    char p;

    FILE *f;
    f = fopen(name, "r");
    if (f == NULL) {
        printf("Erro ao abrir a imagem \"%s\".\n", name);
        return;
    }
    fscanf(f, "%c", &p);
    fscanf(f, "%d", &lixo);
    fscanf(f, "%d %d", cols, rows);
    fscanf(f, "%d", &lixo);

    for (i = 0; i < (*rows); i++) {
        for (j = 0; j < (*cols); j++) {
            fscanf(f, "%d %d %d", &R[i][j], &G[i][j], &B[i][j]);
        }
    }

    fclose(f);  // Fecha o arquivo após concluir a leitura da imagem
}

/**
 * Escreve uma imagem PPM a partir de matrizes de intensidades RGB em um arquivo.
 *
 * @param arqSaida  Nome do arquivo de saída (imagem PPM).
 * @param R         Matriz de intensidades de vermelho.
 * @param G         Matriz de intensidades de verde.
 * @param B         Matriz de intensidades de azul.
 * @param cols      Número de colunas da imagem.
 * @param rows      Número de linhas da imagem.
 */
void imprimeImagemPPM(
        char *arqSaida,
        int R[MAX][MAX],
        int G[MAX][MAX],
        int B[MAX][MAX],
        int cols,
        int rows
) {
    int i, j;
    FILE *f;

    f = fopen(arqSaida, "w");
    fprintf(f, "P3\n%d %d\n255\n", cols, rows);

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            fprintf(f, "%d %d %d", R[i][j], G[i][j], B[i][j]);
            if (j < cols - 1) {
                fprintf(f, " ");
            }
        }
        fprintf(f, "\n");
    }
    fclose(f);
}

/**
 * Aplica o efeito de esticar contrastePPM em uma imagem.
 *
 * @param R         Matriz de intensidades de vermelho.
 * @param G         Matriz de intensidades de verde.
 * @param B         Matriz de intensidades de azul.
 * @param novaR     Matriz de intensidades de vermelho resultante.
 * @param novaG     Matriz de intensidades de verde resultante.
 * @param novaB     Matriz de intensidades de azul resultante.
 * @param cols      Número de colunas da imagem.
 * @param rows      Número de linhas da imagem.
 */
void contrastePPM(
        int R[MAX][MAX],
        int G[MAX][MAX],
        int B[MAX][MAX],
        int novaR[MAX][MAX],
        int novaG[MAX][MAX],
        int novaB[MAX][MAX],
        int cols,
        int rows
) {
    int x, y;  // Variáveis de iteração

    int minR = 255, maxR = 0;
    int minG = 255, maxG = 0;
    int minB = 255, maxB = 0;

    for (x = 0; x < rows; x++) {
        for (y = 0; y < cols; y++) {
            int r = R[x][y];
            int g = G[x][y];
            int b = B[x][y];

            // Atualiza os valores mínimos e máximos para R, G e B
            minR = (r < minR) ? r : minR;
            maxR = (r > maxR) ? r : maxR;
            minG = (g < minG) ? g : minG;
            maxG = (g > maxG) ? g : maxG;
            minB = (b < minB) ? b : minB;
            maxB = (b > maxB) ? b : maxB;
        }
    }

    for (x = 0; x < rows; x++) {
        for (y = 0; y < cols; y++) {
            // Aplica a fórmula para esticar o contrastePPM aos componentes R, G e B
            novaR[x][y] = (int) (((R[x][y] - minR) * 255) / (maxR - minR));
            novaG[x][y] = (int) (((G[x][y] - minG) * 255) / (maxG - minG));
            novaB[x][y] = (int) (((B[x][y] - minB) * 255) / (maxB - minB));
        }
    }
}

/**
 * Converte uma imagem colorida em escala de cinzaPPM.
 *
 * @param R         Matriz de intensidades de vermelho.
 * @param G         Matriz de intensidades de verde.
 * @param B         Matriz de intensidades de azul.
 * @param novaR     Matriz de intensidades de vermelho resultante (escala de cinzaPPM).
 * @param novaG     Matriz de intensidades de verde resultante (escala de cinzaPPM).
 * @param novaB     Matriz de intensidades de azul resultante (escala de cinzaPPM).
 * @param cols      Número de colunas da imagem.
 * @param rows      Número de linhas da imagem.
 */
void cinzaPPM(
        int R[MAX][MAX],
        int G[MAX][MAX],
        int B[MAX][MAX],
        int novaR[MAX][MAX],
        int novaG[MAX][MAX],
        int novaB[MAX][MAX],
        int cols,
        int rows
) {
    int x, y;

    for (x = 0; x < rows; x++) {
        for (y = 0; y < cols; y++) {
            int grayscale = (int) (R[x][y] + G[x][y] + B[x][y]) / 3;

            // Atribui o valor de escala de cinzaPPM calculado a cada componente R, G e B
            novaR[x][y] = grayscale;
            novaG[x][y] = grayscale;
            novaB[x][y] = grayscale;
        }
    }
}

#pragma clang diagnostic pop