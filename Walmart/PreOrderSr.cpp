
#include<iostream>
// a string using stringstream.
#include <iostream>
#include <sstream>
#include<string>
using namespace std;
class Solution {
public:
    bool isValidSerialization(string preorder) {
      int slots = 1;
        string node;

        stringstream s(preorder);

        while (getline(s, node, ',')) {
            
            slots--;

            if (slots < 0) return false;

            if (node != "#") slots += 2;
        }

        return slots == 0;  
    }
};