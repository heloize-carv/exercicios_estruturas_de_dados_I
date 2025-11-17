#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char nome[100];
} Mercenario;

typedef struct No {
    Mercenario m;
    struct No *prox;
} No;

typedef struct {
    No *inicio;
} Lista;

void menu();
void inserir_fim(Lista *l, Mercenario m);
void mostrar(Lista l);
int tamanho(Lista l);

int main() {
    Lista guilda;
    guilda.inicio = NULL;

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
                fgets(m.nome, 100, stdin);
                m.nome[strcspn(m.nome, "\n")] = 0;
                inserir_fim(&guilda, m);
                break;

            case 2:
                mostrar(guilda);
                break;

            case 3:
                printf("\nTamanho atual da guilda: %d mercenario(s)\n", tamanho(guilda));
                break;

            case 4:
                printf("\nEncerrando sistema...\n");
                break;

            default:
                printf("\nOpcao invalida!\n");
        }

    } while(op != 4);

    return 0;
}

void menu() {
    printf("\n--- Censo da Guilda ---\n");
    printf("1 - Contratar mercenario\n");
    printf("2 - Mostrar guilda\n");
    printf("3 - Mostrar tamanho da guilda\n");
    printf("4 - Sair\n");
    printf("Escolha: ");
}

void inserir_fim(Lista *l, Mercenario m) {
    No *novo = (No*) malloc(sizeof(No));
    novo->m = m;
    novo->prox = NULL;

    if (l->inicio == NULL) {
        l->inicio = novo;
    } else {
        No *p = l->inicio;
        while (p->prox != NULL)
            p = p->prox;
        p->prox = novo;
    }

    printf("Mercenario '%s' contratado!\n", m.nome);
}

void mostrar(Lista l) {
    if (l.inicio == NULL) {
        printf("\nA guilda esta vazia.\n");
        return;
    }

    printf("\n--- Lista de Mercenarios ---\n");
    No *p = l.inicio;

    while (p != NULL) {
        printf("ID: %d | Nome: %s\n", p->m.id, p->m.nome);
        p = p->prox;
    }
}

int tamanho(Lista l) {
    int cont = 0;
    No *p = l.inicio;

    while (p != NULL) {
        cont++;
        p = p->prox;
    }

    return cont;
}