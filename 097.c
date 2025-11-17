#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char nome[100];
} Membro;

typedef struct No {
    Membro membro;
    struct No *prox;
} No;

typedef struct {
    No *inicio;
} Lista;

void menu();
void inserir_fim(Lista *lista, Membro m);
void mostrar(Lista lista);
void salvar_guild_arquivo(Lista lista);

int main() {
    Lista guilda;
    guilda.inicio = NULL;

    int op;
    Membro m;

    do {
        menu();
        scanf("%d", &op);
        getchar();

        switch(op) {
            case 1:
                printf("\nID do membro: ");
                scanf("%d", &m.id);
                getchar();
                printf("Nome do membro: ");
                fgets(m.nome, 100, stdin);
                m.nome[strcspn(m.nome, "\n")] = 0;
                inserir_fim(&guilda, m);
                break;

            case 2:
                mostrar(guilda);
                break;

            case 3:
                salvar_guild_arquivo(guilda);
                printf("\nGuilda salva no arquivo guild_roster.bin\n");
                break;

            case 4:
                printf("\nEncerrando...\n");
                break;

            default:
                printf("\nOpcao invalida!\n");
        }

    } while (op != 4);

    No *atual = guilda.inicio;
    while (atual != NULL) {
        No *temp = atual;
        atual = atual->prox;
        free(temp);
    }

    return 0;
}

void menu() {
    printf("\n=== Sistema da Guilda ===\n");
    printf("1 - Adicionar membro\n");
    printf("2 - Mostrar guilda\n");
    printf("3 - Salvar em arquivo\n");
    printf("4 - Sair\n");
    printf("Escolha: ");
}

void inserir_fim(Lista *lista, Membro m) {
    No *novo = (No*) malloc(sizeof(No));
    if (!novo) return;

    novo->membro = m;
    novo->prox = NULL;

    if (lista->inicio == NULL) {
        lista->inicio = novo;
    } else {
        No *p = lista->inicio;
        while (p->prox != NULL)
            p = p->prox;
        p->prox = novo;
    }
}

void mostrar(Lista lista) {
    if (lista.inicio == NULL) {
        printf("\nGuilda vazia.\n");
        return;
    }

    printf("\n--- Membros da Guilda ---\n");
    No *p = lista.inicio;

    while (p != NULL) {
        printf("ID: %d | Nome: %s\n", p->membro.id, p->membro.nome);
        p = p->prox;
    }
}

void salvar_guild_arquivo(Lista lista) {
    FILE *arq = fopen("guild_roster.bin", "wb");
    if (!arq) return;

    No *p = lista.inicio;
    while (p != NULL) {
        fwrite(&p->membro, sizeof(Membro), 1, arq);
        p = p->prox;
    }

    fclose(arq);
}