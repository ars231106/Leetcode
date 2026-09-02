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
    void dfs(TreeNode* root, int height, int &maxheight, int &value){
        if(root == NULL){
            return;
        }

        if(height > maxheight){
            maxheight = height;
            value = root -> val;
        }

        dfs(root -> left, height + 1, maxheight, value);
        dfs(root -> right, height + 1, maxheight, value);


    }

    int findBottomLeftValue(TreeNode* root) {
        int maxheight = -1;
        int height = 0;

        if(root == NULL){
            return 0;
        }

        int value = 0;
        dfs(root, height, maxheight,value);

        return value;
    }
};