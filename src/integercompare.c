#include "integercompare.h"


int integerCompare(int value, int refvalue){
  if(value > refvalue){
    return 1;
  }
  else if(value <refvalue)
  {
    return 0;
  }
  else{
  return value == refvalue;
}
}
