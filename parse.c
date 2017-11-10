#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
  ex: takes "ls -a -l"
  returns array ["ls", "-a", "-l", NULL]

  assume 1 space between each argument
  assume no more than 5 args
  assume correctly formatted
*/

char **parse_args(char *line) {
  //pointer to "array"; free this later
  char **args = malloc(6 * sizeof(char *));

  int i = 0;
  while (line) {
    char *arg = strsep(&line, " ");
    args[i] = arg;
    i++;
  }
  args[i] = NULL;
  
  return args;
}

int main() {
  /*
  char line[100] = "wow-this-is-cool";
  char *s1 = line;
  printf("[%s]\n", strsep( &s1, "-" ));
  printf("[%s]\n", s1);
  */

  char line[] = "ls -a -l";
  char **args = parse_args(line);
  /* like this
  char *args[6];
  args[0] = "ls";
  args[1] = "-a";
  args[2] = "-l";
  args[3] = NULL;
  */
  execvp(args[0], args);
  
  return 0;
}
