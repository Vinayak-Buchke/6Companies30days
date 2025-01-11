
 
#include <iostream>
#include <unordered_map>
#include<algorithm>
#include <vector>
#include <queue>
#include <sstream>
using namespace std;


  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
class Codec {
public:

    // Encodes a tree to a single string.
   string serialize(TreeNode* root) {
        if(!root) return "";
        string s = "";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(!node) s +="null,";

            else{
                s += to_string(node->val) +",";

                q.push(node->left);
                q.push(node->right);
            }
        }
        return s;
    }

     TreeNode* deserialize(string data) {
        if (data.empty()) {
            return nullptr;
        }

        // Use a stringstream to
        // tokenize the serialized data
        stringstream s(data);
        string str;
        // Read the root value
        // from the serialized data
        getline(s, str, ',');
        TreeNode* root = new TreeNode(stoi(str));

        // Use a queue for 
        // level-order traversal
        queue<TreeNode*> q;
        // Start with the root node
        q.push(root);

        // Perform level-order traversal
        // to reconstruct the tree
        while (!q.empty()) {
            // Get the front node in the queue
            TreeNode* node = q.front();
            q.pop();

            // Read the value of the left
            // child from the serialized data
            getline(s, str, ',');
            // If the value is not "#", create a new
            // left child and push it to the queue
            if (str != "null") {
                TreeNode* leftNode = new TreeNode(stoi(str));
                node->left = leftNode;
                q.push(leftNode);
            }

            // Read the value of the right child
            // from the serialized data
            getline(s, str, ',');
            // If the value is not "#", create a
            // new right child and push it to the queue
            if (str != "null") {
                TreeNode* rightNode = new TreeNode(stoi(str));
                node->right = rightNode;
                q.push(rightNode);
            }
        }

        // Return the reconstructed
        // root of the tree
        return root;
    }
};

