#include<iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include<algorithm>
using namespace std;
class Solution {
private:
    vector<pair<int, int>> adjacencies = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

public:
    int minDays(vector<vector<int>>& grid) {
        int height = grid.size();
        int width = grid[0].size();
        
        int islandCount = calculateIslands(grid);
        
        if (islandCount != 1) return 0;
        
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                if (grid[i][j] == 1) {
                    grid[i][j] = 0;
                    if (calculateIslands(grid) != 1) return 1;
                    grid[i][j] = 1;
                }
            }
        }
        
        return 2;
    }

private:
    int calculateIslands(vector<vector<int>>& grid) {
        int height = grid.size();
        int width = grid[0].size();
        vector<vector<bool>> seen(height, vector<bool>(width, false));
        int totalIslands = 0;
        
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                if (grid[i][j] == 1 && !seen[i][j]) {
                    markIsland(grid, i, j, seen);
                    ++totalIslands;
                }
            }
        }
        
        return totalIslands;
    }

    void markIsland(vector<vector<int>>& grid, int i, int j, vector<vector<bool>>& seen) {
        seen[i][j] = true;
        
        for (const auto& move : adjacencies) {
            int newI = i + move.first;
            int newJ = j + move.second;
            if (isValidPosition(grid, newI, newJ, seen)) {
                markIsland(grid, newI, newJ, seen);
            }
        }
    }

    bool isValidPosition(const vector<vector<int>>& grid, int i, int j, const vector<vector<bool>>& seen) {
        int height = grid.size();
        int width = grid[0].size();
        return i >= 0 && j >= 0 && i < height && j < width && grid[i][j] == 1 && !seen[i][j];
    }
};