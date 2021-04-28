#define __USE_GNU
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tree.h"

/* ********** ASSERT ********** */

#define ASSERT(expr)                                                                  \
  do                                                                                  \
  {                                                                                   \
    if ((expr) == 0)                                                                  \
    {                                                                                 \
      fprintf(stderr, "[%s:%d] Assertion '%s' failed!\n", __FILE__, __LINE__, #expr); \
      abort();                                                                        \
    }                                                                                 \
  } while (0)

/* ********** TEST NEW & FREE ********** */

bool test_new_free(void)
{
  tree *o = tree_new("o");
  tree *a = tree_new("a");
  tree *b = tree_new("b");
  tree_set_left(o, a);
  tree_set_right(o, b);
  tree_free(o);
  return true;
}

/* ********** USAGE ********** */

void usage(int argc, char *argv[])
{
  fprintf(stderr, "Usage: %s <testname> [<...>]\n", argv[0]);
  exit(EXIT_FAILURE);
}

/* ********** MAIN ROUTINE ********** */

int main(int argc, char *argv[])
{
  if (argc == 1)
    usage(argc, argv);

  // start test
  fprintf(stderr, "=> Start test \"%s\"\n", argv[1]);
  bool ok = false;
  if (strcmp("new_free", argv[1]) == 0)
    ok = test_new_free();
  // else if (strcmp("push_head", argv[1]) == 0)
  //   ok = test_push_head(100);
  // else if (strcmp("pop_head", argv[1]) == 0)
  //   ok = test_pop_head(100);
  // else if (strcmp("push_tail", argv[1]) == 0)
  //   ok = test_push_tail(100);
  // else if (strcmp("pop_tail", argv[1]) == 0)
  //   ok = test_pop_tail(100);
  // else if (strcmp("length", argv[1]) == 0)
  //   ok = test_length(10);
  // else if (strcmp("empty", argv[1]) == 0)
  //   ok = test_empty(10);
  // else if (strcmp("clear", argv[1]) == 0)
  //   ok = test_clear(10);
  else
  {
    fprintf(stderr, "Error: test \"%s\" not found!\n", argv[1]);
    exit(EXIT_FAILURE);
  }

  // print test result
  if (ok)
  {
    fprintf(stderr, "Test \"%s\" finished: SUCCESS\n", argv[1]);
    return EXIT_SUCCESS;
  }
  else
  {
    fprintf(stderr, "Test \"%s\" finished: FAILURE\n", argv[1]);
    return EXIT_FAILURE;
  }
}
