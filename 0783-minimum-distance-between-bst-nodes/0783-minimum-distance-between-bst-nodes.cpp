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
    void inorder_traversal(TreeNode* root, TreeNode*& prev, int& ans){
        if(root == NULL){
            return;
        }

        inorder_traversal(root->left, prev, ans);

        if(prev != NULL){
            ans = min(ans, root->val - prev->val);
        }

        prev = root;

        inorder_traversal(root->right, prev, ans);
    }

    int minDiffInBST(TreeNode* root) {
        TreeNode* prev = NULL;
        int ans = INT_MAX;

        inorder_traversal(root, prev, ans);

        return ans;
    }
};