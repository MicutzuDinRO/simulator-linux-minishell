#include "check_content.h"
#include "create.h"
#include "remove.h"

#include "change.h"

void cd(Dir **target, char *name) {
  // Daca parametrul nume este .. se duce la parintele directorului daca nu
  // este NULL. Daca este parintele NULL ramane in acelasi director
  if (strcmp(name, "..") == 0) {
    if ((*target)->parent != NULL)
      *target = (*target)->parent;
    return;
  }

  Dir *cursor = (*target)->head_children_dirs;

  // Cauta directorul cu numele dat ca parametru si cand il gaseste schimba
  // directorul initial cu cel final si termina functia
  while (cursor != NULL) {
    if (strcmp(cursor->name, name) == 0) {
      *target = cursor;
      return;
    }
    cursor = cursor->next;
  }

  // Nu a gasit niciun director cu numele dat ca parametru, da mesaj de eroare
  printf("No directories found!\n");
}

void mv(Dir *parent, char *oldname, char *newname) {
  Dir *cursor = parent->head_children_dirs;
  Dir *aux = parent->head_children_dirs;

  // Verifica daca in continutul directorului parinte se afla un director sau
  // fisier cu numele dat initial
  if (check_file(parent, oldname) == 0 && check_dir(parent, oldname) == 0) {
    printf("File/Director not found\n");
    return;
  }

  // Verifica daca numele final nu este deja folosit in directorul parinte de
  // catre un director sau un fisier
  if (check_file(parent, newname) == 1 || check_dir(parent, newname) == 1) {
    printf("File/Director already exists\n");
    return;
  }

  // Sterge fisierul initial si creeaza unul nou cu nume final
  if (check_file(parent, oldname) == 1) {
    rm(parent, oldname);
    touch(parent, newname);
    return;
  }

  // Verifica daca directorul are mai multe directoare in continut.
  // Daca nu, doar schimba numele directorului
  if (parent->head_children_dirs->next == NULL) {
    parent->head_children_dirs->name = realloc(
        parent->head_children_dirs->name, sizeof(char) * (strlen(newname) + 1));
    strcpy(parent->head_children_dirs->name, newname);
    return;
  }

  while (aux->next != NULL)
    aux = aux->next;

  // Verifica daca directorul de mutat este directorul head
  if (strcmp(cursor->name, oldname) == 0) {
    cursor = parent->head_children_dirs->next;
    aux->next = parent->head_children_dirs;
    aux->next->next = NULL;
    aux->next->name =
        realloc(aux->next->name, sizeof(char) * (strlen(newname) + 1));
    strcpy(aux->next->name, newname);
    parent->head_children_dirs = cursor;
    return;
  }

  // Cauta directorul cu numele vechi dat, il muta la finalul listei si
  // ii schimba numele
  Dir *help = cursor->next;
  while (strcmp(help->name, oldname) != 0) {
    help = help->next;
    cursor = cursor->next;
  }
  cursor->next = cursor->next->next;
  aux = help;
  aux->name = realloc(aux->name, sizeof(char) * (strlen(newname) + 1));
  strcpy(aux->name, newname);
}
