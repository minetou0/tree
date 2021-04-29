#ifndef TREE_AUX_H
#define TREE_AUX_H

#include "tree.h"

struct sample {
  tree *o, *a, *b, *c, *d, *e, *f;
};

/*
        o
       / \
      a   b
     / \   \
    c   d   e
           /
          f
*/

struct sample tree_sample();

void tree_print_str(tree *t);

#endif
