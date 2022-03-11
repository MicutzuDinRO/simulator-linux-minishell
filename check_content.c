#include "create.h"

#include "check_content.h"

int check_file(Dir *parent, char *name) {
  File *check = parent->head_children_files;
  while (check != NULL) {
    if (strcmp(check->name, name) == 0)
      return 1;
    check = check->next;
  }
  return 0;
}

int check_dir(Dir *parent, char *name) {
  Dir *check = parent->head_children_dirs;
  while (check != NULL) {
    if (strcmp(check->name, name) == 0)
      return 1;
    check = check->next;
  }
  return 0;
}
