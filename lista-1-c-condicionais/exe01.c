#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <locale.h>

#define MAX_EXERCISES 10

void exercicio01(void) {

    /*
    1. Qual é o tipo de variável correta para armazenar as seguintes informações:
    a. A idade.
    b. O número de estrelas na galáxia.
    c. A quantidade de chuva média no mês de fevereiro.
    d. A área do seu quintal.
    */

    printf("Exercício 01 - Lista01\n");

    printf("1. Qual e o tipo de variavel correta para armazenar as seguintes informacoes:\n");
    printf("a. A idade.\n");
    printf("b. O numero de estrelas na galáxia.\n");
    printf("c. A quantidade de chuva media no mes de fevereiro.\n");
    printf("d. A Área do seu quintal.\n\n");
}

void exercicio02(void) {
    printf("Exercício 02 - Lista01\n");

    /*
    2. Indique a diferença entre as seguintes atribuições:
    char a;
    a = ’6’;
    a = 6;
    */

    printf(" 2. Indique a diferenca entre as seguintes atribuicoes:\n");
    printf("char a ;\n");
    printf("a = '6';\n");
    printf("a =  6 ;\n");

    printf("1- Na primeira linha, estamos declarando a variavel 'a' como um char \n");
    printf("2- Na segunda  linha atribuiimos '6' a ela. Aqui, '6' é interpretado como um caractere, nao como um numero inteiro. Portanto, o valor armazenado em 'a' sera o codigo ASCII correspondente ao caractere '6', que e 54 em decimal.\n");
    printf("3- Na terceira linha atribuimos o valor inteiro 6 diretamente a variavel 'a'. Aqui, 6 e um valor numerico inteiro. Portanto, o valor armazenado em 'a' sera 6.\n\n");
}

void exercicio03(void) {
    printf("Exercício 03 - Lista01\n");

    /*
    3. Faça um programa que leia um número real x e calcule o valor de f(x) = px+(x/2)+xx.
    (pesquise sobre as funções sqrt e pow).
    */

    printf(" 3. Faça um programa que leia um numero real x e calcule o valor de f(x) = square(x)+ (x/2)+ pow(x,x). ");
    double x, f;
    printf("Digite um número real: ");
    scanf("%lf", &x);
    f = sqrt(x) + (x / 2) + pow(x, x);

    printf("%.02lf\n\n", f);
}

int exercicio04(void) {

    printf("Exercício 04 - Lista01\n");

    /*
    4. Faça um programa que leia dois valores inteiros nas variáveis x e y e troque o conteúdo
    das variáveis. Refaça este problema sem o uso de outras variáveis que não x e y.
    */

    printf("4. Faça um programa que leia dois valores inteiros nas variáveis x e y e troque o conteudo das variaveis. Refaca este problema sem o uso de outras variaveis que nao x e y.\n");
    int a, b, temp;
    printf("Atribua um inteiro a A: \n");
    scanf("%d", &a);
    printf("Atribua um inteiro a B: \n");
    scanf("%d", &b);

    temp = a;
    a = b;
    b = temp;

    /*
    maneira utilizando apenas 2 variaveis e nenhuma auxiliar
    x = x + y;
    y = x - y;
    x = x - y;
    */

    printf("Os valores trocados são: A = %d | B = %d\n", a, b);
    return 0;
}

int exercicio05(void) {
    printf("Exercício 05 - Lista01\n");

    /*
    5. Faça um programa que leia os valores correspondentes aos três lados a, b e c de um
    triângulo. O programa então determina se o triângulo é isósceles, escaleno ou equilátero,
    informando isto para o usuário, e em seguida imprime a área A do triângulo utilizando a
    fórmula de Heron:
    */

    printf("5. Faça um programa que leia os valores correspondentes aos três lados a, b e c de um\n");
    printf("triângulo. O programa então determina se o triângulo é isósceles, escaleno ou equilátero\n");
    printf("informando isto para o usuário, e em seguida imprime a área A do triângulo utilizando a\n");
    printf("fórmula de Heron:\n");

    float ladoA, ladoB, ladoC, numF, numS;
    printf("Atribua um inteiro a A: \n");
    scanf("%f", &ladoA);
    printf("Atribua um inteiro a B: \n");
    scanf("%f", &ladoB);
    printf("Atribua um inteiro a C: \n");
    scanf("%f", &ladoC);

    if ((ladoA * ladoB * ladoC) <= 0) {
        printf("Valores inválidos\n");
    }

    if (ladoA < ladoB + ladoC && ladoB < ladoA + ladoC && ladoC < ladoA + ladoB) {
        if (ladoA != ladoB && ladoB != ladoC && ladoA != ladoC) {
            printf("o triângulo %.02f , %.02f, %.02f e Escaleno\n", ladoA, ladoB, ladoC);
        } else if (ladoA == ladoB && ladoB == ladoC) {
            printf("Triâgulo equilátero\n");
        } else {
            if (ladoA == ladoB) {
                printf("Triângulo Isósceles pois ladoA: %.02f = ladoB: %.02f\n", ladoA, ladoB);
            } else if (ladoB == ladoC) {
                printf("Triângulo Isósceles pois ladoB: %.02f - ladoC: %.02f\n", ladoB, ladoC);
            } else {
                printf("Triângulo Isósceles pois ladoA: %.02f - ladoC: %.02f\n", ladoA, ladoC);
            }
        }

        numS = (ladoA + ladoB + ladoC) / 2;
        numF = sqrtf(numS * (numS - ladoA) * (numS - ladoB) * (numS - ladoC));

        printf("Área do triângulo digitado = %.02f", numF);
    } else {
        printf("Os valores informados nao formam um triângulo.\n");
    }

    return 0;
}

