#include <stdio.h>

int partition(int *array, int left, int right) {
  int pivot = array[right];
  int i = left - 1;

  for (int j = left; j < right; j++) {
    if (array[j] <= pivot) {
      i++;
      int temp = array[i];
      array[i] = array[j];
      array[j] = temp;
    }
  }

  int pivotIndex = i + 1;
  int temp = array[pivotIndex];
  array[pivotIndex] = array[right];
  array[right] = temp;

  return pivotIndex;
}

void quickSort(int *array, int left, int right) {
  if (left < right) {
    int pivotIndex = partition(array, left, right);
    quickSort(array, left, pivotIndex - 1);
    quickSort(array, pivotIndex + 1, right);
  }
}

int main() {
  int array[] = {5, 3, 2, 1, 4};
  int size = 5;

  quickSort(array, 0, size - 1);

  for (int i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }

  printf("\n");

  return 0;
}
