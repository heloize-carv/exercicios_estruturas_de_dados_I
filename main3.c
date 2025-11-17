#include <stdio.h>
#include "personagem.h"

int main() {

    int n;

    printf("Quantos membros terá a equipe? ");
    scanf("%d", &n);

    // Cria equipe
    Personagem* party = cria_party(n);

    // Registra dados dos membros
    registra_membros(party, n);

    // Exibe relatório
    exibe_relatorio(party, n);

    // Libera memória
    libera_party(party);

    return 0;
}
