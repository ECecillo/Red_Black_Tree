CC=g++
CFLAGS=-Wall -O
LDFLAGS=
EXEC=./bin/arbre_exec

all: $(EXEC)

./bin/arbre_exec: ./object/element.o ./object/Noeud.o ./object/arbre.o ./object/main.o 
	$(CC) -o $(EXEC) ./object/element.o ./object/Noeud.o ./object/arbre.o ./object/main.o

./object/element.o: ./src/element.cpp
	$(CC) -o ./object/element.o -c ./src/element.cpp $(CFLAGS)

./object/arbre.o: ./src/arbre.cpp ./src/module/Noeud.h ./src/module/element.h  
	$(CC) -o ./object/arbre.o -c ./src/arbre.cpp $(CFLAGS)

./object/Noeud.o: ./src/Noeud.cpp ./src/module/element.h
	$(CC) -o ./object/Noeud.o -c ./src/Noeud.cpp $(CFLAGS)	

./object/main.o: ./src/main.cpp ./src/module/element.h ./src/module/arbre.h ./src/module/Noeud.h
	$(CC) -o ./object/main.o -c ./src/main.cpp $(CFLAGS)

clean:
	rm -f ./object/*.o core
mrproper: clean
	rm -f $(EXEC)