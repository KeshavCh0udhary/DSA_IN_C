#include <stdio.h>

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int swapped = 0;
      
        for (int j = 0; j < n - i - 1; j++) {
    
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
      
        if (swapped == 0) {
            break;
        }
    }
}

int main() {
    int arr[] = {43, 29, 9, 89, 22, 11, 90};
    int n = 7;

    bubbleSort(arr, n);

    printf("Sorted array is: ");
    for (int i = 0; i<n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}