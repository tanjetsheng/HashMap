#include "integercompare.h"


int integerCompare(int value, int refvalue){
  if(value > refvalue){
    return 1;
  }
  else if(value <refvalue)
  {
    return -1;
  }
  else{
  return 0;
}
}


int CompareKey(uint32_t key,Data *data){
  if(key > data->key){
    return 1;
  }
  else if(key < data->key)
  {
    return -1;
  }
  else{
  return 0;
}
}
