#include "data.h"
#include "stdint.h"
#include "stdio.h"


Data *dataCreate(uint32_t key,void *value){
  Data *data = (Data *)malloc(sizeof(Data));
  data->key = key;
  data->value = value;

  return data;
}
