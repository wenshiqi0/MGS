INCLUDE := ./include
LIB := ./lib
SRC := ./src
LIBUV := uv
LIBNAME := uvhash
MAIN := .
OUT := .
CC := gcc

edit:hashTable.o hashData.o hashDB.o hashUvData.o libuvhash.a out

hashTable.o:$(SRC)/hashTable.c $(INCLUDE)/hashTable.h $(INCLUDE)/header.h
	$(CC) -c $(SRC)/hashTable.c -o $(LIB)/hashTable.o

hashData.o:$(SRC)/hashData.c $(INCLUDE)/hashData.h $(INCLUDE)/hashTable.h $(INCLUDE)/header.h
	$(CC) -c $(SRC)/hashData.c -o $(LIB)/hashData.o

hashUvData.o:$(SRC)/hashUvData.c $(INCLUDE)/hashUvData.h $(INCLUDE)/hashTable.h $(INCLUDE)/header.h
	$(CC) -c $(SRC)/hashUvData.c -o $(LIB)/hashUvData.o

hashDB.o:$(INCLUDE)/hashTable.h $(INCLUDE)/hashData.h $(INCLUDE)/header.h $(SRC)/hashDB.c
	$(CC) -c $(SRC)/hashDB.c -o $(LIB)/hashDB.o

libuvhash.a:$(LIB)/hashTable.o $(LIB)/hashData.o $(LIB)/hashDB.o $(LIB)/hashUvData.o
	ar rc $(LIB)/libuvhash.a $(LIB)/hashTable.o $(LIB)/hashData.o $(LIB)/hashDB.o $(LIB)/hashUvData.o

out:$(LIB)/libuvhash.a $(MAIN)/main.c $(INCLUDE)/hashData.h $(INCLUDE)/hashUvData.h $(INCLUDE)/hashTable.h $(INCLUDE)/hashDB.h $(INCLUDE)/header.h
	$(CC) $(MAIN)/main.c -o $(OUT)/out -L $(LIB) -l$(LIBNAME) -l$(LIBUV)
