//
// Created by jesse_wang on 3/3/2017.
//

#ifndef CODING1_POSTORDERTRAVERSAL_H
#define CODING1_POSTORDERTRAVERSAL_H

#include "inc_me.h"

class PostorderTraversal {
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == NULL) {
            return res;
        }
        stack<TreeNode*> stk;
        TreeNode* curr = root, *lastNode = NULL;
        while (curr || !stk.empty()) {
            while (curr) {
                stk.push(curr);
                curr = curr->left;
            }
            TreeNode* node = stk.top();
            if (node->right && lastNode != node->right) {
                curr = node->right;
            } else {
                res.push_back(node->val);
                lastNode = node;
                stk.pop();
            }
        }
        return res;
    }

};


#endif //CODING1_POSTORDERTRAVERSAL_H
