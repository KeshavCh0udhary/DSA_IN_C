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
    int arr[] = {73,49, 53, 12,48,10,84,70,20,16};
    int n = 10;

    bubbleSort(arr, n);

    printf("Sorted array is: ");
    for (int i = 0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    // Output: Sorted array is: 10 12 16 20 48 49 53 70 73 84
    return 0;
}