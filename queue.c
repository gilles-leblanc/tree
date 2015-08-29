#include <stdlib.h>

struct queue_node {
  void * value;
  struct queue_node *next;
};

typedef struct queue_node q_node;

q_node * create_qnode(void *);
void enqueue(q_node *, q_node *);
q_node * dequeue(q_node **);

q_node * create_qnode(void * value) {
  q_node *new = malloc(sizeof(q_node));
  new->value = value;

  return new;
}

void enqueue(q_node *head, q_node *new) {
  if (new == NULL || head == NULL) {
    return;
  }

  q_node *node_ptr = head;
  while (node_ptr->next != NULL) {
    node_ptr = node_ptr->next;
  }

  node_ptr->next = new;
}

q_node * dequeue(q_node **head) {
  if (*head == NULL) {
    return NULL;
  }

  q_node *old_head = *head;
  *head = (*head)->next;

  return old_head;
}

