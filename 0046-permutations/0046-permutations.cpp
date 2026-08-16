class Solution {
public:
   /* vector<vector<int>> ans;
    vector<int> curr;

    void solve(vector<int>& nums, vector<bool>& used) {
        if (curr.size() == nums.size()) {
            ans.push_back(curr);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (used[i])
                continue;

            used[i] = true;
            curr.push_back(nums[i]);

            solve(nums, used);

            curr.pop_back();
            used[i] = false;
        }
    } */

    void permutations(vector<int>& nums, vector<int>& temp, vector<bool>& vis, vector<vector<int>>& ans){

        if(temp.size() == nums.size()){
            ans.push_back(temp);
            return;
        }

        for(int i = 0; i<nums.size(); i++){
            if(vis[i] == true){
                continue;
            }

            temp.push_back(nums[i]);
            vis[i] = true;

            permutations(nums, temp, vis, ans);
            temp.pop_back();
            vis[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
       /* vector<bool> used(nums.size(), false);
        solve(nums, used);
        return ans; */

        vector<vector<int>> ans;
        vector<int> temp;
        vector<bool> vis(nums.size(), false);
        
        permutations(nums, temp, vis, ans);

        return ans;
    }
};