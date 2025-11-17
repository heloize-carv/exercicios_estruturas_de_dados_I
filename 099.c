#include <stdio.h>
#include "spellbook.h"

int main() {
    Spellbook *book = create_spellbook();

    add_spell(book, 1, "Bola de Fogo", 30);
    add_spell(book, 2, "Seta Arcana", 12);
    add_spell(book, 3, "Tempestade de Gelo", 50);

    display_spellbook(book);

    destroy_spellbook(book);
    return 0;
}
