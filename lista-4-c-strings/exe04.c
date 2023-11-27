#include <stdio.h>
#include <locale.h>
#include <string.h>
#include "global.h"

#define MAX_EXERCISES 26

bool getExitChoice(void);
void executeExercise(int choice);
int displayMenuAndGetChoice(void);

int main(void) {
    setlocale(LC_ALL, "Portuguese");

    bool exitProgram = false;

    do {
        int choice = displayMenuAndGetChoice();

        if (choice >= 1 && choice <= MAX_EXERCISES)
            executeExercise(choice);
        else
            printf("Invalid option!\n");

        exitProgram = getExitChoice();
    } while (!exitProgram);
    printf("Thank you for using the program!\n");
    return 0;
}

int exercise01(void) {
    /**
        1 - Faca um programa que leia do teclado uma string (possivelmente com espacos) de ate 80
        <p>caracteres e que entao salve a inversa desta string em uma nova string.
        <p>
       <p> Refaca o programa de tal forma que nao seja utilizado nenhum vetor adicional!
        <p>Ou seja, devemos computar a inversa no proprio vetor original da string lida.
    */

    printf("\nExercicio01 - Lista04\n");

    char str[80];

    printf("Digite uma string: ");
    fflush(stdin);
    fgets(str, sizeof(str), stdin);

    int tamStr = strlen(str) - 1; // Desconsidera o caractere de nova linha '\n'
    int j, i;

    printf("String original:  %s", str);

    for (i = 0, j = tamStr - 1; i < j; i++, j--) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }

    printf("String invertida: %s\n", str);

    return 0;
}

int exercise02(void) {
    /**
        2. Faca um programa que leia do teclado uma string (possivelmente com espacos) de ate 80
        <p>caracteres e que entao salve a string lida em uma nova removendo-se os espacos.
        <p>Exemplo de entrada:
<p>
        <p>Out of the night that covers me
<p>
        <p>e vetor resultante:
<p>
        <p>Outofthenightthatcoversme
<p>
        <p>Refaca o programa de tal forma que nao seja utilizado nenhum vetor adicional! Ou seja
        <p>devemos deixar a string sem espacos no proprio vetor original da string lida sem o uso de
        <p>nenhum outro vetor auxiliar.
    */

    printf("\nExercicio02 - Lista04\n");

    char str[80], strSemEspaco[80];

    printf("Digite uma string: ");
    fflush(stdin);
    fgets(str, sizeof(str), stdin);

    int i, j = 0;
    for (i = 0; i < strlen(str); i++) {
        if (str[i] != ' ') {
            strSemEspaco[j] = str[i];
            j++;
        }
    }

    strSemEspaco[j] = '\0';
    printf("String sem espaco: %s", strSemEspaco);
    return 0;
}

int exercise03(void) {
    /**
        3. Faca um programa que leia do teclado uma string (possivelmente com espacos) de ate 80
        <p>caracteres e que entao salve a string lida em uma nova removendo-se os espacos extras
        <p>entre as palavras.
<p>
        <p>Exemplo de entrada:
        <p>Out of    the    night    that   covers me
<p>
        <p>e vetor resultante:
        <p>ut of the night that covers me
<p>
        <p>Refaca o programa de tal forma que nao seja utilizado nenhum vetor adicional! Ou seja
        <p>devemos deixar a string sem espacos extras no proprio vetor original da string lida sem o
        <p>uso de nenhum outro vetor auxiliar.
    */

    printf("\nExercicio03 - Lista04\n");

    char str[80], strSemEspacoExtra[80];

    printf("Digite uma string: ");
    escreveString(str);

    int i, j = 0;
    for (i = 0; i < strlen(str); i++) {
        if (str[i] != ' ') {
            strSemEspacoExtra[j] = str[i];
            j++;
        } else if (str[i] == ' ' && str[i + 1] != ' ') {
            strSemEspacoExtra[j] = str[i];
            j++;
        }
    }

    strSemEspacoExtra[j] = '\0';

    printf("String sem espaco: %s\n", strSemEspacoExtra);

    return 0;
}

