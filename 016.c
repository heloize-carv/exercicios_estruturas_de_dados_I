#include <stdio.h>
#include <locale.h>
#include <string.h>

// Inventário do Herói e a Porta Trancada

int main () {
    setlocale(LC_ALL, "Portuguese_Brazil");

    char inventario[5][20];   // 5 itens, cada um até 19 caracteres + '\0'
    char item_necessario[20]; // item que abre a porta
    int encontrado = 0;       // flag para verificar se o item foi achado

    // Preencher inventário
    for (int i = 0; i < 5; i++) {
        printf("Digite o item %d que está no inventário: ", i + 1);
        scanf("%19s", inventario[i]);
    }

    // Ler o item necessário
    printf("Digite o nome do item necessário para abrir a porta: ");
    scanf("%19s", item_necessario);

    // Verificar se o item está no inventário
    for (int i = 0; i < 5; i++) {
        if (strcmp(inventario[i], item_necessario) == 0) {
            encontrado = 1; // achou o item
            break;
        }
    }

    // Exibir resultado
    if (encontrado) {
        printf("Porta aberta!\n");
    } else {
        printf("Você não tem o item necessário.\n");
    }

    return 0;
}