int exercicio06(void) {

    printf("Exercício 06 - Lista01\n");

    /*
    6. A solução abaixo está correta para classificar um número como par e menor que 100, ou
    par e maior ou igual a 100, etc, como no exemplo visto em aula?

    int a;
    printf("Digite um número inteiro:");
    scanf("%d", &a);
    if( ( a % 2 == 0) && (a<100) )
        printf("O número é par e menor que 100\n");
    else if( a>=100 )
        printf("O número é par e maior ou igual a 100\n");
    if( ( a % 2 != 0) && (a<100) )
        printf("O número é ímpar e menor que 100\n");
    else if (a>=100)
        rintf("O número é ímpar e maior que 100\n");
    */

    int a;
    printf("Digite um numero inteiro:");
    scanf("%d", &a);

    if (a < 100) {
        if (a % 2 == 0)
            printf("Par <= 100\n");
        else
            printf("Ímpar < 100\n");
    } else {
        if (a % 2 == 0)
            printf("Par >= 100\n");
        else
            printf("Ímpar > 100\n");
    }
    return 0;
}

int exercicio07(void) {
    printf("Exercício 07 - Lista01\n");
    /*
    7. Escreva um programa lê três números e os imprime em ordem (ordem crescente).
    */

    int num1, num2, num3;

    printf("Atribua um inteiro a A: \n");
    scanf("%d", &num1);

    printf("Atribua um inteiro a B: \n");
    scanf("%d", &num2);

    printf("Atribua um inteiro a C: \n");
    scanf("%d", &num3);

    if (num1 < num2 && num1 < num3 && num2 < num3) {
        printf("Números em ordem crescente\n");
        printf("%d, %d, %d\n", num1, num2, num3);
    } else if (num1 < num2 && num1 < num3 && num3 < num2) {
        printf("Números em ordem crescente\n");
        printf("%d, %d, %d\n", num1, num3, num2);
    } else if (num3 < num2 && num3 < num1 && num1 < num2) {
        printf("Números em ordem crescente\n");
        printf("%d, %d, %d\n", num3, num1, num2);
    } else if (num3 < num2 && num3 < num1 && num2 < num1) {
        printf("Números em ordem crescente\n");
        printf("%d, %d, %d\n", num3, num2, num1);
    } else if (num2 < num1 && num2 < num3 && num1 < num3) {
        printf("Números em ordem crescente\n");
        printf("%d, %d, %d\n", num2, num1, num3);
    } else if (num2 < num1 && num2 < num3 && num3 < num1) {
        printf("Números em ordem crescente\n");
        printf("%d, %d, %d\n", num2, num3, num1);
    }

    return 0;
}

int exercicio08(void) {
    printf("Exercício 08 - Lista01\n");

    /*
    8. Faça um programa que lê um caracter ’F’ ou ’C’, que indica se o próximo número a ser
    digitado corresponde a temperatura em Fahrenheit ou Celsius. Em seguida o programa
    deve ler o valor da temperatura e então imprimir o valor correspondente da temperatura
    na outra unidade de medida. Obs.: (C = 5/9 · (F − 32)).
    */

    char temp;
    float F, C, conversionToCelsius, conversionToFahrenheit;

    printf("Digite a unidade de temperatura: \n");
    printf("F - Fahrenheit C - Celsius\n");

    scanf("%c", &temp);

    if (temp == 'F' || temp == 'f') {

        printf("Digite a temperatura em F\n");
        scanf("%f", &F);

        conversionToCelsius = (F - 32) * (5.0 / 9.0);

        printf("%.02fF = %.02fC \n", F, conversionToCelsius);
    } else if (temp == 'C' || temp == 'c') {
        printf("Digite a temperatura em C\n");
        scanf("%f", &C);

        conversionToFahrenheit = (C * (9.0 / 5.0)) + 32;

        printf("%.02fC = %.02fF \n", C, conversionToFahrenheit);
    } else {
        printf("Unidade de medida nao identificada\n");
    }

    return 0;
}

