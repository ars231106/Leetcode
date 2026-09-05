class Solution {
public:
    int maximumGap(string skill, string station) {
        int n = skill.size();
        int m = station.size();

        vector<int> latest(n);

        int j = m - 1;

        for(int i = n - 1; i >= 0; i--){
            while(station[j] != skill[i]){
                j--;
            }

            latest[i] = j;
            j--;
        }

        int ans = 0;
        int earliest = 0;

        for(int i = 0; i < n - 1; i++){
            while(station[earliest] != skill[i]){
                earliest++;
            }

            ans = max(ans, latest[i + 1] - earliest);
            earliest++;
        }

        return ans;
    }
};