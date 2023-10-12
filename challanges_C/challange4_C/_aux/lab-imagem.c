#include <stdio.h>
#include <string.h>

#define MAX 129

void readImage(char *name, int R[MAX][MAX], int G[MAX][MAX], int B[MAX][MAX], int *cols, int *rows) {
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
    fclose(f);
}


void writeImage(char *arqSaida, int R[MAX][MAX], int G[MAX][MAX], int B[MAX][MAX], int cols, int rows) {
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

void esticarContraste(
        int R[MAX][MAX],
        int G[MAX][MAX],
        int B[MAX][MAX],
        int novaR[MAX][MAX],
        int novaG[MAX][MAX],
        int novaB[MAX][MAX],
        int cols,
        int rows
) {
    int minR = 255, maxR = 0;
    int minG = 255, maxG = 0;
    int minB = 255, maxB = 0;

    for (int x = 0; x < cols; x++) {
        for (int y = 0; y < rows; y++) {
            int r = R[x][y];
            int g = G[x][y];
            int b = B[x][y];

            minR = (r < minR) ? r : minR;
            maxR = (r > maxR) ? r : maxR;
            minG = (g < minG) ? g : minG;
            maxG = (g > maxG) ? g : maxG;
            minB = (b < minB) ? b : minB;
            maxB = (b > maxB) ? b : maxB;
        }
    }
    for (int x = 0; x < cols; x++) {
        for (int y = 0; y < rows; y++) {
            novaR[x][y] = (int) (((R[x][y] - minR) * 255) / (maxR - minR));
            novaG[x][y] = (int) (((G[x][y] - minG) * 255) / (maxG - minG));
            novaB[x][y] = (int) (((B[x][y] - minB) * 255) / (maxB - minB));
        }
    }
}

void escalaCinza(
        int R[MAX][MAX],
        int G[MAX][MAX],
        int B[MAX][MAX],
        int novaR[MAX][MAX],
        int novaG[MAX][MAX],
        int novaB[MAX][MAX],
        int cols,
        int rows
) {
    for (int x = 0; x < cols; x++) {
        for (int y = 0; y < rows; y++) {
            int grayscale = (R[x][y] + G[x][y] + B[x][y]) / 3;
            novaR[x][y] = grayscale;
            novaG[x][y] = grayscale;
            novaB[x][y] = grayscale;
        }
    }
}

int main(int argc, char **argv) {

    if (argc != 4) {
        fprintf(stderr, "Argumentos inválidos.\n");
        fprintf(stderr, "Uso: %s arquivo_entrada.ppm arquivo_saida.ppm [esticar|cinza]\n", argv[0]);
        return 1;
    }

    char *arqEntrada = argv[1];
    char *arqSaida = argv[2];
    int R[MAX][MAX], G[MAX][MAX], B[MAX][MAX], novaR[MAX][MAX], novaG[MAX][MAX], novaB[MAX][MAX];
    int cols, rows;

    readImage(arqEntrada, R, G, B, &cols, &rows);

    if (strcmp(argv[3], "cinza") == 0) {
        escalaCinza(R, G, B, novaR, novaG, novaB, cols, rows);
    } else if (strcmp(argv[3], "esticar") == 0) {
        esticarContraste(R, G, B, novaR, novaG, novaB, cols, rows);
    } else {
        fprintf(stderr, "Efeito não reconhecido. Use 'cinza' ou 'esticar'.\n");
        return 1;
    }

    writeImage(arqSaida, novaR, novaG, novaB, cols, rows);
    return 0;
}