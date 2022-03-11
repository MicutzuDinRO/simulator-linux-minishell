#ifndef CHECK_CONTENT_H_
#define CHECK_CONTENT_H_

#include "create.h"

// Verifica daca exista in directorul curent un fisier cu numele dat ca
// parametrul functiei
int check_file(Dir *parent, char *name);

// Verifica daca exista in directorul curent un director cu numele dat ca
// parametrul functiei
int check_dir(Dir *parent, char *name);

#endif
