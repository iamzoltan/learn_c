#include <stdio.h>

#define MAXLINE 1000    /* maximum characters in a line */ 
#define TABWIDTH 4      /* tab size */ 

int my_getline(char line[], int maxline);
void entab(char to[], char from[]);


main()
{
  int len;                    /* current line length */ 
  char line[MAXLINE];         /* current input line */
  char entab_line[MAXLINE];   /* detabbed line */

  while ((len = my_getline(line, MAXLINE)) > 0) {
    entab(entab_line, line);
    printf("%s", entab_line);
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

/* entab: replace blanks with tab in line; does not handle the limit */
void entab(char to[], char from[])
{
  int i, j, k;

  i = j = k = 0;
  while ((to[j] = from[i]) != '\0') {
    if (from[i] == ' ') {
      ++k;
      if (k == TABWIDTH) {
        k = 0;
        j = j - TABWIDTH;
        to[j] = '\t';
      }
    } else {
      k = 0;
    }
    ++j;
    ++i;
  }
}
