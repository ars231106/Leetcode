/* * Definition for a binary tree node. 
* struct TreeNode { 
* int val; 
* TreeNode *left; 
* TreeNode *right; 
* TreeNode() : val(0), left(nullptr), right(nullptr) {} 
* TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} 
* TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {} 
* }; 
*/

class Solution {
public:
    // check through inorder traversal of a binary search tree (bcs in an inorder traversal of 
    // a bst the prev val <= next val (always bcs in inorder you travere from left -> root ->  // right). This condition is only valid for inoder travesal of a "BST".)
    
    TreeNode* prev = NULL;

    bool isValidBST(TreeNode* root) {

        if(root == NULL){
            return true;
        }

        if(!isValidBST(root->left)){
            return false;
        }

        if(prev != NULL && root->val <= prev->val){
            return false;
        }

        prev = root;

        if(!isValidBST(root->right)){
            return false;
        }

        return true;
    }
};