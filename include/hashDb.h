#ifndef _HASH_DB_H_
#define _HASH_DB_H_

#include "header.h"
#include "hashData.h"
#include "hashTable.h"

extern int hashDbInsert(HashData *data,HashTable *table,char *key,char *value);

extern int hashDbFind(HashData *data,HashTable *table,char *key,char *value);

#endif
