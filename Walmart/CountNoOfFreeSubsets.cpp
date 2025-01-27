
#include<iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;
class Solution {
public:
    const int MOD = 1e9 + 7;

    int gcd(int a, int b) {
        while (b) {
            a %= b;
            swap(a, b);
        }
        return a;
    }

    long long solve(int mask, vector<int>& nums, vector<long long>& dp, unordered_map<int, int> &freq) {
        if (dp[mask] != -1) {
            return -1;
        }

        long long ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (!((1 << i) & mask)) {
                bool isPossible = true;
                for (int j = 0; j < nums.size(); j++) {
                    if ((1 << j) & mask && gcd(nums[i], nums[j]) != 1) {
                        isPossible = false;
                        break;
                    }
                }
                if (isPossible) {
                    long long subAns = solve(mask | (1 << i), nums, dp, freq);
                    ans = (ans + ((subAns + 1) * freq[nums[i]]) % MOD) % MOD;
                }
            }
        }
        return dp[mask] = ans;
    }

    int squareFreeSubsets(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int i = 2; i <= 5; i++) {
            for (int j = i * i; j <= 30; j += i * i) {
                mp[j] = 1;
            }
        }
        vector<int> squareFreeNums;
        unordered_map<int, int> freq;
        int ones = 0;
        for (int num : nums) {
            if (num == 1) {
                ones++;
            } else if (mp[num] != 1) {
                freq[num]++;
                if (freq[num] == 1) squareFreeNums.push_back(num);
            }
        }
        vector<long long> dp(1 << squareFreeNums.size(), -1);
        long long result = solve(0, squareFreeNums, dp, freq);

        // Handle ones
        for (int i = 0; i < ones; i++) {
            result = (result * 2 + 1) % MOD;
        }

        return result;
    }
};