
#include<iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <set>
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

 // Helper function to calculate the maximum sum of a valid BST subtree in the binary tree
    pair<int, pair<int, int>> helper(TreeNode* root, int& maxSum) {
        // Base case: If the node is null, return a default value
        if (!root) return {0, {INT_MIN, INT_MAX}};
        
        // Recursively calculate the sum and range of the left subtree
        auto [leftSum, leftElement] = helper(root->left, maxSum);
        auto [leftMax, leftMin] = leftElement;
        
        // Recursively calculate the sum and range of the right subtree
        auto [rightSum, rightElement] = helper(root->right, maxSum);
        auto [rightMax, rightMin] = rightElement;

        // Check if the current tree (root + left + right) satisfies BST conditions:
        // - The root value should be greater than the maximum value in the left subtree
        // - The root value should be less than the minimum value in the right subtree
        if (root->val > leftMax && root->val < rightMin) {
            // Calculate the sum of the current subtree (BST)
            int currSum = root->val + leftSum + rightSum;
            
            // Update the global maximum sum if the current sum is greater
            maxSum = max(currSum, maxSum);

            // Return the sum of the current subtree and its range
            return {currSum, {max(root->val, rightMax), min(root->val, leftMin)}};
        } 
        else {
            // If the current tree is not a BST, return a default value
            // Set range to invalidate further parent nodes as BST
            return {max(leftSum, rightSum), {INT_MAX, INT_MIN}};
        }
    }

    int maxSumBST(TreeNode* root) {
        int maxSum = 0; // Initialize the maximum sum to 0
        helper(root, maxSum); // Call the helper function with the root node
        return maxSum; // Return the maximum sum found
    }
};