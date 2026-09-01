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
    vector<vector<int>> levelorder(TreeNode* root, vector<vector<int>>& ans) {
        if(root == NULL)
            return ans;

        stack<TreeNode*> ltor;
        stack<TreeNode*> rtol;

        ltor.push(root);

        while(!ltor.empty() || !rtol.empty()){
            vector<int> level;

            while(!ltor.empty()) {
                TreeNode* temp = ltor.top();
                ltor.pop();

                level.push_back(temp->val);

                if(temp->left != NULL){
                    rtol.push(temp->left);
                }

                if(temp->right != NULL){
                    rtol.push(temp->right);
                }
            }

            if(!level.empty()){
                ans.push_back(level);
            }

            level.clear();

            while(!rtol.empty()) {
                TreeNode* temp = rtol.top();
                rtol.pop();

                level.push_back(temp->val);

                if(temp->right != NULL){
                    ltor.push(temp->right);
                }

                if(temp->left != NULL){
                    ltor.push(temp->left);
                }
            }

            if(!level.empty()){
                ans.push_back(level);
            }
        }

        return ans;
    }


    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        ans = levelorder(root, ans);
        return ans;
    }
};