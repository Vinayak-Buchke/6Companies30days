#include<iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
    vector<int>index1;
    vector<int>index2;
    vector<int>final;
    size_t pos=s.find(a,0);
    while(pos!=string::npos)
    {
        index1.push_back(pos);
        pos=s.find(a,pos+1);
    }
    pos=s.find(b,0);
    while(pos!=string::npos)
    {
        index2.push_back(pos);
        pos=s.find(b,pos+1);
    }
    for(int i=0;i<index1.size();i++)
    {
        for(int j=0;j<index2.size();j++)
        {
            if(abs(index1[i]-index2[j])<=k)
            {
                final.push_back(index1[i]);
                break;
            }
        }
    }
    return final;
    }
};