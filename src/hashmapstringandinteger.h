#ifndef _HASHMAPSTRINGANDINTEGER_H
#define _HASHMAPSTRINGANDINTEGER_H
#include <stdio.h>
#include <stdint.h>
#include <malloc.h>
#include "linkedlist.h"
#include "data.h"
#include "integercompare.h"
#include "hashmap.h"

void HashMapAddInteger(HashTable *table,int *data,uint32_t key);
void HashMapAddString(HashTable *table,char *data,uint32_t key);

#endif // _HASHMAPSTRINGANDINTEGER_H
