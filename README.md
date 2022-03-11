Nume: Alexandru Micu
Grupa: 321CC
Tema: Sistemul lui Biju

/*****************************************************************************/

*Biblioteca create.h
    - Defineste structurile de date pentru fisiere si directoare date
    - Tot restul fisierelor se folosesc de structurile de date definite aici
    - Functia touch: Creeaza un fisier si il adauga in directorul curent din
                     structura data
    - Functia mkdir: Creeaza un director si il adauga in directorul curent din
                     structura data


*Biblioteca check_content.h
    - Functia check_file: Verifica daca exista in directorul curent un fisier
                          cu numele dat ca parametrul functiei
    - Functia check_dir: Verifica daca exista in directorul curent un director
                         cu numele dat ca parametrul functiei

*Biblioteca free.h
    - Functia free_file: Sterge din memorie fisierul dat ca parametru aflat
                         in directorul curent
    - Functia free_all_files: Sterge recursiv toate fisierele create si ramase
                              in memorie
    - Functia free_all_dirs: Sterge recursiv toate directoarele si continutul
                             acestora create si ramase in memorie
    - Functia free_dir: Sterge din memorie directorul si tot continul aflat in 
                        acesta, director dat ca parametru aflat in directorul
                        curent
    - Functia stop: Opreste citirea comenzilor, elibereaza memoria alocata
                    structurilor de directoare si fisiere ramase si opreste
                    executia programului

*Biblioteca write.h
    - Functia ls: Afiseaza continutul directorului direct (directoare si 
                  fisiere), dar nu si ce se afla mai departe in aceste
                  directoare
    - Functia pwd: Afiseaza calea de la root la directorul curent
    - Functia tree: Afiseaza recursiv continutul directorului direct 
                    (directoare si fisiere), dar si ce se afla mai departe in 
                    aceste directoare pana nu mai gaseste nimic in continutul
                    directorului, cand se intoarce cu un nivel mai sus

*Biblioteca remove.h
    - Se foloseste de functiile din biblioteca free.h:
        - free_file
        - free_dir
    - Functia rm: Sterge din memorie fisierul cu numele dat ca parametru din
                  directorul curent
    - Functia rmdir: Sterge din memorie directorul cu numele dat ca parametru 
                     din directorul curent

*Biblioteca change.h
    - Se foloseste de functiile din biblioteca check_content.h:
        - check_file
        - check_dir
    - Se foloseste de functiile din biblioteca remove.h:
    - Functia cd: Schimba directorul curent
    - Functia mv: Muta in acelasi director un director/fisier la coada listei
                  si ii schimba numele

*Fisierul tema1.c
    - Se foloseste de toate bibliotecile de mai sus
    - Realizeaza comenzile date de utilizator prin stdin
    - Functia read: Citeste linia data de utilizator, o imparte dupa space si
                    efectueaza operatia corespunzatoare primului parametru
                    cu urmatorii doi parametrii folositi eventual in apelul
                    functiei corespunzatoare operatiei
    - Functia commands: Apeleaza functia corespunzatoare operatiei dupa primul
                        parametru
