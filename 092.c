#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char nome[50];
} Mercenario;

typedef struct No {
    Mercenario m;
    struct No *prox;
} No;

typedef struct {
    No *inicio;
} Lista;

void contratar(Lista *l, Mercenario m);
void mostrar(Lista l);
void demitir_todos_mercenarios(Lista *l);
void menu();

int main() {
    Lista companhia;
    companhia.inicio = NULL;

    int op;
    Mercenario m;

    do {
        menu();
        scanf("%d", &op);
        getchar();

        switch(op) {
            case 1:
                printf("\nID do mercenario: ");
                scanf("%d", &m.id);
                getchar();
                printf("Nome do mercenario: ");
                fgets(m.nome, 50, stdin);
                m.nome[strcspn(m.nome, "\n")] = 0;
                contratar(&companhia, m);
                break;

            case 2:
                mostrar(companhia);
                break;

            case 3:
                demitir_todos_mercenarios(&companhia);
                printf("\nA companhia foi dissolvida! Todos os mercenarios foram demitidos.\n");
                break;

            case 4:
                printf("\nEncerrando sistema...\n");
                break;

            default:
                printf("\nOpcao invalida!\n");
        }

    } while(op != 4);

    demitir_todos_mercenarios(&companhia);

    return 0;
}

void menu() {
    printf("\n--- Companhia de Mercenarios ---\n");
    printf("1 - Contratar mercenario\n");
    printf("2 - Exibir companhia\n");
    printf("3 - Declarar falencia (demitir todos)\n");
    printf("4 - Sair\n");
    printf("Escolha: ");
}

void contratar(Lista *l, Mercenario m) {
    No *novo = (No*) malloc(sizeof(No));
    novo->m = m;
    novo->prox = NULL;

    if (l->inicio == NULL) {
        l->inicio = novo;
    } else {
        No *aux = l->inicio;
        while (aux->prox != NULL)
            aux = aux->prox;
        aux->prox = novo;
    }

    printf("Mercenario '%s' contratado!\n", m.nome);
}

void mostrar(Lista l) {
    printf("\n--- Lista de Mercenarios ---\n");

    if (l.inicio == NULL) {
        printf("A companhia esta vazia.\n");
        return;
    }

    No *aux = l.inicio;
    while (aux != NULL) {
        printf("ID: %d | Nome: %s\n", aux->m.id, aux->m.nome);
        aux = aux->prox;
    }
}

void demitir_todos_mercenarios(Lista *l) {
    No *aux = l->inicio;
    while (aux != NULL) {
        No *temp = aux;
        aux = aux->prox;
        free(temp);
    }
    l->inicio = NULL;
}
