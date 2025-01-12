
#include<iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        // sort(ages.begin(), ages.end());
        int ans = 0;
        vector<int> count(121, 0);
        for(int i = 0; i < ages.size(); i++){
            count[ages[i]]++;
        }
        for(int i = 15; i <= 120; i++){
            if(count[i] == 0) continue;
            for(int j = 15; j <= i; j++){
                if(count[j] == 0) continue;

                if(j > i/2 + 7){
                    if(i == j){
                        ans += (count[i] - 1)*(count[j]);
                    }
                    else{
                        ans += count[i]*count[j];
                    }
                }
            }
        }
        return ans;
    }
};