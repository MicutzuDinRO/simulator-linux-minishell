#include "create.h"

#include "free.h"

void free_file(File *target) {
  // Verifica daca exista fisierul
  if (target == NULL)
    return;

  free(target->name);
  free(target);
}

void free_all_files(File *target) {
  // Verifica daca exista fisierul
  if (target == NULL)
    return;

  // Verifica daca exista urmatorul fisier in lista creata
  if (target->next != NULL)
    free_all_files(target->next);

  free(target->name);
  free(target);
}

void free_all_dirs(Dir *target) {
  // Verifica daca exista directorul
  if (target == NULL)
    return;

  // Verifica daca exista urmatorul fisier in lista creata
  if (target->next != NULL)
    free_all_dirs(target->next);

  // Sterge continutul directorului
  free_all_files(target->head_children_files);
  free_all_dirs(target->head_children_dirs);
  free(target->name);
  free(target);
}

void free_dir(Dir *target) {
  // Verifica daca exista directorul
  if (target == NULL)
    return;

  // Sterge continutul directorului
  free_all_files(target->head_children_files);
  free_all_dirs(target->head_children_dirs);
  free(target->name);
  free(target);
}

void stop(Dir *target) {
  fclose(stdin);
  free_all_dirs(target);
  exit(0);
}
