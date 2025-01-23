#include<iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        const int m = 1e9+7;
        int curr =0;// number of active spreader
        int ans =1;// number of person who knows the secret
        queue<pair<int,int>>delayq, forgetq;
        delayq.push({1,1});
        forgetq.push({1,1});
        for(int i=1;i<=n;i++){
            //step 1 number of people forgets the secret on ith day
            if(!forgetq.empty()&&forgetq.front().first+forget<=i){
                auto element = forgetq.front().second;
                forgetq.pop();
                ans = (ans- element +m)%m;
                curr = (curr - element+m)%m;
                
            }
            // step 2 number of active spreader
            if(!delayq.empty()&&delayq.front().first+ delay<=i){
                auto element = delayq.front().second;
                delayq.pop();
                curr = (curr + element)%m;
            }
            // step 3 persons who knows the secret
            if(curr>0){
                ans  = (ans+curr)%m;
                delayq.push({i,curr});
                forgetq.push({i,curr});
            }
        }
        return ans;
        
    }
};