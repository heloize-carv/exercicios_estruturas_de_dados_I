#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char nome[100];
} Ward;

typedef struct no {
    Ward ward;
    struct no *prox;
} No;

typedef struct {
    No *inicio;
} Lista;

void inicializar(Lista *l) {
    l->inicio = NULL;
}

void adicionar_fim(Lista *l, Ward w) {
    No *novo = (No*) malloc(sizeof(No));
    novo->ward = w;
    novo->prox = NULL;

    if (l->inicio == NULL) {
        l->inicio = novo;
    } else {
        No *aux = l->inicio;
        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = novo;
    }
}

void mostrar(Lista *l) {
    if (l->inicio == NULL) {
        printf("\nNenhum ward ativo.\n");
        return;
    }

    printf("\n--- Wards Ativos ---\n");
    No *aux = l->inicio;
    while (aux != NULL) {
        printf("ID: %d | Nome: %s\n", aux->ward.id, aux->ward.nome);
        aux = aux->prox;
    }
}

void deletar_apos(Lista *l, int id_ref) {
    if (l->inicio == NULL) {
        printf("\nNenhum ward na lista.\n");
        return;
    }

    No *aux = l->inicio;
    while (aux != NULL && aux->ward.id != id_ref) {
        aux = aux->prox;
    }

    if (aux == NULL) {
        printf("\nWard de referencia nao encontrado.\n");
        return;
    }

    if (aux->prox == NULL) {
        printf("\nNao ha ward apos o ID informado.\n");
        return;
    }

    No *remover = aux->prox;
    aux->prox = remover->prox;

    printf("\nWard '%s' (ID %d) foi destruido!\n", remover->ward.nome, remover->ward.id);
    free(remover);
}

int main() {
    Lista wards;
    inicializar(&wards);

    int opcao;
    do {
        printf("\n===== SISTEMA DE WARDS =====\n");
        printf("1. Adicionar Ward\n");
        printf("2. Lancar 'Ward Shatter'\n");
        printf("3. Mostrar Wards\n");
        printf("4. Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            Ward w;
            printf("ID do ward: ");
            scanf("%d", &w.id);
            printf("Nome do ward: ");
            getchar();
            fgets(w.nome, 100, stdin);
            w.nome[strcspn(w.nome, "\n")] = '\0';
            adicionar_fim(&wards, w);
        }

        else if (opcao == 2) {
            int id;
            printf("ID do ward alvo: ");
            scanf("%d", &id);
            deletar_apos(&wards, id);
        }

        else if (opcao == 3) {
            mostrar(&wards);
        }

    } while (opcao != 4);

    printf("\nEncerrando...\n");
    return 0;
}