int exercise04(void) {
    /**
        4. Escreva um programa que leia duas palavras do teclado e determina se a segunda e um
        <p>anagrama da primeira. Uma palavra e um anagrama de outra se todas as letras de uma
        <p>ocorrem na outra, em mesmo numero, independente da posicao. Exemplos: ROMA, MORA,
        <p>ORAM, AMOR, RAMO sao anagramas entre si.
    */

    printf("\nExercicio04 - Lista04\n");
    char str1[80], str2[80], aux[80];

    printf("Digite uma string: ");
    fflush(stdin);
    fgets(str1, sizeof(str1), stdin);

    printf("Digite outra string: ");
    fflush(stdin);
    fgets(str2, sizeof(str1), stdin);

    strcpy(aux, str2); // Copia str2 para aux

    int i, j;

    int tamStr1 = strlen(str1) - 1;
    int tamStr2 = strlen(str2) - 1;

    if (tamStr1 != tamStr2) {
        printf("Nao e anagrama!\n");
        return 0;
    }

    for (i = 0; i < tamStr1; i++) {
        for (j = 0; j < tamStr2; j++) {
            // Verifica se os caracteres são iguais sem distinção de maiúsculas e minúsculas
            if (str1[i] == str2[j] || str1[i] == str2[j] + 32 || str1[i] == str2[j] - 32) {
                str2[j] = ' ';
                break;
            }
        }
    }

    for (i = 0; i < tamStr2; i++) {
        if (str2[i] != ' ') {
            printf("Nao e anagrama!\n");
            return 0;
        }
    }

    str1[tamStr1] = '\0'; // Coloca o caractere de fim de string
    aux[tamStr2] = '\0';

    printf("%s e anagrama de %s!\n", str1, aux);

    return 0;
}

int exercise05(void) {

    /**
        5. Faça um programa que leia duas strings e elimine, da segunda string, todas as ocorrências
        dos caracteres da primeira string.
    */

    printf("\nExercicio05 - Lista04\n");

    char str1[80], str2[80];

    printf("Digite uma string: ");
    fflush(stdin);
    fgets(str1, sizeof(str1), stdin);

    printf("Digite outra string: ");
    fflush(stdin);
    fgets(str2, sizeof(str2), stdin);

    char copia[80];
    strcpy(copia, str2); // Copia str2 para copia

    int tamStr1 = strlen(str1) - 1; // Desconsidera o caractere de nova linha '\n'
    int tamStr2 = strlen(str2) - 1;

    // Verifica se as strings tem os mesmos caracteres
    for (int i = 0; i < tamStr2; i++) {
        for (int j = 0; j < tamStr1; j++) {
            if (str1[i] == str2[j])
                str2[j] = ' ';
        }
    }

    printf("String 1: %s", str1);
    printf("String 2: %s", copia);
    printf("String 3: %s", str2);

    return 0;
}

int exercise06(void) {
    /**
        6. Faça um programa que leia um texto T (com espacos) e uma palavra p do teclado. Em
        seguida o programa devera imprimir todas as posicoes onde ocorrem a palavra p em T.
        <p>Se por exemplo T = "duas bananas e 4 abacates. Nao havera mais bananas.", e p ="bananas",
        então o programa deveria imprimir 5 e 43.
    */

    printf("\nExercicio06 - Lista04\n");

    char t[80], p[80];

    printf("Digite um texto de ate 80 caracteres: ");
    fflush(stdin);
    fgets(t, sizeof(t), stdin);

    printf("Digite uma palavra: ");
    fflush(stdin);
    fgets(p, sizeof(p), stdin);

    int tamT = strlen(t) - 1; // Desconsidera o caractere de nova linha '\n'
    int tamP = strlen(p) - 1;

    t[tamT] = '\0'; // Coloca o caractere de fim de string
    p[tamP] = '\0';

    int i, j, cont = 0;

    for (i = 0; i <= tamT - tamP; i++) // Percorre o texto ate o tamanho do texto menos o tamanho da palavra
    {
        j = 0;
        while (j < tamP && p[j] == t[i + j]) // Percorre a palavra e verifica se os caracteres são iguais
            j++;

        if (j == tamP) // Se j == tamP, significa que a palavra foi encontrada
        {
            printf("Encontrada na posição [%d - %d]\n", i, i + tamP - 1); // Imprime a posição da palavra
            cont++;
        }
    }

    if (cont == 0)
        printf("Palavra não encontrada!\n");
    else
        printf("Palavra encontrada %d vezes!\n", cont);

    return 0;
}

