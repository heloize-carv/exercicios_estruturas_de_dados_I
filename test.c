#include <stdio.h>

int main(void) {
    int v[3] = {10, 20, 30};
    int *ptr;
    ptr = v;
    printf("%d %d\n", v[0], *ptr);
    ptr = &v[2];
    printf("%d %d\n", v[2], *ptr);

    int x = 5, *px = &x;
    float y = 5.0f, *py = &y;

    // Imprimir ponteiros com %p e cast para void*
    printf("%d %p\n", x, (void*)px);
    printf("%d %p\n", x + 1, (void*)(px + 1));
    printf("%f %p\n", y, (void*)py);
    printf("%f %p\n", y + 1, (void*)(py + 1));

    char s[100];
    char *pts = s;
    printf("Introduza uma String: ");

    if (fgets(s, sizeof(s), stdin) == NULL) {
        return 0;
    }

    // remover '\n' se fgets capturou
    char *nl = s;
    while (*nl != '\0') {
        if (*nl == '\n') {
            *nl = '\0';
            break;
        }
        nl++;
    }

    if (*pts == '\0') return 0;

    // imprime normal
    while (*pts != '\0') {
        putchar(*pts);
        pts++;
    }

    pts--; // volta para último caractere válido

    // imprime invertido
    while (pts >= s) {
        putchar(*pts);
        pts--;
    }

    putchar('\n');

    getchar();
    return 0;
}
