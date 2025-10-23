#include <stdio.h>
#include <stdlib.h>

// Construindo o Mapa do Jogo Dinamicamente

int main() {
    int linhas, colunas;
    int **mapa;
    int contador_tijolos = 0;

    // Pedindo ao usuário as dimensões do mapa
    printf("Digite o número de linhas do mapa: ");
    scanf("%d", &linhas);
    printf("Digite o número de colunas do mapa: ");
    scanf("%d", &colunas);

    // Alocando o vetor de ponteiros (para as linhas)
    mapa = (int **) malloc(linhas * sizeof(int *));
    if (mapa == NULL) {
        printf("Erro ao alocar memória para o mapa.\n");
        return 1;
    }

    // Alocando cada linha individualmente
    for (int i = 0; i < linhas; i++) {
        mapa[i] = (int *) malloc(colunas * sizeof(int));
        if (mapa[i] == NULL) {
            printf("Erro ao alocar memória para a linha %d.\n", i);
            // Liberando linhas já alocadas antes de sair
            for (int j = 0; j < i; j++) {
                free(mapa[j]);
            }
            free(mapa);
            return 1;
        }
    }

    // Preenchendo o mapa com valores fornecidos pelo usuário
    printf("Digite os valores do mapa (0: Espaço, 1: Tijolo, 2: Moeda):\n");
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("Mapa[%d][%d]: ", i, j);
            scanf("%d", &mapa[i][j]);

            // Contando blocos de tijolo
            if (mapa[i][j] == 1) {
                contador_tijolos++;
            }
        }
    }

    // Exibindo a contagem de blocos de tijolo
    printf("O mapa possui %d blocos de tijolo.\n", contador_tijolos);

    // Liberando a memória
    for (int i = 0; i < linhas; i++) {
        free(mapa[i]); // libera cada linha
    }
    free(mapa); // libera o vetor de ponteiros

    return 0;
}
