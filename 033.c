#include <stdio.h>
#include <locale.h>

// Movimentando o Personagem no Mapa

// Definição da estrutura
struct Posicao {
    int x;
    int y;
};

// Função que move o personagem (recebe um ponteiro)
void mover_personagem(struct Posicao *p, int movimento_x, int movimento_y) {
    p->x += movimento_x;  // Atualiza o eixo X
    p->y += movimento_y;  // Atualiza o eixo Y
}

int main() {
    setlocale(LC_ALL, "Portuguese_Brazil");

    // Criação e inicialização da posição do jogador
    struct Posicao posicao_jogador = {0, 0};

    // Criação do ponteiro que aponta para a estrutura
    struct Posicao *ponteiro_posicao = &posicao_jogador;

    // Exibir posição inicial
    printf("Posicao inicial do jogador: X=%d, Y=%d\n", posicao_jogador.x, posicao_jogador.y);

    // Movimentar o personagem (10 no eixo X e 5 no eixo Y)
    mover_personagem(ponteiro_posicao, 10, 5);

    // Exibir posição final
    printf("Posicao final do jogador: X=%d, Y=%d\n", posicao_jogador.x, posicao_jogador.y);

    return 0;
}
