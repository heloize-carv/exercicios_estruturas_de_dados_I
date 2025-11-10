#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Personagem e Seus Atributos

struct Atributos {
    int vida;
    int pontuacao;
};

struct Personagem {
    char nome[50];
    struct Atributos stats;
};

int main() {
    setlocale(LC_ALL, "Portuguese_Brazil");

    struct Personagem jogador;

    printf("Digite o nome do personagem: ");
    fgets(jogador.nome, sizeof(jogador.nome), stdin);

    // Inicialização dos atributos
    jogador.stats.vida = 100;
    jogador.stats.pontuacao = 0;

    printf("\nStatus Inicial -> Nome: %s | Vida: %d | Pontuação: %d\n",
           jogador.nome, jogador.stats.vida, jogador.stats.pontuacao);

    // Simulação: coletou moeda (+10 pontos)
    jogador.stats.pontuacao += 10;

    // Simulação: sofreu dano (-25 de vida)
    jogador.stats.vida -= 25;

    printf("Status Final -> Nome: %s | Vida: %d | Pontuação: %d\n",
           jogador.nome, jogador.stats.vida, jogador.stats.pontuacao);

    return 0;
}
