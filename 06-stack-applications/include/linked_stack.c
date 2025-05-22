#include "include/linked_list.h"
#include <stdio.h>
#include <stdlib.h>


void push(Node **head, int n) {
  Node *newNode = createNode(n);
  newNode->next = *head;
  *head = newNode;
}

// pop хийж буй элементийн утгыг буцаана, байхгүй бол -1
int pop(Node **head) {
  if (*head == NULL) {
    return -1;
  }

  Node *temp = *head;
  int value = temp->val;
  *head = temp->next;

  free(temp);
  return value;
}