#include <stdio.h>

#define MAX_SIZE 100

typedef struct queue {
  int data[MAX_SIZE];
  int front, rear;
} queue;

void enqueue(queue *q, int data) {
  if (q->rear == MAX_SIZE - 1) {
    printf("Queue overflow.\n");
    return;
  }

  q->rear++;
  q->data[q->rear] = data;
}

int dequeue(queue *q) {
  if (q->front == q->rear) {
    printf("Queue underflow.\n");
    return -1;
  }

  int data = q->data[q->front];
  q->front++;
  return data;
}

int peek(queue *q) {
  if (q->front == q->rear) {
    printf("Queue empty.\n");
    return -1;
  }

  return q->data[q->front];
}

int is_empty(queue *q) {
  return q->front == q->rear;
}

void print_queue(queue *q) {
  for (int i = q->front; i < q->rear; i++) {
    printf("%d ", q->data[i]);
  }
  printf("\n");
}

int main() {
  queue q;
  q.front = 0;
  q.rear = 0;

  int choice, data;

  while (1) {
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Peek\n");
    printf("4. Is empty\n");
    printf("5. Print queue\n");
    printf("6. Exit\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("Enter the data to be enqueued: ");
        scanf("%d", &data);
        enqueue(&q, data);
        break;
      case 2:
        data = dequeue(&q);
        if (data != -1) {
          printf("Dequeued element: %d\n", data);
        }
        break;
      case 3:
        data = peek(&q);
        if (data != -1) {
          printf("Front element: %d\n", data);
        }
        break;
      case 4:
        if (is_empty(&q)) {
          printf("Queue is empty.\n");
        } else {
          printf("Queue is not empty.\n");
        }
        break;
      case 5:
        print_queue(&q);
        break;
      case 6:
        exit(0);
        break;
      default:
        printf("Invalid choice.\n");
    }
  }

  return 0;
}
