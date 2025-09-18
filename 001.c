#include <stdio.h>
#include <locale.h>

// O Power-up e vida do jogador

int main() {
    setlocale(LC_ALL, "Portuguese_Brazil");

    // Variável que armazena a vida do jogador
    int vida_jogador = 100;

    // Ponteiro que aponta para a vida do jogador
    int *ponteiro_vida = &vida_jogador;

    // Mostra vida inicial
    printf("Vida inicial do jogador: %d\n", vida_jogador);

    // Simula dano sofrido pelo jogador
    *ponteiro_vida = 50;  // altera a vida via ponteiro
    printf("O jogador sofreu dano! Vida atual: %d\n", vida_jogador);

    // Simula coleta de power-up que restaura a vida
    *ponteiro_vida = 100;  // restaura a vida via ponteiro
    printf("Power-up coletado! Vida restaurada: %d\n", vida_jogador);

    return 0;
}