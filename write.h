#ifndef WRITE_H_
#define WRITE_H_

// Afiseaza continutul directorului direct (directoare si  fisiere), dar nu si
// ce se afla mai departe in aceste directoare
void ls(Dir *parent);

// Afiseaza calea de la root la directorul curent
char *pwd(Dir *target);

// Afiseaza recursiv continutul directorului direct (directoare si fisiere),
// dar si ce se afla mai departe in aceste directoare pana nu mai gaseste nimic
// in continutul directorului, cand se intoarce cu un nivel mai sus
void tree(Dir *target, int level);

#endif
