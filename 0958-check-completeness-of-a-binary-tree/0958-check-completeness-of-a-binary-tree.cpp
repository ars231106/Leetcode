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
    void levelorder(TreeNode* root, bool &flag){
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            vector<TreeNode*> level;
            
            for(int i = 0; i<size; i++){
                TreeNode* temp = q.front();
                q.pop();

                level.push_back(temp);

                if(temp != NULL){
                    q.push(temp -> left);
                    q.push(temp -> right);
                }
            }

            for(int i = 0; i<level.size(); i++){
                if(level[i] == NULL){
                    flag = true;
                }

                else if(flag == true){
                    flag = false;
                    return;
                }
            }
        }
    }

    bool isCompleteTree(TreeNode* root) {
        bool flag = false;
        levelorder(root, flag);

        return flag;
    }
};