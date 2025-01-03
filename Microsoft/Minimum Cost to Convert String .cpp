#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        vector<vector<int>>matrix(26,vector<int>(26,INT_MAX));
        for(int i=0; i<26; i++){
            matrix[i][i] = 0;
        }

        for(int index=0; index<cost.size(); index++){
            int i = original[index] - 'a';
            int j = changed[index] - 'a';
            int w = cost[index];

            matrix[i][j] = min(w,matrix[i][j]);

        }

        for(int via=0; via<26; via++){
            for(int i=0; i<26; i++){
                for(int j=0; j<26; j++){
                    if(matrix[i][via]!=INT_MAX && matrix[via][j]!=INT_MAX){
                        matrix[i][j] = min(matrix[i][via]+matrix[via][j],matrix[i][j]);
                    }
                }
            }
        }

        int n = source.length();
        long long miniCost = 0;

        for(int i=0; i<n; i++){
            if(source[i]!=target[i]){
                int u = source[i]-'a';
                int v = target[i]-'a';

                if(matrix[u][v]==INT_MAX){
                    return -1;
                }

                miniCost += matrix[u][v];
            }
        }

        return miniCost;
    }
};
