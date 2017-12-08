#include <stdio.h>
#include "linkedlist.h"
#include <stdio.h>
#include <string.h>


void listInit(LinkedList *list) {
  list->head = NULL;
  list->tail = NULL;
  list->len = 0;
}

void listAdd(LinkedList *list,Item *item){
    if(list->len == 0)
    {
    list->head = item;
    list->tail = item;


    }
    else
    {
	  list->tail->next=item;
      list->tail=item;

    }
    list->len += 1;
    item->next=NULL;

}

void createItem(Item *item,void *data, Item *next){

  item->data = data;
  item->next = next;

}

Item *linkSearch(LinkedList *list,void *data,Compare comparefunc){
    Item *past = NULL;
    Item *now = list->head;
    if(now == NULL){
      return NULL;
    }
    else {
      while(comparefunc())
    }

}
/*
Item *LinkRemove(LinkedList *list,char *name){
	Item *current = list->head;
	Item *previous = NULL;

	if(list->head==NULL){
		return NULL;
	}

	else if(list->head==list->tail){   //first head
		listInit(list);
	}

	else{
		while(strcmp(((Student*)current->data)->name,name)!=0){
			previous = current;
			current = current->next;
		}
	}
	if(current ==NULL){
		return NULL;
	}
	else if(current ==list->tail){
		list->tail=previous;
		list->tail->next=NULL;
		list->len--;
	}
	else{
		previous->next = current->next;
		list->len--;
	}

}
*/
