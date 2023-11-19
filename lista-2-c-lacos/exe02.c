#include <stdio.h>
#include <locale.h>
#include <stdbool.h>

#define MAX_EXERCISES 29

int exercicio01(void) {
    /**
    1. Fa�a um programa que imprima um menu de 4 pratos na tela e uma quinta op��o para sair do programa.
    <p>O programa deve imprimir o prato solicitado. O programa deve terminarquando for escolhido a quinta op��o.
    */

    printf("\nExe01 - Lista02\n");

    int opcao = 1;

    do {
        int escolha;
        printf("Escolha um prato:\n");
        printf("(1) Feijoada\n");
        printf("(2) Arroz com Feij�o\n");
        printf("(3) Macarr�o\n");
        printf("(4) Bife\n");
        printf("(5) Sair\n");

        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                printf("Voc� escolheu Feijoada\n\n");
                break;
            case 2:
                printf("Voc� escolheu Arroz com Feij�o\n\n");
                break;
            case 3:
                printf("Voc� escolheu Macarr�o\n\n");
                break;
            case 4:
                printf("Voc� escolheu Bife\n\n");
                break;
            case 5:
                printf("Finalizando o programa!\n\n");
                opcao = 2;
            default:
                printf("Opcao inv�lida!\n\n");
                break;
        }

        printf("Gostaria de escolhe outro prato?\n");
        printf("Deseja sair? (1) - Sim (0) - N�o: ");
        scanf("%d", &opcao);

        while (opcao != 0 && opcao != 1) {
            printf("Op��o inv�lida, digite novamente!\n");
            printf("Deseja sair? (1) - Sim (0) - N�o: ");
            scanf("%d", &opcao);
        }
    } while (opcao != 1);
    printf("Fim do Exercicio 1!\n\n");

    return 0;
}

int exercicio02(void) {
    /**
    2. Fa�a um programa que l� dois n�meros inteiros positivos a e b.
    <p>Utilizando la�os, o seu programa deve calcular e imprimir o valor a^b.
    */

    printf("\nExe02 - Lista02\n");

    int a, b, resultado = 1;

    printf("Para calcular a^b, digite o valor de a e b:\n");

    printf("a = ");
    scanf("%d", &a);

    printf("b = ");
    scanf("%d", &b);

    for (int i = 0; i < b; i++)
        resultado *= a;

    printf("O resultado de %d^%d �: %d\n\n", a, b, resultado);

    return 0;
}

int exercicio03(void) {
    /**
    <p> 3.Fa�a um programa que l� um n�merone que compute e imprima o valor do somat�rio de 1 at� n.
    <p> OBS: N�o use formulas como a da soma de uma P.A.
     */

    printf("\nExe03 - Lista02\n");

    int n, resultado = 0;

    printf("Para calcular o somatorio de 1 at� n, digite o valor de n:\n");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
        resultado += i;

    printf("O resultado do somatorio de 1 at� %d �: %d\n\n", n, resultado);
    return 0;
}

int exercicio04(void) {
    /**
    4. No exemplo dos n�meros primos visto em aula, n�o precisamos testar todos os n�meros
    entre 2, . . . , (n?1), para verificar se dividem ou n�o n. Basta testarmos at� n/2. Por que?
    <p>Qual o maior divisor poss�vel de n? Na verdade basta testarmos os n�meros 2, . . . ,pn.
    Por que?
    */

    printf("\nExe04 - Lista02\n");
    return 0;
}

