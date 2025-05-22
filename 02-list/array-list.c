#include <stdio.h>
#include <stdlib.h>
#include "array_list.h"

/* Жагсаалтыг хэвлэх */
void printList(ArrayList *list) {
    if (list == NULL || list->values == NULL) {
        printf("\n");
        return;
    }

    for (int i = 0; i < list->length; i++) {
        printf("%d ", list->values[i]);
    }
}

/* Жагсаалтыг хоослох */
void makeEmpty(ArrayList *list) {
    if (list != NULL) {
        list->length = 0;
    }
}

/* Шинэ n хэмжээтэй хоосон ArrayList үүсгэх */
ArrayList *createList(int n) {
    if (n <= 0) 
        return NULL;

    
}

/* ArrayList-н санах ойг чөлөөлж, устгах */
void deleteList(ArrayList *list) {
    if (list != NULL) {
        free(list->values);
        free(list);
    }
}

/* n утгатай элементийг хайж, index-г буцаах */
int find(ArrayList *list, int n) {
    if (!list || list->length == 0) return -1;
    for (int i = 0; i < list->length; i++) {
        if (list->values[i] == n) 
            return i;
    }
    return -1;
}

/* j-р элементийг олж, утгыг result заагчид олгох */
int findAt(ArrayList *list, int j, int *result) {

}

/* x-ийг j байранд оруулах */
void insertAt(ArrayList *list, int x, int j) {
    
}

/* x-ийг n утгын ард оруулах */
int insertAfter(ArrayList *list, int x, int n) {
    int index = find(list, n);
    if (index == -1 || list->length >= list->max_size) 
        return 0;
    insertAt(list, x, index + 1);
    return 1;
}

/* j-р элементийг устгах */
int removeAt(ArrayList *list, int j) {
    if (list == NULL || j < 0 || j >= list->length) 
        return 0;

    for (int i = j; i < list->length - 1; i++) {
        list->values[i] = list->values[i + 1];
    }
    list->length--;

    return 1;
}

/* n утгатай элементийг устгах */
int removeValue(ArrayList *list, int n) {
    int index = find(list, n);
    if (index == -1) 
        return 0;
    return removeAt(list, index);
}