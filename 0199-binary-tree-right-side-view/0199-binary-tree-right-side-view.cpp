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
    int height(TreeNode* root) {
        if (root == NULL)
            return 0;

        return 1 + max(height(root->left), height(root->right));
    }

    void printLevel(TreeNode* root, int level, int &ans) {
        if (root == NULL)
            return;

        if (level == 1) {
            ans = root->val;      
            return;
        }

        printLevel(root->left, level - 1, ans);
        printLevel(root->right, level - 1, ans);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;

        int h = height(root);

        for (int i = 1; i <= h; i++) {
            int val = 0;
            printLevel(root, i, val);
            res.push_back(val);
        }

        return res;
    }
};