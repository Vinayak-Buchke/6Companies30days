#include<iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
    unordered_map<string, vector<string>> mp;
    for (const auto& at : access_times)
        mp[at[0]].push_back(at[1]);
    vector<string> res{};
    for (auto [empl, ac] : mp) {
        sort(begin(ac), end(ac));
        for (int i = 0, j = 0; i < ac.size(); i++) {
            while (stoi(ac[i]) - stoi(ac[j]) >= 100)
                j++;
            if (i - j >= 2) {
                res.push_back(empl);
                break;
            }
        }
    }
    return res;
}
};