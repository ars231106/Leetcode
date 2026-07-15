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
    vector<vector<int>> ans;

    bool dfs(TreeNode* root, int targetSum, vector<int>& path){
        if(root == NULL){
            return false;
        }

        path.push_back(root -> val);
        targetSum = targetSum - (root -> val);

        if(root -> left == NULL && root -> right == NULL && targetSum == 0){
            ans.push_back(path);
            path.pop_back();
            return true;
        }

        bool left = dfs(root->left, targetSum, path);
        bool right = dfs(root -> right, targetSum, path);

        path.pop_back();
        
        return left || right;

    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        bool found = dfs(root, targetSum, path);
        return ans;
    }
};