//
// Created by jesse wang on 3/13/17.
//

#ifndef CODE1_BINARYTREEVERTICALORDERTRAVERSAL_H
#define CODE1_BINARYTREEVERTICALORDERTRAVERSAL_H

#include "inc_me.h"

class BinaryTreeVerticalOrderTraversal {
public:
    vector<vector<int>> vertical(TreeNode* root) {
        map<int, vector<int>> mp; // vertical level -> val
        queue<pair<TreeNode*, int>> que; // node ->level
        if (root != NULL) {
            que.push(make_pair(root, 0));
        }
        while (!que.empty()) {
            pair<TreeNode*, int> curr = (pair<TreeNode *, int> &&) que.front(); que.pop();
            mp[curr.second].push_back(curr.first->val);
            if (curr.first->left != NULL) {
                que.push(make_pair(curr.first->left, curr.second-1));
            }
            if (curr.first->right != NULL) {
                que.push(make_pair(curr.first->right, curr.second+1));
            }
        }
        vector<vector<int>> res;
        for (auto itr : mp) {
            res.push_back(itr.second);
        }
        return res;

    }

};


#endif //CODE1_BINARYTREEVERTICALORDERTRAVERSAL_H
