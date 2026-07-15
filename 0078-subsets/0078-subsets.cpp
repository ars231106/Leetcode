class Solution {
public:
   /* vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans = {{}};
        
        for(int i = 0; i<nums.size(); i++){
            int size = ans.size();

            for(int j = 0; j<size; j++){
                vector<int> list = ans[j];
                list.push_back(nums[i]);
                ans.push_back(list);
            }
        }

        return ans;  */

//dfs - backtracking approach
    vector<vector<int>> ans;
    
    void dfsBacktrack(vector<int>& nums, vector<int>& curr, int i){
        ans.push_back(curr);

        for(int j = i; j<nums.size(); j++){
            curr.push_back(nums[j]);
            dfsBacktrack(nums, curr, j + 1);
            curr.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> curr;    
        dfsBacktrack(nums, curr, 0);
        return ans;
    }
};
