#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H
#include "hashmap.h"

typedef struct Item Item;
typedef struct LinkedList LinkedList;

struct Item {
  Item *next;
  void *data;
};

struct LinkedList{
  Item *head;
  Item *tail;
  int len;
};

void listInit(LinkedList *list);
void listAdd(LinkedList *list,Item *item);
Item *LinkRemove(LinkedList *list,char *name);
void createItem(Item *item,void *data, Item *next);
Item *linkSearch(Item *item,void *data,int hashValue,Compare comparefunc);
#endif // _LINKEDLIST_H
