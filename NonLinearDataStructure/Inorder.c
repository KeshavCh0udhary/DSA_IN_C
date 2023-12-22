#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *left;
  struct Node *right;
};

void printInorder(struct Node *root) {
  if (!root) return;

  printInorder(root->left);

  printf("%d ", root->data);

  printInorder(root->right);
}
// Function to create a new Node
struct Node* newNode(int v) {
  struct Node *node = (struct Node *)malloc(sizeof(struct Node));
  node->data = v;
  node->left = NULL;
  node->right = NULL;
  return node;
}

void printPostOrder(struct Node *root) {
  if (!root) return;
  postOrder(root->left);

  postOrder(root->right);

  printf("%d ", root->data);
}

int main() {
  struct Node *root = newNode(1);
  root->left = newNode(2);
  root->right = newNode(3);
  root->left->left = newNode(4);
  root->left->right = newNode(5);
  root->right->right = newNode(6);

  printf("\nPostorder traversal of binary tree is: \n");
  printPostOrder(root);
  free(root);
  return 0;
}
