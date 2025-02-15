
#include<iostream>
#include <vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> dp(n, 1), prev(n, -1);
        int maxSize = 0, maxIndex = -1;
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
            if (dp[i] > maxSize) {
                maxSize = dp[i];
                maxIndex = i;
            }
        }
        
        vector<int> result;
        for (int i = maxIndex; i != -1; i = prev[i]) {
            result.push_back(nums[i]);
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};