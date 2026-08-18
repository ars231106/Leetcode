class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() == 0){
            return false;
        }

        if(nums.size() == 1){
            return true;
        }

        int farthest = nums[0];

        for(int i = 0; i<nums.size(); i++){
            if(i <= farthest){
                farthest = max(farthest, i + nums[i]);
            }
            else{
                return false;
            }
        }
        return true;
    }
};