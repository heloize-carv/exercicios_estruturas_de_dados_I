#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Item {
    int id;
    char nome[50];
    struct Item *prox;
} Item;

Item* criar_item(int id, char nome[]) {
    Item *novo = (Item*) malloc(sizeof(Item));
    novo->id = id;
    strcpy(novo->nome, nome);
    novo->prox = NULL;
    return novo;
}

void inserir_inicio(Item **lista, Item *novo) {
    novo->prox = *lista;
    *lista = novo;
}

void inserir_fim(Item **lista, Item *novo) {
    if (*lista == NULL) {
        *lista = novo;
    } else {
        Item *aux = *lista;
        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = novo;
    }
}

int inserir_apos(Item **lista, int id_fragmento, Item *novo) {
    Item *aux = *lista;

    while (aux != NULL) {
        if (aux->id == id_fragmento) {
            novo->prox = aux->prox;
            aux->prox = novo;
            return 1; 
        }
        aux = aux->prox;
    }

    return 0; 
}


void mostrar(Item *lista) {
    if (lista == NULL) {
        printf("\nInventario vazio!\n");
        return;
    }

    printf("\n--- Inventario de Itens ---\n");
    Item *aux = lista;
    while (aux != NULL) {
        printf("ID: %d | Nome: %s\n", aux->id, aux->nome);
        aux = aux->prox;
    }
}

int main() {
    Item *inventario = NULL;
    int opcao;

    do {
        printf("\n===== INVENTARIO RPG =====\n");
        printf("1 - Inserir item no inicio\n");
        printf("2 - Inserir item no fim\n");
        printf("3 - Inserir catalisador apos fragmento\n");
        printf("4 - Mostrar inventario\n");
        printf("5 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            int id;
            char nome[50];
            printf("ID: ");
            scanf("%d", &id);

            printf("Nome do item: ");
            getchar();
            fgets(nome, 50, stdin);
            nome[strcspn(nome, "\n")] = '\0';

            inserir_inicio(&inventario, criar_item(id, nome));
            printf("Item inserido no inicio!\n");
        }

        else if (opcao == 2) {
            int id;
            char nome[50];
            printf("ID: ");
            scanf("%d", &id);

            printf("Nome do item: ");
            getchar();
            fgets(nome, 50, stdin);
            nome[strcspn(nome, "\n")] = '\0';

            inserir_fim(&inventario, criar_item(id, nome));
            printf("Item inserido no fim!\n");
        }

        else if (opcao == 3) {
            int id_catalisador, id_fragmento;
            char nome[50];

            printf("ID do catalisador: ");
            scanf("%d", &id_catalisador);

            printf("Nome do catalisador: ");
            getchar();
            fgets(nome, 50, stdin);
            nome[strcspn(nome, "\n")] = '\0';

            printf("ID do Fragmento de Poder alvo: ");
            scanf("%d", &id_fragmento);

            Item *novo = criar_item(id_catalisador, nome);

            if (inserir_apos(&inventario, id_fragmento, novo)) {
                printf("Catalisador inserido apos o fragmento!\n");
            } else {
                printf("Fragmento nao encontrado! Insercao cancelada.\n");
                free(novo); 
            }
        }

        else if (opcao == 4) {
            mostrar(inventario);
        }

    } while (opcao != 5);

    printf("Encerrando...\n");
    return 0;
}