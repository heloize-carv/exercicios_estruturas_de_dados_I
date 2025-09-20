#include <stdio.h>

int str_len(char *s) {
    int cont;
    for (cont = 0; *s != '\0'; s++) {
        cont++;
    }
    return cont;
}

int main() {
    char nome[100];
    int cont;

    printf("Informe seu nome completo: ");
    gets(nome); 

    cont = str_len(nome);

    printf("O nome (%s) tem %d caracteres\n", nome, cont);

    return 0;
}
