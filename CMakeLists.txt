cmake_minimum_required(VERSION 3.0)

project("tree" C)

include(CTest)
enable_testing()

set(CMAKE_C_FLAGS "-std=c99 -Wall")

add_library(tree tree.c)
add_executable(sample sample.c)
target_link_libraries(sample tree)

add_executable(test_tree test_tree.c)
target_link_libraries(test_tree tree)

add_test(test_tree_new_free ./test_tree new_free)
# add_test(test_tree_push_head ./test_tree push_head)
# add_test(test_tree_pop_head ./test_tree pop_head)
# add_test(test_tree_push_tail ./test_tree push_tail)
# add_test(test_tree_pop_tail ./test_tree pop_tail)
# add_test(test_tree_length ./test_tree length)
# add_test(test_tree_empty ./test_tree empty)
# add_test(test_tree_clear ./test_tree clear)

