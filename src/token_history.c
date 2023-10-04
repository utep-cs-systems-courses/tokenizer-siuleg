#include "history.h"
#include "tokenizer.h"
#include <stdio.h>
#include <stdlib.h>

List *init_history() {
  List *list = malloc(sizeof(List));
  list->root = malloc(sizeof(Item));
  return list;
}

void add_history(List *list, char *str) {
  // First go to the end of the list
  Item *temp = list->root;
  short id = 1;
  while (temp->next != NULL) {
    temp = temp->next;
    id++;
  }

  // Add space for a new item at the end of the list
  temp->next = malloc(sizeof(Item));
  temp->next->str = copy_str(str, get_full_str_length(str));
  temp->next->id = id;
}

char *get_history(List *list, int id) {
  Item *temp = list->root;
  while (temp != NULL) {
    if (temp->id == id) {
      return temp->str;
    }
    temp = temp->next;
  }
  // Didn't find anything, return null
  return NULL;
}

void print_history(List *list) {
  if (list == NULL || list->root->next == NULL) {
    puts("No history to print!");
    return;
  }
  Item *temp = list->root;

  while (temp != NULL) {
    printf("[%d].- %s\n", temp->id, temp->str);
    temp = temp->next;
  }
}

void free_history(List *list) {
  Item *current = list->root;

  while (current != NULL) {
    Item *previous = current;
    free(current->str);
    current = previous->next;
    free(previous);
  }
  free(list);
}
