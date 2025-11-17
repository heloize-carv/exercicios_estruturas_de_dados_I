#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char nome[50];
} Jogador;

typedef struct No {
    Jogador dado;
    struct No *prox;
} No;

typedef struct {
    No *inicio;
} Lista;

void inicializar(Lista *l) {
    l->inicio = NULL;
}

No* criar_no(int id, char nome[]) {
    No *novo = (No*) malloc(sizeof(No));
    novo->dado.id = id;
    strcpy(novo->dado.nome, nome);
    novo->prox = NULL;
    return novo;
}

void inserir_fim(Lista *l, int id, char nome[]) {
    No *novo = criar_no(id, nome);

    if (l->inicio == NULL) {
        l->inicio = novo;
    } else {
        No *aux = l->inicio;
        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = novo;
    }

    printf("Jogador adicionado à fila!\n");
}

void remover_inicio(Lista *l) {
    if (l->inicio == NULL) {
        printf("Nao ha jogadores na fila!\n");
        return;
    }

    No *temp = l->inicio;
    printf("Jogador %s (ID %d) entrou na partida!\n", temp->dado.nome, temp->dado.id);

    l->inicio = l->inicio->prox;
    free(temp);
}

void mostrar(Lista *l) {
    if (l->inicio == NULL) {
        printf("Fila vazia!\n");
        return;
    }

    printf("\n--- Fila de Matchmaking ---\n");
    No *aux = l->inicio;
    while (aux != NULL) {
        printf("ID: %d | Nome: %s\n", aux->dado.id, aux->dado.nome);
        aux = aux->prox;
    }
}

int main() {
    Lista fila;
    inicializar(&fila);

    int opcao;
    do {
        printf("\n===== MATCHMAKING =====\n");
        printf("1 - Adicionar jogador ao fim da fila\n");
        printf("2 - Iniciar partida (remover primeiro jogador)\n");
        printf("3 - Mostrar fila\n");
        printf("4 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            int id;
            char nome[50];

            printf("ID do jogador: ");
            scanf("%d", &id);

            printf("Nome do jogador: ");
            getchar(); 
            fgets(nome, 50, stdin);
            nome[strcspn(nome, "\n")] = '\0'; 

            inserir_fim(&fila, id, nome);
        }

        else if (opcao == 2) {
            remover_inicio(&fila);
        }

        else if (opcao == 3) {
            mostrar(&fila);
        }

    } while (opcao != 4);

    printf("Encerrando sistema...\n");
    return 0;
}
