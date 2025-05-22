#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quicksort(int number[], int first, int last) {
    if (first < last) {
        int pivot = first;
        int i = first;
        int j = last;

        while (i < j) {
            while (number[i] <= number[pivot] && i < last)
                i++;
            while (number[j] > number[pivot])
                j--;
            if (i < j)
                swap(&number[i], &number[j]);
        }

        swap(&number[pivot], &number[j]);

        quicksort(number, first, j - 1);
        quicksort(number, j + 1, last);
    }
}

int main() {
    int i, n;

    scanf("%d", &n);

    if (n <= 0) {
        printf("0-ees ih too oruul.\n");
        return 1;
    }

    int a[n];

    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    quicksort(a, 0, n - 1); 

    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\n");
    return 0;
}