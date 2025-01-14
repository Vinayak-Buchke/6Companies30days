#include<iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int countCollisions(string d) {
        int n = d.length();
        int right = 0;
        int left = 0;
        int stay = 0;
        int collision = 0;
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                if (d[i] == 'L') {
                    left++;
                }
                if (d[i] == 'R') {
                    right++;
                }
                if (d[i] == 'S') {
                    stay++;
                }
            } else {
                if (d[i] == 'L') {
                    if (d[i - 1] == 'R') {
                        collision += 2;
                        stay += 2;
                        right--;
                    } else if (stay > 0) {
                        collision++;
                    }
                    if (right > 0) {
                        collision += right;
                        right = 0;
                    }

                } else if (d[i] == 'R') {
                    right++;
                } else {
                    if (right > 0) {
                        collision += right;
                        right = 0;
                        stay += 2;
                    } else {
                        stay++;
                    }
                }
            }
        }
        return collision;
    }
};