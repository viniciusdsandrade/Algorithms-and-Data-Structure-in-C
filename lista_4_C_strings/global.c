#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#include "global.h"

/**
 * Função para inverter um texto.
 *
 * Esta função recebe uma string como entrada e inverte-a, retornando uma nova
 * string com o texto invertido.
 *
 * @param text A string a ser invertida.
 * @return Um ponteiro para a string resultante, que é a versão invertida do texto
 *         de entrada. O chamador é responsive por liberar a memória alocada
 *         dinamicamente quando não precisar mais dela.
 *         Em caso de erro na alocação de memória, retorna NULL.
 */
char *inversorTexto(char *text)
{
    int length = strlen(text) - 1;
    char *reverse = (char *)malloc(sizeof(char) * (length + 1));

    if (reverse == NULL)
    {
        printf("Erro ao alocar memoria.\n");
        return NULL;
    }

    for (int i = length - 1, j = 0; i >= 0; i--, j++)
    {
        reverse[j] = text[i];
    }
    reverse[length] = '\0';

    return reverse;
}

/**
 * Função para inverter um texto.
 *
 * Esta função recebe uma string como entrada e inverte-a no próprio local
 * (sem alocação de memória adicional), retornando um ponteiro para a
 * string invertida.
 *
 * @param texto A string a ser invertida. A própria string será modificada
 *              para conter o texto invertido após a chamada desta função.
 * @return Um ponteiro para a string invertida (a mesma referência de texto).
 */
char *inversorTexto2(char *texto)
{
    int length = strlen(texto) - 1;

    for (int i = 0, j = length - 1; i < j; i++, j--)
    {
        char temp = texto[i];
        texto[i] = texto[j];
        texto[j] = temp;
    }

    return texto;
}

/**
 * Função para contar o número de palavras em uma string.
 *
 * Esta função recebe uma string como entrada e retorna o número de palavras
 * presentes na string. Uma palavra é definida como uma sequência de caracteres
 * separados por espaços em branco.
 *
 * @param s A string na qual as palavras serão contadas.
 * @return O número de palavras na string.
 */
int contadorDePalavras(const char *s)
{
    int i = 0, n = 0;
    while (s[i] != '\0')
    {
        while (s[i] == ' ')
        {
            i++;
        }

        if (s[i] != '\0')
        {
            n++;
            while (s[i] != ' ' && s[i] != '\0')
            {
                i++;
            }
        }
    }

    return n;
}

/**
 * Função para contar o número de palavras em uma string.
 *
 * Esta função recebe uma string como entrada e retorna o número de palavras
 * presentes na string. Uma palavra é definida como uma sequência de caracteres
 * alfanuméricos, ignorando espaços em branco e caracteres de pontuação.
 *
 * @param s A string na qual as palavras serão contadas.
 * @return O número de palavras na string.
 */
int contadorDePalavras2(char *s)
{
    int i = 0, n = 0;
    int dentroPalavra = 0; // Flag para indicar se estamos dentro de uma palavra

    while (s[i] != '\0')
    {
        while (s[i] == ' ' || ispunct(s[i])) // Ignorant espacos e caracteres de pontuacao
        {
            i++;
        }

        if (s[i] != '\0')
        {
            n++;
            dentroPalavra = 1; // Estamos dentro de uma palavra

            while (s[i] != ' ' && s[i] != '\0')
            {
                if (ispunct(s[i]))
                {
                    dentroPalavra = 0; // Se encontrarmos um caractere de pontuacao, n�o estamos mais dentro de uma palavra
                }
                i++;
            }
        }

        if (!dentroPalavra)
        {
            dentroPalavra = 1; // Se nao estamos mais dentro de uma palavra, resetamos a flag
        }
    }

    return n;
}

/**
 * Função para contar e exibir as ocorrências de uma palavra em um texto.
 *
 * Esta função recebe uma string de texto e uma palavra como entrada, e conta
 * o número de vezes que a palavra ocorre no texto. Ela também exibe as posições
 * em que a palavra é encontrada no texto.
 *
 * @param texto A string de texto na qual as ocorrências da palavra serão contadas.
 * @param palavra A palavra a ser procurada no texto.
 */
void contadorOcorrencia(char *texto, char *palavra)
{
    int tamTexto = strlen(texto) - 1;
    int tamPalavra = strlen(palavra) - 1;
    int freq = 0;

    for (int i = 0; i <= tamTexto - tamPalavra; i++)
    {
        int j = 0;

        while (j < tamPalavra && palavra[j] == texto[i + j])
        {
            j++;
        }

        if (j == tamPalavra)
        {
            freq++;
            printf("Encontrada na posicao %d - %d\n", i, i + tamPalavra - 1);
        }
    }
}

