#include "array_list.h"
#include <stdio.h>
#include <stdlib.h>

// TODO: array_list.h дотор тодорхойлсон функцуудыг хэрэгжүүлэх

/* Жагсаалтыг хэвлэх */
void printList(ArrayList *list){
  for (int i = 0; i < list->length; i++) {
      printf("%d ", list->values[i]);
  }
}

/* Жагсаалтыг хоослох */
void makeEmpty(ArrayList *list){
    list -> length = 0;
}

/* Шинэ n хэмжээтэй хоосон ArrayList үүсгэх */
ArrayList *createList(int n){
  ArrayList *list =(ArrayList *)malloc(sizeof(ArrayList));
  list -> values = (int *)malloc(n * sizeof(int));
  list -> max_size = n;
  list -> length =0;
  return list;
}

/* ArrayList-н санах ойг чөлөөлж, устгах */
void deleteList(ArrayList *list){
      free(list->values);
}

/* n утгатай элементийг хайж, index-г буцаах (0 -> n-1)
 * байхгүй бол -1 */
int find(ArrayList *list, int n){
  for (int i = 0; i < list->length; i++){
    if (list->values[i] == n) return i;
  }
  return -1;
}

/* j-р элементийг олж, утгыг result заагчид олгох
 * амжилттай олсон бол 1 (true), амжилтгүй бол 0 (false) буцаана */
int findAt(ArrayList *list, int j, int *result){
  if (j < 0 || j >= list->length) 
    return 0;
  *result = list->values[j];
  return 1;
}

/* x-ийг j байранд оруулах
 * 0-с бага бол 0, уртаас их бол төгсгөлд нь оруулна */
void insertAt(ArrayList *list, int x, int j){
  if (j < 0) 
    j = 0;
  if (j > list->length) 
    j=list->length;
  if (list->length < list->max_size) {
    for(int i = list->length; i > j; i--){
      list->values[i] = list->values[i - 1];
    }
    list->values[j] = x;
    list->length++;
  }
}

/* x-ийг n утгын ард оруулах
 * амжилттай оруулсан бол  1, амжилтгүй бол 0 утга буцаах */
int insertAfter(ArrayList *list, int x, int n){
  int index = find(list, n);
  if(index == -1) 
    return 0;
  insertAt(list, x, index + 1);
  return 1;
}

/* j-р элементийг устгах
 * амжилттай устгасан бол 1, амжилтгүй бол 0 утга буцаах */
int removeAt(ArrayList *list, int j){
  if(j < 0 || j >= list->length) 
    return 0;
  for (int i = j; i < list->length - 1; i++){
    list->values[i] = list->values[i + 1];
  }
  list->length--;
  return 1;
}

/* n утгатай элементийг устгах
 * амжилттай устгасан бол 1, амжилтгүй бол 0 утга буцаах */
int removeValue(ArrayList *list, int n){
  int index = find(list, n);
  if(index == -1) 
    return 0;
  return removeAt(list, index);
}