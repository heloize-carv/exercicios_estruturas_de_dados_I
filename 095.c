#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char tipo[50];
} Inimigo;

typedef struct No {
    Inimigo inimigo;
    struct No *prox;
} No;

typedef struct {
    No *inicio;
} Lista;

void inserir_fim(Lista *lista, Inimigo i);
void mostrar(Lista lista);
void menu();
void limpar_lista(Lista *lista);
Lista criar_lista(int n);

int main() {
    Lista onda;
    onda.inicio = NULL;

    int op, n;

    do {
        menu();
        scanf("%d", &op);

        switch(op) {

            case 1:
                printf("\nQuantos inimigos tera a nova onda? ");
                scanf("%d", &n);
                limpar_lista(&onda);
                onda = criar_lista(n);
                printf("\nNova onda iniciada com sucesso!\n");
                break;

            case 2:
                mostrar(onda);
                break;

            case 3:
                printf("\nEncerrando o sistema...\n");
                break;

            default:
                printf("\nOpcao invalida!\n");
        }

    } while(op != 3);

    limpar_lista(&onda);

    return 0;
}

void menu() {
    printf("\n=== Sistema de Ondas de Inimigos ===\n");
    printf("1 - Iniciar Nova Onda\n");
    printf("2 - Mostrar Inimigos Atuais\n");
    printf("3 - Sair\n");
    printf("Escolha: ");
}

void inserir_fim(Lista *lista, Inimigo i) {
    No *novo = (No*) malloc(sizeof(No));
    novo->inimigo = i;
    novo->prox = NULL;

    if (lista->inicio == NULL) {
        lista->inicio = novo;
    } else {
        No *aux = lista->inicio;
        while (aux->prox != NULL)
            aux = aux->prox;
        aux->prox = novo;
    }
}

void mostrar(Lista lista) {
    if (lista.inicio == NULL) {
        printf("\nNao ha inimigos nesta onda.\n");
        return;
    }

    printf("\n--- Inimigos da Onda ---\n");
    No *aux = lista.inicio;
    while (aux != NULL) {
        printf("ID: %d | Tipo: %s\n", aux->inimigo.id, aux->inimigo.tipo);
        aux = aux->prox;
    }
}

void limpar_lista(Lista *lista) {
    No *atual = lista->inicio;
    while (atual != NULL) {
        No *temp = atual;
        atual = atual->prox;
        free(temp);
    }
    lista->inicio = NULL;
}

Lista criar_lista(int n) {
    Lista nova;
    nova.inicio = NULL;

    Inimigo i;
    getchar(); // limpa buffer

    for (int k = 0; k < n; k++) {
        printf("\nInimigo %d:\n", k + 1);
        printf("ID: ");
        scanf("%d", &i.id);
        getchar();
        printf("Tipo: ");
        fgets(i.tipo, 50, stdin);
        i.tipo[strcspn(i.tipo, "\n")] = 0;

        inserir_fim(&nova, i);
    }

    return nova;
}
