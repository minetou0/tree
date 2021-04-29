/**
 * @brief Lightweight implementation of binary tree data structure.
 **/

#ifndef TREE_H
#define TREE_H

#include <stdbool.h>

typedef struct tree_s tree;

/* constructor */
tree *tree_new(void *data);
tree *tree_copy(tree *t);
bool tree_equal(tree *t1, tree *t2);

/* accessor */
tree *tree_left(tree *t);
tree *tree_right(tree *t);
tree *tree_parent(tree *t);
void *tree_value(tree *t);
bool tree_is_leaf(const tree *t);
bool tree_is_root(const tree *t);

/* modificator */
void tree_set_left(tree *t, tree *left);
void tree_set_right(tree *t, tree *right);
void tree_set_value(tree *t, void *data);

/* misc */
int tree_height(const tree *t);
int tree_nnodes(const tree *t);
tree *tree_root(tree *t);
void tree_unlink(tree *t);

/* destructor */
void tree_free(tree *t);
void tree_free_full(tree *t, void (*destroy)(void *));

#endif
