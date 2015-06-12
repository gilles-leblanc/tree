#include <stdio.h>
#include <stdlib.h>

struct tree_node {
  int value;
  struct tree_node *parent;
  struct tree_node *left, *right;
};

typedef struct tree_node node;
typedef void (*node_func)(node *);

node * create_node(int, node *);
node * build_tree();
void depth_first_pre(node *, node_func);
void depth_first_post(node *, node_func);
void print_node(node *);
void free_node(node *);

int main() {
  node *root = build_tree();

  depth_first_pre(root, print_node);

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

void print_node(node *current) {
  printf("%d, ", current->value);
}

void free_node(node *current) {
  free(current);
}
