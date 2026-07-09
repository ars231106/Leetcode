class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int, int>hp;
        for(int i = 0; i<nums.size(); i++){
            int req = target - nums[i]; 
            
            if(hp.find(req) != hp.end()){
            return {hp[req], i};
        }
        hp[nums[i]] = i;
      }
     return {};
    }
};