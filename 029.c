#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Itens Colecionáveis em um Jogo de Plataforma

int main() {
    setlocale(LC_ALL, "Portuguese_Brazil");

    // Definição da estrutura
    struct ItemColetavel {
        int valor_pontos;
        float peso;
    };

    // Criação e inicialização direta dos itens
    struct ItemColetavel moeda_bronze = {10, 0.5};
    struct ItemColetavel moeda_prata = {50, 0.7};
    struct ItemColetavel moeda_ouro = {100, 1.0};

    // Pontuação do jogador
    int pontuacao_jogador = 0;

    // Simular coleta da moeda de ouro
    pontuacao_jogador += moeda_ouro.valor_pontos;

    // Exibir resultado
    printf("Moeda de ouro coletada! Pontuação atual: %d\n", pontuacao_jogador);

    return 0;
}
