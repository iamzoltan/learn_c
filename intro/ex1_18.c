#include <stdio.h>
#define MAXLINE 1000  /* maximum input line size */ 

int get_line(char line[], int maxline);

/* print longest input line */ 
main()
{
  int len;
  char line[MAXLINE];

  while ((len = get_line(line, MAXLINE)) > 0)
    if (len > 1 && line[0] != ' ' && line[0] != '\t')
      printf("%s\n", line);
  return 0;
}

/* getline: read a line into s, return lenght */
int get_line(char s[], int lim)
{
  int c, i;

  for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i)
    if (i == 0)
      s[i] = c;
    else if ((c == ' ' || c == '\t') && (s[i-1] == ' ' || s[i-1] == '\t'))
      --i;
    else if (s[i-1] != ' ' || s[i-1] != '\t')
      s[i] = c;

  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}
