#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "tree.h"
#include "tree_aux.h"

int main(void) {
  srand(time(NULL));

  // make tree
  printf("make random tree\n");
  tree *t = tree_random_int(4, 100);

  // print tree
  printf("print tree\n");
  tree_print_int(t);
  printf("tree height: %d\n", tree_height(t));
  printf("tree nb nodes: %d\n", tree_nnodes(t));

  // save tree
  const char *filename = "random.tree";
  printf("save tree: %s\n", filename);
  tree_save_int(t, filename);

  // free it
  printf("free\n");
  tree_free_full(t, free);

  return EXIT_SUCCESS;
}