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
    TreeNode* arraytobst(vector<int>& nums, int left, int right, TreeNode*& root){
        if(left > right){
            root = NULL;
            return root;
        }

        int mid = left + (right - left) / 2;

        root = new TreeNode(nums[mid]);

        arraytobst(nums, left, mid - 1, root->left);
        arraytobst(nums, mid + 1, right, root->right);

        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root = NULL;

        arraytobst(nums, 0, nums.size() - 1, root);

        return root;
    }
};