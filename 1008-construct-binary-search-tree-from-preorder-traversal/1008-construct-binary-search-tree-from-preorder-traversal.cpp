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
class Solution {
public:
    TreeNode* preordertobst(TreeNode* root, int target){
        if(root == NULL){
            TreeNode* newNode = new TreeNode(target);
            return newNode;
        }

        if(target < root -> val){
            root -> left = preordertobst(root -> left, target);
        }

        else{
            root -> right = preordertobst(root -> right, target);
        }

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = NULL;
        for(int i = 0; i< preorder.size(); i++){
           root = preordertobst(root, preorder[i]);
        }

        return root;
    }
};