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

void mostrar(Fila *f) {
    if (f->inicio == NULL) {
        printf("\nA fila de matchmaking esta vazia.\n");
        return;
    }

    printf("\n--- Jogadores na Fila ---\n");

    No *aux = f->inicio;
    while (aux != NULL) {
        printf("ID: %d | Nickname: %s\n", aux->dado.id, aux->dado.nickname);
        aux = aux->prox;
    }

    printf("-------------------------\n");
}

Jogador remover(Fila *f) {
    Jogador vazio;
    vazio.id = -1;
    strcpy(vazio.nickname, "");

    if (f->inicio == NULL) {
        printf("\nA fila esta vazia! Nao ha ninguem para remover.\n");
        return vazio;
    }

    No *rem = f->inicio;
    Jogador j = rem->dado;

    f->inicio = rem->prox;

    if (f->inicio == NULL) {
        f->fim = NULL;
    }

    free(rem);

    return j;
}

int estaVazia(Fila *f) {
    return f->inicio == NULL;
}

Jogador verInicio(Fila *f) {
    Jogador vazio;
    vazio.id = -1;
    strcpy(vazio.nickname, "");

    if (f->inicio == NULL) {
        return vazio;
    }

    return f->inicio->dado;
}

int main() {
    Fila fila;
    inicializar(&fila);

    int op;
    Jogador j;

    do {
        printf("\n--- FILA DE MATCHMAKING ---\n");
        printf("1 - Inserir jogador na fila\n");
        printf("2 - Mostrar fila\n");
        printf("3 - Remover jogador da fila (Iniciar partida)\n");
        printf("4 - Verificar se a fila esta vazia\n");
        printf("5 - Ver quem e o proximo da fila (Peek)\n");
        printf("6 - Sair\n");
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
                mostrar(&fila);
                break;

            case 3:
                j = remover(&fila);
                if (j.id != -1) {
                    printf("\nO jogador %s (ID: %d) entrou em uma partida.\n", j.nickname, j.id);
                }
                break;

            case 4:
                if (estaVazia(&fila)) {
                    printf("\nSIM, a fila esta vazia.\n");
                } else {
                    printf("\nNAO, a fila contem jogadores.\n");
                }
                break;

            case 5:
                j = verInicio(&fila);
                if (j.id == -1) {
                    printf("\nNao ha ninguem na fila.\n");
                } else {
                    printf("\nO proximo jogador a entrar na partida e: %s (ID: %d)\n", j.nickname, j.id);
                }
                break;

            case 6:
                printf("\nEncerrando...\n");
                break;

            default:
                printf("\nOpcao invalida!\n");
        }

    } while (op != 6);

    return 0;
}
