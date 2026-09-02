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
    int height(TreeNode* root){
        if(root == NULL){
            return 0;
        }

        int left = height(root -> left);
        int right = height(root -> right);

        int height = 1 + max(left, right);
        return height;
    }

  void dfs(TreeNode* root, int currdepth, int togodepth, int &ans, bool &found){
    if(root == NULL || found){
        return;
    }

    if(currdepth == togodepth){
        ans = root->val;
        found = true;
        return;
    }

    dfs(root->left, currdepth + 1, togodepth, ans, found);
    dfs(root->right, currdepth + 1, togodepth, ans, found);
}

    int findBottomLeftValue(TreeNode* root) {
       if(root == NULL){
           return 0; 
       }

       int h = height(root);
       int togodepth = h - 1;
       bool found = false;

       int ans = 0;
       dfs(root, 0, togodepth, ans, found);
       return ans;
    }
};