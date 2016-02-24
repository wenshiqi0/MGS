#include "hashTable.h"

//Hash Define
static unsigned long phpStrHash(char *arKey, unsigned int nKeyLength);
unsigned int classicHash(char *str);

#define Hash(X) classicHash(X)%MAX_PACKEGE

HashTable *initHashTable(){
  HashTable *table = (HashTable *)malloc(HASH_TABLE_SIZE);
  if(NULL == table){
    printf("malloc failed\n");
    exit(0);
  }

  table->size = MAX_PACKEGE;
  table->array = (HashNode **)malloc(sizeof(HashNode *)*MAX_PACKEGE);
  if(NULL == table->array){
    printf("malloc failed\n");
    exit(0);
  }
  memset(table->array,0,MAX_PACKEGE*sizeof(HashNode *));

  return table;
}

int freeHashTable(HashTable *table){
  for(int i=0;i<MAX_PACKEGE;i++){
    if(NULL != table->array[i]){
      freeHashNode(table->array[i]);
    }
  }
  free(table->array);
  table->array = NULL;
  free(table);
  table = NULL;
  return 1;
}

int freeHashNode(HashNode *node){
  if(node == NULL){
    return 1;
  }
  free(node);
  node = NULL;
  return 1;
}

int setHashTableValue(HashTable *table,char *key,char *value){
  HashNode *node = (HashNode *)malloc(sizeof(HashNode));
  if(NULL == node){
    printf("node malloc failed\n");
    return 0;
  }
  node->key = key;
  node->value = value;

  if(NULL == value){
    printf("can not set a NULL value for key:%s\n",key);
    return 0;
  }
  
  table->array[Hash(key)] = node;

  return 1;
}

int setHashTableHashNode(HashTable *table,HashNode* node){
  if(NULL == node || NULL == node->value){
    printf("can not set an empty node\n");
    return 0;
  }
  if(NULL == node->key){
    printf("key can not be NULL\n");
    return 0;
  }

  table->array[Hash(node->key)] = node;

  return 1;
}

char *getHashTableValue(HashTable *table,char *key){
  HashNode *node = table->array[Hash(key)];
  if(!node){
    return NULL;
  }
  return node->value;
}

HashNode *getHashTableHashNode(HashTable *table,char *key){
  HashNode *node = table->array[Hash(key)];
  if(!node || !node->value){
    return NULL;
  }
  return node;
}

//Hash Function
static unsigned long phpStrHash(char *arKey, unsigned int nKeyLength)
{
    unsigned long h = 0, g;
    char *arEnd=arKey+nKeyLength;

    while (arKey < arEnd) {
        h = (h << 4) + *arKey++;
        if ((g = (h & 0xF0000000))) {
            h = h ^ (g >> 24);
            h = h ^ g;
        }
    }

    return h;
}

unsigned int classicHash(char *str)
{
    register unsigned int h;
    register unsigned char *p;

    for(h=0, p = (unsigned char *)str; *p ; p++)
        h = 31 * h + *p;

    return h;
}
