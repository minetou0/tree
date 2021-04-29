#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "tree_aux.h"

int main(void) {
  // make tree
  printf("make tree\n");
  struct sample s = tree_sample();

  // print tree
  tree_print_str(s.o);

  printf("tree height: %d\n", tree_height(s.o));
  printf("tree nb nodes: %d\n", tree_nnodes(s.o));

  tree *r = tree_root(s.f);
  printf("tree root: \"%s\"\n", (char *)tree_value(r));

  // tree free
  printf("tree free\n");
  tree_free(s.o);

  return EXIT_SUCCESS;
}