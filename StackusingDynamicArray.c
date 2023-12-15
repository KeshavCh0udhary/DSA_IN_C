#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

typedef struct Stack {
  int top;
  int size;
  int *array;
} Stack;

Stack *create_stack() {
  Stack *stack = (Stack *)malloc(sizeof(Stack));
  stack->array = (int *)malloc(sizeof(int) * SIZE);
  stack->top = -1;
  stack->size = 1;
  return stack;
}

int is_empty(Stack *stack) {
  return stack->top == -1;
}

void resize(Stack* stack) {
  stack->array = (int*)realloc(stack->array, stack->size * 2 * sizeof(int));
}

void push(Stack *stack, int element) {
  if (stack->size == stack->top + 1) {
    //Increasing size of Dynamic array
    resize(stack);
  }

  stack->array[++stack->top] = element;
  stack->size++;
}

int pop(Stack *stack) {
  if (is_empty(stack)) {
    printf("Stack underflow\n");
    return -1;
  }

  int element = stack->array[stack->top--];
  stack->size--;
  return element;
}

int peek(Stack *stack) {
  if (is_empty(stack)) {
    printf("Stack is empty!\n");
    return -1;
  }
  return stack->array[stack->top];
}

void free_stack(Stack *stack) {
  free(stack->array);
  free(stack);
}

int main() {
  Stack *stack = create_stack();

  push(stack, 10);
  push(stack, 20);
  push(stack, 30);

  printf("%d\n", pop(stack)); // Output: 30
  printf("%d\n", pop(stack)); // Output: 20
  printf("%d\n", pop(stack)); // Output: 10
  printf("%d", pop(stack));// Output: Stack underflow -1

  free_stack(stack);

  return 0;
}
