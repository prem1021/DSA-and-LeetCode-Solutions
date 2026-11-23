class Solution {
public:
    void solve(int index, vector<int>& candidates, vector<vector<int>>& ans,
               vector<int>& s, int target) {
        // base case
        if (index == candidates.size()) {
            if (target == 0) {
                ans.push_back(s);
            }
            return;
        }
        // include same index
        if (candidates[index] <= target) {
            s.push_back(candidates[index]);
            solve(index, candidates, ans, s, target - candidates[index]);
            s.pop_back();
        }
        // include other index
        solve(index + 1, candidates, ans, s, target);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int index = 0;
        int sum = 0;
        vector<int> s;
        vector<vector<int>> ans;
        solve(index, candidates, ans, s, target);
        return ans;
    }
};