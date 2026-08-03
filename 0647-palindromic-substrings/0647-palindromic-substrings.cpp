class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        int count = 0;
        
        // Check all substrings
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                // Check if s[i..j] is palindrome
                bool isPalin = true;
                int left = i, right = j;
                while (left < right) {
                    if (s[left] != s[right]) {
                        isPalin = false;
                        break;
                    }
                    left++;
                    right--;
                }
                
                if (isPalin) {
                    count++;
                }
            }
        }
        
        return count;
    }
};