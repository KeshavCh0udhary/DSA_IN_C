#include <stdio.h>

void insertionSort(int *array, int size) {
  int key, j;

  for (int i = 1; i < size; i++) {
    key = array[i];
    j = i - 1;

    while (j >= 0 && array[j] > key) {
      array[j + 1] = array[j];
      j--;
    }

    array[j + 1] = key;
  }
}

int main() {
  int array[] = {5, 3, 2, 1, 4};
  int size = 5;

  insertionSort(array, size);

  for (int i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }

  printf("\n");

  return 0;
}
