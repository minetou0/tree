#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tree.h"
#include "tree_aux.h"

/* *********************************************************** */

bool test_new_free(void) {
  struct sample s = tree_sample();
  tree_free(s.o);
  return true;
}

/* *********************************************************** */

bool test_copy(void) {
  struct sample s = tree_sample();
  tree *oo = tree_copy(s.o);
  if (tree_equal(s.o, oo) != true) return false;
  tree_free(s.o);
  tree_free(oo);
  return true;
}

/* *********************************************************** */

bool test_equal(void) {
  struct sample s = tree_sample();
  if (tree_equal(s.o, s.o) != true) return false;
  tree_free(s.o);
  return true;
}

/* *********************************************************** */

bool test_left(void) {
  struct sample s = tree_sample();
  if (tree_left(s.o) != s.a) return false;
  if (tree_left(s.a) != s.c) return false;
  if (tree_left(s.b) != NULL) return false;
  if (tree_left(s.c) != NULL) return false;
  if (tree_left(s.d) != NULL) return false;
  if (tree_left(s.e) != s.f) return false;
  if (tree_left(s.f) != NULL) return false;
  tree_free(s.o);
  return true;
}

/* *********************************************************** */

bool test_right(void) {
  struct sample s = tree_sample();
  if (tree_right(s.o) != s.b) return false;
  if (tree_right(s.a) != s.d) return false;
  if (tree_right(s.b) != s.e) return false;
  if (tree_right(s.c) != NULL) return false;
  if (tree_right(s.d) != NULL) return false;
  if (tree_right(s.e) != NULL) return false;
  if (tree_right(s.f) != NULL) return false;
  tree_free(s.o);
  return true;
}

/* *********************************************************** */

bool test_parent(void) {
  struct sample s = tree_sample();
  if (tree_parent(s.o) != NULL) return false;
  if (tree_parent(s.a) != s.o) return false;
  if (tree_parent(s.b) != s.o) return false;
  // ...
  tree_free(s.o);
  return true;
}

/* *********************************************************** */

bool test_value(void) {
  struct sample s = tree_sample();
  if (strcmp(tree_value(s.o), "o") != 0) return false;
  if (strcmp(tree_value(s.a), "a") != 0) return false;
  if (strcmp(tree_value(s.b), "b") != 0) return false;
  // ...
  tree_free(s.o);
  return true;
}
/* *********************************************************** */

bool test_is_leaf(void) {
  struct sample s = tree_sample();
  if (tree_is_leaf(s.o) != false) return false;
  if (tree_is_leaf(s.a) != false) return false;
  if (tree_is_leaf(s.b) != false) return false;
  if (tree_is_leaf(s.c) != true) return false;
  if (tree_is_leaf(s.d) != true) return false;
  if (tree_is_leaf(s.e) != false) return false;
  if (tree_is_leaf(s.f) != true) return false;
  tree_free(s.o);
  return true;
}

/* *********************************************************** */

bool test_is_root(void) {
  struct sample s = tree_sample();
  if (tree_is_root(s.o) != true) return false;
  if (tree_is_root(s.a) != false) return false;
  if (tree_is_root(s.b) != false) return false;
  if (tree_is_root(s.c) != false) return false;
  if (tree_is_root(s.d) != false) return false;
  if (tree_is_root(s.e) != false) return false;
  if (tree_is_root(s.f) != false) return false;
  tree_free(s.o);
  return true;
}

/* *********************************************************** */

bool test_height(void) {
  struct sample s = tree_sample();
  if (tree_height(s.o) != 3) return false;
  if (tree_height(s.a) != 1) return false;
  if (tree_height(s.b) != 2) return false;
  if (tree_height(s.c) != 0) return false;
  if (tree_height(s.d) != 0) return false;
  if (tree_height(s.e) != 1) return false;
  if (tree_height(s.f) != 0) return false;
  tree_free(s.o);
  return true;
}

/* *********************************************************** */

bool test_nnodes(void) {
  struct sample s = tree_sample();
  if (tree_nnodes(s.o) != 7) return false;
  if (tree_nnodes(s.a) != 3) return false;
  if (tree_nnodes(s.b) != 3) return false;
  if (tree_nnodes(s.c) != 1) return false;
  if (tree_nnodes(s.d) != 1) return false;
  if (tree_nnodes(s.e) != 2) return false;
  if (tree_nnodes(s.f) != 1) return false;
  tree_free(s.o);
  return true;
}

/* *********************************************************** */

bool test_root(void) {
  struct sample s = tree_sample();
  if (tree_root(s.o) != s.o) return false;
  if (tree_root(s.a) != s.o) return false;
  if (tree_root(s.b) != s.o) return false;
  if (tree_root(s.c) != s.o) return false;
  if (tree_root(s.d) != s.o) return false;
  if (tree_root(s.e) != s.o) return false;
  if (tree_root(s.f) != s.o) return false;
  tree_free(s.o);
  return true;
}

/* *********************************************************** */

bool test_unlink(void) {
  struct sample s = tree_sample();
  tree_unlink(s.e);
  /* s.e becomes root of a new tree */
  if (tree_is_root(s.e) != true) return false;
  if (tree_is_leaf(s.b) != true) return false;
  if (tree_root(s.f) != s.e) return false;
  if (tree_root(s.b) != s.o) return false;
  tree_free(s.o);
  tree_free(s.e);
  return true;
}

/* *********************************************************** */

bool test_free_full(void) {
  char *so = calloc(2, sizeof(char));
  char *sa = calloc(2, sizeof(char));
  char *sb = calloc(2, sizeof(char));
  *so = 'o';
  *sa = 'a';
  *sb = 'b';
  tree *o = tree_new(so);
  tree *a = tree_new(sa);
  tree *b = tree_new(sb);
  tree_set_left(o, a);
  tree_set_right(o, b);
  if (strcmp(tree_value(o), "o") != 0) return false;
  if (strcmp(tree_value(a), "a") != 0) return false;
  if (strcmp(tree_value(b), "b") != 0) return false;
  tree_free_full(o, free);
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
  else if (strcmp("copy", argv[1]) == 0)
    ok = test_copy();
  else if (strcmp("equal", argv[1]) == 0)
    ok = test_equal();
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
  else if (strcmp("root", argv[1]) == 0)
    ok = test_root();
  else if (strcmp("unlink", argv[1]) == 0)
    ok = test_unlink();
  else if (strcmp("free_full", argv[1]) == 0)
    ok = test_free_full();
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
