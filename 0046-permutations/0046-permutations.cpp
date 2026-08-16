class Solution {
public:
// Soln 1 (Backtracking I - both are the same just diff variable names and func arguments)

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
    } 
*/

//Soln 2 (Backtarcking II - both are the same, just diff variable names and func arguments)

/* void permutations(vector<int>& nums, vector<int>& temp, vector<bool>& vis, vector<vector<int>>
    ans){

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
*/

    void permuatations(vector<int>& nums, vector<vector<int>>& ans, int index){
        if(index == nums.size()){
            ans.push_back(nums);
            return;
        }

        for(int i = index; i< nums.size(); i++){
            swap(nums[i], nums[index]);
            permuatations(nums, ans, index + 1);
            swap(nums[i], nums[index]);

        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
    /* vector<bool> used(nums.size(), false);
        solve(nums, used);
        return ans; 

        (for Soln I)
    */

     /* vector<vector<int>> ans;
        vector<int> temp;
        vector<bool> vis(nums.size(), false);
        
        permutations(nums, temp, vis, ans);

        return ans;

        (for Soln II)
     */

        vector<vector<int>>ans;
        permuatations(nums, ans, 0);

        return ans;
    }
};