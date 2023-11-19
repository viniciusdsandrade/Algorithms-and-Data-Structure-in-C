#include <stdio.h>
#include <locale.h>
#include <stdbool.h>

#define MAX_EXERCISES 29

int exercicio01(void) {
    /**
    1. Faça um programa que imprima um menu de 4 pratos na tela e uma quinta opção para sair do programa.
    <p>O programa deve imprimir o prato solicitado. O programa deve terminarquando for escolhido a quinta opção.
    */

    printf("\nExe01 - Lista02\n");

    int opcao = 1;

    do {
        int escolha;
        printf("Escolha um prato:\n");
        printf("(1) Feijoada\n");
        printf("(2) Arroz com Feijão\n");
        printf("(3) Macarrão\n");
        printf("(4) Bife\n");
        printf("(5) Sair\n");

        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                printf("Você escolheu Feijoada\n\n");
                break;
            case 2:
                printf("Você escolheu Arroz com Feijão\n\n");
                break;
            case 3:
                printf("Você escolheu Macarrão\n\n");
                break;
            case 4:
                printf("Você escolheu Bife\n\n");
                break;
            case 5:
                printf("Finalizando o programa!\n\n");
                opcao = 2;
            default:
                printf("Opcao inválida!\n\n");
                break;
        }

        printf("Gostaria de escolhe outro prato?\n");
        printf("Deseja sair? (1) - Sim (0) - Não: ");
        scanf("%d", &opcao);

        while (opcao != 0 && opcao != 1) {
            printf("Opção inválida, digite novamente!\n");
            printf("Deseja sair? (1) - Sim (0) - Não: ");
            scanf("%d", &opcao);
        }
    } while (opcao != 1);
    printf("Fim do Exercicio 1!\n\n");

    return 0;
}

int exercicio02(void) {
    /**
    2. Faça um programa que lê dois números inteiros positivos a e b.
    <p>Utilizando laços, o seu programa deve calcular e imprimir o valor a^b.
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

    printf("O resultado de %d^%d é: %d\n\n", a, b, resultado);

    return 0;
}

int exercicio03(void) {
    /**
    <p> 3.Faça um programa que lê um númerone que compute e imprima o valor do somatório de 1 até n.
    <p> OBS: Não use formulas como a da soma de uma P.A.
     */

    printf("\nExe03 - Lista02\n");

    int n, resultado = 0;

    printf("Para calcular o somatorio de 1 até n, digite o valor de n:\n");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
        resultado += i;

    printf("O resultado do somatorio de 1 até %d é: %d\n\n", n, resultado);
    return 0;
}

int exercicio04(void) {
    /**
    4. No exemplo dos números primos visto em aula, não precisamos testar todos os números
    entre 2, . . . , (n?1), para verificar se dividem ou não n. Basta testarmos até n/2. Por que?
    <p>Qual o maior divisor possível de n? Na verdade basta testarmos os números 2, . . . ,pn.
    Por que?
    */

    printf("\nExe04 - Lista02\n");
    return 0;
}

