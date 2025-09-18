#include <stdio.h>
#include <locale.h>

// Gerenciando o Inventário de Munição

int main() {
    setlocale(LC_ALL, "Portuguese_Brazil");

    // Vetores de munição: [quantidade atual, capacidade máxima]
    int balas[2] = {30, 30};
    int granadas[2] = {5, 5};
    int foguetes[2] = {2, 2};

    // Vetor de ponteiros para inteiros
    int *inventario[3] = {balas, granadas, foguetes};

    // Imprime o inventário inicial
    printf("Inventário Inicial:\n");
    printf("Balas: %d\n", *inventario[0]);
    printf("Granadas: %d\n", *inventario[1]);
    printf("Foguetes: %d\n", *inventario[2]);

    // Simula o uso de 1 unidade de cada munição
    for (int i = 0; i < 3; i++) {
        (*inventario[i])--;  // decréscimo usando ponteiros
    }

    // Imprime o inventário após o uso
    printf("\nInventário Após o Uso:\n");
    printf("Balas: %d\n", *inventario[0]);
    printf("Granadas: %d\n", *inventario[1]);
    printf("Foguetes: %d\n", *inventario[2]);

    return 0;
}