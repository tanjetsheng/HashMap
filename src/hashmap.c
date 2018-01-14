#include "hashmap.h"


//used to resered a place to implement data
void initHashMap(HashTable *table, int size){
  table->list = (LinkedList *)calloc(size * SIZE_FACTOR, sizeof(LinkedList));
  table->size = size;
  table->sizefactor = SIZE_FACTOR;
}

//adding data into table and determine is the value is repeated in the HashTable
//if the key value has already in the table,it will remove the value and replace it with new value
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

//used to search value by using the key of the data
void *_HashMapSearch(HashTable *table,uint32_t key,int index, Compare compareFunc){
   return linkSearch(&table->list[index],key,(Compare)compareFunc);
}

//reemoving the data by its key value
void _HashMapRemove(HashTable *table,uint32_t key,int index, Compare compareFunc){
  return LinkRemove(&table->list[index],key,(Compare)compareFunc);
}

//use to calculate the place that the data should put into
uint32_t hashUsingModule(uint32_t value,uint32_t range){
  return value % range;
}
/********************************************************************/
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
