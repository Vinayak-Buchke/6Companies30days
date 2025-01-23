 #include<iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include<algorithm>
using namespace std;
 class Solution {
 public:
     vector<vector<int>> combinationSum3(int k, int n) {
         int arr[512] = { 0 };
         for (unsigned int i = 0; i < 512; i++) {
             string s = std::bitset<9>(i).to_string();
             for (int j = 0; j < 9; j++) {
                 if (s[j] == '1') {
                     arr[i] += (j + 1);
                 }
             }
         
         }
         vector<vector<int>> ans;
         for (unsigned int i = 0; i < 512; i++) {
             auto bs = std::bitset<9>(i);
             if (bs.count() == k && arr[i] == n) {
                 vector<int> vc;
                 string s = bs.to_string();
                 for (int j = 0; j < 9; j++) {
                     if (s[j] == '1') {
                         vc.push_back(j + 1);
                     }
                 }
                 ans.push_back(vc);
             }
             
  

         }
         return ans;
     }
 };