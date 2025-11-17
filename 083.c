#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct de jogador
typedef struct {
    int matricula;
    char nome[50];
} Jogador;

// Nó da lista encadeada
typedef struct no {
    Jogador dado;
    struct no* prox;
} No;

// Lista com ponteiro para o início
typedef struct {
    No* inicio;
} Lista;

// Inicializa lista vazia
void inicializa_lista(Lista* L) {
    L->inicio = NULL;
}

// Inserção no início (prioridade)
void inserir_inicio(Lista* L, Jogador j) {
    No* novo = (No*) malloc(sizeof(No));
    if (!novo) {
        printf("Erro ao alocar memória.\n");
        return;
    }
    novo->dado = j;
    novo->prox = L->inicio;
    L->inicio = novo;
}

// Inserção NO FIM (principal da atividade)
void inserir_fim(Lista* L, Jogador j) {
    No* novo = (No*) malloc(sizeof(No));
    if (!novo) {
        printf("Erro ao alocar memória.\n");
        return;
    }
    novo->dado = j;
    novo->prox = NULL;   // último elemento SEMPRE aponta para NULL

    // Se a fila está vazia
    if (L->inicio == NULL) {
        L->inicio = novo;
        return;
    }

    // Senão, percorre até o último nó
    No* aux = L->inicio;
    while (aux->prox != NULL) {
        aux = aux->prox;
    }

    aux->prox = novo;
}

// Exibe toda a fila
void mostrar_fila(const Lista* L) {
    if (L->inicio == NULL) {
        printf("\nA fila está vazia.\n");
        return;
    }

    printf("\n--- FILA DE JOGADORES ---\n");
    No* p = L->inicio;

    while (p != NULL) {
        printf("Matrícula: %d | Nome: %s\n", p->dado.matricula, p->dado.nome);
        p = p->prox;
    }
}

int main() {
    Lista fila;
    inicializa_lista(&fila);

    int opcao;

    do {
        printf("\n===== MENU =====\n");
        printf("1 - Adicionar jogador no início (prioridade)\n");
        printf("2 - Adicionar jogador no fim (fila normal)\n");
        printf("3 - Mostrar fila\n");
        printf("4 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        if (opcao == 1 || opcao == 2) {
            Jogador j;

            printf("Matrícula: ");
            scanf("%d", &j.matricula);

            printf("Nome: ");
            scanf(" %[^\n]", j.nome);

            if (opcao == 1)
                inserir_inicio(&fila, j);
            else
                inserir_fim(&fila, j);

            printf("Jogador inserido com sucesso!\n");
        }
        else if (opcao == 3) {
            mostrar_fila(&fila);
        }

    } while (opcao != 4);

    printf("Encerrando...\n");

    return 0;
}