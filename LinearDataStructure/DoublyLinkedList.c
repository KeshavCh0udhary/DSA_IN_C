#include <stdio.h>

struct Node {
  int data;
  struct Node *prev;
  struct Node *next;
};

struct Node *head = NULL;

void insertAtBeginning(int data) {
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->prev = NULL;
  newNode->next = head;

  if (head != NULL) {
    head->prev = newNode;
  }

  head = newNode;
}

void insertAtEnd(int data) {
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->prev = NULL;
  newNode->next = NULL;

  if (head == NULL) {
    head = newNode;
    return;
  }

  struct Node *currentNode = head;
  while (currentNode->next != NULL) {
    currentNode = currentNode->next;
  }

  currentNode->next = newNode;
  newNode->prev = currentNode;
}

void insertAfter(struct Node *previousNode, int data) {
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->prev = previousNode;
  newNode->next = previousNode->next;

  if (previousNode->next != NULL) {
    previousNode->next->prev = newNode;
  }

  previousNode->next = newNode;
}

void deleteAtBeginning() {
  if (head == NULL) {
    return;
  }

  struct Node *currentNode = head;
  head = head->next;

  if (head != NULL) {
    head->prev = NULL;
  }

  free(currentNode);
}

void deleteAtEnd() {
  if (head == NULL) {
    return;
  }

  struct Node *currentNode = head;
  while (currentNode->next != NULL) {
    currentNode = currentNode->next;
  }

  if (head == currentNode) {
    head = NULL;
    free(currentNode);
    return;
  }

  currentNode->prev->next = NULL;
  free(currentNode);
}

void deleteAfter(struct Node *previousNode) {
  if (previousNode == NULL || previousNode->next == NULL) {
    return;
  }

  struct Node *currentNode = previousNode->next;
  previousNode->next = currentNode->next;

  if (currentNode->next != NULL) {
    currentNode->next->prev = previousNode;
  }

  free(currentNode);
}

void printDoublyLinkedList() {
  struct Node *currentNode = head;

  while (currentNode != NULL) {
    printf("%d ", currentNode->data);
    currentNode = currentNode->next;
  }

  printf("\n");
}

int main() {
  insertAtBeginning(10);
  insertAtEnd(20);
  insertAfter(head, 30);

  printDoublyLinkedList();

  deleteAtBeginning();
  deleteAtEnd();
  deleteAfter(head);

  printDoublyLinkedList();

  return 0;
}
