#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
class Solution {
public:
        vector<vector<int>>react;
        vector<int>v;
int sides(vector<int>& r){
    return (r[2] - r[0] + 1) * (r[3] - r[1] + 1);
}
    Solution(vector<vector<int>>& rects) {
        react = rects;
        
        int totalsides = 0;
        for(auto r : react){
         totalsides += sides(r);
        v.push_back(totalsides);
        }

    }
    
    vector<int> pick() {
        int rnd = rand() % v.back();
        int idx = upper_bound(v.begin(),v.end(), rnd) - v.begin();// next step i want the reactangle at r so 
        auto r = react[idx];
        int x_rnd = rand() % (r[2] - r[0] +1) + r[0] ; //rand() is offset(includes zero 0)
        int y_rnd = rand() % (r[3] - r[1] + 1 ) + r[1]; 
        return {x_rnd,y_rnd};
    }
};

