#include<iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();
        int n = isWater[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> visited(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (isWater[i][j] == 1) {
                    q.push({i, j});
                    isWater[i][j] = 0;
                    visited[i][j] = 1;
                }
            }
        }
        int left[] = {-1, 0, 1, 0};
        int right[] = {0, 1, 0, -1};
        int max_height = 0;
        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            int min_val = 1e6;
            for (int i = 0; i < 4; i++) {
                int row = r + left[i];
                int col = c + right[i];
                if (row >= 0 && row < m && col >= 0 && col < n &&
                    visited[row][col] == 0) {
                    isWater[row][col] = isWater[r][c] + 1;
                    visited[row][col] = 1;
                    q.push({row, col});
                }
            }
        }
        return isWater;
    }
};