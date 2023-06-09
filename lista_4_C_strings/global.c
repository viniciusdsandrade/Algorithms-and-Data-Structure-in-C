#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

// Funcao que inverte uma string e retorna o resultado
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

// Funcao que inverte uma string e retorna o resultado com 1 variavel para armazenar o resultado
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

// Funcao o que conta a quantidade de palavras em uma string inclusive considerando que o usuario possa ter digitado mais de um espaco entre uma palavra e outra
int contadorDePalavras(char *s)
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

// Aprimoramento da Funcao contadorDePalavras para considerar caracteres de pontuacao e seus possiveis espacos falhos
int contadorDePalavras2(char *s)
{
    int i = 0, n = 0;
    int dentroPalavra = 0; // Flag para indicar se estamos dentro de uma palavra

    while (s[i] != '\0')
    {
        while (s[i] == ' ' || ispunct(s[i])) // Ignorar espacos e caracteres de pontuacao
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

//Funcao que conta a quantidade de ocorrencia de uma determinada palavra em uma determinada string
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


// Funcao que verifica se uma string e palindromo
bool isPalindrome(char* str) {
    int left = 0;
    int right = strlen(str) - 1;

    while (left < right) {
        // Ignorar caracteres nao alfanumericos
        while (!isalnum(str[left]))
            left++;

        while (!isalnum(str[right]))
            right--;

        // Converter caracteres para minusculo
        char leftChar = tolower(str[left]);
        char rightChar = tolower(str[right]);

        if (leftChar != rightChar)
            return false;

        left++;
        right--;
    }

    return true;
}

//Funcao que transtorna uma string com espacos em uma unica string sem espacos
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

//Funcao que verifica se uma string e subsequencia de outra
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

//Elimina espaco extra respeitando o espaco entre as palavras
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

void escreveString(char *texto)
{
    fflush(stdin);
    fgets(texto, sizeof(texto), stdin);
    texto[strlen(texto) - 1] = '\0';
}