int exercise07(void) {
    /**
    7. Escreva um programa que lê uma string de atÉ 50 caracteres, e imprime "Palindrome"caso
    <p>a string seja um palindromo e "Nao Palindromo" caso contr?rio.

    <p>OBS: Um palindromo é uma palavra ou frase, que é igual quando lida da esquerda para a
    direita ou da direita para a esquerda (assuma que s? s?o usados caracteres min?sculos
    e sem acentos. Espa?os em brancos devem ser desperadoes).

    <p>Exemplo de palindromo: saudavel leva duas.

    <p>DESAFIO: Adapte o código do palindromo para que ele reconheça se uma frase com Letras maiusculas e minusculas e inclusive com pontuação é um palindro
    inclusive com espaços extras e outras anomalias da lingua portuguesa
    */

    printf("\nExercicio07 - Lista04\n");

    char str[50];

    printf("Digite uma string de ate 50 caracteres: ");
    fflush(stdin);
    fgets(str, sizeof(str), stdin);

    if (strlen(str) > 50 || strlen(str) < 0) {
        printf("Erro ao alocar memória!\n");
        return 0;
    }

    int tam = strlen(str) - 1;

    str[tam] = '\0';

    if (isPalindrome(str) == 0)
        printf("\n'%s' NÃO é palindrome!\n", str);
    else
        printf("\n'%s' É palindrome!\n", str);

    return 0;
}

int exercise08(void) {
    /**
        8. Faca um programa que leia duas palavras e verifique se uma delas pode ser obtida por
       <p> meio da remove o de letras da outra. A ordem das letras nao pode ser alterada.

       <p> Por exemplo:

        <p>moda e uma subsequencia em moradia
        cereja e uma subsequencia em cerveja
   */

    printf("\nExercicio08 - Lista04\n");

    char p1[100], p2[100];

    printf("Digite a primeira palavra: ");
    scanf("%s", p1);

    printf("Digite a segunda palavra: ");
    scanf("%s", p2);

    int len1 = strlen(p1), len2 = strlen(p2);
    int i = 0, j = 0, isSub = 0;

    while (i < len1 && j < len2) {
        if (p1[i] == p2[j]) {
            i++;
        }
        j++;

        if (i == len1) {
            isSub = 1;
            break;
        }
    }

    i = 0;
    j = 0;
    int isSub2 = 0;
    while (i < len2 && j < len1) {
        if (p2[i] == p1[j]) {
            i++;
        }
        j++;

        if (i == len2) {
            isSub2 = 1;
            break;
        }
    }

    if (isSub == 1 || isSub2 == 1)
        printf("Uma palavra e subsequencia da outra.\n");
    else
        printf("As palavras nao sao subsequencias uma da outra.\n");

    return 0;
}

