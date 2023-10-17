#include <stdio.h>
#include <string.h>

/**
    - MEMBROS DO GRUPO:
    @ALUNO 1: Vin�cius dos Santos Andrade  RA: 2760482311026
    @ALUNO 2: Gianlucca Fadiga Rissato     RA: 2760482311014
*/
#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCDFAInspection"
#define MAX 129 // Tamanho m�ximo da imagem em pixels

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
 * Fun��o principal do programa que aplica efeitos a imagens PPM.
 *
 * @param argc  N�mero de argumentos na linha de comando.
 * @param argv  Vetor de strings contendo os argumentos da linha de comando.
 *
 * @return 0 se o programa for executado com sucesso, 1 em caso de erro.
 */
int main(int argc, char **argv) {
    // Verifica se o n�mero de argumentos � v�lido
    if (argc != 4) {
        fprintf(stderr, "Argumentos inv�lidos.\n");
        fprintf(stderr, "Uso: %s arquivo_entrada.ppm arquivo_saida.ppm [esticar|cinzaPPM]\n", argv[0]);
        return 1;
    }
    char *arqEntrada = argv[1]; // Nome do arquivo de entrada
    char *arqSaida = argv[2];  // Nome do arquivo de sa�da
    int R[MAX][MAX], G[MAX][MAX], B[MAX][MAX], novaR[MAX][MAX], novaG[MAX][MAX], novaB[MAX][MAX]; // Matrizes de cores
    int cols, rows; // N�mero de colunas e linhas da imagem

    // L� a imagem de entrada e armazena as informa��es nas matrizes R, G e B
    leImagemPPM(arqEntrada, R, G, B, &cols, &rows);

    // Verifica o terceiro argumento para determinar o efeito desejado
    if (strcmp(argv[3], "esticar") == 0) {
        contrastePPM(R, G, B, novaR, novaG, novaB, cols, rows); // Aplica o efeito de esticar contrastePPM
    } else if (strcmp(argv[3], "cinza") == 0) {
        cinzaPPM(R, G, B, novaR, novaG, novaB, cols, rows); // Converte a imagem para escala de cinzaPPM
    } else {
        printf("Efeito desconhecido.\n");
        return 1;
    }

    // Escreve a imagem resultante no arquivo de sa�da
    imprimeImagemPPM(arqSaida, novaR, novaG, novaB, cols, rows);

    return 0;
}

/**
 * L� uma imagem PPM a partir de um arquivo e armazena os valores RGB em matrizes.
 *
 * @param name  Nome do arquivo de entrada (imagem PPM).
 * @param R     Matriz de intensidades de vermelho.
 * @param G     Matriz de intensidades de verde.
 * @param B     Matriz de intensidades de azul.
 * @param cols  Ponteiro para armazenar o n�mero de colunas da imagem.
 * @param rows  Ponteiro para armazenar o n�mero de linhas da imagem.
 */
void leImagemPPM(
        char *name,            // Nome do arquivo da imagem a ser lida
        int R[MAX][MAX],       // Matriz de componentes vermelhos da imagem
        int G[MAX][MAX],       // Matriz de componentes verdes da imagem
        int B[MAX][MAX],       // Matriz de componentes azuis da imagem
        int *cols,             // Ponteiro para armazenar a largura da imagem
        int *rows             // Ponteiro para armazenar a altura da imagem
) {
    int i, j, lixo;            // Vari�veis para controle e descarte tempor�rio de dados
    char p;                    // Vari�vel para armazenar o tipo de imagem (P3)

    FILE *f;                   // Ponteiro de arquivo para abrir e ler a imagem
    f = fopen(name, "r");      // Tenta abrir o arquivo especificado para leitura
    if (f == NULL) {
        printf("Erro ao abrir a imagem \"%s\".\n", name); // Exibe uma mensagem de erro caso a abertura do arquivo falhe
        return;  // Retorna da fun��o, pois a leitura da imagem n�o � poss�vel
    }
    fscanf(f, "%c", &p);      // L� o tipo de imagem (P3) do arquivo
    fscanf(f, "%d", &lixo);   // L� e descarta o valor de lixo
    fscanf(f, "%d %d", cols, rows); // L� a largura e a altura da imagem e armazena nos ponteiros correspondentes
    fscanf(f, "%d", &lixo);   // L� e descarta o valor de lixo

    // Loop para ler os componentes R, G e B de cada pixel da imagem
    for (i = 0; i < (*rows); i++) {
        for (j = 0; j < (*cols); j++) {
            fscanf(f, "%d %d %d", &R[i][j], &G[i][j], &B[i][j]); // L� e armazena os componentes de cada pixel
        }
    }

    fclose(f);  // Fecha o arquivo ap�s concluir a leitura da imagem
}

/**
 * Escreve uma imagem PPM a partir de matrizes de intensidades RGB em um arquivo.
 *
 * @param arqSaida  Nome do arquivo de sa�da (imagem PPM).
 * @param R         Matriz de intensidades de vermelho.
 * @param G         Matriz de intensidades de verde.
 * @param B         Matriz de intensidades de azul.
 * @param cols      N�mero de colunas da imagem.
 * @param rows      N�mero de linhas da imagem.
 */
