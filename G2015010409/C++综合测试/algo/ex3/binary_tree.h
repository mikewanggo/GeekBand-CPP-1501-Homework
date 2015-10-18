#ifndef BINARY_TREE_H_
#define BINARY_TREE_H_

#include <iostream>
#include <vector>

#include "tree_node.h"


template<typename T>
class BinaryTree {
public:
    BinaryTree(TreeNode<T>* r = nullptr): root_(r) { }
    explicit BinaryTree(const T& value): root_(new TreeNode<T>(value)) { }

    void PrintAllPath() const;

    void AddLeftTree(BinaryTree<T>* tree) {
        if (!root_) {
            root_ = tree->root_;
        } else {
            clear(root_->left_);
            root_->left_ = tree->root_;
        }
        tree = nullptr;
    }

    void AddRightTree(BinaryTree<T>* tree) {
        if (!root_) {
            root_ = tree->root_;
        } else {
            clear(root_->right_);
            root_->right_ = tree->root_;
        }
    }

    ~BinaryTree();

private:
    TreeNode<T>* root_;  // Owned.
    static void FindAllPath(const TreeNode<T>* current_root, std::vector<T>& current_path, std::vector<std::vector<T> >& all_path);
    static void clear(TreeNode<T>* r);
    static void PrintPath(const std::vector<T>& path);
    static void PrintTree(TreeNode<T>* r) {
        if (r) {
            std::cout << r->value_ << ' ';
            PrintTree(r->left_);
            PrintTree(r->right_);
        }
    }
};

template<typename T>
void BinaryTree<T>::PrintAllPath() const {
    std::vector<T> path;
    std::vector<std::vector<T> > all_path;
    FindAllPath(root_, path, all_path);
    bool first_path = true;
    for (const auto& path: all_path) {
        if (first_path) {
            PrintPath(path);
            first_path = false;
        } else {
            std::cout << ",";
            PrintPath(path);
        }
    }
    std::cout << std::endl;
}

template<typename T>
void BinaryTree<T>::PrintPath(const std::vector<T>& path) {
    bool first = true;
    if (path.empty()) {
        return;
    }
    std::cout << "[";
    for (const T& value: path) {
        if (first) {
            first = false;
            std::cout << value;
        } else {
            std::cout << "," << value;
        }
    }
    std::cout << "]";
}

template<typename T>
BinaryTree<T>::~BinaryTree() {
    clear(root_);
}

template<typename T>
void BinaryTree<T>::clear(TreeNode<T>* root) {
    if (root) {
        clear(root->left_);
        clear(root->right_);
    }
    delete root;
}


template<typename T>
void BinaryTree<T>::FindAllPath(const TreeNode<T>* current_root, std::vector<T>& path, std::vector<std::vector<T> >& all_path) {
    if (!current_root) {
        return;
    }
    path.push_back(current_root->value_);
    if (!current_root->left_ && !current_root->right_) {
        if (!path.empty()) {
            all_path.push_back(path);
        }
    } else {
        FindAllPath(current_root->left_, path, all_path);
        FindAllPath(current_root->right_, path, all_path);
    }
    path.pop_back();
}

#endif  // BINARY_TREE_H_

