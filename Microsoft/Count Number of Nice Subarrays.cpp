#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n  =  nums.size()  ;
        int prevcnt =  0  ;
        int oddcnt = 0 ;
        int res  = 0  ;

        int i  =  0 ;
        int j = 0   ;
        while (j < n) {
            if( nums[j] % 2 != 0 ) {
                oddcnt++ ;
                prevcnt = 0  ;
            }
            while(oddcnt == k  ) {
                prevcnt++ ;
                if(i < n  && nums[i]%2 == 1 ) {
                 oddcnt-- ;
                }
                i++ ;
            }
            res +=  prevcnt  ;
            j++ ;
        }
        return res ;
    }
};

int main()
{
vector<int>nums={1,2,3,4};
    Solution obj;
    cout << obj. numberOfSubarrays(nums,3);
    return 0;
}