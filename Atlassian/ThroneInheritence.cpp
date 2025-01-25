#include<iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;
class ThroneInheritance {
public:
    unordered_map<string, pair<bool, vector<string>>> tree;
    string king = "";
    ThroneInheritance(string kingName) {
        king = kingName;
        tree[kingName] = {true, {}};
    }
    
    void birth(string parentName, string childName) {
        tree[parentName].second.push_back(childName);
        tree[childName] = {true, {}};
    }
    
    void death(string name) {
        tree[name].first = false;
    }
    void dfs(string src, vector<string>& order, unordered_map<string, pair<bool, vector<string>>>& adjlist)
    {
        if (adjlist[src].first == true)
            order.push_back(src);
        for (auto child: adjlist[src].second)
        {
            dfs(child, order, adjlist);
        }
    }
    vector<string> getInheritanceOrder() {
        vector<string> order;
        dfs(king, order, tree);

        return order;
    }
};

