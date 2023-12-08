#include <stdio.h>

int linear_search(int *array, int size, int key) {

  for(int i=0; i<size; i++){
      if(array[i] == key) return i;
  }

  return -1;
}

int main() {
  int array[] = {1, 3, 5, 7, 9};
  int size = 5;

  int key = 5;
  int index = linear_search(array, size, key);

  if (index == -1) {
    printf("Element not found.\n");
  } else {
    printf("Element found at index %d.\n", index);
  }

  return 0;
}