int exercicio05(void) {
    /**
        5. Considere o programa para determinar se uma sequência de n números digitados pelo
        <p>usuário está ordenada ou não. Faça o programa usando uma variável contadora.
    */

    int qtdNumber, anterior, atual, ordenado = 1;

    printf("Digite a quantidade de números que você deseja digitar:\n");
    scanf("%d", &qtdNumber);

    printf("1º número: ");
    scanf("%d", &anterior);

    for (int i = 2; i < qtdNumber + 1; i++) {

        printf("%d número: ", i);
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
    6. Faça um programa em C que calcule o máximo divisor comum de dois números m, n. Você
    <p>deve utilizar a seguinte regra do cálculo do mdc com m # n
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
    7. Escreva um programa que lê um número n,
    e então imprime :
    1- menor número primo que é maior ou igual n,
    2- maior primo que é menor ou igual a n.
    */

    printf("\nExe07 - Lista02\n");

    int n, menorPrimoMaiorQueN = 0, maiorPrimoMenorQueN = 0;
    int isNPrime = 0;

    printf("Digite um numero n:\n");
    scanf("%d", &n);

    // verificar se o numero digitado 'n' é primo
    for (int i = 1; i <= n; i++) {

        if (n % i == 0)
            isNPrime++;

        if (isNPrime > 2)
            break; // Nao é primo
    }

    if (isNPrime == 2) {
        printf("O numero %d é primo!\n", n);
        printf("O menor numero primo que é maior ou igual a %d é: %d\n", n, n);
        printf("O maior numero primo que é menor ou igual a %d é: %d\n", n, n);
    } else {
        printf("O numero %d não é primo!\n\n", n);

        // verificar o menor numero primo que é maior ou igual a 'n'
        for (int i = n + 1; i <= 2 * n; i++) // Laço que percorrer n até o seu dobro, que com certeza não será primo
        {
            // Aqui vou verificar a partir de n+1 até o dobro de n se o numero é primo
            menorPrimoMaiorQueN = 0; // reiniciar a contagem para cada número i
            for (int j = 1; j <= i; j++) {

                if (i % j == 0)
                    menorPrimoMaiorQueN++;

                if (menorPrimoMaiorQueN > 2)
                    break; // Nao é primo
            }
            if (menorPrimoMaiorQueN == 2)
                printf("O menor numero primo que é maior ou igual a %d é: %d\n", n, i);
        }
        // verificar o maior numero primo que é menor ou igual a 'n'
        for (int k = n - 1; k >= 1; k--) {
            maiorPrimoMenorQueN = 0; // reiniciar a contagem para cada número k
            for (int j = 1; j <= k; j++) {

                if (k % j == 0)
                    maiorPrimoMenorQueN++;

                if (maiorPrimoMenorQueN > 2)
                    break; // Nao é primo
            }
            if (maiorPrimoMenorQueN == 2) {
                printf("O maior numero primo que é menor ou igual a %d é: %d\n", n, k);
                break;
            }
        }
    }
    return 0;
}

int exercicio08(void) {
    /**
    8. O que será impresso pelo programa abaixo? Assuma que o valor de D na declaração de x
    é o valor do último dígito do seu RA.

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
    9. Escreva um programa para ler n de números do tipo float e imprimir quantos deles estão
    nos seguintes intervalos: [0 . . . 25], [26 . . . 50], [51 . . . 75] e [76 . . . 100]. Por exemplo, para
    n = 10 e os seguintes dez números 2.0, 61.5,?1.0, 0.0, 88.7, 94.5, 55.0, 3.1415, 25.5, 75.0,
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
        printf("Digite o %dº numero do tipo float: ", i);
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
    10. Escreva um programa em C para computar a raiz quadrada de um número positivo. Use
    a idéia abaixo, baseada no método de aproximações sucessivas de Newton. O programa
    deverá imprimir o valor da vigésima aproximação.
    Seja Y um número, sua raiz quadrada é raiz da equação
    f(x) = x^2 ? Y.
    A primeira aproximação é x1 = Y/2. A (n + 1)-ésima aproximação é
    xn+1 = xn ? f(xn)/f'(xn)
    */

    printf("\nExe10 - Lista02\n");

    double Y, x;

    printf("Digite um número positivo: ");
    scanf("%lf", &Y);

    if (Y < 0) {
        printf("Erro: o número digitado é negativo.\n");
        return 0;
    }

    x = Y / 2.0;

    for (int i = 0; i < 20; i++)
        x = x - ((x * x - Y) / (2.0 * x));


    printf("A raiz quadrada de %lf é %lf\n", Y, x);

    return 0;
}

int exercicio11(void) {
    // Ctrl + k + c = Comentar
    // Ctrl + k + u = Descomentar

    // /*
    // Aponte os erros de implementação existentes no código em C, a seguir, desenvolvido com o intuito
    // de calcular e imprimir o fatorial de um número inteiro não-negativo n.
    // */

    // // 1º erro = Não pede para o usuário digitar o valor de n.
    // int valor;
    // scanf("%d", &valor);

    // // 2º erro = tipo do valor digitado não é o mesmo do tipo da variável fatorial. Embora não ocorre problemas de compilação, não é considerado boas práticas. Visto que pode haver perda de precisão das informações.
    // int n = valor;
    // float fatorial = 1;

    // if (n > -1)   // 3º erro = block de identacao do if inexiste.
    //     while (n > 0)
    //     {
    //         fatorial *= n;
    //         n--;
    //     }
    //     printf("O fatorial de %d é %d\n", valor, fatorial); // 4º erro = fatorial é do tipo float mas a mascara de impressão é %d, que é do tipo int
    // else
    //     printf("O fatorial de %d não existe\n", valor);
    // return 0;

    // Uma possível implementação correta do código seria:

    printf("\nExe11 - Lista02\n");

    int n, fatorial = 1;

    printf("Digite um número inteiro: ");
    scanf("%d", &n);

    // Calcula o fatorial
    for (int i = 1; i <= n; i++)
        fatorial *= i;

    printf("O fatorial de %d é %d\n", n, fatorial);

    return 0;
}

int exercicio12(void) {
    /**
   12. Implemente um programa que compute todas as soluções de equações do tipo
   x1 + x2 + x3 + x4 = C
   onde todas as variáveis x1, . . . ,x4 são inteiras não negativas e C > 0 é uma constante
   inteira. Melhore o seu programa com as seguinte idéias.
   ? Fixado x1, os valores possíveis para x2 são 0, . . . ,C ? x1. Fixado x1 e x2, os valores
   possíveis para x3 são 0, . . . ,C ?x1 ?x2. Fixados x1, x2, e x3, então x4 é unicamente
   determinado.
   */

    printf("\nExe12 - Lista02\n");

    int C;
    int cont = 0;
    printf("Digite um número inteiro: ");
    scanf("%d", &C);

    // Solução 1
    for (int x1 = 0; x1 <= C; x1++) {
        // Solução 2
        for (int x2 = 0; x2 <= C - x1; x2++) {
            // Solução 3
            for (int x3 = 0; x3 <= C - x1 - x2; x3++) {
                // Solução 4
                int x4 = C - x1 - x2 - x3;
                printf("%d + %d + %d + %d = %d\n", x1, x2, x3, x4, C);
                cont++;
            }
        }
    }
    printf("O numero total de solucoes para C = %d é %d \n", C, cont);
    printf("\n");
    return 0;
}

int exercicio13(void) {
    /**
    13. Na transformação decimal para binário, modifique o programa para que este obtenha o
    valor binário em uma variável inteira, ao invés de imprimir os dígitos um por linha na
    tela. Dica: Suponha n = 7 (111 em binário), e você já computou x = 11, para "inserir"o
    último dígito 1 em x você deve fazer x = x + 100. Ou seja, você precisa de uma variável
    acumuladora que armazena as potências de 10: 1, 10, 100, 1000 etc.
    */

    printf("\nExe13 - Lista02\n");

    printf("Digite um número inteiro que você deseja transformar para binário: ");
    int n;
    scanf("%d", &n);

    int x = 0; // variável que vai armazenar o número em binário
    int potencia = 1;
    while (n > 0) {
        x = x + (n % 2) * potencia; // o resto da divisão por 2 vai ser 1(quando for ímpar) ou 0(quando for par)
        n = n / 2;                  // como n é inteiro, a divisão por sempre vai ser a parte inteira da divisao
        potencia = potencia * 10;
    }
    printf("O número em binário é: %d\n", x);
    return 0;
}

int exercicio14(void) {
    /**
    14. Faça um programa que leia um inteiro n (no máximo 50) e imprima uma saída da forma:
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
    printf("Digite um número n: ");
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
    <p>15. Faça um programa que leia um número n e imprima n linhas na tela com o seguinte
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
    printf("Digite um número n:\n");
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
    <p>16. Faça um programa que leia um número n e imprima n linhas na tela com o seguinte
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
    printf("Digite um número n:\n");
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
        <p>17. Um jogador da Mega-Sena é supersticioso, e só faz jogos em que
        <p>o primeiro é par,
        <p>o segundo  é ímpar,
        <p>o terceiro é par,
        <p>o quarto   é ímpar,
        <p>o quinto   é par e
        <p>o sexto    é ímpar.
        <p>Faça um programa que imprima todas as possibilidades de jogos
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

    // imprime o número total de jogos possíveis
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
    Faça um programa que imprima todos os números primos entre 1 e um numero n digitado pelo usuario
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
                break; // significa que o numero não é primo
        }
        if (isPrime == 2)
            printf("%d \n", i);
    }

    return 0;
}

int exercicio23(void) {
    /**
    <p>Faça um programa que que o usuario iria digitar um numero e descubra todos os primos entre 1 e esse numero
<p>
    <p>a) Lista de todos os primos nesse intervalo numérico
    <p>b) Exiba o maior número primo
    <p>c) Exiba o menor número primo
    */

    int n, i, j, count = 0, max_prime = 0, min_prime = 0;
    printf("Digite um número: ");
    scanf("%d", &n);

    // iterando através dos números de 1 até n
    for (i = 1; i <= n; i++) {
        int is_prime = 0;
        // verificando se o número atual é primo
        for (j = 1; j <= i; j++) {

            if (i % j == 0)
                is_prime++;

            if (is_prime > 2)
                break;
        }

        if (is_prime == 2) {
            // se o número é primo, imprimir na tela e contar
            printf("%d \n", i);
            count++;

            // se é o primeiro primo encontrado, definir como mínimo e máximo
            if (count == 1) {
                min_prime = i;
                max_prime = i;
            }
                // caso contrário, atualizar o mínimo e o máximo, se necessário
            else {

                if (i > max_prime)
                    max_prime = i;

                if (i < min_prime)
                    min_prime = i;
            }
        }
    }
    // imprimir o maior e o menor primo encontrados
    printf("\nMaior número primo: %d\n", max_prime);
    printf("Menor número primo: %d\n", min_prime);

    return 0;
}

int exercicio24(void) {

    /**
 <p>Faça um programa que leia um número n e imprima n linhas na tela com o seguinte
 <p>formato (exemplo se n = 3):
<p>
 <p>A
 <p>B B
 <p>C C C

 */

    int n;
    printf("Digite um número n:\n");
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
      Escreva um programa que solicite um numero ao usuário até que o valor deste esteja entre os  valores 1 e 100
    */

    int n;
    printf("Digite um numero inteiro: \n");
    scanf("%d", &n);

    if (n >= 1 && n <= 100) {
        printf("Você digitou um numero entre 0 e 100\n");
    } else {
        do {
            printf("Digite um numero inteiro: \n");
            scanf("%d", &n);

        } while (n <= 1 || n >= 100);
        printf("Você digitou um numero entre 0 e 100\n");
    }
    return 0;
}

int exercicio26(void) {
    /**
    Escreva um programa em C que escreva na tela toda a tabela ASCII(0, 255chars), escrevendo em cada linha o código ASCII e o caractere correspondente.
    */
    int i;
    for (i = 0; i <= 255; i++)
        printf("%3d - %c\n", i, (char) i);

    return 0;
}

int exercicio27(void) {

    /**
      Escreva um program que solicite ao usuário um número e escreva simultaneamente a sequencia crescente e decrescente entre 1 e esse número
    */

    int n;

    printf("Digite um número: ");
    scanf("%d", &n);

    printf("Sequência crescente e decrescente: \n");
    for (int i = 1; i <= n; i++)
        printf("%d  %d\n", i, n - i + 1);


    printf("\n");

    return 0;
}

int exercicio28(void) {

    /**
    Escreva um programa que solicite ao usuário um número e um caractere. Em seguida terá que preencher n linhas, cada uma delas com n caracteres
    */

    int n;
    char ch;

    printf("Digite um número: ");
    scanf("%d", &n);
    printf("Digite um caractere:  ");
    scanf(" %c",
          &ch); // Não esquecer o espaço em branco antes de %c para retirar o <ENTER> que ficou no buffer do teclado, depois de introduzido o inteiro

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
      Faça um algoritmo que peça para o coloque a tabuada de todos os numeros de 1 até o numero que o usuário digitar
    */
    int d, res;
    printf("Qual numero inteiro você deseja saber a tabuada?\n");
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
    printf("Qual exercício você gostaria de realizar ?\n");

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
            printf("Exercicio não existente na lista.\n");
            break;
    }
}

bool getExitChoice(){
    int sair;
    do{
        printf("Deseja sair? (1) - Sim (0) - Não: ");
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