/**
 * Função para verificar se uma string é um palíndromo.
 *
 * Esta função recebe uma string como entrada e verifica se ela é um palíndromo,
 * ou seja, se pode ser lida da mesma forma de trás para frente, ignorando
 * caracteres não alfanuméricos e considerando letras maiúsculas e minúsculas
 * como equivalentes.
 *
 * @param str A string a ser verificada como palíndromo.
 * @return true se a string for um palíndromo, false caso contrário.
 */
bool isPalindrome(char* str) {
    int left = 0;
    int right = strlen(str) - 1;

        // Ignorar caracteres nao alfanumericos
        while (!isalnum(str[left]))
            left++;

        while (!isalnum(str[right]))
            right--;

        char leftChar = tolower(str[left]);
        char rightChar = tolower(str[right]);

        if (leftChar != rightChar)
            return false;

        left++;
        right--;


    return true;
}

/**
 * Função para eliminar espaços em branco de uma string.
 *
 * Esta função recebe uma string como entrada e remove todos os espaços em branco
 * da string, retornando uma nova string sem os espaços. A nova string é alocada
 * dinamicamente e o chamador é responsável por liberar a memória alocada quando
 * não precisar mais dela.
 *
 * @param texto A string da qual os espaços em branco serão removidos.
 * @return Um ponteiro para a nova string sem espaços, ou NULL em caso de erro de
 * alocação de memória.
 */
char *eliminaEspaco(char *texto)
{

    int tam = strlen(texto) - 1;
    int j = 0;
    char *textoSemEspaco = (char *)malloc(sizeof(char) * (tam + 1));

    if (textoSemEspaco == NULL)
    {
        printf("Erro ao alocar memoria.\n");
        return NULL;
    }

    for (int i = 0; i < tam; i++)
    {
        if (texto[i] != ' ')
        {
            textoSemEspaco[j] = texto[i];
            j++;
        }
    }

    textoSemEspaco[j] = '\0';

    return textoSemEspaco;
}

/**
 * Função para verificar se uma string é subsequência de outra.
 *
 * Esta função recebe duas strings como entrada e verifica se a primeira string
 * (w1) é uma subsequência da segunda string (w2). Uma subsequência é uma string
 * que pode ser obtida a partir da outra string removendo zero ou mais caracteres,
 * sem alterar a ordem dos caracteres restantes.
 *
 * @param w1 A primeira string a ser verificada como subsequência.
 * @param w2 A segunda string da qual se verificará a subsequência.
 * @return true se w1 for uma subsequência de w2, false caso contrário.
 */
int isSubsequence(char* w1, char* w2) {
    int len1 = strlen(w1);
    int len2 = strlen(w2);
    int i = 0, j = 0;

    while (i < len1 && j < len2) {
        if (w1[i] == w2[j]) {
            i++;
        }
        j++;
    }

    return (i == len1);
}

/**
 * Função para eliminar espaços em branco extras de uma string.
 *
 * Esta função recebe uma string como entrada e remove espaços em branco extras
 * da string, mantendo apenas um espaço entre palavras. A nova string resultante
 * é alocada dinamicamente e o chamador é responsável por liberar a memória
 * alocada quando não precisar mais dela.
 *
 * @param texto A string da qual os espaços em branco extras serão removidos.
 * @return Um ponteiro para a nova string sem espaços em branco extras, ou NULL
 * em caso de erro de alocação de memória.
 */
char *eliminaEspacoExtra(char *texto)
{

    int tam = strlen(texto) - 1;
    int j = 0;
    char *textoSemEspacoExtra = (char *)malloc(sizeof(char) * (tam + 1));

    if (textoSemEspacoExtra == NULL)
    {
        printf("Erro ao alocar memoria.\n");
        return NULL;
    }

    for (int i = 0; i < tam; i++)
    {
        if (texto[i] != ' ')
        {
            textoSemEspacoExtra[j] = texto[i];
            j++;
        }
        else if (texto[i] == ' ' && texto[i + 1] != ' ')
        {
            textoSemEspacoExtra[j] = texto[i];
            j++;
        }
    }

    textoSemEspacoExtra[j] = '\0';

    return textoSemEspacoExtra;
}

/**
 * Função para ler uma linha de texto da entrada padrão (stdin).
 *
 * Esta função lê uma linha de texto da entrada padrão (stdin) e a armazena em um
 * array de caracteres (string) fornecido como parâmetro.
 *
 * @param texto O array de caracteres (string) onde a linha de texto será armazenada.
 */
void escreveString(char *texto)
{
    fflush(stdin);
    fgets(texto, sizeof(texto), stdin);
    texto[strlen(texto) - 1] = '\0';
}