#include <stdio.h>
#include <locale.h>

// Power-up de Pontuação Dupla

// Função que dobra a pontuação via ponteiro
void aplicar_powerup_pontuacao_dupla(int *P) {
    *P = *P * 2; // altera o valor original diretamente na memória
    printf("Valor da pontuação dentro da função: %d\n", *P);
}

int main() {
    setlocale(LC_ALL, "Portuguese_Brazil");

    // Variável que armazena a pontuação do jogador
    int pontuacao_jogador = 1500;

    // Exibe a pontuação antes do power-up
    printf("Pontuação antes do power-up: %d\n", pontuacao_jogador);

    // Passa o endereço da variável para a função
    aplicar_powerup_pontuacao_dupla(&pontuacao_jogador);

    // Exibe a pontuação após o power-up
    printf("Pontuação após o power-up: %d\n", pontuacao_jogador);

    return 0;
}