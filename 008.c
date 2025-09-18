#include <stdio.h>
#include <locale.h>

// Coletando Moedas com Ponteiros

int main() {
    setlocale(LC_ALL, "Portuguese_Brazil");

    int fase[10] = {0, 1, 0, 0, 1, 1, 0, 1, 0, 0};
    int *ponteiro_jogador;
    int moedas_coletadas = 0;

    // Ponteiro aponta para o início do vetor
    ponteiro_jogador = fase;

    // Percorre os 10 blocos da fase
    for (int i = 0; i < 10; i++) {
        if (*(ponteiro_jogador + i) == 1) { // aritmética de ponteiros
            moedas_coletadas++;
        }
    }

    printf("O jogador coletou um total de %d moedas!\n", moedas_coletadas);

    return 0;
}
