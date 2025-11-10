#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// A Mochila Expansível do Aventureiro

int main() {
    setlocale(LC_ALL, "Portuguese_Brazil");

    int *mochila;
    int tamanho_inicial = 3;
    int i;

    // Alocar espaço inicial
    mochila = (int *)malloc(tamanho_inicial * sizeof(int));
    if (mochila == NULL) {
        printf("Erro ao alocar memória!\n");
        return 1;
    }

    // Primeira coleta
    printf("Digite os valores dos %d primeiros itens:\n", tamanho_inicial);
    for (i = 0; i < tamanho_inicial; i++) {
        printf("Item %d: ", i + 1);
        if (scanf("%d", &mochila[i]) != 1) {
            printf("Entrada inválida! Encerrando...\n");
            free(mochila);
            return 1;
        }
    }

    // Mostrar itens
    printf("\nItens atuais na mochila:\n");
    for (i = 0; i < tamanho_inicial; i++) {
        printf("Item %d: %d\n", i + 1, mochila[i]);
    }

    // Expandir mochila com segurança
    int novo_tamanho = tamanho_inicial * 2;
    int *temp = (int *)realloc(mochila, novo_tamanho * sizeof(int));
    if (temp == NULL) {
        printf("Erro ao expandir a mochila!\n");
        free(mochila);
        return 1;
    }
    mochila = temp;

    printf("\nO herói encontrou o item de expansão!\n");
    printf("A mochila agora pode carregar %d itens.\n", novo_tamanho);

    // Segunda coleta
    printf("\nDigite os valores dos novos %d itens:\n", novo_tamanho - tamanho_inicial);
    for (i = tamanho_inicial; i < novo_tamanho; i++) {
        printf("Item %d: ", i + 1);
        if (scanf("%d", &mochila[i]) != 1) {
            printf("Entrada inválida! Encerrando...\n");
            free(mochila);
            return 1;
        }
    }

    // Mostrar todos os itens
    printf("\nTodos os itens na mochila:\n");
    for (i = 0; i < novo_tamanho; i++) {
        printf("Item %d: %d\n", i + 1, mochila[i]);
    }

    free(mochila);
    printf("\nMemória liberada com sucesso!\n");

    return 0;
}
