#include <stdbool.h>
#include <stdio.h>
#include <locale.h>
#include "global.h"

#define MAX_EXERCISES 11

bool getExitChoice(void);

void executeExercise(int choice);

int displayMenuAndGetChoice(void);

int main(void) {
    setlocale(LC_ALL, "Portuguese");

    bool exitProgram = false;

    do {
        int choice = displayMenuAndGetChoice();

        if (choice >= 1 && choice <= MAX_EXERCISES) {
            executeExercise(choice);
        } else {
            printf("Invalid option!\n");
        }
        exitProgram = getExitChoice();
    } while (!exitProgram);
    printf("Thank you for using this program!\n");
    return 0;
}

int exercise01(void) {

    /*Soma dos elementos de um vetor*/

    /*
    * 1 - Dado um vetor v de inteiro de tamanho tam, devemos caluclar a soma dos seus elementso da posição 0 até tam - 1
    * 2 - Como podemos descrever este problema de forma recurstiva ? Isto é, como podemos descrever este problema em função de si mesmo?
    * 3 - Vamos denotar por S(n) a soma dos elementos das posições 0 até n do vetor, e portanto devemos achar S(tam - 1)
    * 4 - O Valor de S(n) é dado por S(n) = v[n] + S(n - 1), onde S(0) = v[0]

     Se n = 0 então a somaElementosVetorInt S(o) é igual a v[0]
     */

    int v[] = {1, 2, 3, 4, 5};
    int tam = 5;

    int somaVetor = somaElementosVetorInt(v, tam - 1);

    printf("Soma dos elementos do vetor: %d\n", somaVetor);
    return 0;
}

int exercise02(void) {
    int v[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    int tam = sizeof(v)/sizeof(v[0]);

    imprimeVetorIntEmOrderRecursivo(v, 0, tam);
    putchar('\n');

    return 0;
}

int exercise03(void) {



    return 0;
}

int exercise04(void) {
    return 0;
}

int exercise05(void) {
    return 0;
}

int exercise06(void) {
    return 0;
}

int exercise07(void) {
    return 0;
}

int exercise08(void) {
    return 0;
}

int exercise09(void) {
    return 0;
}

int exercise10(void) {
    return 0;
}

int exercise11(void) {
    return 0;
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
        default:
            printf("Invalid option!\n");
            break;
    }
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
    printf("Enter the number of the exercise you want to execute: ");

    int choice;
    scanf("%d", &choice);
    return choice;
}