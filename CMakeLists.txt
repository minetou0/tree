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

add_test(test_new_free ./test_tree "new_free")
add_test(test_left ./test_tree "left")
add_test(test_right ./test_tree "right")
add_test(test_parent ./test_tree "parent")
add_test(test_value ./test_tree "value")
add_test(test_is_leaf ./test_tree "is_leaf")
add_test(test_is_root ./test_tree "is_root")
add_test(test_height ./test_tree "height")
add_test(test_root ./test_tree "root")
add_test(test_unlink ./test_tree "unlink")
