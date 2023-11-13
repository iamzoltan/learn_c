#include <stdio.h>

/* count characters input; 1st version */ 
main()
{
  long nc;

  nc = 0;
  while (getchar() != EOF) 
    ++nc;
  printf("%ld\n", nc);
}
