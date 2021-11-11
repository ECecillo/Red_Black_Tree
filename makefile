CC=g++
CFLAGS=-Wall -O
EXEC=./bin/tp_7
OBJ_FOLDER = ./object/
OBJ_EXEC = $(OBJ_FOLDER)element.o $(OBJ_FOLDER)Noeud.o $(OBJ_FOLDER)Noeud_ARN.o $(OBJ_FOLDER)arbre.o $(OBJ_FOLDER)arbre_ARN.o $(OBJ_FOLDER)main.o 
SRC_FOLDER = ./src/
MODULE_FOLDER = ./src/module/

all: $(EXEC)

$(EXEC): $(OBJ_EXEC) 
	$(CC) -o $(EXEC) $(OBJ_EXEC)

$(OBJ_FOLDER)element.o: $(SRC_FOLDER)element.cpp
	$(CC) -o $(OBJ_FOLDER)element.o -c $(SRC_FOLDER)element.cpp $(CFLAGS)

$(OBJ_FOLDER)arbre.o: $(SRC_FOLDER)arbre.cpp $(MODULE_FOLDER)Noeud.h $(MODULE_FOLDER)element.h  
	$(CC) -o $(OBJ_FOLDER)arbre.o -c $(SRC_FOLDER)arbre.cpp $(CFLAGS)

$(OBJ_FOLDER)arbre_ARN.o: $(SRC_FOLDER)arbre_ARN.cpp $(MODULE_FOLDER)Noeud_ARN.h $(MODULE_FOLDER)element.h  
	$(CC) -o $(OBJ_FOLDER)arbre_ARN.o -c $(SRC_FOLDER)arbre_ARN.cpp $(CFLAGS)

$(OBJ_FOLDER)Noeud.o: $(SRC_FOLDER)Noeud.cpp $(MODULE_FOLDER)element.h
	$(CC) -o $(OBJ_FOLDER)Noeud.o -c $(SRC_FOLDER)Noeud.cpp $(CFLAGS)	

$(OBJ_FOLDER)Noeud_ARN.o: $(SRC_FOLDER)Noeud_ARN.cpp $(MODULE_FOLDER)element.h
	$(CC) -o $(OBJ_FOLDER)Noeud_ARN.o -c $(SRC_FOLDER)Noeud_ARN.cpp $(CFLAGS)	

$(OBJ_FOLDER)main.o: $(SRC_FOLDER)main.cpp $(MODULE_FOLDER)element.h $(MODULE_FOLDER)arbre.h $(MODULE_FOLDER)Noeud.h
	$(CC) -o $(OBJ_FOLDER)main.o -c $(SRC_FOLDER)main.cpp $(CFLAGS)




clean:
	rm -f $(OBJ_FOLDER)*.o $(EXEC)
mrproper: clean
	rm -f $(EXEC) 