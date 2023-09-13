#ifndef INC_2_LISTAS_GLOBAL_H
#define INC_2_LISTAS_GLOBAL_H

int fun1(int a, int b);
int mdc(int m, int n);
bool amigos(int a, int b);
double media(double pDouble[], int qtd);
void preencheMatrizQuadrada(int matriz[30][30], int dimensao);
void preencheVetorDouble(int qtd, double pDouble[qtd]);
double *preencheVetorDoubleReturn(int qtd);
void transposta(int **matriz, int **matrizTransposta, int dimensao);
void imprimeMatrizQuadrada(int **matriz, int dimensao);
int menor_base_log(int n);
int pitagorico(int n);
int test(int a, int b, int n);
bool isMagico(int matrix[30][30], int size);
int calculaSoma(int matrix[30][30], int size, int isRow, int index);
bool verificaLinha(int linha, int numero, int tabuleiro[9][9]);
bool verificaColuna(int coluna, int numero, int tabuleiro[9][9]);
bool verificaQuadrante(int linha, int coluna, int numero, int tabuleiro[9][9]);
void multiplica(double mat1[30][30], double mat2[30][30], double matRes[30][30], int n);
void cidadesComEntradaSemSaida(int mat[30][30], int n, int resposta[]);
void cidadesComSaidaSemEntrada(int mat[30][30], int n, int resposta[]);

#endif //INC_2_LISTAS_GLOBAL_H