class Solution {
public:
    bool checkSum(vector<int>& nums, int mid, int threshold) {
        long long sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += ceil((double)nums[i] / mid);
        }
        return sum <= threshold;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int maxi = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            maxi = max(maxi, nums[i]);
        }
        int low = 1, high = maxi;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (checkSum(nums, mid, threshold)) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};