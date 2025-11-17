#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[50];
    int custo_mana;
} Feitico;

typedef struct No {
    Feitico f;
    struct No *prox;
} No;

typedef struct {
    No *topo;
} Pilha;

void inicializar(Pilha *p) {
    p->topo = NULL;
}

void push(Pilha *p, Feitico f) {
    No *novo = (No*) malloc(sizeof(No));
    strcpy(novo->f.nome, f.nome);
    novo->f.custo_mana = f.custo_mana;
    novo->prox = p->topo;
    p->topo = novo;
}

void mostrar_pilha(Pilha *p) {
    if (p->topo == NULL) {
        printf("\nA pilha de comandos esta vazia.\n");
        return;
    }
    No *aux = p->topo;
    printf("\n--- PILHA DE FEITICOS (TOPO -> BASE) ---\n");
    while (aux != NULL) {
        printf("Feitico: %s | Custo de Mana: %d\n", aux->f.nome, aux->f.custo_mana);
        aux = aux->prox;
    }
}

Feitico pop(Pilha *p) {
    Feitico vazio;
    vazio.custo_mana = -1;

    if (p->topo == NULL) {
        printf("\nA pilha de comandos esta vazia!\n");
        return vazio;
    }

    No *rem = p->topo;
    Feitico fx = rem->f;

    p->topo = rem->prox;
    free(rem);

    return fx;
}

void liberar_pilha(Pilha *p) {
    while (p->topo != NULL) {
        pop(p);
    }
}

int main() {
    Pilha comandos;
    inicializar(&comandos);

    int op;
    Feitico fx;

    do {
        printf("\n--- MENU ---\n");
        printf("1 - Adicionar feitiço\n");
        printf("2 - Lançar próximo feitiço\n");
        printf("3 - Mostrar pilha\n");
        printf("4 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &op);
        getchar();

        if (op == 1) {
            printf("Nome do feitiço: ");
            fgets(fx.nome, 50, stdin);
            fx.nome[strcspn(fx.nome, "\n")] = 0;
            printf("Custo de mana: ");
            scanf("%d", &fx.custo_mana);
            push(&comandos, fx);
            printf("Feitiço adicionado ao topo da pilha!\n");
        }
        else if (op == 2) {
            Feitico usado = pop(&comandos);
            if (usado.custo_mana != -1) {
                printf("\nFeitiço '%s' lançado com sucesso!\n", usado.nome);
            }
        }
        else if (op == 3) {
            mostrar_pilha(&comandos);
        }

    } while (op != 4);

    liberar_pilha(&comandos);

    return 0;
}
