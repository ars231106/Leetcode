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
    TreeNode* helperrecursive(vector<int>& preorder, int& preidx, int min, int max){
        if(preidx == preorder.size()){
            return NULL;
        }

    int root = preorder[preidx];

    if(root <= min || root >= max){
        return NULL;
    }

    TreeNode* newNode = new TreeNode(root);
    preidx++;

    newNode->left = helperrecursive(preorder, preidx, min, root);
    newNode->right = helperrecursive(preorder, preidx, root, max);

    return newNode;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int preidx = 0;
        return helperrecursive(preorder, preidx, INT_MIN, INT_MAX);
    }
};