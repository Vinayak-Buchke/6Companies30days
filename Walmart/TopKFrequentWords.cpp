
#include<iostream>
#include<algorithm>
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    bool operator()(pair<string, int>& a, pair<string, int>& b) {
        if (a.second > b.second) {
            return 0;
        } else if (a.second == b.second) {
            return a.first > b.first;
        } else {
            return 1;
        }
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        sort(words.begin(), words.end());
        priority_queue<pair<string, int>, vector<pair<string, int>>, Solution>
            p;

        int i = 0;
        while (i < words.size()) {
            int count = 0;
            string curr = words[i];
            int index = i;
            while (index < words.size() && curr == words[index]) {
                count++;
                index++;
            }
            if (index == i) {
                index++;
            }
            i = index;
            p.push({curr, count});
        }
        vector<string> ans;

        while (k > 0 && !p.empty()) {
            ans.push_back(p.top().first);
            p.pop();
            k--;
        }
        return ans;

        return ans;
    }
};