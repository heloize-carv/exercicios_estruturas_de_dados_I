#include <stdio.h>
#include <string.h>
#include <locale.h>

// O Inventário de Itens

struct ItemColetavel {
    char nome[50];
    int valor_pontos;
};

int main() {
    setlocale(LC_ALL, "Portuguese_Brazil");

    struct ItemColetavel inventario[3];
    struct ItemColetavel mais_valioso;
    int i;

    // Entrada de dados
    for (i = 0; i < 3; i++) {
        printf("Digite o nome do item %d: ", i + 1);
        scanf(" %[^\n]", inventario[i].nome); // Lê string com espaços

        printf("Digite o valor em pontos do item %d: ", i + 1);
        scanf("%d", &inventario[i].valor_pontos);
    }

    // Inicializa o mais valioso com o primeiro item
    mais_valioso = inventario[0];

    // Verifica o item mais valioso
    for (i = 1; i < 3; i++) {
        if (inventario[i].valor_pontos > mais_valioso.valor_pontos) {
            mais_valioso = inventario[i];
        }
    }

    // Saída final
    printf("\nO item mais valioso coletado foi: %s\n", mais_valioso.nome);

    return 0;
}
