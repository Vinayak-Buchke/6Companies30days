#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int med = 0;
        int moves = 0;
        if (n % 2 == 0) {
            med = (nums[n / 2] + nums[n / 2 - 1]) / 2;
        } else {
            med = nums[n / 2];
        }
        for (int i = 0; i < n; i++) {
            moves += abs(nums[i] - med);
        }
        return moves;
    }
};
int main()
{
    Solution obj;
    vector<int>arr={1,2,3};
    cout<<obj.minMoves2(arr);
}