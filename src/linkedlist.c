#include "linkedlist.h"



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

Data *linkSearch(LinkedList *list,uint32_t key,Compare comparefunc){
    Item *past = NULL;
    Item *now = list->head;
    if(now == NULL){
      return NULL;
    }
    else {
        while(comparefunc((void*)key,(void*)&(((Data *)now->data))->key) !=0){
        past = now;
        now = now->next;
      }
      return now->data;
    }

}

void *LinkRemove(LinkedList *list,uint32_t key,Compare comparefunc){
  Item *past = NULL;
	Item *now = list->head;

	if(now == NULL){
		return NULL;
	}
	else{
    while(comparefunc((void*)key,(void*)&(((Data *)now->data))->key) !=0){
			past = now;
			now = now->next;
		}
    if(now == list->head){
      if(list->head==list->tail){   //first head
       listInit(list);
     }
      else{
				now = now->next;
				list->head = now;
				list->len--;
      }
     }

	else if(now == list->tail){
		    list->tail=past;
		    past->next=NULL;
		    list->len--;
	     }
	  else{
		  past->next = now->next;
		  list->len--;
	   }
   }
}
