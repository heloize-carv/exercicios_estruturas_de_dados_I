#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char nome[100];
    int nivel;
} Membro;

typedef struct No {
    Membro m;
    struct No *prox;
} No;

typedef struct {
    No *inicio;
} Lista;

void inserir_fim(Lista *lista, Membro m) {
    No *novo = (No*) malloc(sizeof(No));
    if (!novo) return;
    novo->m = m;
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

void mostrar_guilda(Lista lista) {
    if (lista.inicio == NULL) {
        printf("\nGuilda vazia.\n");
        return;
    }

    No *p = lista.inicio;
    printf("\n--- Membros da Guilda ---\n");
    while (p != NULL) {
        printf("ID: %d | Nome: %s | Nivel: %d\n",
               p->m.id, p->m.nome, p->m.nivel);
        p = p->prox;
    }
}

void salvar_guilda_teste() {
    FILE *arq = fopen("guild_roster.b", "wb");
    if (!arq) return;

    Membro m1 = {1, "Astarion", 12};
    Membro m2 = {2, "Shadowheart", 15};
    Membro m3 = {3, "Lae'zel", 18};

    fwrite(&m1, sizeof(Membro), 1, arq);
    fwrite(&m2, sizeof(Membro), 1, arq);
    fwrite(&m3, sizeof(Membro), 1, arq);

    fclose(arq);
}

Lista carregar_guilda() {
    Lista lista;
    lista.inicio = NULL;

    FILE *arq = fopen("guild_roster.b", "rb");
    if (!arq) {
        printf("\nArquivo guild_roster.b nao encontrado.\n");
        return lista;
    }

    Membro m;
    while (fread(&m, sizeof(Membro), 1, arq) == 1) {
        inserir_fim(&lista, m);
    }

    fclose(arq);
    return lista;
}

int main() {
    salvar_guilda_teste();

    Lista guilda = carregar_guilda();

    mostrar_guilda(guilda);

    No *p = guilda.inicio;
    while (p != NULL) {
        No *tmp = p;
        p = p->prox;
        free(tmp);
    }

    return 0;
}
