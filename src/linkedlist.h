#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H
#include "data.h"


typedef struct Item Item;
typedef struct LinkedList LinkedList;

struct Item {
  Item *next;
  Data *data;
};

struct LinkedList{
  Item *head;
  Item *tail;
  int len;
};

typedef int(*Compare)(void *value,void **refvalue);

void listInit(LinkedList *list);
void listAdd(LinkedList *list,Item *item);
void *LinkRemove(LinkedList *list,uint32_t key,Compare comparefunc);
void createItem(Item *item,void *data, Item *next);
Data *linkSearch(LinkedList *list,uint32_t key,Compare comparefunc);
#endif // _LINKEDLIST_H
