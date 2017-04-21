//
// Created by jesse wang on 3/17/17.
//

#ifndef CODE1_NUMBEROFISLANDS_H
#define CODE1_NUMBEROFISLANDS_H

#include "inc_me.h"

struct Coordinate {
    int x, y;
};

class NumberOfIslands {

    int numIsland(vector<vector<char>>& grid) {
        const int m = grid.size();
        if (m == 0) { return 0; }
        const int n = grid[0].size();
        int islands = 0;
        for (int i =0 ; i <m; i++) {
            for (int j=0; j < n; j++) {
                if (grid[i][j] == '1') {
                    markByBFS(grid, i, j);
                    islands++;
                }
            }
        }
        return islands;
    }
    void markByBFS(vector<vector<char>>& grid, int x, int y) {
        vector<int> directionX = {0, 1, -1, 0};
        vector<int> directionY = {1, 0, 0, -1};

        queue<pair<int, int>> que;
        que.push(make_pair(x, y));
        grid[x][y] = '0';
        while (!que.empty()) {
            pair<int, int> coor = (pair<int, int> &&) que.front();
            que.pop();
            for (int i =0; i < 4; i++) {
                pair<int, int> adj(
                        coor.first+directionX[i],
                        coor.second+directionY[i]
                );
                if (!inBound(adj, grid)) {
                    continue;
                }
                if (grid[adj.first][adj.second] == '1') {
                    grid[adj.first][adj.second] = '0';
                    que.push(adj);
                }
            }
        }
    }

    bool inBound(pair<int, int>& coor, vector<vector<char>>& grid) {
        return coor.first >= 0 && coor.first < grid.size() &&
                                  coor.second >= 0 && coor.second < grid.size();
    }
};


#endif //CODE1_NUMBEROFISLANDS_H
