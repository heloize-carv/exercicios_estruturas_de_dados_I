#include <stdio.h>
#include <locale.h>

// Coletando Moedas com Ponteiros

int main() {
    setlocale(LC_ALL, "Portuguese_Brazil");

    int pontuacao = 0;                    // Pontuação do jogador
    int *ponteiro_pontuacao = &pontuacao; // Ponteiro para a pontuação

    int moedas[3] = {10, 10, 10}; // Vetor representando o valor de cada moeda

    // Imprime a pontuação inicial
    printf("Pontuação inicial: %d\n", pontuacao);

    // Coleta das moedas usando o vetor e ponteiro
    for (int i = 0; i < 3; i++) {
        *ponteiro_pontuacao += moedas[i]; // adiciona os pontos via ponteiro
    }

    // Imprime a pontuação final
    printf("Pontuação final após coletar 3 moedas: %d\n", pontuacao);

    return 0;
}