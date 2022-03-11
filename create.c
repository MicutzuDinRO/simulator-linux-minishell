#include "create.h"

void touch(Dir *parent, char *name) {
  File *fis = calloc(1, sizeof(File));
  fis->parent = parent;
  fis->name = calloc(sizeof(char), strlen(name) + 1);
  strcpy(fis->name, name);
  fis->next = NULL;

  // Verifica daca exista fisierul head in directorul parinte
  if (parent->head_children_files == NULL) {
    parent->head_children_files = fis;
    return;
  }

  File *aux = parent->head_children_files;
  while (aux != NULL) {
    // Verifica daca fisierul cu numele dat ca parametru exista deja in
    // directorul parinte
    if (strcmp(aux->name, name) == 0) {
      printf("File already exists\n");
      free(fis->name);
      free(fis);
      return;
    }

    if (aux->next == NULL) {
      aux->next = fis;
      return;
    }
    aux = aux->next;
  }
}

void mkdir(Dir *parent, char *name) {
  Dir *dir = calloc(1, sizeof(Dir));
  dir->parent = parent;
  dir->name = calloc(sizeof(char), strlen(name) + 1);
  strcpy(dir->name, name);
  dir->next = NULL;

  // Verifica daca exista directorul head in directorul parinte
  if (parent->head_children_dirs == NULL) {
    parent->head_children_dirs = dir;
    return;
  }

  Dir *aux = parent->head_children_dirs;
  while (aux != NULL) {
    // Verifica daca directorul cu numele dat ca parametru exista deja in
    // directorul parinte
    if (strcmp(aux->name, name) == 0) {
      printf("Directory already exists\n");
      free(dir->name);
      free(dir->head_children_dirs);
      free(dir->head_children_files);
      free(dir);
      return;
    }

    if (aux->next == NULL) {
      aux->next = dir;
      return;
    }
    aux = aux->next;
  }
}