int exercicio05(void) {
    /**
        5. Considere o programa para determinar se uma sequ�ncia de n n�meros digitados pelo
        <p>usu�rio est� ordenada ou n�o. Fa�a o programa usando uma vari�vel contadora.
    */

    int qtdNumber, anterior, atual, ordenado = 1;

    printf("Digite a quantidade de n�meros que voc� deseja digitar:\n");
    scanf("%d", &qtdNumber);

    printf("1� n�mero: ");
    scanf("%d", &anterior);

    for (int i = 2; i < qtdNumber + 1; i++) {

        printf("%d n�mero: ", i);
        scanf("%d", &atual);

        if (atual < anterior)
            ordenado = 0;

        anterior = atual;
    }
    if (ordenado)
        printf("Sequencia Ordenada\n");
    else
        printf("Sequencia Desordenada\n");

    return 0;
}

int exercicio06(void) {
    /**
    6. Fa�a um programa em C que calcule o m�ximo divisor comum de dois n�meros m, n. Voc�
    <p>deve utilizar a seguinte regra do c�lculo do mdc com m # n
    <p>mdc(m, n) = m se n = 0
    <p>mdc(m, n) = mdc(n,m%n) se n > 0
  */

    printf("\nExe06 - Lista02\n");

    int m, n, resto;

    printf("Digite o valor de m: ");
    scanf("%d", &m);

    printf("Digite o valor de n: ");
    scanf("%d", &n);

    while (n != 0) {
        resto = m % n;
        m = n;
        n = resto;
    }
    return 0;
}

int exercicio07(void) {
    /**
    7. Escreva um programa que l� um n�mero n,
    e ent�o imprime :
    1- menor n�mero primo que � maior ou igual n,
    2- maior primo que � menor ou igual a n.
    */

    printf("\nExe07 - Lista02\n");

    int n, menorPrimoMaiorQueN = 0, maiorPrimoMenorQueN = 0;
    int isNPrime = 0;

    printf("Digite um numero n:\n");
    scanf("%d", &n);

    // verificar se o numero digitado 'n' � primo
    for (int i = 1; i <= n; i++) {

        if (n % i == 0)
            isNPrime++;

        if (isNPrime > 2)
            break; // Nao � primo
    }

    if (isNPrime == 2) {
        printf("O numero %d � primo!\n", n);
        printf("O menor numero primo que � maior ou igual a %d �: %d\n", n, n);
        printf("O maior numero primo que � menor ou igual a %d �: %d\n", n, n);
    } else {
        printf("O numero %d n�o � primo!\n\n", n);

        // verificar o menor numero primo que � maior ou igual a 'n'
        for (int i = n + 1; i <= 2 * n; i++) // La�o que percorrer n at� o seu dobro, que com certeza n�o ser� primo
        {
            // Aqui vou verificar a partir de n+1 at� o dobro de n se o numero � primo
            menorPrimoMaiorQueN = 0; // reiniciar a contagem para cada n�mero i
            for (int j = 1; j <= i; j++) {

                if (i % j == 0)
                    menorPrimoMaiorQueN++;

                if (menorPrimoMaiorQueN > 2)
                    break; // Nao � primo
            }
            if (menorPrimoMaiorQueN == 2)
                printf("O menor numero primo que � maior ou igual a %d �: %d\n", n, i);
        }
        // verificar o maior numero primo que � menor ou igual a 'n'
        for (int k = n - 1; k >= 1; k--) {
            maiorPrimoMenorQueN = 0; // reiniciar a contagem para cada n�mero k
            for (int j = 1; j <= k; j++) {

                if (k % j == 0)
                    maiorPrimoMenorQueN++;

                if (maiorPrimoMenorQueN > 2)
                    break; // Nao � primo
            }
            if (maiorPrimoMenorQueN == 2) {
                printf("O maior numero primo que � menor ou igual a %d �: %d\n", n, k);
                break;
            }
        }
    }
    return 0;
}

int exercicio08(void) {
    /**
    8. O que ser� impresso pelo programa abaixo? Assuma que o valor de D na declara��o de x
    � o valor do �ltimo d�gito do seu RA.

    RA: 2760482311026
    */

    printf("\nExe08 - Lista02\n");

    int x = 5 + 6, y = 0;
    do {
        y = (x % 2) + 10 * y;
        x = x / 2;
        printf("x = %d, y = %d\n", x, y);
    } while (x != 0);
    while (y != 0) {
        x = y % 100;
        y = y / 10;
        printf("x = %d, y = %d\n", x, y);
    }
    return 0;
}

