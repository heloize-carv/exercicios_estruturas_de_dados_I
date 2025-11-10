#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura Campeao
typedef struct {
    char nome[50];
    int vida;
    int ataque;
} Campeao;

int main() {
    FILE *arquivo;
    Campeao campeoes[3]; // vetor para armazenar os campeões lidos

    // Abre o arquivo binário para leitura
    arquivo = fopen("squad1.dat", "rb");
    if (arquivo == NULL) {
        printf("Erro: arquivo squad1.dat nao encontrado!\n");
        return 1; // encerra o programa com erro
    }

    // Lê os 3 campeões do arquivo de uma vez
    size_t lidos = fread(campeoes, sizeof(Campeao), 3, arquivo);
    fclose(arquivo);

    // Verifica se conseguiu ler os 3 corretamente
    if (lidos != 3) {
        printf("Erro ao ler os dados do arquivo!\n");
        return 1;
    }

    // Procura o campeão com maior vida (HP)
    int indiceTanque = 0;
    for (int i = 1; i < 3; i++) {
        if (campeoes[i].vida > campeoes[indiceTanque].vida) {
            indiceTanque = i;
        }
    }

    // Exibe o resultado
    printf("%s: Tanque do esquadrão.\n", campeoes[indiceTanque].nome);

    return 0;
}
