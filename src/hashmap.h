#ifndef _HASHMAP_H
#define _HASHMAP_H
#include <stdio.h>
#include <stdint.h>
#include <malloc.h>
#include "linkedlist.h"
#include "data.h"
#include "integercompare.h"

#define SIZE_FACTOR 3



typedef struct HashTable HashTable;

struct HashTable{
  LinkedList *list;
  int size;
  int sizefactor;
};

void initHashMap(HashTable *table, int size);
void _HashMapAdd(HashTable *table, void *data,uint32_t key,int hashValue,Compare compareFunc);
void *_HashMapSearch(HashTable *table, uint32_t key,int index, Compare compareFunc);
void _HashMapRemove(HashTable *table, uint32_t key,int index, Compare compareFunc);
void HashMapAdd(HashTable *table,void *data,uint32_t key);
void *HashMapSearch(HashTable *table,void *data,uint32_t key);
void HashMapRemove(HashTable *table, void *data,uint32_t key);




#endif // _HASHMAP_H
