class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return dp(nums, 0, target);
    }
    
private:
    int dp(vector<int>& nums, int idx, int remaining) {
        if (idx == nums.size()) {
            return remaining == 0 ? 1 : 0;
        }
        
        // Try adding + sign
        int add = dp(nums, idx + 1, remaining - nums[idx]);
        
        // Try adding - sign
        int subtract = dp(nums, idx + 1, remaining + nums[idx]);
        
        return add + subtract;
    }
};