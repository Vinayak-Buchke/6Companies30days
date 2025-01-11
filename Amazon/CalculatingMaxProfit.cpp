

#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int N, K;
    vector<vector<vector<int>>> dp;
    int memo(int x, int y, int z, vector<int> &p) {

        if(x == K || y == N)
            return 0;

        if(dp[x][y][z] > -1)
            return dp[x][y][z];

        // skip 
        int a = memo(x, y + 1, z, p);

        int b;
        // if have bought and sell now
        if(z == 1)
            b = p[y] + memo(x + 1, y + 1, 0, p);

        // if haven't bought and buy now
        else
            b = -p[y] + memo(x, y + 1, 1, p);

        return dp[x][y][z] = max(a, b);
    }

    int maxProfit(int k, vector<int>& prices) {
        N = prices.size();
        K = k;
        dp = vector<vector<vector<int>>>(k, vector<vector<int>>(N, vector<int>(2, -1)));

        return memo(0, 0, 0, prices);
    }
};