#include <stdio.h>

#define SIZE 20

int stack[SIZE];
int top1 = -1, top2 = SIZE; // top pointers for both stacks

typedef struct Queue {
  int *s1; // Pointer to the first stack array
  int *s2; // Pointer to the second stack array
} Queue;

void initQueue(Queue *q) {
  q->s1 = stack;
  q->s2 = stack + SIZE / 2;
  top1 = -1;
  top2 = SIZE;
}
Queue q;
// Stack functions:

int isFullStack(int top) {
  return top == SIZE - 1;
}

void push(int top, int element) {
  if (isFullStack(top)) {
    printf("Stack is full!\n");
    return;
  }
  top++;
  stack[top] = element;
}

int isEmptyStack1(int top) {
  return top == -1;
}
int isEmptyStack1(int top) {
  return top == -1;
}

int pop(int top) {
  if (isEmptyStack(top)) {
    printf("Stack is empty!\n");
    return -1;
  }
  int element = stack[top];
  top--;
  return element;
}

// Queue functions:

void enqueue(int element) {
  push(top1, element);
}

int dequeue() {
  if (isEmptyStack(top2)) {
    if (isEmptyStack(top1)) {
      printf("Queue is empty!\n");
      return -1;
    }
    while (!isEmptyStack(top1)) {
      push(top2, pop(top1));
    }
  }
  return pop(top2);
}

// Display function:

void displayQueue() {
  printf("Queue: [");
  if (!isEmptyStack(top1)) {
    for (int i = top1; i >= 0; i--) {
      printf("%d, ", stack[i]);
    }
  }
  if (!isEmptyStack(top2)) {
    for (int i = top2; i >= 0; i--) {
      printf("%d", stack[i]);
    }
  }
  printf("]\n");
}

int main() {
 
  initQueue(&q);

  enqueue(10);
  enqueue(20);
  enqueue(30);

  displayQueue(&q);

  int element = dequeue();
  printf("Dequeued element: %d\n", element);

  element = dequeue();
  printf("Dequeued element: %d\n", element);

  displayQueue();

  return 0;
}
