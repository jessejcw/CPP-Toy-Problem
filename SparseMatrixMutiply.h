//
// Created by jesse wang on 3/13/17.
//

#ifndef CODE1_SPARSEMATRIXMUTIPLY_H
#define CODE1_SPARSEMATRIXMUTIPLY_H


#include "inc_me.h"
class SparseMatrixMutiply {
public:
    vector<vector<int>> mutiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        const int na = A.size();
        const int nb = B.size();
        const int mb = B[0].size();
        vector<vector<int>> res(na, vector<int>(mb, 0));
        for (int i =0; i < na; i++) {
            for (int j = 0; j < nb; j++) {
                if (A[i][j] != 0) {
                    for (int k = 0; k < mb; k++) {
                        res[i][k] += (A[i][j]*B[j][k]);
                    }
                }
            }
        }
        return res;
    }

};


#endif //CODE1_SPARSEMATRIXMUTIPLY_H
