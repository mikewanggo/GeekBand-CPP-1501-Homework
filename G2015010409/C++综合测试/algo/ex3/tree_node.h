#ifndef TREE_NODE_H
#define TREE_NODE_H

template<typename T>
struct TreeNode {
    TreeNode(const T& value): 
        value_(value), left_(nullptr), right_(nullptr) { }

    T value() const { return value_; }
    T value_;
    TreeNode* left_;  // Not owned.
    TreeNode* right_;  // Not owned.
};

#endif  // TREE_NODE_H

