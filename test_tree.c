#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tree.h"

/* *********************************************************** */

bool test_new_free(void) {
  tree *o = tree_new("o");
  tree *a = tree_new("a");
  tree *b = tree_new("b");
  tree *c = tree_new("c");
  tree *d = tree_new("d");
  tree *e = tree_new("e");
  tree *f = tree_new("f");
  tree_set_left(o, a);
  tree_set_right(o, b);
  tree_set_left(a, c);
  tree_set_right(a, d);
  tree_set_right(b, e);
  tree_set_left(e, f);
  tree_free(o);
  return true;
}

/* *********************************************************** */

bool test_left(void) {
  tree *o = tree_new("o");
  tree *a = tree_new("a");
  tree *b = tree_new("b");
  tree_set_left(o, a);
  tree_set_right(o, b);
  if (tree_left(o) != a) return false;
  tree_free(o);
  return true;
}

/* *********************************************************** */

bool test_right(void) {
  tree *o = tree_new("o");
  tree *a = tree_new("a");
  tree *b = tree_new("b");
  tree_set_left(o, a);
  tree_set_right(o, b);
  if (tree_right(o) != b) return false;
  tree_free(o);
  return true;
}

/* *********************************************************** */

bool test_parent(void) {
  tree *o = tree_new("o");
  tree *a = tree_new("a");
  tree *b = tree_new("b");
  tree_set_left(o, a);
  tree_set_right(o, b);
  if (tree_parent(o) != NULL) return false;
  if (tree_parent(a) != o) return false;
  if (tree_parent(b) != o) return false;
  tree_free(o);
  return true;
}

/* *********************************************************** */

bool test_value(void) {
  tree *o = tree_new("o");
  tree *a = tree_new("a");
  tree *b = tree_new("b");
  tree_set_left(o, a);
  tree_set_right(o, b);
  if (strcmp(tree_value(o), "o") != 0) return false;
  if (strcmp(tree_value(a), "a") != 0) return false;
  if (strcmp(tree_value(b), "b") != 0) return false;
  tree_free(o);
  return true;
}
/* *********************************************************** */

bool test_is_leaf(void) {
  tree *o = tree_new("o");
  tree *a = tree_new("a");
  tree *b = tree_new("b");
  tree_set_left(o, a);
  tree_set_right(a, b);
  if (tree_is_leaf(o) != false) return false;
  if (tree_is_leaf(a) != false) return false;
  if (tree_is_leaf(b) != true) return false;
  tree_free(o);
  return true;
}

/* *********************************************************** */

bool test_is_root(void) {
  tree *o = tree_new("o");
  tree *a = tree_new("a");
  tree *b = tree_new("b");
  tree_set_left(o, a);
  tree_set_right(a, b);
  if (tree_is_root(o) != true) return false;
  if (tree_is_root(a) != false) return false;
  if (tree_is_root(b) != false) return false;
  tree_free(o);
  return true;
}

/* *********************************************************** */

bool test_height(void) {
  tree *o = tree_new("o");
  tree *a = tree_new("a");
  tree *b = tree_new("b");
  tree *c = tree_new("c");
  tree *d = tree_new("d");
  tree *e = tree_new("e");
  tree *f = tree_new("f");
  tree_set_left(o, a);
  tree_set_right(a, b);
  tree_set_left(b, c);
  tree_set_right(c, d);
  tree_set_right(d, e);
  tree_set_left(e, f);
  if (tree_height(o) != 6) return false;
  tree_free(o);
  return true;
}

/* *********************************************************** */

bool test_nnodes(void) { return true; }

/* *********************************************************** */

void usage(int argc, char *argv[]) {
  fprintf(stderr, "Usage: %s <testname> [<...>]\n", argv[0]);
  exit(EXIT_FAILURE);
}

/* *********************************************************** */

int main(int argc, char *argv[]) {
  if (argc == 1) usage(argc, argv);

  // start test
  fprintf(stderr, "=> Start test \"%s\"\n", argv[1]);
  bool ok = false;
  if (strcmp("new_free", argv[1]) == 0)
    ok = test_new_free();
  else if (strcmp("left", argv[1]) == 0)
    ok = test_left();
  else if (strcmp("right", argv[1]) == 0)
    ok = test_right();
  else if (strcmp("parent", argv[1]) == 0)
    ok = test_parent();
  else if (strcmp("value", argv[1]) == 0)
    ok = test_value();
  else if (strcmp("is_leaf", argv[1]) == 0)
    ok = test_is_leaf();
  else if (strcmp("is_root", argv[1]) == 0)
    ok = test_is_root();
  else if (strcmp("height", argv[1]) == 0)
    ok = test_height();
  else if (strcmp("nnodes", argv[1]) == 0)
    ok = test_nnodes();
  else {
    fprintf(stderr, "Error: test \"%s\" not found!\n", argv[1]);
    exit(EXIT_FAILURE);
  }

  // print test result
  if (ok) {
    fprintf(stderr, "Test \"%s\" finished: SUCCESS\n", argv[1]);
    return EXIT_SUCCESS;
  } else {
    fprintf(stderr, "Test \"%s\" finished: FAILURE\n", argv[1]);
    return EXIT_FAILURE;
  }
}
