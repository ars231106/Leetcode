class Solution {
public:
    void permutations(vector<int>& nums, int index, vector<vector<int>>& ans){
        if(index == nums.size()){
            ans.push_back(nums);
            return;
        }

        unordered_set<int> used;

        for(int i = index; i<nums.size(); i++){
            if(used.count(nums[i])){
                continue;
            }
            
            used.insert(nums[i]);

            swap(nums[i], nums[index]);
            permutations(nums, index + 1, ans);
            swap(nums[i], nums[index]);
            
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        permutations(nums, 0, ans);

        return ans;
    }
};