#include <stdio.h>

#include "diff.h"

int main ()
{
  const char *a = "horse";
  const char *b = "ros";
  
  printf ("minimum number of edits: %d\n", shortest_edit (a, b));
  return 0;
}
