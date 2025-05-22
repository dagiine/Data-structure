#include "binary_search_tree.h"
#include <stdio.h>
#include <stdlib.h>

// Pre-order traversal
void preorder(Node *nd) {
  if (nd == NULL)
    return;
  printf("%d ", nd->value);
  preorder(nd->left);
  preorder(nd->right);
}

// In-order traversal
void inorder(Node *nd) {
  if (nd == NULL)
    return;
  inorder(nd->left);
  printf("%d ", nd->value);
  inorder(nd->right);
}

// Post-order traversal
void postorder(Node *nd) {
  if (nd == NULL)
    return;
  postorder(nd->left);
  postorder(nd->right);
  printf("%d ", nd->value);
}

// int утгатай шинэ node үүсгэх
Node *newNode(int value) {
  Node *t = (Node *)malloc(sizeof(Node));
  t->value = value;
  t->parent = NULL;
  t->left = NULL;
  t->right = NULL;
  return t;
}

// Модонд элемент нэмэх
Node *insert(Node *n, int value) {
  if (n == NULL)
    return newNode(value);

  if (value < n->value) {
    Node *leftChild = insert(n->left, value);
    n->left = leftChild;
    leftChild->parent = n;
  } else if (value > n->value) {
    Node *rightChild = insert(n->right, value);
    n->right = rightChild;
    rightChild->parent = n;
  }
  return n;
}

// Модноос элемент хайх
Node *search(Node *nd, int x) {
  if (nd == NULL || nd->value == x)
    return nd;

  if (x < nd->value)
    return search(nd->left, x);
  else
    return search(nd->right, x);
}

// а node-г b node-р солих
void replace(Node *a, Node *b) {
  if (a->parent != NULL) {
    if (a == a->parent->left)
      a->parent->left = b;
    else
      a->parent->right = b;
  }
  if (b != NULL)
    b->parent = a->parent;
}

// Модны оройг олох
Node *findRoot(Node *nd) {
  if (nd == NULL)
    return NULL;
  while (nd->parent != NULL)
    nd = nd->parent;
  return nd;
}

// Модны хамгийн их элемент
Node *bstMax(Node *n) {
  if (n == NULL)
    return NULL;
  while (n->right != NULL)
    n = n->right;
  return n;
}

// Модны хамгийн бага элемент
Node *bstMin(Node *n) {
  if (n == NULL)
    return NULL;
  while (n->left != NULL)
    n = n->left;
  return n;
}

// Модноос параметраар ирсэн node-г хасах
Node *removeNode(Node *n) {
  if (n->left == NULL && n->right == NULL) {
    replace(n, NULL);
  } else if (n->left == NULL) {
    replace(n, n->right);
  } else if (n->right == NULL) {
    replace(n, n->left);
  } else {
    Node *minRight = bstMin(n->right);
    if (minRight->parent != n) {
      replace(minRight, minRight->right);
      minRight->right = n->right;
      if (minRight->right)
        minRight->right->parent = minRight;
    }
    replace(n, minRight);
    minRight->left = n->left;
    if (minRight->left)
      minRight->left->parent = minRight;
  }
  free(n);
  return n;
}

// Модноос элемент утгаар нь хайж хасах
Node *removeValue(Node *root, int x) {
  Node *target = search(root, x);
  if (target == NULL) return root;

  int isRoot = (target->parent == NULL);
  removeNode(target);
  
  if (isRoot) {
    return findRoot(target->left ? target->left : target->right);
  }
  return findRoot(root);
}

// Модны элементийн тоо
int count(Node *nd) {
  if (nd == NULL)
    return 0;
  return 1 + count(nd->left) + count(nd->right);
}

// Модны өндөр
int height(Node *nd) {
  if (nd == NULL)
    return -1;
  int leftHeight = height(nd->left);
  int rightHeight = height(nd->right);
  return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}