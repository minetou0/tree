cmake_minimum_required(VERSION 3.0)

project("tree" C)

include(CTest)
enable_testing()

set(CMAKE_C_FLAGS "-g -std=c99 -Wall --coverage")

add_library(tree tree.c tree_aux.c)
add_executable(sample sample.c)
target_link_libraries(sample tree)

add_executable(tree_test tree_test.c)
target_link_libraries(tree_test tree)

add_test(test_new_free ./tree_test "new_free")
add_test(test_copy ./tree_test "copy")
add_test(test_equal ./tree_test "equal")
add_test(test_left ./tree_test "left")
add_test(test_right ./tree_test "right")
add_test(test_parent ./tree_test "parent")
add_test(test_value ./tree_test "value")
add_test(test_is_leaf ./tree_test "is_leaf")
add_test(test_is_root ./tree_test "is_root")
add_test(test_height ./tree_test "height")
add_test(test_nnodes ./tree_test "nnodes")
add_test(test_root ./tree_test "root")
add_test(test_unlink ./tree_test "unlink")
add_test(test_free_full ./tree_test "free_full")
