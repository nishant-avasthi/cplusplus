#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int delRow[] = {0, 0, -1, 1};
        int delCol[] = {1, -1, 0, 0};

        vector<vector<int>> vis(n, vector<int>(m, 0));

        queue<pair<pair<int, int>, int>> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});  // Fix: Added double curly braces
                }
            }
        }

        int time = 0;  // Fix: Initialize time variable outside the loop

        while (!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int t = q.front().second;

            q.pop();

            for (int i = 0; i < 4; i++) {
                int Nrow = row + delRow[i];
                int Ncol = col + delCol[i];  // Fix: Corrected variable name

                if (Nrow >= 0 && Nrow < n && Ncol >= 0 && Ncol < m &&
                    grid[Nrow][Ncol] == 1 && vis[Nrow][Ncol] != 2) {
                    vis[Nrow][Ncol] = 2;
                    q.push({{Nrow, Ncol}, t + 1});  
                }
            }
            time = t;  // Fix: Corrected the assignment of time inside the loop
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && vis[i][j] != 2) {  // Fix: Corrected the condition
                    return -1;
                }
            }
        }
        return time;
    }
};