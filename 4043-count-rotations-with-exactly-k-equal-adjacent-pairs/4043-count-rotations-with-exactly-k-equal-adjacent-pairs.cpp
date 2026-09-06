class Solution {
public:
    int countRotations(string s, int k) {
        int n = s.length();
        int ans = 0;

        for(int r = 0; r < n; r++) {
            int score = 0;

            for(int i = 0; i < n - 1; i++) {
                if(s[i] == s[i + 1])
                    score++;
            }

            if(score == k)
                ans++;

            char ch = s[0];
            s.erase(0, 1);
            s.push_back(ch);
        }

        return ans;
    }
};