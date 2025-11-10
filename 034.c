#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct Heroi {
    int saude;
    int pontuacao;
    int posX;
    int posY;
};

int main() {
    setlocale(LC_ALL, "Portuguese_Brazil");

    // Criação e inicialização do herói
    struct Heroi meuHeroi = {100, 0, 0, 0};

    // Exibição do estado inicial
    printf("Estado inicial do herói:\n");
    printf("Saúde: %d\n", meuHeroi.saude);
    printf("Pontuação: %d\n", meuHeroi.pontuacao);
    printf("Posição: X=%d, Y=%d\n\n", meuHeroi.posX, meuHeroi.posY);

    // Criação do ponteiro
    struct Heroi *ptrHeroi;
    ptrHeroi = &meuHeroi;

    // --- Simulação de ações no jogo ---
    // Sofrer dano
    ptrHeroi->saude -= 25;
    printf("O herói sofreu dano! Nova saúde: %d\n", ptrHeroi->saude);

    // Coletar moedas
    ptrHeroi->pontuacao += 50;
    printf("O herói coletou moedas! Nova pontuação: %d\n", ptrHeroi->pontuacao);

    // Mover o herói
    ptrHeroi->posX += 10;
    ptrHeroi->posY -= 5;
    printf("O herói se moveu! Nova posição: X=%d, Y=%d\n\n", ptrHeroi->posX, ptrHeroi->posY);

    // Exibição final do estado do herói (usando apenas o ponteiro)
    printf("=== Estado Final do Herói ===\n");
    printf("Saúde: %d\n", ptrHeroi->saude);
    printf("Pontuação: %d\n", ptrHeroi->pontuacao);
    printf("Posição: X=%d, Y=%d\n", ptrHeroi->posX, ptrHeroi->posY);

    return 0;
}
