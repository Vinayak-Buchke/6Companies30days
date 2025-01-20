#include<iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include<algorithm>
using namespace std;
class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap(nums.begin(), nums.end());
        while(k){
            auto node = minHeap.top(); minHeap.pop();
            ++node;
            minHeap.push(node);
            --k;
        }

        int mMod {1000000007};
        long long result = 1;
        while(!minHeap.empty()){
            result = (result * minHeap.top()) % mMod; minHeap.pop();
        }

        return result;
    }
};