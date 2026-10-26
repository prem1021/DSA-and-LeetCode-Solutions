class Solution {
public:
    void solve(int index, vector<int> output, vector<int> nums,
               vector<vector<int>>& ans) {
        // base Case
        if (index >= nums.size()) {
            ans.push_back(output);
            return;
        }
        // exclude
        solve(index + 1, output, nums, ans);
        // include
        int element = nums[index];
        output.push_back(element);
        solve(index + 1, output, nums, ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;
        solve(0, output, nums, ans);
        return ans;
    }
};