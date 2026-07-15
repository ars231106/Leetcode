/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<vector<int>> paths;

    void dfs(TreeNode* root, vector<int>& path) {
        if (root == NULL)
            return;

        path.push_back(root->val);

        if (root->left == NULL && root->right == NULL) {
            paths.push_back(path);
        }

        dfs(root->left, path);
        dfs(root->right, path);

        path.pop_back();
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        dfs(root, path);

        for (auto &v : paths) {
            int sum = 0;
            for (int x : v)
                sum += x;

            if (sum == targetSum)
                return true;
        }

        return false;
    }
};