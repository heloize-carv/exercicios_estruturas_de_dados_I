#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// Coletando Moedas no Nível

// Definição da estrutura Moeda
struct Moeda {
    int posicao_x;
    int posicao_y;
    int valor;
};

int main() {
    setlocale(LC_ALL, "Portuguese");

    int quantidade;
    int total_pontos = 0;
    struct Moeda *moedas; // Ponteiro para struct Moeda

    printf("===== COLETANDO MOEDAS NO NÍVEL =====\n\n");
    printf("Quantas moedas existem neste nível? ");
    scanf("%d", &quantidade);

    // Alocação dinâmica de memória para o vetor de estruturas
    moedas = (struct Moeda *) malloc(quantidade * sizeof(struct Moeda));

    if (moedas == NULL) {
        printf("Erro: memória insuficiente!\n");
        return 1;
    }

    // Cadastro das moedas
    for (int i = 0; i < quantidade; i++) {
        printf("\nMoeda %d:\n", i + 1);
        printf("Posição X: ");
        scanf("%d", &moedas[i].posicao_x);
        printf("Posição Y: ");
        scanf("%d", &moedas[i].posicao_y);
        printf("Valor da moeda: ");
        scanf("%d", &moedas[i].valor);
    }

    // Cálculo da pontuação total
    for (int i = 0; i < quantidade; i++) {
        total_pontos += moedas[i].valor;
    }

    // Exibição do total de pontos
    printf("\n====================================\n");
    printf("Pontuação máxima do nível: %d\n", total_pontos);
    printf("====================================\n");

    // Libera a memória alocada
    free(moedas);

    return 0;
}