int exercise09(void) {
    /**
    9. Historicamente Cesar foi o primeiro a codificar mensagens. Ele reorganizava o texto de
    suas mensagens de maneira que o texto parecia n?o ter sentido. Cada mensagem sempre
    possua uma contagem de letras Mujo total equivalia a um quadrado perfeito, dependendo
    de quanto Cesar tivesse que escrever. Assim, uma mensagem com 16 caracteres usava
    um quadrado de quatro por quatro; se fossem 25 caracteres, seria cinco por cinco; 100
    caracteres requeriam um quadrado de dez por dez, etc. Seus oficiais sabiam que deviam
    transcrever o texto preenchendo as casas do quadrado sempre que uma mensagem aleatória
    chegasse. Ao fazerem isso, podiam ler a mensagem na vertical e seu sentido se tornaria
    claro.Escreva um programa que le o tamanho de uma string e em seguida uma string. Depois o
    programa escreve a mensagem decifrada.
   <p>Exemplo:
    <p>36
    <p>MEEUMOCSHMSC1T*AGU0A***L2****T*****A
    <p>Esta mensagem pode ser transcrita em um quadrado perfeito 6x6.
    <p>M E E U M O
    <p>C S H M S C
    <p>1 T * A G U
    <p>0 A * * * L
    <p>2 * * * * T
    <p>* * * * * A
    <p>Lendo cada coluna da matriz (desconsiderando o caractere ?*?), a sa?da deve ser:
    MC102 ESTA EH UMA MSG OCULTA.
    */
    return 0;
}

int exercise10(void) {

    return 0;
}

int exercise11(void) {
    /**
        Ler uma string de ate 79 caracteres e salvar a inversa desta em um
        <p>vetor. Imprimir a inversa da string lida.
<p>
        <p>Exemplo de entrada:
        <p>Out of the night that covers me
        <p>e vetor resultante:
        <p>em srevoc taht thgin eht fo tuO

       <p> Refaca o programa de tal forma que nao seja utilizado nenhum vetor
        */

    char st1[80], stInversa[80];
    int i, j, tam;

    printf("  \nDigite um texto (max. 79):");

    fflush(stdin);
    fgets(st1, sizeof(st1), stdin);

    int comStrlen = strlen(st1) - 1;

    for (tam = 0; (st1[tam] != '\0') && (st1[tam] != '\n'); tam++);

    printf("\ntamanho da string com strlen: %llu\n", strlen(st1) - 1);
    printf("Tamanho da string com for:    %d\n", tam);

    for (j = comStrlen - 1, i = 0; j >= 0; j--, i++)
        stInversa[j] = st1[i];

    stInversa[comStrlen] = '\0';

    printf("\n**********************\n");
    printf("Texto:   %s", st1);
    printf("Inversa: %s", stInversa);
    printf("\n**********************\n");

    char *st3 = inversorTexto(st1);
    char *st4 = inversorTexto2(st1);
    printf("Inversa: %s\n", st3);
    printf("Inversa: %s \n", st4);

    return 0;
}

int exercise12(void) {

    /**
       Como exemplo de uso de strings vamos implementar duas
       <p>funcionalidades basicas de processadores de texto:

       <p>1 - Contar o numero de palavras em um texto.
     */

    printf("1 - Contar o numero de palavras em um texto.\n");

    char s[80];
    int i = 0, n = 0;

    printf("Digite um texto que voce gostaria de saber quantas palavras tem: (limite 80):  ");

    fflush(stdin);
    fgets(s, sizeof(s), stdin);
    while (s[i] != '\n' && s[i] != '\0') {
        while (s[i] == ' ') {
            i++;
        }

        if (s[i] != '\n' && s[i] != '\0') {
            n++;
            while (s[i] != ' ' && s[i] != '\n' && s[i] != '\0') {
                i++;
            }
        }
    }

    printf("Total de palavras: %d\n", n);
    int contador = contadorDePalavras(s);
    int contador2 = contadorDePalavras2(s);
    printf("Total de palavras1: %d\n", contador);
    printf("Total de palavras2: %d\n", contador2);

    return 0;
}

