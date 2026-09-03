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
    int find(vector<int>& inorder, int root, int left, int right){
        for(int i = left; i<= right; i++){
            if(inorder[i] == root){
                return i;
            }
        }
        return 0;
    }

    TreeNode* postrecurssive(vector<int>& inorder, vector<int>& postorder, int left, int right, int &postidx){
        if(left > right){
            return NULL;
        }

        int root = postorder[postidx];
        int inidx = find(inorder, root, left, right);
        postidx--;

        TreeNode* newNode = new TreeNode(root);
        newNode -> right = postrecurssive(inorder, postorder, inidx + 1, right, postidx);
        newNode -> left = postrecurssive(inorder, postorder, left, inidx - 1, postidx);
        
        return newNode;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int postidx = postorder.size() - 1;
        TreeNode* root = postrecurssive(inorder, postorder, 0, inorder.size() - 1, postidx);
        return root;
    }
};