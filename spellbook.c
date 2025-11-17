#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "spellbook.h"

Spellbook* create_spellbook() {
    Spellbook *book = (Spellbook*) malloc(sizeof(Spellbook));
    book->start = NULL;
    return book;
}

void add_spell(Spellbook* book, int id, const char* name, int mana_cost) {
    Node *novo = (Node*) malloc(sizeof(Node));
    novo->spell.id = id;
    strcpy(novo->spell.name, name);
    novo->spell.mana_cost = mana_cost;
    novo->next = NULL;

    if (book->start == NULL) {
        book->start = novo;
    } else {
        Node *p = book->start;
        while (p->next != NULL)
            p = p->next;
        p->next = novo;
    }
}

void display_spellbook(Spellbook* book) {
    Node *p = book->start;
    while (p != NULL) {
        printf("ID: %d, Feitico: %s, Custo de Mana: %d\n",
               p->spell.id, p->spell.name, p->spell.mana_cost);
        p = p->next;
    }
}

void destroy_spellbook(Spellbook* book) {
    Node *p = book->start;
    while (p != NULL) {
        Node *temp = p;
        p = p->next;
        free(temp);
    }
    free(book);
}
