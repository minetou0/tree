#define __USE_GNU
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tree.h"

/* *********************************************************** */

#define ASSERT(expr)                                                                  \
  do {                                                                                \
    if ((expr) == 0) {                                                                \
      fprintf(stderr, "[%s:%d] Assertion '%s' failed!\n", __FILE__, __LINE__, #expr); \
      abort();                                                                        \
    }                                                                                 \
  } while (0)

/* *********************************************************** */

static tree *sample(void) {
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
  return o;
}

/* *********************************************************** */

bool test_new_free(void) {
  tree *root = sample();
  tree_free(root);
  return true;
}

/* *********************************************************** */

bool test_left(void) {
  tree *o = tree_new("o");
  tree *a = tree_new("a");
  tree *b = tree_new("b");
  tree_set_left(o, a);
  tree_set_right(o, b);
  ASSERT(tree_left(o) == a);
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
  ASSERT(tree_right(o) == b);
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
  ASSERT(tree_parent(o) == NULL);
  ASSERT(tree_parent(a) == o);
  ASSERT(tree_parent(b) == o);
  tree_free(o);
  return true;
}

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
