#include<iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include<algorithm>
using namespace std;
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& a) {
        int n = a.size();
        sort(a.begin(), a.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
             });
        int ans = 0;
        vector<int> b;
        for (int i = 0; i < n; i++) {
            if (b.size() == 0)
                b.push_back(a[i][1]);
            else {
                auto p = lower_bound(b.begin(), b.end(), a[i][1]) - b.begin();
                if (p == b.size())
                    b.push_back(a[i][1]);
                else
                    b[p] = a[i][1];
            }
        }
        return b.size();
    }
};