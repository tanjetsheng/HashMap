#include "hashmap.h"

void initHashMap(HashTable *table, int size){
  table->list = (LinkedList *)calloc(size * SIZE_FACTOR, sizeof(LinkedList));
  table->size = size;
  table->sizefactor = SIZE_FACTOR;
}

void _HashMapAdd(HashTable *table, void *data,uint32_t key,int hashValue,Compare compareFunc){
  Item *newItem = (Item *)malloc(sizeof(Item));
  createItem(newItem,data,NULL);
  if(linkSearch(&table->list[hashValue],key,(Compare)compareFunc)==NULL){
    listAdd(&table->list[hashValue],newItem);
  }
  else{
    LinkRemove(&table->list[hashValue],key,(Compare)compareFunc);
    listAdd(&table->list[hashValue],newItem);
  }

}

void *_HashMapSearch(HashTable *table,uint32_t key,int index, Compare compareFunc){
   return linkSearch(&table->list[index],key,(Compare)compareFunc);
}

void _HashMapRemove(HashTable *table,uint32_t key,int index, Compare compareFunc){
  return LinkRemove(&table->list[index],key,(Compare)compareFunc);
}

uint32_t hashUsingModule(uint32_t value,uint32_t range){
  return value % range;
}


void HashMapAdd(HashTable *table,void *data,uint32_t key){
  //compute hash value
  int hashValue = hashUsingModule(key,table->size);
  _HashMapAdd(table,data,key,hashValue,(Compare)CompareKey);


}

void *HashMapSearch(HashTable *table,void *data,uint32_t key){
  int hashValue = hashUsingModule(key,table->size);
  _HashMapSearch(table,key,hashValue,(Compare)CompareKey);
}

void HashMapRemove(HashTable *table, void *data,uint32_t key){
  int hashValue = hashUsingModule(key,table->size);
  _HashMapRemove(table,key,hashValue,(Compare)CompareKey);
}
