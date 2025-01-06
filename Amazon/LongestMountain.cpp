#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;
        for (int i = 1; i < n - 1; i++) {
            if (arr[i - 1] < arr[i] && arr[i] > arr[i + 1]) {

                int left = i - 1;
                int right = i + 1;
                while (left > -1 && arr[left] < arr[left + 1]) {
                    left--;
                }

                while (right < n - 1 && arr[right + 1] < arr[right]) {
                    right++;
                }
                ans = max(ans, (i - left) + (right - i));
            }
        }
        return ans;
    }
};