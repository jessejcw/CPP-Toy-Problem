//
// Created by jesse wang on 3/20/17.
//

#ifndef CODE1_INORDERSUCCESSOROFBST_H
#define CODE1_INORDERSUCCESSOROFBST_H

#include "inc_me.h"

class InorderSuccessorOfBST {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        stack<TreeNode*> stk;
        TreeNode* curr = root, *prev = NULL;
        while (curr || stk.empty()) {
            while (curr) {
                stk.push(curr);
                curr = curr->left;
            }
            TreeNode* node = stk.top(); stk.pop();
            if (prev && prev == p) {
                return curr;
            }
            prev = node;
            curr = node->right;
        }
        return NULL;
    }

};


#endif //CODE1_INORDERSUCCESSOROFBST_H
