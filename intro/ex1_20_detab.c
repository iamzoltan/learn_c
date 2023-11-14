#include <stdio.h>

#define MAXLINE 1000    /* maximum characters in a line */ 
#define TABWIDTH 4      /* tab size */ 

int my_getline(char line[], int maxline);
void detab(char to[], char from[]);


main()
{
  int len;                    /* current line length */ 
  char line[MAXLINE];         /* current input line */
  char detab_line[MAXLINE];   /* detabbed line */

  while ((len = my_getline(line, MAXLINE)) > 0) {
    detab(detab_line, line);
    printf("%s", detab_line);
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

/* detab: replace tab with blanks in line; does not handle the limit */
void detab(char to[], char from[])
{
  int i, j, k;

  i = j = k = 0;
  while ((to[j] = from[i]) != '\0') {
    if (to[j] == '\t')
      for (k = 0; k < TABWIDTH; ++k, ++j) 
        to[j] = ' ';
    else
      ++j;
    ++i;
  }
}