int exercicio09(void) {
    /**
    9. Escreva um programa para ler n de n�meros do tipo float e imprimir quantos deles est�o
    nos seguintes intervalos: [0 . . . 25], [26 . . . 50], [51 . . . 75] e [76 . . . 100]. Por exemplo, para
    n = 10 e os seguintes dez n�meros 2.0, 61.5,?1.0, 0.0, 88.7, 94.5, 55.0, 3.1415, 25.5, 75.0,
    seu programa deve imprimir:
    Intervalo [0..25]: 3
    Intervalo [26..50]: 0
    Intervalo [51..75]: 3
    Intervalo [76..100]: 2
    */

    printf("\nExe09 - Lista02\n");

    int n;
    printf("Quantos numeros do tipo float desejas digitar?\n");
    scanf("%d", &n);

    int qtdIntervalo1 = 0, qtdIntervalo2 = 0, qtdIntervalo3 = 0, qtdIntervalo4 = 0;

    for (int i = 1; i <= n; i++) {
        float number;
        printf("Digite o %d� numero do tipo float: ", i);
        scanf("%f", &number);

        if (number >= 0 && number <= 25)
            qtdIntervalo1++;
        else if (number > 25 && number <= 50)
            qtdIntervalo2++;
        else if (number > 50 && number <= 75)
            qtdIntervalo3++;
        else if (number > 75 && number <= 100)
            qtdIntervalo4++;

    }

    printf("\n");
    printf("Intervalo [0..25]   : %d\n", qtdIntervalo1);
    printf("Intervalo [26..50]  : %d\n", qtdIntervalo2);
    printf("Intervalo [51..75]  : %d\n", qtdIntervalo3);
    printf("Intervalo [76..100] : %d\n", qtdIntervalo4);
    printf("\n");

    return 0;
}

int exercicio10(void) {
    /**
    10. Escreva um programa em C para computar a raiz quadrada de um n�mero positivo. Use
    a id�ia abaixo, baseada no m�todo de aproxima��es sucessivas de Newton. O programa
    dever� imprimir o valor da vig�sima aproxima��o.
    Seja Y um n�mero, sua raiz quadrada � raiz da equa��o
    f(x) = x^2 ? Y.
    A primeira aproxima��o � x1 = Y/2. A (n + 1)-�sima aproxima��o �
    xn+1 = xn ? f(xn)/f'(xn)
    */

    printf("\nExe10 - Lista02\n");

    double Y, x;

    printf("Digite um n�mero positivo: ");
    scanf("%lf", &Y);

    if (Y < 0) {
        printf("Erro: o n�mero digitado � negativo.\n");
        return 0;
    }

    x = Y / 2.0;

    for (int i = 0; i < 20; i++)
        x = x - ((x * x - Y) / (2.0 * x));


    printf("A raiz quadrada de %lf � %lf\n", Y, x);

    return 0;
}

