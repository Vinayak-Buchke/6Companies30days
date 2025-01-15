
#include<iostream>
#include <vector>
using namespace std;
class Solution {
public:
    // dp 1D optimized from dp 2D
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() < nums2.size()) swap(nums1, nums2); // After swap: nums1.size() >= nums2.size()
        vector<int> dp(nums2.size()+1, 0);
        int ans = 0;
        for(int i=nums1.size()-1; i>=0; --i){
            for(int j=0; j<nums2.size(); ++j){
                if(nums1[i] == nums2[j]){
                    dp[j] = dp[j+1] + 1;
                    ans = max(ans, dp[j]);
                }else{
                    dp[j]=0;
                }
            }
        }
        return ans;
    }
};