void exercicio09(void) {
    printf("Exercício 09 - Lista01\n");

    /*
    9. Faça um programa que leia um ano (valor inteiro) e imprima se ele é bissexto ou não. OBS:
    São bissexto todos os anos múltiplos de 400. Não sendo múltiplo de 400, são bissextos todos
    os anos múltiplos de 4 mas que não são múltiplos de 100.
    */

    int year;
    printf("Digite um ano\n");
    scanf("%d", &year);

    if ((year % 4 == 0) && (year % 100 != 0 || year % 400 == 0)) {
        printf("%d é bissexto\n", year);
    } else {
        printf("%d não é bissexto\n", year);
    }
}

int exercicio10(void) {
    printf("Exercício 10 - Lista01\n");

    /*
    10. Escreva um programa que determina a data cronologicamente maior de duas datas fornecidas
    pelo usuário. Cada data deve ser fornecida por três valores inteiros onde o primeiro
    representa um dia, o segundo um mês e o terceiro um ano.
    */

    int dia1, mes1, ano1, dia2, mes2, ano2;

    printf("Digite a primeira data (dd mm aaaa): ");
    scanf("%d %d %d", &dia1, &mes1, &ano1);

    printf("Digite a segunda data (dd mm aaaa): ");
    scanf("%d %d %d", &dia2, &mes2, &ano2);

    if (ano1 == ano2 && mes1 == mes2 && dia1 == dia2) {
        printf("As duas datas sao Cronologicamente iguais: %02d/%02d/%d\n", dia1, mes1, ano1);
    } else if (ano1 > ano2 || (ano1 == ano2 && mes1 > mes2) || (ano1 == ano2 && mes1 == mes2 && dia1 > dia2)) {
        printf("A primeira data e Cronologicamente maior: %02d/%02d/%d\n", dia1, mes1, ano1);
    } else {
        printf("A segunda data e Cronologicamente maior: %02d/%02d/%d\n", dia2, mes2, ano2);
    }

    return 0;
}

int exercicio11(void) {
    printf("Exercício 11 - Lista01\n");

    /*
    11. Uma pessoa pode se aposentar pelo INSS caso esteja em alguma das situações abaixo:
    • É do sexo masculino, possui pelo menos 65 anos, e pelo menos 10 anos de contribuição.
    • É do sexo masculino, possui pelo menos 63 anos, e pelo menos 15 anos de contribuição.
    • É do sexo feminino, possui pelo menos 63 anos, e pelo menos 10 anos de contribuição.
    • É do sexo feminino, possui pelo menos 61 anos, e pelo menos 15 anos de contribuição.
    Crie um programa para ler um caracter ’M’ ou ’F’ que representa o sexo de um indivíduo,
    ler a sua idade, e seu tempo de contribuição. O programa deverá então imprimir “Aposentável”
    caso o indivíduo se enquadrar em uma das situações acima. Caso contrário o
    programa deverá imprimir “Não Aposentável”.
    */

    char sexo;
    int idade;
    int contribuicao;

    printf("M - Masculino | F - Feminino\n");
    scanf("%s", &sexo);

    printf("Idade: ");
    scanf("%d", &idade);

    if (idade < 0 || idade > 120) {
        printf("idade invalida! \n");
    }
    printf("Anos de contribuicao: \n");
    scanf("%d", &contribuicao);

    if (contribuicao < 0 || contribuicao > 120) {
        printf("contribuicao invalida! \n");
    }

    if (idade * contribuicao <= 0 && contribuicao == 0) {
        printf("Erro na digitação dos dados\n");
        return 0;
    }

    if (contribuicao + 3 > idade && idade < 18) {
        printf("(Erro) Tempo de contribuicao invalido.\n");
        return 0;
    }

    if (sexo == 'M' || sexo == 'm') {
        if (idade >= 65 && contribuicao >= 10) {
            printf("Aposentável!\n");
            printf("É do sexo masculino, possui pelo menos 65 anos, e pelo menos 10 anos de contribuicao.\n");
        } else if (idade >= 63 && contribuicao >= 15) {
            printf("Aposentavel!\n");
            printf("É do sexo masculino, possui pelo menos 63 anos, e pelo menos 15 anos de contribuicao\n");
        } else {
            printf("E do sexo masculino e nao é aposentavel\n");
        }
    } else if (sexo == 'F' || sexo == 'f') {
        if (idade >= 63 && contribuicao >= 10) {
            printf("Aposentavel!\n");
            printf("Sexo feminino, possui pelo menos 63 anos, e pelo menos 10 anos de contribuicao.\n");
        } else if (idade >= 61 && contribuicao >= 15) {
            printf("Aposentavel!\n");
            printf("Sexo feminino, possui pelo menos 61 anos, e pelo menos 15 anos de contribuicao.\n");
        } else {
            printf("E do sexo feminino e nao é aposentavel\n");
        }
    } else {
        printf("Sexo nao reconhecido.");
    }
    return 0;
}

