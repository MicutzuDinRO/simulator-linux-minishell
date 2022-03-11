#include "create.h"

#include "write.h"

void ls(Dir *parent) {
  Dir *cursor1 = parent->head_children_dirs;
  File *cursor2 = parent->head_children_files;

  // Afiseaza directorul actual si se muta la urmatorul
  while (cursor1 != NULL) {
    printf("%s\n", cursor1->name);
    cursor1 = cursor1->next;
  }

  // Afiseaza fisierul actual si se muta la urmatorul
  while (cursor2 != NULL) {
    printf("%s\n", cursor2->name);
    cursor2 = cursor2->next;
  }
}

char *pwd(Dir *target) {
  // Verifica daca directorul actual are parinte
  if (target->parent == NULL) {
    // Creeaza noul sir de caractere
    char *result = calloc(sizeof(char), strlen(target->name) + 2);
    strcpy(result, "/");
    strcat(result, target->name);
    return result;
  }

  // Preia rezultatul de la parinte si adauga numele directorului curent
  char *aux = pwd(target->parent);
  char *result = calloc(sizeof(char), strlen(aux) + strlen(target->name) + 2);
  strcpy(result, aux);
  strcat(result, "/");
  strcat(result, target->name);
  free(aux);
  return result;
}

void tree(Dir *target, int level) {
  Dir *dir = target->head_children_dirs;
  File *fis = target->head_children_files;

  // Afiseaza directoarele in ordinea creari acestora
  while (dir != NULL) {
    for (int i = 1; i <= level; i++)
      printf("    ");
    printf("%s\n", dir->name);
    tree(dir, level + 1);
    dir = dir->next;
  }

  // Afiseaza fisierele in ordinea creari acestora
  while (fis != NULL) {
    for (int i = 1; i <= level; i++)
      printf("    ");
    printf("%s\n", fis->name);
    fis = fis->next;
  }
}
