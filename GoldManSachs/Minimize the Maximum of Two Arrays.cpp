#include<iostream>
#include <vector>
#include <queue>
#include<algorithm>
using namespace std;
class Solution {
public:
    bool possible(long x,long d1, long d2, long uc1, long uc2)
    {
        long c1=x-(x/d1);   //Not divisible by d1 and <= x
        long c2=x-(x/d2);
        if(c1<uc1 || c2<uc2)
            return false;
        long com = (d1*d2)/__gcd(d1,d2);
        long overlapping = c2 - (x/d1)+(x/com);
        long total = c1+c2-overlapping;
        return total>=uc1+uc2;
    }
    int minimizeSet(int d1, int d2, int uc1, int uc2) 
    {
        long l=1,h=10e9,res=0;
        while(l<=h)
        {
            long mid=(l+h)/2;
            if(possible(mid, d1,d2,uc1,uc2))
            {
                res=mid;
                h=mid-1;
            }
            else
                l=mid+1;
        }
        return res;
    }
};