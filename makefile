CFLAGS = -O2 -Wall -g 
CC = gcc
LDLIBS = -lX11 -lm

vpath %.o obj/
vpath %.c src/
vpath %.h include/
vpath genlab /bin
vpath cheminlab /bin

all : genlab cheminlab


cheminlab : main2.o  matrice.o chemin.o 
	gcc $(CFLAGS) -o $@ obj/main2.o obj/matrice.o obj/chemin.o $(LDLIBS)
	mv $@ bin/.

genlab : main1.o ensemble.o matrice.o labyrinthe.o graph.o sort.o 
	$(CC) $(CFLAGS) -o $@ obj/main1.o obj/ensemble.o obj/matrice.o obj/labyrinthe.o obj/graph.o $(LDLIBS)
	mv $@ bin/.

main1.o : ensemble.h matrice.h labyrinthe.h graph.h sort.o

main2.o : matrice.h chemin.h 

ensemble.o : ensemble.h 

matrice.o : matrice.h ensemble.h

labyrinthe.o : labyrinthe.h ensemble.h matrice.h graph.h sort.h

graph.o : graph.h 

chemin.o : chemin.h ensemble.h matrice.h graph.h

sort.o : sort.h

%.o : %.c
	$(CC) $(CFLAGS) -c $< -Iinclude $(LDLIBS)
	mv $@ obj/

clean :
	rm -rf obj/*.o bin/* genlab cheminlab


archive :
	tar -f labyrinthe_Serradj_Tourki.tar.gz -cvz src/*.c include/*.h makefile Readme.txt bin/ obj/
