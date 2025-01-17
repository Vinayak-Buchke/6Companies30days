#include<iostream>
#include <vector>
#include <queue>
using namespace std;
class KthLargest {
public:
    int num;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    KthLargest(int k, vector<int>& nums) {
        num = k;
        for(auto i: nums) {
            minHeap.push(i);
            if(minHeap.size() > k) {
                minHeap.pop();
            }
        }
    }
    
    int add(int val) {
        minHeap.push(val);
        if(minHeap.size() > num) {
            minHeap.pop();
        }

        return minHeap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */