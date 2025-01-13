
#include<iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
class Solution {
public:
    TreeNode* starting = NULL;
    void find(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& nodes,
              int start) {
        if (root == NULL) {
            return;
        }
        if (root->val == start) {
            starting = root;
        }
        if (root->left != NULL) {
            nodes[root->left] = root;
            find(root->left, nodes, start);
        }
        if (root->right != NULL) {
            nodes[root->right] = root;
            find(root->right, nodes, start);
        }
        return;
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*, TreeNode*> nodes;
        find(root, nodes, start);

        queue<TreeNode*> q;
        q.push(starting);
        int dist = 0;
        unordered_map<TreeNode*, bool> visited;
        visited[starting] = true;
        while (!q.empty()) {
            int size = q.size();
            bool spread = false;
            for (int i = 0; i < size; i++) {
                TreeNode* front = q.front();
                q.pop();
                if (front->left != NULL && !visited[front->left]) {
                    q.push(front->left);
                    visited[front->left] = true;

                    spread = true;
                }
                if (front->right != NULL && !visited[front->right]) {
                    q.push(front->right);
                    visited[front->right] = true;
                    spread = true;
                }
                if (nodes[front] && !visited[nodes[front]]) {
                    q.push(nodes[front]);
                    visited[nodes[front]] = true;

                    spread = true;
                }
            }
            if (spread) {
                dist++;
            }
        }
        return dist;
    }
};