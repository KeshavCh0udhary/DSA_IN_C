#include <stdio.h>

void selectionSort(int *array, int size) {
  int min_idx, temp;

  for (int i = 0; i < size - 1; i++) {
    min_idx = i;

    for (int j = i + 1; j < size; j++) {
      if (array[j] < array[min_idx]) {
        min_idx = j;
      }
    }

    temp = array[i];
    array[i] = array[min_idx];
    array[min_idx] = temp;
  }
}

int main() {
  int array[] = {5, 3, 2, 1, 4};
  int size = 5;

  selectionSort(array, size);

  for (int i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }

  printf("\n");

  return 0;
}
