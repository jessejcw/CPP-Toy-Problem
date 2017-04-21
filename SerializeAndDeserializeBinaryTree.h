//
// Created by jesse wang on 3/16/17.
//

#ifndef CODE1_SERIALIZEANDDESERIALIZEBINARYTREE_H
#define CODE1_SERIALIZEANDDESERIALIZEBINARYTREE_H

#include <sstream>
#include "inc_me.h"

class SerializeAndDeserializeBinaryTree {
    string serialize(TreeNode* root) {
        vector<TreeNode*> que;
        que.push_back(root);
        for (int i =0; i < que.size(); i++) {
            TreeNode* node = que[i];
            if (node == NULL) {
                continue;
            }
            que.push_back(node->left);
            que.push_back(node->right);
        }
        while (que.size() > 0 && que[que.size()-1] == NULL) {
            que.pop_back();
        }
        if (que.size()==0) {
            return "{}";
        }

        stringstream ss;
        ss << "{" << que[0]->val;
        for (int i =1; i < que.size(); i++) {
            if (que[i] == NULL) {
                ss << ",#";
            } else {
                ss << "," << que[i]->val;
            }
        }
        ss << "}";

        return ss.str();
    }

    TreeNode* deserialize(string data) {
        if (data == "{}") {
            return NULL;
        }
        vector<string> vals = split(data.substr(1, data.size()-2), ",");
        TreeNode* root = new TreeNode(atoi(vals[0].c_str()));
        queue<TreeNode*> que;
        que.push(root);
        bool isLefChild = true;
        for (int i =0; i < vals.size(); i++) {
            if (vals[i] != "#") {
                TreeNode* node = new TreeNode(atoi(vals[i].c_str()));
                if (isLefChild) {
                    que.front()->left = node;
                } else {
                    que.front()->right = node;
                }
                que.push(node);
            }
            if (!isLefChild) {
                que.pop();
            }
            isLefChild = !isLefChild;
        }
        return root;
    }
    vector<string> split(const string& str, string delim) {
        vector<string> results;
        int last_idx = 0, idx;
        while ((idx = str.find(delim, last_idx)) != string::npos) {
            results.push_back(str.substr(last_idx, idx - last_idx));
            last_idx = idx + delim.length();
        }
        if (last_idx != str.length()) {
            results.push_back(str.substr(last_idx, str.length()-last_idx));
        }
        return results;
    }
};


#endif //CODE1_SERIALIZEANDDESERIALIZEBINARYTREE_H
