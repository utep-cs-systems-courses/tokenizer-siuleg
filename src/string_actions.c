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
  return str + i;
}

char *token_terminator(char *token) {
  int token_size = 0;
  while (token[token_size] != '\0' && non_space_char(token[token_size]))
    token_size++;
  return token + token_size;
}

int count_tokens(char *str) {
  int count = 0;
  int token_flag = 0;
  for (int i = 0; str[i] != '\0'; i++) {
    if (space_char(str[i])) {
      token_flag = 0;
    } else if (!token_flag) {
      token_flag = 1;
      count++;
    }
  }
  return count;
}

char *copy_str(char *inStr, short len) {
  char *str_copy = (char *)malloc(len * sizeof(char) + 1);
  for (short i = 0; i < len; i++) {
    str_copy[i] = inStr[i];
  }
  str_copy[len] = '\0';
  return str_copy;
}

short get_length(char *inStr) {
  short length = 0;
  for (length = 0; non_space_char(inStr[length]); length++)
    ;
  return length;
}

char **tokenize(char *str) {
  int token_count = count_tokens(str);
  puts("Counted tokens");
  char **tokens = (char **)malloc((token_count + 1) * (sizeof(char *)));
  puts("Allocated space for tokens");
  char *temp_ptr = str;
  puts("Created temp pointer");

  puts("Entering for loop");
  for (int i = 0; i < token_count; i++) {
    temp_ptr = token_start(temp_ptr);
    puts("\nset temp pointer to start of token");
    *(tokens + i) = copy_str(temp_ptr, get_length(temp_ptr));
    puts("added copy of string to token");
    temp_ptr = token_terminator(temp_ptr);
    puts("Moved temp pointer to end of token\n");
  }
  tokens[token_count] = NULL;
  return tokens;
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
