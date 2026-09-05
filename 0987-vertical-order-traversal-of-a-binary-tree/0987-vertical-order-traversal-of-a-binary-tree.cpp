class Solution {
public:

    void dfs(TreeNode* root, int row, int col,
             map<int,vector<pair<int,int>>>& mp){

        if(root==NULL)
            return;

        mp[col].push_back({row,root->val});

        dfs(root->left,row+1,col-1,mp);
        dfs(root->right,row+1,col+1,mp);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {

        vector<vector<int>> ans;

        if(root==NULL)
            return ans;

        map<int,vector<pair<int,int>>> mp;

        dfs(root,0,0,mp);

        for(auto x:mp){

            vector<pair<int,int>>& level=x.second;

            sort(level.begin(),level.end());

            vector<int> temp;

            for(auto y:level){
                temp.push_back(y.second);
            }

            ans.push_back(temp);
        }

        return ans;
    }
};