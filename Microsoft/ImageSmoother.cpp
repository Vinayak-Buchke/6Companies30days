#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<vector<int>> imageSmoother(vector<vector<int>> &img)
    {
        int m = img.size();
        int n = img[0].size();
        int left[] = {1, 0, -1, 0, 1, -1, 1, -1};
        int right[] = {0, 1, 0, -1, 1, -1, -1, 1};
        vector<vector<int>> ans(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int count = 0;
                int sum = 0;
                for (int k = 0; k < 8; k++)
                {
                    int row = i + left[k];
                    int col = j + right[k];
                    if (row >= 0 && col >= 0 && row < m && col < n)
                    {
                        sum += img[row][col];
                        count++;
                    }
                }
                sum += img[i][j];
                count++;
                ans[i][j] = (sum / count);
            }
        }
        return ans;
    }
};

int main()
{
    Solution obj;
    vector<vector<int>> img = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    vector<vector<int>> ans = obj.imageSmoother(img);
}