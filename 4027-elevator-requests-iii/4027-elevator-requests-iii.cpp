class Solution {
public:
    long long elevatorRequests(int n, int start, vector<vector<int>>& requests) {
        int m = requests.size();

        const long long INF = 1e18;

        vector<vector<long long>> dp(
            1 << m,
            vector<long long>(m, INF)
        );

        // First request
        for(int i = 0; i < m; i++){
            long long distance = abs(start - requests[i][1]);

            dp[1 << i][i] =
                max(distance, (long long)requests[i][0]);
        }

        // All masks
        for(int mask = 1; mask < (1 << m); mask++){

            for(int i = 0; i < m; i++){

                if(!(mask & (1 << i)))
                    continue;

                if(dp[mask][i] == INF)
                    continue;

                // Try next request
                for(int j = 0; j < m; j++){

                    if(mask & (1 << j))
                        continue;

                    long long distance =
                        abs(requests[i][1] - requests[j][1]);

                    long long newTime =
                        max(
                            dp[mask][i] + distance,
                            (long long)requests[j][0]
                        );

                    int newmask =
                        mask | (1 << j);

                    dp[newmask][j] =
                        min(dp[newmask][j], newTime);
                }
            }
        }

        int full = (1 << m) - 1;

        long long ans = INF;

        for(int i = 0; i < m; i++){
            ans = min(ans, dp[full][i]);
        }

        return ans;
    }
};