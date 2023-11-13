#include <stdio.h>

#define MAXWORDLENGTH 10
#define IN 1 /* inside a word */ 
#define OUT 0 /* outside a word */ 

/* write a histogram of length of words in input */ 
main()
{
  int c, nc, i, j, state;
  int lengths_arr[MAXWORDLENGTH];

  for (i = 0; i < MAXWORDLENGTH; ++i)
    lengths_arr[i] = 0;

  state = OUT;
  while((c = getchar()) != EOF) {
    if (c != ' ' && c != '\t' && c != '\n') {
			if (state == OUT)
				state = IN ;
        ++nc;
		}
		else if (state == IN) {
			state = OUT ;
      if (nc <= MAXWORDLENGTH)
        ++lengths_arr[nc-1];
      nc = 0;
		}
  }
  for (i = 0; i < MAXWORDLENGTH; ++i) {
    printf(" %2d|", i+1);
    for (j = 0; j < lengths_arr[i]; ++j)
      printf("=");
    printf("\n");
  }
}
