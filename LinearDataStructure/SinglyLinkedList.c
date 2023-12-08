#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *next;
} node;

node *head = NULL;

void insert_first(int data) {
  node *new_node = (node *)malloc(sizeof(node));
  new_node->data = data;
  new_node->next = head;
  head = new_node;
}

node* create_node(int data){
  node *new_node = (node *)malloc(sizeof(node));
  new_node->data = data;
  new_node->next = NULL;
  return new_node;
}

void insert_last(node *head, int data){

  node *new_node = (node *)malloc(sizeof(node));
  new_node->data = data;
  new_node->next = NULL;

  if (head == NULL) {
    head = new_node;
  } else {
    node *current_node = head;
    while (current_node->next != NULL) {
      current_node = current_node->next;
    }
    current_node->next = new_node;
  }
}

void delete_node(int data) {
  node *current_node = head;
  node *previous_node = NULL;

  while (current_node != NULL && current_node->data != data) {
    previous_node = current_node;
    current_node = current_node->next;
  }

  if (current_node == NULL) {
    printf("Element not found.\n");
    return;
  }

  if (current_node == head) {
    head = head->next;
  } else {
    previous_node->next = current_node->next;
  }

  free(current_node);
}

void search_node(int data) {
  node *current_node = head;
  int found = 0;

  while (current_node != NULL) {
    if (current_node->data == data) {
      found = 1;
      break;
    }
    current_node = current_node->next;
  }

  if (found) {
    printf("Element found.\n");
  } else {
    printf("Element not found.\n");
  }
}

void print_linked_list() {
  node *current_node = head;

  while (current_node != NULL) {
    printf("%d ", current_node->data);
    current_node = current_node->next;
  }

  printf("\n");
}

 node * reverseLinkedList(node * head){

    node *current_node = head;
    node *previous_node = NULL;
    if(head==NULL) return NULL;

    node * previous = NULL;
    node *  next = NULL;

    while(head != NULL){

        next = head->next;
        head->next = previous;
        previous = head;
        head = next;
    }
    return previous;

 }

int main() {
  int choice, data;

  while (1) {
    printf("1. Insert at start\n");
    printf("2. Insert at end\n");
    printf("3. Delete node\n");
    printf("4. Search node\n");
    printf("5. Print linked list\n");
    printf("6. Reverse linked list\n");
    printf("7. Exit\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("Enter the data to be inserted: ");
        scanf("%d", &data);
        insert_first(data);
        break;
      case 2:
      printf("Enter the data to be inserted: ");
      scanf("%d", &data);
      insert_last(head,data);

      break;
      case 3:
        printf("Enter the data to be deleted: ");
        scanf("%d", &data);
        delete_node(data);
        break;
      case 4:
        printf("Enter the data to be searched: ");
        scanf("%d", &data);
        search_node(data);
        break;
      case 5:
        print_linked_list();
        break;
      case 6:
        head = reverseLinkedList(head);
        break;
      case 7:
        return -1;
      default:
        printf("Invalid choice.\n");
    }
  }
  return 0;
}