int exercise13(void) {
    /**
      Fazer um programa que acha todas as posicoes de ocorrencia de uma
      <p>palavra em um texto.

     <p> Entrada:
      <p>Texto=  a tete tetete
      <p>Palavra=  tete

    <p> Saida:
    <p>  2, 7 e 9.
    */

    printf("2 - Fazer a busca de uma palavra em um texto e:\n");
    printf("a) retornar a posicao de todas as ocorrencias\n");

    char s[80];
    char p[80];

    printf("Digite um texto: ");
    fflush(stdin);
    fgets(s, sizeof(s), stdin);

    printf("Digite uma palavra: ");
    fflush(stdin);
    fgets(p, sizeof(p), stdin);

    int tamTexto = strlen(s) - 1;
    int tamPalavra = strlen(p) - 1;

    int i, j;

    // Percorre o texto
    for (i = 0; i <= tamTexto - tamPalavra; i++) {
        j = 0; // Inicializa o passo que vai percorre a palavra
        while (j < tamPalavra && p[j] == s[i + j])
            j++; // Incrementa o contador


        // Se j == tamPalavra, significa que a palavra foi encontrada
        if (j == tamPalavra)
            printf("Encontrada na posicao [%d - %d]\n", i, i + tamPalavra - 1);

    }

    return 0;
}

int exercise14(void) {
    /*
        Escreva um programa que le uma string de ate 50 caracteres, e
        imprime \Palindrome"caso a string seja um palindrome e
        "Nao Palindrome"caso contrario.
    */

    printf("Digite um string de ate 50 caracteres:");
    char s[50];
    int i = 0;

    fflush(stdin);
    fgets(s, sizeof(s), stdin);

    int tam = strlen(s) - 1;
    int j = tam - 1;

    while (i < j) {
        if (s[i] != s[j]) {
            printf(" Nao e palindrome\n");
            return 0;
        }
        i++;
        j--;
    }
    printf("%s E palindrome\n", s);

    return 0;
}

int exercise15(void) {
    /**
      Refaca o exemplo visto em aula de inversao de uma string de tal
      forma que nao seja utilizado nenhum vetor adicional! Ou seja
      devemos computar a inversa no proprio vetor original.
  */

    printf("Digite um string de ate 50 caracteres:");
    char s[50];

    fflush(stdin);
    fgets(s, sizeof(s), stdin);

    int tam = strlen(s) - 1;
    int i;

    for (i = 0; i < tam; i++) {
        char temp = s[i];
        s[i] = s[tam];
        s[tam] = temp;
    }

    printf("Inversa: %s\n", s);

    return 0;
}

int exercise16(void) {
    /**
     Fazer a busca de uma palavra em um texto e:
     <p>a) retornar quantas vezes essa palavra esta inserida em determinado texto
    <p>b) retornar a posicao da primeira ocorrencia dessa palavra
     */

    char s[80], palavra[80];

    printf("Digite um texto: ");
    fflush(stdin);
    fgets(s, sizeof(s), stdin);

    printf("Digite uma palavra: ");
    fflush(stdin);
    fgets(palavra, sizeof(palavra), stdin);

    int tamTexto = strlen(s) - 1;
    int tamPalavra = strlen(palavra) - 1;
    int freq = 0;

    int i, j;
    for (i = 0; i <= tamTexto - tamPalavra; i++) {
        j = 0; // Inicializa o passo que vai percorre a palavra
        // Percorre a palavra
        while (j < tamPalavra && palavra[j] == s[i + j]) {
            j++; // Incrementa o contador
        }

        if (j == tamPalavra) {
            freq++; // Incrementa o contador de frequencia
            printf("Encontrada na posicao [%d - %d]\n", i, i + tamPalavra - 1);
        }
    }

    if (freq == 0)
        printf("Palavra nao encontrada!\n");
    else
        printf("Palavra encontrada %d vezes!\n", freq);


    return 0;
}

