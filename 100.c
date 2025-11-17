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

int main() {
    Pilha comandos;
    inicializar(&comandos);

    int op;
    Feitico fx;

    do {
        printf("\n--- PILHA DE FEITICOS ---\n");
        printf("1 - Adicionar feitiço\n");
        printf("2 - Sair\n");
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

    } while (op != 2);

    return 0;
}
