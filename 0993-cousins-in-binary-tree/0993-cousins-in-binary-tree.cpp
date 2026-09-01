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
    bool find_parent(TreeNode* root, int x, int y){
        if(root == NULL){
            return false;
        }

        if(root -> left != NULL && root -> right != NULL){
            if(root -> left -> val == x && root -> right -> val == y){
                return true;
            }

            if(root -> left -> val == y && root -> right -> val == x){
                return true;
            }
        }
        return find_parent(root -> left, x, y) || find_parent(root -> right, x, y);
    }

    int height(TreeNode* root, int value){
        if(root == NULL){
            return -1;
        }

        if(root -> val == value){
            return 0;
        }

        int leftside = height(root -> left, value);

        if(leftside != -1){
            return 1 + leftside;
        }

        int rightside = height(root -> right, value);

        if(rightside != -1){
            return 1 + rightside;
        }

        return -1;
    }

    bool isCousins(TreeNode* root, int x, int y) {
        int x_height = height(root, x);
        int y_height = height(root, y);

        if(x_height != y_height)
             return false;

        if(find_parent(root, x, y))
             return false;

        return true;
    }
};