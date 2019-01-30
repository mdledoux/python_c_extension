#include <stdio.h>
#include <math.h>


char str[20];
//char *str = (char*)malloc(20 * sizeof(char)); //doesn't work


char* my_str_func(void) {
  sprintf(str, "%f", M_PI );
  return str;
}

float my_float_func(void) {
  return M_PI;
}

int my_multiply_ints(int a, int b)
{
  return a*b;
}
