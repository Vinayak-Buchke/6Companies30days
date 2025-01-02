#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
    int incremovableSubarrayCount(vector<int>& nums) {
        
        int ans = 0;

        int leftIncreasing = 0 , rightDecreasing = nums.size()-1;
        for(int i = 1; i < nums.size() ; i++)
        {
            if(nums[i-1] >= nums[i]) break;
            leftIncreasing++;
        }

        for(int i = nums.size()-1 ; i > 0; i--)
        {
            if(nums[i] <= nums[i-1]) break;
            rightDecreasing--;
        }

        for(int i = 0 ; i < nums.size(); i++)
        {
            for(int j = i; j < nums.size(); j++)
            {

                bool tillLeft =  i-1 <= leftIncreasing ? 1 : 0, tillRight = j+1 >= rightDecreasing ? 1 : 0 ;

                if(tillLeft && tillRight && (i-1>=0 ? nums[i-1] : INT_MIN ) < (j+1 < nums.size() ? nums[j+1] : INT_MAX))
                {
                    ans++;
                }
            }
        }

        return ans;
    }
};

int main()
{
vector<int>nums={1,2,3,4};
    Solution obj;
    cout << obj.incremovableSubarrayCount(nums);
    return 0;
}