#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// O Estado do Personagem em um Jogo de Plataforma

struct Jogador {
    float pos_x;          // Posição horizontal
    int pontuacao;        // Pontuação do jogador
    int tem_pulo_duplo;   // 0 = não, 1 = sim
};

int main() {
    setlocale(LC_ALL, "Portuguese_Brazil");

    // Criação e inicialização do personagem
    struct Jogador heroi;
    heroi.pos_x = 50.0;
    heroi.pontuacao = 0;
    heroi.tem_pulo_duplo = 0;

    // Estado inicial
    printf("Inicio da fase! Posicao X: %.1f, Pontos: %d, Pulo Duplo: %s\n",
           heroi.pos_x, heroi.pontuacao,
           heroi.tem_pulo_duplo ? "Sim" : "Nao");

    // Simulação das ações
    heroi.pontuacao += 10;       // Coleta de moeda
    heroi.tem_pulo_duplo = 1;    // Coleta de power-up

    // Estado final
    printf("Itens coletados! Posicao X: %.1f, Pontos: %d, Pulo Duplo: %s\n",
           heroi.pos_x, heroi.pontuacao,
           heroi.tem_pulo_duplo ? "Sim" : "Nao");

    return 0;
}
