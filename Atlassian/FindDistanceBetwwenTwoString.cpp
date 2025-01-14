#include<iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int n = arr1.size();
        int m = arr2.size();
        int count = 0;

        for (int i = 0; i < n; i++) {
            bool flag = false;
            int curr = arr1[i];
            for (int j = 0; j < m; j++) {
                if (abs(arr1[i] - arr2[j]) <= d) {
                    cout << arr1[i] << " " << arr2[j] << endl;

                    flag = true;
                }
            }
            if (flag) {
                count++;
            }
        }
        return n - count;
    }
};