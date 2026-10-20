class Solution {
public:
    void solve(int n, int open, int close, string ans, vector<string>& result) {
        // Base case
        if (ans.length() == 2 * n) {
            result.push_back(ans);
            return;
        }
        // Add opening bracket
        if (open < n) {
            solve(n, open + 1, close, ans + '(', result);
        }
        // Add closing bracket
        if (close < open) {
            solve(n, open, close + 1, ans + ')', result);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        solve(n, 0, 0, "", result);

        return result;
    }
};