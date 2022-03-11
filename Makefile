CC = gcc
CCFLAGS = -g -Wall

.PHONY: clean

build: main.c create.o change.o check_content.o free.o remove.o write.o
	$(CC) $(CCFLAGS) main.c create.o change.o check_content.o free.o remove.o write.o -o main

create: create.c create.h
	$(CC) $(CCFLAGS) create.c create.h -o create.o

check_content: check_content.c check_content.h create.o
	$(CC) $(CCFLAGS) check_content.c check_content.h create.o -o check_content.o

free: free.c free.h create.o
	$(CC) $(CCFLAGS) free.c free.h create.o -o free.o

remove: remove.c remove.h create.o free.o
	$(CC) $(CCFLAGS) remove.c remove.h create.o free.o -o remove.o

change: change.c change.h create.o check_content.o remove.o
	$(CC) $(CCFLAGS) change.c change.h create.o check_content.o remove.o -o change.o

write: write.c write.h create.o
	$(CC) $(CCFLAGS) write.c write.h create.o -o write.o

memcheck:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./main

clean:
	rm -f *.o
	rm -f main