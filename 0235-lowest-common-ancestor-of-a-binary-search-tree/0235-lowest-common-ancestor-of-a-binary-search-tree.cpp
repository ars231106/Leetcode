/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        //CASE 1 : leftLCA = NULL and righLCA = NULL; return NULL
        if(root == NULL){
            return NULL;
        }

        if(root == p || root == q){
            return root;
        }

        TreeNode* leftLCA = lowestCommonAncestor(root -> left, p, q);
        TreeNode* rightLCA = lowestCommonAncestor(root -> right, p, q);
        
        //CASE 4: leftLCA = not NULL(valid) and righLCA = not NULL(valid); return root

        //becase both p and q have returned a not NULL value to the same node (first lowest
        //ancestor encountered, same to be returned)
        if(leftLCA != NULL && rightLCA != NULL){
            return root;
        }

        //CASE 2:leftLCA = not NULL(valid) and righLCA = NULL(not valid); return leftLCA
        //because the other one is NULL 
        else if(leftLCA != NULL){
            return leftLCA;
        }

        //CASE 3:leftLCA = NULL(not valid) and righLCA = not NULL(valid); return rightLCA
        //because the other one is NULL
        else{
            return rightLCA;
        }
    }
};