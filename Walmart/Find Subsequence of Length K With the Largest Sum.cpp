#include<iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool operator()(pair<int, int>& a, pair<int, int>& b) {
        return a.second > b.second;
    }
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int> ans;
        int n = nums.size();
        if (k > n) {
            return ans;
        }
        priority_queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            q.push({nums[i], i});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, Solution> q2;

        while (k > 0) {
            q2.push(q.top());
            q.pop();
            k--;
        }

        while (!q2.empty()) {
            ans.push_back(q2.top().first);
            q2.pop();
        }

        return ans;
    }
};