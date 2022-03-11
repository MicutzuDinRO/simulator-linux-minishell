#include "create.h"
#include "free.h"

#include "remove.h"

void rm(Dir *parent, char *name) {
  File *cursor = parent->head_children_files;
  File *aux;

  // Verifica daca directorul are fisiere
  if (cursor == NULL) {
    printf("Could not find the file\n");
    return;
  }

  // Verifica daca fisierul care trebuie sters e head-ul listei
  if (strcmp(cursor->name, name) == 0) {
    parent->head_children_files = cursor->next;
    free_file(cursor);
    return;
  }

  // Verifica daca exista un al doilea fisier in director
  if (cursor->next == NULL) {
    printf("Could not find the file\n");
    return;
  }

  // Verifica daca exista fisierul in directorul cu mai mult de 2 fisiere
  aux = cursor->next;
  while (aux->next != NULL) {
    if (strcmp(aux->name, name) == 0) {
      cursor->next = cursor->next->next;
      free_file(aux);
      return;
    }
    cursor = cursor->next;
    aux = aux->next;
  }

  // Verifica daca fisierul actual este cel care trebuie sters
  if (strcmp(aux->name, name) == 0) {
    cursor->next = NULL;
    free_file(aux);
    return;
  }

  printf("Could not find the file\n");
}

void rmdir(Dir *parent, char *name) {
  Dir *cursor = parent->head_children_dirs;
  Dir *aux;

  // Verifica daca directorul are alte directoare
  if (cursor == NULL) {
    printf("Could not find the dir\n");
    return;
  }

  // Verifica daca directorul care trebuie sters e head-ul listei
  if (strcmp(cursor->name, name) == 0) {
    parent->head_children_dirs = cursor->next;
    free_dir(cursor);
    return;
  }

  // Verifica daca exista un al doilea director in directorul parinte
  if (cursor->next == NULL) {
    printf("Could not find the dir\n");
    return;
  }

  // Verifica daca exista directorul in directorul parinte cu mai mult de
  // 2 directoare
  aux = cursor->next;
  while (aux->next != NULL) {
    if (strcmp(aux->name, name) == 0) {
      cursor->next = cursor->next->next;
      free_dir(aux);
      return;
    }
    cursor = cursor->next;
    aux = aux->next;
  }

  // Verifica daca directorul actual este cel care trebuie sters
  if (strcmp(aux->name, name) == 0) {
    cursor->next = NULL;
    free_dir(aux);
    return;
  }

  printf("Could not find the dir\n");
}
