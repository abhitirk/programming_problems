#ifndef SOLUTIONS_BINARY_TREE_PROTOTYPE_H_
#define SOLUTIONS_BINARY_TREE_PROTOTYPE_H_

#include <memory>

//#include "test_toolkit/more_type_traits.h"

using std::unique_ptr;

// @pg_header
// @include
template <typename T>
struct BinaryTreeNode {
  T data;
  unique_ptr<BinaryTreeNode<T>> left, right;
};
// @exclude
// @pg_end

//REGISTER_TREE_TYPE(unique_ptr<BinaryTreeNode<T>>)

//#endif  // SOLUTIONS_BINARY_TREE_PROTOTYPE_H_