int exercicio17(void) {

    /*
     17 -  Ler uma string de ate 79 caracteres e salvar a inversa desta em um
     vetor. Imprimir a inversa da string lida.
     */

    char st[80], stInv[80];

    printf("Digite um texto (max. 79):");
    scanf("%s", st);
    int tam;
    tam = 0;

    //maneira manual de calcular o tamanho de um vetor de char
    while ((st[tam] != '\0') && (st[tam] != '\n'))
        tam++;

    stInv[tam] = '\0';

    for (int i = 0; i < tam; i++)
        stInv[i] = st[tam - i - 1];

    printf("Texto:   %s\n", st);
    printf("Inversa: %s\n", stInv);

    return 0;
}

int exercicio18(void) {

    char st[80], stInv[80];
    int i, j, tam;

    printf("Digite um texto (max. 79):");
    scanf("%s", st);

    //maneira de calcular o tamanho deu uma String
    for (tam = 0; (st[tam] != '\0') && (tam < 80); tam++);

    stInv[tam] = '\0';
    for (j = tam - 1, i = 0; j >= 0; j--, i++)
        stInv[j] = st[i];

    printf("Texto:   %s\n", st);
    printf("Inversa: %s\n", stInv);


    return 0;
}

int exercicio19(void) {

    char st[80], stInv[80];
    int i, j, tam;

    printf("Digite um texto (max. 79):");
    fflush(stdin);
    fgets(st, sizeof(st), stdin);

    //maneira de calcular o tamanho deu uma String
    for (tam = 0; (st[tam] != '\0') && (tam < 80); tam++);

    stInv[tam] = '\0';
    for (j = tam - 1, i = 0; j >= 0; j--, i++)
        stInv[j] = st[i];

    printf("Texto:   %s\n", st);
    printf("Inversa: %s\n", stInv);

    return 0;
}

int exercicio20(void) {
    /*
     * 1 - char *strcat(char *s1, const char *s2: Para fazer a concatenação de duas strings
     * 2 - int strcmp(const char *s1, const char *s2): Para fazer a comparacao lexicografica (utilizada em ordenação) de duas strings
     * 3 - char *strcpy(char *s1, const char *s2): Para fazer a cópia de uma string para outra
     * 4 - int strlen(const char *s): Para calcular o tamanho de uma string
     */

    char s1[80], s2[80] = "Vinicius dos Santos Andrade";
    strcpy(s1, s2);

    printf("s1: %s\n", s1);
    printf("s2: %s\n", s2);

    return 0;
}

int exercicio21(void) {

    /*Programa que conta o número de palavras em textos sem pontuação*/

    char s[80];
    int i = 0, n = 0;

    printf("Digite um texto que voce gostaria de saber quantas palavras tem: (limite 80):  ");
    fflush(stdin);
    fgets(s, 80, stdin);

    while (s[i] != '\n' && s[i] != '\0') {
        while (s[i] == ' ') {
            i++;
        }

        if (s[i] != '\n' && s[i] != '\0') {
            n++;
            while (s[i] != ' ' && s[i] != '\n' && s[i] != '\0') {
                i++;
            }
        }
    }

    printf("Total de palavras: %d\n", n);


    return 0;
}

int exercicio22(void) {

    /*
     Fazer um programa que acha todas as posições de ocorrência de uma
     palavra em um texto.
     */

    char s[80], p[80];
    int tamS, tamP, i, j;

    printf("Digite um texto: ");
    fflush(stdin);
    fgets(s, sizeof(s), stdin);

    printf("Digite uma palavra: ");
    fflush(stdin);
    fgets(p, sizeof(p), stdin);

    tamS = strlen(s) - 1;
    tamP = strlen(p) - 1;

    for (i = 0; i <= tamS - tamP; i++) {
        j = 0;
        while (j < tamP && p[j] == s[i + j])
            j++;

        if (j == tamP)
            printf("Encontrada na posicao [%d - %d]\n", i, i + tamP - 1);
    }

    return 0;
}

