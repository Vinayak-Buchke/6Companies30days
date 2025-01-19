#include<iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include<algorithm>
using namespace std;
class Solution {
public:
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        int n=aliceValues.size();
        // max heap  to sort stones based on the sum of values to Alice and Bob
        priority_queue<pair<int,int>> pq;
        // Fill the heap with pairs of (sum of values, stone)
        for(int i=0;i<n;i++){
            pq.push({aliceValues[i]+bobValues[i],i});
        }

        int aliceScore=0,bobScore=0;
        int turn =1;
        while(!pq.empty()){
            int stone =pq.top().second;
            pq.pop();
            if(turn==1){
                aliceScore+=aliceValues[stone];
            }else{
                bobScore+=bobValues[stone];
            }
            turn=!turn;
        }
        if(aliceScore>bobScore) return 1;
        if(aliceScore<bobScore) return -1;
        return 0;
    }
};