class Solution {
public:
    pair<int,int> dfs(TreeNode* root) {
        if(root == NULL) {
            return {0, 1};
        }

        pair<int,int> left = dfs(root->left);
        pair<int,int> right = dfs(root->right);

        int height = 1 + max(left.first, right.first);

        int balanced = left.second &&
                       right.second &&
                       abs(left.first - right.first) <= 1;

        return {height, balanced};
    }

    bool isBalanced(TreeNode* root) {
        pair<int,int> ans = dfs(root);

        return ans.second;
    }
};