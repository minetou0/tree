#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "tree.h"

#define MAX(x, y) (((x) <= (y)) ? (y) : (x))

/* *********************************************************** */

struct tree_s {
  void *data;
  struct tree_s *left;
  struct tree_s *right;
  struct tree_s *parent;
};

/* *********************************************************** */

typedef struct tree_s tree;

/* *********************************************************** */

tree *tree_new(void *data) {
  tree *t = malloc(sizeof(tree));
  assert(t);
  t->data = data;
  t->left = NULL;
  t->right = NULL;
  t->parent = NULL;
  return t;
}

/* *********************************************************** */

tree *tree_left(tree *t) {
  assert(t);
  return t->left;
}

/* *********************************************************** */

tree *tree_right(tree *t) {
  assert(t);
  return t->right;
}

/* *********************************************************** */

tree *tree_parent(tree *t) {
  assert(t);
  return t->parent;
}

/* *********************************************************** */

void *tree_value(tree *t) {
  assert(t);
  return t->data;
}

/* *********************************************************** */

bool tree_is_leaf(const tree *t) { return ((t->left == NULL) && (t->right == NULL)); }

/* *********************************************************** */

bool tree_is_root(const tree *t) {
  assert(t);
  return (t->parent == NULL);
}

/* *********************************************************** */

void tree_set_left(tree *t, tree *left) {
  assert(t);
  assert(t->left == NULL);
  assert(left->parent == NULL);
  t->left = left;
  left->parent = t;
}

/* *********************************************************** */

void tree_set_right(tree *t, tree *right) {
  assert(t);
  assert(t->right == NULL);
  assert(right->parent == NULL);
  t->right = right;
  right->parent = t;
}

/* *********************************************************** */

void tree_set_value(tree *t, void *data) {
  assert(t);
  t->data = data;
}

/* *********************************************************** */

int tree_height(const tree *t) {
  /* Conventionally, an empty tree has height −1. */
  if (t == NULL) return -1;
  return MAX(tree_height(t->left) + 1, tree_height(t->right) + 1);
}

/* *********************************************************** */

int tree_nnodes(const tree *t) {
  if (t == NULL) return 0;
  return tree_nnodes(t->left) + tree_nnodes(t->right) + 1;
}

/* *********************************************************** */

tree *tree_root(tree *t) {
  assert(t);
  tree *tmp = t;
  while (tmp->parent) {
    tmp = tmp->parent;
  }
  return tmp;
}

/* *********************************************************** */

void tree_unlink(tree *t) {
  assert(t);
  if (t->parent == NULL) return;
  if (t->parent->left == t) t->parent->left = NULL;
  if (t->parent->right == t) t->parent->right = NULL;
  t->parent = NULL;
}

/* *********************************************************** */

static void tree_print_str_rec(tree *t, int depth) {
  char *str = "(null)";
  if (t) str = t->data;
  for (int k = 1; k < depth; k++) printf("  ");
  char *head = "└──";
  if (depth == 0) head = "";
  printf("%s%s\n", head, str);
  if (t == NULL) return;
  if (t && tree_is_leaf(t)) return;
  tree_print_str_rec(t->left, depth + 1);
  tree_print_str_rec(t->right, depth + 1);
}

/* *********************************************************** */

void tree_print_str(tree *t) { tree_print_str_rec(t, 0); }

/* *********************************************************** */

void tree_free(tree *t) {
  if (t && t->left) tree_free(t->left);
  if (t && t->right) tree_free(t->right);
  if (t && t->parent) t->parent = NULL;
  free(t);
}

/* *********************************************************** */

void tree_free_full(tree *t, void (*destroy)(void *)) {
  if (t && t->left) tree_free(t->left);
  if (t && t->right) tree_free(t->right);
  if (t && t->parent) t->parent = NULL;
  destroy(t->data);
  free(t);
}

/* *********************************************************** */
