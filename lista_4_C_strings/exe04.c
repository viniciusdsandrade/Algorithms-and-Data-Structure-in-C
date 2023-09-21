#include <stdio.h>
#include <locale.h>
#include <string.h>
#include "global.c"

#define MAX_EXERCISES 10

int exercicio01(void) {
    /**
       <p> 1 - Faca um programa que leia do teclado uma string (possivelmente com espacos) de ate 80
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

int exercicio02(void) {
    /**
        <p>2. Faca um programa que leia do teclado uma string (possivelmente com espacos) de ate 80
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

    char str[80];
    char strSemEspaco[80];

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
}

int exercicio03(void) {
    /**
        <p>3. Faca um programa que leia do teclado uma string (possivelmente com espacos) de ate 80
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

    char str[80];
    char strSemEspacoExtra[80];

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

int exercicio04(void) {
    /**
        <p>4. Escreva um programa que leia duas palavras do teclado e determina se a segunda e um
        <p>anagrama da primeira. Uma palavra e um anagrama de outra se todas as letras de uma
        <p>ocorrem na outra, em mesmo numero, independente da posicao. Exemplos: ROMA, MORA,
        <p>ORAM, AMOR, RAMO sao anagramas entre si.
    */

    printf("\nExercicio04 - Lista04\n");
    char str1[80];
    char str2[80];
    char aux[80];

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
        printf("Não e anagrama!\n");
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
            printf("Não é anagrama!\n");
            return 0;
        }
    }

    str1[tamStr1] = '\0'; // Coloca o caractere de fim de string
    aux[tamStr2] = '\0';

    printf("%s é anagrama de %s!\n", str1, aux);

    return 0;
}

