#include <stdio.h>
#define MAXLINE 1000  /* maximum input line size */ 

int get_line(char line[], int maxline);
void myreverse(char to[], char from[], int len);

/* print longest input line */ 
main()
{
  int len;
  char line[MAXLINE];
  char reverse_line[MAXLINE];

  while ((len = get_line(line, MAXLINE)) > 0) {
    myreverse(reverse_line, line, len);
    printf("%s", reverse_line);
  }
  return 0;
}

/* getline: read a line into s, return length */
int get_line(char s[], int lim)
{
  int c, i;

  for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}

/* reverse: reverse a char string */ 
void myreverse(char to[], char from[], int len)
{
  int i;
  to[len] = '\0';
  to[len-1] = '\n';

  for (i = 0; i < len-1; ++i)
    to[len-2-i] = from[i];

  // printf("%s", from);
  // printf("%s", to);
}
