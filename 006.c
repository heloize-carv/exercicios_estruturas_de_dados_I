#include <stdio.h>
#include <locale.h>

// A Jornada do Saltador

int main () {
    setlocale(LC_ALL, "Portuguese_Brazil");

    // Vetor de plataformas com os impulsos
    int plataformas[5] = {10, 20, 5, 15, 30};

    // Ponteiro para percorrer as plataformas
    int *ponteiro_plataforma = plataformas;  

    // Variável que acumula a altura total
    int altura_total = 0;

    // Percorre o vetor usando aritmética de ponteiros
    for (int i = 0; i < 5; i++) {
        altura_total += *(ponteiro_plataforma + i);
    }

    // Exibe o resultado final
    printf("Altura total do salto: %d metros!\n", altura_total);

    return 0;
}