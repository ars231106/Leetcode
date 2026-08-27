class Solution {
public:
    string getPermutation(int n, int k) {

        vector<int> nums;

        for(int i = 1; i <= n; i++)
            nums.push_back(i);

        string ans = "";

        int fact = 1;
        for(int i = 1; i < n; i++)
            fact *= i;

        k--;  

        while(n > 0) {

            int index = k / fact;

            ans += to_string(nums[index]);

            nums.erase(nums.begin() + index);

            k = k % fact;

            n--;

            if(n > 0)
                fact /= n;
        }

        return ans;
    }
};