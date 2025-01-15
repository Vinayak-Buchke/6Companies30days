#include<iostream>
using namespace std;
class Solution {
public:
    int longestString(int x, int y, int z) {
        return 2 * ((x == y) ? (x + y + z) : (2 * min(x, y) + 1 + z));
    }
};