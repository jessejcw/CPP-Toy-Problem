//
// Created by jesse_wang on 3/3/2017.
//

#ifndef CODING1_INORDERTRAVERSAL_H
#define CODING1_INORDERTRAVERSAL_H

#include "inc_me.h"

//http://www.jiuzhang.com/solutions/binary-tree-inorder-traversal/
class InorderTraversal {
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == NULL) {return res;}
        stack<TreeNode*> stk;
        TreeNode* curr = root;
        while (curr || !stk.empty()) {
            while (curr) {
                stk.push(curr);
                curr = curr->left;
            }
            curr = stk.top(); stk.pop();
            res.push_back(curr->val);
            curr = curr->right;
        }
        return res;
    }
};


#endif //CODING1_INORDERTRAVERSAL_H
