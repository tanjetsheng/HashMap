#include "hashmap.h"
#include <stdint.h>
#include <stdio.h>
#include <malloc.h>

void initHashMap(HashTable *table, int size){
  table->list = (LinkedList **)calloc(size * SIZE_FACTOR, sizeof(LinkedList **));
  table->size = size;
}

void _HashMapAdd(HashTable *table, void *data, int hashValue){
    
}

void _HashMapSearch(HashTable *table, void *data,int index, Compare compareFunc){

}

void _HashMapRemove(HashTable *table, void *data,int index, Compare compareFunc){

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
