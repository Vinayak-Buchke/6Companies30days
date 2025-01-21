#include<iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int> result;
        for (auto& query : queries) {
            int k = query[0], trim = query[1];
            vector<pair<string, int>> trimmed_nums;
            for (int i = 0; i < nums.size(); i++) {
                trimmed_nums.push_back({nums[i].substr(nums[i].size() - trim), i});
            }
            sort(trimmed_nums.begin(), trimmed_nums.end());
            result.push_back(trimmed_nums[k - 1].second);
        }
        return result;
    }
};