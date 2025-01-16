#include<iostream>
#include <vector>
using namespace std;
class Solution {
  public:
    string encode(string s) {
        int n=s.length();
        string ans="";
        int j=0;
        int i=0;
        while(i<n)
        {
            char c=s[i];
            
            int count=0;
            while(c==s[j] && j<n)
            {
                j++;
                count++;
            }
            ans+=c+to_string(count);
            i=j;
        }
        return ans;
    }
};