#ifndef _HASH_UV_DATA_H_
#define _HASH_UV_DATA_H_

#include "header.h"
#include "hashTable.h"

extern void asyncOpenHashFile(uv_fs_t *req,const char *file,uv_fs_cb cb);

extern void asyncCloseHashFile(uv_fs_t *req,uv_file file,uv_fs_cb cb);

extern void asyncSaveOneHashNode(uv_fs_t *req,HashNode *node,uv_file file,uv_fs_cb cb);

extern void asyncFindOneHashNode(uv_fs_t *req,HashNode *node,uv_file file,uv_fs_cb cb);

extern void asyncSaveOneKeyValue(uv_fs_t *req,char *key,char *value,uv_file file,uv_fs_cb cb);

extern void asyncFindOneKeyValue(uv_fs_t *req,char *key,uv_file file,uv_fs_cb cb);

#endif
