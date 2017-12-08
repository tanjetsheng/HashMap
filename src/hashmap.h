#ifndef _HASHMAP_H
#define _HASHMAP_H
#include "stdint.h"
#include "linkedlist.h"

#define SIZE_FACTOR 3

typedef int (*Compare)(void *data,void *refData);

typedef struct HashTable HashTable;

struct HashTable{
  LinkedList *list;
  int size;
  int sizefactor;
};

void initHashMap(HashTable *table, int size);
void _HashMapAdd(HashTable *table, void *data, int hashValue);
void *_HashMapSearch(HashTable *table, uint32_t key,int index, Compare compareFunc);
void *_HashMapRemove(HashTable *table, uint32_t key,int index, Compare compareFunc);
void HashMapAddInteger(HashTable *table, int data);
void HashMapSearch(HashTable *table, int data);
void HashMapRemove(HashTable *table, int data);




#endif // _HASHMAP_H
