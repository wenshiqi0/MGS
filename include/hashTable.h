#ifndef _HASH_TABLE_h_
#define _HASH_TABLE_h_

#include "header.h"

typedef struct HashNode{
  char *key;
  char *value;
}HashNode;

typedef struct HashTable{
  unsigned int size;
  HashNode **array;
}HashTable;

#define HASH_NODE_SIZE sizeof(HashNode)
#define HASH_TABLE_SIZE sizeof(HashTable)

extern HashTable *initHashTable(unsigned int size);

extern int freeHashTable(HashTable *table);

extern int freeHashNode(HashNode *node);

extern int setHashTableValue(HashTable *table,char *key,char *value);

extern int setHashTableHashNode(HashTable *table,HashNode* node);

extern char *getHashTableValue(HashTable *table,char *key);

extern HashNode *getHashTableHashNode(HashTable *table,char *key);

extern unsigned int classicHash(char *str);

#endif
