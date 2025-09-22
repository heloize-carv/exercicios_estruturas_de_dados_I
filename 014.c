#include <stdio.h>
#include <locale.h>
#include <string.h>

// O Diálogo do Final Boss

int main () {
    setlocale(LC_ALL, "Portuguese_Brazil");

    // Frase padrão do chefe
    char frase_inicio_luta[] = "Você nunca sairá daqui com vida!";

    // Caixa de diálogo da tela
    char caixa_dialogo[100] = "(Silêncio)";

    // Estado inicial da caixa de diálogo
    printf("Chefe antes da luta: %s\n", caixa_dialogo);

    // Copiando a fala do chefe para a caixa de diálogo
    strcpy(caixa_dialogo, frase_inicio_luta);

    // Estado após ativar o diálogo
    printf("Chefe diz: %s\n", caixa_dialogo);

    return 0;
}