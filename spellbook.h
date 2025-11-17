#ifndef SPELLBOOK_H
#define SPELLBOOK_H

typedef struct {
    int id;
    char name[50];
    int mana_cost;
} Spell;

typedef struct Node {
    Spell spell;
    struct Node *next;
} Node;

typedef struct {
    Node *start;
} Spellbook;

Spellbook* create_spellbook();
void add_spell(Spellbook* book, int id, const char* name, int mana_cost);
void display_spellbook(Spellbook* book);
void destroy_spellbook(Spellbook* book);

#endif
