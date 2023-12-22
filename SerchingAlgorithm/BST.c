#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node* left;
  struct Node* right;
} Node;

Node* insert(Node* root, int data) {
  if (root == NULL) {
    root = (Node*)malloc(sizeof(Node));
    root->data = data;
    root->left = NULL;
    root->right = NULL;
    return root;
  }
  if (data < root->data) {
    root->left = insert(root->left, data);
  } else {
    root->right = insert(root->right, data);
  }
  return root;
}

int search(Node* root, int data) {
  if (root == NULL) {
    return 0;
  }
  if (data == root->data) {
    return 1;
  } else if (data < root->data) {
    return search(root->left, data);
  } else {
    return search(root->right, data);
  }
}


Node* findMin(Node* root) {
  if (root == NULL) {
    return NULL;
  }
  while (root->left) {
    root = root->left;
  }
  return root;
}
/*
Node* remove(Node* root, int data) {
  if (root == NULL) {
    return NULL;
  }
  if (data < root->data) {
    root->left = remove(root->left, data);
  } else if (data > root->data) {
    root->right = remove(root->right, data);
  } else {
    // Found the node to delete
    if (root->left == NULL && root->right == NULL) {
      free(root);
      return NULL;
    } else if (root->left == NULL) {
      Node* temp = root->right;
      free(root);
      return temp;
    } else if (root->right == NULL) {
      Node* temp = root->left;
      free(root);
      return temp;
    } else {
      // Two children
      Node* successor = findMin(root->right);
      root->data = successor->data;
      root->right = remove(root->right, successor->data);
    }
  }
  return root;
}
*/
void printTree(Node* root) {
  if (root == NULL) {
    return;
  }
  printf("%d ", root->data);
  printTree(root->left);
  printTree(root->right);
}

int main() {nj
  Node* root = NULL;

  root = insert(root, 5);
  root = insert(root, 2);
  root = insert(root, 7);
  root = insert(root, 3);
  root = insert(root, 8);

  if (search(root, 7)) {
    printf("7 is present in the tree.\n");
  } else {
    printf("7 is not present in the tree.\n");
  }

  printTree(root);

  free(root);

  return 0;
}
