#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

// Invocando um Inimigo: Alocação Dinâmica de Vida

int main () {
    setlocale(LC_ALL, "Portuguese_Brazil");
    
    int *vida_inimigo;

    // Aloca memória para armazenar a vida do inimigo
    vida_inimigo = (int *) malloc(sizeof(int));

    // Verifica se a alocação deu certo
    if (vida_inimigo == NULL) {
        printf("ERRO! ALOCAÇÃO DE MEMÓRIA FALHOU\n");
        return 1; // encerra o programa
    }

    // Define a vida inicial
    *vida_inimigo = 80;
    printf("Um novo inimigo apareceu com %d de vida!\n", *vida_inimigo);

    // Simula o ataque do jogador
    *vida_inimigo = *vida_inimigo - 35;
    printf("O jogador atacou! Vida restante do inimigo: %d\n", *vida_inimigo);

    // Libera a memória
    free(vida_inimigo);

    return 0; 
}