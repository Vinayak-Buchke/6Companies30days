#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
class Solution {
private:
    static bool comp(vector<int>& a, vector<int>& b){
        if(a[0] == b[0]) return a[1]>b[1];
        return a[0] < b[0];
    }
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        if (n == 0)
            return n;
        sort(envelopes.begin(),envelopes.end(),comp);
        vector<int> temp;
        temp.push_back(envelopes[0][1]);
        for (int i = 1; i < n; i++) {
            if(envelopes[i][1] > temp.back()){
                temp.push_back(envelopes[i][1]);
            }else{
                int lb = lower_bound(temp.begin(),temp.end(),envelopes[i][1]) - 
                    temp.begin();
                temp[lb] = envelopes[i][1];
            }
        }
        return temp.size();
    }
};