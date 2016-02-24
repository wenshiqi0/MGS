#include "./include/header.h"
#include "./include/hashTable.h"
#include "./include/hashUvData.h"
#include "./include/hashData.h"
#include "./include/hashDb.h"

HashNode rnode;
uv_fs_t req1;
uv_file myfile;


void read_callback(uv_fs_t *req);

void write_callback(uv_fs_t *req){
  int result = req->result;
  printf("%d\n",result);
  uv_fs_req_cleanup(req);
  asyncFindOneHashNode(req,&rnode,myfile,read_callback);
}

void read_callback(uv_fs_t *req){
  if (req->result < 0) {
    fprintf(stderr, "Read error: %s\n", uv_strerror(req->result));
  }
  printf("%s\n",rnode.value);
}

void open_callback(uv_fs_t *req){
  printf("test\n");
  char *key = (char *)malloc(MAX_KEY_BYTE*BYTE_SIZE);
  char *value = (char *)malloc(MAX_VALUE_BYTE*BYTE_SIZE);
  strcpy(key,"name");
  strcpy(value,"munongmunong");
  myfile = req->result;
  uv_fs_req_cleanup(req);
  asyncSaveOneKeyValue(req,key,value,myfile,write_callback);
}

int main(int argc, char **argv) {
  rnode.key = (char *)malloc(MAX_KEY_BYTE*BYTE_SIZE);
  rnode.value = (char *)malloc(MAX_VALUE_BYTE*BYTE_SIZE);
  rnode.key = "haha";

  uv_fs_t req;
  asyncOpenHashFile(&req,"./data/data.db",open_callback);
  uv_run(uv_default_loop(), UV_RUN_DEFAULT);

  char *test = (char *)malloc(MAX_VALUE_BYTE*BYTE_SIZE);
  char *key = (char *)malloc(MAX_KEY_BYTE*BYTE_SIZE);
  key = "name";
  HashData *data = openHashFile("./data/data.db");
  findOneKeyValue(data,key,test);
  printf("%s\n",test);

  return 0;
}
