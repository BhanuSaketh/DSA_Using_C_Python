#include <stdio.h>

int a[100], n;

void display() {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
}

int partition(int low, int high) {
    int pivot = a[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (a[j] <= pivot) {
            i++;
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    
    int temp = a[i + 1];
    a[i + 1] = a[high];
    a[high] = temp;
    
    return i + 1;
}

void quicksort(int low, int high) {
    if (low < high) {
        int pi = partition(low, high);
        quicksort(low, pi - 1);
        quicksort(pi + 1, high);
    }
}

int main() {
    printf("Enter Number of Elements: ");
    scanf("%d", &n);
    printf("Enter array Elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    printf("Unsorted array: ");
    display();
    printf("\n");

    quicksort(0, n - 1);

    printf("Sorted array: ");
    display();
    printf("\n");

    return 0;
}
