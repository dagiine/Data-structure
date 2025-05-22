#include "include/linked_list.h"
#include <stdio.h>
#include <stdlib.h>

int enqueue(Node **head, int n) {
  Node *newNode = createNode(n);
  if (*head == NULL) {
    *head = newNode;
    return 1;
  }

  Node *current = *head;
  while (current->next != NULL) {
    current = current->next;
  }
  current->next = newNode;

  return 1;
}

// dequeue хийж буй элементийн утгыг буцаана, олдоогүй бол -1
int dequeue(Node **head) {
  if (*head == NULL) {
    return -1;
  }

  Node *temp = *head;
  int value = temp->val;
  *head = temp->next;
  
  free(temp);
  return value;
}

int main() {
  Node *head = NULL;

  int running = 1;
  int n;
  char op;

  while (running == 1) {
    scanf(" %c", &op);
    switch (op) {
    case '+':
      scanf("%d", &n);
      enqueue(&head, n);
      break;
    case '-':
      printf("%d\n", dequeue(&head));
      break;
    default:
      running = 0;
      break;
    }
    printf("[%d] > ", length(head));
    printList(head);
    printf("\n");
  }

  makeEmpty(&head);
  return 0;
}
