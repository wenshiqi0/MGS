#include "hashDB.h"

int hashDbInsert(HashData *data,HashTable *table,char *key,char *value){
  HashNode *node = (HashNode *)malloc(MAX_VALUE_BYTE*BYTE_SIZE);
  node->key = key;
  node->value = value;

  setHashTableHashNode(table,node);
  saveOneKeyValue(data,key,value);

  return 1;
}

int hashDbFind(HashData *data,HashTable *table,char *key,char *value){
  int ret = findOneKeyValue(data,key,value);

  if(!ret){
    return 0;
  }

  return 1;
}
