#include<iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;
class Solution {
private:
    int m, n, total;
    unordered_map<int, int> map;
    
public:
    Solution(int m, int n) {
        this->m = m;
        this->n = n;
        this->total = m * n;
    }
    
    vector<int> flip() {
        int index = rand() % total;
        total--;
        int target = map.count(index) ? map[index] : index;
        map[index] = map.count(total) ? map[total] : total;
        return {target / n, target % n};
    }
    
    void reset() {
        map.clear();
        total = m * n;
    }
};  