//
// Created by jessew on 3/18/17.
//

#ifndef CODE1_BINARYSEARCHTREEITERATOR_H
#define CODE1_BINARYSEARCHTREEITERATOR_H

#include "inc_me.h"

class BinarySearchTreeIterator {

    stack<TreeNode*> stk;
    void push_all_left(TreeNode* root) {
        while (root) {
            stk.push(root);
            root = root->left;
        }
    }
public:
    BinarySearchTreeIterator(TreeNode* root) {
        push_all_left(root);
    }

    bool hasNext() {
        return !stk.empty();

    }
    TreeNode* next() {
        TreeNode* node = stk.top();
        stk.pop();
        push_all_left(node->right);
        return node;
    }
};


#endif //CODE1_BINARYSEARCHTREEITERATOR_H
