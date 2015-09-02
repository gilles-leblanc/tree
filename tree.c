#include <stdio.h>
#include <stdlib.h>
#include "queue.c"

struct tree_node {
  int value;
  struct tree_node *parent;
  struct tree_node *left, *right;
};

typedef struct tree_node node;
typedef void (*node_func)(node *);

node * create_node(int, node *);
node * build_tree();
void breadth_first(node *);
void create_or_enqueue(q_node **, node *);
void depth_first_pre(node *, node_func);
void depth_first_post(node *, node_func);
void print_node(node *);
void free_node(node *);

int main() {
  node *root = build_tree();

  // depth_first_pre(root, print_node);
  breadth_first(root);
  depth_first_post(root, free_node);

  return 0;
}

node * create_node(int value, node *parent) {
  node *new = malloc(sizeof(node));
  new->value = value;
  new->parent = parent;

  return new;
}

/* builds a tree with a preset of data */
node * build_tree() {
  node *root = create_node(2, NULL);
    root->left = create_node(7, root);
      root->left->left = create_node(2, root->left);
      root->left->right = create_node(6, root->left);
        root->left->right->left = create_node(5, root->left->right);
        root->left->right->right = create_node(11, root->left->right);
    root->right = create_node(5, root);
      root->right->right = create_node(9, root->right);
        root->right->right->left = create_node(4, root->right->right);

  return root;
}

/* function that walks tree and takes function pointer */
/* Pre-order Depth-first traversal */
void depth_first_pre(node *current, node_func func) {
  if (current == NULL) {
    return;
  }

  (func(current));

  depth_first_pre(current->left, func);
  depth_first_pre(current->right, func);
}

/* function that walks tree and takes function pointer */
/* Post-order Depth-first traversal */
void depth_first_post(node *current, node_func func) {
  if (current == NULL) {
    return;
  }

  depth_first_post(current->left, func);
  depth_first_post(current->right, func);

  (func(current));
}

/* function that walks tree and takes function pointer */
/* breadth-first traversal */
void breadth_first(node *current) {
  if (current == NULL) {
    return;
  }

  q_node *head = create_qnode(current);

  while (head != NULL) {
    q_node *q_node_ptr = dequeue(&head);
    node *node_ptr = q_node_ptr->value;
    printf("%d, ", node_ptr->value);
    q_node **head_ptr = &head;

    if (node_ptr->left != NULL) {
      create_or_enqueue(head_ptr, node_ptr->left);
    }

    if (node_ptr->right != NULL) {
      create_or_enqueue(head_ptr, node_ptr->right);
    }
  }
}

void create_or_enqueue(q_node **head, node *next_node) {
  if (*head == NULL) {
    *head = create_qnode(next_node);
  }
  else {
    enqueue(*head, create_qnode(next_node));
  }
}

void print_node(node *current) {
  printf("%d, ", current->value);
}

void free_node(node *current) {
  free(current);
}
