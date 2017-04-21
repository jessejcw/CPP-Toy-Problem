//
// Created by jesse wang on 3/22/17.
//

#ifndef CODE1_WORDSEARCH_H
#define CODE1_WORDSEARCH_H

#include "inc_me.h"

class WordSearch {
public:
    bool exist(vector<vector<char>>& board, string word) {
        const int m = board.size();
        if ( m == 0) { return false; }
        const int n = board[0].size();
        if (word.size() == 0) { return true; }

        for (int i =0 ; i<m; i++) {
            for (int j= 0; j < n; j++) {
                if (exist_helper(board, i, j, word, 0))
                    return true;
            }
        }
        return false;
    }
    bool exist_helper(vector<vector<char>>& board, int x, int y, string& word, int idx) {
        if (idx == word.size()) {
            return true;
        }
        if (board[x][y] != word[idx]) {
            return false;
        }
        if (!in_bound(board, x, y)) {
            return false;
        }
        board[x][y] = '#';
        bool result = exist_helper(board, x-1, y, word, idx+1) ||
                      exist_helper(board, x+1, y, word, idx+1) ||
                      exist_helper(board, x, y-1, word, idx+1) ||
                      exist_helper(board, x, y+1, word, idx+1);
        board[x][y] = word[idx];
        return result;
    }

    bool in_bound(vector<vector<char>> board, int x, int y) {
        return x >= 0 && x < board.size() && y >= 0 && y <board[0].size();
    }

};


#endif //CODE1_WORDSEARCH_H
