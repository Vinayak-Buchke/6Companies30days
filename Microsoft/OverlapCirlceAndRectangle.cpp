#include <iostream>
#include <unordered_map>
using namespace std;
class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
              int xn = max(x1, min(x2,xCenter));
        int yn = max(y1, min(y2, yCenter));
        return (yn-yCenter)*(yn-yCenter)+(xn-xCenter)*(xn-xCenter) <= radius*radius;
    }
};

int main()
{
    Solution obj;
    cout<<obj.checkOverlap(1,0,0,1,-1,3,1);
}