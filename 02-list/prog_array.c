#include "array_list.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 100;
    ArrayList *list = createList(n);

    if (list == NULL) {
        printf("Failed to create list\n");
        return 1;
    }

    insertAt(list, 13, 0);
    insertAt(list, 27, 1);
    insertAt(list, 30, 2);
    printList(list); 

    insertAfter(list, 23, 13);
    printList(list); 

    int index = find(list, 27);
    printf("Index of 27: %d\n", index);

    removeAt(list, 1);
    printList(list);

    removeValue(list, 30);
    printList(list); 

    makeEmpty(list);
    printList(list); 

    deleteList(list);

    return 0;
}