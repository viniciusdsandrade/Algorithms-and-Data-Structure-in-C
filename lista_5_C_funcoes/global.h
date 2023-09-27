#ifndef INC_2_LISTAS_GLOBAL_H
#define INC_2_LISTAS_GLOBAL_H

#define MAX_DIMENSION 30

int pot(int a, int b);
int mdc(int m, int n);
bool amigos(int a, int b);
double media(const double pDouble[], int qtd);
void preencheVetorDouble(int qtd, double pDouble[qtd]);
void readMatrix(int matrix[MAX_DIMENSION][MAX_DIMENSION], int dimension);
void printMatrix(int matrix[MAX_DIMENSION][MAX_DIMENSION], int dimension);
void transpose(int inputMatrix[MAX_DIMENSION][MAX_DIMENSION], int resultMatrix[MAX_DIMENSION][MAX_DIMENSION], int dimension);
void multiplySquareMatrix(int matrixA[MAX_DIMENSION][MAX_DIMENSION], int matrixB[MAX_DIMENSION][MAX_DIMENSION], int resultMatrix[MAX_DIMENSION][MAX_DIMENSION],int dimension);
int menor_base_log(int n);
bool pitagorico(int n);
int isSumSquare(int a, int b, int n);
bool isMagico(int matrix[30][30], int size);
int calculaSoma(int matrix[30][30], int size, int isRow, int index);
bool verificaLinha(int linha, int numero, int tabuleiro[9][9]);
bool verificaColuna(int coluna, int numero, int tabuleiro[9][9]);
bool verificaQuadrante(int linha, int coluna, int numero, int tabuleiro[9][9]);
void cidadesComEntradaSemSaida(int mat[30][30], int n, int resposta[]);
void cidadesComSaidaSemEntrada(int mat[30][30], int n, int resposta[]);

#endif //INC_2_LISTAS_GLOBAL_H