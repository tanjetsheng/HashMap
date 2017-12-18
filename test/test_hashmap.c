#include "unity.h"
#include "hashmap.h"
#include "data.h"
#include "stdint.h"
#include "linkedlist.h"
#include <malloc.h>
#include "integercompare.h"

void setUp(void)
{
}

void tearDown(void)
{
}

void test_hashmap_init(void)
{
  HashTable table;
  initHashMap(&table,6);
  TEST_ASSERT_NOT_NULL(table.list);

}



void test__hashMapAdd_given_empty_hash_table_and_value_5_david_has_added(void){
  Data *data;
  HashTable hashTable;
  initHashMap(&hashTable,10);
  data = dataCreate(5,"David");
  _HashMapAdd(&hashTable,(void *)data,5,7,(Compare)CompareKey);

  TEST_ASSERT_NOT_NULL(hashTable.list[7].head);
  data = (Data *)(hashTable.list[7].head->data);
  TEST_ASSERT_EQUAL(5,data->key);
  TEST_ASSERT_EQUAL_STRING("David",data->value);
  free(data);
}


void test__hashMapAdd_given_empty_hash_table_and_value_5_6_has_added_in_7(void){
  Data *data,*David,*Ali;
  HashTable hashTable;
  initHashMap(&hashTable,10);
  David = dataCreate(5,"David");
  _HashMapAdd(&hashTable,(void *)David,5,7,(Compare)CompareKey);
  Ali = dataCreate(6,"Ali");
  _HashMapAdd(&hashTable,(void *)Ali,6,7,(Compare)CompareKey);

  TEST_ASSERT_NOT_NULL(hashTable.list[7].head);
  data = (Data *)(hashTable.list[7].head->data);
  TEST_ASSERT_EQUAL(5,data->key);
  TEST_ASSERT_EQUAL_STRING("David",data->value);

  TEST_ASSERT_NOT_NULL(hashTable.list[7].head->next);
  data = (Data *)(hashTable.list[7].head->next->data);
  TEST_ASSERT_EQUAL(6,data->key);
  TEST_ASSERT_EQUAL_STRING("Ali",data->value);

  TEST_ASSERT_NULL(hashTable.list[7].head->next->next);
  free(David);
  free(Ali);

}

void test_hashmapSearch(void){
  Data *David,*Ali;
  HashTable hashTable;
  initHashMap(&hashTable,10);
  David = dataCreate(5,"David");
  _HashMapAdd(&hashTable,(void *)David,5,7,(Compare)CompareKey);
  Ali = dataCreate(6,"Ali");
  _HashMapAdd(&hashTable,(void *)Ali,6,7,(Compare)CompareKey);

  Data *a=_HashMapSearch(&hashTable,6,7,(Compare)CompareKey);
  TEST_ASSERT_EQUAL(a,Ali);
  free(David);
  free(Ali);
}

void test_hashmapRemove(void){
  Data *data,*David,*Ali;
  HashTable hashTable;
  initHashMap(&hashTable,10);
  David = dataCreate(5,"David");
  _HashMapAdd(&hashTable,(void *)David,5,7,(Compare)CompareKey);
  Ali = dataCreate(6,"Ali");
  _HashMapAdd(&hashTable,(void *)Ali,6,7,(Compare)CompareKey);

  data =  (Data *)(hashTable.list[7].head);
  TEST_ASSERT_NOT_NULL(data);
  _HashMapRemove(&hashTable,5,7,(Compare)CompareKey);
  data = (Data *)(hashTable.list[7].head->next);
  TEST_ASSERT_NULL(data);
  free(David);
  free(Ali);
}

void test__hashMapAdd_two_similar_value(void){
  Data *data,*David,*Ali;
  HashTable hashTable;
  initHashMap(&hashTable,10);
  David = dataCreate(5,"David");
  Ali = dataCreate(6,"Ali");
  _HashMapAdd(&hashTable,(void *)David,5,7,(Compare)CompareKey);
  _HashMapAdd(&hashTable,(void *)Ali,6,7,(Compare)CompareKey);
  _HashMapAdd(&hashTable,(void *)Ali,6,7,(Compare)CompareKey);

  TEST_ASSERT_NOT_NULL(hashTable.list[7].head);
  data = (Data *)(hashTable.list[7].head->data);
  TEST_ASSERT_EQUAL(5,data->key);
  TEST_ASSERT_EQUAL_STRING("David",data->value);

  TEST_ASSERT_NOT_NULL(hashTable.list[7].head->next);
  data = (Data *)(hashTable.list[7].head->next->data);
  TEST_ASSERT_EQUAL(6,data->key);
  TEST_ASSERT_EQUAL_STRING("Ali",data->value);

  TEST_ASSERT_NULL(hashTable.list[7].head->next->next);
  free(David);
  free(Ali);
}

void test_hashMapAdd(void){
  Data *data,*David,*Ali;
  HashTable hashTable;
  initHashMap(&hashTable,10);
  David = dataCreate(1,"David");
  HashMapAdd(&hashTable,(void *)David,1);

  TEST_ASSERT_NOT_NULL(hashTable.list[1].head);
  data = (Data *)(hashTable.list[1].head->data);
  TEST_ASSERT_EQUAL(1,data->key);
  TEST_ASSERT_EQUAL_STRING("David",data->value);

  free(David);
}

void test_hashMapAdd_two_value(void){
  Data *data,*David,*Ali;
  HashTable hashTable;
  initHashMap(&hashTable,10);
  David = dataCreate(1,"David");
  HashMapAdd(&hashTable,(void *)David,1);
  Ali = dataCreate(11,"Ali");
  HashMapAdd(&hashTable,(void *)Ali,11);

  TEST_ASSERT_NOT_NULL(hashTable.list[1].head);
  data = (Data *)(hashTable.list[1].head->data);
  TEST_ASSERT_EQUAL(1,data->key);
  TEST_ASSERT_EQUAL_STRING("David",data->value);

  TEST_ASSERT_NOT_NULL(hashTable.list[1].head->next);
  data = (Data *)(hashTable.list[1].head->next->data);
  TEST_ASSERT_EQUAL(11,data->key);
  TEST_ASSERT_EQUAL_STRING("Ali",data->value);

  free(David);
  free(Ali);
}

void test_hashmapSearch_implement(void){
  Data *David,*Ali;
  HashTable hashTable;
  initHashMap(&hashTable,10);
  David = dataCreate(1,"David");
  HashMapAdd(&hashTable,(void *)David,1);
  Ali = dataCreate(11,"Ali");
  HashMapAdd(&hashTable,(void *)Ali,11);

  Data *a=HashMapSearch(&hashTable,(void *)Ali,11);
  TEST_ASSERT_EQUAL(a,Ali);
  free(David);
  free(Ali);
}

void test_hashmapRemove_implement(void){
  Data *data,*David,*Ali;
  HashTable hashTable;
  initHashMap(&hashTable,10);
  David = dataCreate(5,"David");
  HashMapAdd(&hashTable,(void *)David,1);
  Ali = dataCreate(6,"Ali");
  HashMapAdd(&hashTable,(void *)Ali,11);

  data =  (Data *)(hashTable.list[1].head);
  TEST_ASSERT_NOT_NULL(data);
  HashMapRemove(&hashTable,(void *)Ali,11);
  data = (Data *)(hashTable.list[1].head->next);
  TEST_ASSERT_NULL(data);
  free(David);
  free(Ali);
}
