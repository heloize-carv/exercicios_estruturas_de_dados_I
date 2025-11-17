#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "heroi.h"

// Definição completa da struct (implementação oculta no .h)
struct Heroi {
    char nome[50];
    int hp;
    int ataque;
};

Heroi* alocar_herois(int qtd) {
    Heroi* vet = (Heroi*) malloc(qtd * sizeof(Heroi));
    if (vet == NULL) {
        printf("Erro ao alocar memória!\n");
        exit(1);
    }
    return vet;
}

void ler_herois(Heroi* vetor, int qtd) {
    for (int i = 0; i < qtd; i++) {
        printf("\n--- Herói %d ---\n", i + 1);

        printf("Nome: ");
        scanf(" %[^\n]", vetor[i].nome);

        printf("HP: ");
        scanf("%d", &vetor[i].hp);

        printf("Ataque: ");
        scanf("%d", &vetor[i].ataque);
    }
}

void imprimir_herois(Heroi* vetor, int qtd) {
    printf("\n===== ROSTER DE HERÓIS =====\n");
    for (int i = 0; i < qtd; i++) {
        printf("\nHerói %d:\n", i + 1);
        printf("Nome: %s\n", vetor[i].nome);
        printf("HP: %d\n", vetor[i].hp);
        printf("Ataque: %d\n", vetor[i].ataque);
    }
}
