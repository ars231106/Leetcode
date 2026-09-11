class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        vector<int> ans;
        unordered_map<int,int> mp;

        for(int i=0;i<nums.size();i++){

            if(mp.find(nums[i])==mp.end()){
                ans.push_back(nums[i]);
                mp[nums[i]]++;
            }
        }

        for(int i=0;i<ans.size();i++)
            nums[i]=ans[i];

        return ans.size();
    }
};