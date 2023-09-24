#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 250
#define DELIMETER ' '

void tokenize_string(char *str) {}

/**
 * Captures and saves the user input
 *
 * @return user_input
 */
char *save_user_input() {
  char *user_input = malloc(MAX_SIZE * sizeof(char));
  fputs("Please enter the sequence you'd like to tokenize\n> ", stdout);
  fflush(stdout);
  int c;
  while ((c = getchar()) == '\n')
    ; // Ignore first new line characters

  for (int i = 0; i < MAX_SIZE; i++) {
    if (c == '\n' || i == (MAX_SIZE - 1)) {
      user_input[i] = '\0';
      break;
    }
    user_input[i] = c;
    c = getchar();
  }
  puts("");
  printf("'%s'\n\n", user_input);
  return user_input;
}
