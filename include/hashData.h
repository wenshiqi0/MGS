#ifndef _HASH_DATA_H_
#define _HASH_DATA_H_

#include "hashTable.h"
#include "header.h"

typedef struct HashData{
  FILE *file;
}HashData;

extern HashData *openHashFile(char *filename);

extern int closeHashFile(HashData *data);

extern int saveOneHashNode(HashData *data,HashNode *node);
extern int saveOneKeyValue(HashData *data,char *key,char *value);

extern int findOneHashNode(HashData *data,HashNode *node);
extern int findOneKeyValue(HashData *data,char *key,char *value);

#endif
