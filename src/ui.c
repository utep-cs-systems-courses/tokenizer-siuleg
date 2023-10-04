#include "history.h"
#include "tokenizer.h"
#include <stdio.h>
#include <stdlib.h>

/* Entry point to the code. It displays a basic UI for the user to interact
 * with*/
int main() {
  printf("\x1b[2J\x1b[2H");
  puts("Welcome!");
  char *string_to_tokenize;
  char **tokens;
  List *history_list = init_history();
  while (1) { // Infinite whlie loop
    fputs("Please enter 't' to tokenize a string, 'v' to view the history, '!n "
          "to view a certain item in history, or 'q' to quit:\n> ",
          stdout);
    fflush(stdout);
    char c[10];

    fgets(c, 10, stdin);

    switch (c[0]) {
    case 't':
      puts("You selected to tokenize a string\n");
      string_to_tokenize = save_user_input();
      printf("`%s`", string_to_tokenize);
      add_history(history_list, string_to_tokenize);
      tokens = tokenize(string_to_tokenize);
      break;
    case 'v':
      puts("You selected to view the history\n");
      print_history(history_list);
      break;
    case '!':
      printf("Viewing item with id %s\n\n", c + 1);
      int find_id = atoi(c + 1);
      char *history_item = get_history(history_list, find_id);
      if (history_item == NULL) {
        printf("Did not find item:(\n\n");
      } else {
        printf("%d.- %s\n\n", find_id, history_item);
        free(tokens);
        tokens = tokenize(history_item);
      }
      break;
    case 'q':
      puts("Bye!");
      goto done;
    default:
      printf("Unrecognized option '%c', please try again!\n", c[0]);
    }
  }

done:
  free_history(history_list);
  free(string_to_tokenize);
  free(tokens);
  return 0;
}
