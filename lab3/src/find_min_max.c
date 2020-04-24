#include "find_min_max.h"

#include <limits.h>

struct MinMax GetMinMax(int *array, unsigned int begin, unsigned int end) {
  struct MinMax min_max;
  min_max.min = INT_MAX;
  min_max.max = INT_MIN;
  INT_MAX = array[0];
  for(i = 0; array[i] != NULL, i++)
    if int(array[i]) > INT_MAX
      INT_MAX = array[i];
  
  INT_MIN = array[0];
  for(i = 0; array[i] != NULL, i++)
    if int(array[i]) < INT_MIN
      INT_MIN = array[i];
  printf("Max = %d", INT_MAX);
  printf("Min = %d", INT_MIN);
    
  // your code here
  return min_max;
}
