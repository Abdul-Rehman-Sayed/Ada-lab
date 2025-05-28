#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

void swap(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int a[], int left, int right) {
    int p, i, j;
    p = a[left];
    i = left + 1;
    j = right;

    while (1) {
        while (a[i] < p && i <= right) { // find elt > p
            i++;
        }
        while (a[j] > p) { // find elt < p
            j--;
        }
        if (i > j)
            break;

        swap(&a[i], &a[j]);
        i++;
        j--;
    }
    swap(&a[left], &a[j]); // swap pivot and a[j]
    return j;
}

void quicksort(int a[], int left, int right) {
    int s;
    if (left < right) {
        s = partition(a, left, right);
        quicksort(a, left, s - 1);
        quicksort(a, s + 1, right);
    }
}

void input(int a[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        a[i] = rand() % 100;
    }
}

int main() {
    int n, a[100], i;

    printf("Enter the number of elements:\n");
    scanf("%d", &n);

    printf("Randomly generated elements are:\n");
    input(a, n);

    printf("Array is\n");
    for (i = 0; i < n; i++)
        printf("%d\t", a[i]);

    clock_t start = clock();
    quicksort(a, 0, n - 1);
    clock_t end = clock();

    printf("\nSorted array is\n");
    for (i = 0; i < n; i++)
        printf("%d\t", a[i]);

    double elapsedTime = ((double)(end - start)) / CLOCKS_PER_SEC * 1000000000;
    printf("\nTotal time = %f nanoseconds\n", elapsedTime);

    return 0;
}
