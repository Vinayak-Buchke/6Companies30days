#include<iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include<algorithm>
#include <map>
using namespace std;
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // ITS A EG OF MULTI SOURCE DIJKSTRA ALGO
        map<int,vector<pair<int,int>>>adj;

        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int>nums(n,INT_MAX);
        for(int i=0;i<n;i++){
            vector<int>dist(n,INT_MAX);
            dist[i]=0;
            pq.push({0,i});
            while(!pq.empty()){
                int curr_d=pq.top().first;
                int node=pq.top().second;
                pq.pop();
                for(auto nbr_p:adj[node]){
                    int nbr=nbr_p.first;
                    int nbr_d=nbr_p.second;
                    if(curr_d+nbr_d<dist[nbr]){
                        dist[nbr]=curr_d+nbr_d;
                        pq.push({curr_d+nbr_d,nbr});
                    }
                }
            }
            int count=0;
            for(int j=0;j<n;j++){
                if(j!=i && dist[j]<=distanceThreshold){
                    count++;
                }
            }
            nums[i]=count;
        }
        int ans=INT_MAX;
        int index=-1;
        for(int i=0;i<n;i++){
            ans=min(ans,nums[i]);
        }
        for(int i=0;i<n;i++){
            if(nums[i]==ans){
                index=i;
            }
            
        }
        return index;
        
    }
};