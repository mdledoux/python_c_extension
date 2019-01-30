#include <stdio.h>
#include "mylib.h"


void main(void)
{
  printf("string: %s\n", my_str_func() );
  printf("long float: %lf\n", my_float_func() );

  printf("product: %d\n", multiply_ints(3,5) );
}
