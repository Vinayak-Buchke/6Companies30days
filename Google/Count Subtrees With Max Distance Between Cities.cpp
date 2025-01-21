

#include <bits/stdc++.h>
using namespace std;
class DSU{
    private:
    vector<int>size;
    vector<int>parent;
    public:
    DSU(int n){
        size.resize(n+1,1);
        parent.resize(n+1);
        iota(parent.begin(),parent.end(),0);
    }
    int findPar(int node){
        if(node==parent[node])return node;
        return parent[node] = findPar(parent[node]);
    }
    void unite(int x,int y){
        x = findPar(x);
        y = findPar(y);
        if(x==y)return;
        if(size[x] < size[y]){
            size[y] += size[x];
            parent[x] = y;
        }
        else{
            size[x] += size[y];
            parent[y] = x;
        }
    }
};
class Solution {
public:
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        vector<int>ans(n);
        int fmask = (1 << n);
        vector<vector<int>>adj(n+1);
        for(auto &i:edges){
            int a = i[0],b = i[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        auto dfs = [&](int node,int par,int d,int &md,int &index,auto &&adjj,auto &&self)->void{
            if(d>md){
                md = d;
                index = node;
            }
            for(auto &i:adjj[node]){
                if(i!=par){
                    self(i,node,d+1,md,index,adjj,self);
                }
            }
        };
        auto bfs = [&](int source,vector<vector<int>>&adjj)->void{
            int md = 0,index = source;
            dfs(source,-1,0,md,index,adjj,dfs);
            md = 0;
            dfs(index,-1,0,md,index,adjj,dfs);
            if(md<=n-1)ans[md]++;
        };
        auto calc = [&](int mask){
            DSU ds(n);
            int source = -1;
            for(int i=0;i<=n;i++){
                if((1<<i)&mask){
                    source = i+1;
                    break;
                }
            }
            queue<int>q; 
            unordered_set<int>m;
            m.insert(source);
            q.push(source);
            vector<vector<int>>adj1(n+1);
            while(!q.empty()){
                int node = q.front();
                q.pop();
                for(auto i:adj[node]){
                    if(m.find(i)==m.end() && (1<<(i-1))&mask){
                        m.insert(i);
                        ds.unite(node,i);
                        adj1[node].push_back(i);
                        adj1[i].push_back(node);
                        q.push(i);
                    }
                }
            }
            unordered_set<int>s;
            for(int i=0;i<n;i++){
                if((1<<i)&mask){
                    s.insert(ds.findPar(i+1));
                }
            }
            if(s.size()>1)return;  
            bfs(source,adj1);
        };
        for(int mask=1;mask<fmask;mask++){
            calc(mask);
        }
        ans.erase(ans.begin());
        return ans;
    }
};