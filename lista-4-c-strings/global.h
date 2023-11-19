#ifndef LISTA_4_GLOBAL_H
#define LISTA_4_GLOBAL_H
#include "global.c"

char *inversorTexto(char *texto);
char *inversorTexto2(char *texto);
char *eliminaEspaco(char *texto);
char *eliminaEspacoExtra(char *texto);
int contadorDePalavras2(char *s);
void contadorOcorrencia(char *texto, char *palavra);
void escreveString(char *texto);
int isSubsequence(char* w1, char* w2);
bool isPalindrome(char* str);
int contadorDePalavras(const char *s);

#endif // LISTA_4_GLOBAL_H
