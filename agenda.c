#include "agenda.h"
#include <stdbool.h>
#include <stdlib.h>

struct contato {
  char *nome;
  char *telefone;
};

struct agenda {
  int tamanho;
  Contato contatos[];
};

Agenda *agenda_cria() {
  Agenda *agenda = (Agenda *)malloc(sizeof(Agenda));
  agenda->tamanho = 0;

  return agenda;
};

Contato *contato_cria(char *nome, char *telefone) {
  Contato *contato = (Contato *)malloc(sizeof(Contato));

  if (contato == NULL) {
    return contato;
  }

  contato->nome = nome;
  contato->telefone = telefone;

  return contato;
};

bool agenda_adiciona(Agenda *agenda, char *nome, char *telefone) {
  Contato *novo_contato = contato_cria(nome, telefone);

  if (novo_contato == NULL) {
    return false;
  }

  int novo_tamanho = agenda->tamanho + 1;
  Contato *contatos = (Contato *)realloc(agenda->contatos, sizeof(novo_tamanho));

  if (contatos == NULL) {
    return false;
  }

  agenda->tamanho = novo_tamanho;
  agenda->contatos[agenda->tamanho - 1] = *novo_contato;

  return true;
};

Contato *agenda_get(Agenda *agenda, int pos) { return &agenda->contatos[pos]; }

void agenda_set(Agenda *agenda, int pos, Contato *contato) { agenda->contatos[pos] = *contato; }

bool agenda_troca(Agenda *agenda, int x, int y) {
  Contato *contato1 = agenda_get(agenda, x);
  Contato *contato2 = agenda_get(agenda, x);

  if (contato1 == NULL || contato2 == NULL) {
    return false;
  }

  agenda_set(agenda, x, contato2);
  agenda_set(agenda, y, contato1);

  return true;
}

void agenda_mover_para_final(Agenda *agenda, int pos) {}

Contato *agenda_remove(Agenda *agenda, int pos) {
  if (agenda->tamanho == 0 || pos < 0 || pos > agenda->tamanho - 1) {
    return NULL;
  }

  agenda_mover_para_final(agenda, pos);

  Contato *contato = agenda_get(agenda, agenda->tamanho - 1);

  free(contato);

  agenda->tamanho--;
  Contato *contatos = (Contato *)realloc(agenda->contatos, sizeof(agenda->tamanho));

  return contato;
};

bool agenda_alterar_nome(Agenda *agenda, int pos, char *nome) {
  Contato *contato = (Contato *)agenda_get(agenda, pos);

  if (contato == NULL) {
    return false;
  }

  contato->nome = nome;

  return true;
};

bool agenda_alterar_telefone(Agenda *agenda, int pos, char *novo_telefone) {
  Contato *contato = (Contato *)agenda_get(agenda, pos);

  if (contato == NULL) {
    return false;
  }

  contato->telefone = novo_telefone;

  return true;
}

void agenda_limpa(Agenda *agenda) {
  for (int i = agenda->tamanho - 1; i >= 0; i++) {
    agenda_remove(agenda, i);
  }
};

int main() { return 0; }
