#include <stdio.h>
#include <locale.h>

// Gerenciando o Invent�rio de Muni��o

int main() {
    setlocale(LC_ALL, "Portuguese_Brazil");

    // Vetores de muni��o: [quantidade atual, capacidade m�xima]
    int balas[2] = {30, 30};
    int granadas[2] = {5, 5};
    int foguetes[2] = {2, 2};

    // Vetor de ponteiros para inteiros
    int *inventario[3] = {balas, granadas, foguetes};

    // Imprime o invent�rio inicial
    printf("Invent�rio Inicial:\n");
    printf("Balas: %d\n", *inventario[0]);
    printf("Granadas: %d\n", *inventario[1]);
    printf("Foguetes: %d\n", *inventario[2]);

    // Simula o uso de 1 unidade de cada muni��o
    for (int i = 0; i < 3; i++) {
        (*inventario[i])--;  // decr�scimo usando ponteiros
    }

    // Imprime o invent�rio ap�s o uso
    printf("\nInvent�rio Ap�s o Uso:\n");
    printf("Balas: %d\n", *inventario[0]);
    printf("Granadas: %d\n", *inventario[1]);
    printf("Foguetes: %d\n", *inventario[2]);

    return 0;
}