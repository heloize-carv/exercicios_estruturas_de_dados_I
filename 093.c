#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char nome[100];
} Membro;

typedef struct No {
    Membro m;
    struct No *prox;
} No;

typedef struct {
    No *inicio;
} Lista;

void inserir_fim(Lista *l, Membro m);
void mostrar_lista(Lista l);
No* pesquisar(Lista l, int id);
void alterar_nome(Lista *l, int id, char novo_nome[]);
void menu();

int main() {
    Lista lista;
    lista.inicio = NULL;

    int op, id;
    Membro m;
    char novo_nome[100];

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
                inserir_fim(&lista, m);
                break;

            case 2:
                mostrar_lista(lista);
                break;

            case 3:
                printf("\nDigite o ID do membro que deseja renomear: ");
                scanf("%d", &id);
                getchar();
                printf("Digite o novo nome: ");
                fgets(novo_nome, 100, stdin);
                novo_nome[strcspn(novo_nome, "\n")] = 0;
                alterar_nome(&lista, id, novo_nome);
                break;

            case 4:
                printf("\nEncerrando sistema...\n");
                break;

            default:
                printf("\nOpcao invalida!\n");
        }

    } while(op != 4);

    return 0;
}

void menu() {
    printf("\n--- Gerenciador da Guilda ---\n");
    printf("1 - Adicionar membro\n");
    printf("2 - Mostrar lista\n");
    printf("3 - Alterar nome de membro\n");
    printf("4 - Sair\n");
    printf("Escolha: ");
}

void inserir_fim(Lista *l, Membro m) {
    No *novo = (No*) malloc(sizeof(No));
    novo->m = m;
    novo->prox = NULL;

    if (l->inicio == NULL) {
        l->inicio = novo;
    } else {
        No *p = l->inicio;
        while (p->prox != NULL)
            p = p->prox;
        p->prox = novo;
    }

    printf("Membro '%s' adicionado!\n", m.nome);
}

void mostrar_lista(Lista l) {
    if (l.inicio == NULL) {
        printf("\nA guilda esta vazia.\n");
        return;
    }

    printf("\n--- Lista de Membros ---\n");
    No *p = l.inicio;
    while (p != NULL) {
        printf("ID: %d | Nome: %s\n", p->m.id, p->m.nome);
        p = p->prox;
    }
}

No* pesquisar(Lista l, int id) {
    No *p = l.inicio;
    while (p != NULL) {
        if (p->m.id == id)
            return p;
        p = p->prox;
    }
    return NULL;
}

void alterar_nome(Lista *l, int id, char novo_nome[]) {
    No *membro = pesquisar(*l, id);

    if (membro == NULL) {
        printf("\nMembro com ID %d nao encontrado.\n", id);
        return;
    }

    strcpy(membro->m.nome, novo_nome);
    printf("\nNome atualizado com sucesso!\n");
}
