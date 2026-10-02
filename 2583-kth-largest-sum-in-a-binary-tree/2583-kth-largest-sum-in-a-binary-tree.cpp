class Solution {
public:
    void level_order(TreeNode* root, vector<long long> &sums){
        queue<TreeNode*> q;

        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> level;

            for(int i = 0; i < size; i++){
                TreeNode* temp = q.front();
                q.pop();

                level.push_back(temp -> val);

                if(temp -> left){
                    q.push(temp -> left);
                }

                if(temp -> right){
                    q.push(temp -> right);
                }
            }

            long long sum = 0;

            for(int i = 0; i < level.size(); i++){
                sum += level[i];
            }

            sums.push_back(sum);
        }
    }
    
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long> sums;
        level_order(root, sums);

        sort(sums.begin(), sums.end(), greater<long long>());

        if(k > sums.size())
            return -1;

        return sums[k-1];
    }
};