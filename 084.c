#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Missao {
    int id;
    char titulo[50];
    char status[20];
    struct Missao *prox;
} Missao;

Missao* criar_missao(int id, char titulo[], char status[]) {
    Missao *nova = (Missao*) malloc(sizeof(Missao));
    nova->id = id;
    strcpy(nova->titulo, titulo);
    strcpy(nova->status, status);
    nova->prox = NULL;
    return nova;
}

void inserir_missao(Missao **lista, Missao *nova) {
    if (*lista == NULL) {
        *lista = nova;
    } else {
        Missao *aux = *lista;
        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = nova;
    }
}

void mostrar_missoes(Missao *lista) {
    if (lista == NULL) {
        printf("\nNao ha missoes no diario!\n");
        return;
    }

    printf("\n--- Missoes Ativas ---\n");
    Missao *aux = lista;
    while (aux != NULL) {
        printf("ID: %d | Titulo: %s | Status: %s\n",
               aux->id, aux->titulo, aux->status);
        aux = aux->prox;
    }
}

Missao* pesquisar_missao(Missao *lista, int id) {
    Missao *aux = lista;
    while (aux != NULL) {
        if (aux->id == id) {
            return aux;  
        }
        aux = aux->prox;
    }
    return NULL; 
}

int main() {
    Missao *diario = NULL;
    int opcao;

    do {
        printf("\n===== Diario de Missoes =====\n");
        printf("1 - Adicionar Missao\n");
        printf("2 - Mostrar Missoes\n");
        printf("3 - Buscar Missao por ID\n");
        printf("4 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            int id;
            char titulo[50];
            char status[20];

            printf("ID da missao: ");
            scanf("%d", &id);

            printf("Titulo da missao: ");
            getchar(); 
            fgets(titulo, 50, stdin);
            titulo[strcspn(titulo, "\n")] = '\0';

            printf("Status da missao: ");
            fgets(status, 20, stdin);
            status[strcspn(status, "\n")] = '\0';

            Missao *nova = criar_missao(id, titulo, status);
            inserir_missao(&diario, nova);

            printf("Missao adicionada com sucesso!\n");
        }

        else if (opcao == 2) {
            mostrar_missoes(diario);
        }

        else if (opcao == 3) {
            int id_busca;
            printf("Digite o ID da missao: ");
            scanf("%d", &id_busca);

            Missao *m = pesquisar_missao(diario, id_busca);

            if (m == NULL) {
                printf("Missao nao encontrada!\n");
            } else {
                printf("\n--- Missao Encontrada ---\n");
                printf("ID: %d\nTitulo: %s\nStatus: %s\n",
                       m->id, m->titulo, m->status);
            }
        }

    } while (opcao != 4);

    printf("Encerrando...\n");
    return 0;
}