#include<iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <set>
using namespace std;
class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        int n = nums.size();
        set<vector<int>> uniqueSubarrays;
        for (int i = 0; i < n; i++) {
            vector<int> currentSubarray;
            int divisibleCount = 0;
            for (int j = i; j < n; j++) {
                currentSubarray.push_back(nums[j]);
                if (nums[j] % p == 0) {
                    divisibleCount++;
                }
                if (divisibleCount > k) {
                    break;
                }
                uniqueSubarrays.insert(currentSubarray);
            }
        }
        return uniqueSubarrays.size();
    }
};