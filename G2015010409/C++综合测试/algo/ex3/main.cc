#include <iostream>

#include "binary_tree.h"
#include "tree_node.h"

using namespace std;

int main() {
    // Construct Sample Test.
    // 3 1 5 2 6 7 8 
    BinaryTree<int>* left_child_tree = new BinaryTree<int>(1);
    left_child_tree->AddLeftTree(new BinaryTree<int>(2));
    BinaryTree<int>* right_child_tree = new BinaryTree<int>(5);
    right_child_tree->AddRightTree(new BinaryTree<int>(7));
    BinaryTree<int>* tree = new BinaryTree<int>(6);
    tree->AddLeftTree(new BinaryTree<int>(8));
    right_child_tree->AddLeftTree(tree);
    tree = nullptr;
    BinaryTree<int>* root = new BinaryTree<int>(3);
    root->AddLeftTree(left_child_tree);
    left_child_tree = nullptr;
    root->AddRightTree(right_child_tree);
    right_child_tree = nullptr;

    // Print All Path
    root->PrintAllPath();
    delete root;
    return 0;
}

