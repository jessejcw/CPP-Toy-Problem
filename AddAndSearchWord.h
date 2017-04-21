//
// Created by jesse wang on 3/20/17.
//

#ifndef CODE1_ADDANDSEARCHWORD_H
#define CODE1_ADDANDSEARCHWORD_H

#include "inc_me.h"

struct TrieNode {
    TrieNode* next[26];
    bool exist = false;
    TrieNode() {
        memset(next, '\0', 26 * sizeof(TrieNode*));
    }
};

class AddAndSearchWord {
    TrieNode* root;
    vector<TrieNode*> tobeDelete;
public:
    AddAndSearchWord() {
        root = new TrieNode();
        tobeDelete.push_back(root);
    }
    ~AddAndSearchWord() {
        for (auto itr : tobeDelete) {
            delete itr;
        }
    }
    void addWord(string word) {
        TrieNode* node = root;
        int index;
        for (int i= 0; i < word.size(); i++) {
            index = word[i] -'a';
            if (node->next[index] == NULL) {
                node->next[index] = new TrieNode();
                tobeDelete.push_back(node->next[index]);
            }
            node = node->next[index];
        }
        node->exist = true;
    }

    bool search(string word) {
        return searchWord(root, word, 0);
    }

private:
    bool searchWord(TrieNode* node, string& word, int curr_id) {
        if (node == NULL) {
            return false;
        }
        if (word.length() == curr_id) {
            return node->exist;
        }
        char c = word[curr_id];
        if (c == '.') {
            for (int i = 0; i < 26; i++) {
                if (node->next[i] != NULL) {
                    if (searchWord(node->next[i], word, curr_id + 1))
                        return true;
                }
            }
            return false;
        } else {
            return searchWord(node->next[c-'a'], word, curr_id+1);
        }
    }
};


#endif //CODE1_ADDANDSEARCHWORD_H
