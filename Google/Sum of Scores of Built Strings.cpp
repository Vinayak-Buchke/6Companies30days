#include<iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include<algorithm>
using namespace std;
#define li long long
class Solution {
public:
    long long sumScores(string s) {
        li n = s.size(), i = 1, left = 0, right = 0, ans = 0;
        vector<li> z(n, 0);
        while (i < n) {
            if (i <= right)
                z[i] = min(z[i - left], right - i + 1);
            while (s[z[i]] == s[i + z[i]])
                z[i]++;
            if (i + z[i] - 1 > right) {
                left = i;
                right = i + z[i] - 1;
            }
            ans += z[i];
            i++;
        }
        return ans + n;
    }
};