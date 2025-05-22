#include "include/array_list.h"
#include <stdio.h>
#include <stdlib.h>

void push(ArrayList *list, int n) {
    if (list->length < list->max_size) {
        for (int i = list->length; i > 0; i--) {
            list->values[i] = list->values[i - 1];
        }
        list->values[0] = n;
        list->length++;
    }
}

int pop(ArrayList *list) {
    if (list->length == 0) {
        return -1;
    }
    int top = list->values[0];
    for (int i = 0; i < list->length - 1; i++) {
        list->values[i] = list->values[i + 1];
    }
    list->length--;
    return top;
}

int main() {
  ArrayList *list = createList(100);

  int running = 1;
  int n;
  char op;

  while (running == 1) {
    scanf(" %c", &op);
    switch (op) {
    case '+':
      scanf("%d", &n);
      push(list, n);
      break;
    case '-':
      printf("%d\n", pop(list));
      break;
    default:
      running = 0;
      break;
    }
    printf("[%d] > ", list->length);
    printList(list);
    printf("\n");
  }

  deleteList(list);
  free(list);
  return 0;
}
