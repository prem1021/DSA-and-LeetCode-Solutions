class Solution {
public:
    int binarySearch(vector<int>& nums, int s, int e, int target) {
        int n = nums.size();
        int mid = s + (e - s) / 2;
        if (s > e) {
            return -1;
        }
        if (nums[mid] == target) {
            return mid;
        }
        if (nums[mid] < target) {
            return binarySearch(nums, mid + 1, e, target);
        } else {
            return binarySearch(nums, s, mid-1, target);
        }
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        return binarySearch(nums, 0, n - 1, target);
    }
};