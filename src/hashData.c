#include "hashData.h"

HashData *openHashFile(char *filename){
  HashData *data = (HashData *)malloc(sizeof(HashData));
  data->file = NULL;
  data->file = fopen(filename,"rb+");
  if(NULL == data->file){
    printf("no data.db this file,create a new one\n");
    fclose(fopen(filename,"w"));
    data->file = fopen(filename,"rb+");
  }
  return data;
}

int saveOneHashNode(HashData *data,HashNode *node){
  unsigned int offset = classicHash(node->key)%MAX_PACKEGE;
  if(NULL == node->value){
    printf("can not save a NULL value\n");
    return 0;
  }

  fseek(data->file,offset*MAX_VALUE_BYTE,SEEK_SET);
  fwrite(node->value,MAX_VALUE_BYTE,1,data->file);
  return 1;
}

int saveOneKeyValue(HashData *data,char *key,char *value){
  HashNode node;
  node.key = key;
  node.value = value;
  return saveOneHashNode(data,&node);
}

int findOneHashNode(HashData *data,HashNode *node){
  unsigned int offset = classicHash(node->key)%MAX_PACKEGE;
  if(NULL == node->value || NULL == node || NULL == node->key){
    printf("can not find a NULL HashNode\n");
  }
  fseek(data->file,offset*MAX_VALUE_BYTE,SEEK_SET);
  fread(node->value,MAX_VALUE_BYTE,1,data->file);
  if(strcmp(node->value,"") == 0){
    return 0;
  }
  return 1;
}

int findOneKeyValue(HashData *data,char *key,char *value){
  HashNode node;
  node.key = key;
  node.value = value;

  int ret = findOneHashNode(data,&node);
  return ret;
}

int closeHashFile(HashData *data){
  fclose(data->file);
  data->file = NULL;
  return 1;
}
