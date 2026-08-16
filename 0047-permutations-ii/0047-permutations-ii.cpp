class Solution {
public:
    void permutations(vector<int>& nums, int index, vector<vector<int>>& ans){
        if(index == nums.size()){
            ans.push_back(nums);
            return;
        }

        vector<bool> used(21, false);

        for(int i = index; i<nums.size(); i++){
            if(used[nums[i] + 10] == false){
                swap(nums[i], nums[index]);
                permutations(nums, index + 1, ans);
                swap(nums[i], nums[index]);
                used[nums[i] + 10] = true;
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        permutations(nums, 0, ans);

        return ans;
    }
};