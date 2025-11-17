#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct de aventureiro
typedef struct {
    int id;
    char nome[50];
} Aventureiro;

// Nó da lista
typedef struct no {
    Aventureiro dado;
    struct no* prox;
} No;

// Lista com ponteiro para o primeiro elemento
typedef struct {
    No* inicio;
} Lista;

// Inicializa a lista como vazia
void inicializa_lista(Lista* L) {
    L->inicio = NULL;
}

// Insere aventureiro no início (novo líder temporário)
void adiciona_inicio(Lista* L, Aventureiro av) {
    No* novo = (No*) malloc(sizeof(No));
    if (!novo) {
        printf("Erro ao alocar memória.\n");
        return;
    }
    novo->dado = av;
    novo->prox = L->inicio;
    L->inicio = novo;
}

// Mostra todos os aventureiros do grupo
void mostrar_grupo(const Lista* L) {
    if (L->inicio == NULL) {
        printf("\nO grupo está vazio.\n");
        return;
    }

    printf("\n--- GRUPO ATUAL ---\n");
    No* ponteiro = L->inicio;

    while (ponteiro != NULL) {
        printf("ID: %d | Nome: %s\n", ponteiro->dado.id, ponteiro->dado.nome);
        ponteiro = ponteiro->prox;
    }
}

int main() {
    Lista grupo;
    inicializa_lista(&grupo);

    int opcao;

    do {
        printf("\n===== MENU =====\n");
        printf("1 - Adicionar Aventureiro\n");
        printf("2 - Mostrar Grupo\n");
        printf("3 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            Aventureiro av;

            printf("ID do aventureiro: ");
            scanf("%d", &av.id);

            printf("Nome do aventureiro: ");
            scanf(" %[^\n]", av.nome);

            adiciona_inicio(&grupo, av);
            printf("Aventureiro adicionado ao início do grupo!\n");
        }
        else if (opcao == 2) {
            mostrar_grupo(&grupo);
        }

    } while (opcao != 3);

    printf("Programa encerrado.\n");
    return 0;
}
