#include <stdarg.h>
#include "variadic_functions.h"

int sum_them_all(const unsigned int n, ...);

int sum_them_all(const unsigned int n, ...)
{
  int num = 0, i;
  
  if (n == 0)
  return (0);
  
  va_list add;
  
  va_start(add, n);
  for (i = 0; i < n; i++)
  {
    num += va_arg(add, int);
  }
  va_end(add);
  return (num);
}
