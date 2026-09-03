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
    TreeNode* helper(vector<int>& preorder, int& preidx, int left, int right) {
        if(left > right || preidx >= preorder.size())
            return NULL;

        int root = preorder[preidx];
        TreeNode* newNode = new TreeNode(root);
        preidx++;

        int mid = preidx;

        while(mid <= right && preorder[mid] < root) {
            mid++;
        }

        newNode->left = helper(preorder, preidx, preidx, mid - 1);
        newNode->right = helper(preorder, preidx, mid, right);

        return newNode;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int preidx = 0;
        return helper(preorder, preidx, 0, preorder.size() - 1);
    }
};