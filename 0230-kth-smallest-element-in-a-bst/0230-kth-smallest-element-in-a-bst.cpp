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
    void inorder_traversal(TreeNode* root, int &k, int &result){
        if(root == NULL){
            return;
        }

        inorder_traversal(root -> left, k, result);
        k--;

        if(k==0){
            result = root -> val;
            return;
        }

        inorder_traversal(root -> right, k, result);
    }

    int kthSmallest(TreeNode* root, int k) {
        int result;
        inorder_traversal(root, k, result);

        return result;
    }
};