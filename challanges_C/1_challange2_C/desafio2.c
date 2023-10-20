/**
Dada uma sequência de valores do PIB correspondentes a um determinado intervalo de anos,
o objetivo deste laboratório é determinar o triênio que teve o maior crescimento médio do PIB.

Entrada
A entrada consiste de um número inteiro positivo n, que indica o número de anos considerado,
seguido por n números reais, representando o PIB de cada ano da amostragem.
Cada número da entrada estará em uma linha distinta

Saída
A saída deverá conter apenas uma linha, contendo a seguinte frase
a maior media de crescimento foi entre os anos X e Y: Z,
onde X e Y representam o primeiro e o último ano do triênio
(onde o primeiro ano é o ano 0) com a maior média de crescimento,
e Z deve ser o crescimento médio percentual deste triênio com uma casa decimal.
Em caso de empate, i.e, mais de um triênio com a mesma média de crescimento,
você deverá escolher o triênio mais antigo.

Toda linha que vem depois de "// Debug" deve pode ser comentada.

*/

#include <stdio.h>

int main()
{
    int n, i, imax, imaxsup;
    float n1, n2, n3, tx1, tx2, tx3, media, maior;

    scanf("%d", &n);

    // Valores para todos os casos.
    tx1 = 0;
    imax = 0;

    // n é positivo n > 0

    // Edge cases?? n = 1 e n = 2
    if (n == 1)
    {
        // Se n = 1 a tx1 = 0 = media = maior

        scanf("%f", &n1); // so para tirar o prompt

        maior = 0;
        imaxsup = 0;
    }
    else if (n == 2)
    {
        // Se n = 1 a tx2 /= 0
        // maior = media = tx1 + tx2/2 mas tx1 = 0

        scanf("%f", &n1);
        scanf("%f", &n2);

        tx2 = (n2 / n1 - 1) * 100;

        maior = tx2 / 2;
        imaxsup = 1;
    }
    else
    {
        // Primeiro ciclo
        scanf("%f", &n1);
        scanf("%f", &n2);
        scanf("%f", &n3);

        // Debug
        printf("%f %f %f\n", n1, n2, n3);

        tx1 = 0;
        tx2 = (n2 / n1 - 1) * 100;
        tx3 = (n3 / n2 - 1) * 100;

        media = (tx1 + tx2 + tx3) / 3;
        maior = media;
        imax = 0;
        imaxsup = 2;

        // Debug
        printf("%f %f %f %f %f %d %d\n", tx1, tx2, tx3, media, maior, imax, imaxsup);

        // Se n = 3 ele não entra no loop
        for (i = 3; i < n; i++)
        {
            // Agora outros numeros
            n1 = n2;
            n2 = n3;
            scanf("%f", &n3);

            // Debug
            printf("%f %f %f\n", n1, n2, n3);

            tx1 = tx2;
            tx2 = tx3;
            tx3 = (n3 / n2 - 1) * 100;

            media = (tx1 + tx2 + tx3) / 3;

            if (media > maior)
            {
                maior = media;
                imax = i - 2;
                imaxsup = i;
            }

            // Debug
            printf("%f %f %f %f %f %d %d\n", tx1, tx2, tx3, media, maior, imax, imaxsup);
        }
    }

    // Debug
    printf("\n\n");

    printf("a maior media de crescimento foi entre os anos %d e %d: %0.1f\n", imax, imaxsup, maior);
}
