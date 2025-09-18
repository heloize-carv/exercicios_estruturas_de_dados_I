#include <stdio.h>
#include <locale.h>

// Coletando Moedas em Salas Secretas

int main() {
    setlocale(LC_ALL, "Portuguese_Brazil");

    // Arrays de moedas em cada sala
    int sala_1[] = {10, 20, 5};
    int sala_2[] = {50, 100};
    int sala_3[] = {5, 5, 5, 10};

    // Vetor de ponteiros (gerenciador de salas)
    int *ponteiro_salas[3];
    ponteiro_salas[0] = sala_1;
    ponteiro_salas[1] = sala_2;
    ponteiro_salas[2] = sala_3;

    // Tamanhos de cada sala
    int tamanho_sala_1 = sizeof(sala_1) / sizeof(sala_1[0]);
    int tamanho_sala_2 = sizeof(sala_2) / sizeof(sala_2[0]);
    int tamanho_sala_3 = sizeof(sala_3) / sizeof(sala_3[0]);

    // Imprimindo moedas de cada sala
    printf("Moedas na Sala 1: ");
    for (int i = 0; i < tamanho_sala_1; i++) {
        printf("%d ", ponteiro_salas[0][i]);
    }
    printf("\n");

    printf("Moedas na Sala 2: ");
    for (int i = 0; i < tamanho_sala_2; i++) {
        printf("%d ", ponteiro_salas[1][i]);
    }
    printf("\n");

    printf("Moedas na Sala 3: ");
    for (int i = 0; i < tamanho_sala_3; i++) {
        printf("%d ", ponteiro_salas[2][i]);
    }
    printf("\n");

    return 0;
}