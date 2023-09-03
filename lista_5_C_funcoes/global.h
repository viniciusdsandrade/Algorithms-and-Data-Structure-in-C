#ifndef INC_2_LISTAS_GLOBAL_H
#define INC_2_LISTAS_GLOBAL_H

int MAX_DIMENSAO = 1000;

int fun1(int a, int b);
int mdc(int m, int n);
bool amigos(int a, int i);
double media(double pDouble[], int qtd);
void preencheMatrizQuadrada(int matriz[][MAX_DIMENSAO], int dimensao);
void preencheVetorDouble(int qtd, double pDouble[qtd]);
void transposta(double matriz[30][30], double matrizTransposta[30][30], int dimensao);
double *preencheVetorDoubleReturn(int qtd);
void imprimeMatrizQuadrada(double matriz[][MAX_DIMENSAO], int dimensao);
int menor_base_log(int n);
int pitagorico(int n);
int test(int a, int b, int n);


#endif //INC_2_LISTAS_GLOBAL_H
