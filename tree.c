#include <stdio.h>
#include <stdlib.h>

struct tree_node {
  int value;
  struct tree_node *parent;
  struct tree_node *left, *right;
};

typedef struct tree_node node;

node * create_node(int, node *);
void build_tree(node *);
void free_tree(node *);

int main() {
  node *root = malloc(sizeof(*root));

  build_tree(root);

  /* TODO: function that frees the tree */
  free_tree(root);
  /* free(root); */
  return 0;
}

node * create_node(int value, node *parent) {
  node *new = malloc(sizeof(*new));
  new->value = value;
  new->parent = parent;

  return new;
}

/* builds a tree with a preset of data */
void build_tree(node *root) {
  root = create_node(2, NULL);
    root->left = create_node(7, root);
      root->left->left = create_node(2, root->left);
      root->left->right = create_node(6, root->left);
        root->left->right->left = create_node(5, root->left->right);
        root->left->right->right = create_node(11, root->left->right);
    root->right = create_node(5, root);
      root->right->right = create_node(9, root->right);
        root->right->right->left = create_node(4, root->right->right);
}

/* recursively frees the tree */
void free_tree(node *root) {
}
