#include <iostream>
#include <unordered_map>
#include<algorithm>
#include <vector>
#include <queue>

using namespace std;
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        int time = 0;
        int fresh = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                }
                if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }
        if (fresh == 0) {
            return 0;
        }
        int left[] = {1, 0, -1, 0};
        int right[] = {0, 1, 0, -1};

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                for (int i = 0; i < 4; i++) {
                    int row = r + left[i];
                    int col = c + right[i];
                    if (row < 0 || col < 0 || row == m || col == n) {
                        continue;
                    } else if (grid[row][col] == 1) {
                        fresh--;
                        q.push({row, col});
                        grid[row][col] = 2;
                    }
                }
            }

            time++;
            if (fresh == 0) {
                return time;
            }
        }

        if (fresh != 0) {
            return -1;
        }
        return time;
    }
};