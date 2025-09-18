#include <stdio.h>
#include <locale.h>

// O Portal de Teletransporte e as Coordenadas do Jogador

// Função que aplica o power-up de pontuação dupla
void aplicar_powerup_pontuacao_dupla(int *pontuacao) {
    *pontuacao = *pontuacao * 2; // altera o valor diretamente na memória
}

int main() {
    setlocale(LC_ALL, "Portuguese_Brazil");

    // 1. Cria a variável da pontuação e inicializa com 1500
    int pontuacao_jogador = 1500;

    // 2. Imprime a pontuação antes do power-up
    printf("Pontuação antes do power-up: %d\n", pontuacao_jogador);

    // 3. Chama a função passando o endereço da variável
    aplicar_powerup_pontuacao_dupla(&pontuacao_jogador);

    // 4. Imprime a pontuação após o power-up
    printf("Pontuação após o power-up: %d\n", pontuacao_jogador);

    return 0;
}