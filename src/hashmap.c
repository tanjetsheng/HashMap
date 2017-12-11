#include "hashmap.h"

void initHashMap(HashTable *table, int size){
  table->list = (LinkedList *)calloc(size * SIZE_FACTOR, sizeof(LinkedList));
  table->size = size;
  table->sizefactor = SIZE_FACTOR;
}

void _HashMapAdd(HashTable *table, void *data, int hashValue){
  Item *newItem = (Item *)malloc(sizeof(Item));
  createItem(newItem,data,NULL);
   listAdd(&table->list[hashValue],newItem);
}

void *_HashMapSearch(HashTable *table,uint32_t key,int index, Compare compareFunc){
   return linkSearch(&table->list[index],key,(Compare)compareFunc);
}

void *_HashMapRemove(HashTable *table,uint32_t key,int index, Compare compareFunc){
  return LinkRemove(&table->list[index],key,(Compare)compareFunc);
}

uint32_t hashUsingModule(uint32_t value,uint32_t range){
  return value % range;
}


void HashMapAddInteger(HashTable *table, int data){
  //compute hash value



}

void HashMapSearch(HashTable *table, int data){

}

void HashMapRemove(HashTable *table, int data){

}
