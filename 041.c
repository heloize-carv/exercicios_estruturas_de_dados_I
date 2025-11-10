#include <stdio.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, ""); // permite acentuação no Windows, por exemplo

    int opcao;
    char evento[100]; // espaço para armazenar a descrição do evento
    FILE *arquivo;

    do {
        printf("\nMenu:\n1 - Registrar novo evento\n2 - Sair\nEscolha: ");
        scanf("%d", &opcao);

        if(opcao == 1) {
            printf("Digite o evento (sem espacos): ");
            scanf("%s", evento);

            // abrir arquivo em modo append (adicionar ao final)
            arquivo = fopen("game_log.txt", "a");
            if (arquivo == NULL) {
                printf("Erro ao abrir o arquivo!\n");
                return 1;
            }

            fprintf(arquivo, "%s\n", evento); // escreve o evento no arquivo
            fclose(arquivo); // fecha o arquivo

            printf("Evento registrado com sucesso!\n");
        }

    } while(opcao != 2);

    printf("Programa encerrado.\n");
    return 0;
}
