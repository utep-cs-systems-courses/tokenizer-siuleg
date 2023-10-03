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

char *token_start(char *str) {
  int i = 0;
  while (space_char(str[i]))
    i++;
  return &str[i];
}

char *token_terminator(char *token) {
  char *token_end;
  int token_size = sizeof(token) / sizeof('a');
  for (int i = 0; i < token_size; i++) {
    if (space_char(token[i])) {
      token_end = (char *)&token[i];
      return token_end;
    }
  }
  return (char *)0;
}

int count_tokens(char *str) {
  int count = 0;
  for (int i = 0; str[i] != '\0'; i++) {
    count += (space_char(str[i]) && non_space_char(str[i + 1])) ? 1 : 0;
  }
  return count + 1;
}

char *copy_str(char *inStr, short len) {
  char *str_copy = (char *)malloc(len * sizeof(char) + 1);
  for (short i = 0; i < len; i++) {
    str_copy[i] = inStr[i];
  }
  str_copy[-1] = '\0';
  return str_copy;
}

char **tokenize(char *str) {
  int token_count = count_tokens(str);
  char **tokens = (char **)malloc(token_count * (sizeof(char *)));

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
  return user_input;
}
