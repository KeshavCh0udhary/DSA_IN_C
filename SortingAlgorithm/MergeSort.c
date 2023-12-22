#include <stdio.h>

void merge(int *array, int left, int mid, int right) {
  int temp[right - left + 1], i = left, j = mid + 1, k = 0;

  while (i <= mid && j <= right) {
    if (array[i] <= array[j]) {
      temp[k++] = array[i++];
    } else {
      temp[k++] = array[j++];
    }
  }

  while (i <= mid) {
    temp[k++] = array[i++];
  }

  while (j <= right) {
    temp[k++] = array[j++];
  }

  for (i = left; i <= right; i++) {
    array[i] = temp[i - left];
  }
}

void mergeSort(int *array, int left, int right) {
  if (left < right) {
    int mid = (left + right) / 2;

    mergeSort(array, left, mid);
    mergeSort(array, mid + 1, right);
    merge(array, left, mid, right);
  }
}

int main() {
  int array[] = {5, 3, 6, 1, 4};
  int size = 5;

  mergeSort(array, 0, size - 1);

  for (int i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }
   
  printf("\n");
  return 0;
}
