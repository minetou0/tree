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

tree *sample1(void) {
  tree *o = tree_new("o");
  tree *a = tree_new("a");
  tree *b = tree_new("b");
  tree_set_left(o, a);
  tree_set_right(o, b);
  return o;
}

/* *********************************************************** */

tree *sample2(void) {
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

bool test_new_free_1(void) {
  tree *root = sample1();
  tree_free(root);
  return true;
}

/* *********************************************************** */

bool test_new_free_2(void) {
  tree *root = sample2();
  tree_free(root);
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
  if (strcmp("new_free_1", argv[1]) == 0)
    ok = test_new_free_1();
  else if (strcmp("new_free_2", argv[1]) == 0)
    ok = test_new_free_2();
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
