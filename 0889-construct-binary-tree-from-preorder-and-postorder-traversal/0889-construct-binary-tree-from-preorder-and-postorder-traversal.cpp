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
    int find(vector<int>& postorder, int leftroot, int left, int right){
        for(int i = left; i<=right; i++){
            if(postorder[i] == leftroot){
                return i;
            }
        }
        return 0;
    }

    TreeNode* recurssivehelper(vector<int>& preorder, vector<int>& postorder, int left, int right, int &preidx){
        if(left > right){
            return NULL;
        }

        int root = preorder[preidx];
        TreeNode* newNode = new TreeNode(root);

        if(left == right){
            preidx++;
            return newNode;
        }

        int leftroot = preorder[preidx + 1];
        int postidx = find(postorder, leftroot, left, right);
        preidx++;

        newNode -> left = recurssivehelper(preorder, postorder, left, postidx, preidx);
        newNode -> right = recurssivehelper(preorder, postorder, postidx + 1, right - 1, preidx);

        return newNode;
    } 

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int preidx = 0;
        TreeNode* root = recurssivehelper(preorder, postorder, 0, postorder.size() - 1, preidx);
        return root;
    }
};