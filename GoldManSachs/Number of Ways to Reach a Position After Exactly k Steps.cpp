#include<iostream>
#include <vector>
using namespace std;
class Solution {
public:
    const int mod = 1e9 + 7;
    int find(int startPos, int endPos, int k, vector<vector<int>>& dp) {

        if (k == 0) {
            if (startPos == endPos) {
                return 1;
            }
            return 0;
        }
        if (dp[startPos + 1000][k] != -1) {
            return dp[startPos + 1000][k];
        }
        int left = find(startPos - 1, endPos, k - 1, dp) % mod;
        int right = find(startPos + 1, endPos, k - 1, dp) % mod;
        return dp[startPos + 1000][k] = (left + right) % mod;
    }
    int numberOfWays(int startPos, int endPos, int k) {
        vector<vector<int>> dp(4000, vector<int>(4000, -1));
        return find(startPos, endPos, k, dp);
    }
};