#include "tokenizer.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 250

int space_char(char c) {
  if (c == '\t' || c == ' ')
    return 1;
  else
    return 0;
}

int non_space_char(char c) {
  if (c == '\t' || c == ' ')
    return 0;
  else
    return 1;
}

char **tokenize(char *str) {
  int word_start, word_end = 0;
  int str_length = sizeof(str) / sizeof(char);

  return NULL;
}

/**
 * Captures and saves the user input
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
  printf("`%s`\n\n", user_input);
  return user_input;
}
