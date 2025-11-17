#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Heroi {
    int id;
    char nome[50];
    struct Heroi *prox;
} Heroi;

Heroi* criar_heroi(int id, char nome[]) {
    Heroi *novo = (Heroi*) malloc(sizeof(Heroi));
    novo->id = id;
    strcpy(novo->nome, nome);
    novo->prox = NULL;
    return novo;
}

void inserir_fim(Heroi **lista, Heroi *novo) {
    if (*lista == NULL) {
        *lista = novo;
    } else {
        Heroi *aux = *lista;
        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = novo;
    }
}

int inserir_antes(Heroi **lista, int id_vip, Heroi *novo) {
    // Lista vazia
    if (*lista == NULL) {
        return 0;
    }

    Heroi *atual = *lista;
    Heroi *anterior = NULL;

    if (atual->id == id_vip) {
        novo->prox = *lista;
        *lista = novo;
        return 1;
    }

    while (atual != NULL && atual->id != id_vip) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual == NULL) {
        return 0;
    }

    anterior->prox = novo;
    novo->prox = atual;
    return 1;
}

void mostrar(Heroi *lista) {
    if (lista == NULL) {
        printf("\nFormacao vazia!\n");
        return;
    }

    printf("\n--- Formacao de Batalha ---\n");
    Heroi *aux = lista;
    while (aux != NULL) {
        printf("ID: %d | Nome: %s\n", aux->id, aux->nome);
        aux = aux->prox;
    }
}

int main() {
    Heroi *formacao = NULL;
    int opcao;

    do {
        printf("\n===== FORMACAO DE BATALHA =====\n");
        printf("1 - Adicionar heroi no fim\n");
        printf("2 - Adicionar guarda-costas (inserir antes)\n");
        printf("3 - Mostrar formacao\n");
        printf("4 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            int id;
            char nome[50];

            printf("ID: ");
            scanf("%d", &id);

            printf("Nome do heroi: ");
            getchar();
            fgets(nome, 50, stdin);
            nome[strcspn(nome, "\n")] = '\0';

            inserir_fim(&formacao, criar_heroi(id, nome));
            printf("Heroi adicionado ao fim da formacao!\n");
        }

        else if (opcao == 2) {
            int id_gc, id_vip;
            char nome[50];

            printf("ID do guarda-costas: ");
            scanf("%d", &id_gc);

            printf("Nome do guarda-costas: ");
            getchar();
            fgets(nome, 50, stdin);
            nome[strcspn(nome, "\n")] = '\0';

            printf("ID do heroi VIP: ");
            scanf("%d", &id_vip);

            Heroi *novo = criar_heroi(id_gc, nome);

            if (inserir_antes(&formacao, id_vip, novo)) {
                printf("Guarda-costas inserido antes do VIP!\n");
            } else {
                printf("VIP nao encontrado! Insercao cancelada.\n");
                free(novo);
            }
        }

        else if (opcao == 3) {
            mostrar(formacao);
        }

    } while (opcao != 4);

    printf("Encerrando...\n");
    return 0;
}