int exercicio11(void) {
    // Ctrl + k + c = Comentar
    // Ctrl + k + u = Descomentar

    // /*
    // Aponte os erros de implementa��o existentes no c�digo em C, a seguir, desenvolvido com o intuito
    // de calcular e imprimir o fatorial de um n�mero inteiro n�o-negativo n.
    // */

    // // 1� erro = N�o pede para o usu�rio digitar o valor de n.
    // int valor;
    // scanf("%d", &valor);

    // // 2� erro = tipo do valor digitado n�o � o mesmo do tipo da vari�vel fatorial. Embora n�o ocorre problemas de compila��o, n�o � considerado boas pr�ticas. Visto que pode haver perda de precis�o das informa��es.
    // int n = valor;
    // float fatorial = 1;

    // if (n > -1)   // 3� erro = block de identacao do if inexiste.
    //     while (n > 0)
    //     {
    //         fatorial *= n;
    //         n--;
    //     }
    //     printf("O fatorial de %d � %d\n", valor, fatorial); // 4� erro = fatorial � do tipo float mas a mascara de impress�o � %d, que � do tipo int
    // else
    //     printf("O fatorial de %d n�o existe\n", valor);
    // return 0;

    // Uma poss�vel implementa��o correta do c�digo seria:

    printf("\nExe11 - Lista02\n");

    int n, fatorial = 1;

    printf("Digite um n�mero inteiro: ");
    scanf("%d", &n);

    // Calcula o fatorial
    for (int i = 1; i <= n; i++)
        fatorial *= i;

    printf("O fatorial de %d � %d\n", n, fatorial);

    return 0;
}

int exercicio12(void) {
    /**
   12. Implemente um programa que compute todas as solu��es de equa��es do tipo
   x1 + x2 + x3 + x4 = C
   onde todas as vari�veis x1, . . . ,x4 s�o inteiras n�o negativas e C > 0 � uma constante
   inteira. Melhore o seu programa com as seguinte id�ias.
   ? Fixado x1, os valores poss�veis para x2 s�o 0, . . . ,C ? x1. Fixado x1 e x2, os valores
   poss�veis para x3 s�o 0, . . . ,C ?x1 ?x2. Fixados x1, x2, e x3, ent�o x4 � unicamente
   determinado.
   */

    printf("\nExe12 - Lista02\n");

    int C;
    int cont = 0;
    printf("Digite um n�mero inteiro: ");
    scanf("%d", &C);

    // Solu��o 1
    for (int x1 = 0; x1 <= C; x1++) {
        // Solu��o 2
        for (int x2 = 0; x2 <= C - x1; x2++) {
            // Solu��o 3
            for (int x3 = 0; x3 <= C - x1 - x2; x3++) {
                // Solu��o 4
                int x4 = C - x1 - x2 - x3;
                printf("%d + %d + %d + %d = %d\n", x1, x2, x3, x4, C);
                cont++;
            }
        }
    }
    printf("O numero total de solucoes para C = %d � %d \n", C, cont);
    printf("\n");
    return 0;
}

int exercicio13(void) {
    /**
    13. Na transforma��o decimal para bin�rio, modifique o programa para que este obtenha o
    valor bin�rio em uma vari�vel inteira, ao inv�s de imprimir os d�gitos um por linha na
    tela. Dica: Suponha n = 7 (111 em bin�rio), e voc� j� computou x = 11, para "inserir"o
    �ltimo d�gito 1 em x voc� deve fazer x = x + 100. Ou seja, voc� precisa de uma vari�vel
    acumuladora que armazena as pot�ncias de 10: 1, 10, 100, 1000 etc.
    */

    printf("\nExe13 - Lista02\n");

    printf("Digite um n�mero inteiro que voc� deseja transformar para bin�rio: ");
    int n;
    scanf("%d", &n);

    int x = 0; // vari�vel que vai armazenar o n�mero em bin�rio
    int potencia = 1;
    while (n > 0) {
        x = x + (n % 2) * potencia; // o resto da divis�o por 2 vai ser 1(quando for �mpar) ou 0(quando for par)
        n = n / 2;                  // como n � inteiro, a divis�o por sempre vai ser a parte inteira da divisao
        potencia = potencia * 10;
    }
    printf("O n�mero em bin�rio �: %d\n", x);
    return 0;
}

int exercicio14(void) {
    /**
    14. Fa�a um programa que leia um inteiro n (no m�ximo 50) e imprima uma sa�da da forma:
    1
        2
            3
                .
                    .
                        .
                            n
    */

    printf("\nExe14 - Lista02\n");

    int n;
    printf("Digite um n�mero n: ");
    scanf("%d", &n);

    for (int i = 1; (i > 50) ? i <= 50 : i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j)
                printf("%d", i);
            else
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}

