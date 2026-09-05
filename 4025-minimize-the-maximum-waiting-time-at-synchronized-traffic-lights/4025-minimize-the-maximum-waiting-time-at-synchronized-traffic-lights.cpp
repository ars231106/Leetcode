class Solution {
public:
    int minPenalty(int period, vector<int>& lights, vector<int>& arrivalTime) {
        int velunoraxi = period;

        int mx = 0;

        for(int x : lights){
            mx = max(mx, x);
        }

        int ans = 0;

        for(int x : arrivalTime){
            int r = x % velunoraxi;

            if(r >= mx){
                ans = max(ans, velunoraxi - r);
            }
        }

        return ans;
    }
};