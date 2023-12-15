#include <stdio.h>
#define MAX 10

int arr[MAX];
int front=-1, rear=-1;

void display() {
  printf("\n front:  ");
  for (int i = 0; i < MAX; i++){
    printf("  %d", arr[i]);
  }
  printf("  :rear");
}

int count() {
  int c = 0;

  for (int i = 0; i < MAX; i++) {
    if (arr[i] != 0){
      c++;
    }
  }
  return c;
}

void addFront(int item) {
  int k, c;

  if (front == 0 && rear == MAX - 1) {
    printf("\nDeque overflow.\n");
    return;
  }

  if (front == -1) {
    front = rear = 0;
    arr[front] = item;
    return;
  }

  if (rear != MAX - 1) {
    c = count();
    k = rear + 1;
    for (int i = 1; i <= c; i++) {
      arr[k] = arr[k - 1];
      k--;
    }
    arr[k] = item;
    front = k;
    rear++;
  } else {
    front--;
    arr[front] = item;
  }
}

void addRear(int item) {
  int k;

  if (front == 0 && rear == MAX - 1) {
    printf("\nDeque overflow.\n");
    return;
  }

  if (front == -1) {
    rear = front = 0;
    arr[rear] = item;
    return;
  }

  if (rear == MAX - 1) {
    k = front - 1;
    for (int i = front - 1; i < rear; i++) {
      k = i;
      if (k == MAX - 1)
        arr[k] = 0;
      else
        arr[k] = arr[i + 1];
    }
    rear--;
    front--;
  }
  rear++;
  arr[rear] = item;
}

int delFront() {
  int item;

  if (front == -1) {
    printf("\nDeque underflow.\n");
    return 0;
  }

  item = arr[front];
  arr[front] = 0;

  if (front == rear){
    front = rear = -1;
  }
  else{
    front++;
  }
  return item;
}

int delRear() {
  int item;

  if (front == -1) {
    printf("\nDeque underflow\n");
    return 0;
  }

  item = arr[rear];
  arr[rear--] = 0;
  if (rear == -1){
    front = -1;
  }
  return item;
}


int main() {
  int i;
   
  front = rear = -1;
  for (i = 0; i < MAX; i++){
    arr[i] = 0;  //Initializing each element to 0 for tacking front & rear
  }

  addRear(5);
  printf("\nElements in a deque: ");
  display();
  addFront(12);
  printf("\nElements in a deque: ");
  display();
  addRear(11);
  printf("\nElements in a deque: ");
  display();

  i = delFront();
  printf("\nremoved item: %d", i);

  printf("\nElements in a deque after deletion: ");
  display();

  addRear(16);
  printf("\nElements in a deque: ");
  display();

  i = delRear();
  printf("\nremoved item: %d", i);

  printf("\nElements in a deque after deletion: ");
  display();

  int n = count();
  printf("\nTotal number of elements in deque: %d", n);
}

/*
Heap treee ate those in which the all nodes are greater than its parent
*/