int exercicio15(void) {
    /**
    <p>15. Fa�a um programa que leia um n�mero n e imprima n linhas na tela com o seguinte
    <p>formato (exemplo se n = 6):
    <p>
    <p>1
    <p>1 2
    <p>1 2 3
    <p>1 2 3 4
    <p>1 2 3 4 5
    <p>1 2 3 4 5 6
    */

    printf("\nExe15 - Lista02\n");

    int n;
    printf("Digite um n�mero n:\n");
    scanf("%d", &n);

    printf("\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++)
            printf("%d ", j);

        printf("\n");
    }
    printf("\n");

    return 0;
}

int exercicio16(void) {
    /**
    <p>16. Fa�a um programa que leia um n�mero n e imprima n linhas na tela com o seguinte
    <p>formato (exemplo se n = 6):
     <p>
    <p>+ * * * * *
    <p>* + * * * *
    <p>* * + * * *
    <p>* * * + * *
    <p>* * * * + *
    <p>* * * * * +
    */

    printf("\nExe16 - Lista02\n");

    int n;
    printf("Digite um n�mero n:\n");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j)
                printf("+ ");
            else
                printf("* ");
        }
        printf("\n");
    }
    return 0;
}

int exercicio17(void) {
    /**
        <p>17. Um jogador da Mega-Sena � supersticioso, e s� faz jogos em que
        <p>o primeiro � par,
        <p>o segundo  � �mpar,
        <p>o terceiro � par,
        <p>o quarto   � �mpar,
        <p>o quinto   � par e
        <p>o sexto    � �mpar.
        <p>Fa�a um programa que imprima todas as possibilidades de jogos
        <p>que este jogador supersticioso pode jogar.
    */

    printf("\nExe17 - Lista02\n");

    double cont = 0;

    for (int par1 = 2; par1 <= 54; par1 += 2) {
        for (int impar1 = par1 + 1; impar1 <= 55; impar1 += 2) {
            for (int par2 = 4; impar1 + 1 <= 56; par2 += 2) {
                for (int impar2 = par2 + 1; impar2 <= 57; impar2 += 2) {
                    for (int par3 = impar2 + 1; par3 <= 58; par3 += 2) {
                        for (int impar3 = par3 + 1; impar3 <= 59; impar3 += 2) {
                            cont++;
                            printf("%02d %02d %02d %02d %02d %02d\n", par1, impar1, par2, impar2, par3, impar3);
                            // usleep(500000);
                        }
                    }
                }
            }
        }
    }

    // imprime o n�mero total de jogos poss�veis
    printf("Numero total de jogos: %.0lf", cont);
    return 0;
}

int exercicio18(void) {
    printf("\nExe18 - Lista02\n");
    double cont = 0;
    for (int i = 1; i <= 55; i++) {
        for (int j = i + 1; j <= 56; j++) {
            for (int k = j + 1; k <= 57; k++) {
                for (int l = k + 1; l <= 58; l++) {
                    for (int m = l + 1; m <= 59; m++) {
                        for (int n = m + 1; n <= 60; n++) {
                            cont++;
                            // printf("%02d %02d %02d %02d %02d %02d\n", i, j, k, l, m, n);
                        }
                    }
                }
            }
        }
    }
    printf("%.0lf \n", cont);
    return 0;
}

int exercicio21(void) {

    /**
    Fa�a um programa que imprima todos os n�meros primos entre 1 e um numero n digitado pelo usuario
    */

    int n;
    printf("Digite um numero natural: \n");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        int isPrime = 0;
        for (int j = 1; j <= i; j++) {

            if (i % j == 0)
                isPrime++;

            if (isPrime > 2)
                break; // significa que o numero n�o � primo
        }
        if (isPrime == 2)
            printf("%d \n", i);
    }

    return 0;
}

