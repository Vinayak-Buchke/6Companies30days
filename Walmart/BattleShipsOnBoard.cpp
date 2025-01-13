

#include<iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void dfs(vector<vector<int>>& visited, vector<vector<char>>& board, int i,
             int j) {
        if (i < 0 || j < 0 || i == board.size() || j == board[0].size()) {
            return;
        }
        if (visited[i][j] == 1) {
            return;
        }
        visited[i][j] = 1;
        if (board[i][j] == 'X') {
            dfs(visited, board, i + 1, j);
            dfs(visited, board, i - 1, j);
            dfs(visited, board, i, j + 1);
            dfs(visited, board, i, j - 1);
        } else {
            return;
        }
    }
    int countBattleships(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));

        int ships = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (visited[i][j] == 0 && board[i][j] == 'X') {
                    dfs(visited, board, i, j);
                    ships++;
                }
            }
        }
        return ships;
    }
};