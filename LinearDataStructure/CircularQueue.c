#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1, size = 0;

int isFull() {
  return size == SIZE;
}

int isEmpty() {
  return size == 0;
}

void enqueue(int data) {

  if(isFull()){
     printf("Queue overflow\n");
     return;
  }

  if(rear == SIZE-1) {
    rear = -1;
  }

  queue[++rear] = data;
  size++;
  
  if(front == -1){
    front++;
  }

}

int dequeue() {
  if (isEmpty()) {
    printf("Queue underflow!\n");
    front = -1;
    return -1;
  }

  int data = queue[front];
  front++;

  if(front == SIZE-1){
    front = 0;
  }

  size--;
  return data;

}

void print_queue() {
 if (isEmpty()) {
    printf("Queue is empty.\n");
    return;
  }
  int i = front;
  do {
    printf("%d -> ", queue[i]);
    i = (i + 1) % SIZE;
  } while (i != front && i != rear);

}

int main() {
  
  dequeue(); // Output: Queue underflow!
  enqueue(10);
  enqueue(20);
  enqueue(30);
  enqueue(40);
  dequeue();
  enqueue(50);
  enqueue(60);
  enqueue(70);//Output: Queue overflow!
  print_queue();// Output: 20 30 40 50 60  // Inside array the actual order is [60, 20, 30, 40, 50]
 


  
  return 0;
}

/*

int choice, data;

  while (1) {
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Print queue\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("Enter the data to be enqueued: ");
        scanf("%d", &data);
        enqueue(data);
        break;
      case 2:
        data = dequeue();
        if (data != -1) {
          printf("Dequeued element: %d\n", data);
        }
        break;
      case 3:
        print_queue();
        break;
      default:
         printf("Invalid input");
       return -1;
    }
  }
*/