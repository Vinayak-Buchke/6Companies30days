#include<iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        
        unordered_map<string,int> um;

        int n = s.size();
        for(int i=0;i<=(n-10);i++) {
            string temp = s.substr(i,10);
            // cout<<" temp &i "<<temp<<" i "<<i<<endl;
            um[temp]++;
        }

        vector<string> ans;

        for(auto it = um.begin(); it != um.end(); it++) {
            if(it->second >= 2) {
                ans.push_back(it->first);
            }
        }

        return ans;


    }
};

// AAAAAAAAAAA