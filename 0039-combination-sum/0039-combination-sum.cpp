class Solution {
public:
    vector<vector<int>> ans;
    vector<int> curr;
    
    void solve(vector<int>& candidates, int target, int index){
        if(target == 0){
            ans.push_back(curr);
            return;
        }

        if(target < 0){
            return;
        }

        for(int i = index; i<candidates.size(); i++){
            curr.push_back(candidates[i]);
            solve(candidates, target - candidates[i], i);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        solve(candidates, target, 0);
        return ans;
    }
};