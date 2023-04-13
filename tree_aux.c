#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "tree.h"
#include "tree_aux.h"

/* *********************************************************** */

static void tree_print_str_rec(tree *t, int depth) {
  if (t == NULL) return;
  char *str = tree_value(t);
  for (int k = 1; k < depth; k++) printf("  ");
  char *head = "└──";
  if (depth == 0) head = "";
  printf("%s%s\n", head, str);
  if (tree_is_leaf(t)) return;
  tree_print_str_rec(tree_left(t), depth + 1);
  tree_print_str_rec(tree_right(t), depth + 1);
}

void tree_print_str(tree *t) { tree_print_str_rec(t, 0); }

/* *********************************************************** */

static void tree_print_int_rec(tree *t, int depth) {
  if (t == NULL) return;
  int *val = tree_value(t);
  if (val == NULL) return;
  for (int k = 1; k < depth; k++) printf("  ");
  char *head = "└──";
  if (depth == 0) head = "";
  printf("%s%d\n", head, *val);
  if (tree_is_leaf(t)) return;
  tree_print_int_rec(tree_left(t), depth + 1);
  tree_print_int_rec(tree_right(t), depth + 1);
}

void tree_print_int(tree *t) { tree_print_int_rec(t, 0); }

/* *********************************************************** */

static tree *tree_random_rec(int n, int maxvalue) {
  if (n == 0) return NULL;
  int *val = malloc(sizeof(int));
  *val = rand() % maxvalue;
  tree *t = tree_new(val);
  bool left = (rand() % 2 == 0);
  bool right = (rand() % 2 == 0);
  if(!left) right = true; // enforce at least one child
  if (left) tree_set_left(t, tree_random_rec(n - 1, maxvalue));
  if (right) tree_set_right(t, tree_random_rec(n - 1, maxvalue));
  return t;
}

/* *********************************************************** */

tree *tree_random_int(int height, int maxvalue) { return tree_random_rec(height + 1, maxvalue); }

/* *********************************************************** */

static void tree_save_int_rec(tree *t, FILE *file) {
  if (t == NULL) {
    fprintf(file, "N\n");
    return;
  }
  int val = *((int *)tree_value(t));  // assuming the data is an integer
  fprintf(file, "%d\n", val);
  tree_save_int_rec(tree_left(t), file);
  tree_save_int_rec(tree_right(t), file);
}

/* *********************************************************** */

void tree_save_int(tree *t, const char *filename) {
  FILE *file = fopen(filename, "w");
  assert(file);
  tree_save_int_rec(t, file);
  fclose(file);
}

/* *********************************************************** */

#define MAXLINE 100

static tree *tree_load_int_rec(FILE *file) {
  char line[MAXLINE];
  char *res = fgets(line, MAXLINE, file);
  assert(res);

  char c;
  sscanf(line, " %c", &c);
  if (c == 'N') return NULL;

  int *data = malloc(sizeof(int));  // assuming the data is an integer
  assert(data);
  int ret = sscanf(line, " %d", data);
  assert(ret == 1);
  tree *t = tree_new(data);
  assert(t);

  tree_set_left(t, tree_load_int_rec(file));
  tree_set_right(t, tree_load_int_rec(file));

  return t;
}

/* *********************************************************** */

tree *tree_load_int(const char *filename) {
  FILE *file = fopen(filename, "r");
  assert(file);
  tree *t = tree_load_int_rec(file);
  fclose(file);
  return t;
}

/* *********************************************************** */
