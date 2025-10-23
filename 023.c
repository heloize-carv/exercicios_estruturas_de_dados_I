#include <stdio.h>
#include <stdlib.h>

// Construindo o Chão de uma Fase

#define LINHAS 5
#define COLUNAS 10

int main() {
    int *level_map; // ponteiro para armazenar toda a matriz

    // Alocando memória para toda a matriz (LINHAS x COLUNAS)
    level_map = (int *) malloc(LINHAS * COLUNAS * sizeof(int));

    // Verificando se a alocação foi bem-sucedida
    if (level_map == NULL) {
        printf("Erro ao alocar memoria para o level_map.\n");
        return 1; // encerra o programa com erro
    }

    // Construção do nível: 0 para ar, 1 para chão na última linha
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            if (i == LINHAS - 1) {
                *(level_map + i * COLUNAS + j) = 1; // chão
            } else {
                *(level_map + i * COLUNAS + j) = 0; // ar
            }
        }
    }

    // Exibindo o nível na tela
    printf("Mapa do nivel:\n");
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            printf("%d ", *(level_map + i * COLUNAS + j));
        }
        printf("\n");
    }

    // Liberando a memória alocada
    free(level_map);
    level_map = NULL; // evita ponteiro pendurado

    return 0;
}
