#include <stdio.h>

int inicio(void)
{
    printf("************************************\n");
    printf("ALUNO:  VINICIUS DOS SANTOS ANDRADE\n");
    printf("RA:     2760482311026\n");
    printf("CURSO:  ADS 1 SEMESTRE 2023\n");
    printf("************************************\n");
    printf("\n");
    printf("Desafio 01 - Beta\n");
    printf("\n");
    printf("Descricao do problema e estrategia de resolucao:\n");
    printf("\n");
    printf("O programa consciente no calculo do comprimento da circunferencia de um determinado planeta baseado em duas variaveis:\n");
    printf("D - distancia entre duas localidades | A - angulo entre duas localidades. Dados que serao informados pelo usuario.\n");
    printf("Manipulando a formula matematica do comprimento da circunferencia --> C = 2*pi*R.\n");
    printf("Considerando que, 360 graus correspondem ao angulo maximo e o angulo digitado sera uma fracao desse total:\n");
    printf("Podemos reduzir a formula: Ce = (360*D)/A.\n");
    printf("Ce sera a distancia em Estadios.\n");
    printf("Para converter Estadios para KM basta multiplicarmos pela contante de conversao c = 0.1764.\n");
    printf("Ckm = Ce X 0.1764 sera a distancia em Estadios.\n");
    printf("\n");
}

int main()
{
    inicio();
    int sair = 1;
    while (sair != 0)
    {
        double D;          // distancia entre duas localidades
        double A;          // angulo entre duas localidades
        double c = 0.1764; // Constante de conversao Estadio --> Km

        printf("Distancia entre C1 e C2\n");
        scanf("%lf", &D);
        printf("Angulo entre C1 e C2\n");
        scanf("%lf", &A);

        double Ce = (360 * D) / A;
        double Ckm = (Ce)*c;

        printf("\n");
        printf("Circunferencia do planeta em Estadios:    %.1lf\n", Ce);
        printf("Circunferencia do planeta em       Km:    %.1lf\n", Ckm);
        printf("\n");

        printf("Deseja calcular novamente a circunferencia da Terra?\n");
        printf("(Y) - 1 | (N) - 0  \n");
        scanf("%d", &sair);
        printf("\n");
    }
    printf("Tchau =)");
    return 0;
}