int exercicio23(void) {

    /*
     23 - Escreva um programa que lê uma string de até 50 caracteres, e
     imprime "Palindromo" caso a string seja um palindromo e  "Não Palindromo"
     caso contrário
     */

    char s[50];
    printf("Digite uma string de ate 50 caracteres: ");
    fflush(stdin);
    fgets(s, sizeof(s), stdin);

    int tam = strlen(s) - 1; // Desconsidera o caractere de nova linha '\n'
    int i, j = tam - 1;

    for (i = 0; i < tam; i++) {
        if (s[i] != s[j]) {
            printf("Nao e palindromo!\n");
            return 0;
        }
        j--;
    }

    printf("E palindromo!\n");

    return 0;
}

int exercicio24(void) {

    /*
     24 -  Refaça o exemplo visto em aula de inversão dee uma string de tal
     forma que não seja utilizado nenhum vetor adicional! Ou seja devemos
     computar a inversa no proprio vetor original
     */

    printf("Digite uma string: ");
    char st[80];
    fflush(stdin);
    fgets(st, sizeof(st), stdin); //string / tamanho / entrada Padrão

    int tam = strlen(st) - 1;
    int i, j;

    for (i = 0, j = tam; j > 0; i++, j--) {
        char temp = st[i];
        st[i] = st[j];
        st[j] = temp;
    }

    printf("%s\n", st);

    return 0;
}

int displayMenuAndGetChoice(void) {
    printf("Exercise 01:\n");
    printf("Exercise 02:\n");
    printf("Exercise 03:\n");
    printf("Exercise 04:\n");
    printf("Exercise 05:\n");
    printf("Exercise 06:\n");
    printf("Exercise 07:\n");
    printf("Exercise 08:\n");
    printf("Exercise 09:\n");
    printf("Exercise 10:\n");
    printf("Exercise 11:\n");
    printf("Exercise 12:\n");
    printf("Exercise 13:\n");
    printf("Exercise 14:\n");
    printf("Exercise 15:\n");
    printf("Exercise 16:\n");
    printf("Exercise 17:\n");
    printf("Exercise 18:\n");
    printf("Exercise 19:\n");
    printf("Exercise 20:\n");
    printf("Exercise 21:\n");
    printf("Exercise 22:\n");
    printf("Exercise 23:\n");
    printf("Exercise 24:\n");

    printf("Enter the number of the exercise you want to execute: ");

    int choice;
    scanf("%d", &choice);
    return choice;
}

void executeExercise(int choice) {
    switch (choice) {
        case 1:
            exercise01();
            break;
        case 2:
            exercise02();
            break;
        case 3:
            exercise03();
            break;
        case 4:
            exercise04();
            break;
        case 5:
            exercise05();
            break;
        case 6:
            exercise06();
            break;
        case 7:
            exercise07();
            break;
        case 8:
            exercise08();
            break;
        case 9:
            exercise09();
            break;
        case 10:
            exercise10();
            break;
        case 11:
            exercise11();
            break;
        case 12:
            exercise12();
            break;
        case 13:
            exercise13();
            break;
        case 14:
            exercise14();
            break;
        case 15:
            exercise15();
            break;
        case 16:
            exercise16();
            break;
        case 17:
            exercicio17();
            break;
        case 18:
            exercicio18();
            break;
        case 19:
            exercicio19();
            break;
        case 20:
            exercicio20();
            break;
        case 21:
            exercicio21();
            break;
        case 22:
            exercicio22();
            break;
        case 23:
            exercicio23();
            break;
        case 24:
            exercicio24();
            break;
        default:
            printf("Invalid option!\n");
            break;
    }
}

bool getExitChoice(void) {
    int exitChoice;
    do {
        printf("Do you want to exit?\n"
               "Enter (1) for Yes or (0) for No: ");
        scanf("%d", &exitChoice);
    } while (exitChoice != 0 && exitChoice != 1);
    return exitChoice;
}