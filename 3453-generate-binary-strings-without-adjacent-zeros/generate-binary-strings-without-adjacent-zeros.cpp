class Solution {
public:
    void solve(int index, vector<string>& ans, int n, string temp) {
        // Base Case
        if (index == n) {
            ans.push_back(temp);
            return ;
        }
        // include 0
        if (temp.empty() || temp.back() != '0') {
            temp.push_back('0');
            solve(index + 1, ans, n, temp);
            temp.pop_back();
        }
        // include 1
        temp.push_back('1');
        solve(index + 1, ans, n, temp);
        temp.pop_back();
    }

    vector<string> validStrings(int n) {
        int index = 0;
        vector<string> ans;
        string s = "";
        solve(index, ans, n, s);
        return ans;
    }
};