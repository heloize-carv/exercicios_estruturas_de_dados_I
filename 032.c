#include <stdio.h>
#include <locale.h>

// Movimentação do Personagem e Coleta de Moedas

// Definindo a estrutura
struct Personagem {
    int posX;
    int posY;
    int moedas;
};

// Função que recebe uma cópia da struct e retorna a struct modificada
struct Personagem atualizarPersonagem(struct Personagem p) {
    p.posX = 10;
    p.posY = 5;
    p.moedas++;
    return p;
}

int main() {
    setlocale(LC_ALL, "Portuguese_Brazil");
    
    struct Personagem jogador;

    // Inicializando os valores
    jogador.posX = 0;
    jogador.posY = 0;
    jogador.moedas = 0;

    printf("Posicao inicial: (%d, %d) - Moedas: %d\n", jogador.posX, jogador.posY, jogador.moedas);

    // Atualizando o personagem (retorno da função substitui a variável)
    jogador = atualizarPersonagem(jogador);

    printf("Posicao atualizada: (%d, %d) - Moedas: %d\n", jogador.posX, jogador.posY, jogador.moedas);

    return 0;
}
