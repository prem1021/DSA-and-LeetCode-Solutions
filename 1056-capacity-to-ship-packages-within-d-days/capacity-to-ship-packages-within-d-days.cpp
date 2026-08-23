class Solution {
public:
    bool isPossible(vector<int>& weights, int mid, int days) {
        int n = weights.size();
        int sum = 0;
        int noOfDay = 1;
        for (int i = 0; i <= n - 1; i++) {
            if (sum + weights[i] > mid) {
                noOfDay++;
                sum = weights[i];
            } else {
                sum += weights[i];
            }
        }
        return noOfDay <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int maxi = INT_MIN;
        int maxSum = 0;
        for (int i = 0; i <= n - 1; i++) {
            maxi = max(maxi, weights[i]);
            maxSum += weights[i];
        }
        int low = maxi;
        int high = maxSum;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (isPossible(weights, mid, days)) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};