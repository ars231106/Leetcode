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
    TreeNode* arraytobst(vector<int>& nums, int left, int right){
        if(left > right){
            return NULL;
        }

        int mid = left + ((right - left) / 2);

        TreeNode* newNode = new TreeNode(nums[mid]);

        newNode -> left = arraytobst(nums, left, mid - 1);
        newNode -> right = arraytobst(nums, mid + 1, right);

        return newNode;

    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1 ;

        TreeNode* result = arraytobst(nums, left, right);

        return result;

    }
};