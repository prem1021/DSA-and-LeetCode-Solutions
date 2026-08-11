class Solution {
public:
    int findMin(vector<int>& nums) {
        int ans = INT_MAX;
        int start = 0;
        int end = nums.size() - 1;
        while (start <= end) {
            int mid = (start + end) / 2;
            if (nums[mid] < ans) {
                ans = min(ans, nums[mid]);
            } else if (nums[mid] > nums[end]) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return ans;
    }
};