int exercicio05(void) {

    /**
        5. Faça um programa que leia duas strings e elimine, da segunda string, todas as ocorrências
        dos caracteres da primeira string.
    */

    printf("\nExercicio05 - Lista04\n");

    char str1[80];
    char str2[80];

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

int exercicio06(void) {
    /**
        <p>6. Faça um programa que leia um texto T (com espacos) e uma palavra p do teclado. Em
        seguida o programa devera imprimir todas as posicoes onde ocorrem a palavra p em T.
        <p>Se por exemplo T = "duas bananas e 4 abacates. Nao havera mais bananas.", e p ="bananas",
        então o programa deveria imprimir 5 e 43.
    */

    printf("\nExercicio06 - Lista04\n");

    char t[80];
    char p[80];

    printf("Digite um texto de ate 80 caracteres: ");
    fflush(stdin); // Limpa o buffer do teclado
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

int exercicio07(void) {
    /**
    7. Escreva um programa que lê uma string de atÉ 50 caracteres, e imprime "Palindromo"caso
    <p>a string seja um palindromo e "Nao Palindromo" caso contr?rio.

    <p>OBS: Um palindromo é uma palavra ou frase, que é igual quando lida da esquerda para a
    direita ou da direita para a esquerda (assuma que s? s?o usados caracteres min?sculos
    e sem acentos. Espa?os em brancos devem ser descartados).

    <p>Exemplo de palindromo: saudavel leva duas.

    <p>DESAFIO: Adapte o código do palindro para que ele reconheça se uma frase com Letras maiusculas e minusculas e inclusive com pontuação é um palindro
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
    int i = 0;
    int j = tam - 1;

    str[tam] = '\0';

    if (isPalindrome(str) == 0)
        printf("\n'%s' NÃO é palíndromo!\n", str);
    else
        printf("\n'%s' É palíndromo!\n", str);

    return 0;
}

int exercicio08(void) {
    /**
        8. Faca um programa que leia duas palavras e verifique se uma delas pode ser obtida por
       <p> meio da remove o de letras da outra. A ordem das letras nao pode ser alterada.

       <p> Por exemplo:

        <p>moda e uma subsequencia em moradia
        cereja e uma subsequencia em cerveja
   */

    printf("\nExercicio08 - Lista04\n");

    char p1[100];
    char p2[100];

    printf("Digite a primeira palavra: ");
    scanf("%s", p1);

    printf("Digite a segunda palavra: ");
    scanf("%s", p2);

    int len1 = strlen(p1);
    int len2 = strlen(p2);
    int i = 0, j = 0;
    int isSub = 0;

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

int exercicio09(void) {
    /**
    9. Historicamente Cesar foi o primeiro a codificar mensagens. Ele reorganizava o texto de
    suas mensagens de maneira que o texto parecia n?o ter sentido. Cada mensagem sempre
    possua uma contagem de letras cujo total equivalia a um quadrado perfeito, dependendo
    de quanto Cesar tivesse que escrever. Assim, uma mensagem com 16 caracteres usava
    um quadrado de quatro por quatro; se fossem 25 caracteres, seria cinco por cinco; 100
    caracteres requeriam um quadrado de dez por dez, etc. Seus oficiais sabiam que deviam
    transcrever o texto preenchendo as casas do quadrado sempre que uma mensagem aleat?ria
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

int exercicio10(void) {

    return 0;
}

int exercicio11(void) {
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

    printf("\ntamanho da string com strlen: %d\n", strlen(st1) - 1);
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
}

int exercicio12(void) {

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

int exercicio13(void) {
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

int exercicio14(void) {
    /*
        Escreva um programa que le uma string de ate 50 caracteres, e
        imprime \Palindromo"caso a string seja um palindromo e
        "Nao Palindromo"caso contrario.
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
            printf(" Nao e palindromo\n");
            return 0;
        }
        i++;
        j--;
    }
    printf("%s E palindromo\n", s);

    return 0;
}

int exercicio15(void) {
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
    int i = 0;

    for (i = 0; i < tam; i++) {
        char temp = s[i];
        s[i] = s[tam];
        s[tam] = temp;
    }

    printf("Inversa: %s\n", s);

    return 0;
}

int exercicio16(void) {
    /**
     Fazer a busca de uma palavra em um texto e:
     <p>a) retornar quantas vezes essa palavra esta inserida em determinado texto
    <p>b) retornar a posicao da primeira ocorrencia dessa palavra
     */

    char s[80];
    char palavra[80];

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


int displayMenuAndGetChoice() {
    printf("Escolha uma opcao:\n");
    printf("1 - Exercicio 1\n");
    printf("2 - Exercicio 2\n");
    printf("3 - Exercicio 3\n");
    printf("4 - Exercicio 4\n");
    printf("5 - Exercicio 5\n");
    printf("6 - Exercicio 6\n");
    printf("7 - Exercicio 7\n");
    printf("8 - Exercicio 8\n");
    printf("9 - Exercicio 9\n");
    printf("10 - Exercicio 10\n");
    printf("11 - Exercicio 11\n");
    printf("12 - Exercicio 12\n");
    printf("13 - Exercicio 13\n");
    printf("14 - Exercicio 14\n");
    printf("15 - Exercicio 15\n");
    printf("16 - Exercicio 16\n");
    printf("20 - Sair\n");
    printf("Digite sua escolha: ");

    int choice;
    scanf("%d", &choice);
    return choice;
}

void executeExercise(int choice) {
    switch (choice) {
        case 1:
            exercicio01();
            break;
        case 2:
            exercicio02();
            break;
        case 3:
            exercicio03();
            break;
        case 4:
            exercicio04();
            break;
        case 5:
            exercicio05();
            break;
        case 6:
            exercicio06();
            break;
        case 7:
            exercicio07();
            break;
        case 8:
            exercicio08();
            break;
        case 9:
            exercicio09();
            break;
        case 10:
            exercicio10();
            break;
        case 11:
            exercicio11();
            break;
        case 12:
            exercicio12();
            break;
        case 13:
            exercicio13();
            break;
        case 14:
            exercicio14();
            break;
        case 15:
            exercicio15();
            break;
        case 16:
            exercicio16();
            break;
        default:
            printf("Opcao invalida!\n");
            break;
    }
}

bool getExitChoice() {
    int sair;
    do {
        printf("Deseja sair? (1) - Sim (0) - Nao: ");
        scanf("%d", &sair);


    } while (sair != 0 && sair != 1);
    return sair;
}

int main(void) {
    setlocale(LC_ALL, "Portuguese");

    bool sair = false;
    do{
        int escolha = displayMenuAndGetChoice();

        if(escolha >= 1 && escolha <= MAX_EXERCISES)
            executeExercise(escolha);
        else {
            printf("Opcao invalida!\n");
        }

        sair = getExitChoice();
    } while (!sair);
    printf("Fim do Programa!\n");
    printf("Ate Breve!");
    return 0;
}
