#include<bits/stdc++.h>
using namespace std;

template<typename T>

class TreeSet {
private:
    struct TreeNode {
        T value;
        std::unique_ptr<TreeNode> left;
        std::unique_ptr<TreeNode> right;

        TreeNode(const T& val) : value(val), left(nullptr), right(nullptr) {}
    };

    std::unique_ptr<TreeNode> root;

    void addNode(std::unique_ptr<TreeNode>& node, const T& value) {
        if (!node) {
            node = std::make_unique<TreeNode>(value);
        } else if (value < node->value) {
            addNode(node->left, value);
        } else if (value > node->value) {
            addNode(node->right, value);
        }
    }

    bool containsNode(const std::unique_ptr<TreeNode>& node, const T& value) const {
        if (!node) {
            return false;
        } else if (value == node->value) {
            return true;
        } else if (value < node->value) {
            return containsNode(node->left, value);
        } else {
            return containsNode(node->right, value);
        }
    }

public:
    TreeSet() : root(nullptr) {}

    void add(const T& value) {
        addNode(root, value);
    }

    bool contains(const T& value) const {
        return containsNode(root, value);
    }
};
