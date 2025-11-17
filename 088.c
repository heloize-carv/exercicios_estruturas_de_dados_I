#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int matricula;
    char nome[50];
} Jogador;

typedef struct No {
    Jogador dado;
    struct No *prox;
} No;

typedef struct {
    No *inicio;
} Lista;

void inicializar(Lista *l) {
    l->inicio = NULL;
}

No* criar_no(int matricula, char nome[]) {
    No *novo = (No*) malloc(sizeof(No));
    novo->dado.matricula = matricula;
    strcpy(novo->dado.nome, nome);
    novo->prox = NULL;
    return novo;
}

void inserir_fim(Lista *l, int matricula, char nome[]) {
    No *novo = criar_no(matricula, nome);

    if (l->inicio == NULL) {
        l->inicio = novo;
    } else {
        No *aux = l->inicio;
        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = novo;
    }

    printf("Jogador adicionado ao fim.\n");
}

void mostrar(Lista *l) {
    if (l->inicio == NULL) {
        printf("Lista vazia.\n");
        return;
    }

    No *aux = l->inicio;
    while (aux != NULL) {
        printf("Matricula: %d | Nome: %s\n", aux->dado.matricula, aux->dado.nome);
        aux = aux->prox;
    }
}

void deletar_fim(Lista *plista) {
    if (plista->inicio == NULL) {
        printf("Nao e possivel remover. Lista vazia.\n");
        return;
    }

    if (plista->inicio->prox == NULL) {
        printf("Jogador %s removido do fim.\n", plista->inicio->dado.nome);
        free(plista->inicio);
        plista->inicio = NULL;
        return;
    }

    No *atual = plista->inicio;
    No *anterior = NULL;

    while (atual->prox != NULL) {
        anterior = atual;
        atual = atual->prox;
    }

    printf("Jogador %s removido do fim.\n", atual->dado.nome);
    free(atual);
    anterior->prox = NULL;
}

int main() {
    Lista lista;
    inicializar(&lista);

    int opcao;

    do {
        printf("\n1 - Inserir no fim\n");
        printf("2 - Mostrar lista\n");
        printf("8 - Deletar do fim\n");
        printf("9 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            int m;
            char nome[50];

            printf("Matricula: ");
            scanf("%d", &m);

            printf("Nome: ");
            getchar();
            fgets(nome, 50, stdin);
            nome[strcspn(nome, "\n")] = '\0';

            inserir_fim(&lista, m, nome);
        }

        else if (opcao == 2) {
            mostrar(&lista);
        }

        else if (opcao == 8) {
            deletar_fim(&lista);
        }

    } while (opcao != 9);

    return 0;
}
