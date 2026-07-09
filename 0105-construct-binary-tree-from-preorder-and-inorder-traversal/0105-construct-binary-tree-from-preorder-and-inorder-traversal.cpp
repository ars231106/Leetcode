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
    //searching index of root in the inorder list
    int search(vector<int>& inorder, int value, int left, int right){
        for(int i = 0; i<inorder.size(); i++){
            if(inorder[i] == value){
                return i;
            }
        }
        return -1;
    }
    
    //helper function to recurrsively traverse the preorder list to build the tree 
    TreeNode* helpfunction(vector<int>& preorder, vector<int>& inorder, int &preidx, int left, int right){
        if (left > right){
            return NULL;
        }
         
        int value = preorder[preidx]; 
        TreeNode* root = new TreeNode(value);
        preidx++;

        int idridx = search(inorder, value, left, right);
        root -> left = helpfunction(preorder, inorder, preidx, left, idridx - 1);
        root -> right = helpfunction(preorder, inorder, preidx, idridx + 1, right);

        return root;
    }

    //preorder list for finding root
    //inorder list for finding the left and right subtree 

    //building the tree from the given preorder and inorder lists 
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preidx = 0;
        TreeNode* root = helpfunction(preorder, inorder, preidx, 0, inorder.size() - 1);
        return root;
    }
};