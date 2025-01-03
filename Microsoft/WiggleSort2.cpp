#include <iostream>
#include <map>
#include <vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    void wiggleSort(vector<int>& nums) {

        int n = nums.size();
        vector<int> nums1(nums);
        sort(begin(nums1), end(nums1));
        int i = n - 1;
        int j = 1;
        while (j < n && i > -1) {
            nums[j] = nums1[i];
            i--;
            j += 2;
        }
        j = 0;
        while (j < n && i > -1) {
            nums[j] = nums1[i];
            i--;
            j += 2;
        }
    }
};