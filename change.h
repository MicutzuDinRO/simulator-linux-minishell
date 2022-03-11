#ifndef CHANGE_H_
#define CHANGE_H_

#include "check_content.h"
#include "create.h"
#include "remove.h"

// Schimba directorul curent
void cd(Dir **target, char *name);

// Muta in acelasi director un director/fisier la coada listei si ii schimba
// numele
void mv(Dir *parent, char *oldname, char *newname);

#endif
