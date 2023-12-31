#include <stdio.h>
#define MAXLINE 1000  /* maximum input line size */ 

int get_line(char line[], int maxline);
void copy(char to[], char from[]);

/* print longest input line */ 
main()
{
  int len;
  int max;
  char line[MAXLINE];
  char longest[MAXLINE];

  max = 0;
  while ((len = get_line(line, MAXLINE)) > 0)
    if (len > max) {
      max = len;
      copy(longest, line);
    }
  if (max > 0)  /* there was a line */ 
    if (max > MAXLINE) {
      printf("\n\nStorage limit exceeded by : %d", max-MAXLINE);
      printf("\nString length : %d", max);
      printf("\n%s", longest);
    }
    else 
      printf("%s", longest);
  return 0;
}

/* getline: read a line into s, return lenght */
int get_line(char s[], int lim)
{
  int c, i;

  for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i)
    if (i < lim-1)
      s[i] = c;
  if (i < lim-1) {
    if (c == '\n') {
      s[i] = c;
      ++i;
    }
    s[i] = '\0';
  }
  return i;
}

/* copy: cope 'from' in 'to'; assume to is big enough */
void copy(char to[], char from[])
{
  int i;

  i = 0;
  while ((to[i] = from[i]) != '\0')
    ++i;
}
