#include <stdbool.h>

typedef struct contato Contato;

typedef struct agenda Agenda;

Agenda *agenda_cria();
bool agenda_adiciona(Agenda *agenda, char *nome, char *telefone);
int agenda_find(Agenda *agenda, char *nome);
Contato *agenda_get(Agenda *agenda, int pos);
void agenda_set(Agenda *agenda, int pos, Contato *contato);
bool agenda_troca(Agenda *agenda, int x, int y);
void agenda_mover_para_final(Agenda *agenda, int pos);
Contato *agenda_remove(Agenda *agenda, int pos);
void agenda_limpa(Agenda *agenda);
bool agenda_alterar_nome(Agenda *agenda, int pos, char *novo_nome);
bool agenda_alterar_telefone(Agenda *agenda, int pos, char *novo_telefone);
