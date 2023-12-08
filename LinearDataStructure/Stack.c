#include <stdio.h>

#define MAX_SIZE 100

typedef struct stack {
  int data[MAX_SIZE];
  int top;
} stack;

void push(stack *s, int data) {
  if (s->top == MAX_SIZE - 1) {
    printf("Stack overflow.\n");
    return;
  }
  s->data[++s->top] = data;
}

int pop(stack *s) {
  if (s->top == -1) {
    printf("Stack underflow.\n");
    return -1;
  }

  int data = s->data[s->top--];
  return data;
}

int peek(stack *s) {
  if (s->top == -1) {
    printf("Stack empty.\n");
    return -1;
  }

  return s->data[s->top];
}

int is_empty(stack *s) {
  return s->top == -1;
}

void print_stack(stack *s) {
  for (int i = s->top; i >= 0; i--) {
    printf("%d ", s->data[i]);
  }
  printf("\n");
}

int main() {
  stack s;
  s.top = -1;

  int choice, data;

  while (1) {
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Peek\n");
    printf("4. Is empty\n");
    printf("5. Print stack\n");
    printf("6. Exit\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("Enter the data to be pushed: ");
        scanf("%d", &data);
        push(&s, data);
        break;
      case 2:
        data = pop(&s);
        if (data != -1) {
          printf("Popped element: %d\n", data);
        }
        break;
      case 3:
        data = peek(&s);
        if (data != -1) {
          printf("Top element: %d\n", data);
        }
        break;
      case 4:
        if (is_empty(&s)) {
          printf("Stack is empty.\n");
        } else {
          printf("Stack is not empty.\n");
        }
        break;
      case 5:
        print_stack(&s);
        break;
      case 6:
        return -1;
        break;
      default:
        printf("Invalid choice.\n");
    }
  }

  return 0;
}
