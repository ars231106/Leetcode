class Solution {
public:
    vector<vector<int>> ans;
    vector<int> curr;

    void solve(int k, int n, int index){
        if(n == 0 && curr.size() == k){
            ans.push_back(curr);
            return;
        }

        if(n < 0 || curr.size() > k){
            return;
        }

        for(int i = index; i<=9; i++){
            curr.push_back(i);
            solve(k, n - i, i + 1);
            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        solve(k, n, 1);
        return ans;
    }
};