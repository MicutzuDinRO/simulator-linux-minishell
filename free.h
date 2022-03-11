#ifndef FREE_H_
#define FREE_H_

#include "create.h"

// Sterge din memorie fisierul dat ca parametru aflat in directorul curent
void free_file(File *target);

// Sterge recursiv toate fisierele create si ramase in memorie
void free_all_files(File *target);

// Sterge recursiv toate directoarele si continutul acestora create si ramase
// in memorie
void free_all_dirs(Dir *target);

// Sterge din memorie directorul si tot continul aflat in acesta, director dat
// ca parametru aflat in directorul curent
void free_dir(Dir *target);

// Opreste citirea comenzilor, elibereaza memoria alocata structurilor de
// directoare si fisiere ramase si opreste executia programului
void stop(Dir *target);

#endif
