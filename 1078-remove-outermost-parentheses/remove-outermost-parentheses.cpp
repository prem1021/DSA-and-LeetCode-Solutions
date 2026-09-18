class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        int i = 0;
        int depth = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                depth++;
                if (depth != 1) {
                    ans.push_back(s[i]);
                }
            } else {
                depth--;
                if (depth != 0) {
                    ans.push_back(s[i]);
                }
            }
        }
        return ans;
    }
};