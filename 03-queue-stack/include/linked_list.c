#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

// TODO: linked_list.h дотор тодорхойлсон функцуудыг хэрэгжүүлэх

/* Жагсаалтыг хэвлэх */
void printList(Node *head) {
  Node *current = head;
  while (current != NULL){
    printf("%d ", current->val);
    current = current->next;
  }
}

/* Жагсаалтыг хоослох */
void makeEmpty(Node **head) {
  Node *current = *head;
  while (current != NULL){
    Node *temp = current;
    current = current->next;
    free(temp);
  }
  *head = NULL;
}

/* n утгатай шинэ Node үүсгэж, буцаах */
Node *createNode(int n){
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->val = n;
  newNode->next = NULL;
  
  return newNode;
}

/* n утгатай элементийг хайж, эхний олдсон Node-г буцаана
 * байхгүй бол null буцаана */
Node *findValue(Node *head, int n){
  Node *current = head;
  while (current != NULL){
    if (current->val == n) return current;
    current = current->next;
  }
  return NULL;
}

/* j-р элементийг олж буцаах
 * амжилтгүй бол null буцаана */
Node *findAt(Node *head, int j){
  if(j < 0) 
    return NULL;
  Node *current = head;
  int index = 0;
  while (current !=NULL){
    if(index == j) 
      return current;
    current = current -> next;
    index++;
  }
  return NULL;
}

/* n утгатай элементийг хайж, хэд дэх элемент гэдгийг буцаана
 * байхгүй бол -1 */
int findIndex(Node *head, int n){
  Node *current = head;
  int index = 0;
  while (current != NULL){
    if (current->val == n) 
      return index;
    current = current->next;
    index++;
  }
  return -1;
}

/* x-ийг шинэ Node үүсгэн j-р байранд оруулах
 * 0-с бага бол 0, уртаас их бол төгсгөлд нь оруулна,
 * амжилттай оруулсан бол  1, амжилтгүй бол 0 утга буцаах */
int insertAt(Node **head, int x, int j){
  Node *newNode = createNode(x);
  if (j <= 0){
    newNode -> next = *head;
    *head = newNode;
    return 1;
  }
  
  Node *current = *head;
  for (int i = 0; i < j-1 && current->next != NULL; i++){
    current = current->next;
  }
  newNode->next = current->next;
  current->next = newNode;
  return 1;
}

/* x-ийг n утгатай Node-н ард оруулах
 * амжилттай оруулсан бол  1, амжилтгүй бол 0 утга буцаах */
int insertAfter(Node *head, int x, int n){
  Node *targetNode = findValue(head, n);
  if (targetNode == NULL)
        return 0;
    
  Node *newNode = createNode(x);
  newNode->next = targetNode->next;
  targetNode->next = newNode;
  return 1;
}

/* j-р элементийг устгах
 * амжилттай устгасан бол 1, амжилтгүй бол 0 утга буцаах */
int removeAt(Node **head, int j) {
  if (*head == NULL || j < 0)
      return 0;

  Node *current = *head;
  if (j == 0) {
      *head = current->next;
      free(current);
      return 1;
  }

  for (int i = 0; current != NULL && i < j - 1; i++) {
      current = current->next;
  }

  if (current == NULL || current->next == NULL)
      return 0;
    
  Node *temp = current->next;
  current->next = temp->next;

  free(temp);
  return 1;
}

/* n утгатай элементийг устгах
 * амжилттай устгасан бол 1, амжилтгүй бол 0 утга буцаах */
int removeValue(Node **head, int n) {
  if (*head == NULL)
      return 0;

  Node *current = *head;
  if (current->val == n) {
      *head = current->next;
      free(current);
      return 1;
  }

  Node *prev = NULL;
  while (current != NULL && current->val != n) {
      prev = current;
      current = current->next;
  }
  if (current == NULL)
      return 0;
  prev->next = current->next;

  free(current);
  return 1;
}
/* Жагсаалтын уртыг олж, буцаана */
int length(Node *head) {
  int count = 0;
  Node *current = head;
  while (current != NULL) {
      count++;
      current = current->next;
  }

  return count;
}
