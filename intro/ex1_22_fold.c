#include <stdio.h>

#define MAXLINE 1000    /* maximum characters in a line */ 
#define FOLDLENGTH 20     /* sub line size */ 

int my_getline(char line[], int maxline);
void fold(char input[], int maxline, int foldlength);


int main()
{
  int len;                    /* current line length */ 
  char line[MAXLINE];         /* current input line */

  while ((len = my_getline(line, MAXLINE)) > 0) {
    fold(line, MAXLINE, FOLDLENGTH);
  }
  return 0;
}

/* my_getline: reads in a line, return the length */
int my_getline(char line[], int lim)
{
  int c, i;

  for (i = 0; i < lim-1 && (c=getchar()) != EOF && c != '\n'; ++i)
    line[i] = c;
  if (c == '\n') {
    line[i] = c;
    ++i;
  }
  line[i] = '\0';
  return i;
}

/* fold: split long input lines into 2 or more shorter lines after
         the last non-blank character that occurs before the nth
         column of input. */
void fold(char input[], int lim, int fold_lim)
{
  int i, j;
  char fold_line[lim];

  j  = 0;
  for (i = 0; i < lim-1 && input[i] != '\0'; ++i, ++j) {
    if (j > fold_lim-1 && input[i] != ' ' && input[i] != '\t') {
      fold_line[j] = '\0';
      j = 0;
      printf("%s\n", fold_line);
    }
    fold_line[j] = input[i];
  }
  fold_line[j] = '\0';
  printf("%s\n", fold_line);
}
