#ifndef REMOVE_H_
#define REMOVE_H_

#include "create.h"
#include "free.h"

// Sterge din memorie fisierul cu numele dat ca parametru din directorul curent
void rm(Dir *parent, char *name);

// Sterge din memorie directorul cu numele dat ca parametru din directorul
// curent
void rmdir(Dir *parent, char *name);

#endif
