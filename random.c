#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "tree_aux.h"

int main(void) {
  srand(time(NULL));

  // make tree
  printf("make random tree\n");
  tree *t = tree_random(8);

  // print tree
  tree_print_str(t);

  printf("tree height: %d\n", tree_height(t));
  printf("tree nb nodes: %d\n", tree_nnodes(t));

  // tree free
  printf("tree free\n");
  tree_free(t);

  return EXIT_SUCCESS;
}