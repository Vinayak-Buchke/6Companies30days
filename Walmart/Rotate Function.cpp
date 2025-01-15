
#include<iostream>
#include <vector>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int t_sum = accumulate(nums.begin(), nums.end(), 0);
        int n = nums.size();
        vector<int> dp(n);
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += (i * nums[i]);
        }
        dp[0] = sum;

        int ans = dp[0];
        for(int i = 1; i < n; i++){
            dp[i] = dp[i-1] - t_sum + n*nums[i-1];
            ans = max(ans, dp[i]);
        }

        return ans;
    }
};