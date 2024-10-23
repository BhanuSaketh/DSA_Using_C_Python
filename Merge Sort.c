#include <stdio.h>
#include <stdlib.h>

int a[100], b[100], n;

void display() {
        for (int i = 0; i < n; i++) {
            printf("%d ", a[i]);
        }
}

void merge(int low, int mid, int high) {
    int n1 = low; 
    int n2 = mid + 1; 
    int i = 0; 

    while (n1 <= mid && n2 <= high) {
        if (a[n1] <= a[n2]) {
            b[i++] = a[n1++];
        } else {
            b[i++] = a[n2++];
        }
    }

    while (n1 <= mid) {
        b[i++] = a[n1++];
    }

    while (n2 <= high) {
        b[i++] = a[n2++];
    }

    for (int j = 0; j < i; j++) {
        a[low + j] = b[j];
    }
}

void mergesort(int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        mergesort(low, mid);
        mergesort(mid + 1, high);
        merge(low, mid, high);
    }
}

int main() {
    printf("Enter Number of Elements: ");
    scanf("%d", &n);
    printf("Enter array Elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    printf("Unsorted arrya:");
    display();
    printf("\n")
    mergesort(0, n - 1);
    printf("Sorted array: ");
    display();

    return 0;
}
