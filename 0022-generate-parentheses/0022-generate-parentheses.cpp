class Solution {
public:
//backtrackig approach I
   /* vector<string> ans;

    void solve(int n, int openused, int opennotclosed, string &curr){
        if(curr.size() == 2 * n){
            ans.push_back(curr);
            return;
        }

        if(openused < n){
            curr.push_back('(');
            solve(n, openused + 1, opennotclosed + 1, curr);
            curr.pop_back();
        }

        if(opennotclosed > 0){
            curr.push_back(')');
            solve(n, openused, opennotclosed - 1, curr);
            curr.pop_back();
        }
    } */

    void binarybacktrack(int n, int left, int right, vector<string>& ans, string temp){
        if(left == n && right == n){
            ans.push_back(temp);
            return;
        }

        if(left < n){
            temp.append(1, '(');
            binarybacktrack(n, left + 1, right, ans, temp);
            temp.pop_back();
        }

        if(left > right){
            temp.append(1, ')');
            binarybacktrack(n, left, right + 1, ans, temp);
            temp.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
       /* string curr;
        solve(n, 0, 0, curr);
        return ans; 

        (for backtarcking approach I)
        */

        vector<string> ans;
        string temp;
        binarybacktrack(n, 0, 0, ans, temp);
        return ans;
    }
};