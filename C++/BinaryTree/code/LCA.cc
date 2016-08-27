#include <cassert>
#include <iostream>
#include <memory>

#include "./Binary_tree_prototype.h"

using std::cout;
using std::endl;
using std::make_unique;
using std::unique_ptr;

struct Status;
Status LCAHelper(const unique_ptr<BinaryTreeNode<int>>&,
                 const unique_ptr<BinaryTreeNode<int>>&,
                 const unique_ptr<BinaryTreeNode<int>>&);

// @include

struct Status {
	int num_target_nodes;
	BinaryTreeNode<int> ancestor;
}

BinaryTreeNode<int> findLCA(const unique_ptr<BinaryTreeNode<int>>& current, const unique_ptr<BinaryTreeNode<int>>& node1, const unique_ptr<BinaryTreeNode<int>>& node2){
	
	return recursiveLCA(current, node1, node2).ancestor;
}

Status recursiveLCA(const unique_ptr<BinaryTreeNode<int>>& current, const unique_ptr<BinaryTreeNode<int>>& node1, const unique_ptr<BinaryTreeNode<int>>& node2){
	
	if (current == nullptr)
		return {0, nullptr};
	
	auto leftResult = recursiveLCA(current->left, node1, node2);
	if (leftResult.num_target_nodes == 2)
		return leftResult;
	auto rightResult = recursiveLCA(current->right, node1, node2);
	if (rightResult.num_target_nodes == 2)
		return rightResult;
	num_target_nodes = leftResult.num_target_nodes + rightResult.num_target_nodes + (current == node1) + (current == node2);
	return {num_target_nodes, num_target_nodes == 2? current.get() : nullptr};
}


