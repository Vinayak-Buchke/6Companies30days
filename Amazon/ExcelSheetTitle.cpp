#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
    string convertToTitle(int c) {
        string ans = "";
        while (c > 0) {
            int r = (c - 1) % 26;
            ans = char('A' + r) + ans;
            c = (c - 1) / 26;
        }
        return ans;
    }
};