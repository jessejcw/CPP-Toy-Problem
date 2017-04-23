//
// Created by jesse_wang on 3/19/2017.
//

#ifndef CODE1_BINARYTREEPATH_H
#define CODE1_BINARYTREEPATH_H

#include "inc_me.h"

class BinaryTreePath {
public:
    vector<string> binaryTreePath(TreeNode* root) {
        vector<string> res;
        if (root == NULL) { return res;}

        vector<string> left = binaryTreePath(root->left);
        vector<string> right = binaryTreePath(root->right);

        for (const string& path : left) {
            res.push_back(to_string(root->val)+"->"+path);
        }

        for (const string& path : right) {
            res.push_back(to_string(root->val)+"->"+path);
        }
        if (res.empty()) {

        }

    }

};


#endif //CODE1_BINARYTREEPATH_H