void exercicio12(void) {

    /*
    Escreva um programa que leia um inteiro positivo n e imprima todos os números pares
    */
    printf("Exercicio 12 \n");

    int numero;
    printf("Digite um numero \n");
    scanf("%d", &numero);
    printf("-----------------\n");
    printf("pares entre 1 e %d\n", numero);
    for (int i = 1; i <= numero; i++) {
        if (i % 2 == 0) {
            printf("Par: %d \n", i);
        }
    }
    printf("-----------------\n");
}

int exercicio13(void) {
    printf("Exercicio 13 \n");

    printf(" Exercicio que coloca um inteiro positivo n, e imprima as potencias : 2^0, 2^1, 2^2, ...., 2 ^ n \n\n ");

    long numb,
            aux = 1;
    printf("Digite um numero natural: \n");
    scanf("%li", &numb);

    for (int i = 0; i <= numb; i++) {
        printf("2^%d = %li\n", i, aux);
        aux = aux * 2;
    }
    return 0;
}

void exercicio14(void) {
    printf("Exercicio 14 \n");

    printf(" Faca um programa que leia dois numeros inteiros positivos a e b Utilizando lacos, calculo o valor inteiro de 'a' elvado 'b'\n\n ");

    int a, b, resultado = 1;

    printf("Digite a base\n");
    scanf("%d", &a);
    printf("Digite a expoente\n");
    scanf("%d", &b);
    printf("%d^0 = 1\n", a);
    for (int i = 1; i <= b; i++) {
        resultado *= a;
        printf("%d^%d = %d\n", a, i, resultado);
    }
}

int exercicio15(void) {
    printf("Exercicio 15 \n");

    printf("Faça um algoritmo que descobra se um numero é primo ou não \n");
    int numb, cont = 0;
    printf("Digite um numero: ");

    scanf("%d", &numb);

    printf("Os divisores de %d são: \n", numb);
    printf("------------------------\n");
    for (int i = numb; i >= 1; i--) {
        if (numb % i == 0) {
            cont++;
            printf("%d \n", i);
        }
    }
    printf("------------------------\n");

    if (cont > 2) {
        printf("O numero %d nao é primo \n", numb);
    } else {
        printf("O numero %d é primo \n", numb);
    }

    return 0;
}

int displayMenuAndGetChoice() {
    printf("Exercício 01:\n");
    printf("Exercício 02:\n");
    printf("Exercício 03:\n");
    printf("Exercício 04:\n");
    printf("Exercício 05:\n");
    printf("Exercício 06:\n");
    printf("Exercício 07:\n");
    printf("Exercício 08:\n");
    printf("Exercício 09:\n");
    printf("Exercício 10:\n");
    printf("Exercício 11:\n");
    printf("Exercício 12:\n");
    printf("Exercício 13:\n");
    printf("Exercício 14:\n");
    printf("Exercício 15:\n");
    printf("Digite o número do exercício que deseja executar: ");

    int escolha;
    scanf("%d", &escolha);
    return escolha;
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
        default:
            printf("Opção inválida!\n");
            break;
    }
}

bool getExitChoice() {
    int sair;
    do {
        printf("Deseja sair? Digite (1) para Sim ou (0) para Não: ");
        scanf("%d", &sair);
    } while (sair != 0 && sair != 1);
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
            printf("Opção inválida!\n");
        }
        sair = getExitChoice();
    } while (!sair);
    printf("Obrigado por utilizar o programa!\n");
    return 0;
}