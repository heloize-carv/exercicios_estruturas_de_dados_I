#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char nome[50];
} Movimento;

// Nó da lista
typedef struct no {
    Movimento mov;
    struct no* prox;
} No;

// Cabeça da lista
typedef struct {
    No* inicio;
} Lista;

// Inicializa lista vazia
void inicializa_lista(Lista* L) {
    L->inicio = NULL;
}

// Insere no início da lista
void insere_inicio(Lista* L, Movimento m) {
    No* novo = (No*) malloc(sizeof(No));
    if (!novo) {
        printf("Erro ao alocar memória.\n");
        return;
    }

    novo->mov = m;           // copia movimento
    novo->prox = L->inicio;  // aponta para antigo primeiro
    L->inicio = novo;        // agora novo é o primeiro
}

int main() {
    Lista combo;
    inicializa_lista(&combo);

    int opcao;

    do {
        printf("\n===== MENU =====\n");
        printf("1 - Inserir novo movimento no início\n");
        printf("2 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            Movimento m;

            printf("ID do movimento: ");
            scanf("%d", &m.id);

            printf("Nome do movimento: ");
            scanf(" %[^\n]", m.nome);

            insere_inicio(&combo, m);

            printf("Movimento inserido!\n");
        }

    } while (opcao != 2);

    printf("Encerrando...\n");

    return 0;
}
