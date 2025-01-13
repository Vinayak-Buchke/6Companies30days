
#include<iostream>
#include <vector>
using namespace std;
#include <queue>
#include <unordered_map>
class Solution {
public:
    bool operator()(const pair<char, int>& a, const pair<char, int>& b) {
        return a.second < b.second;
    }
    string frequencySort(string s) {

        priority_queue<pair<char, int>, vector<pair<char, int>>, Solution> pq;

        unordered_map<char, int> hm;

        for (char c : s) {
            hm[c]++;
        }

        for (const auto& entry : hm) {
            pq.push(make_pair(entry.first, entry.second));
        }

        string result = "";
        while (!pq.empty()) {
            pair<char, int> p = pq.top();
            pq.pop();
            result.append(p.second, p.first);
        }

        return result;
    }
};
