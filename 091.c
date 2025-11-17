#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char descricao[100];
} Etapa;

typedef struct No {
    Etapa etapa;
    struct No *prox;
} No;

typedef struct {
    No *inicio;
} Lista;

void menu();
void inserir_fim(Lista *lista, Etapa e);
void mostrar(Lista lista);
void deletar_antes(Lista *lista, int id_ref);

int main() {
    Lista lista;
    lista.inicio = NULL;
    int op, id_ref;
    Etapa e;

    do {
        menu();
        scanf("%d", &op);
        getchar();

        switch(op) {
            case 1:
                printf("\nDigite o ID da etapa: ");
                scanf("%d", &e.id);
                getchar();
                printf("Digite a descricao da etapa: ");
                fgets(e.descricao, 100, stdin);
                e.descricao[strcspn(e.descricao, "\n")] = 0;
                inserir_fim(&lista, e);
                break;
            case 2:
                mostrar(lista);
                break;
            case 3:
                printf("\nInforme o ID da etapa de referencia: ");
                scanf("%d", &id_ref);
                deletar_antes(&lista, id_ref);
                break;
            case 4:
                printf("\nFinalizando o programa...\n");
                break;
            default:
                printf("\nOpcao invalida!\n");
        }
    } while(op != 4);

    No *atual = lista.inicio;
    while (atual != NULL) {
        No *temp = atual;
        atual = atual->prox;
        free(temp);
    }

    return 0;
}

void menu() {
    printf("\n--- Gerenciador de Etapas de Missao ---\n");
    printf("1 - Inserir etapa no fim\n");
    printf("2 - Mostrar etapas\n");
    printf("3 - Deletar etapa ANTES de um ID\n");
    printf("4 - Sair\n");
    printf("Escolha uma opcao: ");
}

void inserir_fim(Lista *lista, Etapa e) {
    No *novo = (No*) malloc(sizeof(No));
    if (!novo) {
        printf("Erro de alocacao de memoria!\n");
        return;
    }
    novo->etapa = e;
    novo->prox = NULL;

    if (lista->inicio == NULL) {
        lista->inicio = novo;
    } else {
        No *pi = lista->inicio;
        while (pi->prox != NULL) {
            pi = pi->prox;
        }
        pi->prox = novo;
    }
    printf("Etapa '%s' inserida com sucesso!\n", e.descricao);
}

void mostrar(Lista lista) {
    printf("\n--- Diário de Missao ---\n");
    if (lista.inicio == NULL) {
        printf("Nenhuma etapa registrada.\n");
        return;
    }
    No *pi = lista.inicio;
    while (pi != NULL) {
        printf("ID: %d - Descricao: %s\n", pi->etapa.id, pi->etapa.descricao);
        pi = pi->prox;
    }
    printf("------------------------\n");
}

void deletar_antes(Lista *lista, int id_ref) {
    if (lista->inicio == NULL) {
        printf("\nLista vazia. Nao ha etapas para deletar.\n");
        return;
    }

    No *atual = lista->inicio;
    No *anterior = NULL;
    No *antes_anterior = NULL;

    while (atual != NULL && atual->etapa.id != id_ref) {
        antes_anterior = anterior;
        anterior = atual;
        atual = atual->prox;
    }

    if (atual == NULL) {
        printf("\nEtapa de referencia nao encontrada.\n");
        return;
    }

    if (anterior == NULL) {
        printf("\nA etapa de referencia e a primeira; nao ha etapa anterior para deletar.\n");
        return;
    }

    if (antes_anterior == NULL) {
        No *rem = lista->inicio;
        lista->inicio = rem->prox;
        printf("\nEtapa '%s' (ID %d) removida.\n", rem->etapa.descricao, rem->etapa.id);
        free(rem);
        return;
    }

    No *rem = anterior;
    antes_anterior->prox = atual;
    printf("\nEtapa '%s' (ID %d) removida.\n", rem->etapa.descricao, rem->etapa.id);
    free(rem);
}