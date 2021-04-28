#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

/*
       root
       /  \
       a  b
      /\   \
     c  d   e
           /
          f
*/

int main(void)
{

  // build tree
  printf("build tree\n");
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

  tree_print_str(o);

  printf("tree height: %d\n", tree_height(o));
  printf("tree nb nodes: %d\n", tree_nnodes(o));

  tree * r = tree_root(f);
  printf("tree root: \"%s\"\n", (char*)tree_value(r));

  // tree free
  printf("tree free\n");
  tree_free(o);

  return EXIT_SUCCESS;
}