//
// Created by jesse_wang on 3/3/2017.
//

#ifndef CODING1_PREORDERTRAVERSAL_H
#define CODING1_PREORDERTRAVERSAL_H

#include "inc_me.h"

// sequence : root -> left -> right
// http://www.jiuzhang.com/solutions/binary-tree-preorder-traversal/
class PreorderTraversal {
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == NULL) {
            return res;
        }
        stack<TreeNode*> stk;
        stk.push(root);
        while (!stk.empty()) {
            TreeNode* node = stk.top(); stk.pop();
            if (node->right) {
                stk.push(node->right);
            }
            if (node->left) {
                stk.push(node->left);
            }
            res.push_back(node->val);
        }
        return res;
    }
};


#endif //CODING1_PREORDERTRAVERSAL_H
