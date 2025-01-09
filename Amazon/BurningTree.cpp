
#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
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
    void parentFind(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent,
                    int start, TreeNode*& startNode) {
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (node->val == start)
                startNode = node;

            if (node->left) {
                q.push(node->left);
                parent[node->left] = node;
            }
            if (node->right) {
                q.push(node->right);
                parent[node->right] = node;
            }
        }
    }

    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*, TreeNode*> parent;
        TreeNode* startNode = nullptr;
        parentFind(root, parent, start, startNode);

        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;
        q.push(startNode);
        visited[startNode] = true;

        int time = 0;

        while (!q.empty()) {
            int size = q.size();
            bool spread = false;

            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                q.pop();

                // Visit the left child
                if (node->left && !visited[node->left]) {
                    q.push(node->left);
                    visited[node->left] = true;
                    spread = true;
                }

                // Visit the right child
                if (node->right && !visited[node->right]) {
                    q.push(node->right);
                    visited[node->right] = true;
                    spread = true;
                }

                // Visit the parent
                if (parent[node] && !visited[parent[node]]) {
                    q.push(parent[node]);
                    visited[parent[node]] = true;
                    spread = true;
                }
            }

            if (spread)
                ++time; // Increment time only if infection spread
        }

        return time;
    }
};
