#include "hashUvData.h"

void asyncOpenHashFile(uv_fs_t *req,const char *file,uv_fs_cb cb){
  uv_fs_open(uv_default_loop(),req,file,O_RDWR,0,cb);
}

void asyncCloseHashFile(uv_fs_t *req,uv_file file,uv_fs_cb cb){
  uv_fs_close(uv_default_loop(),req,file,cb);
}

void asyncSaveOneHashNode(uv_fs_t *req,HashNode *node,uv_file file,uv_fs_cb cb){
  unsigned int offset = classicHash(node->key)%MAX_PACKEGE;
  if(NULL == node->value){
    printf("can not save a NULL value\n");
    return;
  }

  uv_buf_t iov = uv_buf_init(node->value, MAX_VALUE_BYTE);

  lseek(file,offset,SEEK_SET);
  uv_fs_write(uv_default_loop(),req,file,&iov,1,-1,cb);
}

void asyncFindOneHashNode(uv_fs_t *req,HashNode *node,uv_file file,uv_fs_cb cb){
  unsigned int offset = classicHash(node->key)%MAX_PACKEGE;
  if(NULL == node->value || NULL == node || NULL == node->key){
    printf("can not find a NULL HashNode\n");
  }

  uv_buf_t iov = uv_buf_init(node->value, MAX_VALUE_BYTE);

  lseek(file,offset,SEEK_SET);
  uv_fs_read(uv_default_loop(),req,file,&iov,1,-1,cb);
}

void asyncSaveOneKeyValue(uv_fs_t *req,char *key,char *value,uv_file file,uv_fs_cb cb){
  HashNode node;
  node.key = key;
  node.value = value;
  printf("%s\n",value);
  asyncSaveOneHashNode(req,&node,file,cb);
}

void asyncFindOneKeyValue(uv_fs_t *req,char *key,uv_file file,uv_fs_cb cb){
  HashNode node;
  char value[MAX_VALUE_BYTE];
  node.key = key;
  node.value = value;
  asyncFindOneHashNode(req,&node,file,cb);
}
