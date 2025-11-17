#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char nickname[50];
} Jogador;

typedef struct No {
    Jogador dado;
    struct No *prox;
} No;

typedef struct {
    No *inicio;
    No *fim;
} Fila;

void inicializar(Fila *f) {
    f->inicio = NULL;
    f->fim = NULL;
}

void inserir(Fila *f, Jogador j) {
    No *novo = (No*) malloc(sizeof(No));
    novo->dado = j;
    novo->prox = NULL;

    if (f->inicio == NULL) {
        f->inicio = novo;
        f->fim = novo;
    } else {
        f->fim->prox = novo;
        f->fim = novo;
    }

    printf("\nJogador '%s' entrou na fila!\n", j.nickname);
}

int main() {
    Fila fila;
    inicializar(&fila);

    int op;
    Jogador j;

    do {
        printf("\n--- FILA DE MATCHMAKING ---\n");
        printf("1 - Inserir jogador na fila\n");
        printf("2 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &op);
        getchar();

        switch (op) {
            case 1:
                printf("\nID do jogador: ");
                scanf("%d", &j.id);
                getchar();

                printf("Nickname: ");
                fgets(j.nickname, 50, stdin);
                j.nickname[strcspn(j.nickname, "\n")] = 0;

                inserir(&fila, j);
                break;

            case 2:
                printf("\nEncerrando...\n");
                break;

            default:
                printf("\nOpcao invalida!\n");
        }

    } while (op != 2);

    return 0;
}
