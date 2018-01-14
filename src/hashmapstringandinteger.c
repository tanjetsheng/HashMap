#include "hashmapstringandinteger.h"

void HashMapAddInteger(HashTable *table,int *data,uint32_t key){
  int hashValue = hashUsingModule(key,table->size);
  _HashMapAdd(table,data,key,hashValue,(Compare)CompareKey);
}

void HashMapAddString(HashTable *table,char *data,uint32_t key){
  int hashValue = hashUsingModule(key,table->size);
  _HashMapAdd(table,data,key,hashValue,(Compare)CompareKey);
}