int exercicio23(void) {
    /**
    <p>Fa�a um programa que que o usuario iria digitar um numero e descubra todos os primos entre 1 e esse numero
<p>
    <p>a) Lista de todos os primos nesse intervalo num�rico
    <p>b) Exiba o maior n�mero primo
    <p>c) Exiba o menor n�mero primo
    */

    int n, i, j, count = 0, max_prime = 0, min_prime = 0;
    printf("Digite um n�mero: ");
    scanf("%d", &n);

    // iterando atrav�s dos n�meros de 1 at� n
    for (i = 1; i <= n; i++) {
        int is_prime = 0;
        // verificando se o n�mero atual � primo
        for (j = 1; j <= i; j++) {

            if (i % j == 0)
                is_prime++;

            if (is_prime > 2)
                break;
        }

        if (is_prime == 2) {
            // se o n�mero � primo, imprimir na tela e contar
            printf("%d \n", i);
            count++;

            // se � o primeiro primo encontrado, definir como m�nimo e m�ximo
            if (count == 1) {
                min_prime = i;
                max_prime = i;
            }
                // caso contr�rio, atualizar o m�nimo e o m�ximo, se necess�rio
            else {

                if (i > max_prime)
                    max_prime = i;

                if (i < min_prime)
                    min_prime = i;
            }
        }
    }
    // imprimir o maior e o menor primo encontrados
    printf("\nMaior n�mero primo: %d\n", max_prime);
    printf("Menor n�mero primo: %d\n", min_prime);

    return 0;
}

int exercicio24(void) {

    /**
 <p>Fa�a um programa que leia um n�mero n e imprima n linhas na tela com o seguinte
 <p>formato (exemplo se n = 3):
<p>
 <p>A
 <p>B B
 <p>C C C

 */

    int n;
    printf("Digite um n�mero n:\n");
    scanf("%d", &n);

    printf("\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            printf("%c ", i + 64);
        }
        printf("\n");
    }
    printf("\n");

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            printf("%c ", i + 65);
        }
        printf("\n");
    }

    return 0;
}

int exercicio25(void) {

    /**
      Escreva um programa que solicite um numero ao usu�rio at� que o valor deste esteja entre os  valores 1 e 100
    */

    int n;
    printf("Digite um numero inteiro: \n");
    scanf("%d", &n);

    if (n >= 1 && n <= 100) {
        printf("Voc� digitou um numero entre 0 e 100\n");
    } else {
        do {
            printf("Digite um numero inteiro: \n");
            scanf("%d", &n);

        } while (n <= 1 || n >= 100);
        printf("Voc� digitou um numero entre 0 e 100\n");
    }
    return 0;
}

int exercicio26(void) {
    /**
    Escreva um programa em C que escreva na tela toda a tabela ASCII(0, 255chars), escrevendo em cada linha o c�digo ASCII e o caractere correspondente.
    */
    int i;
    for (i = 0; i <= 255; i++)
        printf("%3d - %c\n", i, (char) i);

    return 0;
}

int exercicio27(void) {

    /**
      Escreva um program que solicite ao usu�rio um n�mero e escreva simultaneamente a sequencia crescente e decrescente entre 1 e esse n�mero
    */

    int n;

    printf("Digite um n�mero: ");
    scanf("%d", &n);

    printf("Sequ�ncia crescente e decrescente: \n");
    for (int i = 1; i <= n; i++)
        printf("%d  %d\n", i, n - i + 1);


    printf("\n");

    return 0;
}

