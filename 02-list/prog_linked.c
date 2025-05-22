#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  Node *head = NULL;

  // Insert elements
  if (!insertAt(&head, 19, 0)) {
    printf("Failed to insert 19 at index 0\n");
    return 1;
  }
  if (!insertAt(&head, 67, 1)) {
    printf("Failed to insert 67 at index 1\n");
    return 1;
  }
  if (!insertAt(&head, 30, 2)) {
    printf("Failed to insert 30 at index 2\n");
    return 1;
  }

  // Print the list
  printf("Initial list: ");
  printList(head);

  // Remove element at index 1
  if (!removeAt(&head, 1)) {
    printf("Failed to remove element at index 1\n");
    return 1;
  }
  printf("After removing element at index 1: ");
  printList(head);

  // Insert 15 after 19
  if (!insertAfter(head, 15, 19)) {
    printf("Failed to insert 15 after 19\n");
    return 1;
  }
  printf("After inserting 15 after 19: ");
  printList(head);

  // Remove element with value 15
  if (!removeValue(&head, 15)) {
    printf("Failed to remove element with value 15\n");
    return 1;
  }
  printf("After removing element with value 15: ");
  printList(head);

  // Print the length of the list
  printf("Length of the list: %d\n", length(head));

  // Empty the list
  makeEmpty(&head);
  printf("After emptying the list: ");
  printList(head);

  return 0;
}