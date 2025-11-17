#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char nome[100];
} Monstro;

typedef struct No {
    Monstro monstro;
    struct No *prox;
} No;

typedef struct {
    No *inicio;
} Lista;

void menu();
void adicionarMonstro(Lista *lista, Monstro m);
void mostrarBestiario(Lista lista);
void ordenarBestiario(Lista *lista);

int main() {
    Lista bestiario;
    bestiario.inicio = NULL;

    int op;
    Monstro m;

    do {
        menu();
        scanf("%d", &op);
        getchar();

        switch (op) {
            case 1:
                printf("\nNível de ameaça do monstro (ID): ");
                scanf("%d", &m.id);
                getchar();
                printf("Nome do monstro: ");
                fgets(m.nome, 100, stdin);
                m.nome[strcspn(m.nome, "\n")] = 0;
                adicionarMonstro(&bestiario, m);
                break;

            case 2:
                ordenarBestiario(&bestiario);
                printf("\nBestiário ordenado com sucesso!\n");
                break;

            case 3:
                mostrarBestiario(bestiario);
                break;

            case 4:
                printf("\nEncerrando o sistema...\n");
                break;

            default:
                printf("\nOpção inválida!\n");
        }
    } while (op != 4);

    No *atual = bestiario.inicio;
    while (atual != NULL) {
        No *temp = atual;
        atual = atual->prox;
        free(temp);
    }

    return 0;
}

void menu() {
    printf("\n=== Bestiário do RPG ===\n");
    printf("1 - Adicionar monstro\n");
    printf("2 - Ordenar bestiário\n");
    printf("3 - Mostrar bestiário\n");
    printf("4 - Sair\n");
    printf("Escolha: ");
}

void adicionarMonstro(Lista *lista, Monstro m) {
    No *novo = (No*) malloc(sizeof(No));
    if (!novo) return;

    novo->monstro = m;
    novo->prox = NULL;

    if (lista->inicio == NULL) {
        lista->inicio = novo;
    } else {
        No *p = lista->inicio;
        while (p->prox != NULL)
            p = p->prox;
        p->prox = novo;
    }

    printf("\nMonstro '%s' adicionado!\n", m.nome);
}

void mostrarBestiario(Lista lista) {
    if (lista.inicio == NULL) {
        printf("\nBestiário vazio!\n");
        return;
    }

    printf("\n--- Lista de Monstros ---\n");
    No *p = lista.inicio;

    while (p != NULL) {
        printf("Nível de ameaça (ID): %d | Nome: %s\n",
               p->monstro.id, p->monstro.nome);
        p = p->prox;
    }
}

void ordenarBestiario(Lista *lista) {
    if (lista->inicio == NULL || lista->inicio->prox == NULL) return;

    int trocou;
    No *p;
    No *ultimo = NULL;

    do {
        trocou = 0;
        p = lista->inicio;

        while (p->prox != ultimo) {
            if (p->monstro.id > p->prox->monstro.id) {
                Monstro aux = p->monstro;
                p->monstro = p->prox->monstro;
                p->prox->monstro = aux;
                trocou = 1;
            }
            p = p->prox;
        }
        ultimo = p;

    } while (trocou);
}
