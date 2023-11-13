#include <stdio.h>

#define MAXNUMCHARS 94 /* values between 33 and 126 */

/* write a histogram of length of words in input */ 
main()
{
  int c, i, j;
  int char_freqs[MAXNUMCHARS];
  int max_freq = 0;

  for (i = 0; i < MAXNUMCHARS; ++i)
    char_freqs[i] = 0;

  while((c = getchar()) != EOF) {
    if (33 <= c && c <= 126) {
        ++char_freqs[c-33];
        if (char_freqs[c-33] > max_freq)
          max_freq = char_freqs[c-33];
		}
  }

  for (i = max_freq; i > 0 ; --i) {
    for (j = 0; j < MAXNUMCHARS; ++j)
      if (i <= char_freqs[j])
        printf("*");
      else
        printf(" ");
    printf("\n");
  }

  for (i = 0; i < MAXNUMCHARS; ++i)
    printf("-");
  printf("\n");

  for (i = 0; i < MAXNUMCHARS; ++i)
    printf("%c", i+33);
  printf("\n");
}