void imprimeImagemPPM(
        char *arqSaida,         // Nome do arquivo de sa�da
        int R[MAX][MAX],       // Matriz de componentes vermelhos da imagem
        int G[MAX][MAX],       // Matriz de componentes verdes da imagem
        int B[MAX][MAX],       // Matriz de componentes azuis da imagem
        int cols,              // Largura da imagem
        int rows               // Altura da imagem
) {
    int i, j;
    FILE *f;                   // Ponteiro de arquivo para escrever a imagem

    f = fopen(arqSaida, "w");  // Tenta abrir o arquivo de sa�da para escrita
    fprintf(f, "P3\n%d %d\n255\n", cols, rows); // Escreve o cabe�alho da imagem no arquivo

    // Loop para escrever os componentes R, G e B de cada pixel da imagem
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            fprintf(f, "%d %d %d", R[i][j], G[i][j], B[i][j]); // Escreve os componentes de cada pixel no arquivo
            if (j < cols - 1) {
                fprintf(f, " "); // Adiciona um espa�o entre os componentes, exceto no �ltimo componente de cada linha
            }
        }
        fprintf(f, "\n"); // Adiciona uma quebra de linha ap�s cada linha de pixels
    }
    fclose(f); // Fecha o arquivo ap�s concluir a escrita da imagem
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
 * @param cols      N�mero de colunas da imagem.
 * @param rows      N�mero de linhas da imagem.
 */
void contrastePPM(
        int R[MAX][MAX],      // Matriz de componentes vermelhos da imagem original
        int G[MAX][MAX],      // Matriz de componentes verdes da imagem original
        int B[MAX][MAX],      // Matriz de componentes azuis da imagem original
        int novaR[MAX][MAX],  // Matriz de componentes vermelhos da imagem com contrastePPM esticado
        int novaG[MAX][MAX],  // Matriz de componentes verdes da imagem com contrastePPM esticado
        int novaB[MAX][MAX],  // Matriz de componentes azuis da imagem com contrastePPM esticado
        int cols,             // Largura da imagem
        int rows             // Altura da imagem
) {
    int x, y;  // Vari�veis de itera��o

    // Inicializa vari�veis para os valores m�nimos e m�ximos de R, G e B
    int minR = 255, maxR = 0;
    int minG = 255, maxG = 0;
    int minB = 255, maxB = 0;

    // Loop para encontrar os valores m�nimos e m�ximos de R, G e B na imagem
    for (x = 0; x < rows; x++) {
        for (y = 0; y < cols; y++) {
            int r = R[x][y];  // Componente vermelha do pixel atual
            int g = G[x][y];  // Componente verde do pixel atual
            int b = B[x][y];  // Componente azul do pixel atual

            // Atualiza os valores m�nimos e m�ximos para R, G e B
            minR = (r < minR) ? r : minR;
            maxR = (r > maxR) ? r : maxR;
            minG = (g < minG) ? g : minG;
            maxG = (g > maxG) ? g : maxG;
            minB = (b < minB) ? b : minB;
            maxB = (b > maxB) ? b : maxB;
        }
    }

    // Loop para aplicar o efeito de contrastePPM esticado aos componentes R, G e B
    for (x = 0; x < rows; x++) {
        for (y = 0; y < cols; y++) {
            // Aplica a f�rmula para esticar o contrastePPM aos componentes R, G e B
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
 * @param cols      N�mero de colunas da imagem.
 * @param rows      N�mero de linhas da imagem.
 */
void cinzaPPM(
        int R[MAX][MAX],      // Matriz de componentes vermelhos da imagem original
        int G[MAX][MAX],      // Matriz de componentes verdes da imagem original
        int B[MAX][MAX],      // Matriz de componentes azuis da imagem original
        int novaR[MAX][MAX],  // Matriz de componentes vermelhos da imagem em escala de cinzaPPM
        int novaG[MAX][MAX],  // Matriz de componentes verdes da imagem em escala de cinzaPPM
        int novaB[MAX][MAX],  // Matriz de componentes azuis da imagem em escala de cinzaPPM
        int cols,             // Largura da imagem
        int rows             // Altura da imagem
) {
    int x, y;  // Vari�veis de itera��o

    // Loop para percorrer cada pixel da imagem
    for (x = 0; x < rows; x++) {
        for (y = 0; y < cols; y++) {
            // Calcula a m�dia dos componentes R, G e B para obter um valor de escala de cinzaPPM
            int grayscale = (int) (R[x][y] + G[x][y] + B[x][y]) / 3;

            // Atribui o valor de escala de cinzaPPM calculado a cada componente R, G e B
            novaR[x][y] = grayscale;
            novaG[x][y] = grayscale;
            novaB[x][y] = grayscale;
        }
    }
}

#pragma clang diagnostic pop