#include <stdio.h>

/* count lines in input */ 
main()
{
  int c, nb;

  nb = 0;
  while((c = getchar()) != EOF)
    if (c != ' ') {
      putchar(c);
      nb = 0;
    }
    else if ((c == ' ') && (nb == 0)) {
      putchar(c);
      ++nb;
    }
}
