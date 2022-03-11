#ifndef CREATE_H_
#define CREATE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Dir;
struct File;

typedef struct Dir {
  char *name;
  struct Dir *parent;
  struct File *head_children_files;
  struct Dir *head_children_dirs;
  struct Dir *next;
} Dir;

typedef struct File {
  char *name;
  struct Dir *parent;
  struct File *next;
} File;

// Creeaza un fisier si il adauga in directorul curent din structura data
void touch(Dir *parent, char *name);

// Creeaza un director si il adauga in directorul curent din structura data
void mkdir(Dir *parent, char *name);

#endif
