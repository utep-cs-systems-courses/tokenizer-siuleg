#include "tokenizer.h"
#include <stdio.h>
#include <stdlib.h>

/* Entry point to the code. It displays a basic UI for the user to interact
 * with*/
int main() {
  printf("\x1b[2J\x1b[2H");
  puts("Welcome!");
  char *string_to_tokenize;
  while (1) { // Infinite whlie loop
    fputs("Please enter 't' to tokenize a string, or 'q' to quit:\n> ", stdout);
    fflush(stdout);
    int c;
    while ((c = getchar()) == '\n')
      ; // Ignore new-line chars
    if (c == EOF)
      goto done;

    switch (c) {
    case 't':
      puts("You selected to tokenize a string\n");
      string_to_tokenize = save_user_input();
      puts(string_to_tokenize);
      break;
    case 'q':
      puts("Bye!");
      goto done;
    default:
      printf("Unrecognized option '%c', please try again!\n", c);
    }
  }

done:
  free(string_to_tokenize);
  return 0;
}