int exercicio28(void) {

    /**
    Escreva um programa que solicite ao usu�rio um n�mero e um caractere. Em seguida ter� que preencher n linhas, cada uma delas com n caracteres
    */

    int n;
    char ch;

    printf("Digite um n�mero: ");
    scanf("%d", &n);
    printf("Digite um caractere:  ");
    scanf(" %c",
          &ch); // N�o esquecer o espa�o em branco antes de %c para retirar o <ENTER> que ficou no buffer do teclado, depois de introduzido o inteiro

    printf("\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%c", ch);
        }
        printf(" \n");
    }
    printf("\n");

    return 0;
}

int exercicio29(void) {
    /**
      Fa�a um algoritmo que pe�a para o coloque a tabuada de todos os numeros de 1 at� o numero que o usu�rio digitar
    */
    int d, res;
    printf("Qual numero inteiro voc� deseja saber a tabuada?\n");
    scanf("%d", &d);

    for (int i = 1; i <= d; i++) {
        for (int j = 1; j <= 10; j++) {
            res = 0;
            res = i * j;
            printf("%d X %d = %d\n", i, j, res);
        }
        putchar('\n');
    }

    return 0;
}

int displayMenuAndGetChoice(){
    int escolha;
    printf("(1) Exercicio 1 - Lista 2\n");
    printf("(2) Exercicio 2 - Lista 2\n");
    printf("(3) Exercicio 3 - Lista 2\n");
    printf("(4) Exercicio 4 - Lista 2\n");
    printf("(5) Exercicio 5 - Lista 2\n");
    printf("(6) Exercicio 6 - Lista 2\n");
    printf("(7) Exercicio 7 - Lista 2\n");
    printf("(8) Exercicio 8 - Lista 2\n");
    printf("(9) Exercicio 9 - Lista 2\n");
    printf("(10) Exercicio 10 - Lista 2\n");
    printf("(11) Exercicio 11 - Lista 2\n");
    printf("(12) Exercicio 12 - Lista 2\n");
    printf("(13) Exercicio 13 - Lista 2\n");
    printf("(14) Exercicio 14 - Lista 2\n");
    printf("(15) Exercicio 15 - Lista 2\n");
    printf("(16) Exercicio 16 - Lista 2\n");
    printf("(17) Exercicio 17 - Lista 2\n");
    printf("(18) Exercicio 18\n");
    printf("(21) Exercicio 21\n");
    printf("(22) Exercicio 22\n");
    printf("(23) Exercicio 23\n");
    printf("(24) Exercicio 24\n");
    printf("(25) Exercicio 25\n");
    printf("(26) Exercicio 26\n");
    printf("(27) Exercicio 27\n");
    printf("(28) Exercicio 28\n");
    printf("(29) Exercicio 29\n");
    printf("Qual exerc�cio voc� gostaria de realizar ?\n");

    scanf("%d", &escolha);

    return escolha;
}

void executeExercise(int choice){
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
        case 17:
            exercicio17();
            break;
        case 18:
            exercicio18();
            break;
        case 21:
            exercicio21();
            break;
        case 23:
            exercicio23();
            break;
        case 24:
            exercicio24();
            break;
        case 25:
            exercicio25();
            break;
        case 26:
            exercicio26();
            break;
        case 27:
            exercicio27();
            break;
        case 28:
            exercicio28();
            break;
        case 29:
            exercicio29();
            break;
        default:
            printf("Exercicio n�o existente na lista.\n");
            break;
    }
}

bool getExitChoice(){
    int sair;
    do{
        printf("Deseja sair? (1) - Sim (0) - N�o: ");
        scanf("%d", &sair);
    }  while (sair != 0 && sair != 1);
    return sair;
}

int main(void) {
    setlocale(LC_ALL, "Portuguese");

    bool sair = false;

    do {
        int escolha = displayMenuAndGetChoice();

        if (escolha >= 1 && escolha <= MAX_EXERCISES) {
            executeExercise(escolha);
        } else {
            printf("Op??o inv?lida!\n");
        }
        sair = getExitChoice();
    } while (!sair);
    printf("Obrigado por utilizar o programa!\n");
    return 0;
}