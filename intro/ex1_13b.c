#include <stdio.h>

#define MAXWORDLENGTH 10
#define IN 1 /* inside a word */ 
#define OUT 0 /* outside a word */ 

/* write a histogram of length of words in input */ 
main()
{
  int c, nc, i, j, state;
  int lengths_arr[MAXWORDLENGTH];
  int max_freq = 0;

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

  for (i = 0; i < MAXWORDLENGTH; ++i)
    if (lengths_arr[i] > max_freq)
      max_freq = lengths_arr[i];

  for (i = max_freq; i > 0 ; --i) {
    for (j = 0; j < MAXWORDLENGTH; ++j)
      if (i <= lengths_arr[j])
        printf("  *");
      else
        printf("   ");
    printf("\n");
  }

  for (i = 0; i < MAXWORDLENGTH; ++i)
    printf("---");
  printf("\n");

  for (i = 0; i < MAXWORDLENGTH; ++i)
    printf(" %2d", i+1);
  printf("\n");
}
