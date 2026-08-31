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
    vector<int> levelorder(TreeNode* root, vector<int>& ans){
        queue<TreeNode*> q;
         if(root == NULL){
            return ans;
        }

        q.push(root);
        
        while(!q.empty()){
            int size = q.size();
            int max = INT_MIN;

            for(int i = 0; i<size; i++){
                TreeNode* temp = q.front();
                q.pop();

                if(temp -> val > max){
                    max = temp -> val;
                }

                if(temp -> left != NULL){
                    q.push(temp -> left);
                }

                if(temp -> right != NULL){
                    q.push(temp -> right);
                }
            }

            ans.push_back(max);
        }

        return ans;
    }
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        ans = levelorder(root, ans);
        return ans;
    }
};