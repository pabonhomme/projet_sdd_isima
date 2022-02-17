CC=gcc
CFLAGS=-Wextra -Wall
LDFLAGS=
EXEC=projet

all: $(EXEC)

projet: main.o semaine.o jour.o action.o
	$(CC) -o $@ $^ $(LDFLAGS)
	@echo "\nLancer le programme avec ./projet semaines.txt"

action.o: action.c action.h
	$(CC) -o $@ -c $< $(CFLAGS)

semaine.o: semaine.c semaine.h
	$(CC) -o $@ -c $< $(CFLAGS)

jour.o: jour.c jour.h
	$(CC) -o $@ -c $< $(CFLAGS)

main.o: main.c jour.h
	$(CC) -o $@ -c $< $(CFLAGS) 

clean:
	rm -rf *.o

rmExec: clean
	rm -rf $(EXEC)

