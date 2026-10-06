/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
/* Structure of tree Node
class Node {
public:
    int data;
    Node *left;
    Node *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/
class Solution {
  public:
    void nodeinrange(TreeNode* root, int &low, int &high, int &sum){
        if(root == NULL){
            return;
        }
        
        if(root -> val >= low && root -> val <= high){
            sum += root -> val;
        }
        
        if(low <= root -> val){
            nodeinrange(root -> left, low, high, sum);
        }
        
        if(high >= root -> val){
            nodeinrange(root -> right, low, high, sum);
        }
    }
    
    int rangeSumBST(TreeNode *root, int low, int high) {
        int sum = 0;
        nodeinrange(root, low, high, sum);
        
        return sum;
    }
};