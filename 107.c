#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[50];
    int custo_mana;
} Feitico;

typedef struct No {
    Feitico dado;
    struct No *prox;
} No;

typedef struct {
    No *topo;
} Pilha;

void inicializar(Pilha *p) {
    p->topo = NULL;
}

int vazia(Pilha *p) {
    return (p->topo == NULL);
}

void push(Pilha *p, Feitico f) {
    No *novo = (No*) malloc(sizeof(No));
    novo->dado = f;
    novo->prox = p->topo;
    p->topo = novo;
}

Feitico pop(Pilha *p) {
    Feitico erro = {"", -1};

    if (vazia(p)) {
        printf("A pilha de comandos está vazia!\n");
        return erro;
    }

    No *rem = p->topo;
    Feitico copia = rem->dado;

    p->topo = rem->prox;
    free(rem);

    return copia;
}

void mostrar_pilha(Pilha *p) {
    if (vazia(p)) {
        printf("\nA pilha de comandos está vazia.\n");
        return;
    }

    printf("\n--- PILHA DE FEITIÇOS (TOPO → BASE) ---\n");
    No *aux = p->topo;
    while (aux != NULL) {
        printf("Feitiço: %s | Mana: %d\n", aux->dado.nome, aux->dado.custo_mana);
        aux = aux->prox;
    }
    printf("---------------------------------------\n");
}

Feitico top(Pilha *p) {
    Feitico erro = {"", -1};

    if (vazia(p)) {
        printf("A pilha está vazia!\n");
        return erro;
    }

    return p->topo->dado;
}

void inverter_pilha(Pilha *p) {
    if (vazia(p)) {
        printf("\nNada para inverter, a pilha está vazia.\n");
        return;
    }

    Pilha aux;
    inicializar(&aux);

    while (!vazia(p)) {
        Feitico f = pop(p);
        push(&aux, f);
    }

    p->topo = aux.topo;

    printf("\nOrdem dos feitiços invertida!\n");
}

void liberar_pilha(Pilha *p) {
    while (!vazia(p)) {
        pop(p);
    }
}

void salvar_pilha_em_arquivo(Pilha *p, const char *nome_arquivo) {
    FILE *arq = fopen(nome_arquivo, "wb");

    if (!arq) {
        printf("Erro ao abrir o arquivo para salvar!\n");
        return;
    }

    No *aux = p->topo;

    while (aux != NULL) {
        fwrite(&aux->dado, sizeof(Feitico), 1, arq);
        aux = aux->prox;
    }

    fclose(arq);
    printf("\nPilha salva no arquivo '%s' com sucesso!\n", nome_arquivo);
}

void carregar_pilha_de_arquivo(Pilha *p, const char *nome_arquivo) {
    FILE *arq = fopen(nome_arquivo, "rb");

    if (!arq) {
        printf("Nenhum grimório encontrado, iniciando com uma pilha vazia.\n");
        return;
    }

    Feitico f;

    while (fread(&f, sizeof(Feitico), 1, arq) == 1) {
        push(p, f);  
    }

    fclose(arq);

    inverter_pilha(p);

    printf("Pilha carregada do arquivo '%s'!\n", nome_arquivo);
}

int main() {
    Pilha comandos;
    inicializar(&comandos);

    carregar_pilha_de_arquivo(&comandos, "grimorio.bin");

    int op;
    Feitico f;

    do {
        printf("\n--- MENU DO ARCANISTA ---\n");
        printf("1 - Adicionar Feitiço (Push)\n");
        printf("2 - Lançar Próximo Feitiço (Pop)\n");
        printf("3 - Mostrar Pilha\n");
        printf("4 - Consultar Próximo Feitiço (Top)\n");
        printf("5 - Verificar se a Pilha está Vazia\n");
        printf("6 - Inverter Ordem dos Feitiços\n");
        printf("7 - Salvar Sequência no Grimório\n");
        printf("8 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &op);
        getchar();

        switch (op) {
            case 1:
                printf("Nome do feitiço: ");
                fgets(f.nome, 50, stdin);
                f.nome[strcspn(f.nome, "\n")] = 0;

                printf("Custo de mana: ");
                scanf("%d", &f.custo_mana);

                push(&comandos, f);
                break;

            case 2: {
                Feitico lançado = pop(&comandos);
                if (lançado.custo_mana != -1) {
                    printf("Feitiço '%s' lançado com sucesso!\n", lançado.nome);
                }
                break;
            }

            case 3:
                mostrar_pilha(&comandos);
                break;

            case 4: {
                Feitico topo = top(&comandos);
                if (topo.custo_mana != -1) {
                    printf("Próximo feitiço: %s | Mana: %d\n", topo.nome, topo.custo_mana);
                }
                break;
            }

            case 5:
                if (vazia(&comandos))
                    printf("A pilha está vazia.\n");
                else
                    printf("A pilha possui feitiços.\n");
                break;

            case 6:
                inverter_pilha(&comandos);
                break;

            case 7:
                salvar_pilha_em_arquivo(&comandos, "grimorio.bin");
                break;

            case 8:
                printf("Encerrando...\n");
                break;

            default:
                printf("Opção inválida!\n");
        }

    } while (op != 8);

    liberar_pilha(&comandos);

    return 0;
}
