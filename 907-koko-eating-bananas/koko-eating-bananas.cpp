class Solution {
public:
    int maxValue(vector<int>& piles) {
        int maxi = INT_MIN;
        int n = piles.size();
        for (int i = 0; i <= n - 1; i++) {
            maxi = max(piles[i], maxi);
        }
        return maxi;
    }

    long long countHours(vector<int>& piles, int mid) {
        int n = piles.size();
        long long totalHR = 0;
        for (int i = 0; i <= n - 1; i++) {
            totalHR += ceil(double(piles[i]) / double(mid));
        }
        return totalHR;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        long low = 1;
        long high = maxValue(piles);
        while (low <= high) {
            long long mid = (low + high) / 2;
            long long totalHR = countHours(piles, mid);
            if (totalHR <= h) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};