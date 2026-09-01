class Solution {
public:
    int dfs(TreeNode* root){
        if (root == NULL){
            return 0;
        }

        int leftside = dfs(root -> left);
        if(leftside == -1){
            return -1;
        }

        int rightside = dfs(root -> right);
        if(rightside == -1){
            return -1;
        }

        if(abs(leftside - rightside) > 1){
            return -1;
        }

        return 1 + max(leftside, rightside);
    }
    bool isBalanced(TreeNode* root) {
        return dfs(root) != -1;
    }
};