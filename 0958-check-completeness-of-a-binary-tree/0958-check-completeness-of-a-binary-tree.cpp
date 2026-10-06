class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);

        bool flag = false;

        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();

            if(temp == NULL){
                flag = true;
            }
            else{
                if(flag)
                    return false;

                q.push(temp->left);
                q.push(temp->right);
            }
        }

        return true;
    }
};