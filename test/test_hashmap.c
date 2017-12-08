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

void xtest_hashmap_add(void)
{
  HashTable table;
  initHashMap(&table,10);
  _HashMapAdd(&table,(int *)5, 5);
  //TEST_ASSERT_EQUAL((table.list)[5].head->data,5);
}

void test__hashMapAdd_given_empty_hash_table_and_value_5_david_has_added(void){
  Data *data;
  HashTable hashTable;
  initHashMap(&hashTable,10);
  data = dataCreate(5,"David");
  _HashMapAdd(&hashTable,(void *)data,7);

  TEST_ASSERT_NOT_NULL(hashTable.list[7].head);
  data = (Data *)(hashTable.list[7].head->data);
  TEST_ASSERT_EQUAL(5,data->key);
  TEST_ASSERT_EQUAL_STRING("David",data->name);
  free(data);
}


void test__hashMapAdd_given_empty_hash_table_and_value_5_6_has_added_in_7(void){
  Data *data,*David,*Ali;
  HashTable hashTable;
  initHashMap(&hashTable,10);
  David = dataCreate(5,"David");
  _HashMapAdd(&hashTable,(void *)David,7);
  Ali = dataCreate(6,"Ali");
  _HashMapAdd(&hashTable,(void *)Ali,7);

  TEST_ASSERT_NOT_NULL(hashTable.list[7].head);
  data = (Data *)(hashTable.list[7].head->data);
  TEST_ASSERT_EQUAL(5,data->key);
  TEST_ASSERT_EQUAL_STRING("David",data->name);

  TEST_ASSERT_NOT_NULL(hashTable.list[7].head->next);
  data = (Data *)(hashTable.list[7].head->next->data);
  TEST_ASSERT_EQUAL(6,data->key);
  TEST_ASSERT_EQUAL_STRING("Ali",data->name);

  TEST_ASSERT_NULL(hashTable.list[7].head->next->next);
  free(David);
  free(Ali);

}
