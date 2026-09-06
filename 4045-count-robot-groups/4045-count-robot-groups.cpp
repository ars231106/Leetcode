class Solution {
public:
    int countGroups(vector<int>& position, vector<int>& speed, int distance) {
        int n = position.size();
        long long spd = speed[n-1];
        int groups = 1;
        for(int i = n-2; i>=0; i--){
            if(position[i+1] - position[i] <= distance || speed[i] > spd){
                continue;
            }
            groups++;
            spd = speed[i];
        }
        return groups;
    }
};