#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "personagem.h"

// Definição COMPLETA da struct (oculta do main)
struct personagem {
    char nome[50];
    char classe[30];
    int nivel;
    int hp;
};

// Aloca vetor de Personagem
Personagem* cria_party(int num_membros) {
    Personagem* vet = (Personagem*) malloc(num_membros * sizeof(Personagem));
    if (!vet) {
        printf("Erro: não foi possível alocar memória.\n");
        exit(1);
    }
    return vet;
}

void registra_membros(Personagem* party, int num_membros) {
    for (int i = 0; i < num_membros; i++) {
        printf("\n--- Membro %d ---\n", i + 1);

        printf("Nome: ");
        scanf(" %[^\n]", party[i].nome);

        printf("Classe: ");
        scanf(" %[^\n]", party[i].classe);

        printf("Nível: ");
        scanf("%d", &party[i].nivel);

        printf("HP: ");
        scanf("%d", &party[i].hp);
    }
}

void exibe_relatorio(const Personagem* party, int num_membros) {
    printf("\n===== RELATÓRIO DA PARTY =====\n");
    for (int i = 0; i < num_membros; i++) {
        printf("\nPersonagem %d:\n", i + 1);
        printf("Nome:   %s\n", party[i].nome);
        printf("Classe: %s\n", party[i].classe);
        printf("Nível:  %d\n", party[i].nivel);
        printf("HP:     %d\n", party[i].hp);
    }
}

void libera_party(Personagem* party) {
    free(party);
}
