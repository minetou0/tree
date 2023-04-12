#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "tree.h"
#include "tree_aux.h"

/* *********************************************************** */

static void tree_print_str_rec(tree *t, int depth) {
  char *str = "(null)";
  if (t) str = tree_value(t);
  for (int k = 1; k < depth; k++) printf("  ");
  char *head = "└──";
  if (depth == 0) head = "";
  printf("%s%s\n", head, str);
  if (t == NULL) return;
  if (t && tree_is_leaf(t)) return;
  tree_print_str_rec(tree_left(t), depth + 1);
  tree_print_str_rec(tree_right(t), depth + 1);
}

void tree_print_str(tree *t) { tree_print_str_rec(t, 0); }

/* *********************************************************** */

struct sample tree_sample(void) {
  struct sample s;
  s.o = tree_new("o");
  s.a = tree_new("a");
  s.b = tree_new("b");
  s.c = tree_new("c");
  s.d = tree_new("d");
  s.e = tree_new("e");
  s.f = tree_new("f");
  tree_set_left(s.o, s.a);
  tree_set_right(s.o, s.b);
  tree_set_left(s.a, s.c);
  tree_set_right(s.a, s.d);
  tree_set_right(s.b, s.e);
  tree_set_left(s.e, s.f);
  return s;
}

/* *********************************************************** */

static tree *tree_random_rec(int n) {
  if (n == 0) return NULL;
  tree *t = tree_new("x");
  bool left = (rand() % 2 == 0);
  bool right = (rand() % 2 == 0);
  if (left) tree_set_left(t, tree_random_rec(n - 1));
  if (right) tree_set_right(t, tree_random_rec(n - 1));
  return t;
}

/* *********************************************************** */

tree *tree_random(int n) { return tree_random_rec(n); }

/* *********************************************************** */
