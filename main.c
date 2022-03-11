#include "change.h"
#include "check_content.h"
#include "create.h"
#include "free.h"
#include "remove.h"
#include "write.h"

#define MAX_INPUT_LINE_SIZE 300

void read(Dir *home, char *line, char **param) {
  fgets(line, MAX_INPUT_LINE_SIZE + 1, stdin);
  if (strcmp(line, "stop\n") == 0) {
    free(param[0]);
    free(param[1]);
    free(param[2]);
    free(line);
    stop(home);
  }

  int i;
  i = 0;
  char *help = strtok(line, " \n");
  while (help != NULL && i < 3) {
    strcpy(param[i], help);
    i++;
    help = strtok(NULL, " \n");
  }
}

void commands(Dir **parent, char **param) {
    if (strcmp(param[0], "touch") == 0) {
      touch(*parent, param[1]);
      return;
    }

    if (strcmp(param[0], "mkdir") == 0) {
      mkdir(*parent, param[1]);
      return;
    }

    if (strcmp(param[0], "ls") == 0) {
      ls(*parent);
      return;
    }

    if (strcmp(param[0], "rm") == 0) {
      rm(*parent, param[1]);
      return;
    }

    if (strcmp(param[0], "rmdir") == 0) {
      rmdir(*parent, param[1]);
      return;
    }

    if (strcmp(param[0], "cd") == 0) {
      cd(parent, param[1]);
      return;
    }

    if (strcmp(param[0], "pwd") == 0) {
      char *aux = pwd(*parent);
      printf("%s\n", aux);
      free(aux);
      return;
    }

    if (strcmp(param[0], "tree") == 0) {
      tree(*parent, 0);
      printf("\n");
      return;
    }
    
    if (strcmp(param[0], "mv") == 0) {
      mv(*parent, param[1], param[2]);
      return;
    }
}

int main(void) {
  char *line = malloc(sizeof(char) * (MAX_INPUT_LINE_SIZE + 2));

  Dir *home = calloc(1, sizeof(Dir));
  home->name = calloc(sizeof(char), 5);
  strcpy(home->name, "home");
  home->parent = NULL;

  Dir *parent;
  parent = home;
  
  char *param[3];
  param[0] = calloc(sizeof(char), MAX_INPUT_LINE_SIZE);
  param[1] = calloc(sizeof(char), MAX_INPUT_LINE_SIZE);
  param[2] = calloc(sizeof(char), MAX_INPUT_LINE_SIZE);

  do {
    read(home, line, param);
    commands(&parent, param);
  } while (1);

  return 0;
}
