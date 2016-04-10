#include <stdio.h>

void quicksort(int [], int, int);

int main() {
    int x[20], size, i;

    printf("Enter size of the array: ");
    scanf("%d", &size);

    printf("Ener %d elements: ", size);
    for (i = 0; i < size; i++)
        scanf("%d", &x[i]);
    quicksort(x, 0, size-1);

    printf("Sorted elements: ");
    for (i = 0; i < size; i++)
        printf(" %d", x[i]);
    return 0;
}

void quicksort(int x[], int first, int last) {
    int pivot, j, temp, i;

    if (first < last) {
        pivot=first;
        i = first;
        j = last;

        while (i < j) {
            while (x[i] < x[pivot] && i < last)
                i++;
            while(x[j] > x[pivot])
                j--;
            if (i < j) {
                temp = x[i];
                x[i] = x[j];
                x[j] = temp;
            }
        }
