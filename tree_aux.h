#ifndef TREE_AUX_H
#define TREE_AUX_H

#include "tree.h"

tree *tree_random_int(int maxheight, int maxvalue);
void tree_print_str(tree *t);
void tree_print_int(tree *t);
void tree_save_int(tree *t, const char *filename);
tree *tree_load_int(const char *filename);

#endif
